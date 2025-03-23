/*Author: Devi Maulnai 
NIM: 241524007
Kelas: 1A
Prodi: Sarjana Terapan Teknik Informatika
Jurusan: Teknik Komputer dan Informatika
Politeknik Negeri Bandung
*/

#include "gudang.h"

// Inisialisasi struktur data
address stokGudang = NULL;  // Linked List untuk stok barang
Queue antrianPengiriman;
Stack riwayatPengiriman;

void tambahBarangGudang() {
    int data;
    printf("Masukkan ID Barang untuk ditambahkan ke Gudang: ");
    scanf("%d", &data);
    address newItem;
    Create_Node(&newItem);
    Isi_Node(&newItem, data);
    Ins_Akhir(&stokGudang, newItem);
    printf("Barang dengan ID %d berhasil ditambahkan ke gudang.\n", data);
}

void hapusBarangGudang() {
    int data;
    if (stokGudang == NULL) {
        printf("Gudang kosong!\n");
    } else {
        Del_Awal(&stokGudang, &data);
        printf("Barang dengan ID %d telah dihapus dari gudang.\n", data);
    }
}

void lihatStokGudang() {
    printf("Stok Barang di Gudang:\n");
    Tampil_List(stokGudang);
}

void tambahKeAntrianPengiriman() {
    int data;
    if (stokGudang == NULL) {
        printf("Tidak ada barang di gudang untuk dikirim!\n");
    } else {
        printf("Masukkan ID Barang untuk dikirim: ");
        scanf("%d", &data);
        EnQueue(&antrianPengiriman, data);
        printf("Barang dengan ID %d berhasil dimasukkan ke antrian pengiriman.\n", data);
    }
}

void kirimBarang() {
    int data;
    if (is_Empty(antrianPengiriman)) {
        printf("Tidak ada barang dalam antrian pengiriman!\n");
    } else {
        deQueue(&antrianPengiriman, &data);
        push(&riwayatPengiriman, data);
        printf("Barang dengan ID %d telah dikirim.\n", data);
    }
}

void lihatAntrianPengiriman() {
    printf("Antrian Pengiriman Barang:\n");
    TampilQueue(antrianPengiriman);
}

void lihatRiwayatPengiriman() {
    printf("Riwayat Barang yang Sudah Dikirim:\n");
    displayStack(&riwayatPengiriman);
}

