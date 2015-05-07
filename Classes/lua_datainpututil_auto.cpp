#include "lua_datainpututil_auto.hpp"
#include "DataInputUtil.h"
#include "tolua_fix.h"
#include "LuaBasicConversions.h"



int lua_DataInputUtil_DataInputUtil_readShort(lua_State* tolua_S)
{
    int argc = 0;
    DataInputUtil* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"DataInputUtil",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (DataInputUtil*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_DataInputUtil_DataInputUtil_readShort'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_DataInputUtil_DataInputUtil_readShort'", nullptr);
            return 0;
        }
        int ret = cobj->readShort();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "DataInputUtil:readShort",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_DataInputUtil_DataInputUtil_readShort'.",&tolua_err);
#endif

    return 0;
}
int lua_DataInputUtil_DataInputUtil_readInt(lua_State* tolua_S)
{
    int argc = 0;
    DataInputUtil* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"DataInputUtil",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (DataInputUtil*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_DataInputUtil_DataInputUtil_readInt'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_DataInputUtil_DataInputUtil_readInt'", nullptr);
            return 0;
        }
        int ret = cobj->readInt();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "DataInputUtil:readInt",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_DataInputUtil_DataInputUtil_readInt'.",&tolua_err);
#endif

    return 0;
}
int lua_DataInputUtil_DataInputUtil_readBoolean(lua_State* tolua_S)
{
    int argc = 0;
    DataInputUtil* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"DataInputUtil",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (DataInputUtil*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_DataInputUtil_DataInputUtil_readBoolean'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_DataInputUtil_DataInputUtil_readBoolean'", nullptr);
            return 0;
        }
        bool ret = cobj->readBoolean();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "DataInputUtil:readBoolean",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_DataInputUtil_DataInputUtil_readBoolean'.",&tolua_err);
#endif

    return 0;
}
int lua_DataInputUtil_DataInputUtil_readLong(lua_State* tolua_S)
{
    int argc = 0;
    DataInputUtil* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"DataInputUtil",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (DataInputUtil*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_DataInputUtil_DataInputUtil_readLong'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_DataInputUtil_DataInputUtil_readLong'", nullptr);
            return 0;
        }
        unsigned long long ret = cobj->readLong();
        tolua_pushnumber(tolua_S, ret);
        #pragma warning NO CONVERSION FROM NATIVE FOR unsigned long long;
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "DataInputUtil:readLong",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_DataInputUtil_DataInputUtil_readLong'.",&tolua_err);
#endif

    return 0;
}
int lua_DataInputUtil_DataInputUtil_getDatas(lua_State* tolua_S)
{
    int argc = 0;
    DataInputUtil* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"DataInputUtil",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (DataInputUtil*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_DataInputUtil_DataInputUtil_getDatas'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_DataInputUtil_DataInputUtil_getDatas'", nullptr);
            return 0;
        }
        std::list<unsigned char, std::allocator<unsigned char> >* ret = cobj->getDatas();
        object_to_luaval<std::list<unsigned char, std::allocator<unsigned char> >>(tolua_S, "std::list<unsigned char, std::allocator<unsigned char> >*",(std::list<unsigned char, std::allocator<unsigned char> >*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "DataInputUtil:getDatas",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_DataInputUtil_DataInputUtil_getDatas'.",&tolua_err);
#endif

    return 0;
}
int lua_DataInputUtil_DataInputUtil_readByte(lua_State* tolua_S)
{
    int argc = 0;
    DataInputUtil* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"DataInputUtil",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (DataInputUtil*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_DataInputUtil_DataInputUtil_readByte'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_DataInputUtil_DataInputUtil_readByte'", nullptr);
            return 0;
        }
        int ret = cobj->readByte();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "DataInputUtil:readByte",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_DataInputUtil_DataInputUtil_readByte'.",&tolua_err);
#endif

    return 0;
}
int lua_DataInputUtil_DataInputUtil_readUTF(lua_State* tolua_S)
{
    int argc = 0;
    DataInputUtil* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"DataInputUtil",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (DataInputUtil*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_DataInputUtil_DataInputUtil_readUTF'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_DataInputUtil_DataInputUtil_readUTF'", nullptr);
            return 0;
        }
        std::string ret = cobj->readUTF();
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "DataInputUtil:readUTF",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_DataInputUtil_DataInputUtil_readUTF'.",&tolua_err);
#endif

    return 0;
}
int lua_DataInputUtil_DataInputUtil_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"DataInputUtil",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_DataInputUtil_DataInputUtil_create'", nullptr);
            return 0;
        }
        DataInputUtil* ret = DataInputUtil::create();
        object_to_luaval<DataInputUtil>(tolua_S, "DataInputUtil",(DataInputUtil*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "DataInputUtil:create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_DataInputUtil_DataInputUtil_create'.",&tolua_err);
#endif
    return 0;
}
static int lua_DataInputUtil_DataInputUtil_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (DataInputUtil)");
    return 0;
}

int lua_register_DataInputUtil_DataInputUtil(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"DataInputUtil");
    tolua_cclass(tolua_S,"DataInputUtil","DataInputUtil","cc.Ref",nullptr);

    tolua_beginmodule(tolua_S,"DataInputUtil");
        tolua_function(tolua_S,"readShort",lua_DataInputUtil_DataInputUtil_readShort);
        tolua_function(tolua_S,"readInt",lua_DataInputUtil_DataInputUtil_readInt);
        tolua_function(tolua_S,"readBool",lua_DataInputUtil_DataInputUtil_readBoolean);
        tolua_function(tolua_S,"readLong",lua_DataInputUtil_DataInputUtil_readLong);
        tolua_function(tolua_S,"getDatas",lua_DataInputUtil_DataInputUtil_getDatas);
        tolua_function(tolua_S,"readByte",lua_DataInputUtil_DataInputUtil_readByte);
        tolua_function(tolua_S,"readString",lua_DataInputUtil_DataInputUtil_readUTF);
        tolua_function(tolua_S,"create", lua_DataInputUtil_DataInputUtil_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(DataInputUtil).name();
    g_luaType[typeName] = "DataInputUtil";
    g_typeCast["DataInputUtil"] = "DataInputUtil";
    return 1;
}
TOLUA_API int register_all_DataInputUtil(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
	tolua_module(tolua_S,nullptr,0);
	tolua_beginmodule(tolua_S,nullptr);

	lua_register_DataInputUtil_DataInputUtil(tolua_S);

	tolua_endmodule(tolua_S);
	return 1;
}

