#include <stdio.h>
#include "listbuku.h"         // Untuk manajemen daftar buku
#include "antreanorang.h"   // Untuk manajemen antrean peminjam
#include "menu.h"           // Menu utama aplikasi

int main() {
    
    initList();             // Inisialisasi list buku
    tampilkanMenu();        // Panggil fungsi menu utama
    hapusSemuaAntrean();     // Bersihkan seluruh antrean dari memori
    bersihkanListBuku();    // Bersihkan seluruh daftar buku dari memori
    
    return 0;
}

