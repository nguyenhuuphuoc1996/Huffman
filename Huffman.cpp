#include "Huffman.h"
Huffman::~Huffman()
{
}
void Huffman::g_Huffman_NodeCreate(probabilityTable listTable[])
{
    // Create every single node
    Node *node;
    int k = 0;
    while (listTable[k].probabilityAppearance != INVALID_FREQUENCY)
    {
        node = new Node;
        node->frequency = listTable[k].probabilityAppearance;
        node->left = nullptr;
        node->right = nullptr;
        // add to array of pointer, managed by Queue class
        listNode[k] = node;
    }
}
void Huffman::g_Huffman_Procedure(probabilityTable p_listTable[])
{
    // Huffman processing
}
