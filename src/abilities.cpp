
#include "abilities.h"
#include "eventmanager.h"

/*TriggerAbility::TriggerAbility(const TriggerEvents Event)
{
    EventManager::GetEventSingleton().Subscribe(Event, this);
}

TriggerAbility::~TriggerAbility()
{
    //EventManager::GetEventSingleton().Unsubscribe()
}*/

Ability_Bushido::Ability_Bushido(const Vigor Number) :
    BushidoStrength(Number)
{
    EventManager::GetEventSingleton().Subscribe({TriggerEvents::AttackerBlocked, TriggerEvents::BlockerDeclared}, this);
}

Ability_Bushido::Ability_Bushido(const Ability_Bushido& Other)
{
    EventManager::GetEventSingleton().Subscribe({TriggerEvents::AttackerBlocked, TriggerEvents::BlockerDeclared}, this);
}

Ability_Bushido::~Ability_Bushido()
{
    EventManager::GetEventSingleton().Unsubscribe({TriggerEvents::AttackerBlocked, TriggerEvents::BlockerDeclared}, this);
}

AbilityName Ability_Bushido::GetAbilityID() const
{
    return AbilityName::Bushido;
}

void Ability_Bushido::NotifyOfEvent(const TriggerEvents Event, const magic_card& Card)
{

}

void Ability_Bushido::SetBushidoStrength(const Vigor Number)
{
    BushidoStrength = Number;
}

Vigor Ability_Bushido::GetBushidoStrength() const
{
    return BushidoStrength;
}
