// 1.Create a struct that can store all the information that is on a magic card.
//It needs only to store the information that is important for game-play

//2.Create a function that accepts two of these structs, one as attacker, one as defender,
//and lazily compares their power and toughness to see who would win.  The winner should be the return value.

//3.Two such structs must be instantiated and populated with data pertaining to two cards,
//and then the combat function must be invoked.  The result should be reported to cout.
#include <string>
#include <iostream>
#include "magiccard.h"

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
    std::cout << "GetDevotion of White and Black " << ColorUni.GetDevotion(White | Black) << std::endl;
    ManaCost ColorMulti ("UUBBBRR");
    std::cout << "Checks for three colors " << ColorMulti.GetDevotion(Blue | Black | Red) << std::endl;
    ManaCost ColorSeq("3WUBRG");
    std::cout << "ManaCost of Coalition Victory " << ColorSeq.GetConMana() << std::endl;
    return 0;
}
