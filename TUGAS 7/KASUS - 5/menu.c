#include "menu.h"
#include <stdio.h>


void TampilkanMenu() {
    printf("\n=== Menu ===\n");
    printf("1. Tambah Kota\n");
    printf("2. Tambah Nama\n");
    printf("3. Hapus Kota\n");
    printf("4. Tampilkan Semua Data\n");
    printf("5. Tampilkan Data Kota\n");
    printf("6. Keluar\n");
}

void prosesMenu(Kota A[], int *jumlahKota) {
    int pilihan;
    char nama[50], kota[50];

    do {
        TampilkanMenu();
        printf("Pilih menu: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                printf("Masukkan nama kota: ");
                scanf("%s", kota);
                TambahKota(A, jumlahKota, kota);
                break;
            case 2:
                printf("Masukkan nama: ");
                scanf("%s", nama);
                printf("Masukkan kota: ");
                scanf("%s", kota);
                TambahNama(A, *jumlahKota, nama, kota);
                break;
            case 3:
                printf("Masukkan nama kota yang ingin dihapus: ");
                scanf("%s", kota);
                HapusKota(A, jumlahKota, kota);
                break;
            case 4:
                Tampilkan(A, *jumlahKota);
                break;
            case 5:
                printf("Masukkan kota yang ingin ditampilkan: ");
                scanf("%s", kota);
                TampilkanPerKota(A, *jumlahKota, kota);
                break;
            case 6:
                printf("Keluar dari program...\n");
                break;
            default:
                printf("Pilihan tidak valid!\n");
        }
    } while (pilihan != 6);
}

