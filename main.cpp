
#include <stdio.h>
#include <conio.h>
#include <windows.h>


#include "program.h"



// DEKLARASI MODUL - END

int main() {
	

	// PROSES FITUR SPLASH SCREEN
	
	
	
	

	
	
	home(); 

	system("cls");
	printf("Selesai");
	return 0;
}


// MODUL UNTUK MENGATUR POSISI LOADING
void gotoxy(int x, int y) 
{ 
    COORD coord;
    coord.X = x; 
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
// MODUL UNTUK MENGATUR POSISI LOADING - END
