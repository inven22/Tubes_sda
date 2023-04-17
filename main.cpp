
#include <stdio.h>
#include <conio.h>
#include <windows.h>


#include "program.h"


void gotoxy(int x, int y);
// DEKLARASI MODUL - END

int main() {
	

	// PROSES FITUR SPLASH SCREEN
	int load = 0; // UNTUK MENGHITUNG JUMLAH TITIK
	
	
	

	for( int i = 0; i <= 100; i++ ) //MENGKALKULASI PROSES DARI 0-100%
	{
		if(i % 10 == 0)
		{
			gotoxy(21 + 15 + load, 6);
			printf(".");
			load++;
			if(load == 6) //MENGHAPUS SEMUA TITIK
			{
				load = 0; 
				printf("\tTunggu sebentar lagi");
			}
		}
		gotoxy(21 + 21, 6);
		printf("%i",i);
		for(int j = 0; j < 50; j++ )  
		{
			for(int l = 0;l < 100000;l++) 
			{
				printf(""); 
			}		
		}
	}
	
	main_antrian(); 

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
