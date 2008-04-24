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

	const char *returned; // define returned value

	// compile the entered code (and execute it if error == 0)
	int error = luaL_loadbuffer(L, statement, strlen(statement), "error") || lua_pcall(L, 0, 0, 0);

	// in the event of an error (error != 0)...
		returned = lua_tostring(L, -1); // assign error message to returned value
	if(error) {
		lua_pop(L, 1); // pop error message from the stack
	}
	else {
		returned = "no error"; // assign result to returned value
		lua_settop(L, 0); // completely clear the stack
	}

	_retval.Assign(returned); // return the value
 
	lua_close(L); // destroy created lua state