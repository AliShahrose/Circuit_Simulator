#pragma once
#include "Component.h"

class Battery : public Component
{
private:
    double voltage{};
    
public:
    Battery(std::string, double, Connection&, Connection&);
    ~Battery() = default;

    void simulate(double&) override;
    double current() override;
};
