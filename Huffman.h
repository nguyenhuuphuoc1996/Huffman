#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <iostream>
#include <stdint.h>
#include "ComputeFrequency.h"
#include "Structure.h"
#include "Queue.h"

class Huffman : public Queue
{
private:
    Node *root;

public:
    Huffman() = default;
    ~Huffman();
    void g_Huffman_NodeCreate(probabilityTable listTable[]);
    void g_Huffman_Procedure(probabilityTable p_listTable[]);
};

#endif