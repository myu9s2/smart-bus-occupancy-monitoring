# Smart Bus Occupancy Monitoring System

## Deskripsi Proyek

Sistem Monitoring Keterdudukan Kursi Bus merupakan solusi berbasis Internet of Things (IoT) yang dirancang untuk memantau kondisi keterisian kursi bus secara real-time menggunakan ESP32 dan Blynk.

Sistem mampu mendeteksi kursi yang terisi maupun kosong, menghitung persentase okupansi, menampilkan jumlah kursi yang masih tersedia, serta memberikan peringatan ketika kapasitas bus mendekati penuh.

Proyek ini bertujuan untuk meningkatkan kenyamanan penumpang serta mendukung pengelolaan transportasi umum yang lebih cerdas melalui pemantauan secara real-time.

---

## Demo

Coba simulasi secara langsung:

**https://wokwi.com/projects/464832307027084289**

---

## Fitur Utama

### Monitoring Kursi Secara Real-Time

* Memantau 4 kursi bus secara bersamaan.
* Mendeteksi status kursi terisi atau kosong menggunakan sensor analog.

### Perhitungan Okupansi

* Menghitung jumlah kursi yang terisi.
* Menghitung jumlah kursi yang masih tersedia.
* Menampilkan persentase okupansi secara otomatis.

### Indikator Visual

* LED fisik untuk setiap kursi.
* LED indikator pada dashboard Blynk.

### Sistem Peringatan Otomatis

* Peringatan otomatis ketika okupansi mencapai 80% atau lebih.
* Buzzer aktif satu kali setiap terjadi kondisi peringatan.
* Pesan peringatan ditampilkan pada dashboard.

### Monitoring Jarak Jauh

* Memantau kondisi kursi melalui smartphone menggunakan aplikasi Blynk.
* Mengakses informasi kapasitas bus melalui koneksi internet.

---

## Teknologi yang Digunakan

### Perangkat Keras (Hardware)

* ESP32 DevKit V1
* 4 Sensor Kursi Analog (disimulasikan menggunakan potensiometer)
* 4 LED
* Buzzer
* Breadboard
* Kabel Jumper

### Perangkat Lunak (Software)

* Arduino IDE
* ESP32 Framework
* Platform Blynk IoT
* Simulator Wokwi

### Library

* Blynk
* WiFi
* BlynkTimer

---

## Arsitektur Sistem

```text
Sensor Kursi
      │
      ▼
ESP32
      │
      ▼
Pemrosesan Data Okupansi
      │
      ▼
Blynk Cloud
      │
      ▼
Dashboard Monitoring
```

Output tambahan:

* LED Fisik
* LED Dashboard Blynk
* Buzzer Peringatan

---

## Konfigurasi Pin

| Komponen       | Pin ESP32 |
| -------------- | --------- |
| Sensor Kursi 1 | GPIO 33   |
| Sensor Kursi 2 | GPIO 32   |
| Sensor Kursi 3 | GPIO 35   |
| Sensor Kursi 4 | GPIO 34   |
| LED Kursi 1    | GPIO 13   |
| LED Kursi 2    | GPIO 12   |
| LED Kursi 3    | GPIO 14   |
| LED Kursi 4    | GPIO 27   |
| Buzzer         | GPIO 26   |

---

## Mapping Dashboard Blynk

| Virtual Pin | Fungsi                   |
| ----------- | ------------------------ |
| V0          | Status Kursi 1           |
| V1          | Status Kursi 2           |
| V2          | Status Kursi 3           |
| V3          | Status Kursi 4           |
| V4          | Persentase Okupansi      |
| V5          | Status Peringatan        |
| V6          | Jumlah Kursi Tersedia    |
| V7          | Indikator Buzzer         |
| V8          | LED Ketersediaan Kursi 1 |
| V9          | LED Ketersediaan Kursi 2 |
| V10         | LED Ketersediaan Kursi 3 |
| V11         | LED Ketersediaan Kursi 4 |

---

## Cara Kerja Sistem

1. ESP32 membaca nilai analog dari sensor kursi.
2. Nilai sensor dibandingkan dengan nilai ambang batas (threshold).
3. Jika nilai melebihi threshold, kursi dianggap terisi.
4. LED kursi akan menyala sesuai status keterisian.
5. Status kursi dikirim ke dashboard Blynk.
6. Sistem menghitung persentase okupansi.
7. Sistem menghitung jumlah kursi yang masih tersedia.
8. Jika okupansi mencapai 80% atau lebih:

   * Pesan peringatan ditampilkan.
   * Buzzer aktif satu kali.
   * Indikator peringatan dinyalakan.
9. Data diperbarui secara otomatis setiap 500 ms.

---

## Hasil Implementasi

Sistem berhasil:

* Mendeteksi kursi yang terisi dan kosong secara real-time.
* Menghitung persentase okupansi secara otomatis.
* Menampilkan jumlah kursi yang masih tersedia.
* Mengirim data ke dashboard Blynk secara real-time.
* Mengaktifkan sistem peringatan ketika kapasitas bus hampir penuh.

---

## Pengembangan Selanjutnya

Beberapa pengembangan yang dapat dilakukan pada proyek ini:

* Mengganti potensiometer dengan sensor tekanan (FSR) yang sesungguhnya.
* Menambahkan fitur pelacakan lokasi bus menggunakan GPS.
* Menyimpan data ke database cloud.
* Mengembangkan prediksi okupansi menggunakan Machine Learning.
* Menambahkan dashboard analitik jumlah penumpang.
* Mengintegrasikan sistem dengan platform Smart Transportation.

---

## Kompetensi yang Ditunjukkan

* Internet of Things (IoT)
* Embedded Systems
* ESP32 Programming
* Sensor Integration
* Real-Time Monitoring System
* Cloud IoT Platform (Blynk)
* Dashboard Development
* System Architecture Design

---

## Author

**Mochammad Yuga Ranapraja**

Mahasiswa Informatika
Junior Data Science Intern at Vinix7
