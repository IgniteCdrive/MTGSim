// 1.Create a struct that can store all the information that is on a magic card.
//It needs only to store the information that is important for game-play

//2.Create a function that accepts two of these structs, one as attacker, one as defender,
//and lazily compares their power and toughness to see who would win.  The winner should be the return value.

//3.Two such structs must be instantiated and populated with data pertaining to two cards,
//and then the combat function must be invoked.  The result should be reported to cout.
#include <string>
#include <iostream>

using Whole = unsigned int;
using Vigor = int;

enum Color
{
    Colorless = 0,
    Red = 1,
    Black = 2,
    White = 4,
    Blue = 8,
    Green = 16
};

enum Super_Type
{
    Basic = 1,
    Creature = 2,
    Artifact = 4,
    Sorcery = 8,
    Instant = 16,
    Land = 32,
    Planeswalker = 64,
    Enchantment = 128,
    Snow = 256,
    Legendary = 512,
    World = 1024
};

enum class CombatResult : Whole
{
    AttackerWins,
    DefenderWins,
    Tie,
    DoubleLoss
};

class CreatureStrength
{
        Vigor BasePower = 0;
        Vigor BaseToughness = 0;
        Vigor PowerMod = 0;
        Vigor ToughnessMod = 0;
    public:
        CreatureStrength() = default;
        CreatureStrength(const Vigor PowTough) :
            BasePower(PowTough),
            BaseToughness(PowTough),
            PowerMod(0),
            ToughnessMod(0)
            {}
        CreatureStrength(const Vigor Power, const Vigor Toughness) :
            BasePower(Power),
            BaseToughness(Toughness),
            PowerMod(0),
            ToughnessMod(0)
            {}
        CreatureStrength(const CreatureStrength& Other) = default;
        CreatureStrength(CreatureStrength&& Other) = default;
        ~CreatureStrength() = default;

        CreatureStrength& operator=(const CreatureStrength& Other) = default;
        CreatureStrength& operator=(CreatureStrength&& Other) = default;

        bool IsLethal(const Vigor Dmg) const
        {
            return Dmg >= BaseToughness;
        }

        void SetModifiers(const Vigor Power, const Vigor Toughness)
        {
            PowerMod = Power;
            ToughnessMod = Toughness;
        }

        void ClearModifiers()
        {
            PowerMod = 0;
            ToughnessMod = 0;
        }

        void SetBase(const Vigor Power, const Vigor Toughness)
        {
            BasePower = Power;
            BaseToughness = Toughness;
        }

        Vigor GetPower() const
        {
            return BasePower;
        }

        Vigor GetToughness() const
        {
            return BaseToughness;
        }
};

class ManaCost
{
        std::string Cost;
    public:
        ManaCost() = default;
        ManaCost(const ManaCost& Other) = default;
        ManaCost(ManaCost&& Other) = default;
        ManaCost(const std::string& Str) :
            Cost(Str)
            {}
        ~ManaCost() = default;

        ManaCost& operator=(const ManaCost& Other) = default;
        ManaCost& operator=(ManaCost&& Other) = default;

        void SetCost(const std::string& ToSet)
        {
            Cost = ToSet;
        }

        const std::string& GetCost() const
        {
            return Cost;
        }

        Whole Devotion(Whole Colors) const
        {
            std::string Palette;

            if( Colors & White ) {
                Palette.push_back('W');
            }
            if( Colors & Black ) {
                Palette.push_back('B');
            }
            if( Colors & Red ) {
                Palette.push_back('R');
            }
            if( Colors & Blue ) {
                Palette.push_back('U');
            }
            if( Colors & Green ) {
                Palette.push_back('G');
            }
            Whole DevCount = 0;
            for(std::string::const_iterator StrIt = Cost.begin(); StrIt != Cost.end(); ++StrIt)
            {
                for(std::string::iterator PalCheck = Palette.begin(); PalCheck != Palette.end(); ++PalCheck)
                {
                    if(*StrIt == *PalCheck)
                    {
                        ++DevCount;
                        break;
                    }
                }
            }
            return DevCount;
        }

        Whole GetConMana() const
        {
            Whole RetCost = 0;
            size_t ColorPos = Cost.find_first_of("WUBRGC");
            std::string NumCost = Cost.substr(0,ColorPos);
            RetCost += std::stoi(NumCost);
            RetCost += (Cost.size() - ColorPos);
            return RetCost;
        }

        Whole GetColors() const
        {
            Whole RetColors = 0;
            size_t ColorPos = Cost.find_first_of("WUBRGC");
            std::string ColorString = Cost.substr(ColorPos);
            for(std::string::iterator StrIt = ColorString.begin(); StrIt != ColorString.end(); ++StrIt)
            {
                switch(*StrIt)
                {
                    case 'W':  RetColors |= White; break;
                    case 'U':  RetColors |= Blue;  break;
                    case 'B':  RetColors |= Black; break;
                    case 'R':  RetColors |= Red;   break;
                    case 'G':  RetColors |= Green; break;
                }
            }
            return RetColors;
        }
};

class magic_card
{
    std::string Name;
    ManaCost Cost;
    Whole SuperType = 0;
    std::string SubType;
    CreatureStrength Might;
public:
    magic_card() = default;
    magic_card(const magic_card& Other) = default;
    magic_card(magic_card&& Other) = default;

    magic_card& operator=(const magic_card& Other) = default;
    magic_card& operator=(magic_card&& Other) = default;

    magic_card& SetName(const std::string& ToSet)
    {
        Name = ToSet;
        return *this;
    }

    const std::string& GetName() const
    {
        return Name;
    }

    magic_card& SetCost(const ManaCost& ToSet)
    {
        Cost = ToSet;
        return *this;
    }

    magic_card& SetCost(const std::string& ToSet)
    {
        Cost.SetCost(ToSet);
        return *this;
    }

    const ManaCost& GetCost() const
    {
        return Cost;
    }

    magic_card& SetSuperType(const Whole ToSet)
    {
        SuperType = ToSet;
        return *this;
    }

    Whole GetSuperType() const
    {
        return SuperType;
    }

    magic_card& SetSubType(const std::string& ToSet)
    {
        SubType = ToSet;
        return *this;
    }

    const std::string& GetSubType() const
    {
        return SubType;
    }

    magic_card& SetMight(const CreatureStrength& ToSet)
    {
        Might = ToSet;
        return *this;
    }

    magic_card& SetMight(const Vigor Power, const Vigor Toughness)
    {
        Might.SetBase(Power,Toughness);
        return *this;
    }

    const CreatureStrength& GetMight() const
    {
        return Might;
    }
};

void print(const std::string& str)
{
    std::cout << str << std::endl;
}

CombatResult combat(magic_card attacker, magic_card defender)
{
    bool DefenderDeath = defender.GetMight().IsLethal(attacker.GetMight().GetPower());
    bool AttackerDeath = attacker.GetMight().IsLethal(defender.GetMight().GetPower());

    if(DefenderDeath && AttackerDeath)
    {
        return CombatResult::DoubleLoss;
    }

    if(DefenderDeath && !AttackerDeath)
    {
        return CombatResult::AttackerWins;
    }

    if(AttackerDeath && !DefenderDeath)
    {
        return CombatResult::DefenderWins;
    }

    if(!AttackerDeath && !DefenderDeath)
    {
        return CombatResult::Tie;
    }
}

int main()
{

    magic_card LavaZombie;
    LavaZombie.SetName("Lava Zombie").SetCost("1BR");
    LavaZombie.SetSuperType(Creature).SetSubType("Zombie").SetMight(4,3);

    magic_card WallOfWonder;
    WallOfWonder.SetName("Wall of Wonder").SetCost("2UU");
    WallOfWonder.SetSuperType(Creature).SetSubType("Wall").SetMight(1,5);

    magic_card Ulamog;
    Ulamog.SetName("Ulamog, The Ceaseless Hunger").SetCost("10");
    Ulamog.SetSuperType(Legendary | Creature).SetSubType("Eldrazi").SetMight(10,10);

    CombatResult Com = combat(Ulamog, WallOfWonder);

    if(Com == CombatResult::AttackerWins)
    {
        std::cout << "End Match: Attacker Wins" << std::endl;
    }

    if(Com == CombatResult::DefenderWins)
    {
        std::cout << "End Match: Defender Wins" << std::endl;
    }

    if(Com == CombatResult::DoubleLoss)
    {
        std::cout << "End Match: Double Loss" << std::endl;
    }

    if(Com == CombatResult::Tie)
    {
        std::cout << "End Match: Tie" << std::endl;
    }
    ManaCost ColorUni("10WB");
    std::cout << "Devotion of White and Black " << ColorUni.Devotion(White | Black) << std::endl;
    ManaCost ColorMulti ("UUBBBRR");
    std::cout << "Checks for three colors " << ColorMulti.Devotion(Blue | Black | Red) << std::endl;
    ManaCost ColorSeq("3WUBRG");
    std::cout << "ManaCost of Coalition Victory " << ColorSeq.GetConMana() << std::endl;
    return 0;
}
