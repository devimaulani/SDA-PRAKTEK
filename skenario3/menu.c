#include <stdio.h>
#include <string.h>
#include "listbuku.h"
#include "antrian.h"

void tampilkanMenu() {
    printf("\n=== MENU PEMINJAMAN BUKU ===\n");
    printf("1. Tampilkan Daftar Buku\n");
    printf("2. Tambah Peminjam\n");
    printf("3. Tampilkan Antrian\n");
    printf("4. Proses Peminjaman\n");
    printf("5. Kembalikan Buku\n");
    printf("0. Keluar\n");
    printf("Pilih: ");
}

void prosesMenu() {
    int pilihan;
    char nama[100], kategori[20], judul[100];

    do {
        tampilkanMenu();
        scanf("%d", &pilihan); getchar();

        switch(pilihan) {
            case 1:
                tampilkanDaftarBuku();
                break;
            case 2:
                printf("Nama: "); fgets(nama, sizeof(nama), stdin);
                nama[strcspn(nama, "\n")] = 0;

                printf("Kategori (Dosen/Mahasiswa/Masyarakat): "); fgets(kategori, sizeof(kategori), stdin);
                kategori[strcspn(kategori, "\n")] = 0;

                printf("Judul Buku: "); fgets(judul, sizeof(judul), stdin);
                judul[strcspn(judul, "\n")] = 0;

                if (cariBuku(judul)) {
                    tambahPeminjam(nama, kategori, judul);
                } else {
                    printf("? Buku \"%s\" tidak ditemukan!\n", judul);
                }
                break;
            case 3:
                tampilkanAntrian();
                break;
            case 4:
                prosesPeminjaman();
                break;
            case 5:
			    printf("Judul Buku yang Dikembalikan: "); 
			    fgets(judul, sizeof(judul), stdin);
			    judul[strcspn(judul, "\n")] = 0;
			
			    if (kembalikanBuku(judul)) {
			        printf("? Buku \"%s\" berhasil dikembalikan.\n", judul);
			    } else {
			        printf("? Buku \"%s\" tidak ditemukan dalam daftar.\n", judul);
			    }
			    break;
            case 0:
                hapusSemuaAntrian();
                printf("Terima kasih!\n");
                break;
            default:
                printf("Pilihan tidak valid.\n");
        }

    } while (pilihan != 0);
}

