#include "Queue.h"

Queue::Queue()
{
    top = -1;
}

Queue::~Queue()
{
}

void Queue::g_Queue_Insert(Node *p_node)
{
    top += 1;
    listNode[top] = p_node;
}

Node *Queue::g_Queue_Deletion()
{
    return listNode[top--];
}

uint8_t Queue::g_Queue_TopIs()
{
    return top;
}

Node *Queue::g_Queue_GetNode(int k)
{
    return listNode[k];
}

void Queue::g_Queue_Sort()
{
    // Soft: maximum -> minimum
    Node *tmp;
    int indexAtMax = 0;
    for (int i = 0; i <= top; i++)
    {
        float maxp_string = listNode[i]->frequency;
        for (int j = i + 1; j <= top; j++)
        {
            if (maxp_string <= listNode[j]->frequency)
            {
                maxp_string = listNode[j]->frequency;
                indexAtMax = j;
            }
        }
        // Swap these two node
        listNode[indexAtMax] = tmp;
        listNode[indexAtMax] = listNode[i];
        listNode[i] = tmp;
    }
}