#include "Connection.h"
#include "Component.h"
#include "Battery.h"
#include "Resistor.h"
#include "Capacitor.h"

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

void simulate(vector<Component*> circuit, int n, int l, double t);
void destroy(vector<Component*>& circuit);

int main(int argc, char** argv)
{
    // Command Line Arguments
    int num{};
    int line{};
    double time{};

    // Exception Handling
    try
    {
        num = stoi(argv[1]);
        line = stoi(argv[2]);
        time = stod(argv[3]);
    }
    catch(exception& e)
    {
        cerr << e.what();
        return -1;
    }

    // CIRCUIT 1
    Connection p1{};
    Connection n1{};
    Connection r123{};
    Connection r124{};

    vector<Component*> circuit1;

    circuit1.push_back(new Battery("Batt", 24.0, p1, n1));
    circuit1.push_back(new Resistor("R1", 6.0, p1, r124));
    circuit1.push_back(new Resistor("R2", 4.0, r124, r123));
    circuit1.push_back(new Resistor("R3", 8.0, r123, n1));
    circuit1.push_back(new Resistor("R4", 12.0, r124, n1));

    simulate(circuit1, num, line, time);
    // CIRCUIT 1

    //CIRCUIT 2
    Connection p2{};
    Connection n2{};
    Connection l2{};
    Connection r2{};

    vector<Component*> circuit2;

    circuit2.push_back(new Battery("Batt", 24.0, p2, n2));
    circuit2.push_back(new Resistor("R1", 150.0, p2, l2));
    circuit2.push_back(new Resistor("R2", 50.0, p2, r2));
    circuit2.push_back(new Resistor("R3", 100.0, l2, r2));
    circuit2.push_back(new Resistor("R4", 300.0, l2, n2));
    circuit2.push_back(new Resistor("R5", 250.0, r2, n2));

    simulate(circuit2, num, line, time);
    // CIRCUIT 2

    //CIRCUIT 3
    Connection p3{};
    Connection n3{};
    Connection l3{};
    Connection r3{};

    vector<Component*> circuit3;

    circuit3.push_back(new Battery("Batt", 24.0, p3, n3));
    circuit3.push_back(new Resistor("R1", 150.0, p3, l3));
    circuit3.push_back(new Resistor("R2", 50.0, p3, r3));
    circuit3.push_back(new Resistor("R3", 100.0, l3, r3));
    circuit3.push_back(new Resistor("R4", 300.0, l3, n3));
    circuit3.push_back(new Capacitor("C5", 0.75, r3, n3));

    simulate(circuit3, num, line, time);
    //CIRCUIT 3

    // Deallocating Memory
    destroy(circuit1);
    destroy(circuit2);
    destroy(circuit3);

    return 0;
}

void simulate(vector<Component*> circuit, int n, int l, double t)
{
    int count{};

    for(Component* c:circuit)
    {
        cout << setfill(' ') << setw(12) << c -> getName();
    }

    cout << endl;

    for(int i = 0; i <= circuit.size() - 1; i++)
    {
        cout << setfill(' ') << setw(6) << "Volt" << setfill(' ') << setw(6) << "Curr";
    }
    
    cout << endl;

    for (int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= circuit.size() - 1; j++)
        {
            circuit[j] -> simulate(t);
        }
        if (i == (n/l)*count)
        {
            for(Component* k:circuit)
            {
                cout << setfill(' ') << setw(6) << fixed << setprecision(2) << k -> getVolt() << " ";
                cout << setfill(' ') << setw(6) << fixed << setprecision(2) << k -> current();
            }
            cout << endl;
            count++;
        }
    }
}

void destroy(vector<Component*>& circuit)
{
    for(Component* c:circuit)
    {
        delete c;
    }
}