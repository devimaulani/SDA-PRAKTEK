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

void Isi_Node (address *p , infotype nilai){
   
    if (*p != NULL){
        (*p)->info = nilai;
        (*p)->next = NULL;
    }
}

void Tampil_List(address p) {
    printf("elemen List = {");
    while (p != NULL) {
        printf("%d", p->info);
        if (p->next != NULL) {
            printf(", ");
        }
        p = p->next;
    }
    printf("}\n\n");
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

address Search (address p, infotype nilai){
   
    while (p != NULL){
        if (p->info == nilai){
            return p;
        }
        p = p->next;
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






