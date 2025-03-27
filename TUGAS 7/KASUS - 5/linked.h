
/* Author: Devi Maulnai 
   NIM: 241524007
   Kelas: 1A
   Prodi: Sarjana Terapan Teknik Informatika
   Jurusan: Teknik Komputer dan Informatika
   Politeknik Negeri Bandung
*/

#ifndef LINKED_H
#define LINKED_H

#include <stdio.h>
#include <stdlib.h>  // Digunakan untuk malloc
#include <string.h>  // Untuk operasi string seperti strcmp, strcpy
#include "boolean.h"

typedef char infotype[30];  // Menggunakan string sebagai tipe data
typedef struct tElmtList *address;
typedef struct tElmtList {
    infotype info;
    address next;
} ElmtList;

// Prototipe fungsi dasar Linked List
boolean isEmpty(address p);
void Create_Node(address *p);
void Isi_Node(address *p, infotype nilai);
void Tampil_List(address p);
void Ins_Awal(address *p, address PNew);
void Ins_Akhir(address *p, address PNew);
address Search(address p, infotype nilai);
void InsertAfter(address *pBef, address PNew);
void Del_Awal(address *p, infotype *X);
void Del_Akhir(address *p, infotype *X);
void Del_After(address *pBef, infotype *X);
void DeAlokasi(address *p);
int NbElmt(address p);

// Fungsi tambahan untuk memodifikasi elemen dalam linked list
void modify_first(address *head, infotype new_data);
void modify_last(address *head, infotype new_data);
void modify_middle(address *head, infotype new_data, int position);

#endif




