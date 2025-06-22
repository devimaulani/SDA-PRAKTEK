#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "morsetree.h"

void CreateMorseTree(MorseTree T) {
	int i;
    for (i = 1; i <= MAX_NODE; i++) {
        strcpy(T[i].info, "*");
        T[i].dot = NIL;
        T[i].dash = NIL;
        T[i].parent = NIL;
    }

    // Root
    strcpy(T[1].info, "*"); T[1].dot = 2; T[1].dash = 3;

    strcpy(T[2].info, "Z"); T[2].dot = 4; T[2].dash = 5; T[2].parent = 1;
    strcpy(T[3].info, "A"); T[3].dot = 6; T[3].dash = 7; T[3].parent = 1;

    strcpy(T[4].info, "Y"); T[4].dot = 8; T[4].dash = 9; T[4].parent = 2;
    strcpy(T[5].info, "X"); T[5].dot = 10; T[5].dash = 11; T[5].parent = 2;

    strcpy(T[6].info, "B"); T[6].dot = 12; T[6].dash = 13; T[6].parent = 3;
    strcpy(T[7].info, "C"); T[7].dot = 14; T[7].dash = 15; T[7].parent = 3;

    strcpy(T[8].info, "W"); T[8].dot = 16; T[8].dash = 17; T[8].parent = 4;
    strcpy(T[9].info, "V"); T[9].dot = 18; T[9].dash = 19; T[9].parent = 4;
    strcpy(T[10].info, "U"); T[10].dot = 20; T[10].dash = 21; T[10].parent = 5;
    strcpy(T[11].info, "T"); T[11].dot = 22; T[11].dash = 23; T[11].parent = 5;

    strcpy(T[12].info, "D"); T[12].dot = 28; T[12].dash = NIL; T[12].parent = 6;
    strcpy(T[13].info, "E"); T[13].dot = 29; T[13].dash = NIL; T[13].parent = 6;

    strcpy(T[14].info, "F"); T[14].dot = 30; T[14].dash = 31; T[14].parent = 7;
    strcpy(T[15].info, "G"); T[15].dot = 32; T[15].dash = 33; T[15].parent = 7;

    strcpy(T[16].info, "S"); T[16].dot = 34; T[16].dash = NIL; T[16].parent = 8;
    strcpy(T[17].info, "R"); T[17].dot = 35; T[17].dash = NIL; T[17].parent = 8;
    strcpy(T[18].info, "Q"); T[18].parent = 9;
    strcpy(T[19].info, "P"); T[19].parent = 9;
    strcpy(T[20].info, "O"); T[20].parent = 10;
    strcpy(T[21].info, "8"); T[21].parent = 10;

    strcpy(T[22].info, "N"); T[22].parent = 11;
    strcpy(T[23].info, "SPASI"); T[23].parent = 11;

    strcpy(T[28].info, "L"); T[28].parent = 12;
    strcpy(T[29].info, "H"); T[29].parent = 13;
    strcpy(T[30].info, "I"); T[30].parent = 14;
    strcpy(T[31].info, "J"); T[31].parent = 14;
    strcpy(T[32].info, "K"); T[32].parent = 15;
    strcpy(T[33].info, "M"); T[33].dot = 36; T[33].dash = 37; T[33].parent = 15;
    strcpy(T[34].info, "7"); T[34].parent = 16;
    strcpy(T[35].info, "9"); T[35].parent = 17;
    strcpy(T[36].info, "3"); T[36].parent = 33;
    strcpy(T[37].info, "6"); T[37].parent = 33;
}

void tampilkanKamus(MorseTree T) {
	int i;
    char kode[10];
    printf("\n===== Kamus Morse =====\n");
    for (i = 1; i <= MAX_NODE; i++) {
        if (strcmp(T[i].info, "*") != 0) {
            reversePath(T, i, kode);
            printf("%s : %s\n", T[i].info, kode);
        }
    }
}

void printTreeVisual(MorseTree T, int index, int depth) {
	int i ;
    if (index == NIL) return;
    printTreeVisual(T, T[index].dash, depth + 1);
    for ( i = 0; i < depth; i++) printf("   ");
    printf("%s\n", T[index].info);
    printTreeVisual(T, T[index].dot, depth + 1);
}

void InOrderTraversal(MorseTree T, int idx) {
    if (idx == NIL) return;
    InOrderTraversal(T, T[idx].dot);
    if (strcmp(T[idx].info, "*") != 0) printf("%s ", T[idx].info);
    InOrderTraversal(T, T[idx].dash);
}

int findCharIndex(MorseTree T, const char* c) {
	int i;
    for ( i = 1; i <= MAX_NODE; i++) {
        if (strcasecmp(T[i].info, c) == 0) return i;
    }
    return NIL;
}

void reversePath(MorseTree T, int index, char* buffer) {
    char temp[10];
    int pos = 0;
    int i;
    while (T[index].parent != NIL) {
        int p = T[index].parent;
        if (T[p].dot == index) temp[pos++] = '.';
        else if (T[p].dash == index) temp[pos++] = '-';
        index = p;
    }
    for (i = 0; i < pos; i++)
        buffer[i] = temp[pos - i - 1];
    buffer[pos] = '\0';
}

void encodeChar(MorseTree T, const char* c, char* hasil) {
    int idx = findCharIndex(T, c);
    if (idx == NIL) strcpy(hasil, "?");
    else reversePath(T, idx, hasil);
}

int decodeMorse(MorseTree T, const char* code) {
    int idx = 1;
    int i;
    for (i = 0; code[i]; i++) {
        if (code[i] == '.') idx = T[idx].dot;
        else if (code[i] == '-') idx = T[idx].dash;
        if (idx == NIL) return NIL;
    }
    return idx;
}

void encodeText(MorseTree T, const char* text) {
    char hasil[10], temp[10];
    int i;
    for (i = 0; text[i]; i++) {
        if (text[i] == ' ') {
            printf("   ");
            continue;
        }
        sprintf(temp, "%c", toupper(text[i]));
        encodeChar(T, temp, hasil);
        printf("%s ", hasil);
    }
    printf("\n");
}

void decodeText(MorseTree T, const char* morseSequence) {
    char buffer[10];
    int pos = 0;
    int i;
    for ( i = 0; ; i++) {
        if (morseSequence[i] == ' ' || morseSequence[i] == '\0') {
            buffer[pos] = '\0';
            if (pos > 0) {
                int idx = decodeMorse(T, buffer);
                if (idx != NIL)
                    printf("%s", T[idx].info);
                else
                    printf("?");
                pos = 0;
            } else {
                printf(" ");
            }
            if (morseSequence[i] == '\0') break;
        } else {
            buffer[pos++] = morseSequence[i];
        }
    }
    printf("\n");
}

void encodeFromFile(MorseTree T, const char* inputFile, const char* outputFile) {
	int i;
    FILE* fin = fopen(inputFile, "r");
    FILE* fout = fopen(outputFile, "w");
    if (!fin || !fout) {
        printf("Gagal membuka file.\n");
        return;
    }
    char line[256], hasil[10], temp[10];
    while (fgets(line, sizeof(line), fin)) {
        for (i = 0; line[i]; i++) {
            if (line[i] == ' ') {
                fprintf(fout, "   ");
                continue;
            }
            sprintf(temp, "%c", toupper(line[i]));
            encodeChar(T, temp, hasil);
            fprintf(fout, "%s ", hasil);
        }
        fprintf(fout, "\n");
    }
    fclose(fin);
    fclose(fout);
}


void decodeFromFile(MorseTree T, const char* inputFile, const char* outputFile) {
	int i;
    FILE* fin = fopen(inputFile, "r");
    FILE* fout = fopen(outputFile, "w");

    if (!fin || !fout) {
        printf("Gagal membuka file.\n");
        return;
    }

    char line[256];
    char buffer[10];
    int pos = 0;
    int space_count = 0;

    while (fgets(line, sizeof(line), fin)) {
        for (i = 0; ; i++) {
            char ch = line[i];

            if (ch == '.' || ch == '-') {
                buffer[pos++] = ch;
                space_count = 0;
            } else if (ch == ' ' || ch == '\0' || ch == '\n') {
                buffer[pos] = '\0';

                if (pos > 0) {
                    int idx = decodeMorse(T, buffer);
                    if (idx != NIL)
                        fprintf(fout, "%s", T[idx].info);
                    else
                        fprintf(fout, "?");
                    pos = 0;
                }

                if (ch == ' ') {
                    space_count++;
                    // Jika lebih dari 1 spasi: antar kata
                    if (space_count == 2)
                        fprintf(fout, " ");
                } else {
                    space_count = 0;
                }

                if (ch == '\0' || ch == '\n') break;
            }
        }
        fprintf(fout, "\n");
    }

    fclose(fin);
    fclose(fout);
}
