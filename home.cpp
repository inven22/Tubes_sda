// PEMANGGILAN LIBRARY
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// PEMANGGILAN LIBRARY - END

// PEMANGGILAN HEADER FILE

#include "home.h"

// PEMANGGILAN HEADER FILE - END

// DEKLARASI MODUL FUNCTION
		// MODUL UNTUK KELUAR APLIKASI
int salah_input_menu();		// MODUL UNTUK ERROR HANDLE APABILA SALAH INPUT PADA MENU
// DEKLARASI MODUL FUNCTION - END

// FUNCTION UTAMA UNTUK HOMEPAGE DARI APLIKASI
int home(){
	
	
	// DEKLARASI VARIABEL LOKAL
	int menu;

	// LIST MENU APLIKASI
	system("cls");


	printf("| Silahkan Pilih Menu dibawah ini :                                                                         |\n");
	printf("|===========================================================================================================|\n");
	printf("| 1. Masuk ke admin                                                                                         |\n");
	printf("| 2. Masuk ke petugas                                                                                       |\n");
	printf("| 3. Keluar                                                                                                 |\n");


    
    printf("\n\n");
    printf("Masukkan pilihan : "); // DI ISI DENGAN '1' ATAU '2', SELAIN DARI ITU MAKA PROGRAM AKAN MENGELUARKAN NOTIFIKASI ALERT
	scanf("%d", &menu);

	system("cls");
	
	// SISTEM DIRECT TO PAGE BERKAITAN BERDASARKAN INPUTAN YANG DIPILIH OLEH USER
    switch (menu) { 
        case 1:
			login(); 	// REDIRECT KE main_antrian() UNTUK MULAI SISTEM ANTRIAN
			break;
		case 2:
		    main_antrian(); 	// REDIRECT KE exit_aplikasi() UNTUK KELUAR DARI APLIKASI - LOKASI FILE : homepage.cpp
			break;
		case 3:
			  	menu = cek_antrian();
					if(menu != 0){ // JIKA RETURN NILAI NYA ADALAH 0, MAKA ARTINYA SUDAH TIDAK ADA MOBIL YANG DI CUCI ATAU MENGANTRI
						printf("Masih ada antrian.\n");
						tombol_selanjutnya(); // MODUL UNTUK ALTERNATIF BY PASS

						home(); // MODUL UTAMA
						
						break;	
					}
					
					system("cls");
                   
					out();
					
					break;

	 	default:
	 		salah_input_menu(); // REDIRECT KE salah_input_menu() UNTUK HANDLER PADA SAAT SALAH INPUT - LOKASI FILE : homepage.cpp
			break;
    }
}
// FUNCTION UTAMA UNTUK HOMEPAGE DARI APLIKASI - END

// FUNCTION UNTUK KELUAR DARI APLIKASI

// FUNCTION UNTUK KELUAR DARI APLIKASI - END

// FUNCTION UNTUK ERROR HANDLING PADA INPUTAN PEMILIHAN MENU
int salah_input_menu(){
	printf("Maaf Inputan Salah!\n");
	printf("Silahkan Tekan Apapun Untuk Kembali Ke Homepage...");
	getchar();

	// REDIRECT TO homepage.cpp
	system("cls");
	home(); // FILE : program.h --> homepage.cpp
}
// FUNCTION UNTUK ERROR HANDLING PADA INPUTAN PEMILIHAN MENU - END
