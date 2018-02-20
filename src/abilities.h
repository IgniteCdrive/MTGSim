
#ifndef abilities_h
#define abilities_h

#include "datatypes.h"
#include "enums.h"

class CardAbility
{
public:
    CardAbility() = default;
    CardAbility(const CardAbility& Other) = default;
    CardAbility(CardAbility&& Other) = default;

    CardAbility& operator=(const CardAbility& Other) = default;
    CardAbility& operator=(CardAbility&& Other) = default;

    virtual AbilityName GetAbilityID() const = 0;
};

class Ability_Bushido : public CardAbility
{
protected:
    Vigor BushidoStrength = 0;
public:
    Ability_Bushido() = delete;
    Ability_Bushido(const Ability_Bushido& Other) = default;
    Ability_Bushido(Ability_Bushido&& Other) = default;
    ~Ability_Bushido() = default;

    Ability_Bushido& operator=(const Ability_Bushido& Other) = default;
    Ability_Bushido& operator=(Ability_Bushido&& Other) = default;

    Ability_Bushido(const Vigor Number);

    virtual AbilityName GetAbilityID() const;

    void SetBushidoStrength(const Vigor Number);

    Vigor GetBushidoStrength() const;
};

class ManaAbility : public CardAbility//, public ManaCost
{
public:
    ManaAbility() = default;
};

#endif // abilities_h
