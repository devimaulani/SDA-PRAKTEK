/*Author: Devi Maulnai 
NIM: 241524007
Kelas: 1A
Prodi: Sarjana Terapan Teknik Informatika
Jurusan: Teknik Komputer dan Informatika
Politeknik Negeri Bandung
*/


#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "linked.h"


boolean isEmpty(address p){
   
    return (p == NULL);
}

void Create_Node (address *p){
    
    *p = (address) malloc (sizeof(ElmtList));
    if (*p != NULL){
        (*p)->next = NULL;
    }
}


void Isi_Node(address *P, infotype nama) {
    if (*P != NULL) {
        strcpy((*P)->info, nama); //diubah agar dapat menangani string input user
    }
}


void Tampil_List(address First) {
    address P = First;
    if (P == NULL) {
        printf("Kosong\n");
        return;
    }
    while (P != NULL) {
        printf("%s -> ", P->info);
        P = P->next;
    }
    printf("NULL\n");
}


void Ins_Awal (address *p, address PNew){
    
    PNew->next = *p;
    *p = PNew;
}

void Ins_Akhir (address *p, address PNew){
   
    if (*p == NULL){
        *p = PNew;
    } else {
        address last = *p;
        while (last->next != NULL){
            last = last->next;
        }
        last->next = PNew;
    }
}



address Search(address First, infotype X) {
    address P = First;
    while (P != NULL) {
        if (strcmp(P->info, X) == 0) { // Bandingkan string
            return P;
        }
        P = P->next;
    }
    return NULL;
}



void InsertAfter (address * pBef, address PNew){
   
    PNew->next = (*pBef)->next;
    (*pBef)->next = PNew;
}

void Del_Awal (address * p, infotype * X){
    
    *X = (*p)->info;
    address temp = *p;
    *p = (*p)->next;
    free(temp);
}

void Del_Akhir (address * p, infotype * X){
    
    address last = *p;
    address beforeLast = NULL;
    while (last->next != NULL){
        beforeLast = last;
        last = last->next;
    }
    *X = last->info;
    if (beforeLast == NULL){
        *p = NULL;
    } else {
        beforeLast->next = NULL;
    }
    free(last);
}

void Del_After (address * pBef, infotype * X){
   
    address temp = (*pBef)->next;
    *X = temp->info;
    (*pBef)->next = temp->next;
    free(temp);
}

void DeAlokasi (address * p){
   
    free(*p);
}

int NbElmt (address p){
  
    if (p == NULL){
        return 0;
    } else {
        return 1 + NbElmt(p->next);
    }
}

void modify_first(address head, infotype new_data) {
    if (head == NULL) return;
    head->info = new_data;
}

void modify_last(address head, infotype new_data) {
    if (head == NULL) return;
    address temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->info = new_data;
}

void modify_middle(address head, infotype new_data, int position) {
    if (head == NULL) return;
    address temp = head;
    int count = 1;
    while (count < position && temp != NULL) {
        temp = temp->next;
        count++;
    }
    if (temp == NULL) {
        printf("Position out of bounds\n");
        return;
    }
    temp->info = new_data;
}






