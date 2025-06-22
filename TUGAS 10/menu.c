#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"

void tampilkanMenu() {
    printf("\n================ MENU UTAMA ================\n");
    printf("[1] Tampilkan Pohon Kode Morse (Visual)\n");
    printf("[2] Tampilkan Kamus Kode Morse\n");
    printf("[3] Terjemahkan Teks ke Kode Morse\n");
    printf("[4] Terjemahkan Kode Morse ke Teks\n");
    printf("[5] Terjemahkan File ke Kode Morse\n");
    printf("[6] Terjemahkan File Kode Morse ke Teks\n");
    printf("[0] Keluar\n");
    printf("============================================\n");
    printf("Pilih menu: ");
}


void jalankanMenu(MorseTree T) {
    int pilihan;
    char buffer[256];

    do {
        tampilkanMenu();
        scanf("%d", &pilihan);
        getchar();  // clear newline

        switch (pilihan) {
            case 1:
                printf("\nVisualisasi Pohon Kode Morse:\n");
                printTreeVisual(T, 1, 0);
                break;
            case 2:
                tampilkanKamus(T);
                break;
            case 3:
                printf("\nMasukkan teks: ");
                fgets(buffer, sizeof(buffer), stdin);
                buffer[strcspn(buffer, "\n")] = '\0';
                encodeText(T, buffer);
                break;
            case 4:
                printf("\nMasukkan kode morse (pisah tiap huruf dengan spasi):\n");
                fgets(buffer, sizeof(buffer), stdin);
                buffer[strcspn(buffer, "\n")] = '\0';
                decodeText(T, buffer);
                break;
            case 5:
                encodeFromFile(T, "input.txt", "out.txt");
                printf("Hasil telah disimpan di 'out.txt'\n");
                break;
            case 6:
                decodeFromFile(T, "morse.txt", "decoded.txt");
                printf("Hasil telah disimpan di 'decoded.txt'\n");
                break;
            case 0:
                printf("Keluar dari program.\n");
                break;
            default:
                printf("Pilihan tidak valid.\n");
        }
    } while (pilihan != 0);
}
