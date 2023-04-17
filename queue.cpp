// PEMANGGILAN LIBRARY
#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 
#include <conio.h>
#include <iostream>
// PEMANGGILAN LIBRARY - END


// PEMANGGILAN FILE HEADER

#include "queu.h"

// PEMANGGILAN FILE HEADER - END

#define BUFFER_SIZE 1000

// DEKLARASI MODUL FUNCTION
int exit_aplikasi_antrian();		// MODUL UNTUK KELUAR APLIKASI
int salah_input_menu_antrian();		// MODUL UNTUK ERROR HANDLE APABILA SALAH INPUT PADA MENU
// DEKLARASI MODUL FUNCTION - END



// FUNCTION UTAMA UNTUK ANTRIAN DARI APLIKASI
int main_antrian(){
	// DEKLARASI VARIABEL LOKAL
	int pilihan;
	int pil;

	system("cls");



	printf("\n");
	printf("\t\t\t");jam_waktu();

	if(pukul_waktu >= waktu_tutup){
		out(); // MODUL UNTUK MENAMPILKAN RINGKASAN TOTAL TRANSAKSI
	}
	else if(pukul_waktu >= waktu_mulai_istirahat && pukul_waktu <= waktu_selesai_istirahat){
		printf("\n");
		printf("  Sedang Istirahat dari jam 12:00 - 13:00");
		printf("\n");
	}
	else{
		data_antrian(); // MENAMPILKAN ANTRIAN KENDARAAN YANG SEDANG DICUCI DAN SEDANG MENGANTRI
	}

	// LIST MENU APLIKASI
	if(pukul_waktu >= waktu_mulai_istirahat && pukul_waktu < waktu_selesai_istirahat){
		printf("\n");
		printf("\n");
		header();
		printf("| 3.  Tambah waktu                    |\n",durasi_simulasi);
	

		printf("\n\n");
	    printf("Masukkan Pilihan : ");
		scanf("%d", &pilihan);

		// SISTEM DIRECT TO PAGE BERKAITAN BERDASARKAN INPUTAN YANG DIPILIH OLEH USER
	    switch (pilihan) { 
			case 3:
				simulasi_waktu(); // PROSES UNTUK SIMULASI PENCUCIAN MOBIL DENGAN DURASI TERTENTU

				main_antrian(); // MODUL UTAMA
				
				break;

		 	default:
		 		salah_input_menu_antrian(); // REDIRECT KE salah_input_menu_antrian() UNTUK HANDLER PADA SAAT SALAH INPUT - LOKASI FILE : antrian.cpp
				break;
	    }
	}
	else{
		if((tempat_cuci_1 == NULL) && (tempat_cuci_2 == NULL)){
			printf("\n");
			printf("\n");
			header();
			printf("| 1.  Input Kendaraan                                   |\n");
			printf("| 2.  Lihat kendaraan yang sedang mengantri di tempat 1 |\n"); 
			printf("| 3.  Lihat kendaraan Yang sedang mengantri di tempat 2 |\n");
			printf("| 4.  Tambah waktu                                      |\n",durasi_simulasi);
			printf("| 5.  Cari plat nomor dalam antrian                     |\n");
			printf("| 6.  Cancel antrian                                    |\n");
			printf("| 7.  Selesai                                           |\n");
		

			printf("\n\n");
		    printf("Masukkan Pilihan : ");
			scanf("%d", &pilihan);

			// SISTEM DIRECT TO PAGE BERKAITAN BERDASARKAN INPUTAN YANG DIPILIH OLEH USER
		    switch (pilihan) { 
				case 1:
					input_kendaraan(); // MODUL UNTUK MENAMBAHKAN KENDARAAN YANG AKAN DI CUCI

					tombol_selanjutnya(); // MODUL UNTUK ALTERNATIF BY PASS

					main_antrian(); // MODUL UTAMA
					
					break;
					
				case 2:
					cek_tempat1_antrian(); // PROSES MENGELUARKAN KENDARAAN DARI ANTRIAN
					
					tombol_selanjutnya(); 
					

					main_antrian(); // MODUL UTAMA
					
					break;
					
				case 3:
					cek_tempat2_antrian(); // PROSES MENGELUARKAN KENDARAAN DARI ANTRIAN
					
					tombol_selanjutnya(); 
					

					main_antrian(); // MODUL UTAMA
					
					break;

			


				case 4:
				simulasi_waktu(); // PROSES UNTUK SIMULASI PENCUCIAN MOBIL DENGAN DURASI TERTENTU

					main_antrian(); // MODUL UTAMA

					break;
					
				case 5:
		         	cek(); // PROSES UNTUK SIMULASI PENCUCIAN MOBIL DENGAN DURASI TERTENTU
		         		tombol_selanjutnya(); 

					main_antrian(); // MODUL UTAMA
                           
					break;

				case 6:
					cancel_kendaraan(); // MENAMPILKAN SEMACAM PANDUAN APABILA ADA USER YANG KURANG FAMILIAR DENGAN APLIKASI
					
					tombol_selanjutnya(); // MODUL UNTUK ALTERNATIF BY PASS

					main_antrian(); // MODUL UTAMA
				

					break;
            	case 7:
                 	pil = cek_antrian();
					if(pil != 0){ // JIKA RETURN NILAI NYA ADALAH 0, MAKA ARTINYA SUDAH TIDAK ADA MOBIL YANG DI CUCI ATAU MENGANTRI
						printf("Masih ada antrian.\n");
						tombol_selanjutnya(); // MODUL UNTUK ALTERNATIF BY PASS

						main_antrian(); // MODUL UTAMA
						
						break;	
					}
					
					system("cls");
                   
					out();
					
					break;
			
			

			 	default:
			 		salah_input_menu_antrian(); // REDIRECT KE salah_input_menu_antrian() UNTUK HANDLER PADA SAAT SALAH INPUT - LOKASI FILE : antrian.cpp
					break;
		    }
		}
		else{
			printf("\n");
			printf("\n");
			header();
			printf("| 1.  Input Kendaraan                                   |\n");
			printf("| 2.  Lihat kendaraan yang sedang mengantri di tempat 1 |\n"); 
			printf("| 3.  Lihat kendaraan Yang sedang mengantri di tempat 2 |\n");
			printf("| 4.  Tambah waktu                                      |\n",durasi_simulasi);
			printf("| 5.  Cari plat nomor dalam antrian                     |\n");
    		printf("| 6.  Cancel antrian                                    |\n");
			printf("| 7.  Selesai                                           |\n");
		

			printf("\n\n");
		    printf("Masukkan Pilihan : ");
			scanf("%d", &pilihan);

			// SISTEM DIRECT TO PAGE BERKAITAN BERDASARKAN INPUTAN YANG DIPILIH OLEH USER
		    switch (pilihan) { 
				case 1:
					input_kendaraan(); // MODUL UNTUK MENAMBAHKAN KENDARAAN YANG AKAN DI CUCI

					tombol_selanjutnya(); // MODUL UNTUK ALTERNATIF BY PASS
					
					

					main_antrian(); // MODUL UTAMA
					
					break;
					
		    	case 2:
					cek_tempat1_antrian(); // PROSES MENGELUARKAN KENDARAAN DARI ANTRIAN
					
						tombol_selanjutnya();

					main_antrian(); // MODUL UTAMA
					
					break;
					
				case 3:
					cek_tempat2_antrian(); // PROSES MENGELUARKAN KENDARAAN DARI ANTRIAN
					
						tombol_selanjutnya();

					main_antrian(); // MODUL UTAMA
					
					break;


			

				case 4:
					simulasi_waktu(); // PROSES UNTUK SIMULASI PENCUCIAN MOBIL DENGAN DURASI TERTENTU

					main_antrian(); // MODUL UTAMA
					
					
					break;
					
				case 5:
					cek(); // PROSES MENGELUARKAN KENDARAAN DARI ANTRIAN
					
						tombol_selanjutnya();

					main_antrian(); // MODUL UTAMA
					
					break;

					
		    	case 6:
					cancel_kendaraan(); // PROSES UNTUK SIMULASI PENCUCIAN MOBIL DENGAN DURASI TERTENTU
			
					tombol_selanjutnya();

					main_antrian(); // MODUL UTAMA
					
					
					break;


				

				case 7:
					pil = cek_antrian();
					if(pil != 0){ // JIKA RETURN NILAI NYA ADALAH 0, MAKA ARTINYA SUDAH TIDAK ADA MOBIL YANG DI CUCI ATAU MENGANTRI
						printf("Masih ada mobil yang sedang dicuci! Tidak bisa keluar dari program.\n");
						tombol_selanjutnya(); // MODUL UNTUK ALTERNATIF BY PASS

						main_antrian(); // MODUL UTAMA
						
						break;	
					}
					
					system("cls");

					out(); // MODUL UNTUK MENAMPILKAN RINGKASAN TOTAL TRANSAKSI

					exit(1);	

					break;

			 	default:
			 		salah_input_menu_antrian(); // REDIRECT KE salah_input_menu_antrian() UNTUK HANDLER PADA SAAT SALAH INPUT - LOKASI FILE : antrian.cpp
					break;
		    }
		}
	}	    
}
// FUNCTION UTAMA UNTUK ANTRIAN DARI APLIKASI - END



// FUNCTION UNTUK MENAMPILKAN ALERT
void tombol_selanjutnya(){
	printf("\n");
	printf("Tekan Apapun Untuk Melanjutkan!");
	getch();
}
// FUNCTION UNTUK MENAMPILKAN ALERT



// FUNCTION UNTUK MENAMPILKAN SIMULASI ANTRIAN PADA TEMPAT CUCI MOBIL
void data_antrian(){
	// DEKLARASI VARIABEL LOKAL
	antrian_cuci *tempat1, *tempat2;

	printf("\n");
	printf("TEMPAT CUCI 1 ");

	if(tempat_cuci_1 == NULL){
		printf(" Kosong ");
	}else{
		tempat1 = tempat_cuci_1;
		printf(" %s   sisa : %d menit - datang : ",tempat1->nopol,tempat1->durasi);
		konversi_waktu_cuci(tempat1->waktu_in);
		printf(" - sedang proses : ");
		konversi_waktu_cuci(tempat1->waktu_proses);
		printf(" - selesai : ");
		konversi_waktu_cuci(tempat1->waktu_out);

		
	}
	
	printf("\n");
	printf("\n");
	printf("TEMPAT CUCI 2 ");

	if(tempat_cuci_2 == NULL){
		printf(" Kosong ");
	}else{
		tempat2 = tempat_cuci_2;
		printf(" %s  sisa : %d menit - Datang pada : ",tempat2->nopol,tempat2->durasi);
		konversi_waktu_cuci(tempat2->waktu_in);
		printf(" - sedang proses : ");
		konversi_waktu_cuci(tempat2->waktu_proses);
		printf(" - selesai : ");
		konversi_waktu_cuci(tempat2->waktu_out);
		

		
		}		
	}
	


// FUNCTION UNTUK MENAMPILKAN SIMULASI ANTRIAN PADA TEMPAT CUCI MOBIL - END



// FUNTION UNTUK KONVERSI WAKTU
void jam_waktu(){
	int j, m, d, detik;

	detik = pukul_waktu * 60;

	j = (detik / 3600) + 7; // TAMBAH 7 KARENA BUKA DARI JAM 7
	m = (detik % 3600/60);
	d = detik % 60;

	printf("Jam : %d:%d:%d \n", j, m, d);

}

void konversi_waktu_cuci(int menit_cuci){
	int j, m, d, detik;

	detik = menit_cuci * 60;

	j = (detik / 3600) + 7; // TAMBAH 7 KARENA BUKA DARI JAM 7
	m = (detik % 3600/60);
	d = detik % 60;

	printf("%d:%d:%d", j, m, d);

}
// FUNTION UNTUK KONVERSI WAKTU - END


void header(){
	printf("| --------    Silahkan Pilih Menu Dibawah :    -------- |\n");
}


// FUNCTION UNTUK ERROR HANDLING PADA INPUTAN PEMILIHAN MENU
int salah_input_menu_antrian(){
	printf("Maaf Inputan Salah\n");
	printf("Silahkan Tekan Enter Untuk Kembali...");
	getchar();

	// REDIRECT TO antrian.cpp
	system("cls");
	main_antrian(); // FILE : program.h --> antrian.cpp
}
// FUNCTION UNTUK ERROR HANDLING PADA INPUTAN PEMILIHAN MENU - END



// FUNCTION UNTUK INPUT DATA KENDARAAN
void input_kendaraan(){
	char no_plat[15];
	int cek, jenis, tanda_tempat;

	jenis = jenis_kendaraan();
	if(jenis == 0){ // JIKA INPUTAN ADALAH 0 MAKA AKAN DI ARAHKAN KEMBALI KE MAIN, DAN DI ANGGAP MEMBATALKAN PROSES INPUT DATA
		main_antrian(); // MODUL UTAMA
	}

	if(waktu_tutup < (pilihan_durasi[jenis-1] + pukul_waktu)){
		printf("Waktu tidak mencukupi dikarenakan sebentar lagi akan tutup");
		tombol_selanjutnya();
		main_antrian(); // MODUL UTAMA
	}

	if((waktu_mulai_istirahat < (pilihan_durasi[jenis-1] + pukul_waktu)) && (waktu_selesai_istirahat > (pilihan_durasi[jenis-1] + pukul_waktu))){
		printf("Waktu tidak mencukupi dikarenakan sebentar lagi akan beristirahat");
		tombol_selanjutnya();
		main_antrian(); // MODUL UTAMA
	}

	do{
		fflush(stdin);
		printf("\n");
		printf("Masukkan Nomor Polisi kendaraan : ");
		scanf("%[^\n]", &no_plat);
		fflush(stdin);

		cek = cek_nopol(no_plat, &tanda_tempat);
		if(cek != 0){ // JIKA CEK BERNILAI BUKAN 0 MAKA SUDAH ADA DATA KENDARAAN PADA TEMPAT CUCI ATAU PADA ANTRIAN
			printf("Nomor Polisi kendaraan sudah terdaftar! silahkan ganti.\n");
		}
	}while(cek != 0);
	
	pra_enqueue(no_plat, jenis); // PROSES SEBELUM DATA DI ENQUEUE KE LIST

	notifikasi_status(no_plat, jenis); // PROSES UNTUK MENGELUARKAN NOTIFIKASI
}



// FUNCTION UNTUK MENGELUARKAN KENDARAAN DARI ANTRIAN DALAM ARTIAN TIDAK JADI MENCUCI MOBIL
void cancel_kendaraan(){
	// DEKLARASI VARIABEL LOKAL
	int pil;
	char no_plat[15];
	int cek, tanda_tempat;

	pil = cek_antrian();
	if(pil == 0){ // JIKA RETURN NILAI NYA 0 MAKA LIST NYA SEDANG KOSONG
		printf("ERROR! antrian kosong.");
		tombol_selanjutnya();  // MODUL UNTUK ALTERNATIF BY PASS

		main_antrian(); // MODUL UTAMA
	}

	do{
		tanda_tempat = 0;

		fflush(stdin);
		printf("\n");
		printf("Masukkan Nomor Polisi kendaraan yang ingin dikeluarkan dari antrian : ");
		scanf("%[^\n]",&no_plat);
		fflush(stdin);

		if(no_plat[0]=='0'){  // Jika mengetik "0" Maka program akan di break
			break;
		}

		cek = cek_nopol(no_plat, &tanda_tempat);
		if(cek == 0){ // JIKA RETURN NILAINYA 0 ARTINYA TIDAK ADA KENDARAAN DENGAN NOPOL YANG DI INPUTKAN
			printf("Tidak ada Kendaraan dengan Nomor Polisi tersebut. silahkan isi kembali.\n");
		}
	}while(cek == 0);

	keluarkan(tanda_tempat,no_plat); // PROSES MENGELUARKAN KENDARAAN
}
// FUNCTION UNTUK MENGELUARKAN KENDARAAN DARI ANTRIAN DALAM ARTIAN TIDAK JADI MENCUCI MOBIL

void cek_tempat1_antrian() { //Operasi sama kaya comen di cek antrian 2
  antrian_cuci *tempat1;

	printf("TEMPAT CUCI 1 ");

	if(tempat_cuci_1 == NULL){
		printf(" Kosong ");
	}else{
		tempat1 = tempat_cuci_1;
		tempat1 = tempat1->next;
		while(tempat1 != NULL){
			printf("\n");
			printf("sedang mengantri %s (%d menit - datang pada : ",tempat1->nopol,tempat1->durasi);
			konversi_waktu_cuci(tempat1->waktu_in);
			printf(" ) ");
			tempat1 = tempat1->next;
		}		
	}
}

void cek_tempat2_antrian(){
	antrian_cuci  *tempat2; //POINTER TEMPAT CUCI 2 
	printf("TEMPAT CUCI 2 ");

	if(tempat_cuci_2 == NULL){ //JIKA SLOT VARIABLE TEMPAT_CUCI_2 NULL MAKA LIST ANTRIAN SLOT 2 KOSONG
		printf(" Kosong ");
	}else{
		tempat2 = tempat_cuci_2;
		tempat2 = tempat2->next; //NEXT LIST MENGANTRI KE PROSES 
		while(tempat2 != NULL){ //JIKA NULL MAKA OTOMATIS KENDARAAN YANG MENGANTRI PALING DEPAN MASUK KE ZONA PROSES CUCI 
			printf("\n");
			printf("sedang mengantri %s (%d menit - Datang pada : ",tempat2->nopol,tempat2->durasi); //INFORMASI LIST KENDARAAN YANG SEDANG NGANTRI
			konversi_waktu_cuci(tempat2->waktu_in); //INFORMASI LIST KENDARAAN YANG SEDANG NGANTRI
			printf(" ) ");
			tempat2 = tempat2->next;
		}		
	}
	
}

void Statistic() { //DALAM PENGEMBANGAN
  	
	
	printf("\n");
	printf("  Tempat cuci anda mencuci Mobil selama          : %d menit.\n",jumlah_waktu);
	printf("  Total Kendaraan yang telah selesai di cucu     : %d       \n",jumlah_kendaraan);
	printf("  Total Pemasukan Hari ini Tempat cuci anda      : Rp. %d \n",jumlah_harga);
}

void cek(){
	char no_plat[15];// DECLARE VARIABLE
	int cek, jenis, tanda_tempat; //DECLARE SCOPE

		fflush(stdin);
		printf("\n");
		printf("Masukkan Nomor Polisi kendaraan : ");
		scanf("%[^\n]", &no_plat);
			fflush(stdin);

		cek = cek_nopol(no_plat, &tanda_tempat);
		if(cek != 0){ // JIKA CEK BERNILAI  0 data ditemukan
			printf("Plat Nomor  ditemukan, sedang mengantri/Tahap proses.\n");
		}
	    if(cek != 1){ // JIKA CEK BERNILAI 1 Data belum ditemukan
			printf("Plat nomor  tidak ditemukan Atau sudah keluar.\n");
		}
	
	
}

// FUNCTION UNTUK CEK NOMOR POLISI KENDARAAN
int cek_nopol(char no_plat[], int *tanda_tempat){
	// DEKLARASI VARIABEL LOKAL
	antrian_cuci *tempat1, *tempat2;
	tempat1 = tempat_cuci_1;
	tempat2 = tempat_cuci_2;
	
	int cek = 0;

	if(tempat1 != NULL){
		while(tempat1 != NULL){
//			int compare_1 = strcmp(no_plat,tempat1->nopol); // CALLING STRINGCOMPARE() FUNCTION.  
			if(strcmp(no_plat,tempat1->nopol)==0){
				cek++;
				*tanda_tempat = 1; 
			}  
			// if(strcmp(no_plat,tempat1->nopol) == 0){
			// 	cek++;
			// 	*tanda_tempat = 1;	
			// }
			tempat1 = tempat1->next;
		}	
	}

	if(tempat2 != NULL){
		while(tempat2 != NULL){
//			int compare_2 = strcmp(no_plat,tempat2->nopol); // CALLING STRINGCOMPARE() FUNCTION.  
			if(strcmp(no_plat,tempat2->nopol)==0){
				cek++;
				*tanda_tempat = 2;
			}
			// if(strcmp(no_plat,tempat2->nopol) == 0){
			// 	cek++;
			// 	*tanda_tempat = 2;
			// }
			tempat2 = tempat2->next;
		}	
	}
	
	return cek;
}
// FUNCTION UNTUK CEK NOMOR POLISI KENDARAAN - END



// FUNCTION UNTUK MENAMPILKAN PILIHAN JENIS KENDARAAN
int jenis_kendaraan(){
	// DEKLARASI VARIABEL LOKAL
	int pilihan_jenis_kendaraan;
	printf("\n");
	printf("\n");
	printf("|===============================================================================|\n");
	printf("|                             JENIS KENDARAAN                                   |\n");
	printf("|===============================================================================|\n");
	printf("| NO | JENIS                                           |  DURASI  |    HARGA     |\n");
	printf("| 1. |   Mini car (Avanza,kayla,brio dll)              | %d menit |    Rp. %d    |\n",pilihan_durasi[0], pilihan_harga[0]);
	printf("| 2. |   SUV      (Innova,Fortuner,Pajero dll)         | %d menit |    Rp. %d    |\n",pilihan_durasi[1], pilihan_harga[1]);
	printf("| 3. |   Big  car (Bus,truck,container dll             | %d menit |    Rp. %d    |\n",pilihan_durasi[2], pilihan_harga[2]);
	printf("| 4. |   Roda Dua (Sepeda motor dll)                   | %d menit |    Rp. %d    |\n",pilihan_durasi[3], pilihan_harga[3]);
	
  
	do{
		printf("\n");
		printf("Pilih Jenis Kendaraan (1-4) : ");
		scanf("%d", &pilihan_jenis_kendaraan);

		if((pilihan_jenis_kendaraan < 0) || (pilihan_jenis_kendaraan > 4)){ // JIKA INPUTAN KURANG DARI 0 ATAU LEBIH DARI 3 MAKA KELUAR ALERT
			printf("Inputan Salah ! Pilihan diantara 1 - 3, silahkan input lagi.\n\n");
		}
	}while((pilihan_jenis_kendaraan < 0) || (pilihan_jenis_kendaraan > 4));

	return pilihan_jenis_kendaraan;
}
// FUNCTION UNTUK MENAMPILKAN PILIHAN JENIS KENDARAAN - END



// FUNCTION UNTUK PROSES MENGELUARKAN KENDARAAN BERDASARKAN TEMPAT CUCI
void keluarkan(int tanda_tempat, char no_plat[]){
	antrian_cuci *tempat1,*tempat2; 
	tempat1 = tempat_cuci_1;
	tempat2 = tempat_cuci_2;

	
	switch(tanda_tempat){
		case 1:
			keluar_kendaraan(no_plat,tempat1);
			break;

		case 2:
			keluar_kendaraan(no_plat,tempat2);
			break;	
	}
	tombol_selanjutnya(); // MODUL UNTUK ALTERNATIF BY PASS	
}
// FUNCTION UNTUK PROSES MENGELUARKAN KENDARAAN BERDASARKAN TEMPAT CUCI - END



// FUNTION UNTUK CEK ANTRIAN MOBIL
int cek_antrian(){
	// DEKLARASI VARIABEL LOKAL
	int cek;

	cek = 0;

	if(tempat_cuci_1 != NULL){
		cek++;	
	}

	if(tempat_cuci_2 != NULL){
		cek++;
	}

	return cek;
}
// FUNTION UNTUK CEK ANTRIAN MOBIL



// FUNCTION UNTUK PROSES MENGELUARKAN MOBIL DARI LIST / ANTRIAN
int keluar_kendaraan(char no_plat[], antrian_cuci *tempat){
	antrian_cuci *kendaraan_siap_keluar_antrian;

	if(strcmp(no_plat,tempat->nopol) == 0){ // JIKA RETURNNYA 0, ITU ARTINYA MOBIL SEDANG DICUCI, KARENA ITU ELEMEN PALING AWAL / KENDARAAN YANG MEMANG SEDANG DI CUCI
		printf("\n");
		printf("Kendaraan sedang dicuci! tunggu hingga selesai.\n");
	}else{
		while(strcmp(no_plat,tempat->next->nopol)!=0){ // PROSES PENCARIAN NOPOL YANG SAMA ANTARA INPUTAN DENGAN YANG ADA DI ANTRIAN
			tempat = tempat->next;
		}
		kendaraan_siap_keluar_antrian = tempat->next;
		tempat->next = tempat->next->next;
		free(kendaraan_siap_keluar_antrian);
	}
}
// FUNCTION UNTUK PROSES MENGELUARKAN MOBIL DARI LIST / ANTRIAN - END



// FUNTION UNTUK SKIP WAKTU SISTEM PENCUCIAN
void skip_waktu_berjalan(int m){
	pukul_waktu += m; // SKIP WAKTU BERJALAN SEBANYAK m MENIT
}
// FUNTION UNTUK SKIP WAKTU SISTEM PENCUCIAN - END



// FUNCTION UNTUK SIMULASI PENCUCIAN MOBIL DENGAN DURASI YANG SUDAH DI SET DI VARIABEL GLOBAL
void simulasi_waktu(){
	pukul_waktu += durasi_simulasi;

	if(tempat_cuci_1 != NULL){
		if(tempat_cuci_1->durasi != 0){ // CEK APAKAH DURASI DI 1 SUDAH 0 ATAU BELUM
			tempat_cuci_1->durasi -= durasi_simulasi;
		}

		if(tempat_cuci_1->durasi == 0){ // CEK APAKAH DURASI DI 1 SUDAH 0 ATAU BELUM
			if (tempat_cuci_2 != NULL){ // CEK APAKAH LIST 2 NULL ATAU TIDAK
				if (tempat_cuci_2->durasi >= durasi_jeda){ // CEK APAKAH DURASI DI 2 MASIH LEBIH DARI 5 ATAU TIDAK
					tempat_cuci_2->durasi -= durasi_jeda; // DURASI DI 2 DIKURANGIN 5 MENIT UNTUK JEDA KE PENCUCIAN SELANJUTNYA
				}
			}
		}
	}

	if(tempat_cuci_2 != NULL){
		if(tempat_cuci_2->durasi != 0){ // CEK APAKAH DURASI DI 2 SUDAH 0 ATAU BELUM
			tempat_cuci_2->durasi -= durasi_simulasi;
		}

		if(tempat_cuci_2->durasi == 0){ // CEK APAKAH DURASI DI 2 SUDAH 0 ATAU BELUM
			if (tempat_cuci_1 != NULL){ // CEK APAKAH LIST 1 NULL ATAU TIDAK
				if (tempat_cuci_1->durasi >= durasi_jeda){ // CEK APAKAH DURASI DI 1 MASIH LEBIH DARI 5 ATAU TIDAK
					tempat_cuci_1->durasi -= durasi_jeda; // DURASI DI 1 DIKURANGIN 5 MENIT UNTUK JEDA KE PENCUCIAN SELANJUTNYA
				}
			}
		}
	}

	if(((tempat_cuci_1 != NULL)&&(tempat_cuci_1->durasi == 0)) || ((tempat_cuci_2 != NULL)&&(tempat_cuci_2->durasi == 0))){
		pukul_waktu += durasi_jeda; // jeda 5 menit dari mobil 1 ke lainnya;
	}

	cek_sisawaktu_cuci();
}
// FUNCTION UNTUK SIMULASI PENCUCIAN MOBIL DENGAN DURASI YANG SUDAH DI SET DI VARIABEL GLOBAL




// FUNTION UNTUK CEK SISA WAKTU MENCUCI MOBIL
void cek_sisawaktu_cuci(){
	if(tempat_cuci_1 != NULL){
		if(tempat_cuci_1->durasi == 0){
			dequeue(0);

			if(tempat_cuci_1 != NULL){
				tempat_cuci_1->waktu_proses = pukul_waktu;
				tempat_cuci_1->waktu_out = pukul_waktu + tempat_cuci_1->durasi;
			}
		}
	}

	if(tempat_cuci_2 != NULL){
		if(tempat_cuci_2->durasi == 0){
			dequeue(1);

			if(tempat_cuci_2 != NULL){
				tempat_cuci_2->waktu_proses = pukul_waktu;
				tempat_cuci_2->waktu_out = pukul_waktu + tempat_cuci_2->durasi;
			}
		}
	}
}
// FUNTION UNTUK CEK SISA WAKTU MENCUCI MOBIL




// FUNCTION UNTUK DEQUE ATAU MENGHAPUS DATA DARI ANTRIAN (QUEUE)
void dequeue(int pilih){
	// DEKLARASI VARIABEL LOKAL
	antrian_cuci *tempat;

	switch(pilih){
		case 0:
			hitung_total(tempat_cuci_1->golongan);
			hitung_total_by_tempat_cuci(pilih, tempat_cuci_1->golongan);
			tempat = tempat_cuci_1;
			tampil_laporan_semua(tempat); // generate laporan
			tampil_laporan_semua_tempat_cuci_1(tempat);
			tempat_cuci_1 = tempat_cuci_1->next;
			free(tempat); // DI DEALOKASI
			break;

		case 1:
			hitung_total(tempat_cuci_2->golongan);
			hitung_total_by_tempat_cuci(pilih, tempat_cuci_2->golongan);
			tempat = tempat_cuci_2;
			tampil_laporan_semua(tempat); // generate laporan
			tampil_laporan_semua_tempat_cuci_2(tempat);
			tempat_cuci_2 = tempat_cuci_2->next;
			free(tempat); // DI DEALOKASI
			break;
	}
}
// FUNCTION UNTUK DEQUE ATAU MENGHAPUS DATA DARI ANTRIAN (QUEUE) - END



// FUNCTION UNTUK MENGHITUNG TOTAL KENDARAAN YANG SUDAH DI CUCI DAN JUGA TOTAL DURASI PENCUCIANNYA
void hitung_total(int pilih){
	switch(pilih){
		case 1:
			jumlah_kendaraan++;
			jumlah_waktu += pilihan_durasi[0];
			jumlah_harga += pilihan_harga[0];
			break;

		case 2:
			jumlah_kendaraan++;
			jumlah_waktu += pilihan_durasi[1];
			jumlah_harga += pilihan_harga[1];
			break;

		case 3:
			jumlah_kendaraan++;
			jumlah_waktu += pilihan_durasi[2];
			jumlah_harga += pilihan_harga[2];
			break;
		case 4:
			jumlah_kendaraan++;
			jumlah_waktu += pilihan_durasi[3];
			jumlah_harga += pilihan_harga[3];
			break;
	}
}
// FUNCTION UNTUK MENGHITUNG TOTAL KENDARAAN YANG SUDAH DI CUCI DAN JUGA TOTAL DURASI PENCUCIANNYA - END

// FUNCTION UNTUK MENGHITUNG TOTAL KENDARAAN YANG SUDAH DI CUCI DAN JUGA TOTAL DURASI PENCUCIANNYA BERDASARKAN TEMPAT CUCINYA
void hitung_total_by_tempat_cuci(int pilih_cuci, int pilih_golongan){
	switch(pilih_golongan){
		case 1:
			jumlah_kendaraan_by_tempat_cuci[pilih_cuci]++;
			jumlah_waktu_by_tempat_cuci[pilih_cuci] += pilihan_durasi[0];
			jumlah_harga_by_tempat_cuci[pilih_cuci] += pilihan_harga[0];
			break;

		case 2:
			jumlah_kendaraan_by_tempat_cuci[pilih_cuci]++;
			jumlah_waktu_by_tempat_cuci[pilih_cuci] += pilihan_durasi[1];
			jumlah_harga_by_tempat_cuci[pilih_cuci] += pilihan_harga[1];
			break;

		case 3:
			jumlah_kendaraan_by_tempat_cuci[pilih_cuci]++;
			jumlah_waktu_by_tempat_cuci[pilih_cuci] += pilihan_durasi[2];
			jumlah_harga_by_tempat_cuci[pilih_cuci] += pilihan_harga[2];
			break;
			
	   case 4:  
			jumlah_kendaraan_by_tempat_cuci[pilih_cuci]++;
			jumlah_waktu_by_tempat_cuci[pilih_cuci] += pilihan_durasi[3];
			jumlah_harga_by_tempat_cuci[pilih_cuci] += pilihan_harga[3];
			break;
	}
}
// FUNCTION UNTUK MENGHITUNG TOTAL KENDARAAN YANG SUDAH DI CUCI DAN JUGA TOTAL DURASI PENCUCIANNYA BERDASARKAN TEMPAT CUCINYA - END

// FUNCTION UNTUK PROSES PENGINPUTAN DATA KENDARAAN KE TEMPAT PENCUCIAN, DAN JUGA MEMILIH ANTARA TEMPAT CUCI 1 ATAU TEMPAT CUCI 2
void pra_enqueue(char no_plat[], int golongan){
	// DEKLARASI VARIABEL LOKAL
	int pilihan;
	antrian_cuci *data_inputan, *tempat;
	data_inputan = (antrian_cuci*)malloc(sizeof(antrian_cuci)); // ALOKASI VARIABEL
	
	if(data_inputan == NULL){ // JIKA VARIABEL data_inputan NULL, BERARTI TIDAK ADA 1 PUN ELEMEN DALAM LIST ATAU ALOKASI GAGAL DILAKUKAN, MAKA AKAN KELUAR ALERT
		printf("\n");
		printf("ERROR! Tidak tersedia memori\n");
	}else{
		strcpy(data_inputan->nopol,no_plat); // INPUT NOPOL KENDARAAN KE LIST BARU
		data_inputan->next = NULL; // LIST data_inputan->next MENUNJUK NULL

		switch(golongan){
			case 1:
				data_inputan->golongan = 1;
				data_inputan->durasi = pilihan_durasi[0];
				data_inputan->harga = pilihan_harga[0];
				data_inputan->waktu_in = pukul_waktu;
				break;

			case 2:
				data_inputan->golongan = 2;
				data_inputan->durasi = pilihan_durasi[1];
				data_inputan->harga = pilihan_harga[1];
				data_inputan->waktu_in = pukul_waktu;
				break;

			case 3:
				data_inputan->golongan = 3;
				data_inputan->durasi = pilihan_durasi[2];
				data_inputan->harga = pilihan_harga[2];	
				data_inputan->waktu_in = pukul_waktu;	
				break;
				
			case 4:
				data_inputan->golongan = 4;
				data_inputan->durasi = pilihan_durasi[3];
				data_inputan->harga = pilihan_harga[3];	
				data_inputan->waktu_in = pukul_waktu;	
				break;	
		}
	}
	
	hitung_durasi(); // PROSES PENGHITUNGAN DURASI PENCUCIAN MOBIL

	pilihan = pilih_tempat_cuci(); // PROSES PEMILIHAN TEMPAT CUCI BERDASARKAN DURASI TERPENDEK YANG AKAN SELESAI DARI PROSES PENCUCIAN
	switch(pilihan){
		case 0:
			tempat = tempat_cuci_1;
			enqueue_proses(data_inputan,tempat,pilihan);
			break;

		case 1:
			tempat = tempat_cuci_2;
			enqueue_proses(data_inputan,tempat,pilihan);
			break;
	}
}
// FUNCTION UNTUK PROSES PENGINPUTAN DATA KENDARAAN KE TEMPAT PENCUCIAN, DAN JUGA MEMILIH ANTARA TEMPAT CUCI 1 ATAU TEMPAT CUCI 2 - END



// FUNCTION UNTUK MENGHITUNG DURASI PENCUCIAN MOBIL
void hitung_durasi(){
	antrian_cuci *tempat1,*tempat2;
	tempat1 = tempat_cuci_1;
	tempat2 = tempat_cuci_2;
	
	jumlah_durasi[0] = 0;
	jumlah_durasi[1] = 0;
	jumlah_durasi[2] = 0;
	
	if(tempat_cuci_1 == NULL){
		jumlah_durasi[0] = 0;
	}else{
		while(tempat1 != NULL){
			jumlah_durasi[0] += tempat1->durasi;
			tempat1 = tempat1->next;
		}	
	}

	if(tempat_cuci_2 == NULL){
		jumlah_durasi[1] = 0;
	}else{
		while(tempat2 != NULL){
			jumlah_durasi[1] += tempat2->durasi;
			tempat2 = tempat2->next;
		}
	}
}
// FUNCTION UNTUK MENGHITUNG DURASI PENCUCIAN MOBIL - END


// FUNCTION UNTUK PROSES PENENTUAN TEMPAT CUCI MOBIL
int pilih_tempat_cuci(){
	int c, d, swap;
	int jumlah_durasi_asc[2];

	jumlah_durasi_asc[0] = jumlah_durasi[0];
	jumlah_durasi_asc[1] = jumlah_durasi[1];
	jumlah_durasi_asc[2] = jumlah_durasi[2];
	
        
	for (d = 0; d < 1; d++){            
  		if (jumlah_durasi_asc[d] > jumlah_durasi_asc[d+1]){
    		swap = jumlah_durasi_asc[d];
    		jumlah_durasi_asc[d] = jumlah_durasi_asc[d+1];
    		jumlah_durasi_asc[d+1] = swap;
  		}
	}

	for (c = 0; c < 2; c++){
    	if (jumlah_durasi[c] == jumlah_durasi_asc[0]){
        	break;
    	}
	}

	antrean = c;
  	return c;
}
// FUNCTION UNTUK PROSES PENENTUAN TEMPAT CUCI MOBIL



// FUNCTION UNTUK ENQUEUE DATA KE LIST
void enqueue_proses(antrian_cuci *data_inputan, antrian_cuci *tempat, int pilihan){
	// DEKLARASI VARIABEL
	antrian_cuci *data_inputan_langsung_cuci;

	data_inputan_langsung_cuci = data_inputan;
	data_inputan_langsung_cuci->waktu_proses = pukul_waktu;
	data_inputan_langsung_cuci->waktu_out = pukul_waktu + data_inputan->durasi;
	
	if(tempat == NULL){
		switch(pilihan){
		case 0:
			tempat_cuci_1 = data_inputan_langsung_cuci;
			break;
		case 1:
			tempat_cuci_2 = data_inputan_langsung_cuci;
			break;
		}
	}else{
		while(tempat->next != NULL){
			tempat = tempat->next;
		}
		data_inputan->next = NULL;
		tempat->next = data_inputan;		
	}	
}
// FUNCTION UNTUK ENQUEUE DATA KE LIST - END



// FUNCTION UNTUK PUSH NOTIFIKASI
void notifikasi_status(char no_plat[],int golongan){
	// DEKLARASI VARIABEL LOKAL
	int temp_waktu;

	printf("\n");
	printf("Mobil dengan Plat Nomor %s berhasil ditambahkan keantrian pada tempat cuci no - %d, perkiraan durasi pencucian",no_plat, antrean+1);

	switch(golongan){
		case 1:
			temp_waktu = pilihan_durasi[0];
			break;

		case 2:
			temp_waktu = pilihan_durasi[1];
			break;

		case 3:
			temp_waktu = pilihan_durasi[2];
			break;	
			
	    case 4:
			temp_waktu = pilihan_durasi[3];
			break;	
	}

	switch(antrean){
		case 0:
			printf(" %d menit dan durasi antri sekitar",temp_waktu);
			printf(" %d menit.\n",jumlah_durasi[0]);
			break;

		case 1:
			printf(" %d menit dan durasi antri sekitar",temp_waktu);
			printf(" %d menit.\n",jumlah_durasi[1]);
			break;
		
	}
}
// FUNCTION UNTUK PUSH NOTIFIKASI - END

// MODUL UNTUK EXPORT LAPORAN TRANSAKSI SEMUA DATA
void tampil_laporan_semua(antrian_cuci *tempat)
{
	char filename[255], baris[310];
	// antrian_cuci data_transaksi; // VARIABEL STRUCT
	FILE *f_txt; // VARIABEL FILE

      
	strcpy(filename, "main_data/laporan keseluruhan transaksi.txt");

	if (!(f_txt = fopen(filename, "a")))
	{
		system("cls");
		printf ("File %s tidak dapat diakses\n", filename); 
		printf("Silahkan tekan Enter untuk kembali ke halaman laporan transaksi...");
		getch();

     
		// REDIRECT KE main_antrian() UNTUK KEMBALI
		main_antrian();
	}

	// PROSES MEMASUKAN DATA KE CSV FILE
	int hitung_durasi_by_jenis; 
	hitung_durasi_by_jenis =  tempat->waktu_out - tempat->waktu_proses;
	sprintf(baris,"plat nomor :%s,jenis kendaraan :%d,durasi :%d Menit,harga :Rp.%d,datang :%d Menit setelah buka,proses :%d Menit,selesai:%d\n",tempat->nopol, tempat->golongan, hitung_durasi_by_jenis, tempat->harga, tempat->waktu_in, tempat->waktu_proses, tempat->waktu_out);
	printf("\n");
	fputs(baris,f_txt);
	
	fclose(f_txt);

}
// MODUL UNTUK EXPORT LAPORAN TRANSAKSI SEMUA DATA - END


// MODUL UNTUK EXPORT LAPORAN TRANSAKSI DATA ANTRIAN TEMPAT CUCI 1
void tampil_laporan_semua_tempat_cuci_1(antrian_cuci *tempat)
{
	char filename[255], baris[310];
	// antrian_cuci data_transaksi; // VARIABEL STRUCT
	FILE *f_txt; // VARIABEL FILE

	strcpy(filename, "main_data/Laporan akumulasi pemasukan tempat cuci 1.txt");

	if (!(f_txt = fopen(filename, "a")))
	{
		system("cls");
		printf ("File %s tidak dapat diakses\n", filename); 
		printf("Silahkan tekan Enter untuk kembali ke halaman laporan transaksi...");
		getch();

		// REDIRECT KE main_antrian() UNTUK KEMBALI
		main_antrian();
	}

	// PROSES MEMASUKAN DATA KE CSV FILE
	int hitung_durasi_by_jenis; 
	hitung_durasi_by_jenis =  tempat->waktu_out - tempat->waktu_proses;
	sprintf(baris,"plat nomor :%s,jenis kendaraan :%d,durasi :%d Menit,harga :Rp.%d,datang :%d Menit setelah buka,proses :%d menit,selesai:%d\n",tempat->nopol, tempat->golongan, hitung_durasi_by_jenis, tempat->harga, tempat->waktu_in, tempat->waktu_proses, tempat->waktu_out);
	printf("\n");
	fputs(baris,f_txt);
	
	fclose(f_txt);
	
}
// MODUL UNTUK EXPORT LAPORAN TRANSAKSI DATA ANTRIAN TEMPAT CUCI 1 - END


// MODUL UNTUK EXPORT LAPORAN TRANSAKSI DATA ANTRIAN TEMPAT CUCI 2
void tampil_laporan_semua_tempat_cuci_2(antrian_cuci *tempat)
{
	char filename[255], baris[310];
	// antrian_cuci data_transaksi; // VARIABEL STRUCT
	FILE *f_txt; // VARIABEL FILE

	strcpy(filename, "main_data/Laporan akumulasi pemasukan tempat cuci 2.txt");

	if (!(f_txt = fopen(filename, "a")))
	{
		system("cls");
		printf ("File %s tidak dapat diakses\n", filename); 
		printf("Silahkan tekan Enter untuk kembali ke halaman laporan transaksi...");
		getch();

		// REDIRECT KE main_antrian() UNTUK KEMBALI
		main_antrian();
	}

	// PROSES MEMASUKAN DATA KE CSV FILE
	int hitung_durasi_by_jenis; 
	hitung_durasi_by_jenis =  tempat->waktu_out - tempat->waktu_proses;
	sprintf(baris,"plat nomor :%s,jenis kendaraan :%d,durasi :%d Menit,harga :Rp.%d,datang :%d Menit setelah buka,proses :%d menit,selesai:%d\n",tempat->nopol, tempat->golongan, hitung_durasi_by_jenis, tempat->harga, tempat->waktu_in, tempat->waktu_proses, tempat->waktu_out);
	printf("\n");
	fputs(baris,f_txt);
	
	fclose(f_txt);
	
}
// MODUL UNTUK EXPORT LAPORAN TRANSAKSI DATA ANTRIAN TEMPAT CUCI 2 - END


// MODUL UNTUK MENAMPILKAN RINGKASAN TOTAL TRANSAKSI
void out()
{
	

	printf("\n");
	printf("  Terimakasih! Sampai Jumpa Kembali\n\n");



	exit(1);
}
// MODUL UNTUK MENAMPILKAN RINGKASAN TOTAL TRANSAKSI - END
