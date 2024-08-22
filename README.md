# GOLDAR: Alat Pengecekan Golongan Darah Berbasis Arduino

## Deskripsi Umum

GOLDAR adalah sebuah alat inovatif untuk mengecek golongan darah menggunakan platform Arduino Mega. Alat ini dirancang untuk memberikan hasil yang akurat dan cepat dalam menentukan golongan darah seseorang. GOLDAR menggunakan sensor LDR (Light Dependent Resistor) untuk mendeteksi perubahan pada sampel darah, yang kemudian diproses untuk menentukan golongan darah.

Fitur utama GOLDAR meliputi:

- Penentuan golongan darah menggunakan sensor LDR
- Tampilan hasil melalui LCD TFT touchscreen
- Kemampuan mencetak hasil
- Pemberitahuan hasil melalui speaker
- Sistem mekanik menggunakan servo dan motor stepper untuk penanganan sampel

## Komponen Utama

1. Arduino Mega (sebagai mikrokontroler utama)
2. Sensor LDR (untuk mendeteksi golongan darah)
3. LCD TFT Touchscreen (sebagai antarmuka pengguna)
4. Mini DFPlayer (untuk output suara)
5. Servo 180 derajat (2 buah, untuk mekanisme pergerakan)
6. Motor Stepper 28BYJ-48 (untuk mekanisme pergerakan tambahan)
7. Printer (untuk mencetak hasil)

## Cara Kerja

GOLDAR bekerja dengan prinsip sebagai berikut:

1. Sampel darah ditempatkan pada area pengujian.
2. Sensor LDR mendeteksi perubahan pada sampel darah.
3. Arduino Mega memproses data dari sensor LDR.
4. Hasil analisis ditampilkan pada LCD TFT touchscreen.
5. Hasil juga diumumkan melalui speaker menggunakan Mini DFPlayer.
6. Pengguna dapat mencetak hasil menggunakan printer yang terhubung.
7. Servo dan motor stepper digunakan untuk menggerakkan komponen mekanis selama proses pengujian.
