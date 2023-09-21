#ifndef COMPUTEFREQUENCY_H
#define COMPUTEFREQUENCY_H

#include <stdio.h>
#include <cstring>
#include <iostream>

#define NUMBER_OF_CHARACTER 1024

#define INVALID_FREQUENCY 2

struct probabilityTable
{
    char character;
    float probabilityAppearance;
};

class ComputeFrequency
{
private:
    probabilityTable listTable[NUMBER_OF_CHARACTER];

public:
    ComputeFrequency();
    ~ComputeFrequency();

    bool g_ComputeFrequency_FrequencyProcessing(std::string p_string);

    probabilityTable *g_ComputeFrequency_get_probabilityTable()
    {
        return listTable;
    }
};

#endif