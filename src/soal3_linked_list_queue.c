/**
 * ============================================================================
 * Praktikum Struktur Data - SIA103
 * Topik        : Linked List Queue (Antrian Berbasis Senarai Berantai Dinamis)
 * Soal 3B      : Program Implementasi Queue Menggunakan Linked List
 * Nama         : Hellyos Ageng Haqiqie
 * NIM          : 163251001
 * Program Studi: S1 Teknik Robotika dan Kecerdasan Buatan
 * Fakultas     : Fakultas Teknologi Maju dan Multidisiplin, Universitas Airlangga
 * ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

/* Struktur Node untuk Linked List */
typedef struct Node {
    int data;
    struct Node* next;
} Node;

/* Struktur Queue berbasis Linked List */
typedef struct {
    Node* front; /* Penunjuk elemen terdepan antrian */
    Node* rear;  /* Penunjuk elemen paling belakang antrian */
    int count;   /* Jumlah elemen aktif */
} LinkedQueue;

LinkedQueue antrian;

/* Inisialisasi Queue kosong */
void InitQueue(LinkedQueue* q) {
    q->front = NULL;
    q->rear = NULL;
    q->count = 0;
}

/* Memeriksa apakah antrian kosong */
int IsEmpty(LinkedQueue* q) {
    return (q->front == NULL);
}

/* Menambahkan elemen baru di posisi belakang (Enqueue) */
void Enqueue(LinkedQueue* q, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("[ERROR] Alokasi memori gagal (Heap Overflow)! Tidak dapat menambahkan data %d.\n", data);
        return;
    }

    newNode->data = data;
    newNode->next = NULL;

    if (IsEmpty(q)) {
        /* Jika antrian masih kosong, node baru menjadi front sekaligus rear */
        q->front = newNode;
        q->rear = newNode;
    } else {
        /* Sambungkan rear saat ini ke node baru, lalu perbarui rear */
        q->rear->next = newNode;
        q->rear = newNode;
    }
    q->count++;

    printf("[SUKSES] Enqueue: Elemen %d berhasil ditambahkan pada alamat memori [%p]. Total elemen: %d.\n",
           data, (void*)newNode, q->count);
}

/* Mengambil dan menghapus elemen dari posisi depan (Dequeue) */
int Dequeue(LinkedQueue* q) {
    if (IsEmpty(q)) {
        printf("[PERINGATAN] Antrian Kosong (Underflow)! Tidak ada elemen yang dapat dikeluarkan.\n");
        return -1;
    }

    Node* temp = q->front;
    int dataKeluar = temp->data;

    /* Majukan pointer front ke node berikutnya */
    q->front = q->front->next;

    /* Jika setelah dihapus antrian menjadi kosong, setel rear ke NULL */
    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(temp); /* Bebaskan memori node yang dihapus */
    q->count--;

    printf("[SUKSES] Dequeue: Elemen %d berhasil dihapus dari depan antrian. Sisa elemen: %d.\n",
           dataKeluar, q->count);
    return dataKeluar;
}

/* Melihat elemen terdepan tanpa menghapusnya (Peek / Front) */
int Peek(LinkedQueue* q) {
    if (IsEmpty(q)) {
        printf("[INFO] Antrian kosong!\n");
        return -1;
    }
    return q->front->data;
}

/* Mengosongkan seluruh antrian dan mendealokasikan seluruh node memori */
void Clear(LinkedQueue* q) {
    Node* curr = q->front;
    while (curr != NULL) {
        Node* nextNode = curr->next;
        free(curr);
        curr = nextNode;
    }
    q->front = NULL;
    q->rear = NULL;
    q->count = 0;
    printf("[SUKSES] Seluruh node memori berhasil didealokasikan (Queue Clear).\n");
}

/* Menampilkan isi antrian beserta rantai pointer node */
void Tampil(LinkedQueue* q) {
    if (IsEmpty(q)) {
        printf("[INFO] Antrian kosong! Tidak ada data dalam Linked List.\n");
        return;
    }

    printf("\n=== STATUS LINKED LIST QUEUE ===\n");
    printf("Jumlah Elemen Aktif (Count) : %d node\n", q->count);
    printf("Alamat Node Front           : %p (Nilai: %d)\n", (void*)q->front, q->front->data);
    printf("Alamat Node Rear            : %p (Nilai: %d)\n", (void*)q->rear, q->rear->data);

    printf("\nAlur Rantai Antrian (FIFO):\n");
    printf("[FRONT] -> ");
    Node* curr = q->front;
    while (curr != NULL) {
        printf("[Data: %d | Next: %p]", curr->data, (void*)curr->next);
        if (curr->next != NULL) {
            printf(" -> ");
        }
        curr = curr->next;
    }
    printf(" -> NULL [REAR]\n\n");
}

int main(void) {
    int pilihan, nilai;
    InitQueue(&antrian);

    printf("========================================================\n");
    printf("   PROGRAM IMPLEMENTASI LINKED LIST QUEUE (SOAL 3B)    \n");
    printf("   Nama : Hellyos Ageng Haqiqie (NIM: 163251001)       \n");
    printf("   Prodi: S1 Teknik Robotika dan Kecerdasan Buatan      \n");
    printf("========================================================\n");

    do {
        printf("\n========================================================\n");
        printf("               MENU LINKED LIST QUEUE                   \n");
        printf("========================================================\n");
        printf(" 1. Tambah Elemen Baru (Enqueue)                       \n");
        printf(" 2. Ambil Elemen Terdepan (Dequeue)                    \n");
        printf(" 3. Lihat Elemen Terdepan (Peek)                       \n");
        printf(" 4. Tampilkan Seluruh Rantai Queue                     \n");
        printf(" 5. Kosongkan Seluruh Node (Clear)                     \n");
        printf(" 6. Keluar dari Program                                \n");
        printf("========================================================\n");
        printf("Pilihan Anda [1-6]: ");
        if (scanf("%d", &pilihan) != 1) {
            printf("[ERROR] Input tidak valid!\n");
            while (getchar() != '\n');
            continue;
        }

        switch (pilihan) {
            case 1:
                printf("Masukkan bilangan bulat untuk di-enqueue: ");
                if (scanf("%d", &nilai) == 1) {
                    Enqueue(&antrian, nilai);
                } else {
                    printf("[ERROR] Input tidak valid!\n");
                    while (getchar() != '\n');
                }
                break;
            case 2:
                Dequeue(&antrian);
                break;
            case 3:
                nilai = Peek(&antrian);
                if (nilai != -1) {
                    printf("\n[HASIL PEEK] Elemen terdepan adalah: %d\n", nilai);
                }
                break;
            case 4:
                Tampil(&antrian);
                break;
            case 5:
                Clear(&antrian);
                break;
            case 6:
                Clear(&antrian);
                printf("\nTerima kasih telah menggunakan program Linked List Queue. Selesai.\n");
                break;
            default:
                printf("[ERROR] Pilihan menu tidak valid! Silakan pilih 1 - 6.\n");
        }
    } while (pilihan != 6);

    return 0;
}
