#ifndef LISTBUKU_H
#define LISTBUKU_H

#define MAX_BUKU 100

typedef struct {
    char judul[100];
    int stok;
} Buku;

void initBuku();
void tambahBuku(char *judul, int stok);
void tampilkanDaftarBuku();
int getJumlahBuku();
Buku* cariBuku(char *judul);
void kurangiStok(Buku *b);
int kembalikanBuku(const char *judul);


#endif

