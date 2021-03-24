#include "Component.h"
#include <string>


Component::Component(std::string nm, Connection& p, Connection& n) : name{nm}, positive{p}, negative{n} {}

void Component::simulate(double& t) {}

double Component::current() {}

std::string Component::getName() const
{
    return name;
}

double Component::getVolt() const
{
    return positive.value - negative.value;
}
