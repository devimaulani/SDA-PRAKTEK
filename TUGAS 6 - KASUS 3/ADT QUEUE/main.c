/*Author: Devi Maulnai 
NIM: 241524007
Kelas: 1A
Prodi: Sarjana Terapan Teknik Informatika
Jurusan: Teknik Komputer dan Informatika
Politeknik Negeri Bandung
*/


#include <stdio.h>
#include "queue.h"

int main() {
    Queue Q;
    infotype X;
    int pilihan;

    CreateQueue(&Q);

    do {
        printf("\nMenu:\n");
        printf("1. Tambah Antrian (EnQueue)\n");
        printf("2. Hapus Antrian (DeQueue)\n");
        printf("3. Tampilkan Antrian\n");
        printf("4. Cek Apakah Queue Penuh\n");
        printf("5. Keluar\n");
        printf("Pilih menu: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                if (!is_Full(Q)) {
                    printf("Masukkan nilai: ");
                    scanf("%d", &X);
                    EnQueue(&Q, X);
                } else {
                    printf("Queue sudah penuh!\n");
                }
                break;
            case 2:
                deQueue(&Q, &X);
                printf("Elemen yang dihapus: %d\n", X);
                break;
            case 3:
                TampilQueue(Q);
                break;
            case 4:
                if (is_Full(Q)) {
                    printf("Queue penuh!\n");
                } else {
                    printf("Queue masih memiliki ruang kosong.\n");
                }
                break;
            case 5:
                printf("Keluar dari program.\n");
                break;
            default:
                printf("Pilihan tidak valid!\n");
        }
    } while (pilihan != 5);

    return 0;
}

