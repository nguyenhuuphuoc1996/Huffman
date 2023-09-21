#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <iostream>
#include "ComputeFrequency.h"
#include <stdint.h>

struct Node
{
    uint8_t binaryDecision;
    float frequency;
    Node *left;
    Node *right;
};

class Huffman
{
private:
    Node *root;

public:
    Huffman() = default;
    ~Huffman();
    void g_Huffman_NodeCreate();
    void g_Huffman_Procedure(probabilityTable p_listTable[]);
};

#endif