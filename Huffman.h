#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <iostream>
#include <stdint.h>
// #include "ComputeFrequency.h"
#include "Structure.h"
#include "Queue.h"

class Huffman : public Queue
{
private:
    Node *root;
    Node *leafNode[NUMBER_OF_CHARACTER];
    encoding var_Queue_encoding[NUMBER_OF_CHARACTER];

public:
    Huffman();
    ~Huffman();
    void g_Huffman_NodeCreate(probabilityTable listTable[]);
    void g_Huffman_Procedure();
    void g_Huffman_Encoding();
    void g_Huffman_Decoding();
};

#endif