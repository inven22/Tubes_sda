#ifndef queue_h
#define queue_h

#define MAX_USERNAME_LENGTH 50
#define MAX_PASSWORD_LENGTH 50
#define MAX_LINE_SIZE 256
#define MAX_LINE_LENGTH 1000
#define MAX_NUM_COLS 1000
#define MAX_NUM_ROWS 1000

// DEKLARASI VARIABEL GLOBAL
typedef struct antrian_cuci *address;
 struct antrian_cuci{
	char nopol[15];
	int golongan;
	int pil_jenis_cuci;
	int durasi;
	int harga;
//	int harga_cuci;
	int waktu_in;
//	int waktu_proses;
	int waktu_out;
	address next;
	
	 };
	
//typedef struct { char nopol[15];
//                 int golongan;
//				 int durasi;
//				 int harga;
//				 int waktu_in;
//				 int waktu_proses;
//				 int waktu_out; }  file; 
//    

	             
antrian_cuci *tempat_cuci_1 = NULL; // LIST MENUNJUK NULL
antrian_cuci *tempat_cuci_2 = NULL; // LIST MENUNJUK NULL

int jumlah_durasi[7]; // DURASI PADA SETIAP TEMPAT CUCI
int pilihan_durasi[8] = {80,120,40,160, 80,120,40,160}; // DURASI SESUAI JENIS MOBIL
int pilihan_harga[8] = {10000,30000,9000,50000, 10000,30000,9000,50000}; // HARGA SESUAI JENIS MOBIL
int pilihan_harga_cuci1[1] = {0};  //harga jenis cuci 1
int pilihan_harga_cuci2[1] = {1000};   //harga jenis cuci 2
int pilihan_harga_cuci3[1] = {20000};  //harga jenis cuci 3
int pilihan_durasi1[1] = {0};
int pilihan_durasi2[1] = {1};
//int pilihan_durasi3[1] = {1};
int durasi_simulasi = 10 ; // SIMULASI SKIP WAKTU DI SET 5 MENIT
int durasi_jeda = 0; // SIMULASI JEDA WAKTU DI SET 5 MENIT SETIAP SELESAI MENCUCI
int waktu_buka = 0; // DALAM MENIT 
int waktu_tutup = 600; // DALAM MENIT
int waktu_mulai_istirahat = 300; // DALAM MENIT
int waktu_selesai_istirahat = 359; // DALAM MENIT
int pukul_waktu; // JAM SEBAGAI PENGGANTI JAM REALTIME
int antrean; // TEMPAT CUCI
int jumlah_kendaraan; // JUMLAH TOTAL KENDARAAN YANG DI CUCI
int jumlah_waktu; // JUMLAH TOTAL WAKTU MENCUCI
int jumlah_harga; // JUMLAH TOTAL PEMASUKAN
int jumlah_kendaraan_by_tempat_cuci[2]; // JUMLAH TOTAL KENDARAAN YANG DI CUCI BERDASARKAN TEMPAT CUCI
int jumlah_waktu_by_tempat_cuci[2]; // JUMLAH TOTAL WAKTU MENCUCI BERDASARKAN TEMPAT CUCI
int jumlah_harga_by_tempat_cuci[2]; // JUMLAH TOTAL PEMASUKAN BERDASARKAN TEMPAT CUCI
// DEKLARASI VARIABEL GLOBAL - END

//DECLARE STRUKTUR DATA dan variabel ADMIN


// DEKLRASI MODUL
int main_antrian();
int home();
//int search();
void read_all();
void read_tempat1();
void read_tempat2();
void hapushistoriall();
void hapushistoritempat1();
void hapushistoritempat2();
void tombol_selanjutnya();
void tutup();
void header();
void cancel_kendaraan();
void data_antrian();
void jam_waktu();
void konversi_waktu_cuci(int menit_cuci);
void input_kendaraan();
void cek_tempat1_antrian();
void cek_tempat2_antrian();
void Statistic();
int cek_nopol(char no_plat[], int *tanda_tempat);
int jenis_kendaraan();
//int jenis_cuci();
void keluarkan(int tanda_tempat, char no_plat[]);
int cek_antrian();
int keluar_kendaraan(char no_plat[], struct antrian_cuci *tempat);
void skip_waktu_berjalan(int m);
void simulasi_waktu();
void cek();
void cek_sisawaktu_cuci();
void dequeue(int pilih);
void hitung_total(int pilih);
void hitung_total_by_tempat_cuci(int pilih_cuci, int pilih_golongan);
void pra_enqueue(char no_plat[],int golongan);
void hitung_durasi();
int pilih_tempat_cuci();
void enqueue_proses(struct antrian_cuci *data_inputan, struct antrian_cuci *tempat, int pilihan);
void notifikasi_status(char no_plat[], int golongan);

void tampil_laporan_semua(struct antrian_cuci *tempat);
void tampil_laporan_semua_tempat_cuci_1(antrian_cuci *tempat);
void tampil_laporan_semua_tempat_cuci_2(antrian_cuci *tempat);
void out(); // MODUL UNTUK MENAMPILKAN RINGKASAN TOTAL TRANSAKSI
// DEKLRASI MODUL - END

#endif
