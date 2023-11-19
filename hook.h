#pragma once
#include "hook_macro.h"

typedef struct lua_State lua_State;

#define LUAOPEN_BASE
#define LUAOPEN_BIT
#define LUAOPEN_DEBUG
#define LUAOPEN_FFI
#define LUAOPEN_IO
#define LUAOPEN_JIT
#define LUAOPEN_MATH
#define LUAOPEN_OS
#define LUAOPEN_PACKAGE
#define LUAOPEN_STRING
#define LUAOPEN_TABLE

FAKE(int, __cdecl, luaopen_bit, lua_State *L) {
  return luaopen_bit_real(L);
}
FAKE(int, __cdecl, luaopen_debug, lua_State *L) {
  return luaopen_debug_real(L);
}
FAKE(int, __cdecl, luaopen_ffi, lua_State *L) {
  return luaopen_ffi_real(L);
}
FAKE(int, __cdecl, luaopen_io, lua_State *L) {
  return luaopen_io_real(L);
}
FAKE(int, __cdecl, luaopen_jit, lua_State *L) {
  return luaopen_jit_real(L);
}
FAKE(int, __cdecl, luaopen_math, lua_State *L) {
  return luaopen_math_real(L);
}
FAKE(int, __cdecl, luaopen_os, lua_State *L) {
  return luaopen_os_real(L);
}
FAKE(int, __cdecl, luaopen_package, lua_State *L) {
  return luaopen_package_real(L);
}
FAKE(int, __cdecl, luaopen_string, lua_State *L) {
  return luaopen_string_real(L);
}
FAKE(int, __cdecl, luaopen_table, lua_State *L) {
  return luaopen_table_real(L);
}

FAKE(int, __cdecl, luaopen_base, lua_State *L) {
  int result = luaopen_base_real(L);
  result += luaopen_bit_real(L);
  result += luaopen_debug_real(L);
  result += luaopen_ffi_real(L);
  result += luaopen_io_real(L);
  //result += luaopen_jit_real(L);
  //result += luaopen_math_real(L);
  result += luaopen_os_real(L);
  result += luaopen_package_real(L);
  //result += luaopen_string_real(L);
  //result += luaopen_table_real(L);
  return ret;
}
