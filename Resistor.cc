#include "Resistor.h"
#include <string>

Resistor::Resistor(std::string nm, double r, Connection& p, Connection& n) : Component(nm, p, n), resistance{r} {}

void Resistor::simulate(double& t)
{
    double diff = positive.value - negative.value;
    positive.value = positive.value - (diff / resistance) * t;
    negative.value = negative.value + (diff / resistance) * t;
}

double Resistor::current()
{
    return (positive.value - negative.value / resistance);
}