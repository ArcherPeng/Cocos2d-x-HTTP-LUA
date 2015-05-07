#include "AppDelegate.h"
#include "CCLuaEngine.h"
#include "SimpleAudioEngine.h"
#include "cocos2d.h"
#include "lua_module_register.h"
using namespace CocosDenshion;

USING_NS_CC;
using namespace std;

AppDelegate::AppDelegate()
{
}

AppDelegate::~AppDelegate()
{
    SimpleAudioEngine::end();
}
//注册LUA回调C++函数



bool popTable(lua_State* L, int idx,DataOutputUtil *dos)
{
    try{
        lua_pushnil(L);
        std::string keyStr;
        std::string typeStr;
        int valueIndex;
        while(lua_next(L, idx) != 0)
        {
            
            int keyType = lua_type(L, -2);
            if(keyType == LUA_TNUMBER){
                valueIndex = (int)lua_tonumber(L, -2);
            }else if(keyType == LUA_TSTRING){
                const char*  value = lua_tostring(L, -2);
                keyStr = value;
            }else{
                CCLOG("AppDelegate popTable --> Key类型错误 : %d  参数编号 : %d",keyType,valueIndex);
                return false;
            }
            int valueType = lua_type(L, -1);
            if (keyStr != "value")
            {
                if (valueType == LUA_TTABLE)
                {
                    int index = lua_gettop(L);
                    popTable(L, index,dos);
                    lua_pop(L, 1);
                    continue;
                }
                else
                {
                    if (keyStr == "type")
                    {
                        typeStr = lua_tostring(L, -1);
                    }
                }
                lua_pop(L, 1);
                continue;
            }
            
            if (valueType == LUA_TTABLE)
            {
                return false;
            }
            else
            {
                if (keyStr == "value")
                {
                    keyStr="";
//                    CCLOG("typeStr : %s ",typeStr.c_str());
                    if (typeStr == "byte")
                    {
                        dos->writeByte((int)lua_tonumber(L, -1));
                    }
                    else if (typeStr == "int")
                    {
                        dos->writeInt((int)lua_tonumber(L, -1));
                    }
                    else if (typeStr == "bool")
                    {
                        dos->writeBoolean((bool)lua_toboolean(L, -1));
                    }
                    else if (typeStr == "long")
                    {
                        dos->writeLong((long)lua_tonumber(L, -1));
                    }
                    else if (typeStr == "short")
                    {
                        dos->writeShort((short)lua_tonumber(L, -1));
                    }
                    else if (typeStr == "string" || typeStr == "str")
                    {
                        std::string str = lua_tostring(L, -1);
                        dos->writeUTF(str);
                    }
//                    else if (typeStr == "charArr")
//                    {
//                        std::string str = lua_tostring(L, -1);
//                        dos->writeUTF(str);
//                    }
                    else
                    {
                        CCLOG("AppDelegate popTable --> Unkown type : %s 参数编号 : %d",typeStr.c_str(),valueIndex);
                        return false;
                    }
                    typeStr="";
                    lua_pop(L, 1);
                }
                else
                {
                    return false;
                }
            }
        }
    }
    catch(const char* s)
    {
        lua_pop(L,1);
        CCLOG("AppDelegate popTable --> %s",s);
        return false;
    }
    catch(std::exception& e)
    {
        const char* errMsg = e.what();
        lua_pop(L,1);
        CCLOG("AppDelegate popTable --> %s",errMsg);
        return false;
    }
    catch(...)
    {
        const char* errMsg = lua_tostring(L,-1);
        lua_pop(L,1);
        CCLOG("AppDelegate popTable --> %s",errMsg);
        return false;
    }
    return true;
}

static int httpSend(lua_State*L)
{
    const char * url = lua_tostring(L, 1);
    int index = lua_gettop(L);
    //    DataOutputUtil * dou = (DataOutputUtil *)lua_touserdata(L,2);
    if(lua_istable(L, 2))
    {
        DataOutputUtil * dou = DataOutputUtil::create();
        if(popTable(L,index,dou))
        {
            APHttp::send(url, dou);
        }
        else
        {
            CCLOG("AppDelegate httpSend --> popTable return false");
        }
    }
    else
    {
        DataOutputUtil * dou = (DataOutputUtil *)lua_touserdata(L,2);
        APHttp::send(url, dou);
    }
    
    return 0;
}
//C++回调LUA函数
const char * httpReceive()
{
    lua_State*  ls = cocos2d::LuaEngine::getInstance()->getLuaStack()->getLuaState();
    std::string scriptPath=cocos2d::FileUtils::getInstance()->fullPathForFilename("httpCallback.lua");
    int isOpen = luaL_dofile(ls, scriptPath.c_str());
    
    if (isOpen != 0){
        CCLOG("AppDelegate httpReceive --> Open Lua Error: %i", isOpen);
        return NULL;
    }
    
    lua_getglobal(ls, "httpCallback");
    
//    lua_pushlightuserdata(ls, input);
    lua_call(ls, 0, 1);
    
    const char* iResult = lua_tostring(ls, -1);
    return iResult;
}

//if you want a different context,just modify the value of glContextAttrs
//it will takes effect on all platforms
void AppDelegate::initGLContextAttrs()
{
    //set OpenGL context attributions,now can only set six attributions:
    //red,green,blue,alpha,depth,stencil
    GLContextAttrs glContextAttrs = {8, 8, 8, 8, 24, 8};

    GLView::setGLContextAttrs(glContextAttrs);
}

bool AppDelegate::applicationDidFinishLaunching()
{
    auto engine = LuaEngine::getInstance();
    ScriptEngineManager::getInstance()->setScriptEngine(engine);
    lua_State* L = engine->getLuaStack()->getLuaState();
    lua_module_register(L);
    lua_register(L, "_APhttpSendMethod", httpSend);
//    lua_register(L, "httpSend", httpSend);
    // If you want to use Quick-Cocos2d-X, please uncomment below code
    // register_all_quick_manual(L);
    if (engine->executeScriptFile("src/main.lua")) {
        return false;
    }
//    DataOutputUtil *dos = DataOutputUtil::create();
//    dos->writeByte(3);
//    dos->writeInt(CCRANDOM_0_1()*10000);
//    dos->writeUTF("ArcherPeng测试");
//    dos->writeLong(10000);
//    dos->writeBoolean(false);
//    APHttp::send("http://192.168.1.123:8080/dzpk_pay/pay.do", dos);
    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground()
{
    Director::getInstance()->stopAnimation();

    SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground()
{
    Director::getInstance()->startAnimation();

    SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}
