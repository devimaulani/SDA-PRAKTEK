#ifndef MORSE_TREE_H
#define MORSE_TREE_H

#define MAX_NODE 38
#define NIL 0

typedef struct {
    char info[10]; // untuk mendukung "SPASI"
    int dot;
    int dash;
    int parent;
} MorseNode;

typedef MorseNode MorseTree[MAX_NODE + 1];

void CreateMorseTree(MorseTree T);
void tampilkanKamus(MorseTree T);
void printTreeVisual(MorseTree T, int index, int depth);
void InOrderTraversal(MorseTree T, int idx);
int findCharIndex(MorseTree T, const char* c);
void reversePath(MorseTree T, int index, char* buffer);
void encodeChar(MorseTree T, const char* c, char* hasil);
int decodeMorse(MorseTree T, const char* code);
void encodeText(MorseTree T, const char* text);
void decodeText(MorseTree T, const char* morseSequence);
void encodeFromFile(MorseTree T, const char* inputFile, const char* outputFile);
void decodeFromFile(MorseTree T, const char* inputFile, const char* outputFile);
#endif
