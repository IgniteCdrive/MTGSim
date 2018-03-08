
#ifndef abilities_h
#define abilities_h

#include "datatypes.h"
#include "enums.h"
#include "subscriber.h"

class CardAbility
{
public:
    CardAbility() = default;
    CardAbility(const CardAbility& Other) = default;
    CardAbility(CardAbility&& Other) = delete;
    virtual ~CardAbility() = default;

    CardAbility& operator=(const CardAbility& Other) = default;
    CardAbility& operator=(CardAbility&& Other) = delete;

    virtual AbilityName GetAbilityID() const = 0;
};

class TriggerAbility : public CardAbility, public Subscriber
{
public:
    TriggerAbility() = default;
    //TriggerAbility(const TriggerEvents Event);
    TriggerAbility(const TriggerAbility& Other) = default;
    TriggerAbility(TriggerAbility&& Other) = delete;
    virtual ~TriggerAbility() = default;

    TriggerAbility& operator=(const TriggerAbility& Other) = default;
    TriggerAbility& operator=(TriggerAbility&& Other) = delete;
};

class Ability_Bushido : public TriggerAbility
{
protected:
    Vigor BushidoStrength = 0;
public:
    Ability_Bushido() = delete;
    Ability_Bushido(const Vigor Number);
    Ability_Bushido(const Ability_Bushido& Other);
    Ability_Bushido(Ability_Bushido&& Other) = delete;
    ~Ability_Bushido();

    Ability_Bushido& operator=(const Ability_Bushido& Other) = delete;
    Ability_Bushido& operator=(Ability_Bushido&& Other) = delete;

    virtual AbilityName GetAbilityID() const override;
    virtual void NotifyOfEvent(const TriggerEvents Event, const magic_card& Card) override;

    void SetBushidoStrength(const Vigor Number);
    Vigor GetBushidoStrength() const;
};

class ManaAbility : public CardAbility//, public ManaCost
{
public:
    ManaAbility() = default;
};

#endif // abilities_h
