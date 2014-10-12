#ifndef LUABOX2D_VEC2_H
#define LUABOX2D_VEC2_H

namespace LuaBox2D {
	class Vec2 : public Object<b2Vec2> {
	public:
		explicit Vec2(State * state) : Object<b2Vec2>(state){
			LUTOK_PROPERTY("x", &Vec2::getX, &Vec2::setX);
			LUTOK_PROPERTY("y", &Vec2::getY, &Vec2::setY);
			LUTOK_PROPERTY("length", &Vec2::operator_len, &Vec2::nullMethod);
			LUTOK_PROPERTY("lengthSquared", &Vec2::lengthSquared, &Vec2::nullMethod);
			LUTOK_PROPERTY("valid", &Vec2::isValid, &Vec2::nullMethod);

			LUTOK_METHOD("zero", &Vec2::zero);
			LUTOK_METHOD("normalize", &Vec2::normalize);
			LUTOK_METHOD("normalizeTo", &Vec2::normalizeTo);
			LUTOK_METHOD("skew", &Vec2::skew);
		}
		b2Vec2 * constructor(State & state){
			b2Vec2 * obj = nullptr;
			Stack * stack = state.stack;
			if (stack->is<LUA_TNUMBER>(1) && stack->is<LUA_TNUMBER>(2)){
				obj = new b2Vec2(
					static_cast<float32>(stack->to<LUA_NUMBER>(1)),
					static_cast<float32>(stack->to<LUA_NUMBER>(2))
				);
			}else{
				obj = new b2Vec2();
			}

			return obj;
		}
		void destructor(State & state, b2Vec2 * object){
			delete object;
		}

		int getX(State & state, b2Vec2 * object){
			state.stack->push<LUA_NUMBER>(object->x);
			return 1;
		}

		int setX(State & state, b2Vec2 * object){
			object->x = static_cast<float32>(state.stack->to<LUA_NUMBER>(1));
			return 0;
		}

		int getY(State & state, b2Vec2 * object){
			state.stack->push<LUA_NUMBER>(object->y);
			return 1;
		}

		int setY(State & state, b2Vec2 * object){
			object->y = static_cast<float32>(state.stack->to<LUA_NUMBER>(1));
			return 0;
		}

		int zero(State & state, b2Vec2 * object){
			object->SetZero();
			return 0;
		}

		int operator_add(State & state, b2Vec2 * a, b2Vec2 * b){
			push(new b2Vec2((*a) + (*b)), true);
			return 1;
		}

		int operator_sub(State & state, b2Vec2 * a, b2Vec2 * b){
			push(new b2Vec2((*a) - (*b)), true);
			return 1;
		}

		int operator_mul(State & state, b2Vec2 * a, b2Vec2 * b){
			Stack * stack = state.stack;
			if (stack->is<LUA_TNUMBER>(1) && b!=nullptr){
				push(new b2Vec2(
					static_cast<float32>(stack->to<LUA_NUMBER>(1)) * (*b)
					), true);
				return 1;
			}else if (state.stack->is<LUA_TNUMBER>(2) && a!=nullptr){
				push(new b2Vec2(
					static_cast<float32>(stack->to<LUA_NUMBER>(2)) * (*a)
					), true);
				return 1;
			}
			return 0;
		}

		int operator_unm(State & state, b2Vec2 * object){
			push(new b2Vec2(-(*object)), true);
			return 1;
		}

		int operator_getArray(State & state, b2Vec2 * object){
			if (state.stack->is<LUA_TNUMBER>(1)){
				int index = state.stack->to<int>(1);
				if (index>=0 && index <= 1){
					state.stack->push<LUA_NUMBER>((*object)(index));
					return 1;
				}
			}
			return 0;
		}

		int operator_len(State & state, b2Vec2 * object){
			state.stack->push<LUA_NUMBER>(object->Length());
			return 1;
		}
		
		int lengthSquared(State & state, b2Vec2 * object){
			state.stack->push<LUA_NUMBER>(object->LengthSquared());
			return 1;
		}

		int normalize(State & state, b2Vec2 * object){
			state.stack->push<LUA_NUMBER>(object->Normalize());
			return 1;
		}

		int normalizeTo(State & state, b2Vec2 * object){
			b2Vec2 tmp = (*object);
			tmp.Normalize();
			push(new b2Vec2(tmp), true);
			return 1;
		}

		int skew(State & state, b2Vec2 * object){
			push(new b2Vec2(object->Skew()), true);
			return 1;
		}
		int isValid(State & state, b2Vec2 * object){
			state.stack->push<bool>(object->IsValid());
			return 1;
		}
	};

	void initVec2(State *);

};

#endif