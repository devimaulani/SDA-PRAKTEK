/* 
Author: Devi Maulnai
NIM: 241524007
Kelas: 1A
Prodi: Sarjana Terapan Teknik Informatika
Jurusan: Teknik Komputer dan Informatika
Politeknik Negeri Bandung
*/

#include "listbuku.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Buku* Head_Buku = NULL; // Inisialisasi pointer global ke head buku

void initList() {
    Head_Buku = NULL;
}

int isListBukuEmpty() {
    return Head_Buku == NULL;
}

int isBukuExist(char judul[]) {
    Buku* current = Head_Buku;
    while (current != NULL) {
        if (strcmp(current->judul, judul) == 0) {
            return 1; // Ditemukan
        }
        current = current->next;
    }
    return 0; // Tidak ditemukan
}

Buku* createBuku(char judul[], int stok) {
    Buku* newBuku = (Buku*)malloc(sizeof(Buku));
    if (newBuku == NULL) {
        printf("Gagal mengalokasikan memori untuk buku.\n");
        exit(1);
    }
    strcpy(newBuku->judul, judul);
    newBuku->stok = stok;
    newBuku->antrean = NULL;
    newBuku->next = NULL;
    return newBuku;
}

void insertBuku(char judul[], int stok) {
    if (isBukuExist(judul)) {
        printf("Buku \"%s\" sudah ada di daftar.\n", judul);
        return;
    }

    Buku* newBuku = createBuku(judul, stok);

    if (isListBukuEmpty()) {
        Head_Buku = newBuku;
    } else {
        Buku* current = Head_Buku;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newBuku;
    }
    printf("Buku \"%s\" berhasil ditambahkan.\n", judul);
}

void deleteBuku(char judul[]) {
    if (isListBukuEmpty()) {
        printf("List buku kosong.\n");
        return;
    }

    Buku* current = Head_Buku;
    Buku* prev = NULL;

    // Mencari buku berdasarkan judul
    while (current != NULL && strcmp(current->judul, judul) != 0) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Buku \"%s\" tidak ditemukan.\n", judul);
        return;
    }

    // Menghapus buku jika ditemukan
    if (prev == NULL) {
        Head_Buku = current->next; // Buku ada di awal list
    } else {
        prev->next = current->next;
    }

    // Bersihkan antrean peminjam jika ada
    Peminjam* tempPeminjam;  // Gunakan tempPeminjam untuk menyimpan peminjam sementara
    while (current->antrean != NULL) {
        tempPeminjam = current->antrean;  // Menyimpan peminjam sementara
        current->antrean = current->antrean->next;  // Pindah ke antrean berikutnya
        free(tempPeminjam);  // Bebaskan memori peminjam
    }

    free(current);  // Bebaskan memori buku yang dihapus
    printf("Buku \"%s\" berhasil dihapus.\n", judul);
}


Buku* cariBuku(char judul[]) {
    Buku* current = Head_Buku;
    while (current != NULL) {
        if (strcmp(current->judul, judul) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Fungsi untuk menampilkan semua buku dalam list
void tampilkanSemuaBuku() {
    if (isListBukuEmpty()) {
        printf("Tidak ada buku dalam daftar.\n");
        return;
    }

    Buku* current = Head_Buku;
    while (current != NULL) {
        printf("Judul Buku: %s\n", current->judul);
        printf("Stok: %d\n", current->stok);
        printf("--------------------------\n");
        current = current->next;
    }
}

void bersihkanListBuku() {
    Buku* current = Head_Buku;
    while (current != NULL) {
        Buku* temp = current;
        current = current->next;

        // Bersihkan antrean peminjam
        Peminjam* antre = temp->antrean;  // Pastikan temp->antrean adalah pointer ke Peminjam
        while (antre != NULL) {
            Peminjam* nextAntre = antre->next;
            free(antre);
            antre = nextAntre;
        }

        free(temp);
    }
    Head_Buku = NULL;
    printf("Seluruh list buku telah dibersihkan.\n");
}

