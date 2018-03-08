
#ifndef enums_h
#define enums_h

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

enum class CombatResult
{
    AttackerWins,
    DefenderWins,
    Tie,
    DoubleLoss
};

enum class TriggerEvents
{
    BlockerDeclared,
    AttackerDeclared,
    AttackerBlocked,
    SpellCast,
    SpellCountered,
    EntersBattlefield,
    PermanantTargeted,
    PermanantExiled,
    PermanantDestroyed,
    PermanantBounce,
    PermanantTapped,
    PermanantUnTapped,
    PermanantActivated,
    PermanantSacrificed,
    PlayerDiscard,
    PlayerTargeted,
    PlayerLifeGained,
    PlayerLifeLost,
    PlayerSearchLibrary,
    CounterAdded,
    CounterRemoved,
    CardManifested,
    CardTurnedUp,


    BeginningPhaseStart,
    PreCombatMainPhaseStart,
    CombatPhaseStart,
    PostCombatMainPhaseStart,
    EndingPhaseStart,

    UntapStepStart,
    UpkeepStepStart,
    DrawStepStart,

    BeginningCombatStepStart,
    DeclareAttackersStepStart,
    DeclareBlockersStepStart,
    CombatDamageStepStart,
    EndOfCombatStepStart,

    EndStepStart,
    CleanUpStepStart
};

enum class AbilityType
{
    Static,
    Activated,
    Triggered
};

enum class AbilityName
{
    //Static
    DeathTouch,
    Fear,
    FirstStrike,
    ProtectionFrom,

    //Activated
    CustomActivated,

    //Triggered
    Bushido,
    CustomTriggered
};

#endif // enums_h
