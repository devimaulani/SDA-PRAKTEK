#include <stdio.h>
#include <stdlib.h>
#include "listbuku.h"
#include "peminjam.h"
#include "menu.h"

void tampilkanMenu() {
    int pilihan;
    char judul[50], nama[50];
    int stok, tipe;
    Buku *buku;
    Peminjam *peminjamBaru;

    do {
        printf("\n=== MENU PERPUSTAKAAN ===\n");
        printf("1. Tambah Buku\n");
        printf("2. Tampilkan Daftar Buku\n");
        printf("3. Tambah Peminjam\n");
        printf("4. Tampilkan Antrean Peminjam\n");
        printf("5. Keluar\n");
        printf("Pilih menu: ");
        scanf("%d", &pilihan);
        getchar(); // Bersihkan newline

        switch (pilihan) {
            case 1:
                // Tambah Buku
                printf("Judul buku: ");
                fgets(judul, sizeof(judul), stdin);
                judul[strcspn(judul, "\n")] = 0; // Hapus newline

                printf("Stok buku: ");
                scanf("%d", &stok);
                getchar(); // Bersihkan newline

                insertBuku(judul, stok);
                printf("Buku berhasil ditambahkan.\n");
                break;

            case 2:
                // Tampilkan Daftar Buku
                tampilkanSemuaBuku(Head_Buku);
                break;

            case 3:
                // Tambah Peminjam
                printf("Nama peminjam: ");
                fgets(nama, sizeof(nama), stdin);
                nama[strcspn(nama, "\n")] = 0;

                printf("Tipe peminjam (1.Dosen, 2.Mahasiswa, 3.Masyarakat): ");
                scanf("%d", &tipe);
                getchar(); // Bersihkan newline

                printf("Judul buku yang ingin dipinjam: ");
                fgets(judul, sizeof(judul), stdin);
                judul[strcspn(judul, "\n")] = 0;

                buku = cariBuku(judul);
                if (buku == NULL) {
                    printf("Buku tidak ditemukan.\n");
                } else {
                    peminjamBaru = buatPeminjam(nama, tipe);

                    // Tambahkan peminjam ke antrean berdasarkan prioritas
                    tambahPeminjamBerdasarkanPrioritas(&buku->antrean, peminjamBaru);
                    printf("Peminjam berhasil ditambahkan ke antrean buku \"%s\".\n", buku->judul);
                }
                break;

            case 4:
                // Tampilkan Antrean Peminjam
                printf("\n--- Antrean Peminjam ---\n");
                char judulBuku[50];
                printf("Masukkan judul buku untuk melihat antrean peminjam: ");
                fgets(judulBuku, sizeof(judulBuku), stdin);
                judulBuku[strcspn(judulBuku, "\n")] = 0;

                buku = cariBuku(judulBuku);
                if (buku == NULL) {
                    printf("Buku tidak ditemukan.\n");
                } else {
                    tampilkanAntreanPeminjam(buku->antrean);
                }
                break;

            case 5:
                // Keluar dari program
                printf("Keluar dari program.\n");
                break;

            default:
                printf("Pilihan tidak valid.\n");
        }

    } while (pilihan != 5);
}

