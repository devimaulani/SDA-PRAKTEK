#ifndef nbtrees_h
#define nbtrees_h

#include "boolean.h"

#define jml_maks 20
#define kebawah  1
#define keatas   2
#define kekanan  3
#define nil   0

/***************************/
/*  Type data */
/***************************/

/* Indeks dalam bahasa C dimulai dengan 0; tetapi indeks 0 tidak dipakai */

/* Kamus */
typedef char infotype;
typedef int address;

typedef struct {
    infotype info;
    address ps_fs, ps_nb, ps_pr;
} nbtree;

typedef nbtree Isi_Tree[jml_maks + 1];

/***************************************************************/
/********************  S P E S I F I K A S I  *****************/
/*************************************************************/

void Create_tree(Isi_Tree X, int Jml_Node);
// Create Non Binary Tree sebanyak Jml_Node
// Tujuan mengentrykan Non Binary Tree ke array Isi_Tree dengan pola Level Order
// Jml Node adalah banyaknya elemen dalam Tree yang menjadi parameter input

boolean IsEmpty(Isi_Tree P);
/* Mengirimkan true jika Isi_Tree KOSONG */

/***** Traversal *****/
void PreOrder(Isi_Tree P, address idx);
/* Traversal PreOrder */
/* IS : P terdefinisi */
/* FS : Semua simpul P sudah ditampilkan secara PreOrder : Parent, fs, nb */

void PreOrderPrint(Isi_Tree P); // ************* fungsi tambahan ***************** //

void InOrder(Isi_Tree P,address idx);
/* Traversal InOrder */
/* IS : P terdefinisi */
/* FS : Semua simpul P sudah ditampilkan secara InOrder : fs, Parent, Sisa anak lain */

void InOrderPrint(Isi_Tree P); // ************* fungsi tambahan ***************** //

void PostOrder(Isi_Tree P, address idx);
/* Traversal PostOrder */
/* IS : P terdefinisi */
/* FS : Semua simpul P sudah ditampilkan secara PostOrder : fs, nb, Parent */

void PostOrderPrint(Isi_Tree P); // ************* fungsi tambahan ***************** //

void Level_order(Isi_Tree X, int Maks_node);
/* Traversal LevelOrder */
/* IS : P terdefinisi */
/* FS : Semua simpul P sudah ditampilkan secara Level Order */

void PrintTree(Isi_Tree P);
/* IS : P terdefinisi */
/* FS : Semua simpul P sudah ditulis ke layar */

/***** Search *****/
boolean Search(Isi_Tree P, infotype X);
/* Mengirimkan true jika ada node dari P yang bernilai X */

/***** Fungsi Lain *****/
int nbElmt(Isi_Tree P);
/* Mengirimkan banyak elemen (node) di pohon non biner P */

int nbDaun(Isi_Tree P);
/* Mengirimkan banyak daun (node) pohon non biner P */

int Level(Isi_Tree P, infotype X);
/* Mengirimkan level dari node X yang merupakan salah satu simpul dari pohon P. Akar (P) levelnya adalah 0. Pohon tidak kosong */

int Depth(Isi_Tree P);
/* Pohon Biner mungkin Kosong, mengirimkan 'depth' yaitu tinggi dari Pohon */
/* Basis : Pohon Kosong, tingginya Nol */

int Max(infotype Data1, infotype Data2);
/* Mengirimkan Nilai terbesar dari dua data */

#endif


