#include "common.hpp"
#include "objects/JointDef.hpp"
#include "objects/FrictionJointDef.hpp"

namespace LuaBox2D {
	void initFrictionJointDef(State * state){
		state->registerInterface<FrictionJointDef>("LuaBox2D_FrictionJointDef");
	}

	b2FrictionJointDef * FrictionJointDef::constructor(State & state){
		JointDef * interfaceJointDef = state.getInterface<JointDef>("LuaBox2D_JointDef");
		b2JointDef * jointDef = interfaceJointDef->get(1);
		if (jointDef != nullptr){
			if (jointDef->type == b2JointType::e_revoluteJoint){
				return new b2FrictionJointDef(*(b2FrictionJointDef*)(jointDef));
			}else{
				return new b2FrictionJointDef();
			}
		}else{
			return new b2FrictionJointDef();
		}
	}

	void FrictionJointDef::destructor(State & state, b2FrictionJointDef * object){
		delete object;
	}

	inline int FrictionJointDef::getBodyA(State & state, b2FrictionJointDef * object){
		return base->getBodyA(state, object);
	}

	inline int FrictionJointDef::setBodyA(State & state, b2FrictionJointDef * object){
		return base->setBodyA(state, object);
	}

	inline int FrictionJointDef::getBodyB(State & state, b2FrictionJointDef * object){
		return base->getBodyB(state, object);
	}

	inline int FrictionJointDef::setBodyB(State & state, b2FrictionJointDef * object){
		return base->setBodyB(state, object);
	}

	inline int FrictionJointDef::getType(State & state, b2FrictionJointDef * object){
		return base->getType(state, object);
	}

	inline int FrictionJointDef::setType(State & state, b2FrictionJointDef * object){
		return base->setType(state, object);
	}

	inline int FrictionJointDef::getCollideConnected(State & state, b2FrictionJointDef * object){
		return base->getCollideConnected(state, object);
	}

	inline int FrictionJointDef::setCollideConnected(State & state, b2FrictionJointDef * object){
		return base->setCollideConnected(state, object);
	}
};