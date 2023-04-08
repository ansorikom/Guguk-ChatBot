# Guguk ChatBot

## Deskripsi

Guguk ChatBot adalah chatbot sederhana berbasis konsol yang dibangun menggunakan API GPT-3 dari OpenAI. Chatbot menggunakan antrian pesan untuk mengelola masukan dan keluaran pengguna. Chatbot meminta masukan dari pengguna, mengirimkan masukan ke API GPT-3, dan kemudian menampilkan respons API kepada pengguna.

## Fitur

Guguk ChatBot memiliki beberapa fitur utama, antara lain:

- Mendukung conversational AI dengan menggunakan API dari OpenAI
- Memiliki message queue untuk menampung pesan yang masuk dari pengguna
- Mampu memproses dan merespon setiap pesan dengan cepat
- Dapat diintegrasikan dengan berbagai aplikasi lain yang memerlukan conversational AI

## Dependencies
- [C++ Compiler] (https://gcc.gnu.org/)
- [libcurl library] (https://curl.se/libcurl/)
- [JSON for Modern C++ library] (https://github.com/nlohmann/json)

## Cara Penggunaan

1. Pastikan komputer anda telah terinstall library curl dan json untuk C++. Jika belum, silahkan menginstall terlebih dahulu.

2. Buat akun OpenAI dan dapatkan API key-nya.

3. Clone repository ini ke dalam komputer anda.

```bash
git clone https://github.com/ansorikom/Guguk-ChatBot.git
```

4. Install Dependencies
- Install C++ compiler
- Install libcurl library
- Install JSON for Modern C++ library

5. Buka file `guguk.cpp` dan ganti nilai dari variabel `apiKey` dengan API key yang telah anda dapatkan.

6. Compile program menggunakan compiler C++ yang anda miliki.

```bash
g++ -std=c++11 -lcurl guguk.cpp -o guguk.exe
```
7. Jalankan program dan mulailah berinteraksi dengan Guguk ChatBot.

```bash
guguk.exe
```

8. Chatbot akan meminta Anda untuk memberikan masukan. Masukkan pesan Anda dan tekan enter untuk mengirimkannya ke API. Chatbot kemudian akan menampilkan respons dari API.

## Kontribusi

Jika anda ingin berkontribusi dalam pengembangan Guguk ChatBot, silahkan mengirimkan pull request pada repository ini.

## Lisensi

Guguk ChatBot dilisensikan di bawah lisensi MIT. Silahkan lihat file LICENSE untuk informasi lebih detail.
