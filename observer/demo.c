#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "observer.h"

void fun1(EObserver_eventsID eventID)
{
    if(eventID == OBSERVER_EVENT_1)
    {
        printf("%s%d\n","Fun1 is happy to get event ",OBSERVER_EVENT_1);
    }
}

void fun2(EObserver_eventsID eventID)
{
    if(eventID == OBSERVER_EVENT_2)
    {
        printf("%s%d\n","Fun2 is happy to get event ",OBSERVER_EVENT_2);
    }
}

void fun3(EObserver_eventsID eventID)
{
    if(eventID == OBSERVER_EVENT_3)
    {
        printf("%s%d\n","Fun3 is happy to get event ",OBSERVER_EVENT_3);
    }
}

int main()
{
    observer_t* observer = newObserver(5);

    addSubscriber(observer, fun1);
    addSubscriber(observer, fun2);
    addSubscriber(observer, fun3);

    notifySubscribers(observer, OBSERVER_EVENT_1);
    notifySubscribers(observer, OBSERVER_EVENT_2);

    deleteSubscriber(observer, fun2);

    printf("%s%d%s","Current number of subscribers is: ", getCurrentNumberOfSubscribers(observer),"\n");

    notifySubscribers(observer, OBSERVER_EVENT_2);
    notifySubscribers(observer, OBSERVER_EVENT_3);

    deleteObserver(&observer);



    return 0;
}