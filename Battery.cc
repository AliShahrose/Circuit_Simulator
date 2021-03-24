#include "Component.h"
#include "Battery.h"

Battery::Battery(std::string nm, double v, Connection& p, Connection& n) : Component(nm, p, n), voltage{v} {}


void Battery::simulate(double& t)
{
    positive.value = voltage;
    negative.value = 0.0;
}

double Battery::current()
{
    return 0;
}