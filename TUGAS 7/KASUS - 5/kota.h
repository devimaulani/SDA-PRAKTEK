/*Author: Devi Maulnai 
NIM: 241524007
Kelas: 1A
Prodi: Sarjana Terapan Teknik Informatika
Jurusan: Teknik Komputer dan Informatika
Politeknik Negeri Bandung
*/

#ifndef KOTA_H
#define KOTA_H

#include "linked.h"

#define MAX_KOTA 100

typedef struct {
    char kt[50];  // Nama kota
    address p;    // Pointer ke linked list nama-nama di kota ini
} Kota;

void TambahKota(Kota A[], int *jumlahKota, char *kota);
void TambahNama(Kota A[], int jumlahKota, char *nama, char *kota);
void HapusKota(Kota A[], int *jumlahKota, char *kota);
void Tampilkan(Kota A[], int jumlahKota);
void TampilkanPerKota(Kota A[], int jumlahKota, char *kota);

#endif


