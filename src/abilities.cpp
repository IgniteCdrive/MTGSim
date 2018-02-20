
#include "abilities.h"

Ability_Bushido::Ability_Bushido(const Vigor Number) :
    BushidoStrength(Number)
    {}

AbilityName Ability_Bushido::GetAbilityID() const
{
    return AbilityName::Bushido;
}

void Ability_Bushido::SetBushidoStrength(const Vigor Number)
{
    BushidoStrength = Number;
}

Vigor Ability_Bushido::GetBushidoStrength() const
{
    return BushidoStrength;
}
