#include <stdio.h>
#include "morsetree.h"
#include "menu.h"

int main() {
    MorseTree T;
    CreateMorseTree(T);
    jalankanMenu(T);
    return 0;
}
