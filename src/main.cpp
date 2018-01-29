// 1.Create a struct that can store all the information that is on a magic card.
//It needs only to store the information that is important for game-play

//2.Create a function that accepts two of these structs, one as attacker, one as defender,
//and lazily compares their power and toughness to see who would win.  The winner should be the return value.

//3.Two such structs must be instantiated and populated with data pertaining to two cards,
//and then the combat function must be invoked.  The result should be reported to cout.
#include <string>
#include <iostream>

enum CombatResult
{
    AttackerWins,
    DefenderWins,
    Tie,
    DoubleLoss
};


struct magic_card
{
    std::string Name;
    std::string Cost;
    std::string SuperType;
    std::string SubType;
    int Power;
    int Toughness;
};


void print(const std::string& str)
{
    std::cout << str << std::endl;
}


CombatResult combat(magic_card attacker, magic_card defender)
{
    bool DefenderDeath = attacker.Power >= defender.Toughness;
    bool AttackerDeath = defender.Power >= attacker.Toughness;

    if(DefenderDeath && AttackerDeath)
    {
        return DoubleLoss;
    }

    if(DefenderDeath && !AttackerDeath)
    {
        return AttackerWins;
    }

    if(AttackerDeath && !DefenderDeath)
    {
        return DefenderWins;
    }

    if(!AttackerDeath && !DefenderDeath)
    {
        return Tie;
    }
}

int main()
{

    magic_card attacker;
    attacker.Name = "Lava Zombie";
    attacker.Cost = "1BR";
    attacker.SuperType = "Creature";
    attacker.SubType = "Zombie";
    attacker.Power = 4;
    attacker.Toughness = 3;

    magic_card defender;
    defender.Name = "Wall of Wonder";
    defender.Cost = "2BB";
    defender.SuperType = "Creature";
    defender.SubType = "Wall";
    defender.Power = 1;
    defender.Toughness = 5;


    int c = combat(attacker, defender);

    if(c == AttackerWins)
    {
        std::cout << "End Match: Attacker Wins" << std::endl;
    }

    if(c == DefenderWins)
    {
        std::cout << "End Match: Defender Wins" << std::endl;
    }

    if(c == DoubleLoss)
    {
        std::cout << "End Match: Double Loss" << std::endl;
    }

    if(c == Tie)
    {
        std::cout << "End Match: Tie" << std::endl;
    }
    return 0;
}
