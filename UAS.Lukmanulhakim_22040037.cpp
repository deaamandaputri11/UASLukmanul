/*
========================
NAMA	: Lukmanul hakim
KELAS	: 2B
NIM		: 22040037
JUDUL	: kasir apotek
========================
*/




#include <iostream>
#include <string>
#include <algorithm>
#include <windows.h>
#include <iomanip> // Required for setw() function

using namespace std;

void cls() {
	system("cls");
}
void gotoXY(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

struct Produk {
    string nama;
    int harga;
    string kode;
};

void tambahProduk(Produk dataProduk[], int& jumlahProduk) {
    Produk barang;

    gotoXY(3, 1);
    
    cout << "Masukkan nama obat: ";
    cin.ignore();
    getline(cin, barang.nama);

    gotoXY(3, 2);
    
    cout << "Masukkan harga obat: ";
    cin >> barang.harga;

    cin.ignore(); // Membersihkan karakter newline sebelum mengambil input kode obat

    gotoXY(3, 3);
    
    cout << "Masukkan kode obat: ";
    getline(cin, barang.kode);

    dataProduk[jumlahProduk] = barang;
    jumlahProduk++;

    gotoXY(3, 5);
    
    cout << "Produk obat berhasil ditambahkan!" << endl;
    gotoXY(3, 7);system("pause");
    
//    break;
    
}

void tampilkanDaftarObat(Produk dataProduk[], int jumlahProduk) {
	
    gotoXY(3, 1);cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
    gotoXY(3, 2);cout << "| No |       Nama       |     Harga    |   Kode Obat   |" << endl;
    gotoXY(3, 3);cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
    for (int i = 0; i < jumlahProduk; i++) {
        gotoXY(3, 4 + i);
        cout << "| " << i + 1 << "  | ";
        cout << setw(16) << left << dataProduk[i].nama << " | ";
        cout << setw(12) << right << dataProduk[i].harga << " | ";
        cout << setw(13) << right << dataProduk[i].kode << " | " << endl;
    }
    gotoXY(3, 10);cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
}

bool compareProduk(const Produk& a, const Produk& b) {
    return a.harga < b.harga;
}

void bubbleSortProduk(Produk dataProduk[], int jumlahProduk) {
    for (int i = 0; i < jumlahProduk - 1; i++) {
        for (int j = 0; j < jumlahProduk - i - 1; j++) {
            if (dataProduk[j].harga > dataProduk[j + 1].harga) {
                swap(dataProduk[j], dataProduk[j + 1]);
            }
        }
    }

    gotoXY(3, 10);
    cout << "Produk berhasil diurutkan berdasarkan harga!" << endl;
}

void cariProduk(Produk dataProduk[], int jumlahProduk, const string& keyword) {
    bool found = false;

    gotoXY(3, 7);
    cout << "Hasil Pencarian untuk keyword '" << keyword << "':" << endl;

    for (int i = 0; i < jumlahProduk; i++) {
        if (dataProduk[i].nama.find(keyword) != string::npos) {
            gotoXY(3, 8 + i);
            cout << "Nama: " << dataProduk[i].nama << ", Harga: " << dataProduk[i].harga << ", Kode: " << dataProduk[i].kode << endl;
            found = true;
            gotoXY(3, 12);system("pause"); 
			break;          
        }
        
    }

    if (!found) {
        gotoXY(3, 10);
        cout << "Produk tidak ditemukan." << endl;
        gotoXY(3, 15);system("pause");
    }
}

void tampilkanResumeTransaksi(Produk dataProduk[], int jumlahProduk)
{
	
    int subtotal = 0;
    int total = 0;
    gotoXY(3, 2);cout << "++++++++++++++++++++++++++++++++++++++" << endl;
    gotoXY(3, 3);cout << "| No |       Nama       | 	Harga 	|" << endl;
    gotoXY(3, 4);cout << "++++++++++++++++++++++++++++++++++++++" << endl;
    for (int i = 0; i < jumlahProduk; i++) {
        gotoXY(3, 5 + i);
        cout << "| " << i + 1 << "  | ";
        cout << setw(16) << left << dataProduk[i].nama << " | ";
        cout << setw(10) << right << dataProduk[i].harga << " |" << endl;

        subtotal += dataProduk[i].harga;
    }
    gotoXY(3, 11);cout << "++++++++++++++++++++++++++++++++++++++" << endl;

    total = subtotal;

    gotoXY(3, 16 + jumlahProduk);
    gotoXY(3, 17);cout << "Subtotal: " << subtotal << endl;
    gotoXY(3, 18 + jumlahProduk);
    gotoXY(3, 19);cout << "Total   : " << total << endl;
    gotoXY(3, 22);system("pause");
}


//void continue() {
//	system("");
//}

int main() {
    const int MAX_PRODUK = 100;
    Produk dataProduk[MAX_PRODUK];
    int jumlahProduk = 0;
    int pilihan;
    string nama, kelas;
    int nim;

    gotoXY(0, 0);
    cout << "Masukkan NIM: ";
    cin >> nim;
    cin.ignore();
    gotoXY(0, 1);
    cout << "Masukkan Nama: ";
    getline(cin, nama);
    gotoXY(0, 2);
    cout << "Masukkan Kelas: ";
    getline(cin, kelas);
    
    cls();

   	gotoXY(17, 1);cout << "++++++++++++++++++++++++++[ PROGRAM KASIR APOTEK ]+++++++++++++++++++++++++++\n";
    gotoXY(17, 2);cout << "|         NIM        |            NAMA            |           KELAS         |\n";
    gotoXY(17, 3);cout << "+===========================================================================+\n";
    gotoXY(17, 4);cout << "|      " << nim << "      |     " << nama << "         |   	      " << kelas << "	     |\n";
    gotoXY(17, 5);cout << "+===========================================================================+\n\n";
	gotoXY(17, 10);system("pause");
    do {
	system("cls");
		gotoXY(3, 1);cout << "=== Program kasir apotek ===" << endl;
        gotoXY(3, 2);cout << "1. Tambah obat" << endl; 
        gotoXY(3, 3);cout << "2. Tampilkan obat" << endl;
        gotoXY(3, 4);cout << "3. Urutkan obat berdasarkan harga (Bubble Sort)" << endl;
        gotoXY(3, 5);cout << "4. Cari obat" << endl;
        gotoXY(3, 6);cout << "5. Tampilkan resume transaksi" << endl;
        gotoXY(3, 7);cout << "6. Keluar" << endl;
        gotoXY(3, 9);cout << "Pilihan Anda: ";
        cin >> pilihan;
        cls();

		switch (pilihan) {
             break;
			 case 1:
            	
               tambahProduk(dataProduk, jumlahProduk);
                cls();
                break;
             case 2:
             	
               tampilkanDaftarObat(dataProduk, jumlahProduk);
                gotoXY(3, 12);system("pause");
                cls();
                break;
             case 3:
             
               bubbleSortProduk(dataProduk, jumlahProduk);
                tampilkanDaftarObat(dataProduk, jumlahProduk); // Tampilkan daftar obat setelah diurutkan
                gotoXY(3, 12);system("pause");
                break;
            case 4:
                {
                    cin.ignore(); // Clear the input buffer
                    gotoXY(3, 1);
                    cout << "Masukkan keyword pencarian: ";
                    string keyword;
                    getline(cin, keyword);
                    cariProduk(dataProduk, jumlahProduk, keyword);
                    cls();
                    break;
                }
            case 5:
                tampilkanResumeTransaksi(dataProduk, jumlahProduk);
                cls();
                break;
            case 6:
                cout << "Terima kasih telah menggunakan program ini!" << endl;
                cls();
                break;
            default:
				cout << "Pilihan tidak valid!" << endl;
                cls();
                break;
        }

        cout << endl;
    }while (pilihan != 6);
    
    gotoXY(17, 1);cout << "++++++++++++++++++++++++++[ PROGRAM KASIR APOTEK ]+++++++++++++++++++++++++++\n";
    gotoXY(17, 2);cout << "|         NIM        |            NAMA            |           KELAS         |\n";
    gotoXY(17, 3);cout << "+===========================================================================+\n";
    gotoXY(17, 4);cout << "|      " << nim << "      |     " << nama << "         |   	      " << kelas << "	     |\n";
    gotoXY(17, 5);cout << "+===========================================================================+\n\n";
    
    return 0;
}

