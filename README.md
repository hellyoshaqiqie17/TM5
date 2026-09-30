# Praktikum Struktur Data (SIA103) - Pertemuan 5 (TM 5)
## Topik: Struktur Data Antrian (Queue)

Repositori ini memuat berkas laporan akademik lengkap dalam format **LaTeX** (siap dikompilasi secara langsung di **Overleaf**), kode sumber implementasi dalam **Bahasa C**, skrip otomatisasi pengujian, serta gambar visualisasi arsitektur struktur data antrian (*Linear Array*, *Circular Array*, dan *Linked List*).

---

## 👤 Identitas Praktikan
* **Nama** : Hellyos Ageng Haqiqie
* **NIM** : 163251001
* **Program Studi**: S1 Teknik Robotika dan Kecerdasan Buatan
* **Fakultas** : Fakultas Teknologi Maju dan Multidisiplin (FTMM)
* **Perguruan Tinggi**: Universitas Airlangga
* **Dosen Pengampu**:
  - Purbandini, S.Si., M.Kom.
  - Rodik Wahyu Indrawan, S.ST., M.Tr.T.

---

## 📁 Struktur Berkas Repositori

```text
TM5/
├── main.tex                       # Berkas utama laporan akademik LaTeX (Overleaf Entry Point)
├── references.bib                 # Daftar pustaka standar BibTeX
├── README.md                      # Dokumentasi repositori dan panduan penggunaan
├── run_tests.py                   # Skrip otomatisasi pengujian kode sumber C
├── generate_diagrams.py           # Skrip generator ilustrasi dan diagram arsitektur
├── tugas_queue_overleaf.zip       # Arsip siap pakai untuk diunggah ke Overleaf
│
├── src/                           # Direktori kode sumber program Bahasa C
│   ├── soal1_queue_linear.c       # Program antrian linear array berbasis menu interaktif
│   ├── soal2_queue_statistik.c    # Program antrian dengan fungsi statistik (Sum, Mean, Max, Min)
│   ├── soal3_circular_queue.c     # Program antrian array melingkar (Circular Queue Modulo)
│   └── soal3_linked_list_queue.c  # Program antrian senarai berantai dinamis (Linked List)
│
├── images/                        # Direktori aset gambar & diagram resolusi tinggi
│   ├── logo_unair.png             # Logo resmi Universitas Airlangga untuk cover laporan
│   ├── queue_linear.png           # Visualisasi Linear Queue dan pergeseran elemen
│   ├── queue_circular.png         # Visualisasi Circular Queue dengan indeks modulo
│   ├── queue_linked_list.png      # Visualisasi Linked List Queue dan pointer node
│   └── queue_comparison.png      # Tabel grafis komparasi performa ketiga varian
│
└── output/                        # Hasil log pengujian eksekusi terminal riil
    ├── output_soal1.txt
    ├── output_soal2.txt
    ├── output_soal3_circular.txt
    └── output_soal3_linked_list.txt
```

---

## 📝 Ringkasan Pengerjaan Latihan Soal

### Soal 1: Program Menu Implementasi Linear Queue
* **File:** `src/soal1_queue_linear.c`
* **Deskripsi:** Mengimplementasikan antrian linier berbasis array statis (`MAX = 8`) dengan menu interaktif:
  1. *Enqueue* (Memasukkan data ke posisi belakang/tail).
  2. *Dequeue* (Mengeluarkan data terdepan/head dengan menggeser elemen berikutnya ke depan).
  3. *Tampil* (Menampilkan data terurut FIFO dan visualisasi slot memori).
  4. *Clear* (Mengosongkan antrian).
  5. *Keluar*.
* **Kompleksitas:** Enqueue $\mathcal{O}(1)$, Dequeue $\mathcal{O}(N)$ karena pergeseran elemen.

### Soal 2: Operasi Statistik Elemen Antrian
* **File:** `src/soal2_queue_statistik.c`
* **Deskripsi:** Menambahkan 4 fungsi statistik matematis pada antrian Soal 1:
  1. `HitungTotal()` : Menghitung jumlah total nilai elemen ($\sum X$).
  2. `HitungRataRata()` : Menghitung nilai mean ($\bar{X} = \frac{\sum X}{N}$).
  3. `CariTerbesar()` : Menemukan nilai ekstrem maksimum ($X_{\max}$).
  4. `CariTerkecil()` : Menemukan nilai ekstrem minimum ($X_{\min}$).
* **Uji Kasus:** Pada data $[45, 12, 88, 34, 91, 23, 70]$, Total = $363$, Rata-rata = $51.8571$, Max = $91$, Min = $12$. Hasil komputasi presisi $100\%$ terhadap verifikasi analitik manual.

### Soal 3A: Circular Array Queue
* **File:** `src/soal3_circular_queue.c`
* **Deskripsi:** Mengatasi inefisiensi pergeseran linier dengan menghubungkan ujung akhir kembali ke ujung awal menggunakan aritmatika modulo:
  $$\text{Next}(\text{index}) = (\text{index} + 1) \pmod{\text{MAX}}$$
* **Karakteristik:** Kapasitas efektif $\text{MAX} - 1 = 7$ elemen (sesuai modul perkuliahan). Operasi *Enqueue* dan *Dequeue* keduanya berjalan dalam waktu optimal $\mathcal{O}(1)$.

### Soal 3B: Linked List Queue
* **File:** `src/soal3_linked_list_queue.c`
* **Deskripsi:** Mengimplementasikan antrian dinamis menggunakan senarai berantai (*Singly Linked List*).
* **Karakteristik:** Menggunakan struktur `Node` dengan pointer `front` dan `rear`. Kapasitas tidak terbatas oleh ukuran array statis, memori dialokasikan secara dinamis (`malloc`) dan dibebaskan seketika saat di-*dequeue* (`free`) untuk mencegah kebocoran memori (*memory leak*).

---

## ⚡ Kompilasi dan Eksekusi Program C Secara Lokal

Pastikan compiler GCC (MinGW atau Linux GCC) telah terpasang di sistem Anda.

### Kompilasi Seluruh Program:
```bash
# Soal 1
gcc -Wall -Wextra -O2 src/soal1_queue_linear.c -o src/soal1.exe

# Soal 2
gcc -Wall -Wextra -O2 src/soal2_queue_statistik.c -o src/soal2.exe

# Soal 3A
gcc -Wall -Wextra -O2 src/soal3_circular_queue.c -o src/soal3_circular.exe

# Soal 3B
gcc -Wall -Wextra -O2 src/soal3_linked_list_queue.c -o src/soal3_linked_list.exe
```

### Menjalankan Program:
```bash
./src/soal1.exe
./src/soal2.exe
./src/soal3_circular.exe
./src/soal3_linked_list.exe
```

---

## 🚀 Panduan Membuka Dokumen di Overleaf

1. Unduh berkas **`tugas_queue_overleaf.zip`** dari repositori ini.
2. Buka [Overleaf](https://www.overleaf.com/) dan masuk ke akun Anda.
3. Klik tombol **New Project** $\to$ pilih **Upload Project**.
4. Unggah berkas `tugas_queue_overleaf.zip`.
5. Pastikan berkas `main.tex` terpilih, lalu klik **Recompile** (gunakan engine standar **pdfLaTeX**).
6. Dokumen PDF laporan akademik dengan tata letak profesional, logo UNAIR, visualisasi diagram, persamaan matematis, tabel komparasi, dan kode sumber C akan langsung ter-render dengan sempurna.

---

## 📊 Tabel Komparasi Kinerja Implementasi

| Parameter Evaluasi | Linear Array Queue | Circular Array Queue | Linked List Queue |
| :--- | :---: | :---: | :---: |
| **Kompleksitas Enqueue** | $\mathcal{O}(1)$ | $\mathcal{O}(1)$ | $\mathcal{O}(1)$ |
| **Kompleksitas Dequeue** | $\mathcal{O}(N)$ (pergeseran) | $\mathcal{O}(1)$ (modulo) | $\mathcal{O}(1)$ (re-link) |
| **Kapasitas** | Statis ($\text{MAX}$) | Statis ($\text{MAX} - 1$) | Dinamis (Batas RAM) |
| **Resiko False Overflow** | Ya (jika tanpa geser) | Tidak | Tidak |
| **Penggunaan Memori** | Paling hemat | Paling hemat | Tambahan pointer `next` |
| **Bidang Aplikasi Ideal** | Buffer sederhana | Sistem *Embedded* / Robotika | Sistem skala besar / dinamis |
