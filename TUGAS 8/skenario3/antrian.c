#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "antrian.h"
#include "listbuku.h"

static Orang *head = NULL;

int getPrioritas(char *kategori) {
    if (strcmp(kategori, "Dosen") == 0) return 1;
    if (strcmp(kategori, "Mahasiswa") == 0) return 2;
    return 3; // Masyarakat
}

void initAntrian() {
    head = NULL;
}

void tambahPeminjam(char *nama, char *kategori, char *judulBuku) {
    Orang *baru = (Orang*)malloc(sizeof(Orang));
    strcpy(baru->nama, nama);
    strcpy(baru->kategori, kategori);
    strcpy(baru->judulBuku, judulBuku);
    baru->next = NULL;

    if (head == NULL || getPrioritas(kategori) < getPrioritas(head->kategori)) {
        baru->next = head;
        head = baru;
    } else {
        Orang *curr = head;
        while (curr->next != NULL && getPrioritas(kategori) >= getPrioritas(curr->next->kategori)) {
            curr = curr->next;
        }
        baru->next = curr->next;
        curr->next = baru;
    }

    printf("??  %s (%s) masuk antrian untuk buku \"%s\"\n", nama, kategori, judulBuku);
}

void tampilkanAntrian() {
    printf("\n=== Antrian Peminjam ===\n");
    Orang *curr = head;
    int i = 1;
    while (curr != NULL) {
        printf("%d. %s (%s) - Buku: %s\n", i++, curr->nama, curr->kategori, curr->judulBuku);
        curr = curr->next;
    }
    if (head == NULL) printf("Tidak ada antrian.\n");
}

void prosesPeminjaman() {
    Orang *curr = head;
    Orang *prev = NULL;

    while (curr != NULL) {
        Buku *b = cariBuku(curr->judulBuku);
        if (b != NULL && b->stok > 0) {
            printf("\n?? %s berhasil meminjam buku \"%s\"\n", curr->nama, b->judul);
            kurangiStok(b);

            // hapus dari antrian
            if (prev == NULL) {
                head = curr->next;
                free(curr);
                curr = head;
            } else {
                prev->next = curr->next;
                free(curr);
                curr = prev->next;
            }
        } else {
            prev = curr;
            curr = curr->next;
        }
    }
}

void hapusSemuaAntrian() {
    Orang *curr = head;
    while (curr != NULL) {
        Orang *tmp = curr;
        curr = curr->next;
        free(tmp);
    }
    head = NULL;
}

