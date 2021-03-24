#pragma once
#include "Connection.h"
#include <string>


class Component
{
protected:
    std::string name{};
    Connection& positive;
    Connection& negative;

public:
    Component(std::string, Connection&, Connection&);
    virtual ~Component() = default;

    virtual void simulate(double&) = 0;
    virtual double current() = 0;

    std::string getName() const;
    double getVolt() const;
};
