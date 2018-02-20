
#ifndef manacost_h
#define manacost_h

#include <string>
#include "datatypes.h"
#include "enums.h"

class ManaCost
{
    std::string Cost;
public:
    ManaCost() = default;
    ManaCost(const ManaCost& Other) = default;
    ManaCost(ManaCost&& Other) = default;
    ManaCost(const std::string& Str);
    ~ManaCost() = default;

    ManaCost& operator=(const ManaCost& Other) = default;
    ManaCost& operator=(ManaCost&& Other) = default;

    void SetCost(const std::string& ToSet);
    const std::string& GetCost() const;

    Whole GetDevotion(Whole Colors) const;
    Whole GetConMana() const;
    Whole GetColors() const;
};

#endif //manacost_h
