/**
 * ============================================================================
 * Praktikum Struktur Data - SIA103
 * Topik        : Circular Queue (Antrian Berbasis Circular Array)
 * Soal 3A      : Program Implementasi Queue Menggunakan Circular Array
 * Nama         : Hellyos Ageng Haqiqie
 * NIM          : 163251001
 * Program Studi: S1 Teknik Robotika dan Kecerdasan Buatan
 * Fakultas     : Fakultas Teknologi Maju dan Multidisiplin, Universitas Airlangga
 * ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

/* Ukuran array fisik didefinisikan 8, sehingga kapasitas data efektif adalah 7 (MAX - 1) */
#define MAX 8

typedef struct {
    int data[MAX];
    int front; /* Menunjuk posisi sebelum elemen terdepan */
    int rear;  /* Menunjuk posisi elemen terakhir yang dimasukkan */
} CircularQueue;

CircularQueue q;

/* Inisialisasi Circular Queue (Sesuai Slide Teori: F = 0, R = 0) */
void Inisialisasi(void) {
    q.front = 0;
    q.rear = 0;
}

/* Memeriksa apakah Circular Queue kosong: F == R */
int IsEmpty(void) {
    return (q.front == q.rear);
}

/* Memeriksa apakah Circular Queue penuh: (R + 1) % MAX == F */
int IsFull(void) {
    return ((q.rear + 1) % MAX == q.front);
}

/* Menghitung jumlah elemen aktif dalam Circular Queue */
int Noel(void) {
    return (q.rear - q.front + MAX) % MAX;
}

/* Menambahkan elemen baru (Enqueue / INSERT) */
void Enqueue(int nilai) {
    if (IsFull()) {
        printf("[PERINGATAN] Circular Queue Penuh (OVERFLOW)! Kapasitas maksimum adalah %d elemen.\n", MAX - 1);
        printf("             Gagal menyisipkan nilai %d.\n", nilai);
        return;
    }

    q.rear = (q.rear + 1) % MAX;
    q.data[q.rear] = nilai;
    printf("[SUKSES] INSERT %d berhasil. Posisi Rear bergerak ke slot [%d]. Total elemen = %d.\n", 
           nilai, q.rear, Noel());
}

/* Menghapus elemen terdepan (Dequeue / REMOVE) */
int Dequeue(void) {
    if (IsEmpty()) {
        printf("[PERINGATAN] Circular Queue Kosong (UNDERFLOW)! Tidak ada elemen untuk diambil.\n");
        return -1;
    }

    q.front = (q.front + 1) % MAX;
    int nilaiKeluar = q.data[q.front];
    printf("[SUKSES] REMOVE berhasil. Elemen %d dikeluarkan. Posisi Front bergerak ke slot [%d]. Sisa elemen = %d.\n",
           nilaiKeluar, q.front, Noel());
    return nilaiKeluar;
}

/* Mengosongkan antrian */
void Clear(void) {
    q.front = 0;
    q.rear = 0;
    printf("[SUKSES] Circular Queue berhasil dikosongkan (F = 0, R = 0).\n");
}

/* Menampilkan isi Circular Queue serta visualisasi pemetaan indeks melingkar */
void Tampil(void) {
    if (IsEmpty()) {
        printf("[INFO] Circular Queue kosong (Front = %d, Rear = %d).\n", q.front, q.rear);
        return;
    }

    printf("\n=== STATUS CIRCULAR QUEUE ===\n");
    printf("Ukuran Array Fisik (MAX) : %d slot\n", MAX);
    printf("Kapasitas Maksimum Data  : %d elemen (MAX - 1)\n", MAX - 1);
    printf("Jumlah Elemen Aktif      : %d elemen\n", Noel());
    printf("Posisi Front             : %d\n", q.front);
    printf("Posisi Rear              : %d\n", q.rear);

    printf("Daftar Urutan Logis FIFO : [HEAD] ");
    int idx = (q.front + 1) % MAX;
    while (1) {
        printf("%d (slot [%d])", q.data[idx], idx);
        if (idx == q.rear) break;
        printf(" -> ");
        idx = (idx + 1) % MAX;
    }
    printf(" [TAIL]\n");

    /* Visualisasi Slot Array Fisik 0 s.d. MAX - 1 */
    printf("\nVisualisasi Memori Array Fisik:\n");
    printf("+-------");
    for (int i = 0; i < MAX; i++) printf("+-------");
    printf("+\n| Indeks");
    for (int i = 0; i < MAX; i++) printf("|  [%d]  ", i);
    printf("|\n+-------");
    for (int i = 0; i < MAX; i++) printf("+-------");
    printf("+\n| Nilai ");
    for (int i = 0; i < MAX; i++) {
        /* Cek apakah slot i merupakan bagian dari data aktif */
        int isActive = 0;
        if (!IsEmpty()) {
            if (q.front < q.rear) {
                if (i > q.front && i <= q.rear) isActive = 1;
            } else {
                if (i > q.front || i <= q.rear) isActive = 1;
            }
        }
        if (isActive) {
            printf("| %5d ", q.data[i]);
        } else {
            printf("|   -   ");
        }
    }
    printf("|\n+-------");
    for (int i = 0; i < MAX; i++) printf("+-------");
    printf("+\n| Info  ");
    for (int i = 0; i < MAX; i++) {
        if (i == q.front && i == q.rear) {
            printf("|  F,R  ");
        } else if (i == q.front) {
            printf("|   F   ");
        } else if (i == q.rear) {
            printf("|   R   ");
        } else {
            printf("|       ");
        }
    }
    printf("|\n+-------");
    for (int i = 0; i < MAX; i++) printf("+-------");
    printf("+\n\n");
}

int main(void) {
    int pilihan, nilai;
    Inisialisasi();

    printf("========================================================\n");
    printf("   PROGRAM IMPLEMENTASI CIRCULAR QUEUE (SOAL 3A)       \n");
    printf("   Nama : Hellyos Ageng Haqiqie (NIM: 163251001)       \n");
    printf("   Prodi: S1 Teknik Robotika dan Kecerdasan Buatan      \n");
    printf("========================================================\n");

    do {
        printf("\n========================================================\n");
        printf("                 MENU PILIHAN CIRCULAR QUEUE            \n");
        printf("========================================================\n");
        printf(" 1. Sisipkan Elemen (Enqueue / INSERT)                 \n");
        printf(" 2. Ambil Elemen Terdepan (Dequeue / REMOVE)            \n");
        printf(" 3. Tampilkan Status & Visualisasi Array Melingkar     \n");
        printf(" 4. Cek Kondisi (IsEmpty / IsFull / Noel)              \n");
        printf(" 5. Bersihkan Antrian (Clear / RESET)                  \n");
        printf(" 6. Keluar                                             \n");
        printf("========================================================\n");
        printf("Pilihan Anda [1-6]: ");
        if (scanf("%d", &pilihan) != 1) {
            printf("[ERROR] Input tidak valid!\n");
            while (getchar() != '\n');
            continue;
        }

        switch (pilihan) {
            case 1:
                printf("Masukkan bilangan bulat untuk di-insert: ");
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
                printf("\n--- STATUS KONDISI ANTRIAN ---\n");
                printf("IsEmpty (Kosong) : %s\n", IsEmpty() ? "YA (True)" : "TIDAK (False)");
                printf("IsFull (Penuh)   : %s\n", IsFull() ? "YA (True)" : "TIDAK (False)");
                printf("Jumlah Elemen    : %d / %d\n", Noel(), MAX - 1);
                break;
            case 5:
                Clear();
                break;
            case 6:
                printf("\nTerima kasih telah menggunakan program Circular Queue. Selesai.\n");
                break;
            default:
                printf("[ERROR] Pilihan menu tidak valid! Silakan pilih 1 - 6.\n");
        }
    } while (pilihan != 6);

    return 0;
}
