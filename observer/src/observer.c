#include "observer.h"


typedef struct observer_t
{
    callbackArray_t pSubscribersCallbacksLists;
    uint32_t maxNumOfSubscriber;
    uint32_t numOfCurrentSubscribers;
}observer_t;


EObserver_callfFunStatus addSubscriber(observer_t* observer, callback_t subscriberCallback)
{
    if(observer == NULL || subscriberCallback == NULL)
    {
        return OBSERVER_NULL_PTR_GIVEN;
    }

    for(uint32_t i = 0; i < observer->maxNumOfSubscriber; i++)
    {
        if(observer->pSubscribersCallbacksLists[i] == NULL)
        {
            observer->pSubscribersCallbacksLists[i] = subscriberCallback;
            observer->numOfCurrentSubscribers++;
            return OBSERVER_OK;
        }
    }

    return OBSERVER_SUBSCRIBERS_LIST_FULL;
}

EObserver_callfFunStatus deleteSubscriber(observer_t* observer, callback_t subscriberCallback)
{
    if(observer == NULL || subscriberCallback == NULL)
    {
        return OBSERVER_NULL_PTR_GIVEN;
    }

    for(uint32_t i = 0; i < observer->maxNumOfSubscriber; i++)
    {
        if(observer->pSubscribersCallbacksLists[i] == subscriberCallback)
        {
            observer->pSubscribersCallbacksLists[i] = NULL;
            observer->numOfCurrentSubscribers--;
            return OBSERVER_OK;
        }
    }

    return OBSERVER_SUBSCRIBER_NOT_ADDED;
}

EObserver_callfFunStatus notifySubscribers(observer_t* observer, EObserver_eventsID eventID)
{
    if(observer == NULL)
    {
        return OBSERVER_NULL_PTR_GIVEN;
    }

    if(observer->numOfCurrentSubscribers == 0)
    {
        return OBSERVER_NO_SUBSCRIBERS;
    }
    

    for(uint32_t i = 0; i < observer->maxNumOfSubscriber; i++)
    {
        if(observer->pSubscribersCallbacksLists[i] != NULL)
        {
            observer->pSubscribersCallbacksLists[i](eventID);
        }
    }

    return OBSERVER_OK;
}

uint32_t getCurrentNumberOfSubscribers(observer_t* observer)
{
    return observer->numOfCurrentSubscribers;
}

observer_t* newObserver(uint32_t numOfSubscribers)
{
    if(numOfSubscribers == 0)
    {
        return NULL;
    }

    observer_t* observer = (observer_t*)malloc(sizeof(observer_t));

    if(NULL == observer)
    {
        return NULL;
    }

    observer->pSubscribersCallbacksLists = (callbackArray_t)malloc(sizeof(callback_t)*numOfSubscribers);

    if(NULL == observer->pSubscribersCallbacksLists)
    {
        free(observer);
        return NULL;
    }

    observer->maxNumOfSubscriber = numOfSubscribers;
    observer->numOfCurrentSubscribers =0;

    for(uint32_t i = 0; i < observer->maxNumOfSubscriber; i++)
    {
        observer->pSubscribersCallbacksLists[i] = NULL;
    }

    return observer;
}

EObserver_callfFunStatus deleteObserver(observer_t** observer)
{
    if(*observer == NULL)
    {
        return OBSERVER_NULL_PTR_GIVEN;
    }

    if((*observer)->pSubscribersCallbacksLists != NULL)
    {
        free((*observer)->pSubscribersCallbacksLists);
    }
    
    free(*observer);

    *observer = NULL;

    return OBSERVER_OK;
}