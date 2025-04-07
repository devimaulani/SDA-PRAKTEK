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
#include "kota.h"

void tambahKota(KotaAddress *head, infotype namaKota) {
    KotaAddress newKota = (KotaAddress)malloc(sizeof(Kota));
    if (newKota) {
        strcpy(newKota->namaKota, namaKota);
        newKota->daftarNama = NULL; // Inisialisasi Single Linked List Kosong
        newKota->next = newKota->prev = NULL;
        
        if (*head == NULL) {
            *head = newKota;
        } else {
            KotaAddress temp = *head;
            while (temp->next) temp = temp->next;
            temp->next = newKota;
            newKota->prev = temp;
        }
        printf("Kota %s berhasil ditambahkan.\n", namaKota);
    } else {
        printf("Gagal mengalokasikan memori untuk kota baru.\n");
    }
}

// Fungsi untuk menghapus seluruh nama dalam daftar
void hapusSemuaNama(List *daftarNama) {
    infotype tempNama;
    while (*daftarNama != NULL) {
        Del_Awal(daftarNama, &tempNama);
    }
}

void hapusKota(KotaAddress *head, infotype namaKota) {
    if (*head == NULL) {
        printf("Daftar kota kosong.\n");
        return;
    }
    
    KotaAddress temp = *head;
    while (temp && strcmp(temp->namaKota, namaKota) != 0) temp = temp->next;
    
    if (temp) {
        // Hapus semua nama dalam linked list terlebih dahulu
        hapusSemuaNama(&(temp->daftarNama));
        
        // Hapus node kota
        if (temp->prev) temp->prev->next = temp->next;
        if (temp->next) temp->next->prev = temp->prev;
        if (temp == *head) *head = temp->next;
        
        free(temp);
        printf("Kota %s dan semua nama di dalamnya berhasil dihapus.\n", namaKota);
    } else {
        printf("Kota %s tidak ditemukan.\n", namaKota);
    }
}

void tambahNama(KotaAddress head, infotype namaKota, infotype namaOrang) {
    KotaAddress temp = head;
    while (temp && strcmp(temp->namaKota, namaKota) != 0) temp = temp->next;
    
    if (temp) {
        address newNama;
        Create_Node(&newNama);
        if (newNama == NULL) {
            printf("Gagal mengalokasikan memori untuk nama baru.\n");
            return;
        }
        
        Isi_Node(&newNama, namaOrang);
        Ins_Akhir(&temp->daftarNama, newNama);
        printf("Nama %s berhasil ditambahkan ke kota %s.\n", namaOrang, namaKota);
    } else {
        printf("Kota %s tidak ditemukan.\n", namaKota);
    }
}

void hapusNama(KotaAddress head, infotype namaKota, infotype namaOrang) {
    KotaAddress temp = head;
    while (temp && strcmp(temp->namaKota, namaKota) != 0) temp = temp->next;
    
    if (temp) {
        // Kasus khusus: jika nama yang akan dihapus ada di awal list
        if (temp->daftarNama != NULL && strcmp(temp->daftarNama->info, namaOrang) == 0) {
            infotype tempInfo;
            Del_Awal(&temp->daftarNama, &tempInfo);
            printf("Nama %s berhasil dihapus dari kota %s.\n", namaOrang, namaKota);
            return;
        }
        
        // Mencari node sebelum node yang akan dihapus
        address current = temp->daftarNama;
        address prev = NULL;
        
        while (current != NULL && strcmp(current->info, namaOrang) != 0) {
            prev = current;
            current = current->next;
        }
        
        if (current == NULL) {
            printf("Nama %s tidak ditemukan di kota %s.\n", namaOrang, namaKota);
            return;
        }
        
        // Menghapus node yang ditemukan
        infotype tempInfo;
        Del_After(&prev, &tempInfo);
        printf("Nama %s berhasil dihapus dari kota %s.\n", namaOrang, namaKota);
    } else {
        printf("Kota %s tidak ditemukan.\n", namaKota);
    }
}

void tampilkanKota(KotaAddress head) {
    if (head == NULL) {
        printf("Daftar kota kosong.\n");
        return;
    }
    
    KotaAddress temp = head;
    int i = 1;
    while (temp) {
        printf("%d. Kota: %s\n", i++, temp->namaKota);
        if (temp->daftarNama == NULL) {
            printf("   Belum ada nama terdaftar di kota ini.\n");
        } else {
            printf("   Daftar nama: ");
            Tampil_List(temp->daftarNama);
        }
        temp = temp->next;
    }
}

void hitungData(KotaAddress head) {
    int jumlahKota = 0, jumlahNama = 0;
    KotaAddress temp = head;
    while (temp) {
        jumlahKota++;
        int namaPerKota = NbElmt(temp->daftarNama);
        jumlahNama += namaPerKota;
        printf("Kota %s memiliki %d nama.\n", temp->namaKota, namaPerKota);
        temp = temp->next;
    }
    printf("Total Kota: %d, Total Nama: %d\n", jumlahKota, jumlahNama);
}

void cariNamaPerKota(KotaAddress head, infotype namaKota) {
    KotaAddress temp = head;
    while (temp && strcmp(temp->namaKota, namaKota) != 0) temp = temp->next;
    
    if (temp) {
        printf("Nama-nama di kota %s:\n", namaKota);
        if (temp->daftarNama == NULL) {
            printf("Belum ada nama terdaftar di kota ini.\n");
        } else {
            Tampil_List(temp->daftarNama);
        }
    } else {
        printf("Kota %s tidak ditemukan.\n", namaKota);
    }
}

