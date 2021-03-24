#pragma once
#include "Component.h"

class Resistor : public Component
{
private:
    double resistance{};
    
public:
    Resistor(std::string, double, Connection&, Connection&);
    ~Resistor() = default;

    void simulate(double&) override;
    double current() override;
};
