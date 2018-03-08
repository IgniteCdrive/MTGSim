#include <algorithm>
#include "eventmanager.h"

EventManager& EventManager::GetEventSingleton()
{
    static EventManager AllTheSingle;
    return AllTheSingle;
}

void EventManager::Subscribe(const TriggerEvents SubTrig, Subscriber* SubAdd)
{
    SubscriberStorage[SubTrig].push_back(SubAdd);
}

void EventManager::Subscribe(std::initializer_list<TriggerEvents> SubTrigs, Subscriber* SubAdd)
{
    for( const TriggerEvents CurrEvent : SubTrigs )
    {
        Subscribe(CurrEvent, SubAdd);
    }
}

void EventManager::Unsubscribe(const TriggerEvents UnSubTrig, Subscriber* SubRemove)
{
    TriggerMap::iterator FindIt = SubscriberStorage.find(UnSubTrig);
    if( FindIt != SubscriberStorage.end() )
    {
        SubscriberVec& SubVec = (*FindIt).second;
        SubscriberVec::iterator SubIt = std::find(SubVec.begin(),SubVec.end(),SubRemove);
        if( SubIt != SubVec.end() )
        {
            SubVec.erase(SubIt);
        }
    }
}

void EventManager::Unsubscribe(std::initializer_list<TriggerEvents> UnSubTrigs, Subscriber* SubRemove)
{
    for( const TriggerEvents CurrEvent : UnSubTrigs )
    {
        Unsubscribe(CurrEvent, SubRemove);
    }
}

void EventManager::UnsubscibeAll(const TriggerEvents UnSubTrigAll)
{
    TriggerMap::iterator FindIt = SubscriberStorage.find(UnSubTrigAll);
    if( FindIt != SubscriberStorage.end() )
    {
        (*FindIt).second.clear();
    }
}

void EventManager::DispatchEvent(const TriggerEvents Event, const magic_card& Source)
{
    TriggerMap::iterator FindIt = SubscriberStorage.find(Event);
    if( FindIt != SubscriberStorage.end() )
    {
        for( Subscriber* CurrSub : (*FindIt).second )
        {
            CurrSub->NotifyOfEvent(Event, Source);
        }
    }
}
