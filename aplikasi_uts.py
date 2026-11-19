def tampilkan_menu():
    print("\n=== KALKULATOR ===")
    print("1. Penjumlahan")
    print("2. Pengurangan")
    print("3. Perkalian")
    print("4. Pembagian")
    print("5. Pangkat")
    print("0. Keluar")


def tambah(a, b):
    return a + b


def kurang(a, b):
    return a - b


def kali(a, b):
    return a * b


def bagi(a, b):
    return a / b


def pangkat(basis, eksponen):
    hasil = 1.0
    for _ in range(eksponen):
        hasil *= basis
    return hasil


def main():
    hasil_terbesar = 0.0
    jumlah_operasi = 0

    while True:
        tampilkan_menu()
        try:
            pilihan = int(input("Pilih opsi (0-5): "))
        except ValueError:
            print("Masukkan angka saja!")
            continue

        if pilihan == 0:
            break
        if pilihan < 1 or pilihan > 5:
            print("Pilihan tidak valid!")
            continue

        try:
            if pilihan == 5:
                angka1 = float(input("Masukkan basis: "))
                n = int(input("Masukkan pangkat (bilangan bulat >= 0): "))
                if n < 0:
                    print("Pangkat tidak boleh negatif!")
                    continue
                hasil = pangkat(angka1, n)
            else:
                angka1 = float(input("Masukkan angka 1: "))
                angka2 = float(input("Masukkan angka 2: "))

                if pilihan == 1:
                    hasil = tambah(angka1, angka2)
                elif pilihan == 2:
                    hasil = kurang(angka1, angka2)
                elif pilihan == 3:
                    hasil = kali(angka1, angka2)
                else:
                    if angka2 == 0:
                        print("Tidak bisa dibagi dengan 0!")
                        continue
                    hasil = bagi(angka1, angka2)
        except ValueError:
            print("Input harus berupa angka!")
            continue

        print(f"Hasilnya adalah: {hasil:.2f}")

        jumlah_operasi += 1
        if jumlah_operasi == 1 or hasil > hasil_terbesar:
            hasil_terbesar = hasil

    if jumlah_operasi == 0:
        print("\nBelum ada perhitungan.")
    else:
        print(f"\nTerima kasih! Jumlah perhitungan: {jumlah_operasi}, hasil terbesar: {hasil_terbesar:.2f}")


if __name__ == "__main__":
    main()