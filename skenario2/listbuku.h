/*Author: Devi Maulnai 
NIM: 241524007
Kelas: 1A
Prodi: Sarjana Terapan Teknik Informatika
Jurusan: Teknik Komputer dan Informatika
Politeknik Negeri Bandung
*/

#ifndef LISTBUKU_H
#define LISTBUKU_H

// Forward declaration
typedef struct Peminjam Peminjam;

#include "peminjam.h"

// Struktur node untuk buku
typedef struct Buku {
    char judul[50];
    int stok;
    Peminjam* antrean;  
    struct Buku* next; // Pointer ke buku berikutnya (SLL)
} Buku;

// ============ LINKED LIST UNTUK MENGELOLA BUKU ===========

extern Buku* Head_Buku;       // Pointer global ke head list buku

// Inisialisasi list buku
void initList();
// Initial state: Head list buku = NULL
// Final state: Head list buku tetap NULL

// Mengecek apakah list buku kosong
int isListBukuEmpty();
// Initial: List buku
// Final: Mengembalikan 1 jika list kosong, 0 jika tidak

// Mengecek apakah buku dengan judul tertentu ada dalam list
int isBukuExist(char judul[]);
// Initial: List memiliki satu atau lebih buku
// Final: Mengembalikan 1 jika buku ada, 0 jika tidak ada

// Membuat buku baru dan mengembalikan pointer-nya
Buku* createBuku(char judul[], int stok);
// Initial: Judul dan stok buku
// Final: Mengembalikan pointer ke buku baru

// Menambahkan buku ke dalam list buku
void insertBuku(char judul[], int stok);
// Initial state: List buku, head = NULL atau list sudah berisi buku
// Final state: Buku baru ditambahkan di awal atau akhir list

// Menghapus buku dari list berdasarkan judul
void deleteBuku(char judul[]);
// Initial state: List buku, head menunjuk ke list buku
// Final state: Buku dengan judul tertentu dihapus dari list

// Mencari buku berdasarkan judul dan mengembalikan pointer ke buku
Buku* cariBuku(char judul[]);
// Initial: List memiliki buku
// Final: Mengembalikan pointer ke buku dengan judul tertentu

// Menampilkan seluruh buku yang ada dalam list
void tampilkanSemuaBuku();
// Initial: List buku sudah terisi
// Final state: Menampilkan informasi semua buku dalam list

// Membersihkan seluruh list buku
void bersihkanListBuku();
// Initial state: List buku
// Final state: Semua buku dalam list dihapus

#endif // LISTBUKU_H

