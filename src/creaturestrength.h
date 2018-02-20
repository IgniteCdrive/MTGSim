
#ifndef creaturestrength_h
#define creaturestrength_h

#include "datatypes.h"

class CreatureStrength
{
    Vigor BasePower = 0;
    Vigor BaseToughness = 0;
    Vigor PowerMod = 0;
    Vigor ToughnessMod = 0;
public:
    CreatureStrength() = default;
    CreatureStrength(const Vigor PowTough);
    CreatureStrength(const Vigor Power, const Vigor Toughness);
    CreatureStrength(const CreatureStrength& Other) = default;
    CreatureStrength(CreatureStrength&& Other) = default;
    ~CreatureStrength() = default;

    CreatureStrength& operator=(const CreatureStrength& Other) = default;
    CreatureStrength& operator=(CreatureStrength&& Other) = default;

    bool IsLethal(const Vigor Dmg) const;

    void SetModifiers(const Vigor Power, const Vigor Toughness);
    void ClearModifiers();
    void SetBase(const Vigor Power, const Vigor Toughness);
    Vigor GetBasePower() const;
    Vigor GetBaseToughness() const;
    Vigor GetPower() const;
    Vigor GetToughness() const;
};

#endif // creaturestrength_h
