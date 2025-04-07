 /*Author: Devi Maulnai 
NIM: 241524007
Kelas: 1A
Prodi: Sarjana Terapan Teknik Informatika
Jurusan: Teknik Komputer dan Informatika
Politeknik Negeri Bandung
*/ 
#include "menu.h"

void tampilkanMenu(KotaAddress *daftarKota) {
    int pilihan;
    char namaKota[50], namaOrang[50];
    do {
        printf("\n==== MENU MANAJEMEN KOTA DAN PENDUDUK ====\n");
        printf("1. Tambah Kota\n");
        printf("2. Tambah Nama ke Kota\n");
        printf("3. Hapus Kota\n");
        printf("4. Hapus Nama dari Kota\n");
        printf("5. Tampilkan Semua Kota\n");
        printf("6. Hitung Data\n");
        printf("7. Cari Nama per Kota\n");  // Menambahkan opsi baru
        printf("0. Keluar\n");
        printf("Pilihan: ");
        scanf("%d", &pilihan);
        getchar(); // Menghindari newline dari input sebelumnya
        
        switch (pilihan) {
            case 1:
                printf("Nama Kota: ");
                fgets(namaKota, 50, stdin);
                namaKota[strcspn(namaKota, "\n")] = 0; // Alternatif untuk strtok
                tambahKota(daftarKota, namaKota);
                break;
            case 2:
                printf("Nama Kota: ");
                fgets(namaKota, 50, stdin);
                namaKota[strcspn(namaKota, "\n")] = 0;
                printf("Nama: ");
                fgets(namaOrang, 50, stdin);
                namaOrang[strcspn(namaOrang, "\n")] = 0;
                tambahNama(*daftarKota, namaKota, namaOrang);
                break;
            case 3:
                printf("Nama Kota: ");
                fgets(namaKota, 50, stdin);
                namaKota[strcspn(namaKota, "\n")] = 0;
                hapusKota(daftarKota, namaKota);
                break;
            case 4:
                printf("Nama Kota: ");
                fgets(namaKota, 50, stdin);
                namaKota[strcspn(namaKota, "\n")] = 0;
                printf("Nama: ");
                fgets(namaOrang, 50, stdin);
                namaOrang[strcspn(namaOrang, "\n")] = 0;
                hapusNama(*daftarKota, namaKota, namaOrang);
                break;
            case 5:
                tampilkanKota(*daftarKota);
                break;
            case 6:
                hitungData(*daftarKota);
                break;
            case 7:
                printf("Nama Kota: ");
                fgets(namaKota, 50, stdin);
                namaKota[strcspn(namaKota, "\n")] = 0;
                cariNamaPerKota(*daftarKota, namaKota);
                break;
            case 0:
                printf("Terima kasih telah menggunakan program!\n");
                break;
            default:
                printf("Pilihan tidak valid. Silakan coba lagi.\n");
        }
    } while (pilihan != 0);
}
