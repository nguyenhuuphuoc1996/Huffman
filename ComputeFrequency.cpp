#include "ComputeFrequency.h"
ComputeFrequency::ComputeFrequency()
{
    for (int i = 0; i < NUMBER_OF_CHARACTER; i++)
    {
        listTable[i].probabilityAppearance = INVALID_FREQUENCY;
        listTable[i].character = INVALID_CHARACTER;
    }
}
ComputeFrequency::~ComputeFrequency()
{
}

bool ComputeFrequency::g_ComputeFrequency_FrequencyProcessing(std::string p_string)
{
    bool retProbability = true;

    int lengthOfString = p_string.length();
    int numberOfCharInString = 0;
    int i, j;
    int indexAtMax = 0;

    while (p_string[0] != '\0')
    {
        int k = 0;
        char currentCharacter = p_string[0];
        int m_count = 0;
        while (p_string[k] != '\0')
        {
            if (currentCharacter == p_string[k])
            {
                m_count += 1;
                // remove duplicate character in given string
                p_string.erase(k, 1);
                continue;
            }
            k += 1;
        }
        // calculate probability of character p_string[k]
        listTable[numberOfCharInString].character = currentCharacter;
        listTable[numberOfCharInString].probabilityAppearance = (float)((float)m_count / lengthOfString);
        numberOfCharInString += 1;
    }

    // Soft: maximum -> minimum
    for (i = 0; i < 10; i++)
    {
        float maxp_string = listTable[i].probabilityAppearance;
        for (j = i + 1; j < 10; j++)
        {
            if (maxp_string <= listTable[j].probabilityAppearance)
            {
                maxp_string = listTable[j].probabilityAppearance;
                indexAtMax = j;
            }
        }
        // Set the max value at index i
        listTable[indexAtMax].probabilityAppearance = listTable[i].probabilityAppearance;
        listTable[i].probabilityAppearance = maxp_string;
    }

    return retProbability;
}