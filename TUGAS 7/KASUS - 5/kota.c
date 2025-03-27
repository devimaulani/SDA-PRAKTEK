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
#include "kota.h"

// Inisialisasi daftar kota
void inisialisasiDaftarKota(DaftarKota *daftarKota) {
	int i = 0;
	
    daftarKota->jumlahKota = 0;
    for ( i < MAX_KOTA; i++; ) {
        daftarKota->data[i].p = NULL;
        
    }
}

// Tambah kota baru
boolean tambahKota(DaftarKota *daftarKota, char* namaKota) {
    if (daftarKota->jumlahKota >= MAX_KOTA) {
        printf("Jumlah kota sudah mencapai batas maksimum!\n");
        return false;
    }
    
    // Cek apakah kota sudah ada
    int i = 0;
    for ( i < daftarKota->jumlahKota; i++;) {
        if (strcmp(daftarKota->data[i].kt, namaKota) == 0) {
            printf("Kota sudah ada!\n");
            return false;
        }
    }
    
    // Tambah kota baru
    strcpy(daftarKota->data[daftarKota->jumlahKota].kt, namaKota);
    daftarKota->data[daftarKota->jumlahKota].p = NULL;
    daftarKota->jumlahKota++;
    return true;
}

// Tambah nama ke kota tertentu
boolean tambahNamaKeKota(DaftarKota *daftarKota, char* namaKota, infotype nama) {
	int i = 0;
    for ( i < daftarKota->jumlahKota; i++;) {
        if (strcmp(daftarKota->data[i].kt, namaKota) == 0) {
            // Buat node baru
            address nodeBaruNama;
            Create_Node(&nodeBaruNama);
            Isi_Node(&nodeBaruNama, nama);
            
            // Tambahkan ke linked list nama kota
            Ins_Akhir(&daftarKota->data[i].p, nodeBaruNama);
            return true;
        }
    }
    
    printf("Kota tidak ditemukan!\n");
    return false;
}

// Tampilkan nama-nama dalam satu kota
void tampilkanNamaKota(DaftarKota *daftarKota, char* namaKota) {
	int i = 0;
    for ( i < daftarKota->jumlahKota; i++;) {
        if (strcmp(daftarKota->data[i].kt, namaKota) == 0) {
            printf("Daftar nama di kota %s:\n", namaKota);
            Tampil_List(daftarKota->data[i].p);
            return;
        }
    }
    printf("Kota tidak ditemukan!\n");
}

// Hapus semua nama dalam satu kota
void hapusSemuaNamaKota(DaftarKota *daftarKota, char* namaKota) {
	int i = 0;
    for ( i < daftarKota->jumlahKota; i++;) {
        if (strcmp(daftarKota->data[i].kt, namaKota) == 0) {
            // Hapus seluruh linked list nama
            while (daftarKota->data[i].p != NULL) {
                infotype namaDihapus;
                Del_Awal(&daftarKota->data[i].p, &namaDihapus);
            }
            printf("Semua nama di kota %s telah dihapus\n", namaKota);
            return;
        }
    }
    printf("Kota tidak ditemukan!\n");
}

// Hitung total nama dalam satu kota
int hitungNamaKota(DaftarKota *daftarKota, char* namaKota) {
	int i = 0; 
    for (i < daftarKota->jumlahKota; i++;) {
        if (strcmp(daftarKota->data[i].kt, namaKota) == 0) {
            return NbElmt(daftarKota->data[i].p);
        }
    }
    return 0;
}

// Tampilkan informasi total
void tampilkanInfoTotal(DaftarKota *daftarKota) {
    int totalNama = 0;
    
    printf("Informasi Total:\n");
    printf("Jumlah Kota: %d\n", daftarKota->jumlahKota);
    
    int i = 0;
    for ( i < daftarKota->jumlahKota; i++;) {
        int jumlahNamaKota = NbElmt(daftarKota->data[i].p);
        totalNama += jumlahNamaKota;
        printf("Kota %s: %d nama\n", daftarKota->data[i].kt, jumlahNamaKota);
    }
    
    printf("Total Nama: %d\n", totalNama);
}

// Menu utama
void menuUtama(DaftarKota *daftarKota) {
    int pilihan;
    char namaKota[PANJANG_NAMA];
    infotype nama;

    do {
        printf("\n--- PROGRAM MANAJEMEN DATA KOTA ---\n");
        printf("1. Tambah Kota\n");
        printf("2. Tambah Nama ke Kota\n");
        printf("3. Tampilkan Nama Kota\n");
        printf("4. Hapus Semua Nama di Kota\n");
        printf("5. Tampilkan Info Total\n");
        printf("6. Keluar\n");
        printf("Pilih menu (1-6): ");
        scanf("%d", &pilihan);

        switch(pilihan) {
            case 1:
                printf("Masukkan nama kota: ");
                scanf("%s", namaKota);
                tambahKota(daftarKota, namaKota);
                break;
            case 2:
                printf("Masukkan nama kota: ");
                scanf("%s", namaKota);
                printf("Masukkan nama (dalam bilangan): ");
                scanf("%d", &nama);
                tambahNamaKeKota(daftarKota, namaKota, nama);
                break;
            case 3:
                printf("Masukkan nama kota: ");
                scanf("%s", namaKota);
                tampilkanNamaKota(daftarKota, namaKota);
                break;
            case 4:
                printf("Masukkan nama kota: ");
                scanf("%s", namaKota);
                hapusSemuaNamaKota(daftarKota, namaKota);
                break;
            case 5:
                tampilkanInfoTotal(daftarKota);
                break;
            case 6:
                printf("Terima kasih!\n");
                break;
            default:
                printf("Pilihan tidak valid!\n");
        }
    } while (pilihan != 6);
}
