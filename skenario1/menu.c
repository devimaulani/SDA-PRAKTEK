/*Author: Devi Maulnai 
NIM: 241524007
Kelas: 1A
Prodi: Sarjana Terapan Teknik Informatika
Jurusan: Teknik Komputer dan Informatika
Politeknik Negeri Bandung
*/


#include <stdio.h>
#include <stdlib.h>
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
                printf("Nama peminjam: ");
                fgets(nama, sizeof(nama), stdin);
                nama[strcspn(nama, "\n")] = 0;

                printf("Tipe peminjam (1.Dosen, 2.Mahasiswa, 3.Masyarakat): ");
                scanf("%d", &tipe);
                getchar();

                printf("Judul buku yang ingin dipinjam: ");
                fgets(judul, sizeof(judul), stdin);
                judul[strcspn(judul, "\n")] = 0;

                buku = cariBuku(judul);
                if (buku == NULL) {
                    printf("Buku tidak ditemukan.\n");
                } else {
                    peminjamBaru = buatPeminjam(nama, tipe, buku);

                    // Temukan antrean yang ada berdasarkan buku
                    AntreanOrang *antrean = temukanAntreanDariBuku(buku);
                    if (antrean == NULL) {
                        // Jika antrean tidak ada, buat antrean baru
                        antrean = aksesAntreanKosongAtauAda(buku);
                    }

                    // Tambahkan peminjam ke antrean berdasarkan prioritas
                    tambahAntrean(antrean);
                    printf("Peminjam berhasil ditambahkan ke antrean.\n");
                }
                break;

            case 4:
                printf("\n--- Antrean Peminjam ---\n");
                AntreanOrang *curr = DaftarAntrean;
                while (curr != NULL) {
                    // Tampilkan antrean untuk setiap buku
                    printf("Buku: %s\n", curr->antrean->buku->judul); // Asumsi antrean menyimpan pointer ke buku
                    tampilkanAntreanPeminjam(curr->antrean);
                    curr = curr->next;
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
