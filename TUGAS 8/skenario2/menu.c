#include <stdio.h>
#include <stdlib.h>
#include "listbuku.h"
#include "peminjam.h"
#include "menu.h"
#include <string.h>

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
        printf("5. Pengembalian Buku\n");
        printf("6. Keluar\n");
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
                tampilkanSemuaBuku();
                break;

            case 3:
            	 // Tampilkan daftar buku terlebih dahulu
                printf("\nDaftar Buku yang Tersedia:\n");
                printf("--------------------------\n");
                tampilkanSemuaBuku();
                printf("--------------------------\n");
            	
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

                    // Cek stok buku
                    if (buku->stok > 0) {
                        // Ada stok, langsung pinjamkan buku
                        buku->stok--;
                        printf("Buku \"%s\" berhasil dipinjam oleh %s.\n", buku->judul, nama);
                        printf("Stok tersisa: %d\n", buku->stok);
                        // Peminjam tidak perlu dimasukkan ke antrean, tapi perlu dibebaskan
                        free(peminjamBaru);
                    } else {
                        // Tidak ada stok, masukkan ke antrean
                        tambahPeminjamBerdasarkanPrioritas(&buku->antrean, peminjamBaru);
                        printf("Stok habis. %s ditambahkan ke antrean peminjam buku \"%s\".\n", nama, buku->judul);
                    }
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
                // Pengembalian Buku
                printf("\n--- Pengembalian Buku ---\n");
                char judulKembali[50];
                printf("Masukkan judul buku yang dikembalikan: ");
                fgets(judulKembali, sizeof(judulKembali), stdin);
                judulKembali[strcspn(judulKembali, "\n")] = 0;

                buku = cariBuku(judulKembali);
                if (buku == NULL) {
                    printf("Buku tidak ditemukan.\n");
                } else {
                    // Kembalikan buku (tambah stok)
                    buku->stok++;
                    printf("Buku \"%s\" berhasil dikembalikan. Stok sekarang: %d\n", buku->judul, buku->stok);
                    
                    // Cek apakah ada antrean peminjam
                    if (buku->antrean != NULL) {
                        Peminjam* peminjamBerikutnya = buku->antrean;
                        buku->antrean = buku->antrean->next;
                        
                        printf("Memberikan buku kepada peminjam berikutnya dalam antrean: %s\n", peminjamBerikutnya->nama);
                        buku->stok--; // Kurangi stok karena langsung dipinjamkan
                        
                        free(peminjamBerikutnya); // Bebaskan memori peminjam
                        printf("Stok tersisa: %d\n", buku->stok);
                    }
                }
                break;

            case 6:
                // Keluar dari program
                printf("Keluar dari program.\n");
                bersihkanListBuku(); // Membersihkan memory sebelum keluar
                break;

            default:
                printf("Pilihan tidak valid.\n");
        }

    } while (pilihan != 6);
}

