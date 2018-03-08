
#ifndef subscriber_h
#define subscriber_h

class magic_card;

class Subscriber
{
public:
    virtual void NotifyOfEvent(const TriggerEvents Event, const magic_card& Card) = 0;
};

#endif // subscriber_h
