#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include "ComputeFrequency.h"
#include "Huffman.h"

class Queue
{
protected:
    Node *listNode[NUMBER_OF_CHARACTER];
    uint8_t top;

public:
    Queue();
    ~Queue();

    void g_Queue_Insert(Node *p_node);
    Node *g_Queue_Deletion();
    void g_Queue_Sort();
};

#endif