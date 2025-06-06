#include <map>
#include <string>
#include <iostream>
using namespace std;

namespace ParaMeters{
    map<string,float> input={
        {"H1", 501.0},
        {"V23", 501.0-10.0},
        {"S23", 501.0},
        {"E23", 501.0+50.0},
        {"P23", 501.0},
        {"V4", 501.0-50.0},
        {"S4", 501.0},
        {"E4", 501.0+50.0},
        {"P4", 501.0+10.0},
        {"V5", 501.0-10.0},
        {"S5", 501.0},
        {"E5", 501.0+10.0},
        {"P5", 501.0},
        {"V6", 501.0-10.0},
        {"S6", 501.0},
        {"E6", 501.0+50.0},
        {"P6", 501.0}
    };
    struct lifParam{
        float EL = -70.0;
        float Vth = -50.0;
        float Vreset = -60.0;
        float Cm = 500.0;
        float taum = 20.0;
        float tau_syn = 0.5;
        float t_ref = 2.0;
    }lifParam;
    
    struct weightInfo{
        double wAve;
        double wSd;
    };

    enum Area{
        AreaV1,AreaV4,AreaMax
    };
    enum Population{
        PopulationH1,PopulationE23,PopulationS23,PopulationP23,PopulationV23,
        PopulationE4,PopulationS4,PopulationP4,PopulationV4,
        PopulationE5,PopulationS5,PopulationP5,PopulationV5,
        PopulationE6,PopulationS6,PopulationP6,PopulationV6,PopulationMax,
    };
    enum NeuronType{
        typeE,typeI,typeMax
    };
    // Population names
    const string populationNames[PopulationMax] = {
        "H1","E23","S23","P23","V23",
        "E4","S4","P4","V4",
        "E5","S5","P5","V5",
        "E6","S6","P6","V6"
    };
    const string areaNames[AreaMax] = {
        "V1","V2"
    };
    const double meanDelay[typeMax] = {
        1.5,    // PopulationE
        0.75};  // PopulationI

    const double delaySD[typeMax] = {
        0.75,   // PopulationE
        0.375}; // PopulationI
    const double dtMs = 0.1;
    const bool measureTiming = true;
    const double Vmean=-150.0;
    const double Vsd=50.0;
    const double speed=3.5;
    string getPopName(unsigned int Area, unsigned int Population){
        return string(areaNames[Area]+"_"+populationNames[Population]);
    }
    string getSynName(unsigned int tarArea, unsigned int tarPopulation, unsigned int srcArea, unsigned int srcPopulation){
        return string(getPopName(srcArea, srcPopulation)+"to"+getPopName(tarArea, tarPopulation));
    }
}