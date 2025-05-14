/*Author: Devi Maulnai 
NIM: 241524007
Kelas: 1A
Prodi: Sarjana Terapan Teknik Informatika
Jurusan: Teknik Komputer dan Informatika
Politeknik Negeri Bandung
*/

#include "listbuku.h"

Buku* Head_Buku = NULL;

// Inisialisasi list buku
void initList() {
    Head_Buku = NULL;
}

// Mengecek apakah list buku kosong
int isListBukuEmpty() {
    return Head_Buku == NULL;
}

// Mengecek apakah buku dengan judul tertentu ada dalam list
int isBukuExist(char judul[]) {
    Buku* current = Head_Buku;
    while (current != NULL) {
        if (strcmp(current->judul, judul) == 0) {
            return 1; // ditemukan
        }
        current = current->next;
    }
    return 0; // tidak ditemukan
}

// Membuat buku baru dan mengembalikan pointer-nya
Buku* createBuku(char judul[], int stok) {
    Buku* bukuBaru = (Buku*) malloc(sizeof(Buku));
    if (bukuBaru != NULL) {
        strcpy(bukuBaru->judul, judul);
        bukuBaru->stok = stok;
        bukuBaru->next = NULL;
    }
    return bukuBaru;
}

// Menambahkan buku ke dalam list (di akhir list)
void insertBuku(char judul[], int stok) {
    Buku* bukuBaru = createBuku(judul, stok);
    if (Head_Buku == NULL) {
        Head_Buku = bukuBaru;
    } else {
        Buku* current = Head_Buku;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = bukuBaru;
    }
}

// Menghapus buku dari list berdasarkan judul
void deleteBuku(char judul[]) {
    if (Head_Buku == NULL) return;

    Buku* current = Head_Buku;
    Buku* prev = NULL;

    while (current != NULL) {
        if (strcmp(current->judul, judul) == 0) {
            if (prev == NULL) {
                Head_Buku = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            printf("Buku \"%s\" berhasil dihapus.\n", judul);
            return;
        }
        prev = current;
        current = current->next;
    }

    printf("Buku \"%s\" tidak ditemukan.\n", judul);
}

// Mencari buku berdasarkan judul dan mengembalikan pointer ke buku
Buku* cariBuku(char judul[]) {
   
    
    if (Head_Buku == NULL) {
        
        return NULL;
    }
    
    Buku* current = Head_Buku;
    int found = 0;
    
    while (current != NULL) {
        // Gunakan fungsi strcasecmp untuk abaikan perbedaan huruf besar/kecil
        // Jika tidak tersedia di sistem, gunakan strcmp
        #ifdef _WIN32
        // Untuk Windows, gunakan stricmp (case insensitive)
        int result = _stricmp(current->judul, judul);
        #else
        // Untuk sistem lain, gunakan strcasecmp (case insensitive)
        int result = strcasecmp(current->judul, judul);
        #endif
        
               
        if (result == 0) {
            
            found = 1;
            return current;
        }
        
        // Alternatif: gunakan perbandingan string case sensitive standar
        if (strcmp(current->judul, judul) == 0) {
            
            found = 1;
            return current;
        }
        
        current = current->next;
    }
    
    
    return NULL;
}

// Fungsi untuk menampilkan semua buku dalam list
void tampilkanSemuaBuku() {
    if (isListBukuEmpty()) {
        printf("Tidak ada buku dalam daftar.\n");
        return;
    }

    Buku* current = Head_Buku;
    while (current != NULL) {
        printf("Judul Buku: %s\n", current->judul);
        printf("Stok: %d\n", current->stok);
        printf("--------------------------\n");
        current = current->next;
    }
}

// Membersihkan seluruh list buku
void bersihkanListBuku() {
    Buku* current = Head_Buku;
    while (current != NULL) {
        Buku* temp = current;
        current = current->next;
        free(temp);
    }
    Head_Buku = NULL;
    printf("Seluruh list buku telah dibersihkan.\n");
}

