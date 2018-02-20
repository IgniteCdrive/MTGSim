
#include "creaturestrength.h"

CreatureStrength::CreatureStrength(const Vigor PowTough) :
    BasePower(PowTough),
    BaseToughness(PowTough),
    PowerMod(0),
    ToughnessMod(0)
    {}
CreatureStrength::CreatureStrength(const Vigor Power, const Vigor Toughness) :
    BasePower(Power),
    BaseToughness(Toughness),
    PowerMod(0),
    ToughnessMod(0)
    {}

bool CreatureStrength::IsLethal(const Vigor Dmg) const
{
    return Dmg >= GetToughness();
}

void CreatureStrength::SetModifiers(const Vigor Power, const Vigor Toughness)
{
    PowerMod = Power;
    ToughnessMod = Toughness;
}

void CreatureStrength::ClearModifiers()
{
    PowerMod = 0;
    ToughnessMod = 0;
}

void CreatureStrength::SetBase(const Vigor Power, const Vigor Toughness)
{
    BasePower = Power;
    BaseToughness = Toughness;
}

Vigor CreatureStrength::GetBasePower() const
{
    return BasePower;
}

Vigor CreatureStrength::GetBaseToughness() const
{
    return BaseToughness;
}

Vigor CreatureStrength::GetPower() const
{
    return BasePower + PowerMod;
}

Vigor CreatureStrength::GetToughness() const
{
    return BaseToughness + ToughnessMod;
}
