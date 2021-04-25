#include "druid.hpp"


Druid::Druid(JsonEntityBuilder &builder, JsonItemBuilder & inventory, uint32_t uid) : 
    Entity(builder, inventory, uid)
{
    std::cout << Name() << " the druid has entered the battle" << std::endl;
}



void Druid::CatScratch(Entity *target)
{
    Attack(target, GetIntelligence() * 0.5, "Cat Scratch");
    Attack(target, GetIntelligence() * 0.5, "Cat Scratch");
    Attack(target, GetIntelligence() * 0.5, "Cat Scratch");
}

void Druid::BearClaw(Entity *target)
{
    Attack(target, GetIntelligence() * 2, "Bear Claw");
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
    if(spellName == "cat_scratch")
    {
        CatScratch(target);
        return;
    }
    if(spellName == "bear_claw")
    {
        BearClaw(target);
        return;
    }
    errorFindingAbility(spellName);
}