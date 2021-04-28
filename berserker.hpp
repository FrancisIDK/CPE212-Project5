#ifndef BERSERKER_HPP
#define BERSERKER_HPP

#include "JsonEntityBuilder.hpp"
#include "entity.hpp"


class Berserker : public Entity
{
private:

    void AmbitiousStrike(Entity* target);
    void Frenzy(Entity * target);

public:
    Berserker(JsonEntityBuilder &builder, JsonItemBuilder & inventory, uint32_t uid);

    virtual void OutputStatus() const override;
    virtual void WeaponAttack(Entity * target) override;

    virtual void UseAction(Entity * target, const std::string& spellName, const std::string & args) override;

};



#endif // BERSERKER_HPP