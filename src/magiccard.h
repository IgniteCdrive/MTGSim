
#ifndef magiccard_h
#define magiccard_h

#include <string>
#include <vector>
#include "abilities.h"
#include "creaturestrength.h"
#include "manacost.h"


class magic_card
{
    std::string Name;
    ManaCost Cost;
    Whole SuperType = 0;
    std::string SubType;
    CreatureStrength Might;
    std::vector<CardAbility*> Abilities;
public:
    magic_card() = default;
    magic_card(const magic_card& Other) = default;
    magic_card(magic_card&& Other) = default;

    magic_card& operator=(const magic_card& Other) = default;
    magic_card& operator=(magic_card&& Other) = default;

    magic_card& SetName(const std::string& ToSet);
    const std::string& GetName() const;

    magic_card& SetCost(const ManaCost& ToSet);
    magic_card& SetCost(const std::string& ToSet);
    const ManaCost& GetCost() const;

    magic_card& SetSuperType(const Whole ToSet);
    Whole GetSuperType() const;
    magic_card& SetSubType(const std::string& ToSet);
    const std::string& GetSubType() const;

    magic_card& SetMight(const CreatureStrength& ToSet);
    magic_card& SetMight(const Vigor Power, const Vigor Toughness);
    const CreatureStrength& GetMight() const;
};

#endif // magiccard_h
