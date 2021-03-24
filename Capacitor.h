#pragma once
#include "Component.h"

class Capacitor : public Component
{
private:
    double capacitance{};
    double charge{};
public:
    Capacitor(std::string, double, Connection&, Connection&);
    ~Capacitor() = default;

    void simulate(double&) override;
    double current() override;
};
