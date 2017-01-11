#include "../math.h"
#include "../melee.h"

float (*sin)(float x) = (void*) SINE_ADDRESS;
float (*cos)(float x) = (void*) COSINE_ADDRESS;
float (*tan)(float x) = (void*) TANGENT_ADDRESS;
