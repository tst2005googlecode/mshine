		// <experimental code>
		int top = lua_gettop(L); // get top of the stack

		// cycle through the stack
		for(int i = 1; i <= top; i++) {
			int type = lua_type(L, i); // determine type of current item
			switch(type) {
				case LUA_TSTRING: { // return a string
					_retval.Assign(lua_tostring(L, i));
					break;
				}
				case LUA_TNUMBER: { // return a number
					_retval.Assign(lua_tonumber(L, i));
					break;
				}
				case LUA_TBOOLEAN: { // return a boolean
					_retval.Assign(lua_toboolean(L, i));
					break;
				}
				default: { // return another type of value
					_retval.Assign(lua_typename(L, type));
					break;
				}
			}
		}
		// </experimental code>
