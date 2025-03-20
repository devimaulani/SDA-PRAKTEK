/*Author: Devi Maulnai 
NIM: 241524007
Kelas: 1A
Prodi: Sarjana Terapan Teknik Informatika
Jurusan: Teknik Komputer dan Informatika
Politeknik Negeri Bandung
*/




#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

/* Membuat queue baru dengan Front dan Rear NULL */
void CreateQueue(Queue *Q) {
    *Q = NULL;
}

/* Memeriksa apakah queue kosong */
boolean is_Empty(Queue Q) {
    return (Q == NULL);
}

/* Menghitung jumlah elemen dalam queue */
int CountQueue(Queue Q) {
    int count = 0;
    address P = Q;
    while (P != NULL) {
        count++;
        P = Next(P);
    }
    return count;
}

/* Memeriksa apakah queue penuh */
boolean is_Full(Queue Q) {
    return (CountQueue(Q) >= MAX_QUEUE);
}

/* Melakukan insertion pada queue (enqueue) */
void EnQueue(Queue *Q, infotype X) {
    if (is_Full(*Q)) {
        printf("Queue penuh! Tidak dapat menambah elemen.\n");
    } else {
        address PNew;
        Create_Node(&PNew);
        Isi_Node(&PNew, X);

        if (PNew != NULL) {
            Ins_Akhir(Q, PNew);
        } else {
            printf("Alokasi gagal!\n");
        }
    }
}

/* Melakukan deletion pada queue (dequeue) */
void deQueue(Queue *Q, infotype *X) {
    if (!is_Empty(*Q)) {
        Del_Awal(Q, X);
    } else {
        printf("Queue kosong, tidak dapat melakukan dequeue.\n");
    }
}

/* Menampilkan isi queue */
void TampilQueue(Queue Q) {
    if (is_Empty(Q)) {
        printf("Queue kosong!\n");
    } else {
        printf("Isi Queue: ");
        Tampil_List(Q);
    }
}

