#ifndef OBSERVER_H
#define OBSERVER_H

#include <stdint.h>
#include <stdlib.h>

typedef enum EObserver_callfFunStatus
{
    OBSERVER_OK                     = 0,
    OBSERVER_NULL_PTR_GIVEN,
    OBSERVER_SUBSCRIBERS_LIST_FULL,
    OBSERVER_SUBSCRIBER_NOT_ADDED,
    OBSERVER_NO_SUBSCRIBERS,

}EObserver_callfFunStatus;

typedef enum EObserver_eventsID
{
    OBSERVER_EVENT_1 = 1,
    OBSERVER_EVENT_2,
    OBSERVER_EVENT_3,
    OBSERVER_EVENT_4,
    OBSERVER_EVENT_5,
    OBSERVER_EVENT_6,
}EObserver_eventsID;


typedef struct observer_t observer_t;

typedef void (*callback_t)(EObserver_eventsID eventID);
typedef void (**callbackArray_t)(EObserver_eventsID eventID);




EObserver_callfFunStatus addSubscriber(observer_t* observer, callback_t subscriberCallback);

EObserver_callfFunStatus deleteSubscriber(observer_t* observer, callback_t subscriberCallback);

EObserver_callfFunStatus notifySubscribers(observer_t* observer, EObserver_eventsID eventID);

uint32_t getCurrentNumberOfSubscribers(observer_t* observer);

observer_t* newObserver(uint32_t numOfSubscribers);

EObserver_callfFunStatus deleteObserver(observer_t** observer);



#endif //OBSERVER_H