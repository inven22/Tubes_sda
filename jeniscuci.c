#include <stdio.h>

int main() {
char jenis_cuci[20];

printf("Pilih jenis cuci kendaraan: ");
scanf("%s", jenis_cuci);

if (strcmp(jenis_cuci, "cuci biasa") == 0) {
// proses cuci biasa
printf("Proses cuci biasa selesai.\n");
} else if (strcmp(jenis_cuci, "cuci express") == 0) {
// proses cuci express
printf("Proses cuci exspress selesai.\n");
} else if (strcmp(jenis_cuci, "cuci premium") == 0){
//proses cuci premium
printf("Proses cuci premium selesai.\n");
} else {
printf("Jenis cuci tidak tersedia.\n");
}

return 0;
}









