#include <iostream>
using namespace std;
#define MAX_GUNPLA 100

struct Gunpla {
    string nama;
    string seri;
    string status;
};

void tampilkanKoleksi(Gunpla* koleksi, int jumlah) {
    if (jumlah == 0) {
        cout << "Belum ada Gunpla dalam koleksi." << endl;
    } else {
        for (int i = 0; i < jumlah; i++) {
            cout << "Gunpla ke-" << i + 1 << ": " << (koleksi + i)->nama
                 << " - " << (koleksi + i)->seri
                 << " (" << (koleksi + i)->status << ")" << endl;
        }
    }
}

void tambahKoleksi(Gunpla* koleksi, int* jumlah) {
    if (*jumlah < MAX_GUNPLA) {
        cout << "Masukkan nama Gunpla: ";
        cin.ignore();
        getline(cin, (koleksi + *jumlah)->nama);
        cout << "Masukkan seri Gunpla: ";
        getline(cin, (koleksi + *jumlah)->seri);
        cout << "Masukkan status Gunpla (dirakit/belum dirakit/second): ";
        getline(cin, (koleksi + *jumlah)->status);
        (*jumlah)++; 
        cout << "Gunpla berhasil ditambahkan." << endl;
    } else {
        cout << "Koleksi penuh! Tidak bisa menambah Gunpla lagi." << endl;
    }
}

void ubahStatusGunpla(Gunpla* koleksi, int jumlah) {
    if (jumlah == 0) {
        cout << "Belum ada Gunpla untuk diubah." << endl;
    } else {
        tampilkanKoleksi(koleksi, jumlah);
        int index;
        cout << "Masukkan nomor Gunpla yang akan diubah: ";
        cin >> index;
        if (index > 0 && index <= jumlah) {
            cout << "Masukkan status baru: ";
            cin.ignore();
            getline(cin, (koleksi + index - 1)->status);
            cout << "Status Gunpla berhasil diubah." << endl;
        } else {
            cout << "Nomor Gunpla tidak valid." << endl;
        }
    }
}

void hapusGunpla(Gunpla* koleksi, int* jumlah) {
    if (*jumlah == 0) {
        cout << "Belum ada Gunpla untuk dihapus." << endl;
    } else {
        tampilkanKoleksi(koleksi, *jumlah);
        int index;
        cout << "Masukkan nomor Gunpla yang akan dihapus: ";
        cin >> index;
        if (index > 0 && index <= *jumlah) {
            for (int i = index - 1; i < *jumlah - 1; i++) {
                *(koleksi + i) = *(koleksi + i + 1);
            }
            (*jumlah)--;
            cout << "Gunpla berhasil dihapus." << endl;
        } else {
            cout << "Nomor Gunpla tidak valid." << endl;
        }
    }
}

bool login(string user, string pass) {
    return (user == "RaffiZW" && pass == "037");
}

int main() {
    Gunpla koleksi[MAX_GUNPLA];
    int jumlahGunpla = 2;
    koleksi[0] = {"Gundam Wing 0", "Wing", "dirakit"};
    koleksi[1] = {"Gundam 00 Diver", "00", "dirakit"};

    string username, password;
    int login_attempts = 0;

    do {
        cout << "Masukkan Username: ";
        cin >> username;
        cout << "Masukkan Password: ";
        cin >> password;

        if (login(username, password)) {
            break;
        } else {
            cout << "Login gagal!" << endl;
            login_attempts++;
        }
    } while (login_attempts < 3);

    if (login_attempts >= 3) {
        cout << "Terlalu banyak percobaan. Program berhenti." << endl;
        return 0;
    }

    int pilihan;
    do {
        cout << "\nMenu Koleksi Gunpla" << endl;
        cout << "1. Tampilkan Koleksi" << endl;
        cout << "2. Tambah Koleksi" << endl;
        cout << "3. Ubah Status Gunpla" << endl;
        cout << "4. Hapus Gunpla" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                tampilkanKoleksi(koleksi, jumlahGunpla);
                break;
            case 2:
                tambahKoleksi(koleksi, &jumlahGunpla);  // Pass by address
                break;
            case 3:
                ubahStatusGunpla(koleksi, jumlahGunpla);
                break;
            case 4:
                hapusGunpla(koleksi, &jumlahGunpla);  // Pass by address
                break;
            case 5:
                cout << "Program selesai." << endl;
                break;
            default:
                cout << "Pilihan tidak valid." << endl;
                break;
        }
    } while (pilihan != 5);

    return 0;
}
