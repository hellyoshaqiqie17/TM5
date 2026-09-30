/**
 * ============================================================================
 * Praktikum Struktur Data - SIA103
 * Topik        : Queue (Antrian) - Linear Array
 * Soal 1       : Program Menu Implementasi Antrian (Enqueue, Dequeue, Tampil, Exit)
 * Nama         : Hellyos Ageng Haqiqie
 * NIM          : 163251001
 * Program Studi: S1 Teknik Robotika dan Kecerdasan Buatan
 * Fakultas     : Fakultas Teknologi Maju dan Multidisiplin, Universitas Airlangga
 * ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

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
    printf("[SUKSES] Elemen %d berhasil masuk ke antrian (posisi indeks: %d).\n", data, antrian.tail);
}

/* Mengambil dan menghapus elemen terdepan dari antrian */
int Dequeue(void) {
    if (IsEmpty() == 1) {
        printf("[PERINGATAN] Antrian Kosong (Underflow)! Tidak ada elemen yang dapat dikeluarkan.\n");
        return -1;
    }

    int elemenKeluar = antrian.data[antrian.head];

    /* Geser seluruh elemen ke arah depan menggunakan looping */
    for (int i = antrian.head; i < antrian.tail; i++) {
        antrian.data[i] = antrian.data[i + 1];
    }
    antrian.tail--;

    /* Jika setelah digeser elemen menjadi habis, kembalikan ke kondisi awal */
    if (antrian.tail < 0) {
        antrian.head = -1;
        antrian.tail = -1;
    }

    printf("[SUKSES] Elemen %d berhasil keluar dari antrian.\n", elemenKeluar);
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

    printf("\n=== STATUS ELEMEN ANTRIAN (LINEAR ARRAY) ===\n");
    printf("Kapasitas Maksimum : %d elemen\n", MAX);
    printf("Jumlah Elemen Saat Ini: %d elemen\n", antrian.tail - antrian.head + 1);
    printf("Indeks Head (Depan)   : %d (Nilai: %d)\n", antrian.head, antrian.data[antrian.head]);
    printf("Indeks Tail (Belakang): %d (Nilai: %d)\n", antrian.tail, antrian.data[antrian.tail]);
    printf("Daftar Antrian: [FRONT] ");
    for (int i = antrian.head; i <= antrian.tail; i++) {
        printf("%d", antrian.data[i]);
        if (i < antrian.tail) {
            printf(" -> ");
        }
    }
    printf(" [REAR]\n");

    /* Tampilan visualisasi slot memori array */
    printf("Slot Memori Array:\n");
    printf("+-------");
    for (int i = 0; i < MAX; i++) printf("+-------");
    printf("+\n| Indeks");
    for (int i = 0; i < MAX; i++) printf("|  [%d]  ", i);
    printf("|\n+-------");
    for (int i = 0; i < MAX; i++) printf("+-------");
    printf("+\n| Nilai ");
    for (int i = 0; i < MAX; i++) {
        if (i >= antrian.head && i <= antrian.tail) {
            printf("| %5d ", antrian.data[i]);
        } else {
            printf("|   -   ");
        }
    }
    printf("|\n+-------");
    for (int i = 0; i < MAX; i++) printf("+-------");
    printf("+\n\n");
}

int main(void) {
    int pilihan, nilai;
    Create();

    printf("========================================================\n");
    printf("   PROGRAM IMPLEMENTASI QUEUE LINEAR ARRAY (SOAL 1)    \n");
    printf("   Nama : Hellyos Ageng Haqiqie (NIM: 163251001)       \n");
    printf("   Prodi: S1 Teknik Robotika dan Kecerdasan Buatan      \n");
    printf("========================================================\n");

    do {
        printf("\n========================================\n");
        printf("           MENU PILIHAN UTAMA           \n");
        printf("========================================\n");
        printf(" 1. Masukkan Data ke Antrian (Enqueue) \n");
        printf(" 2. Hapus Data dari Antrian (Dequeue)  \n");
        printf(" 3. Tampilkan Data Antrian (Tampil)    \n");
        printf(" 4. Bersihkan Seluruh Antrian (Clear)  \n");
        printf(" 5. Keluar dari Program                \n");
        printf("========================================\n");
        printf("Pilihan Anda [1-5]: ");
        if (scanf("%d", &pilihan) != 1) {
            printf("[ERROR] Input tidak valid! Harap masukkan angka.\n");
            while (getchar() != '\n'); // Bersihkan buffer
            continue;
        }

        switch (pilihan) {
            case 1:
                printf("Masukkan nilai bilangan bulat yang akan ditambahkan: ");
                if (scanf("%d", &nilai) == 1) {
                    Enqueue(nilai);
                } else {
                    printf("[ERROR] Input harus berupa bilangan bulat!\n");
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
                Clear();
                break;
            case 5:
                printf("\nTerima kasih telah menggunakan program antrian. Program selesai.\n");
                break;
            default:
                printf("[ERROR] Pilihan menu tidak valid! Silakan pilih antara 1 - 5.\n");
        }
    } while (pilihan != 5);

    return 0;
}
