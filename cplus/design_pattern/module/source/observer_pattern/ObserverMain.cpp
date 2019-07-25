#include "../../include/observer_pattern/ObserverMain.h"

void ObserverMain()
{
    ConcreteSubject * pSubject = new ConcreteSubject();

    IObserver * pObserver1 = new ConcreteObserver("Jack Ma");
    IObserver * pObserver2 = new ConcreteObserver("Pony");

    pSubject->Attach(pObserver1);
    pSubject->Attach(pObserver2);

    pSubject->SetPrice(12.5);
    pSubject->Notify();

    pSubject->Detach(pObserver2);

    pSubject->SetPrice(15.0);
    pSubject->Notify();

    SAFE_DELETE(pObserver1);
    SAFE_DELETE(pObserver2);
    SAFE_DELETE(pSubject);
}