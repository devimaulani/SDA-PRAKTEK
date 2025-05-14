/*Author: Devi Maulnai 
NIM: 241524007
Kelas: 1A
Prodi: Sarjana Terapan Teknik Informatika
Jurusan: Teknik Komputer dan Informatika
Politeknik Negeri Bandung
*/


#ifndef PEMINJAM_H
#define PEMINJAM_H

#include "listbuku.h"  // Agar bisa refer ke struct Buku

// Enum untuk tipe peminjam
typedef enum {
    DOSEN = 1,
    MAHASISWA = 2,
    MASYARAKAT = 3
} TipePeminjam;

// Struktur data untuk peminjam
typedef struct Peminjam {
    char nama[50];
    TipePeminjam tipe;
    struct Buku *buku;             // Buku yang ingin dipinjam
    struct Peminjam *next;         // Untuk antrean
} Peminjam;

// Fungsi-fungsi manajemen peminjam
Peminjam *buatPeminjam(char *nama, TipePeminjam tipe, Buku *buku);
void tambahPeminjamBerdasarkanPrioritas(Peminjam **head, Peminjam *baru);
void tampilkanAntreanPeminjam(Peminjam *head);
void hapusSemuaPeminjam(Peminjam **head);

#endif
