/*Author: Devi Maulnai 
NIM: 241524007
Kelas: 1A
Prodi: Sarjana Terapan Teknik Informatika
Jurusan: Teknik Komputer dan Informatika
Politeknik Negeri Bandung
*/

#include "linked.h"

// *********************************** Fungsi untuk menampilkan menu utama ****************************
void TampilkanMenu() {
	
    printf("\n===== MENU LINKED LIST =====\n");
    printf("1. Tambah Mahasiswa (Urut Nama)\n");
    printf("2. Tampilkan Data (Ascending Nama)\n");
    printf("3. Tampilkan Data (Descending Nilai)\n");
    printf("4. Salin Mahasiswa dengan Nilai > 70 ke List L2\n");
    printf("5. Hapus Nama Duplikat\n");
    printf("6. Tampilkan Data L2 (Nilai > 70)\n");
    printf("7. Tampilkan Data L2 setelah menghapus duplikat\n");
    printf("8. Hapus L1 dan L2\n");
    printf("9. Keluar\n\n");
    printf("Pilih menu: ");
}

// ********************************************* Fungsi Alokasi ****************************************
// Fungsi untuk mengalokasikan memori untuk node baru
address Alokasi(char nama[], int nilai) {
    address newNode = (address)malloc(sizeof(ElmtList)); // Alokasi memori untuk node baru
    if (newNode != NULL) { // Periksa apakah alokasi berhasil
        strcpy(newNode->namaMahasiswa, nama);  // Salin nama ke node
        newNode->nilai = nilai; // Simpan nilai mahasiswa
        newNode->next = NULL; // Set pointer next menjadi NULL
    }
    return newNode; // Kembalikan alamat node baru
}

// ******************************** Konstruktor (Membuat list kosong) **********************************
void CreateList(List *L) {
    L->First = NULL; // Inisialisasi list kosong
}

// ***************************** Destructor (Menghapus seluruh elemen list) ****************************
void DeleteList(List *L) {
    address temp;
    while (L->First != NULL) { // Looping selama masih ada elemen dalam list
        temp = L->First; // Simpan alamat node pertama
        L->First = L->First->next; // Pindah ke node berikutnya
        free(temp); // Hapus node dari memori
    }
}

// *********************************** Validator (Cek apakah list kosong) ******************************
int isEmpty(List L) {
    return (L.First == NULL); // Mengembalikan 1 jika First == NULL (list kosong)
}

// ****************** Fungsi untuk menyisipkan elemen secara terurut berdasarkan Nama ******************
void InsertSortedByName(List *L, char nama[], int nilai) {
    address newNode = Alokasi(nama, nilai); // Gunakan fungsi Alokasi untuk membuat node baru
    if (newNode == NULL) return; // Jika alokasi gagal, keluar dari fungsi

    // Jika list kosong atau nama lebih kecil dari elemen pertama
    if (isEmpty(*L) || strcmp(nama, L->First->namaMahasiswa) < 0) {
        newNode->next = L->First; // Node baru menjadi First
        L->First = newNode;
    } else {
        address prev = L->First;
        // Cari posisi yang tepat berdasarkan urutan nama
        while (prev->next != NULL && strcmp(nama, prev->next->namaMahasiswa) > 0) {
            prev = prev->next;
        }
        newNode->next = prev->next; // Sisipkan node baru setelah prev
        prev->next = newNode;
    }
}

// ****************** Fungsi untuk menyisipkan elemen secara terurut berdasarkan Nilai ******************
void InsertSortedByValue(List *L, char nama[], int nilai) {
    address newNode = Alokasi(nama, nilai); // Gunakan fungsi Alokasi
    if (newNode == NULL) return; // Jika alokasi gagal, keluar dari fungsi

    // Jika list kosong atau nilai lebih besar dari elemen pertama
    if ((*L).First == NULL || (*L).First->nilai < nilai) {
        newNode->next = (*L).First;
        (*L).First = newNode;
    } else {
        address prev = (*L).First;
        while (prev->next != NULL && prev->next->nilai >= nilai) {
            prev = prev->next;
        }
        newNode->next = prev->next;
        prev->next = newNode;
    }
}

// ********************* Fungsi menampilkan list secara ascending berdasarkan nama *********************
void PrintAscending(List L) {
	system ("cls");
    address temp = L.First;
    while (temp != NULL) { // Loop selama masih ada elemen dalam list
        printf("%s - %d\n", temp->namaMahasiswa, temp->nilai);
        temp = temp->next;
    }
}

//  ******************** Fungsi menampilkan list secara descending berdasarkan nilai ********************
void PrintDescending(List L) {
	system ("cls");
    List tempList; 
    CreateList(&tempList); // Membuat list sementara

    address temp = L.First;
    while (temp != NULL) { 
        InsertSortedByValue(&tempList, temp->namaMahasiswa, temp->nilai);
        temp = temp->next;
    }

    temp = tempList.First;
    while (temp != NULL) {
        printf("%s - %d\n", temp->namaMahasiswa, temp->nilai);
        temp = temp->next;
    }
    DeleteList(&tempList); // Hapus list sementara
}

// ********************* Fungsi menyalin elemen dengan nilai > 70 ke list L2 **************************
void CopyGreaterThan70(List *L1, List *L2) {
    DeleteList(L2); // Hapus isi L2 sebelum menyalin agar tidak duplikasi
    address temp = L1->First;
    while (temp != NULL) { // Looping semua elemen dalam L1
        if (temp->nilai > 70) { 
            InsertSortedByName(L2, temp->namaMahasiswa, temp->nilai); // Salin elemen ke L2
        }
        temp = temp->next;
    }
}

// ************************* Fungsi menghapus nama yang duplikat pada List L **************************
void RemoveDuplicates(List *L) {
    if (isEmpty(*L)) return; // Jika list kosong, keluar dari fungsi

    address current = L->First;
    while (current != NULL) { // Loop setiap elemen
        address temp = current;
        while (temp->next != NULL) { 
            if (strcmp(current->namaMahasiswa, temp->next->namaMahasiswa) == 0) { // Jika ada duplikat
                address duplicate = temp->next; 
                temp->next = temp->next->next; // Lewati elemen duplikat
                free(duplicate); // Hapus dari memori
            } else {
                temp = temp->next; // Geser ke elemen berikutnya
            }
        }
        current = current->next; // Geser current ke elemen berikutnya
    }
}

