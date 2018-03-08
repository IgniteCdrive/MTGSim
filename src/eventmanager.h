
#ifndef eventmanager_h
#define eventmanager_h

#include <initializer_list>
#include <unordered_map>
#include <vector>
#include "enums.h"
#include "magiccard.h"
#include "subscriber.h"

class EventManager
{
public:
    using SubscriberVec = std::vector<Subscriber*>;
    using TriggerMap = std::unordered_map<TriggerEvents,SubscriberVec>;
    using TriggerMapPair = TriggerMap::value_type;
    using InsertPair = std::pair<TriggerMap::iterator,bool>;
protected:
    TriggerMap SubscriberStorage;
public:
    EventManager() = default;
    EventManager(const EventManager& Other) = delete;
    EventManager(EventManager&& Other) = default;

    EventManager& operator=(const EventManager& Other) = delete;
    EventManager& operator=(EventManager&& Other) = default;

    static EventManager& GetEventSingleton();

    void Subscribe(const TriggerEvents SubTrig, Subscriber* SubAdd);
    void Subscribe(std::initializer_list<TriggerEvents> SubTrigs, Subscriber* SubAdd);
    void Unsubscribe(const TriggerEvents UnSubTrig, Subscriber* SubRemove);
    void Unsubscribe(std::initializer_list<TriggerEvents> UnSubTrigs, Subscriber* SubRemove);
    void UnsubscibeAll(const TriggerEvents UnSubTrigAll);

    void DispatchEvent(const TriggerEvents Event, const magic_card& Source);
};

#endif // eventmanager_h
