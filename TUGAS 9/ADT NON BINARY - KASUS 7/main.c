#include "nbtrees.h"

int main() {
    Isi_Tree tree;
    int jumlahNode;

    printf("Masukkan jumlah node: ");
    scanf("%d", &jumlahNode);

    Create_tree(tree, jumlahNode);

    printf("\n===== TREE DALAM BENTUK TABEL =====\n");
    PrintTree(tree);

    printf("\n===== TRAVERSAL =====\n");
    printf("PreOrder   : ");
    PreOrderPrint(tree);
    printf("InOrder    : ");
    InOrderPrint(tree);
    printf("PostOrder  : ");
    PostOrderPrint(tree);
    printf("LevelOrder : ");
    Level_order(tree, jumlahNode);

    char cari;
    printf("\nMasukkan node yang ingin dicari level-nya: ");
    scanf(" %c", &cari);
    if (Search(tree, cari)) {
        printf("Node '%c' ditemukan di level %d\n", cari, Level(tree, cari));
    } else {
        printf("Node '%c' tidak ditemukan\n", cari);
    }

    printf("\nJumlah simpul      : %d\n", nbElmt(tree));
    printf("Jumlah daun        : %d\n", nbDaun(tree));
    printf("Kedalaman tree     : %d\n", Depth(tree));

    return 0;
}

