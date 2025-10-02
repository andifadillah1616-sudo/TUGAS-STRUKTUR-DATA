#include <iostream>
#include <string>

using namespace std;

struct Buku 
{
    int no_akses;
    string penulis;
    string judul;
    bool diterbitkan; 
};

int main() 
{
    const int MAX = 100; 
    Buku perpustakaan[MAX];
    int jumlah = 0; 
    int pilihan;

    do 
	{
        cout << "\n=== MENU PERPUSTAKAAN ===\n";
        cout << "1. Tambah Buku\n";
        cout << "2. Tampilkan Semua Buku\n";
        cout << "3. Keluar\n";
        cout << "Pilihan: ";
        cin >> pilihan;
        cin.ignore();

        switch (pilihan) 
		{
            case 1: {
                if (jumlah < MAX) 
				{
                    cout << "\nMasukkan data buku ke-" << (jumlah + 1) << endl;
                    cout << "Nomor Akses : ";
                    cin >> perpustakaan[jumlah].no_akses;
                    cin.ignore();
                    cout << "Nama Penulis: ";
                    getline(cin, perpustakaan[jumlah].penulis);
                    cout << "Judul Buku  : ";
                    getline(cin, perpustakaan[jumlah].judul);

                    char flag;
                    cout << "Apakah diterbitkan? (y/n): ";
                    cin >> flag;
                    perpustakaan[jumlah].diterbitkan = (flag == 'y' || flag == 'Y');

                    jumlah++;
                } else {
                    cout << "Kapasitas perpustakaan penuh!\n";
                }
                break;
            }
            case 2: {
                cout << "\n=== Daftar Buku ===\n";
                if (jumlah == 0) {
                    cout << "Belum ada buku yang tersimpan.\n";
                } else {
                    for (int i = 0; i < jumlah; i++) {
                        cout << "No Akses : " << perpustakaan[i].no_akses << endl;
                        cout << "Penulis  : " << perpustakaan[i].penulis << endl;
                        cout << "Judul    : " << perpustakaan[i].judul << endl;
                        cout << "Status   : " 
                             << (perpustakaan[i].diterbitkan ? "Diterbitkan" : "Belum Diterbitkan") 
                             << endl;
                        cout << "-----------------------------\n";
                    }
                }
                break;
            }
            case 3:
                cout << "Keluar dari program.\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 3);

    return 0;
}

