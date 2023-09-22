#include "Huffman.h"
Huffman::Huffman()
{
    for (int i = 0; i < NUMBER_OF_CHARACTER; i++)
    {
        var_Queue_encoding[i].character = INVALID_CHARACTER;
        var_Queue_encoding[i].encodingHuffman = 0xff;
    }
    root->parent = nullptr;
}
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
        // Convert from raw data to Node
        //
        //
        //
        // Only leaf had character
        node->alphabet = listTable[k].character;
        node->frequency = listTable[k].probabilityAppearance;
        node->left = nullptr;
        node->right = nullptr;
        //
        //
        //
        // add to array of pointer, managed by Queue class
        g_Queue_Insert(node);
        //
        //
        //
        // backup data in Huffman object: leaf node and character
        var_Queue_encoding[k].character = listTable[k].character;
        leafNode[k] = node;
        //
        //
        //
        k = k + 1;
    }
}
void Huffman::g_Huffman_Procedure()
{
    // Huffman processing
    //
    //
    //
    Node *x, *y; // store two smallest element of frequency
    Node *z;     // new node
    //
    //
    //
    while (g_Queue_TopIs() != 1)
    {
        // Process until there is only one element in Queue
        // That is the element with frequency is 1 (100%)
        //
        //
        //
        z = new Node;
        x = g_Queue_Deletion();
        y = g_Queue_Deletion();
        x->binaryDecision = 0; // left child
        y->binaryDecision = 1; // right child
        x->parent = z;
        y->parent = z;
        //
        //
        //
        z->alphabet = INVALID_CHARACTER;
        z->left = x;
        z->right = y;
        z->frequency = x->frequency + y->frequency;
        //
        //
        //
        // Insert z node to Queue
        g_Queue_Insert(z);
        //
        //
        //
        // Sort Queue in decreasing order
        g_Queue_Sort();
    }
    //
    //
    //
    // root is at top element in Queue
    root = g_Queue_GetNode(g_Queue_TopIs());
}

void Huffman::g_Huffman_Encoding()
{
    int k = 0;
    int VariableLengthCodeword = 0;
    uint8_t binary = 0;
    Node *travesal;
    //
    //
    //
    while (var_Queue_encoding[k].character != INVALID_CHARACTER)
    {
        travesal = leafNode[k];
        while (travesal->parent != nullptr)
        {
            binary = 0;
            binary = travesal->binaryDecision << (8 - VariableLengthCodeword);
            //
            //
            //
            // Get binary code from node
            var_Queue_encoding[k].encodingHuffman |= binary;
            //
            //
            //
            // Increase code word order
            VariableLengthCodeword = VariableLengthCodeword + 1;
            //
            //
            //
            // Go backward to root
            travesal = travesal->parent;
        }
        //
        //
        // Final fixed-length-code
        var_Queue_encoding[k].encodingHuffman = var_Queue_encoding[k].encodingHuffman >> (8 - VariableLengthCodeword + 1);
    }
}
