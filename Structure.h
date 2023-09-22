#ifndef STRUCTURE_H
#define STRUCTURE_H

#include <stdint.h>

#define NUMBER_OF_CHARACTER 1024
#define INVALID_FREQUENCY 2
#define INVALID_CHARACTER 128

struct Node
{
    char alphabet;
    uint8_t binaryDecision;
    float frequency;
    Node *left;
    Node *right;
    Node *parent;
};

struct probabilityTable
{
    char character;
    float probabilityAppearance;
};

struct encoding
{
    char character;
    uint8_t encodingHuffman;
};

struct decoding
{
    char character;
    uint8_t decodingHuffman;
};
#endif