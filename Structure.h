#ifndef STRUCTURE_H
#define STRUCTURE_H

#include <stdint.h>
struct Node
{
    uint8_t binaryDecision;
    float frequency;
    Node *left;
    Node *right;
};

struct probabilityTable
{
    char character;
    float probabilityAppearance;
};
#endif