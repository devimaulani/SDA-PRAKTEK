#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "peminjam.h"



// Membuat peminjam baru
Peminjam *buatPeminjam(char *nama, TipePeminjam tipe) {
    Peminjam *baru = (Peminjam *)malloc(sizeof(Peminjam));
    if (baru == NULL) {
        printf("Gagal mengalokasikan memori untuk peminjam.\n");
        exit(1);
    }
    strcpy(baru->nama, nama);
    baru->tipe = tipe;
    baru->next = NULL;
    return baru;
}

// Menambahkan peminjam ke antrean berdasarkan prioritas
void tambahPeminjamBerdasarkanPrioritas(Peminjam **head, Peminjam *baru) {
    if (*head == NULL || baru->tipe < (*head)->tipe) {
        // Jika antrean kosong atau prioritas lebih tinggi
        baru->next = *head;
        *head = baru;
    } else {
        Peminjam *current = *head;
        while (current->next != NULL && current->next->tipe <= baru->tipe) {
            current = current->next;
        }
        baru->next = current->next;
        current->next = baru;
    }
}

// Menampilkan seluruh antrean peminjam
void tampilkanAntreanPeminjam(Peminjam *head) {
    printf("Daftar Antrean Peminjam:\n");
    if (head == NULL) {
        printf("- (Kosong)\n");
        return;
    }
    int i = 1;
    while (head != NULL) {
        printf("%d. %s (%s)\n", i++, head->nama,
               head->tipe == DOSEN ? "Dosen" :
               head->tipe == MAHASISWA ? "Mahasiswa" : "Masyarakat");
        head = head->next;
    }
}

// Menghapus semua antrean peminjam
void hapusSemuaPeminjam(Peminjam **head) {
    while (*head != NULL) {
        Peminjam *temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

