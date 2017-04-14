// --------------------------------------------------------
// Code generated by Papyrus C++
// --------------------------------------------------------

#define statemachine_EventPriorityQueue_BODY

/************************************************************
 EventPriorityQueue class body
 ************************************************************/

// include associated header file
#include "statemachine/EventPriorityQueue.h"

// Derived includes directives

namespace statemachine {

// static attributes (if any)

/**
 * 
 * @param queueSize 
 * @param eventArray 
 */
EventPriorityQueue::EventPriorityQueue(unsigned int /*in*/queueSize,
		Event_t* /*in*/eventArray) :
		data(eventArray), size(queueSize), numberOfElements(0), readPos(0), writePos(
				0), compSize(4), compNumbers(0), compReadPos(0), compWritePos(
				0), numberOfDeferreds(0), readDef(0), writeDef(0) {
	mutex = PTHREAD_MUTEX_INITIALIZER;
	cond = PTHREAD_COND_INITIALIZER;
	isLock = false;
}

/**
 * 
 * @param priority 
 * @param data 
 * @param eventID 
 * @param eventType 
 * @param associatedState 
 * @param dataSize 
 */
void EventPriorityQueue::push(EventPriority_t /*in*/priority, void* /*in*/data,
		unsigned int /*in*/eventID, EventType_t /*in*/eventType,
		unsigned int /*in*/associatedState, int /*in*/dataSize) {
	statemachine::Event_t* ret = NULL;
	if (EVENT_DATA_SIZE <= dataSize) {
		return;
	}
	pthread_mutex_lock (&mutex);
	while (isLock) {
		pthread_cond_wait(&cond, &mutex);
	}
	if (compNumbers < compSize && eventType == statemachine::COMPLETION_EVENT) {
		ret = &(this->completionEvents[compWritePos]);
		compNumbers++;
		ret->priority = priority;
		memcpy(ret->data, data, dataSize);
		ret->eventID = eventID;
		ret->eventType = eventType;
		ret->associatedState = associatedState;
		compWritePos = (compWritePos + 1) % compSize;
	} else if (numberOfElements < size) {
		ret = &(this->data[writePos]);
		numberOfElements++;
		ret->priority = priority;
		memcpy(ret->data, data, dataSize);
		ret->eventID = eventID;
		ret->eventType = eventType;
		ret->associatedState = associatedState;
		writePos = (writePos + 1) % size;
	}
	isLock = false;
	pthread_cond_signal (&cond);
	pthread_mutex_unlock(&mutex);
}

/**
 * 
 * @return ret 
 * @param popDeferred 
 */
Event_t* EventPriorityQueue::pop(bool /*in*/popDeferred) {
	statemachine::Event_t* ret = NULL;
	pthread_mutex_lock (&mutex);
	while (isLock) {
		pthread_cond_wait(&cond, &mutex);
	}
	if (compNumbers > 0) {
		ret = &completionEvents[compReadPos];
		compNumbers--;
		compReadPos = (compReadPos + 1) % compSize;
	} else if (popDeferred && (numberOfDeferreds > 0)) {
		ret = &deferreds[readDef];
		numberOfDeferreds--;
		readDef = (readDef + 1) % defSize;
	}
	if ((ret == NULL) && (numberOfElements > 0)) {
		ret = &data[readPos];
		numberOfElements--;
		readPos = (readPos + 1) % size;
	}

	if ((ret == NULL) && (numberOfDeferreds > 0)) {
		ret = &deferreds[readDef];
		numberOfDeferreds--;
		readDef = (readDef + 1) % defSize;
	}

	isLock = false;
	pthread_cond_signal (&cond);
	pthread_mutex_unlock(&mutex);
	return ret;
}

/**
 * 
 * @param defe 
 */
void EventPriorityQueue::saveDeferred(Event_t& /*in*/defe) {
	if (numberOfDeferreds < defSize) {
		deferreds[writeDef].priority = defe.priority;
		memcpy(&deferreds[writeDef].data, &defe.data, sizeof(defe.data));
		deferreds[writeDef].eventID = defe.eventID;
		deferreds[writeDef].eventType = defe.eventType;
		deferreds[writeDef].associatedState = defe.associatedState;
		numberOfDeferreds++;
		writeDef = (writeDef + 1) % defSize;
	}
}

/**
 * 
 */
void EventPriorityQueue::heapify() {
}

} // of namespace statemachine

/************************************************************
 End of EventPriorityQueue class body
 ************************************************************/