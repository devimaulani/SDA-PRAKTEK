#ifndef ANTRIAN_H
#define ANTRIAN_H

#include "listbuku.h"

typedef struct Orang {
    char nama[100];
    char kategori[20];
    char judulBuku[100];
    struct Orang *next;
} Orang;

void initAntrian();
void tambahPeminjam(char *nama, char *kategori, char *judulBuku);
void tampilkanAntrian();
void prosesPeminjaman();
void hapusSemuaAntrian();

#endif

