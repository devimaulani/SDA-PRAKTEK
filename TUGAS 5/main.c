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
#include "linked.h"

int main()  {
    List L1, L2;  // List utama dan list hasil salinan
    CreateList(&L1);
    CreateList(&L2);

    int pilihan, nilai;
    char nama[50];

    do {
        TampilkanMenu();
        scanf("%d", &pilihan);
        getchar(); // Menghapus newline agar tidak mengganggu input berikutnya

        switch (pilihan) {
            case 1:
                printf("Masukkan Nama: ");
                fgets(nama, sizeof(nama), stdin);
                nama[strcspn(nama, "\n")] = 0; // Hapus newline dari input

                printf("Masukkan Nilai: ");
                scanf("%d", &nilai);

                InsertSortedByName(&L1, nama, nilai);
                printf("Data berhasil ditambahkan!\n");
                break;

            case 2:
                printf("\nData Mahasiswa (Ascending Nama):\n");
                PrintAscending(L1);
                break;

            case 3:
                printf("\nData Mahasiswa (Descending Nilai):\n");
                PrintDescending(L1);
                break;

            case 4:
            	DeleteList(&L2);  // Hapus L2 sebelum menyalin agar tidak terjadi duplikasi
                CopyGreaterThan70(&L1, &L2);
                printf("Mahasiswa dengan nilai > 70 disalin ke List L2.\n");
                break;

            case 5:
                RemoveDuplicates(&L1);
                printf("Nama duplikat berhasil dihapus!\n");
                break;
			
            case 6:
            	DeleteList(&L2);  // Hapus L2 sebelum menyalin agar tidak terjadi duplikasi
                CopyGreaterThan70(&L1, &L2);
				printf("\nList L2 setelah menyalin nilai > 70:\n");
				PrintAscending(L2);
				break;
			
			case 7:
				RemoveDuplicates(&L2);
			    printf("\nList L2 setelah menghapus duplikat:\n");
			    PrintAscending(L2);
			    break;
			    
			case 8:
				// Hapus semua list
			    DeleteList(&L1);
			    DeleteList(&L2);
			    printf("\nList L1 dan L2 telah dihapus.\n");
				break;
				
			case 9:
				printf ("keluar dari program .... \n");
				break;
				
            default:
                printf("Pilihan tidak valid, silakan coba lagi!\n");
        }
        
    } while (pilihan != 9);

 
    return 0;
}

