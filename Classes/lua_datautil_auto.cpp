#include "lua_datautil_auto.hpp"
#include "DataUtil.h"
#include "tolua_fix.h"
#include "LuaBasicConversions.h"



int lua_DataUtil_DataUtil_setDataInputUtil(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"DataUtil",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        DataInputUtil* arg0;
        ok &= luaval_to_object<DataInputUtil>(tolua_S, 2, "DataInputUtil",&arg0);
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_DataUtil_DataUtil_setDataInputUtil'", nullptr);
            return 0;
        }
        DataUtil::setDataInputUtil(arg0);
        return 0;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "DataUtil:setDataInputUtil",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_DataUtil_DataUtil_setDataInputUtil'.",&tolua_err);
#endif
    return 0;
}
int lua_DataUtil_DataUtil_getDataInputUtil(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"DataUtil",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_DataUtil_DataUtil_getDataInputUtil'", nullptr);
            return 0;
        }
        DataInputUtil* ret = DataUtil::getDataInputUtil();
        object_to_luaval<DataInputUtil>(tolua_S, "DataInputUtil",(DataInputUtil*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "DataUtil:getDataInputUtil",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_DataUtil_DataUtil_getDataInputUtil'.",&tolua_err);
#endif
    return 0;
}
static int lua_DataUtil_DataUtil_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (DataUtil)");
    return 0;
}

int lua_register_DataUtil_DataUtil(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"DataUtil");
    tolua_cclass(tolua_S,"DataUtil","DataUtil","",nullptr);

    tolua_beginmodule(tolua_S,"DataUtil");
        tolua_function(tolua_S,"setDataInputUtil", lua_DataUtil_DataUtil_setDataInputUtil);
        tolua_function(tolua_S,"getDataInputUtil", lua_DataUtil_DataUtil_getDataInputUtil);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(DataUtil).name();
    g_luaType[typeName] = "DataUtil";
    g_typeCast["DataUtil"] = "DataUtil";
    return 1;
}
TOLUA_API int register_all_DataUtil(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
	tolua_module(tolua_S,nullptr,0);
	tolua_beginmodule(tolua_S,nullptr);

	lua_register_DataUtil_DataUtil(tolua_S);

	tolua_endmodule(tolua_S);
	return 1;
}

