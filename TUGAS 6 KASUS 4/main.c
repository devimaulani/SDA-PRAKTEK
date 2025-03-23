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
Queue antrianPengiriman;
Stack riwayatPengiriman;

int main() {
    // Inisialisasi struktur data
    CreateQueue(&antrianPengiriman);
    initStack(&riwayatPengiriman);

    int pilihan;
    do {
        printf("\n==== SISTEM MANAJEMEN GUDANG ====\n");
        printf("1. Kelola Gudang (Linked List)\n");
        printf("2. Kelola Antrian Pengiriman (Queue)\n");
        printf("3. Lihat Riwayat Pengiriman (Stack)\n");
        printf("0. Keluar\n");
        printf("=================================\n");
        printf("Pilih menu: ");
        scanf("%d", &pilihan);
        while (getchar() != '\n'); // Bersihkan buffer input
        
        switch (pilihan) {
            case 1: 
	            system ("cls");
				menuGudang(); 
				break;
			
            case 2: 
	            system ("cls");
				menuQueue(); 
				break;
			
            case 3: 
				system ("cls");
				menuStack(); 
				break;
			
            case 0: 
				printf("Keluar dari sistem.\n"); 
				break;
				
            default: 
				printf("Pilihan tidak valid! Silakan coba lagi.\n");
        }
    } while (pilihan != 0);

    return 0;
}

