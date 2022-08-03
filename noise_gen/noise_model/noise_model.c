#include "noise_model.h"
/*
 * white noise
 */
#define VOLUME_WN 300

/*
 * Brown Noise
 */
#define VOLUME_BN 0.125
#define LPF_Beta  0.005
float RawData;
float SmoothData[2] = {0, 0};

float
get_wnoise(){
    return (randq64_double()*2.0 -1.0)/VOLUME_WN;
}

float
get_bnoise(int slot){
    RawData = (randq64_double()*2.0 -1.0)/VOLUME_BN;
    SmoothData[slot] = SmoothData[slot] - (LPF_Beta * (SmoothData[slot] - RawData)); // RC Filter
    return SmoothData[slot];
}
