/*Author: Devi Maulnai 
NIM: 241524007
Kelas: 1A
Prodi: Sarjana Terapan Teknik Informatika
Jurusan: Teknik Komputer dan Informatika
Politeknik Negeri Bandung
*/

#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"


// Implementasi Stack dengan Linked List
void initStack(Stack* s) {
    s->top = NULL; // Stack kosong
}

int isEmptyStack(Stack* s) {
    return s->top == NULL; // True jika top NULL
}

void push(Stack* s, int item) {
    address newNode;
    Create_Node(&newNode);
    Isi_Node(&newNode, item);
    Ins_Awal(&(s->top), newNode); // Menyisipkan di awal sebagai top
}

int pop(Stack* s) {
    if (isEmptyStack(s)) {
        printf("Stack kosong!\n");
        return -1; // Stack kosong
    }
    int data;
    Del_Awal(&(s->top), &data);
    return data; // Menghapus dan mengembalikan elemen teratas
}

void desimalKeBiner(int n) {
    Stack s;
    initStack(&s);

    if (n == 0) {
        printf("0");
        return;
    }

    // Konversi desimal ke biner
    while (n > 0) {
        push(&s, n % 2);
        n /= 2;
    }

    // Cetak hasil konversi
    while (!isEmptyStack(&s)) {
        printf("%d", pop(&s));
    }
}

void convertToBinary(Stack *s, int decimal) {
    if (decimal == 0) {
        printf("Biner: 0\n");
        return;
    }

    // Push sisa hasil bagi ke Stack
    while (decimal > 0) {
        push(s, decimal % 2);
        decimal /= 2;
    }

    // Pop untuk mendapatkan hasil biner dari stack
    printf("Biner: ");
    while (!isEmptyStack(s)) {
        printf("%d", pop(s));
    }
    printf("\n");
}




