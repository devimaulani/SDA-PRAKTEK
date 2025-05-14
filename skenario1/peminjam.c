/*Author: Devi Maulnai 
NIM: 241524007
Kelas: 1A
Prodi: Sarjana Terapan Teknik Informatika
Jurusan: Teknik Komputer dan Informatika
Politeknik Negeri Bandung
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "peminjam.h"


Peminjam *buatPeminjam(char *nama, TipePeminjam tipe, Buku *buku) {
    Peminjam *baru = (Peminjam *)malloc(sizeof(Peminjam));
    strcpy(baru->nama, nama);
    baru->tipe = tipe;
    baru->buku = buku;
    baru->next = NULL;
    return baru;
}

void tambahPeminjamBerdasarkanPrioritas(Peminjam **head, Peminjam *baru) {
    if (*head == NULL || baru->tipe < (*head)->tipe) {
        baru->next = *head;
        *head = baru;
    } else {
        Peminjam *curr = *head;
        while (curr->next != NULL && curr->next->tipe <= baru->tipe) {
            curr = curr->next;
        }
        baru->next = curr->next;
        curr->next = baru;
    }
}

void tampilkanAntreanPeminjam(Peminjam *head) {
    printf("Daftar antrean:\n");
    while (head != NULL) {
        printf("Nama: %s | Tipe: ", head->nama);
        switch (head->tipe) {
            case DOSEN: printf("Dosen"); break;
            case MAHASISWA: printf("Mahasiswa"); break;
            case MASYARAKAT: printf("Masyarakat"); break;
        }
        printf(" | Judul Buku: %s\n", head->buku->judul);
        head = head->next;
    }
}

void hapusSemuaPeminjam(Peminjam **head) {
    while (*head != NULL) {
        Peminjam *hapus = *head;
        *head = (*head)->next;
        free(hapus);
    }
}
