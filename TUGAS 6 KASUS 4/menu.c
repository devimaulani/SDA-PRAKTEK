/*Author: Devi Maulnai 
NIM: 241524007
Kelas: 1A
Prodi: Sarjana Terapan Teknik Informatika
Jurusan: Teknik Komputer dan Informatika
Politeknik Negeri Bandung
*/


#include <stdio.h>
#include "gudang.h"
#include "menu.h"


// Deklarasi struktur data
extern Queue antrianPengiriman;
extern Stack riwayatPengiriman;

// Fungsi Menu Gudang (Linked List)
void menuGudang() {
    int pilihan;
    do {
    	
        printf("\n==== MENU GUDANG (Linked List) ====\n");
        printf("1. Tambah Barang ke Gudang\n");
        printf("2. Hapus Barang dari Gudang\n");
        printf("3. Lihat Stok Barang di Gudang\n");
        printf("0. Kembali ke Menu Utama\n");
        printf("===================================\n");
        printf("Pilih menu: ");
        scanf("%d", &pilihan);
        while (getchar() != '\n'); 
        
        switch (pilihan) {
            case 1: 
				tambahBarangGudang(); 
				break;	
            case 2: 
				hapusBarangGudang(); 
				break;
            case 3: 
				lihatStokGudang(); 
				break;
            case 0: 
				printf("Kembali ke Menu Utama.\n"); 
				system ("cls");
				break;
            default: 
				printf("Pilihan tidak valid! Silakan coba lagi.\n");
        }
    } while (pilihan != 0);
}

// Fungsi Menu Antrian Pengiriman (Queue)
void menuQueue() {
    int pilihan;
    do {
    	
        printf("\n==== MENU ANTRIAN PENGIRIMAN (Queue) ====\n");
        printf("1. Tambah Barang ke Antrian Pengiriman\n");
        printf("2. Kirim Barang dari Antrian\n");
        printf("3. Lihat Antrian Pengiriman\n");
        printf("0. Kembali ke Menu Utama\n");
        printf("=========================================\n");
        printf("Pilih menu: ");
        scanf("%d", &pilihan);
        while (getchar() != '\n'); //agar membersihkan buffer input 

        switch (pilihan) {
            case 1: 
				tambahKeAntrianPengiriman(); 
				break;
            case 2: 
				kirimBarang(); 
				break;
            case 3: 
				lihatAntrianPengiriman(); 
				break;
            case 0: 
				printf("Kembali ke Menu Utama.\n"); 
				system ("cls");
				break;
            default: 
				printf("Pilihan tidak valid! Silakan coba lagi.\n");
        }
    } while (pilihan != 0);
}

// Fungsi Menu Riwayat Pengiriman (Stack)
void menuStack() {
    int pilihan;
    do {
    	
        printf("\n==== MENU RIWAYAT PENGIRIMAN (Stack) ====\n");
        printf("1. Lihat Riwayat Barang yang Sudah Dikirim\n");
        printf("0. Kembali ke Menu Utama\n");
        printf("=========================================\n");
        printf("Pilih menu: ");
        scanf("%d", &pilihan);
        while (getchar() != '\n'); 
        
        switch (pilihan) {
            case 1: 
				lihatRiwayatPengiriman(); 
				break;
            case 0: 
				printf("Kembali ke Menu Utama.\n"); 
				system ("cls");
				break;
            default: 
				printf("Pilihan tidak valid! Silakan coba lagi.\n");
        }
    } while (pilihan != 0);
}

