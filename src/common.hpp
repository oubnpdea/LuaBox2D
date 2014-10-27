#ifndef LUABOX2D_COMMON_H
#define LUABOX2D_COMMON_H

#include <Lua/lua.hpp>
#include <Box2D/Box2d.h>
#include <lutok2/lutok2.hpp>

using namespace lutok2;

#define ADD_VALID_TYPE(NAME)	validTypes.push_front("class lutok2::Object<class b2" ## #NAME ## "> *")

#endif