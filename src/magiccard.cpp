
#include "magiccard.h"


magic_card& magic_card::SetName(const std::string& ToSet)
{
    Name = ToSet;
    return *this;
}

const std::string& magic_card::GetName() const
{
    return Name;
}

magic_card& magic_card::SetCost(const ManaCost& ToSet)
{
    Cost = ToSet;
    return *this;
}

magic_card& magic_card::SetCost(const std::string& ToSet)
{
    Cost.SetCost(ToSet);
    return *this;
}

const ManaCost& magic_card::GetCost() const
{
    return Cost;
}

magic_card& magic_card::SetSuperType(const Whole ToSet)
{
    SuperType = ToSet;
    return *this;
}

Whole magic_card::GetSuperType() const
{
    return SuperType;
}

magic_card& magic_card::SetSubType(const std::string& ToSet)
{
    SubType = ToSet;
    return *this;
}

const std::string& magic_card::GetSubType() const
{
    return SubType;
}

magic_card& magic_card::SetMight(const CreatureStrength& ToSet)
{
    Might = ToSet;
    return *this;
}

magic_card& magic_card::SetMight(const Vigor Power, const Vigor Toughness)
{
    Might.SetBase(Power,Toughness);
    return *this;
}

const CreatureStrength& magic_card::GetMight() const
{
    return Might;
}

