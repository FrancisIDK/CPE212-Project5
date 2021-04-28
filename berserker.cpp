#include "berserker.hpp"


Berserker::Berserker(JsonEntityBuilder &builder, JsonItemBuilder & inventory, uint32_t uid) :
    Entity(builder, inventory, uid)
{
    std::cout << Name() << " the berserker has entered the battle" << std::endl;
}


void Berserker::AmbitiousStrike(Entity * target)
{
    int damage = 0;
    if(target->CurrentHP() >= 150)
    {
        damage = GetStrength() * 3.0;
    }
    else if (target->CurrentHP() >= 100)
    {
        damage = GetStrength() * 2.0;
    }
    else
    {
        damage = GetStrength() * 1.0;
    }
    Attack(target, damage, "Ambitious Strike");
}

void Berserker::Frenzy(Entity * target)
{
    Attack(target, GetStrength() * 0.75, "Frenzy");
    Attack(target, GetStrength() * 0.75, "Frenzy");
}

void Berserker::OutputStatus() const
{
    std::cout << Class() << ": " << this->Name()
                << "\n\tCurrent HP: " << this->CurrentHP()
                << "\n\tStrength: " << this->GetStrength()
                << std::endl;
                
    PrintInventory();
}

void Berserker::WeaponAttack(Entity * target)
{
    Attack(target, 4.0, "Slash");
}

void Berserker::UseAction(Entity * target, const std::string& spellName, const std::string & args)
{
    if(spellName == "weapon_attack")
    {
        WeaponAttack(target);
        return;
    }
    if(spellName == "ambitious_strike")
    {
        AmbitiousStrike(target);
        return;
    }
    if(spellName == "frenzy")
    {
        Frenzy(target);
        return;
    }
    errorFindingAbility(spellName);

}