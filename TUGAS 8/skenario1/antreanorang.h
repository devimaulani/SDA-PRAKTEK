/*Author: Devi Maulnai 
NIM: 241524007
Kelas: 1A
Prodi: Sarjana Terapan Teknik Informatika
Jurusan: Teknik Komputer dan Informatika
Politeknik Negeri Bandung
*/

#ifndef ANTREANORANG_H
#define ANTREANORANG_H

#include "peminjam.h"

typedef struct AntreanOrang {
    struct Peminjam *antrean;
    struct AntreanOrang *next;
} AntreanOrang;

extern AntreanOrang *DaftarAntrean;

// Fungsi-fungsi
int antreanKosong();
AntreanOrang *buatNodeAntrean();
void tambahAntrean(AntreanOrang *nodeBaru);
AntreanOrang *temukanAntreanDariBuku(Buku *buku);
AntreanOrang *aksesAntreanKosongAtauAda(Buku *buku);
void hapusSemuaAntrean();

#endif
