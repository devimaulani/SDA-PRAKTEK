/*Author: Devi Maulnai 
NIM: 241524007
Kelas: 1A
Prodi: Sarjana Terapan Teknik Informatika
Jurusan: Teknik Komputer dan Informatika
Politeknik Negeri Bandung
*/

#include <stdio.h>
#include <string.h>
#include "kota.h"

// Tambah kota baru (tanpa nama di dalamnya)
void TambahKota(Kota A[], int *jumlahKota, char *kota) {
    if (*jumlahKota >= MAX_KOTA) {
        printf("Kapasitas kota penuh!\n");
        return;
    }

    // Cek apakah kota sudah ada
	int i;
	for (i = 0; i < *jumlahKota; i++) {  
        if (strcmp(A[i].kt, kota) == 0) {
            printf("Kota sudah ada!\n");
            return;
        }
    }

    strcpy(A[*jumlahKota].kt, kota);
    A[*jumlahKota].p = NULL;  // Linked list awalnya kosong
    (*jumlahKota)++;
    printf("Kota %s berhasil ditambahkan.\n", kota);
}

// Tambah nama ke dalam kota tertentu
void TambahNama(Kota A[], int jumlahKota, char *nama, char *kota) {
	int i;
    for ( i=0; i < jumlahKota; i++) {
        if (strcmp(A[i].kt, kota) == 0) { 
            address PNew;
            Create_Node(&PNew);
            Isi_Node(&PNew, nama);
            Ins_Akhir(&A[i].p, PNew);
            printf("Nama %s berhasil ditambahkan ke kota %s.\n", nama, kota);
            return;
        }
    }
    printf("Kota %s tidak ditemukan.\n", kota);
}

// Hapus kota beserta semua nama di dalamnya
void HapusKota(Kota A[], int *jumlahKota, char *kota) {
	int i ;
    for ( i = 0; i < *jumlahKota; i++) {
        if (strcmp(A[i].kt, kota) == 0) {
            address current = A[i].p;
            while (current != NULL) {
                address temp = current;
                current = current->next;
                free(temp);
            }

            // Geser elemen array setelah kota yang dihapus
            int j ;
            for ( j = i; j < *jumlahKota - 1; j++) {
                A[j] = A[j + 1];
            }

            (*jumlahKota)--;
            printf("Kota %s berhasil dihapus.\n", kota);
            return;
        }
    }
    printf("Kota %s tidak ditemukan.\n", kota);
}

// Menampilkan semua data kota beserta nama-nama di dalamnya
void Tampilkan(Kota A[], int jumlahKota) {
    if (jumlahKota == 0) {
        printf("Tidak ada data kota.\n");
        return;
    }
	int i;
    for (i = 0; i < jumlahKota; i++) {
        printf("Kota: %s\n", A[i].kt);
        Tampil_List(A[i].p);
    }
}

// Menampilkan data dari kota tertentu
void TampilkanPerKota(Kota A[], int jumlahKota, char *kota) {
	int i;
	for ( i = 0; i < jumlahKota; i++) {
        if (strcmp(A[i].kt, kota) == 0) {
            printf("Kota: %s\n", A[i].kt);
            Tampil_List(A[i].p);
            return;
        }
    }
    printf("Kota %s tidak ditemukan.\n", kota);
}

