#ifndef PKG_LEGOCARFACTORYREFACTORINGFORSYNC
#define PKG_LEGOCARFACTORYREFACTORINGFORSYNC

/************************************************************
 Pkg_LegoCarFactoryRefactoringForSync package header
 ************************************************************/

#ifndef _IN_
#define _IN_
#endif
#ifndef _OUT_
#define _OUT_
#endif
#ifndef _INOUT_
#define _INOUT_
#endif

/* Package dependency header include                        */

// Include from Include stereotype (header)
#ifdef __linux__ 
//linux code goes here
#elif _WIN32
#include "windows.h"
#else

#endif

#include "string.h"
#define State class
#define InitialState class
#define Region class
#define StateMachine class

#define configuration void configuration()
#define part public:
#define CallEvent(name,operation) void CALL_EVENT___ ## name ## ___ ## operation {}
#define TimeEvent(name,duration) class TIME_EVENT___ ## name ## ___DURATION___ ## duration {};
#define ChangeEvent(name,expression) class CHANGE_EVENT___ ## name ## ___EXPRESSION___ {};
#define TransitionTable void TRANSITION_TABLE___operation(int transition_len)
#define ExT(name, source, target, guard, event, effect) transition_len = strlen(#name) + strlen("transition") + strlen(#source) + strlen(#target) + strlen(#guard) + strlen(#event) + strlen(#effect);
#define LoT(name, source, target, guard, event, effect) transition_len = strlen(#name) + strlen("local_transition") + strlen(#source) + strlen(#target) + strlen(#guard) + strlen(#event) + strlen(#effect);
#define InT(name, source, guard, event, effect) transition_len = strlen(#name) + strlen("internal_transition") + strlen(#source) + strlen(#guard) + strlen(#event) + strlen(#effect);

template<class Sig> class SignalEvent {

};

typedef char* action_type;

class StateEntry {

};

class StateExit {

};

class FinalState {

};

class StateDoActivity {

};

class InitialEffect {

};

//template <char* c> class call_event {
//public:
//	call_event(char* methodName){};
//};
//
//class time_event {
//public:
//	time_event(int milisecond){};
//};
//
//template <class S> class signal_event {
//};
//
//class change_event {
//public:
//	change_event(char* expression){};
//};

class PseudoChoice {

};

class PseudoJoin {

};

class PseudoEntryPoint {

};

class PseudoExitPoint {

};

class PseudoInitial {

};

class PseudoJunction {

};

class PseudoFork {

};

class PseudoShallowHistory {

};

class PseudoDeepHistory {

};

class PseudoTerminate {

};

class Port {

};

template<class T> class ProvidedPort: public Port {
public:
	T* providedIntf;
};

template<class T> class RequiredPort: public Port {
public:
	T* requiredIntf;
};

template<class R, class P> class BidirectionPort: public Port {
public:
	R* requiredIntf;
	P* providedIntf;
};

template<class T> class IPush {
public:
	virtual void push(T&) = 0;
};

template<class T> class OutFlowPort: public Port {
public:
	IPush<T>* outIntf;
};

template<class T> class InOutFlowPort: public Port {
public:
	IPush<T>* inIntf;
	IPush<T>* outIntf;
};

template<class T> class InFlowPort: public Port {
public:
	IPush<T>* inIntf;
};

template<class T> class Part: public T {

};

void bindPorts(Port& p1, Port& p2);
#define SIGNAL_SIZE (50)
#define SIGNAL_SIZE (50)
#define SIGNAL_SIZE (50)
#define SIGNAL_SIZE (50)
// End of Include stereotype (header)
namespace LegoCarFactoryRefactoringForSync {

// Types defined within the package
}// of namespace LegoCarFactoryRefactoringForSync

/************************************************************
 End of Pkg_LegoCarFactoryRefactoringForSync package header
 ************************************************************/

#endif
