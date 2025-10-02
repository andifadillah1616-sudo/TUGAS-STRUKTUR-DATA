#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Buku {
    string judul;
    string penulis;
    int jumlah;
};

vector<Buku> perpustakaan;

void tampilkanInfo() {
    if (perpustakaan.empty()) {
        cout << "Perpustakaan kosong.\n";
        return;
    }
    for (int i = 0; i < perpustakaan.size(); i++) {
        cout << i+1 << ". Judul: " << perpustakaan[i].judul
             << " | Penulis: " << perpustakaan[i].penulis
             << " | Jumlah: " << perpustakaan[i].jumlah << endl;
    }
}

void tambahBuku() {
    Buku b;
    cout << "Masukkan judul: "; getline(cin, b.judul);
    cout << "Masukkan penulis: "; getline(cin, b.penulis);
    cout << "Masukkan jumlah: "; cin >> b.jumlah;
    cin.ignore();
    perpustakaan.push_back(b);
    cout << "Buku berhasil ditambahkan!\n";
}

void tampilkanBukuPenulis() {
    string cari;
    cout << "Masukkan nama penulis: ";
    getline(cin, cari);
    bool ada = false;
    for (auto &b : perpustakaan) {
        if (b.penulis == cari) {
            cout << "Judul: " << b.judul << " | Jumlah: " << b.jumlah << endl;
            ada = true;
        }
    }
    if (!ada) cout << "Tidak ada buku dari penulis tersebut.\n";
}

void jumlahBukuJudul() {
    string cari;
    cout << "Masukkan judul buku: ";
    getline(cin, cari);
    int total = 0;
    for (auto &b : perpustakaan) {
        if (b.judul == cari) total += b.jumlah;
    }
    cout << "Jumlah buku dengan judul \"" << cari << "\": " << total << endl;
}

void totalBuku() {
    int total = 0;
    for (auto &b : perpustakaan) total += b.jumlah;
    cout << "Jumlah total buku di perpustakaan: " << total << endl;
}

void terbitkanBuku() {
    string cari;
    cout << "Masukkan judul buku yang akan diterbitkan: ";
    getline(cin, cari);
    for (auto &b : perpustakaan) {
        if (b.judul == cari) {
            if (b.jumlah > 0) {
                b.jumlah--;
                cout << "Buku \"" << b.judul << "\" berhasil diterbitkan. Sisa: " << b.jumlah << endl;
            } else {
                cout << "Stok buku habis!\n";
            }
            return;
        }
    }
    cout << "Buku tidak ditemukan.\n";
}

int main() {
    int pilihan;
    do {
        cout << "\n=== Menu Perpustakaan ===\n";
        cout << "1. Tampilkan informasi buku\n";
        cout << "2. Tambahkan buku baru\n";
        cout << "3. Tampilkan semua buku penulis tertentu\n";
        cout << "4. Tampilkan jumlah buku dengan judul tertentu\n";
        cout << "5. Tampilkan jumlah total buku\n";
        cout << "6. Terbitkan buku\n";
        cout << "0. Keluar\n";
        cout << "Pilihan: ";
        cin >> pilihan;
        cin.ignore();

        switch (pilihan) {
            case 1: tampilkanInfo(); break;
            case 2: tambahBuku(); break;
            case 3: tampilkanBukuPenulis(); break;
            case 4: jumlahBukuJudul(); break;
            case 5: totalBuku(); break;
            case 6: terbitkanBuku(); break;
            case 0: cout << "Keluar dari program.\n"; break;
            default: cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 0);

    return 0;
}

