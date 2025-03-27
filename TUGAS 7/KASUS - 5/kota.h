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
#include "boolean.h"

#define MAX_KOTA 5
#define PANJANG_NAMA 50

// Struktur untuk elemen array kota
typedef struct {
    char kt[PANJANG_NAMA];  // nama kota
    address p;              // pointer ke daftar nama
} ElemenKota;

// Tipe data untuk kontainer kota
typedef struct {
    ElemenKota data[MAX_KOTA];
    int jumlahKota;
} DaftarKota;

// Prototype fungsi
void inisialisasiDaftarKota(DaftarKota *daftarKota);
boolean tambahKota(DaftarKota *daftarKota, char* namaKota);
boolean tambahNamaKeKota(DaftarKota *daftarKota, char* namaKota, infotype nama);
void tampilkanNamaKota(DaftarKota *daftarKota, char* namaKota);
void hapusSemuaNamaKota(DaftarKota *daftarKota, char* namaKota);
int hitungNamaKota(DaftarKota *daftarKota, char* namaKota);
void tampilkanInfoTotal(DaftarKota *daftarKota);

// Fungsi tambahan untuk menu
void menuUtama(DaftarKota *daftarKota);

#endif // KOTA_NAMA_H
