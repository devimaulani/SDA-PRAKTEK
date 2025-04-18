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

typedef struct tKota *KotaAddress;
typedef struct tKota {
    infotype namaKota;
    List daftarNama; // Single Linked List untuk menyimpan nama orang
    KotaAddress next, prev;
} Kota;

void tambahKota(KotaAddress *head, infotype namaKota);
void hapusSemuaNama(List *daftarNama);                    //fungsi tambahan 
void hapusKota(KotaAddress *head, infotype namaKota);
void tambahNama(KotaAddress head, infotype namaKota, infotype namaOrang);
void hapusNama(KotaAddress head, infotype namaKota, infotype namaOrang);
void tampilkanKota(KotaAddress head);
void hitungData(KotaAddress head);
void cariNamaPerKota(KotaAddress head, infotype namaKota); //fungsi tambahan 

#endif
