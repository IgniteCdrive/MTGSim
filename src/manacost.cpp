
#include "manacost.h"

ManaCost::ManaCost(const std::string& Str) :
    Cost(Str)
    {}

void ManaCost::SetCost(const std::string& ToSet)
{
    Cost = ToSet;
}

const std::string& ManaCost::GetCost() const
{
    return Cost;
}

Whole ManaCost::GetDevotion(Whole Colors) const
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

Whole ManaCost::GetConMana() const
{
    Whole RetCost = 0;
    size_t ColorPos = Cost.find_first_of("WUBRGC");
    std::string NumCost = Cost.substr(0,ColorPos);
    RetCost += std::stoi(NumCost);
    RetCost += (Cost.size() - ColorPos);
    return RetCost;
}

Whole ManaCost::GetColors() const
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
