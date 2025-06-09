#include "menu.h"


void TampilkanMenu() {
    printf("\n===== MENU PROGRAM NON-BINARY TREE =====\n");
    printf("1. Create Tree\n");
    printf("2. Tampilkan Tree (PrintTable)\n");
    printf("3. Traversal PreOrder\n");
    printf("4. Traversal InOrder\n");
    printf("5. Traversal PostOrder\n");
    printf("6. Traversal LevelOrder\n");
    printf("7. Cari Node dan Tampilkan Level-nya\n");
    printf("8. Jumlah Simpul\n");
    printf("9. Jumlah Daun\n");
    printf("10. Kedalaman Tree\n");
    printf("11. Bandingkan Level 2 Node\n");
    printf("0. Keluar\n");
    printf("Pilih menu: ");
}

void JalankanMenu(Isi_Tree tree) {
    int pilihan, jumlahNode;
    infotype cari, node1, node2;
    do {
        TampilkanMenu();
        scanf("%d", &pilihan);
        getchar(); // untuk membersihkan newline di buffer
        switch(pilihan) {
            case 1:
                printf("Masukkan jumlah node: ");
                scanf("%d", &jumlahNode);
                Create_tree(tree, jumlahNode);
                break;
            case 2:
                PrintTree(tree);
                break;
            case 3:
                printf("PreOrder: ");
                PreOrderPrint(tree);
                break;
            case 4:
                printf("InOrder: ");
                InOrderPrint(tree);
                break;
            case 5:
                printf("PostOrder: ");
                PostOrderPrint(tree);
                break;
            case 6:
                printf("LevelOrder: ");
                Level_order(tree, jml_maks);
                break;
            case 7:
                printf("Masukkan node yang ingin dicari level-nya: ");
                scanf(" %c", &cari);
                if (Search(tree, cari)) {
                    printf("Node '%c' ditemukan di level %d\n", cari, Level(tree, cari));
                } else {
                    printf("Node '%c' tidak ditemukan\n", cari);
                }
                break;
            case 8:
                printf("Jumlah simpul: %d\n", nbElmt(tree));
                break;
            case 9:
                printf("Jumlah daun: %d\n", nbDaun(tree));
                break;
            case 10:
                printf("Kedalaman tree: %d\n", Depth(tree));
                break;
            case 11:
                printf("Masukkan dua node yang ingin dibandingkan levelnya (misal A B): ");
                scanf(" %c %c", &node1, &node2);
                if (!Search(tree, node1) || !Search(tree, node2)) {
                    printf("Salah satu atau kedua node tidak ditemukan!\n");
                } else {
                    int level1 = Level(tree, node1);
                    int level2 = Level(tree, node2);
                    printf("Level '%c': %d\n", node1, level1);
                    printf("Level '%c': %d\n", node2, level2);
                    if (level1 == level2) printf("Kedua node berada di level yang sama.\n");
                    else if (level1 < level2) printf("Node '%c' lebih tinggi dari '%c'.\n", node1, node2);
                    else printf("Node '%c' lebih tinggi dari '%c'.\n", node2, node1);
                }
                break;
            case 0:
                printf("Terima kasih!\n");
                break;
            default:
                printf("Pilihan tidak valid. Coba lagi.\n");
        }
    } while (pilihan != 0);
}

