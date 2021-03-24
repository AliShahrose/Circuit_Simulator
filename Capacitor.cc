#include "Capacitor.h"
#include <string>

Capacitor::Capacitor(std::string nm, double c, Connection& p, Connection& n) : Component(nm, p, n), capacitance{c} {}

void Capacitor::simulate(double& t)
{
    double diff = capacitance * ((positive.value - negative.value) - charge) * t;
    charge += diff;

    if(positive.value > negative.value)
    {
        positive.value -= diff;
        negative.value += diff;
    }
    else
    {
        negative.value -= diff;
        positive.value += diff;
    }
}

double Capacitor::current()
{
    return capacitance * ((positive.value - negative.value) - charge);
}