#include "RecordFunc.h"
#include <map>
#include <cmath>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cassert>
#include <memory>
#include "DoubleColumn_CODE/definitions.h"

void IntoFile(unsigned int* Spk, unsigned int* SpkCnt, ofstream& file){
    for (unsigned int i=0;i<*SpkCnt;i++){
        file<<Spk[i];
        if(i<*SpkCnt-1){
            file<<" ";
        }
    }
    file<<endl;
}

void SaveSpike(map<string,map<string,ofstream>>& output){
    pullV1_H1CurrentSpikesFromDevice();
    IntoFile(glbSpkV1_H1,glbSpkCntV1_H1,output["V1"]["H1"]);
    pullV1_E23CurrentSpikesFromDevice();
    IntoFile(glbSpkV1_E23,glbSpkCntV1_E23,output["V1"]["E23"]);
    pullV1_S23CurrentSpikesFromDevice();
    IntoFile(glbSpkV1_S23,glbSpkCntV1_S23,output["V1"]["S23"]);
    pullV1_P23CurrentSpikesFromDevice();
    IntoFile(glbSpkV1_P23,glbSpkCntV1_P23,output["V1"]["P23"]);
    pullV1_V23CurrentSpikesFromDevice();
    IntoFile(glbSpkV1_V23,glbSpkCntV1_V23,output["V1"]["V23"]);
    pullV1_E4CurrentSpikesFromDevice();
    IntoFile(glbSpkV1_E4,glbSpkCntV1_E4,output["V1"]["E4"]);
    pullV1_S4CurrentSpikesFromDevice();
    IntoFile(glbSpkV1_S4,glbSpkCntV1_S4,output["V1"]["S4"]);
    pullV1_P4CurrentSpikesFromDevice();
    IntoFile(glbSpkV1_P4,glbSpkCntV1_P4,output["V1"]["P4"]);
    pullV1_V4CurrentSpikesFromDevice();
    IntoFile(glbSpkV1_V4,glbSpkCntV1_V4,output["V1"]["V4"]);
    pullV1_E5CurrentSpikesFromDevice();
    IntoFile(glbSpkV1_E5,glbSpkCntV1_E5,output["V1"]["E5"]);
    pullV1_S5CurrentSpikesFromDevice();
    IntoFile(glbSpkV1_S5,glbSpkCntV1_S5,output["V1"]["S5"]);
    pullV1_P5CurrentSpikesFromDevice();
    IntoFile(glbSpkV1_P5,glbSpkCntV1_P5,output["V1"]["P5"]);
    pullV1_V5CurrentSpikesFromDevice();
    IntoFile(glbSpkV1_V5,glbSpkCntV1_V5,output["V1"]["V5"]);
    pullV1_E6CurrentSpikesFromDevice();
    IntoFile(glbSpkV1_E6,glbSpkCntV1_E6,output["V1"]["E6"]);
    pullV1_S6CurrentSpikesFromDevice();
    IntoFile(glbSpkV1_S6,glbSpkCntV1_S6,output["V1"]["S6"]);
    pullV1_P6CurrentSpikesFromDevice();
    IntoFile(glbSpkV1_P6,glbSpkCntV1_P6,output["V1"]["P6"]);
    pullV1_V6CurrentSpikesFromDevice();
    IntoFile(glbSpkV1_V6,glbSpkCntV1_V6,output["V1"]["V6"]);
    pullV2_H1CurrentSpikesFromDevice();
    IntoFile(glbSpkV2_H1,glbSpkCntV2_H1,output["V2"]["H1"]);
    pullV2_E23CurrentSpikesFromDevice();
    IntoFile(glbSpkV2_E23,glbSpkCntV2_E23,output["V2"]["E23"]);
    pullV2_S23CurrentSpikesFromDevice();
    IntoFile(glbSpkV2_S23,glbSpkCntV2_S23,output["V2"]["S23"]);
    pullV2_P23CurrentSpikesFromDevice();
    IntoFile(glbSpkV2_P23,glbSpkCntV2_P23,output["V2"]["P23"]);
    pullV2_V23CurrentSpikesFromDevice();
    IntoFile(glbSpkV2_V23,glbSpkCntV2_V23,output["V2"]["V23"]);
    pullV2_E4CurrentSpikesFromDevice();
    IntoFile(glbSpkV2_E4,glbSpkCntV2_E4,output["V2"]["E4"]);
    pullV2_S4CurrentSpikesFromDevice();
    IntoFile(glbSpkV2_S4,glbSpkCntV2_S4,output["V2"]["S4"]);
    pullV2_P4CurrentSpikesFromDevice();
    IntoFile(glbSpkV2_P4,glbSpkCntV2_P4,output["V2"]["P4"]);
    pullV2_V4CurrentSpikesFromDevice();
    IntoFile(glbSpkV2_V4,glbSpkCntV2_V4,output["V2"]["V4"]);
    pullV2_E5CurrentSpikesFromDevice();
    IntoFile(glbSpkV2_E5,glbSpkCntV2_E5,output["V2"]["E5"]);
    pullV2_S5CurrentSpikesFromDevice();
    IntoFile(glbSpkV2_S5,glbSpkCntV2_S5,output["V2"]["S5"]);
    pullV2_P5CurrentSpikesFromDevice();
    IntoFile(glbSpkV2_P5,glbSpkCntV2_P5,output["V2"]["P5"]);
    pullV2_V5CurrentSpikesFromDevice();
    IntoFile(glbSpkV2_V5,glbSpkCntV2_V5,output["V2"]["V5"]);
    pullV2_E6CurrentSpikesFromDevice();
    IntoFile(glbSpkV2_E6,glbSpkCntV2_E6,output["V2"]["E6"]);
    pullV2_S6CurrentSpikesFromDevice();
    IntoFile(glbSpkV2_S6,glbSpkCntV2_S6,output["V2"]["S6"]);
    pullV2_P6CurrentSpikesFromDevice();
    IntoFile(glbSpkV2_P6,glbSpkCntV2_P6,output["V2"]["P6"]);
    pullV2_V6CurrentSpikesFromDevice();
    IntoFile(glbSpkV2_V6,glbSpkCntV2_V6,output["V2"]["V6"]);
}

