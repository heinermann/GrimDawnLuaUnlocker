#include <windows.h>
#include <stdio.h>
#include "hook_macro.h"

HINSTANCE mHinst = 0, mHinstDLL = 0;

UINT_PTR mProcs[135] = {0};

LPCSTR mImportNames[] = {
  "luaJIT_setmode",
  "luaJIT_version_2_0_4",
  "luaL_addlstring",
  "luaL_addstring",
  "luaL_addvalue",
  "luaL_argerror",
  "luaL_buffinit",
  "luaL_callmeta",
  "luaL_checkany",
  "luaL_checkinteger",
  "luaL_checklstring",
  "luaL_checknumber",
  "luaL_checkoption",
  "luaL_checkstack",
  "luaL_checktype",
  "luaL_checkudata",
  "luaL_error",
  "luaL_execresult",
  "luaL_fileresult",
  "luaL_findtable",
  "luaL_getmetafield",
  "luaL_gsub",
  "luaL_loadbuffer",
  "luaL_loadbufferx",
  "luaL_loadfile",
  "luaL_loadfilex",
  "luaL_loadstring",
  "luaL_newmetatable",
  "luaL_newstate",
  "luaL_openlib",
  "luaL_openlibs",
  "luaL_optinteger",
  "luaL_optlstring",
  "luaL_optnumber",
  "luaL_prepbuffer",
  "luaL_pushresult",
  "luaL_ref",
  "luaL_register",
  "luaL_traceback",
  "luaL_typerror",
  "luaL_unref",
  "luaL_where",
  "lua_atpanic",
  "lua_call",
  "lua_checkstack",
  "lua_close",
  "lua_concat",
  "lua_cpcall",
  "lua_createtable",
  "lua_dump",
  "lua_equal",
  "lua_error",
  "lua_gc",
  "lua_getallocf",
  "lua_getfenv",
  "lua_getfield",
  "lua_gethook",
  "lua_gethookcount",
  "lua_gethookmask",
  "lua_getinfo",
  "lua_getlocal",
  "lua_getmetatable",
  "lua_getstack",
  "lua_gettable",
  "lua_gettop",
  "lua_getupvalue",
  "lua_insert",
  "lua_iscfunction",
  "lua_isnumber",
  "lua_isstring",
  "lua_isuserdata",
  "lua_lessthan",
  "lua_load",
  "lua_loadx",
  "lua_newstate",
  "lua_newthread",
  "lua_newuserdata",
  "lua_next",
  "lua_objlen",
  "lua_pcall",
  "lua_pushboolean",
  "lua_pushcclosure",
  "lua_pushfstring",
  "lua_pushinteger",
  "lua_pushlightuserdata",
  "lua_pushlstring",
  "lua_pushnil",
  "lua_pushnumber",
  "lua_pushstring",
  "lua_pushthread",
  "lua_pushvalue",
  "lua_pushvfstring",
  "lua_rawequal",
  "lua_rawget",
  "lua_rawgeti",
  "lua_rawset",
  "lua_rawseti",
  "lua_remove",
  "lua_replace",
  "lua_resume",
  "lua_setallocf",
  "lua_setfenv",
  "lua_setfield",
  "lua_sethook",
  "lua_setlocal",
  "lua_setmetatable",
  "lua_settable",
  "lua_settop",
  "lua_setupvalue",
  "lua_status",
  "lua_toboolean",
  "lua_tocfunction",
  "lua_tointeger",
  "lua_tolstring",
  "lua_tonumber",
  "lua_topointer",
  "lua_tothread",
  "lua_touserdata",
  "lua_type",
  "lua_typename",
  "lua_upvalueid",
  "lua_upvaluejoin",
  "lua_xmove",
  "lua_yield",
  "luaopen_base",
  "luaopen_bit",
  "luaopen_debug",
  "luaopen_ffi",
  "luaopen_io",
  "luaopen_jit",
  "luaopen_math",
  "luaopen_os",
  "luaopen_package",
  "luaopen_string",
  "luaopen_table",
};

#ifndef _DEBUG
inline void log_info(const char* info) {
}
#else
FILE* debug;
inline void log_info(const char* info) {
  fprintf(debug, "%s\n", info);
  fflush(debug);
}
#endif

#include "hook.h"

inline void _hook_setup() {
#ifdef LUAJIT_SETMODE
  luaJIT_setmode_real = (luaJIT_setmode_ptr)mProcs[0];
  mProcs[0] = (UINT_PTR)&luaJIT_setmode_fake;
#endif
#ifdef LUAJIT_VERSION_2_0_4
  luaJIT_version_2_0_4_real = (luaJIT_version_2_0_4_ptr)mProcs[1];
  mProcs[1] = (UINT_PTR)&luaJIT_version_2_0_4_fake;
#endif
#ifdef LUAL_ADDLSTRING
  luaL_addlstring_real = (luaL_addlstring_ptr)mProcs[2];
  mProcs[2] = (UINT_PTR)&luaL_addlstring_fake;
#endif
#ifdef LUAL_ADDSTRING
  luaL_addstring_real = (luaL_addstring_ptr)mProcs[3];
  mProcs[3] = (UINT_PTR)&luaL_addstring_fake;
#endif
#ifdef LUAL_ADDVALUE
  luaL_addvalue_real = (luaL_addvalue_ptr)mProcs[4];
  mProcs[4] = (UINT_PTR)&luaL_addvalue_fake;
#endif
#ifdef LUAL_ARGERROR
  luaL_argerror_real = (luaL_argerror_ptr)mProcs[5];
  mProcs[5] = (UINT_PTR)&luaL_argerror_fake;
#endif
#ifdef LUAL_BUFFINIT
  luaL_buffinit_real = (luaL_buffinit_ptr)mProcs[6];
  mProcs[6] = (UINT_PTR)&luaL_buffinit_fake;
#endif
#ifdef LUAL_CALLMETA
  luaL_callmeta_real = (luaL_callmeta_ptr)mProcs[7];
  mProcs[7] = (UINT_PTR)&luaL_callmeta_fake;
#endif
#ifdef LUAL_CHECKANY
  luaL_checkany_real = (luaL_checkany_ptr)mProcs[8];
  mProcs[8] = (UINT_PTR)&luaL_checkany_fake;
#endif
#ifdef LUAL_CHECKINTEGER
  luaL_checkinteger_real = (luaL_checkinteger_ptr)mProcs[9];
  mProcs[9] = (UINT_PTR)&luaL_checkinteger_fake;
#endif
#ifdef LUAL_CHECKLSTRING
  luaL_checklstring_real = (luaL_checklstring_ptr)mProcs[10];
  mProcs[10] = (UINT_PTR)&luaL_checklstring_fake;
#endif
#ifdef LUAL_CHECKNUMBER
  luaL_checknumber_real = (luaL_checknumber_ptr)mProcs[11];
  mProcs[11] = (UINT_PTR)&luaL_checknumber_fake;
#endif
#ifdef LUAL_CHECKOPTION
  luaL_checkoption_real = (luaL_checkoption_ptr)mProcs[12];
  mProcs[12] = (UINT_PTR)&luaL_checkoption_fake;
#endif
#ifdef LUAL_CHECKSTACK
  luaL_checkstack_real = (luaL_checkstack_ptr)mProcs[13];
  mProcs[13] = (UINT_PTR)&luaL_checkstack_fake;
#endif
#ifdef LUAL_CHECKTYPE
  luaL_checktype_real = (luaL_checktype_ptr)mProcs[14];
  mProcs[14] = (UINT_PTR)&luaL_checktype_fake;
#endif
#ifdef LUAL_CHECKUDATA
  luaL_checkudata_real = (luaL_checkudata_ptr)mProcs[15];
  mProcs[15] = (UINT_PTR)&luaL_checkudata_fake;
#endif
#ifdef LUAL_ERROR
  luaL_error_real = (luaL_error_ptr)mProcs[16];
  mProcs[16] = (UINT_PTR)&luaL_error_fake;
#endif
#ifdef LUAL_EXECRESULT
  luaL_execresult_real = (luaL_execresult_ptr)mProcs[17];
  mProcs[17] = (UINT_PTR)&luaL_execresult_fake;
#endif
#ifdef LUAL_FILERESULT
  luaL_fileresult_real = (luaL_fileresult_ptr)mProcs[18];
  mProcs[18] = (UINT_PTR)&luaL_fileresult_fake;
#endif
#ifdef LUAL_FINDTABLE
  luaL_findtable_real = (luaL_findtable_ptr)mProcs[19];
  mProcs[19] = (UINT_PTR)&luaL_findtable_fake;
#endif
#ifdef LUAL_GETMETAFIELD
  luaL_getmetafield_real = (luaL_getmetafield_ptr)mProcs[20];
  mProcs[20] = (UINT_PTR)&luaL_getmetafield_fake;
#endif
#ifdef LUAL_GSUB
  luaL_gsub_real = (luaL_gsub_ptr)mProcs[21];
  mProcs[21] = (UINT_PTR)&luaL_gsub_fake;
#endif
#ifdef LUAL_LOADBUFFER
  luaL_loadbuffer_real = (luaL_loadbuffer_ptr)mProcs[22];
  mProcs[22] = (UINT_PTR)&luaL_loadbuffer_fake;
#endif
#ifdef LUAL_LOADBUFFERX
  luaL_loadbufferx_real = (luaL_loadbufferx_ptr)mProcs[23];
  mProcs[23] = (UINT_PTR)&luaL_loadbufferx_fake;
#endif
#ifdef LUAL_LOADFILE
  luaL_loadfile_real = (luaL_loadfile_ptr)mProcs[24];
  mProcs[24] = (UINT_PTR)&luaL_loadfile_fake;
#endif
#ifdef LUAL_LOADFILEX
  luaL_loadfilex_real = (luaL_loadfilex_ptr)mProcs[25];
  mProcs[25] = (UINT_PTR)&luaL_loadfilex_fake;
#endif
#ifdef LUAL_LOADSTRING
  luaL_loadstring_real = (luaL_loadstring_ptr)mProcs[26];
  mProcs[26] = (UINT_PTR)&luaL_loadstring_fake;
#endif
#ifdef LUAL_NEWMETATABLE
  luaL_newmetatable_real = (luaL_newmetatable_ptr)mProcs[27];
  mProcs[27] = (UINT_PTR)&luaL_newmetatable_fake;
#endif
#ifdef LUAL_NEWSTATE
  luaL_newstate_real = (luaL_newstate_ptr)mProcs[28];
  mProcs[28] = (UINT_PTR)&luaL_newstate_fake;
#endif
#ifdef LUAL_OPENLIB
  luaL_openlib_real = (luaL_openlib_ptr)mProcs[29];
  mProcs[29] = (UINT_PTR)&luaL_openlib_fake;
#endif
#ifdef LUAL_OPENLIBS
  luaL_openlibs_real = (luaL_openlibs_ptr)mProcs[30];
  mProcs[30] = (UINT_PTR)&luaL_openlibs_fake;
#endif
#ifdef LUAL_OPTINTEGER
  luaL_optinteger_real = (luaL_optinteger_ptr)mProcs[31];
  mProcs[31] = (UINT_PTR)&luaL_optinteger_fake;
#endif
#ifdef LUAL_OPTLSTRING
  luaL_optlstring_real = (luaL_optlstring_ptr)mProcs[32];
  mProcs[32] = (UINT_PTR)&luaL_optlstring_fake;
#endif
#ifdef LUAL_OPTNUMBER
  luaL_optnumber_real = (luaL_optnumber_ptr)mProcs[33];
  mProcs[33] = (UINT_PTR)&luaL_optnumber_fake;
#endif
#ifdef LUAL_PREPBUFFER
  luaL_prepbuffer_real = (luaL_prepbuffer_ptr)mProcs[34];
  mProcs[34] = (UINT_PTR)&luaL_prepbuffer_fake;
#endif
#ifdef LUAL_PUSHRESULT
  luaL_pushresult_real = (luaL_pushresult_ptr)mProcs[35];
  mProcs[35] = (UINT_PTR)&luaL_pushresult_fake;
#endif
#ifdef LUAL_REF
  luaL_ref_real = (luaL_ref_ptr)mProcs[36];
  mProcs[36] = (UINT_PTR)&luaL_ref_fake;
#endif
#ifdef LUAL_REGISTER
  luaL_register_real = (luaL_register_ptr)mProcs[37];
  mProcs[37] = (UINT_PTR)&luaL_register_fake;
#endif
#ifdef LUAL_TRACEBACK
  luaL_traceback_real = (luaL_traceback_ptr)mProcs[38];
  mProcs[38] = (UINT_PTR)&luaL_traceback_fake;
#endif
#ifdef LUAL_TYPERROR
  luaL_typerror_real = (luaL_typerror_ptr)mProcs[39];
  mProcs[39] = (UINT_PTR)&luaL_typerror_fake;
#endif
#ifdef LUAL_UNREF
  luaL_unref_real = (luaL_unref_ptr)mProcs[40];
  mProcs[40] = (UINT_PTR)&luaL_unref_fake;
#endif
#ifdef LUAL_WHERE
  luaL_where_real = (luaL_where_ptr)mProcs[41];
  mProcs[41] = (UINT_PTR)&luaL_where_fake;
#endif
#ifdef LUA_ATPANIC
  lua_atpanic_real = (lua_atpanic_ptr)mProcs[42];
  mProcs[42] = (UINT_PTR)&lua_atpanic_fake;
#endif
#ifdef LUA_CALL
  lua_call_real = (lua_call_ptr)mProcs[43];
  mProcs[43] = (UINT_PTR)&lua_call_fake;
#endif
#ifdef LUA_CHECKSTACK
  lua_checkstack_real = (lua_checkstack_ptr)mProcs[44];
  mProcs[44] = (UINT_PTR)&lua_checkstack_fake;
#endif
#ifdef LUA_CLOSE
  lua_close_real = (lua_close_ptr)mProcs[45];
  mProcs[45] = (UINT_PTR)&lua_close_fake;
#endif
#ifdef LUA_CONCAT
  lua_concat_real = (lua_concat_ptr)mProcs[46];
  mProcs[46] = (UINT_PTR)&lua_concat_fake;
#endif
#ifdef LUA_CPCALL
  lua_cpcall_real = (lua_cpcall_ptr)mProcs[47];
  mProcs[47] = (UINT_PTR)&lua_cpcall_fake;
#endif
#ifdef LUA_CREATETABLE
  lua_createtable_real = (lua_createtable_ptr)mProcs[48];
  mProcs[48] = (UINT_PTR)&lua_createtable_fake;
#endif
#ifdef LUA_DUMP
  lua_dump_real = (lua_dump_ptr)mProcs[49];
  mProcs[49] = (UINT_PTR)&lua_dump_fake;
#endif
#ifdef LUA_EQUAL
  lua_equal_real = (lua_equal_ptr)mProcs[50];
  mProcs[50] = (UINT_PTR)&lua_equal_fake;
#endif
#ifdef LUA_ERROR
  lua_error_real = (lua_error_ptr)mProcs[51];
  mProcs[51] = (UINT_PTR)&lua_error_fake;
#endif
#ifdef LUA_GC
  lua_gc_real = (lua_gc_ptr)mProcs[52];
  mProcs[52] = (UINT_PTR)&lua_gc_fake;
#endif
#ifdef LUA_GETALLOCF
  lua_getallocf_real = (lua_getallocf_ptr)mProcs[53];
  mProcs[53] = (UINT_PTR)&lua_getallocf_fake;
#endif
#ifdef LUA_GETFENV
  lua_getfenv_real = (lua_getfenv_ptr)mProcs[54];
  mProcs[54] = (UINT_PTR)&lua_getfenv_fake;
#endif
#ifdef LUA_GETFIELD
  lua_getfield_real = (lua_getfield_ptr)mProcs[55];
  mProcs[55] = (UINT_PTR)&lua_getfield_fake;
#endif
#ifdef LUA_GETHOOK
  lua_gethook_real = (lua_gethook_ptr)mProcs[56];
  mProcs[56] = (UINT_PTR)&lua_gethook_fake;
#endif
#ifdef LUA_GETHOOKCOUNT
  lua_gethookcount_real = (lua_gethookcount_ptr)mProcs[57];
  mProcs[57] = (UINT_PTR)&lua_gethookcount_fake;
#endif
#ifdef LUA_GETHOOKMASK
  lua_gethookmask_real = (lua_gethookmask_ptr)mProcs[58];
  mProcs[58] = (UINT_PTR)&lua_gethookmask_fake;
#endif
#ifdef LUA_GETINFO
  lua_getinfo_real = (lua_getinfo_ptr)mProcs[59];
  mProcs[59] = (UINT_PTR)&lua_getinfo_fake;
#endif
#ifdef LUA_GETLOCAL
  lua_getlocal_real = (lua_getlocal_ptr)mProcs[60];
  mProcs[60] = (UINT_PTR)&lua_getlocal_fake;
#endif
#ifdef LUA_GETMETATABLE
  lua_getmetatable_real = (lua_getmetatable_ptr)mProcs[61];
  mProcs[61] = (UINT_PTR)&lua_getmetatable_fake;
#endif
#ifdef LUA_GETSTACK
  lua_getstack_real = (lua_getstack_ptr)mProcs[62];
  mProcs[62] = (UINT_PTR)&lua_getstack_fake;
#endif
#ifdef LUA_GETTABLE
  lua_gettable_real = (lua_gettable_ptr)mProcs[63];
  mProcs[63] = (UINT_PTR)&lua_gettable_fake;
#endif
#ifdef LUA_GETTOP
  lua_gettop_real = (lua_gettop_ptr)mProcs[64];
  mProcs[64] = (UINT_PTR)&lua_gettop_fake;
#endif
#ifdef LUA_GETUPVALUE
  lua_getupvalue_real = (lua_getupvalue_ptr)mProcs[65];
  mProcs[65] = (UINT_PTR)&lua_getupvalue_fake;
#endif
#ifdef LUA_INSERT
  lua_insert_real = (lua_insert_ptr)mProcs[66];
  mProcs[66] = (UINT_PTR)&lua_insert_fake;
#endif
#ifdef LUA_ISCFUNCTION
  lua_iscfunction_real = (lua_iscfunction_ptr)mProcs[67];
  mProcs[67] = (UINT_PTR)&lua_iscfunction_fake;
#endif
#ifdef LUA_ISNUMBER
  lua_isnumber_real = (lua_isnumber_ptr)mProcs[68];
  mProcs[68] = (UINT_PTR)&lua_isnumber_fake;
#endif
#ifdef LUA_ISSTRING
  lua_isstring_real = (lua_isstring_ptr)mProcs[69];
  mProcs[69] = (UINT_PTR)&lua_isstring_fake;
#endif
#ifdef LUA_ISUSERDATA
  lua_isuserdata_real = (lua_isuserdata_ptr)mProcs[70];
  mProcs[70] = (UINT_PTR)&lua_isuserdata_fake;
#endif
#ifdef LUA_LESSTHAN
  lua_lessthan_real = (lua_lessthan_ptr)mProcs[71];
  mProcs[71] = (UINT_PTR)&lua_lessthan_fake;
#endif
#ifdef LUA_LOAD
  lua_load_real = (lua_load_ptr)mProcs[72];
  mProcs[72] = (UINT_PTR)&lua_load_fake;
#endif
#ifdef LUA_LOADX
  lua_loadx_real = (lua_loadx_ptr)mProcs[73];
  mProcs[73] = (UINT_PTR)&lua_loadx_fake;
#endif
#ifdef LUA_NEWSTATE
  lua_newstate_real = (lua_newstate_ptr)mProcs[74];
  mProcs[74] = (UINT_PTR)&lua_newstate_fake;
#endif
#ifdef LUA_NEWTHREAD
  lua_newthread_real = (lua_newthread_ptr)mProcs[75];
  mProcs[75] = (UINT_PTR)&lua_newthread_fake;
#endif
#ifdef LUA_NEWUSERDATA
  lua_newuserdata_real = (lua_newuserdata_ptr)mProcs[76];
  mProcs[76] = (UINT_PTR)&lua_newuserdata_fake;
#endif
#ifdef LUA_NEXT
  lua_next_real = (lua_next_ptr)mProcs[77];
  mProcs[77] = (UINT_PTR)&lua_next_fake;
#endif
#ifdef LUA_OBJLEN
  lua_objlen_real = (lua_objlen_ptr)mProcs[78];
  mProcs[78] = (UINT_PTR)&lua_objlen_fake;
#endif
#ifdef LUA_PCALL
  lua_pcall_real = (lua_pcall_ptr)mProcs[79];
  mProcs[79] = (UINT_PTR)&lua_pcall_fake;
#endif
#ifdef LUA_PUSHBOOLEAN
  lua_pushboolean_real = (lua_pushboolean_ptr)mProcs[80];
  mProcs[80] = (UINT_PTR)&lua_pushboolean_fake;
#endif
#ifdef LUA_PUSHCCLOSURE
  lua_pushcclosure_real = (lua_pushcclosure_ptr)mProcs[81];
  mProcs[81] = (UINT_PTR)&lua_pushcclosure_fake;
#endif
#ifdef LUA_PUSHFSTRING
  lua_pushfstring_real = (lua_pushfstring_ptr)mProcs[82];
  mProcs[82] = (UINT_PTR)&lua_pushfstring_fake;
#endif
#ifdef LUA_PUSHINTEGER
  lua_pushinteger_real = (lua_pushinteger_ptr)mProcs[83];
  mProcs[83] = (UINT_PTR)&lua_pushinteger_fake;
#endif
#ifdef LUA_PUSHLIGHTUSERDATA
  lua_pushlightuserdata_real = (lua_pushlightuserdata_ptr)mProcs[84];
  mProcs[84] = (UINT_PTR)&lua_pushlightuserdata_fake;
#endif
#ifdef LUA_PUSHLSTRING
  lua_pushlstring_real = (lua_pushlstring_ptr)mProcs[85];
  mProcs[85] = (UINT_PTR)&lua_pushlstring_fake;
#endif
#ifdef LUA_PUSHNIL
  lua_pushnil_real = (lua_pushnil_ptr)mProcs[86];
  mProcs[86] = (UINT_PTR)&lua_pushnil_fake;
#endif
#ifdef LUA_PUSHNUMBER
  lua_pushnumber_real = (lua_pushnumber_ptr)mProcs[87];
  mProcs[87] = (UINT_PTR)&lua_pushnumber_fake;
#endif
#ifdef LUA_PUSHSTRING
  lua_pushstring_real = (lua_pushstring_ptr)mProcs[88];
  mProcs[88] = (UINT_PTR)&lua_pushstring_fake;
#endif
#ifdef LUA_PUSHTHREAD
  lua_pushthread_real = (lua_pushthread_ptr)mProcs[89];
  mProcs[89] = (UINT_PTR)&lua_pushthread_fake;
#endif
#ifdef LUA_PUSHVALUE
  lua_pushvalue_real = (lua_pushvalue_ptr)mProcs[90];
  mProcs[90] = (UINT_PTR)&lua_pushvalue_fake;
#endif
#ifdef LUA_PUSHVFSTRING
  lua_pushvfstring_real = (lua_pushvfstring_ptr)mProcs[91];
  mProcs[91] = (UINT_PTR)&lua_pushvfstring_fake;
#endif
#ifdef LUA_RAWEQUAL
  lua_rawequal_real = (lua_rawequal_ptr)mProcs[92];
  mProcs[92] = (UINT_PTR)&lua_rawequal_fake;
#endif
#ifdef LUA_RAWGET
  lua_rawget_real = (lua_rawget_ptr)mProcs[93];
  mProcs[93] = (UINT_PTR)&lua_rawget_fake;
#endif
#ifdef LUA_RAWGETI
  lua_rawgeti_real = (lua_rawgeti_ptr)mProcs[94];
  mProcs[94] = (UINT_PTR)&lua_rawgeti_fake;
#endif
#ifdef LUA_RAWSET
  lua_rawset_real = (lua_rawset_ptr)mProcs[95];
  mProcs[95] = (UINT_PTR)&lua_rawset_fake;
#endif
#ifdef LUA_RAWSETI
  lua_rawseti_real = (lua_rawseti_ptr)mProcs[96];
  mProcs[96] = (UINT_PTR)&lua_rawseti_fake;
#endif
#ifdef LUA_REMOVE
  lua_remove_real = (lua_remove_ptr)mProcs[97];
  mProcs[97] = (UINT_PTR)&lua_remove_fake;
#endif
#ifdef LUA_REPLACE
  lua_replace_real = (lua_replace_ptr)mProcs[98];
  mProcs[98] = (UINT_PTR)&lua_replace_fake;
#endif
#ifdef LUA_RESUME
  lua_resume_real = (lua_resume_ptr)mProcs[99];
  mProcs[99] = (UINT_PTR)&lua_resume_fake;
#endif
#ifdef LUA_SETALLOCF
  lua_setallocf_real = (lua_setallocf_ptr)mProcs[100];
  mProcs[100] = (UINT_PTR)&lua_setallocf_fake;
#endif
#ifdef LUA_SETFENV
  lua_setfenv_real = (lua_setfenv_ptr)mProcs[101];
  mProcs[101] = (UINT_PTR)&lua_setfenv_fake;
#endif
#ifdef LUA_SETFIELD
  lua_setfield_real = (lua_setfield_ptr)mProcs[102];
  mProcs[102] = (UINT_PTR)&lua_setfield_fake;
#endif
#ifdef LUA_SETHOOK
  lua_sethook_real = (lua_sethook_ptr)mProcs[103];
  mProcs[103] = (UINT_PTR)&lua_sethook_fake;
#endif
#ifdef LUA_SETLOCAL
  lua_setlocal_real = (lua_setlocal_ptr)mProcs[104];
  mProcs[104] = (UINT_PTR)&lua_setlocal_fake;
#endif
#ifdef LUA_SETMETATABLE
  lua_setmetatable_real = (lua_setmetatable_ptr)mProcs[105];
  mProcs[105] = (UINT_PTR)&lua_setmetatable_fake;
#endif
#ifdef LUA_SETTABLE
  lua_settable_real = (lua_settable_ptr)mProcs[106];
  mProcs[106] = (UINT_PTR)&lua_settable_fake;
#endif
#ifdef LUA_SETTOP
  lua_settop_real = (lua_settop_ptr)mProcs[107];
  mProcs[107] = (UINT_PTR)&lua_settop_fake;
#endif
#ifdef LUA_SETUPVALUE
  lua_setupvalue_real = (lua_setupvalue_ptr)mProcs[108];
  mProcs[108] = (UINT_PTR)&lua_setupvalue_fake;
#endif
#ifdef LUA_STATUS
  lua_status_real = (lua_status_ptr)mProcs[109];
  mProcs[109] = (UINT_PTR)&lua_status_fake;
#endif
#ifdef LUA_TOBOOLEAN
  lua_toboolean_real = (lua_toboolean_ptr)mProcs[110];
  mProcs[110] = (UINT_PTR)&lua_toboolean_fake;
#endif
#ifdef LUA_TOCFUNCTION
  lua_tocfunction_real = (lua_tocfunction_ptr)mProcs[111];
  mProcs[111] = (UINT_PTR)&lua_tocfunction_fake;
#endif
#ifdef LUA_TOINTEGER
  lua_tointeger_real = (lua_tointeger_ptr)mProcs[112];
  mProcs[112] = (UINT_PTR)&lua_tointeger_fake;
#endif
#ifdef LUA_TOLSTRING
  lua_tolstring_real = (lua_tolstring_ptr)mProcs[113];
  mProcs[113] = (UINT_PTR)&lua_tolstring_fake;
#endif
#ifdef LUA_TONUMBER
  lua_tonumber_real = (lua_tonumber_ptr)mProcs[114];
  mProcs[114] = (UINT_PTR)&lua_tonumber_fake;
#endif
#ifdef LUA_TOPOINTER
  lua_topointer_real = (lua_topointer_ptr)mProcs[115];
  mProcs[115] = (UINT_PTR)&lua_topointer_fake;
#endif
#ifdef LUA_TOTHREAD
  lua_tothread_real = (lua_tothread_ptr)mProcs[116];
  mProcs[116] = (UINT_PTR)&lua_tothread_fake;
#endif
#ifdef LUA_TOUSERDATA
  lua_touserdata_real = (lua_touserdata_ptr)mProcs[117];
  mProcs[117] = (UINT_PTR)&lua_touserdata_fake;
#endif
#ifdef LUA_TYPE
  lua_type_real = (lua_type_ptr)mProcs[118];
  mProcs[118] = (UINT_PTR)&lua_type_fake;
#endif
#ifdef LUA_TYPENAME
  lua_typename_real = (lua_typename_ptr)mProcs[119];
  mProcs[119] = (UINT_PTR)&lua_typename_fake;
#endif
#ifdef LUA_UPVALUEID
  lua_upvalueid_real = (lua_upvalueid_ptr)mProcs[120];
  mProcs[120] = (UINT_PTR)&lua_upvalueid_fake;
#endif
#ifdef LUA_UPVALUEJOIN
  lua_upvaluejoin_real = (lua_upvaluejoin_ptr)mProcs[121];
  mProcs[121] = (UINT_PTR)&lua_upvaluejoin_fake;
#endif
#ifdef LUA_XMOVE
  lua_xmove_real = (lua_xmove_ptr)mProcs[122];
  mProcs[122] = (UINT_PTR)&lua_xmove_fake;
#endif
#ifdef LUA_YIELD
  lua_yield_real = (lua_yield_ptr)mProcs[123];
  mProcs[123] = (UINT_PTR)&lua_yield_fake;
#endif
#ifdef LUAOPEN_BASE
  luaopen_base_real = (luaopen_base_ptr)mProcs[124];
  mProcs[124] = (UINT_PTR)&luaopen_base_fake;
#endif
#ifdef LUAOPEN_BIT
  luaopen_bit_real = (luaopen_bit_ptr)mProcs[125];
  mProcs[125] = (UINT_PTR)&luaopen_bit_fake;
#endif
#ifdef LUAOPEN_DEBUG
  luaopen_debug_real = (luaopen_debug_ptr)mProcs[126];
  mProcs[126] = (UINT_PTR)&luaopen_debug_fake;
#endif
#ifdef LUAOPEN_FFI
  luaopen_ffi_real = (luaopen_ffi_ptr)mProcs[127];
  mProcs[127] = (UINT_PTR)&luaopen_ffi_fake;
#endif
#ifdef LUAOPEN_IO
  luaopen_io_real = (luaopen_io_ptr)mProcs[128];
  mProcs[128] = (UINT_PTR)&luaopen_io_fake;
#endif
#ifdef LUAOPEN_JIT
  luaopen_jit_real = (luaopen_jit_ptr)mProcs[129];
  mProcs[129] = (UINT_PTR)&luaopen_jit_fake;
#endif
#ifdef LUAOPEN_MATH
  luaopen_math_real = (luaopen_math_ptr)mProcs[130];
  mProcs[130] = (UINT_PTR)&luaopen_math_fake;
#endif
#ifdef LUAOPEN_OS
  luaopen_os_real = (luaopen_os_ptr)mProcs[131];
  mProcs[131] = (UINT_PTR)&luaopen_os_fake;
#endif
#ifdef LUAOPEN_PACKAGE
  luaopen_package_real = (luaopen_package_ptr)mProcs[132];
  mProcs[132] = (UINT_PTR)&luaopen_package_fake;
#endif
#ifdef LUAOPEN_STRING
  luaopen_string_real = (luaopen_string_ptr)mProcs[133];
  mProcs[133] = (UINT_PTR)&luaopen_string_fake;
#endif
#ifdef LUAOPEN_TABLE
  luaopen_table_real = (luaopen_table_ptr)mProcs[134];
  mProcs[134] = (UINT_PTR)&luaopen_table_fake;
#endif
}

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved) {
  mHinst = hinstDLL;
  if (fdwReason == DLL_PROCESS_ATTACH) {
    mHinstDLL = LoadLibrary("real_lua51.dll");
    if (!mHinstDLL) {
      return FALSE;
    }
    for (int i = 0; i < 135; ++i) {
      mProcs[i] = (UINT_PTR)GetProcAddress(mHinstDLL, mImportNames[i]);
    }
    _hook_setup();
#ifdef _DEBUG
    debug = fopen("./debug.log", "a");
#endif
  } else if (fdwReason == DLL_PROCESS_DETACH) {
#ifdef _DEBUG
    fclose(debug);
#endif
    FreeLibrary(mHinstDLL);
  }
  return TRUE;
}

extern "C" __declspec(naked) void __stdcall luaJIT_setmode_wrapper(){
#ifdef _DEBUG
  log_info("calling luaJIT_setmode");
#endif
  __asm{jmp mProcs[0 * 4]}
}
extern "C" __declspec(naked) void __stdcall luaJIT_version_2_0_4_wrapper(){
#ifdef _DEBUG
  log_info("calling luaJIT_version_2_0_4");
#endif
  __asm{jmp mProcs[1 * 4]}
}
extern "C" __declspec(naked) void __stdcall luaL_addlstring_wrapper(){
#ifdef _DEBUG
  log_info("calling luaL_addlstring");
#endif
  __asm{jmp mProcs[2 * 4]}
}
extern "C" __declspec(naked) void __stdcall luaL_addstring_wrapper(){
#ifdef _DEBUG
  log_info("calling luaL_addstring");
#endif
  __asm{jmp mProcs[3 * 4]}
}
extern "C" __declspec(naked) void __stdcall luaL_addvalue_wrapper(){
#ifdef _DEBUG
  log_info("calling luaL_addvalue");
#endif
  __asm{jmp mProcs[4 * 4]}
}
extern "C" __declspec(naked) void __stdcall luaL_argerror_wrapper(){
#ifdef _DEBUG
  log_info("calling luaL_argerror");
#endif
  __asm{jmp mProcs[5 * 4]}
}
extern "C" __declspec(naked) void __stdcall luaL_buffinit_wrapper(){
#ifdef _DEBUG
  log_info("calling luaL_buffinit");
#endif
  __asm{jmp mProcs[6 * 4]}
}
extern "C" __declspec(naked) void __stdcall luaL_callmeta_wrapper(){
#ifdef _DEBUG
  log_info("calling luaL_callmeta");
#endif
  __asm{jmp mProcs[7 * 4]}
}
extern "C" __declspec(naked) void __stdcall luaL_checkany_wrapper(){
#ifdef _DEBUG
  log_info("calling luaL_checkany");
#endif
  __asm{jmp mProcs[8 * 4]}
}
extern "C" __declspec(naked) void __stdcall luaL_checkinteger_wrapper(){
#ifdef _DEBUG
  log_info("calling luaL_checkinteger");
#endif
  __asm{jmp mProcs[9 * 4]}
}
extern "C" __declspec(naked) void __stdcall luaL_checklstring_wrapper(){
#ifdef _DEBUG
  log_info("calling luaL_checklstring");
#endif
  __asm{jmp mProcs[10 * 4]}
}
extern "C" __declspec(naked) void __stdcall luaL_checknumber_wrapper(){
#ifdef _DEBUG
  log_info("calling luaL_checknumber");
#endif
  __asm{jmp mProcs[11 * 4]}
}
extern "C" __declspec(naked) void __stdcall luaL_checkoption_wrapper(){
#ifdef _DEBUG
  log_info("calling luaL_checkoption");
#endif
  __asm{jmp mProcs[12 * 4]}
}
extern "C" __declspec(naked) void __stdcall luaL_checkstack_wrapper(){
#ifdef _DEBUG
  log_info("calling luaL_checkstack");
#endif
  __asm{jmp mProcs[13 * 4]}
}
extern "C" __declspec(naked) void __stdcall luaL_checktype_wrapper(){
#ifdef _DEBUG
  log_info("calling luaL_checktype");
#endif
  __asm{jmp mProcs[14 * 4]}
}
extern "C" __declspec(naked) void __stdcall luaL_checkudata_wrapper(){
#ifdef _DEBUG
  log_info("calling luaL_checkudata");
#endif
  __asm{jmp mProcs[15 * 4]}
}
extern "C" __declspec(naked) void __stdcall luaL_error_wrapper(){
#ifdef _DEBUG
  log_info("calling luaL_error");
#endif
  __asm{jmp mProcs[16 * 4]}
}
extern "C" __declspec(naked) void __stdcall luaL_execresult_wrapper(){
#ifdef _DEBUG
  log_info("calling luaL_execresult");
#endif
  __asm{jmp mProcs[17 * 4]}
}
extern "C" __declspec(naked) void __stdcall luaL_fileresult_wrapper(){
#ifdef _DEBUG
  log_info("calling luaL_fileresult");
#endif
  __asm{jmp mProcs[18 * 4]}
}
extern "C" __declspec(naked) void __stdcall luaL_findtable_wrapper(){
#ifdef _DEBUG
  log_info("calling luaL_findtable");
#endif
  __asm{jmp mProcs[19 * 4]}
}
extern "C" __declspec(naked) void __stdcall luaL_getmetafield_wrapper(){
#ifdef _DEBUG
  log_info("calling luaL_getmetafield");
#endif
  __asm{jmp mProcs[20 * 4]}
}
extern "C" __declspec(naked) void __stdcall luaL_gsub_wrapper(){
#ifdef _DEBUG
  log_info("calling luaL_gsub");
#endif
  __asm{jmp mProcs[21 * 4]}
}
extern "C" __declspec(naked) void __stdcall luaL_loadbuffer_wrapper(){
#ifdef _DEBUG
  log_info("calling luaL_loadbuffer");
#endif
  __asm{jmp mProcs[22 * 4]}
}
extern "C" __declspec(naked) void __stdcall luaL_loadbufferx_wrapper(){
#ifdef _DEBUG
  log_info("calling luaL_loadbufferx");
#endif
  __asm{jmp mProcs[23 * 4]}
}
extern "C" __declspec(naked) void __stdcall luaL_loadfile_wrapper(){
#ifdef _DEBUG
  log_info("calling luaL_loadfile");
#endif
  __asm{jmp mProcs[24 * 4]}
}
extern "C" __declspec(naked) void __stdcall luaL_loadfilex_wrapper(){
#ifdef _DEBUG
  log_info("calling luaL_loadfilex");
#endif
  __asm{jmp mProcs[25 * 4]}
}
extern "C" __declspec(naked) void __stdcall luaL_loadstring_wrapper(){
#ifdef _DEBUG
  log_info("calling luaL_loadstring");
#endif
  __asm{jmp mProcs[26 * 4]}
}
extern "C" __declspec(naked) void __stdcall luaL_newmetatable_wrapper(){
#ifdef _DEBUG
  log_info("calling luaL_newmetatable");
#endif
  __asm{jmp mProcs[27 * 4]}
}
extern "C" __declspec(naked) void __stdcall luaL_newstate_wrapper(){
#ifdef _DEBUG
  log_info("calling luaL_newstate");
#endif
  __asm{jmp mProcs[28 * 4]}
}
extern "C" __declspec(naked) void __stdcall luaL_openlib_wrapper(){
#ifdef _DEBUG
  log_info("calling luaL_openlib");
#endif
  __asm{jmp mProcs[29 * 4]}
}
extern "C" __declspec(naked) void __stdcall luaL_openlibs_wrapper(){
#ifdef _DEBUG
  log_info("calling luaL_openlibs");
#endif
  __asm{jmp mProcs[30 * 4]}
}
extern "C" __declspec(naked) void __stdcall luaL_optinteger_wrapper(){
#ifdef _DEBUG
  log_info("calling luaL_optinteger");
#endif
  __asm{jmp mProcs[31 * 4]}
}
extern "C" __declspec(naked) void __stdcall luaL_optlstring_wrapper(){
#ifdef _DEBUG
  log_info("calling luaL_optlstring");
#endif
  __asm{jmp mProcs[32 * 4]}
}
extern "C" __declspec(naked) void __stdcall luaL_optnumber_wrapper(){
#ifdef _DEBUG
  log_info("calling luaL_optnumber");
#endif
  __asm{jmp mProcs[33 * 4]}
}
extern "C" __declspec(naked) void __stdcall luaL_prepbuffer_wrapper(){
#ifdef _DEBUG
  log_info("calling luaL_prepbuffer");
#endif
  __asm{jmp mProcs[34 * 4]}
}
extern "C" __declspec(naked) void __stdcall luaL_pushresult_wrapper(){
#ifdef _DEBUG
  log_info("calling luaL_pushresult");
#endif
  __asm{jmp mProcs[35 * 4]}
}
extern "C" __declspec(naked) void __stdcall luaL_ref_wrapper(){
#ifdef _DEBUG
  log_info("calling luaL_ref");
#endif
  __asm{jmp mProcs[36 * 4]}
}
extern "C" __declspec(naked) void __stdcall luaL_register_wrapper(){
#ifdef _DEBUG
  log_info("calling luaL_register");
#endif
  __asm{jmp mProcs[37 * 4]}
}
extern "C" __declspec(naked) void __stdcall luaL_traceback_wrapper(){
#ifdef _DEBUG
  log_info("calling luaL_traceback");
#endif
  __asm{jmp mProcs[38 * 4]}
}
extern "C" __declspec(naked) void __stdcall luaL_typerror_wrapper(){
#ifdef _DEBUG
  log_info("calling luaL_typerror");
#endif
  __asm{jmp mProcs[39 * 4]}
}
extern "C" __declspec(naked) void __stdcall luaL_unref_wrapper(){
#ifdef _DEBUG
  log_info("calling luaL_unref");
#endif
  __asm{jmp mProcs[40 * 4]}
}
extern "C" __declspec(naked) void __stdcall luaL_where_wrapper(){
#ifdef _DEBUG
  log_info("calling luaL_where");
#endif
  __asm{jmp mProcs[41 * 4]}
}
extern "C" __declspec(naked) void __stdcall lua_atpanic_wrapper(){
#ifdef _DEBUG
  log_info("calling lua_atpanic");
#endif
  __asm{jmp mProcs[42 * 4]}
}
extern "C" __declspec(naked) void __stdcall lua_call_wrapper(){
#ifdef _DEBUG
  log_info("calling lua_call");
#endif
  __asm{jmp mProcs[43 * 4]}
}
extern "C" __declspec(naked) void __stdcall lua_checkstack_wrapper(){
#ifdef _DEBUG
  log_info("calling lua_checkstack");
#endif
  __asm{jmp mProcs[44 * 4]}
}
extern "C" __declspec(naked) void __stdcall lua_close_wrapper(){
#ifdef _DEBUG
  log_info("calling lua_close");
#endif
  __asm{jmp mProcs[45 * 4]}
}
extern "C" __declspec(naked) void __stdcall lua_concat_wrapper(){
#ifdef _DEBUG
  log_info("calling lua_concat");
#endif
  __asm{jmp mProcs[46 * 4]}
}
extern "C" __declspec(naked) void __stdcall lua_cpcall_wrapper(){
#ifdef _DEBUG
  log_info("calling lua_cpcall");
#endif
  __asm{jmp mProcs[47 * 4]}
}
extern "C" __declspec(naked) void __stdcall lua_createtable_wrapper(){
#ifdef _DEBUG
  log_info("calling lua_createtable");
#endif
  __asm{jmp mProcs[48 * 4]}
}
extern "C" __declspec(naked) void __stdcall lua_dump_wrapper(){
#ifdef _DEBUG
  log_info("calling lua_dump");
#endif
  __asm{jmp mProcs[49 * 4]}
}
extern "C" __declspec(naked) void __stdcall lua_equal_wrapper(){
#ifdef _DEBUG
  log_info("calling lua_equal");
#endif
  __asm{jmp mProcs[50 * 4]}
}
extern "C" __declspec(naked) void __stdcall lua_error_wrapper(){
#ifdef _DEBUG
  log_info("calling lua_error");
#endif
  __asm{jmp mProcs[51 * 4]}
}
extern "C" __declspec(naked) void __stdcall lua_gc_wrapper(){
#ifdef _DEBUG
  log_info("calling lua_gc");
#endif
  __asm{jmp mProcs[52 * 4]}
}
extern "C" __declspec(naked) void __stdcall lua_getallocf_wrapper(){
#ifdef _DEBUG
  log_info("calling lua_getallocf");
#endif
  __asm{jmp mProcs[53 * 4]}
}
extern "C" __declspec(naked) void __stdcall lua_getfenv_wrapper(){
#ifdef _DEBUG
  log_info("calling lua_getfenv");
#endif
  __asm{jmp mProcs[54 * 4]}
}
extern "C" __declspec(naked) void __stdcall lua_getfield_wrapper(){
#ifdef _DEBUG
  log_info("calling lua_getfield");
#endif
  __asm{jmp mProcs[55 * 4]}
}
extern "C" __declspec(naked) void __stdcall lua_gethook_wrapper(){
#ifdef _DEBUG
  log_info("calling lua_gethook");
#endif
  __asm{jmp mProcs[56 * 4]}
}
extern "C" __declspec(naked) void __stdcall lua_gethookcount_wrapper(){
#ifdef _DEBUG
  log_info("calling lua_gethookcount");
#endif
  __asm{jmp mProcs[57 * 4]}
}
extern "C" __declspec(naked) void __stdcall lua_gethookmask_wrapper(){
#ifdef _DEBUG
  log_info("calling lua_gethookmask");
#endif
  __asm{jmp mProcs[58 * 4]}
}
extern "C" __declspec(naked) void __stdcall lua_getinfo_wrapper(){
#ifdef _DEBUG
  log_info("calling lua_getinfo");
#endif
  __asm{jmp mProcs[59 * 4]}
}
extern "C" __declspec(naked) void __stdcall lua_getlocal_wrapper(){
#ifdef _DEBUG
  log_info("calling lua_getlocal");
#endif
  __asm{jmp mProcs[60 * 4]}
}
extern "C" __declspec(naked) void __stdcall lua_getmetatable_wrapper(){
#ifdef _DEBUG
  log_info("calling lua_getmetatable");
#endif
  __asm{jmp mProcs[61 * 4]}
}
extern "C" __declspec(naked) void __stdcall lua_getstack_wrapper(){
#ifdef _DEBUG
  log_info("calling lua_getstack");
#endif
  __asm{jmp mProcs[62 * 4]}
}
extern "C" __declspec(naked) void __stdcall lua_gettable_wrapper(){
#ifdef _DEBUG
  log_info("calling lua_gettable");
#endif
  __asm{jmp mProcs[63 * 4]}
}
extern "C" __declspec(naked) void __stdcall lua_gettop_wrapper(){
#ifdef _DEBUG
  log_info("calling lua_gettop");
#endif
  __asm{jmp mProcs[64 * 4]}
}
extern "C" __declspec(naked) void __stdcall lua_getupvalue_wrapper(){
#ifdef _DEBUG
  log_info("calling lua_getupvalue");
#endif
  __asm{jmp mProcs[65 * 4]}
}
extern "C" __declspec(naked) void __stdcall lua_insert_wrapper(){
#ifdef _DEBUG
  log_info("calling lua_insert");
#endif
  __asm{jmp mProcs[66 * 4]}
}
extern "C" __declspec(naked) void __stdcall lua_iscfunction_wrapper(){
#ifdef _DEBUG
  log_info("calling lua_iscfunction");
#endif
  __asm{jmp mProcs[67 * 4]}
}
extern "C" __declspec(naked) void __stdcall lua_isnumber_wrapper(){
#ifdef _DEBUG
  log_info("calling lua_isnumber");
#endif
  __asm{jmp mProcs[68 * 4]}
}
extern "C" __declspec(naked) void __stdcall lua_isstring_wrapper(){
#ifdef _DEBUG
  log_info("calling lua_isstring");
#endif
  __asm{jmp mProcs[69 * 4]}
}
extern "C" __declspec(naked) void __stdcall lua_isuserdata_wrapper(){
#ifdef _DEBUG
  log_info("calling lua_isuserdata");
#endif
  __asm{jmp mProcs[70 * 4]}
}
extern "C" __declspec(naked) void __stdcall lua_lessthan_wrapper(){
#ifdef _DEBUG
  log_info("calling lua_lessthan");
#endif
  __asm{jmp mProcs[71 * 4]}
}
extern "C" __declspec(naked) void __stdcall lua_load_wrapper(){
#ifdef _DEBUG
  log_info("calling lua_load");
#endif
  __asm{jmp mProcs[72 * 4]}
}
extern "C" __declspec(naked) void __stdcall lua_loadx_wrapper(){
#ifdef _DEBUG
  log_info("calling lua_loadx");
#endif
  __asm{jmp mProcs[73 * 4]}
}
extern "C" __declspec(naked) void __stdcall lua_newstate_wrapper(){
#ifdef _DEBUG
  log_info("calling lua_newstate");
#endif
  __asm{jmp mProcs[74 * 4]}
}
extern "C" __declspec(naked) void __stdcall lua_newthread_wrapper(){
#ifdef _DEBUG
  log_info("calling lua_newthread");
#endif
  __asm{jmp mProcs[75 * 4]}
}
extern "C" __declspec(naked) void __stdcall lua_newuserdata_wrapper(){
#ifdef _DEBUG
  log_info("calling lua_newuserdata");
#endif
  __asm{jmp mProcs[76 * 4]}
}
extern "C" __declspec(naked) void __stdcall lua_next_wrapper(){
#ifdef _DEBUG
  log_info("calling lua_next");
#endif
  __asm{jmp mProcs[77 * 4]}
}
extern "C" __declspec(naked) void __stdcall lua_objlen_wrapper(){
#ifdef _DEBUG
  log_info("calling lua_objlen");
#endif
  __asm{jmp mProcs[78 * 4]}
}
extern "C" __declspec(naked) void __stdcall lua_pcall_wrapper(){
#ifdef _DEBUG
  log_info("calling lua_pcall");
#endif
  __asm{jmp mProcs[79 * 4]}
}
extern "C" __declspec(naked) void __stdcall lua_pushboolean_wrapper(){
#ifdef _DEBUG
  log_info("calling lua_pushboolean");
#endif
  __asm{jmp mProcs[80 * 4]}
}
extern "C" __declspec(naked) void __stdcall lua_pushcclosure_wrapper(){
#ifdef _DEBUG
  log_info("calling lua_pushcclosure");
#endif
  __asm{jmp mProcs[81 * 4]}
}
extern "C" __declspec(naked) void __stdcall lua_pushfstring_wrapper(){
#ifdef _DEBUG
  log_info("calling lua_pushfstring");
#endif
  __asm{jmp mProcs[82 * 4]}
}
extern "C" __declspec(naked) void __stdcall lua_pushinteger_wrapper(){
#ifdef _DEBUG
  log_info("calling lua_pushinteger");
#endif
  __asm{jmp mProcs[83 * 4]}
}
extern "C" __declspec(naked) void __stdcall lua_pushlightuserdata_wrapper(){
#ifdef _DEBUG
  log_info("calling lua_pushlightuserdata");
#endif
  __asm{jmp mProcs[84 * 4]}
}
extern "C" __declspec(naked) void __stdcall lua_pushlstring_wrapper(){
#ifdef _DEBUG
  log_info("calling lua_pushlstring");
#endif
  __asm{jmp mProcs[85 * 4]}
}
extern "C" __declspec(naked) void __stdcall lua_pushnil_wrapper(){
#ifdef _DEBUG
  log_info("calling lua_pushnil");
#endif
  __asm{jmp mProcs[86 * 4]}
}
extern "C" __declspec(naked) void __stdcall lua_pushnumber_wrapper(){
#ifdef _DEBUG
  log_info("calling lua_pushnumber");
#endif
  __asm{jmp mProcs[87 * 4]}
}
extern "C" __declspec(naked) void __stdcall lua_pushstring_wrapper(){
#ifdef _DEBUG
  log_info("calling lua_pushstring");
#endif
  __asm{jmp mProcs[88 * 4]}
}
extern "C" __declspec(naked) void __stdcall lua_pushthread_wrapper(){
#ifdef _DEBUG
  log_info("calling lua_pushthread");
#endif
  __asm{jmp mProcs[89 * 4]}
}
extern "C" __declspec(naked) void __stdcall lua_pushvalue_wrapper(){
#ifdef _DEBUG
  log_info("calling lua_pushvalue");
#endif
  __asm{jmp mProcs[90 * 4]}
}
extern "C" __declspec(naked) void __stdcall lua_pushvfstring_wrapper(){
#ifdef _DEBUG
  log_info("calling lua_pushvfstring");
#endif
  __asm{jmp mProcs[91 * 4]}
}
extern "C" __declspec(naked) void __stdcall lua_rawequal_wrapper(){
#ifdef _DEBUG
  log_info("calling lua_rawequal");
#endif
  __asm{jmp mProcs[92 * 4]}
}
extern "C" __declspec(naked) void __stdcall lua_rawget_wrapper(){
#ifdef _DEBUG
  log_info("calling lua_rawget");
#endif
  __asm{jmp mProcs[93 * 4]}
}
extern "C" __declspec(naked) void __stdcall lua_rawgeti_wrapper(){
#ifdef _DEBUG
  log_info("calling lua_rawgeti");
#endif
  __asm{jmp mProcs[94 * 4]}
}
extern "C" __declspec(naked) void __stdcall lua_rawset_wrapper(){
#ifdef _DEBUG
  log_info("calling lua_rawset");
#endif
  __asm{jmp mProcs[95 * 4]}
}
extern "C" __declspec(naked) void __stdcall lua_rawseti_wrapper(){
#ifdef _DEBUG
  log_info("calling lua_rawseti");
#endif
  __asm{jmp mProcs[96 * 4]}
}
extern "C" __declspec(naked) void __stdcall lua_remove_wrapper(){
#ifdef _DEBUG
  log_info("calling lua_remove");
#endif
  __asm{jmp mProcs[97 * 4]}
}
extern "C" __declspec(naked) void __stdcall lua_replace_wrapper(){
#ifdef _DEBUG
  log_info("calling lua_replace");
#endif
  __asm{jmp mProcs[98 * 4]}
}
extern "C" __declspec(naked) void __stdcall lua_resume_wrapper(){
#ifdef _DEBUG
  log_info("calling lua_resume");
#endif
  __asm{jmp mProcs[99 * 4]}
}
extern "C" __declspec(naked) void __stdcall lua_setallocf_wrapper(){
#ifdef _DEBUG
  log_info("calling lua_setallocf");
#endif
  __asm{jmp mProcs[100 * 4]}
}
extern "C" __declspec(naked) void __stdcall lua_setfenv_wrapper(){
#ifdef _DEBUG
  log_info("calling lua_setfenv");
#endif
  __asm{jmp mProcs[101 * 4]}
}
extern "C" __declspec(naked) void __stdcall lua_setfield_wrapper(){
#ifdef _DEBUG
  log_info("calling lua_setfield");
#endif
  __asm{jmp mProcs[102 * 4]}
}
extern "C" __declspec(naked) void __stdcall lua_sethook_wrapper(){
#ifdef _DEBUG
  log_info("calling lua_sethook");
#endif
  __asm{jmp mProcs[103 * 4]}
}
extern "C" __declspec(naked) void __stdcall lua_setlocal_wrapper(){
#ifdef _DEBUG
  log_info("calling lua_setlocal");
#endif
  __asm{jmp mProcs[104 * 4]}
}
extern "C" __declspec(naked) void __stdcall lua_setmetatable_wrapper(){
#ifdef _DEBUG
  log_info("calling lua_setmetatable");
#endif
  __asm{jmp mProcs[105 * 4]}
}
extern "C" __declspec(naked) void __stdcall lua_settable_wrapper(){
#ifdef _DEBUG
  log_info("calling lua_settable");
#endif
  __asm{jmp mProcs[106 * 4]}
}
extern "C" __declspec(naked) void __stdcall lua_settop_wrapper(){
#ifdef _DEBUG
  log_info("calling lua_settop");
#endif
  __asm{jmp mProcs[107 * 4]}
}
extern "C" __declspec(naked) void __stdcall lua_setupvalue_wrapper(){
#ifdef _DEBUG
  log_info("calling lua_setupvalue");
#endif
  __asm{jmp mProcs[108 * 4]}
}
extern "C" __declspec(naked) void __stdcall lua_status_wrapper(){
#ifdef _DEBUG
  log_info("calling lua_status");
#endif
  __asm{jmp mProcs[109 * 4]}
}
extern "C" __declspec(naked) void __stdcall lua_toboolean_wrapper(){
#ifdef _DEBUG
  log_info("calling lua_toboolean");
#endif
  __asm{jmp mProcs[110 * 4]}
}
extern "C" __declspec(naked) void __stdcall lua_tocfunction_wrapper(){
#ifdef _DEBUG
  log_info("calling lua_tocfunction");
#endif
  __asm{jmp mProcs[111 * 4]}
}
extern "C" __declspec(naked) void __stdcall lua_tointeger_wrapper(){
#ifdef _DEBUG
  log_info("calling lua_tointeger");
#endif
  __asm{jmp mProcs[112 * 4]}
}
extern "C" __declspec(naked) void __stdcall lua_tolstring_wrapper(){
#ifdef _DEBUG
  log_info("calling lua_tolstring");
#endif
  __asm{jmp mProcs[113 * 4]}
}
extern "C" __declspec(naked) void __stdcall lua_tonumber_wrapper(){
#ifdef _DEBUG
  log_info("calling lua_tonumber");
#endif
  __asm{jmp mProcs[114 * 4]}
}
extern "C" __declspec(naked) void __stdcall lua_topointer_wrapper(){
#ifdef _DEBUG
  log_info("calling lua_topointer");
#endif
  __asm{jmp mProcs[115 * 4]}
}
extern "C" __declspec(naked) void __stdcall lua_tothread_wrapper(){
#ifdef _DEBUG
  log_info("calling lua_tothread");
#endif
  __asm{jmp mProcs[116 * 4]}
}
extern "C" __declspec(naked) void __stdcall lua_touserdata_wrapper(){
#ifdef _DEBUG
  log_info("calling lua_touserdata");
#endif
  __asm{jmp mProcs[117 * 4]}
}
extern "C" __declspec(naked) void __stdcall lua_type_wrapper(){
#ifdef _DEBUG
  log_info("calling lua_type");
#endif
  __asm{jmp mProcs[118 * 4]}
}
extern "C" __declspec(naked) void __stdcall lua_typename_wrapper(){
#ifdef _DEBUG
  log_info("calling lua_typename");
#endif
  __asm{jmp mProcs[119 * 4]}
}
extern "C" __declspec(naked) void __stdcall lua_upvalueid_wrapper(){
#ifdef _DEBUG
  log_info("calling lua_upvalueid");
#endif
  __asm{jmp mProcs[120 * 4]}
}
extern "C" __declspec(naked) void __stdcall lua_upvaluejoin_wrapper(){
#ifdef _DEBUG
  log_info("calling lua_upvaluejoin");
#endif
  __asm{jmp mProcs[121 * 4]}
}
extern "C" __declspec(naked) void __stdcall lua_xmove_wrapper(){
#ifdef _DEBUG
  log_info("calling lua_xmove");
#endif
  __asm{jmp mProcs[122 * 4]}
}
extern "C" __declspec(naked) void __stdcall lua_yield_wrapper(){
#ifdef _DEBUG
  log_info("calling lua_yield");
#endif
  __asm{jmp mProcs[123 * 4]}
}
extern "C" __declspec(naked) void __stdcall luaopen_base_wrapper(){
#ifdef _DEBUG
  log_info("calling luaopen_base");
#endif
  __asm{jmp mProcs[124 * 4]}
}
extern "C" __declspec(naked) void __stdcall luaopen_bit_wrapper(){
#ifdef _DEBUG
  log_info("calling luaopen_bit");
#endif
  __asm{jmp mProcs[125 * 4]}
}
extern "C" __declspec(naked) void __stdcall luaopen_debug_wrapper(){
#ifdef _DEBUG
  log_info("calling luaopen_debug");
#endif
  __asm{jmp mProcs[126 * 4]}
}
extern "C" __declspec(naked) void __stdcall luaopen_ffi_wrapper(){
#ifdef _DEBUG
  log_info("calling luaopen_ffi");
#endif
  __asm{jmp mProcs[127 * 4]}
}
extern "C" __declspec(naked) void __stdcall luaopen_io_wrapper(){
#ifdef _DEBUG
  log_info("calling luaopen_io");
#endif
  __asm{jmp mProcs[128 * 4]}
}
extern "C" __declspec(naked) void __stdcall luaopen_jit_wrapper(){
#ifdef _DEBUG
  log_info("calling luaopen_jit");
#endif
  __asm{jmp mProcs[129 * 4]}
}
extern "C" __declspec(naked) void __stdcall luaopen_math_wrapper(){
#ifdef _DEBUG
  log_info("calling luaopen_math");
#endif
  __asm{jmp mProcs[130 * 4]}
}
extern "C" __declspec(naked) void __stdcall luaopen_os_wrapper(){
#ifdef _DEBUG
  log_info("calling luaopen_os");
#endif
  __asm{jmp mProcs[131 * 4]}
}
extern "C" __declspec(naked) void __stdcall luaopen_package_wrapper(){
#ifdef _DEBUG
  log_info("calling luaopen_package");
#endif
  __asm{jmp mProcs[132 * 4]}
}
extern "C" __declspec(naked) void __stdcall luaopen_string_wrapper(){
#ifdef _DEBUG
  log_info("calling luaopen_string");
#endif
  __asm{jmp mProcs[133 * 4]}
}
extern "C" __declspec(naked) void __stdcall luaopen_table_wrapper(){
#ifdef _DEBUG
  log_info("calling luaopen_table");
#endif
  __asm{jmp mProcs[134 * 4]}
}
