#ifndef LINKED_H
#define LINKED_H
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

// Struktur elemen linked list
typedef struct tElmtList *address;
typedef struct tElmtList {
    char namaMahasiswa[50]; // Nama Mahasiswa
    int nilai;              // Nilai UTS SDA
    address next;           // Pointer ke elemen berikutnya
} ElmtList;

// Struktur list
typedef struct {
    address First;
} List;

// Fungsi untuk menampilkan menu
void TampilkanMenu();

// Konstruktor
void CreateList(List *L);

// Destructor
void DeleteList(List *L);

// Validator
int isEmpty(List L);

// Get/Set
void InsertSortedByName(List *L, char nama[], int nilai);
void InsertSortedByValue(List *L, char nama[], int nilai);
void CopyGreaterThan70(List *L1, List *L2);
void RemoveDuplicates(List *L);

// PrintObject
void PrintAscending(List L);
void PrintDescending(List L);

#endif

