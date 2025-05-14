/*Author: Devi Maulnai 
NIM: 241524007
Kelas: 1A
Prodi: Sarjana Terapan Teknik Informatika
Jurusan: Teknik Komputer dan Informatika
Politeknik Negeri Bandung
*/


#include "antreanorang.h"
#include <stdlib.h>

AntreanOrang *DaftarAntrean = NULL;

int antreanKosong() {
    return DaftarAntrean == NULL;
}

AntreanOrang *buatNodeAntrean() {
    AntreanOrang *baru = (AntreanOrang *)malloc(sizeof(AntreanOrang));
    baru->antrean = NULL;
    baru->next = NULL;
    return baru;
}

void tambahAntrean(AntreanOrang *nodeBaru) {
    if (antreanKosong()) {
        DaftarAntrean = nodeBaru;
    } else {
        AntreanOrang *temp = DaftarAntrean;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = nodeBaru;
    }
}

AntreanOrang *temukanAntreanDariBuku(Buku *buku) {
    AntreanOrang *temp = DaftarAntrean;
    while (temp != NULL) {
        if (temp->antrean != NULL && temp->antrean->buku == buku) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

AntreanOrang *aksesAntreanKosongAtauAda(Buku *buku) {
    AntreanOrang *temp = DaftarAntrean;
    while (temp != NULL) {
        if (temp->antrean == NULL || temp->antrean->buku == buku) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

void hapusSemuaAntrean() {
    AntreanOrang *curr = DaftarAntrean;
    while (curr != NULL) {
        AntreanOrang *hapus = curr;
        curr = curr->next;

        Peminjam *pmj = hapus->antrean;
        while (pmj != NULL) {
            Peminjam *hapusPeminjam = pmj;
            pmj = pmj->next;
            free(hapusPeminjam);
        }

        free(hapus);
    }
    DaftarAntrean = NULL;
}
