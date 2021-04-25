#include "druid.hpp"


Druid::Druid(JsonEntityBuilder &builder, JsonItemBuilder & inventory, uint32_t uid) : 
    Entity(builder, inventory, uid)
{
    std::cout << Name() << " the druid has entered the battle" << std::endl;
}



void Druid::Transform(Entity *target)
{
    Attack(target, GetIntelligence() * 1.5, "Transform");
}

void Druid::AnimalAttack(Entity *target)
{
    Attack(target, GetIntelligence() * 0.5, "Animal Attack");
}

void Druid::OutputStatus() const
{
    std::cout << Class() << ": " << this->Name()
                << "\n\tCurrent HP: " << this->CurrentHP()
                << "\n\tIntelligence: " << this->GetIntelligence()
                << std::endl;

    PrintInventory();
}

void Druid::WeaponAttack(Entity * target)
{
    Attack(target, 4.0, "Staff Attack");
}

void Druid::UseAction(Entity * target, const std::string& spellName, const std::string & args)
{
    if(spellName == "weapon_attack")
    {
        WeaponAttack(target);
        return;
    }
    if(spellName == "transform")
    {
        Transform(target);
        return;
    }
    if(spellName == "animal_attack")
    {
        AnimalAttack(target);
        return;
    }
    errorFindingAbility(spellName);
}