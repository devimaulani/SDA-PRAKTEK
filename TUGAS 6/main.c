/*Author: Devi Maulnai 
NIM: 241524007
Kelas: 1A
Prodi: Sarjana Terapan Teknik Informatika
Jurusan: Teknik Komputer dan Informatika
Politeknik Negeri Bandung
*/


#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"


int main() {
	Stack s;
	int decimal;
	int input;
	
	while (1) { 
        printf("Ketik 0 untuk berhenti dan 1 untuk lanjut : ");
        scanf("%d", &input);
		
		switch (input){
			case 0 : 
				printf("keluar dari program\n");
	            return; 
	        case 1 :
	        	printf ("masukan bilangan desimal :");
				scanf ("%d", &decimal);
				convertToBinary(&s, decimal);	
			default :
				printf ("pilihsn tidak valid\n");
        }
    }
		
	return 0;
}




	

