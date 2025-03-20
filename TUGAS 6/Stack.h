/*Author: Devi Maulnai 
NIM: 241524007
Kelas: 1A
Prodi: Sarjana Terapan Teknik Informatika
Jurusan: Teknik Komputer dan Informatika
Politeknik Negeri Bandung
*/

#define STACK_H
#include "linked.h"

// Deklarasi ADT Stack menggunakan Linked List
typedef struct {
    address top; // Menyimpan elemen teratas dari stack
} Stack;


// Fungsi Prototipe Stack
void initStack(Stack* s); // Inisialisasi stack kosong
int isEmptyStack(Stack* s); // Mengecek apakah stack kosong
void push(Stack* s, infotype data); // Menambahkan elemen ke stack
int pop(Stack* s); // Menghapus elemen dari stack
void convertToBinary(Stack *s, int decimal);
