#include <stdio.h>
#include <string.h>
#include "listbuku.h"

static Buku daftarBuku[MAX_BUKU];
static int jumlahBuku = 0;

void initBuku() {
    jumlahBuku = 0;
}

void tambahBuku(char *judul, int stok) {
    strcpy(daftarBuku[jumlahBuku].judul, judul);
    daftarBuku[jumlahBuku].stok = stok;
    jumlahBuku++;
}

void tampilkanDaftarBuku() {
	int i;
    printf("\n=== Daftar Buku ===\n");
    for (i = 0; i < jumlahBuku; i++) {
        printf("- %s (Stok: %d)\n", daftarBuku[i].judul, daftarBuku[i].stok);
    }
}

int getJumlahBuku() {
    return jumlahBuku;
}

Buku* cariBuku(char *judul) {
	int i;
    for (i = 0; i < jumlahBuku; i++) {
        if (strcmp(daftarBuku[i].judul, judul) == 0)
            return &daftarBuku[i];
    }
    return NULL;
}

void kurangiStok(Buku *b) {
    if (b->stok > 0) {
        b->stok--;
    }
}

int kembalikanBuku(const char *judul) {
	
	int i;
    for (i = 0; i < jumlahBuku; i++) {
        if (strcmp(daftarBuku[i].judul, judul) == 0) {
            daftarBuku[i].stok++;
            return 1; // Berhasil
        }
    }
    return 0; // Tidak ditemukan
    
}


