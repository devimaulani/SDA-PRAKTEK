#ifndef PEMINJAM_H
#define PEMINJAM_H

// Enum tipe peminjam
typedef enum {
    DOSEN = 1,
    MAHASISWA = 2,
    MASYARAKAT = 3
} TipePeminjam;

// Struktur data untuk peminjam
typedef struct Peminjam {
    char nama[50];
    TipePeminjam tipe;
    struct Peminjam *next;  // Untuk antrean
} Peminjam;

// Fungsi-fungsi manajemen peminjam
Peminjam *buatPeminjam(char *nama, TipePeminjam tipe);
void tambahPeminjamBerdasarkanPrioritas(Peminjam **head, Peminjam *baru);
void tampilkanAntreanPeminjam(Peminjam *head);
void hapusSemuaPeminjam(Peminjam **head);

#endif

