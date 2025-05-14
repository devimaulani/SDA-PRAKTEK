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
#include "listbuku.h"
#include "peminjam.h"
#include "antreanorang.h" // Gunakan header yang sesuai
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
        getchar(); // bersihkan newline

        switch (pilihan) {
            case 1:
                printf("Judul buku: ");
                fgets(judul, sizeof(judul), stdin);
                judul[strcspn(judul, "\n")] = 0; // hapus newline

                printf("Stok buku: ");
                scanf("%d", &stok);
                getchar();

                insertBuku(judul, stok);
                printf("Buku berhasil ditambahkan.\n");
                break;

            case 2:
                tampilkanSemuaBuku();
                break;

            case 3:
                // Tampilkan daftar buku terlebih dahulu
                printf("\nDaftar Buku yang Tersedia:\n");
                printf("--------------------------\n");
                tampilkanSemuaBuku();
                printf("--------------------------\n");
                
                printf("Nama peminjam: ");
                fgets(nama, sizeof(nama), stdin);
                nama[strcspn(nama, "\n")] = 0;

                printf("Tipe peminjam (1.Dosen, 2.Mahasiswa, 3.Masyarakat): ");
                scanf("%d", &tipe);
                getchar();

                printf("Judul buku yang ingin dipinjam: ");
                fgets(judul, sizeof(judul), stdin);
                judul[strcspn(judul, "\n")] = 0;

                
                // Pencarian buku dengan perbandingan case-insensitive
                buku = NULL;
                Buku* current = Head_Buku;
                while (current != NULL) {
                    // Untuk Windows, gunakan _stricmp
                    #ifdef _WIN32
                    if (_stricmp(current->judul, judul) == 0) {
                        buku = current;
                        break;
                    }
                    #else
                    // Untuk Unix-like sistem
                    if (strcasecmp(current->judul, judul) == 0) {
                        buku = current;
                        break;
                    }
                    #endif
                    
                    // Coba juga dengan strcmp biasa
                    if (strcmp(current->judul, judul) == 0) {
                        buku = current;
                        break;
                    }
                    
                    current = current->next;
                }
                
                if (buku == NULL) {
                    printf("Buku tidak ditemukan.\n");
                    
                    // Debug: Cek semua buku yang ada di daftar untuk bandingkan judul
                    printf("\nMemeriksa semua buku yang ada:\n");
                    current = Head_Buku;
                    while (current != NULL) {
                        printf("Buku di daftar: '%s' (strcmp result: %d)\n", 
                               current->judul, 
                               strcmp(current->judul, judul));
                        current = current->next;
                    }
                } else if (buku->stok <= 0) {
                    printf("Maaf, stok buku '%s' habis.\n", buku->judul);
                    
                    // Buat antrean baru jika belum ada
                    AntreanOrang *nodeAntrean = temukanAntreanDariBuku(buku);
                    if (nodeAntrean == NULL) {
                        nodeAntrean = buatNodeAntrean();
                        
                        // Buat peminjam baru
                        peminjamBaru = buatPeminjam(nama, tipe, buku);
                        nodeAntrean->antrean = peminjamBaru;
                        
                        tambahAntrean(nodeAntrean);
                        printf("Peminjam ditambahkan ke antrean baru untuk buku '%s'.\n", buku->judul);
                    } else {
                        // Sudah ada antrean untuk buku ini
                        peminjamBaru = buatPeminjam(nama, tipe, buku);
                        tambahPeminjamBerdasarkanPrioritas(&(nodeAntrean->antrean), peminjamBaru);
                        printf("Peminjam ditambahkan ke antrean yang sudah ada untuk buku '%s'.\n", buku->judul);
                    }
                } else {
                    // Ada stok buku, bisa langsung dipinjam
                    buku->stok--;
                    printf("Buku '%s' berhasil dipinjam oleh %s.\n", buku->judul, nama);
                }
                break;

            case 4:
                printf("\n--- Antrean Peminjam ---\n");
                if (antreanKosong()) {
                    printf("Tidak ada antrean peminjam.\n");
                } else {
                    AntreanOrang *curr = DaftarAntrean;
                    while (curr != NULL) {
                        if (curr->antrean != NULL) {
                            printf("Buku: %s\n", curr->antrean->buku->judul);
                            tampilkanAntreanPeminjam(curr->antrean);
                        }
                        curr = curr->next;
                    }
                }
                break;

            case 5:
                printf("Keluar dari program.\n");
                break;

            default:
                printf("Pilihan tidak valid.\n");
        }

    } while (pilihan != 5);
}



