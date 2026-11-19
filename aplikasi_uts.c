/* KALKULATOR MENU DENGAN FUNGSI */
#include <stdio.h>

// Deklarasi (Prototype) Fungsi
void tampilkanMenu();
double tambah(double a, double b);
double kurang(double a, double b);
double kali(double a, double b);
double bagi(double a, double b);
double pangkat(double basis, int eksponen);

int main() {
    int pilihan, n;
    double angka1, angka2, hasil;
    double hasilTerbesar = 0;
    int jumlahOperasi = 0;

    while (1) {
        tampilkanMenu();
        
        if (scanf("%d", &pilihan) != 1) {
            while (getchar() != '\n');
            printf("Masukkan angka saja!\n");
            continue;
        }

        if (pilihan == 0) {
            break;
        }
        if (pilihan < 1 || pilihan > 5) {
            printf("Pilihan tidak valid!\n");
            continue;
        }

        if (pilihan == 5) {
            printf("Masukkan basis: ");
            scanf("%lf", &angka1);
            printf("Masukkan pangkat (bilangan bulat >= 0): ");
            scanf("%d", &n);
            
            if (n < 0) {
                printf("Pangkat tidak boleh negatif!\n");
                continue;
            }
            hasil = pangkat(angka1, n);
        } else {
            printf("Masukkan angka 1: ");
            scanf("%lf", &angka1);
            printf("Masukkan angka 2: ");
            scanf("%lf", &angka2);

            if (pilihan == 1) {
                hasil = tambah(angka1, angka2);
            } else if (pilihan == 2) {
                hasil = kurang(angka1, angka2);
            } else if (pilihan == 3) {
                hasil = kali(angka1, angka2);
            } else {
                if (angka2 == 0) {
                    printf("Tidak bisa dibagi dengan 0!\n");
                    continue;
                }
                hasil = bagi(angka1, angka2);
            }
        }

        printf("Hasilnya adalah: %.2f\n", hasil);

        jumlahOperasi++;
        if (jumlahOperasi == 1 || hasil > hasilTerbesar) {
            hasilTerbesar = hasil;
        }
    }

    if (jumlahOperasi == 0) {
        printf("\nBelum ada perhitungan.\n");
    } else {
        printf("\nTerima kasih! Jumlah perhitungan: %d, hasil terbesar: %.2f\n",
               jumlahOperasi, hasilTerbesar);
    }
    return 0;
}

// Definisi Fungsi
void tampilkanMenu() {
    printf("\n=== KALKULATOR ===\n");
    printf("1. Penjumlahan\n");
    printf("2. Pengurangan\n");
    printf("3. Perkalian\n");
    printf("4. Pembagian\n");
    printf("5. Pangkat\n");
    printf("0. Keluar\n");
    printf("Pilih opsi (0-5): ");
}

double tambah(double a, double b) {
    return a + b;
}

double kurang(double a, double b) {
    return a - b;
}

double kali(double a, double b) {
    return a * b;
}

double bagi(double a, double b) {
    return a / b;
}

double pangkat(double basis, int eksponen) {
    double hasil = 1;
    for (int i = 1; i <= eksponen; i++) {
        hasil = hasil * basis;
    }
    return hasil;
}