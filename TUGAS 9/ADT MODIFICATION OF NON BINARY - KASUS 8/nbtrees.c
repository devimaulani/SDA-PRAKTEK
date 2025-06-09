#include "nbtrees.h"

int Max(infotype Data1, infotype Data2) {
    return (Data1 > Data2) ? Data1 : Data2;
}

boolean IsEmpty(Isi_Tree P) {
    return P[1].info == '\0';
}

void Create_tree(Isi_Tree X, int Jml_Node) {
	int i;
    for (i = 1; i <= jml_maks; i++) {
        X[i].info = '\0';
        X[i].ps_fs = 0;
        X[i].ps_nb = 0;
        X[i].ps_pr = 0;
    }

    for (i = 1; i <= Jml_Node; i++) {
        printf("Masukkan info node ke-%d: ", i);
        scanf(" %c", &X[i].info);
    }

    for (i = 1; i <= Jml_Node; i++) {
        int fs, nb, pr;
        printf("Node '%c'\n", X[i].info);
        printf("  Masukkan index first son (0 jika tidak ada): "); scanf("%d", &fs);
        printf("  Masukkan index next brother (0 jika tidak ada): "); scanf("%d", &nb);
        printf("  Masukkan index parent (0 jika akar): "); scanf("%d", &pr);
        X[i].ps_fs = fs;
        X[i].ps_nb = nb;
        X[i].ps_pr = pr;
    }
}

void PreOrder(Isi_Tree P, address idx) {
    if (idx == 0 || P[idx].info == '\0') return;
    printf("%c ", P[idx].info);
    PreOrder(P, P[idx].ps_fs);
    PreOrder(P, P[idx].ps_nb);
}

void PreOrderPrint(Isi_Tree P) {
    if (!IsEmpty(P)) PreOrder(P, 1);
    printf("\n");
}

void PostOrder(Isi_Tree P, address idx) {
    if (idx == 0 || P[idx].info == '\0') return;
    PostOrder(P, P[idx].ps_fs);
    printf("%c ", P[idx].info);
    PostOrder(P, P[idx].ps_nb);
}

void PostOrderPrint(Isi_Tree P) {
    if (!IsEmpty(P)) PostOrder(P, 1);
    printf("\n");
}

void InOrder(Isi_Tree P, address idx) {
    if (idx == 0 || P[idx].info == '\0') return;
    InOrder(P, P[idx].ps_fs);
    printf("%c ", P[idx].info);
    InOrder(P, P[idx].ps_nb);
}

void InOrderPrint(Isi_Tree P) {
    if (!IsEmpty(P)) InOrder(P, 1);
    printf("\n");
}

void Level_order(Isi_Tree X, int Maks_node) {
	int i;
    for (i = 1; i <= Maks_node; i++) {
        if (X[i].info != '\0') printf("%c ", X[i].info);
    }
    printf("\n");
}

void PrintTree(Isi_Tree P) {
	int i;
    printf("Index | Info | FS | NB | PR\n");
    for (i = 1; i <= jml_maks; i++) {
        if (P[i].info != '\0')
            printf("%5d |  %c   | %2d | %2d | %2d\n", i, P[i].info, P[i].ps_fs, P[i].ps_nb, P[i].ps_pr);
    }
}

boolean Search(Isi_Tree P, infotype X) {
	int i;
    for (i = 1; i <= jml_maks; i++) {
        if (P[i].info == X) return true;
    }
    return false;
}

int nbElmt(Isi_Tree P) {
	int i;
    int count = 0;
    for (i = 1; i <= jml_maks; i++) {
        if (P[i].info != '\0') count++;
    }
    return count;
}

int nbDaun(Isi_Tree P) {
	int i;
    int count = 0;
    for (i = 1; i <= jml_maks; i++) {
        if (P[i].info != '\0' && P[i].ps_fs == 0) count++;
    }
    return count;
}

int Level(Isi_Tree P, infotype X) {
	int i;
    for (i = 1; i <= jml_maks; i++) {
        if (P[i].info == X) {
            int level = 0, parent = P[i].ps_pr;
            while (parent != 0) {
                level++;
                parent = P[parent].ps_pr;
            }
            return level;
        }
    }
    return -1;
}

int DepthHelper(Isi_Tree P, int idx) {
    if (idx == 0 || P[idx].info == '\0') return 0;
    int maxDepth = 0;
    int child = P[idx].ps_fs;
    while (child != 0) {
        int depth = DepthHelper(P, child);
        if (depth > maxDepth) maxDepth = depth;
        child = P[child].ps_nb;
    }
    return maxDepth + 1;
}

int Depth(Isi_Tree P) {
    if (IsEmpty(P)) return 0;
    return DepthHelper(P, 1) - 1;
}

