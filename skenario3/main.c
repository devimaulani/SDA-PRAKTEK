#include "listbuku.h"
#include "antrian.h"
#include "menu.h"

int main() {
    initBuku();
    initAntrian();

    // Tambah beberapa buku awal
    tambahBuku("Algoritma", 2);
    tambahBuku("Struktur Data", 1);
    tambahBuku("Pemrograman C", 0);

    prosesMenu();

    return 0;
}

