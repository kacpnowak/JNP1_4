//
// Created by kacper on 24.11.18.
//

#ifndef PROJECT_REBELFLEET_H
#define PROJECT_REBELFLEET_H

#include <cassert>
#include "imperialfleet.h"

template<typename U>
class ImperialStarship;

template<typename U>
class RebelStarship {
protected:
    U shield, speed;

    RebelStarship() = default;

public:
    RebelStarship &operator-=(const ImperialStarship<U> &a) {
        takeDamage(a.getAttackPower());
        return *this;
    }

    typedef U valueType;

    RebelStarship(U shield, U speed) : shield(shield), speed(speed) {}

    U getShield() const { return shield; }

    U getSpeed() const { return speed; }

    void takeDamage(U damage) {
        if (damage < shield) {
            shield -= damage;
        } else {
            shield = 0;
        }
    }
};

template<typename U>
class Explorer : public RebelStarship<U> {
public:
//    template <typename I, typename R>
//    friend void attack(I & imperialShip, R & rebelShip);
    Explorer(U shield, U speed) : RebelStarship<U>(shield, speed) {}
};

template<typename U>
class XWing : public RebelStarship<U> {
private:
    U attackPower;
public:
//    template <typename I, typename R>
//    friend void attack(I & imperialShip, R & rebelShip);
    XWing(U attackPower, U shield, U speed) {
        assert((speed >= 299796) && (speed <= 2997960));
        this->attackPower = attackPower;
        this->shield = shield;
        this->speed = speed;
    }

    U getAttackPower() const { return attackPower; }
};

template<typename U>
class StarCruiser : public RebelStarship<U> {
private:
    U attackPower;
public:
//    template <typename I, typename R>
//    friend void attack(I & imperialShip, R & rebelShip);
    StarCruiser(U attackPower, U shield, U speed) {
        assert((speed >= 99999) && (speed <= 299795));
        this->attackPower = attackPower;
        this->shield = shield;
        this->speed = speed;
    }

    U getAttackPower() const { return attackPower; }
};

#endif //PROJECT_REBELFLEET_H
