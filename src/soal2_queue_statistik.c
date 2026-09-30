/**
 * ============================================================================
 * Praktikum Struktur Data - SIA103
 * Topik        : Queue (Antrian) - Linear Array dengan Operasi Statistik
 * Soal 2       : Perhitungan Nilai Total, Rata-rata, Terbesar, dan Terkecil
 *                dari Elemen-elemen Queue yang Telah Dibuat pada Soal 1
 * Nama         : Hellyos Ageng Haqiqie
 * NIM          : 163251001
 * Program Studi: S1 Teknik Robotika dan Kecerdasan Buatan
 * Fakultas     : Fakultas Teknologi Maju dan Multidisiplin, Universitas Airlangga
 * ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 8

typedef struct {
    int data[MAX];
    int head;
    int tail;
} Queue;

Queue antrian;

/* Inisialisasi antrian kosong */
void Create(void) {
    antrian.head = -1;
    antrian.tail = -1;
}

/* Memeriksa apakah antrian kosong */
int IsEmpty(void) {
    if (antrian.tail == -1) {
        return 1;
    }
    return 0;
}

/* Memeriksa apakah antrian penuh */
int IsFull(void) {
    if (antrian.tail >= MAX - 1) {
        return 1;
    }
    return 0;
}

/* Menambahkan elemen ke dalam antrian */
void Enqueue(int data) {
    if (IsFull() == 1) {
        printf("[PERINGATAN] Antrian Penuh (Overflow)! Tidak dapat menambahkan data %d.\n", data);
        return;
    }

    if (IsEmpty() == 1) {
        antrian.head = 0;
        antrian.tail = 0;
        antrian.data[antrian.tail] = data;
    } else {
        antrian.tail++;
        antrian.data[antrian.tail] = data;
    }
    printf("[SUKSES] Elemen %d berhasil masuk ke antrian (indeks: %d).\n", data, antrian.tail);
}

/* Mengambil dan menghapus elemen terdepan dari antrian */
int Dequeue(void) {
    if (IsEmpty() == 1) {
        printf("[PERINGATAN] Antrian Kosong (Underflow)! Tidak ada elemen yang dapat dikeluarkan.\n");
        return -1;
    }

    int elemenKeluar = antrian.data[antrian.head];

    /* Geser seluruh elemen ke arah depan */
    for (int i = antrian.head; i < antrian.tail; i++) {
        antrian.data[i] = antrian.data[i + 1];
    }
    antrian.tail--;

    /* Jika setelah digeser elemen menjadi habis, kembalikan ke kondisi awal */
    if (antrian.tail < 0) {
        antrian.head = -1;
        antrian.tail = -1;
    }

    printf("[SUKSES] Elemen %d berhasil dikeluarkan dari antrian.\n", elemenKeluar);
    return elemenKeluar;
}

/* Mengosongkan antrian */
void Clear(void) {
    antrian.head = -1;
    antrian.tail = -1;
    printf("[SUKSES] Seluruh isi antrian berhasil dibersihkan (Clear).\n");
}

/* Menampilkan seluruh elemen dalam antrian */
void Tampil(void) {
    if (IsEmpty() == 1) {
        printf("[INFO] Antrian kosong! Tidak ada data untuk ditampilkan.\n");
        return;
    }

    printf("\n=== STATUS ELEMEN ANTRIAN ===\n");
    printf("Kapasitas Array       : %d elemen\n", MAX);
    printf("Jumlah Elemen Aktif   : %d elemen\n", antrian.tail - antrian.head + 1);
    printf("Daftar Antrian (FIFO) : [FRONT] ");
    for (int i = antrian.head; i <= antrian.tail; i++) {
        printf("%d", antrian.data[i]);
        if (i < antrian.tail) {
            printf(" -> ");
        }
    }
    printf(" [REAR]\n");
}

/* ----------------------------------------------------------------------------
 * FUNGSI STATISTIK ELEMEN QUEUE (SOAL 2)
 * ---------------------------------------------------------------------------- */

/* Menghitung nilai total (penjumlahan) seluruh elemen di dalam queue */
long long HitungTotal(void) {
    if (IsEmpty() == 1) {
        return 0;
    }

    long long total = 0;
    for (int i = antrian.head; i <= antrian.tail; i++) {
        total += antrian.data[i];
    }
    return total;
}

/* Menghitung nilai rata-rata elemen di dalam queue */
double HitungRataRata(void) {
    if (IsEmpty() == 1) {
        return 0.0;
    }

    int jumlahElemen = antrian.tail - antrian.head + 1;
    long long total = HitungTotal();
    return (double)total / (double)jumlahElemen;
}

/* Mencari nilai terbesar (maksimum) di dalam queue */
int CariTerbesar(void) {
    if (IsEmpty() == 1) {
        printf("[PERINGATAN] Antrian kosong! Tidak dapat mencari nilai terbesar.\n");
        return INT_MIN;
    }

    int maxVal = antrian.data[antrian.head];
    for (int i = antrian.head + 1; i <= antrian.tail; i++) {
        if (antrian.data[i] > maxVal) {
            maxVal = antrian.data[i];
        }
    }
    return maxVal;
}

/* Mencari nilai terkecil (minimum) di dalam queue */
int CariTerkecil(void) {
    if (IsEmpty() == 1) {
        printf("[PERINGATAN] Antrian kosong! Tidak dapat mencari nilai terkecil.\n");
        return INT_MAX;
    }

    int minVal = antrian.data[antrian.head];
    for (int i = antrian.head + 1; i <= antrian.tail; i++) {
        if (antrian.data[i] < minVal) {
            minVal = antrian.data[i];
        }
    }
    return minVal;
}

/* Menampilkan ringkasan seluruh analisis statistik elemen antrian */
void TampilStatistik(void) {
    if (IsEmpty() == 1) {
        printf("\n[INFO] Antrian kosong! Tidak ada elemen untuk dianalisis statistiknya.\n");
        return;
    }

    int jumlahElemen = antrian.tail - antrian.head + 1;
    long long total = HitungTotal();
    double rataRata = HitungRataRata();
    int terbesar = CariTerbesar();
    int terkecil = CariTerkecil();

    printf("\n=======================================================\n");
    printf("        HASIL ANALISIS STATISTIK ELEMEN ANTRIAN        \n");
    printf("=======================================================\n");
    printf("  Jumlah Elemen (Count)     : %d elemen\n", jumlahElemen);
    printf("  Nilai Total (Sum)         : %lld\n", total);
    printf("  Nilai Rata-rata (Mean)    : %.4f\n", rataRata);
    printf("  Nilai Terbesar (Maximum)  : %d\n", terbesar);
    printf("  Nilai Terkecil (Minimum)  : %d\n", terkecil);
    printf("=======================================================\n\n");
}

int main(void) {
    int pilihan, nilai;
    Create();

    printf("========================================================\n");
    printf("   PROGRAM QUEUE DENGAN OPERASI STATISTIK (SOAL 2)     \n");
    printf("   Nama : Hellyos Ageng Haqiqie (NIM: 163251001)       \n");
    printf("   Prodi: S1 Teknik Robotika dan Kecerdasan Buatan      \n");
    printf("========================================================\n");

    do {
        printf("\n========================================================\n");
        printf("                       MENU UTAMA                       \n");
        printf("========================================================\n");
        printf(" 1. Masukkan Data ke Antrian (Enqueue)                 \n");
        printf(" 2. Hapus Data dari Antrian (Dequeue)                  \n");
        printf(" 3. Tampilkan Seluruh Data Antrian (Tampil)            \n");
        printf(" 4. Hitung & Tampilkan Analisis Statistik (Total/Rata) \n");
        printf(" 5. Cari Nilai Terbesar Saja (Maksimum)                \n");
        printf(" 6. Cari Nilai Terkecil Saja (Minimum)                 \n");
        printf(" 7. Bersihkan Seluruh Antrian (Clear)                  \n");
        printf(" 8. Keluar dari Program                                \n");
        printf("========================================================\n");
        printf("Pilihan Anda [1-8]: ");
        if (scanf("%d", &pilihan) != 1) {
            printf("[ERROR] Input tidak valid! Harap masukkan angka bulat.\n");
            while (getchar() != '\n');
            continue;
        }

        switch (pilihan) {
            case 1:
                printf("Masukkan bilangan bulat untuk ditambahkan: ");
                if (scanf("%d", &nilai) == 1) {
                    Enqueue(nilai);
                } else {
                    printf("[ERROR] Input tidak valid!\n");
                    while (getchar() != '\n');
                }
                break;
            case 2:
                Dequeue();
                break;
            case 3:
                Tampil();
                break;
            case 4:
                TampilStatistik();
                break;
            case 5:
                if (!IsEmpty()) {
                    printf("\n[HASIL] Nilai Terbesar (Maksimum) dalam antrian adalah: %d\n", CariTerbesar());
                } else {
                    printf("\n[INFO] Antrian kosong!\n");
                }
                break;
            case 6:
                if (!IsEmpty()) {
                    printf("\n[HASIL] Nilai Terkecil (Minimum) dalam antrian adalah: %d\n", CariTerkecil());
                } else {
                    printf("\n[INFO] Antrian kosong!\n");
                }
                break;
            case 7:
                Clear();
                break;
            case 8:
                printf("\nTerima kasih telah menggunakan program statistik antrian. Selesai.\n");
                break;
            default:
                printf("[ERROR] Pilihan menu tidak valid! Silakan masukkan opsi 1 - 8.\n");
        }
    } while (pilihan != 8);

    return 0;
}
