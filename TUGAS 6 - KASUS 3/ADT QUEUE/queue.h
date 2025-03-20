/*Author: Devi Maulnai 
NIM: 241524007
Kelas: 1A
Prodi: Sarjana Terapan Teknik Informatika
Jurusan: Teknik Komputer dan Informatika
Politeknik Negeri Bandung
*/



#ifndef QUEUE_H
#define QUEUE_H

#include "boolean.h"
#include "linked.h"

#define MAX_QUEUE 10  

typedef address Queue; // Queue direpresentasikan dengan pointer ke node pertama

/* Membuat queue baru dengan Front dan Rear NULL */
void CreateQueue(Queue *Q);

/* Memeriksa apakah queue kosong */
boolean is_Empty(Queue Q);

/* Memeriksa apakah queue penuh */
boolean is_Full(Queue Q);

/* Melakukan insertion pada queue (enqueue) */
void EnQueue(Queue *Q, infotype X);

/* Melakukan deletion pada queue (dequeue) */
void deQueue(Queue *Q, infotype *X);

/* Menampilkan isi queue */
void TampilQueue(Queue Q);

/* Menghitung jumlah elemen dalam queue */
int CountQueue(Queue Q);

#endif

