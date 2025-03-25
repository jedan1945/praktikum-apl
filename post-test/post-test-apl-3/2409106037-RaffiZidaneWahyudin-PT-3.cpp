#include <iostream>
using namespace std;

#define MAX_GUNPLA 100
struct Gunpla {
    string nama;
    string seri;
    string status;
};

int main() {
    Gunpla koleksi[MAX_GUNPLA];
    int jumlahGunpla = 2;
    koleksi[0] = {"Gundam Wing 0", "Wing", "dirakit"};
    koleksi[1] = {"Gundam 00 Diver", "00", "dirakit"};

    int pilihan, index;
    string username, password;
    int login_attempts = 0;

    // Login
    do {
        cout << "Masukkan Username: ";
        cin >> username;
        cout << "Masukkan Password: ";
        cin >> password;

        if (username == "RaffiZW" && password == "037") {
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

    // Menu utama
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
                if (jumlahGunpla == 0) {
                    cout << "Belum ada Gunpla dalam koleksi." << endl;
                } else {
                    for (int i = 0; i < jumlahGunpla; i++) {
                        cout << "Gunpla ke-" << i + 1 << ": " << koleksi[i].nama << " - " << koleksi[i].seri << " (" << koleksi[i].status << ")" << endl;
                    }
                }
                break;

            case 2:
                if (jumlahGunpla < MAX_GUNPLA) {
                    cout << "Masukkan nama Gunpla: ";
                    cin.ignore();
                    getline(cin, koleksi[jumlahGunpla].nama);
                    cout << "Masukkan seri Gunpla: ";
                    getline(cin, koleksi[jumlahGunpla].seri);
                    cout << "Masukkan status Gunpla (dirakit/belum dirakit/second): ";
                    getline(cin, koleksi[jumlahGunpla].status);
                    jumlahGunpla++;
                    cout << "Gunpla berhasil ditambahkan." << endl;
                } else {
                    cout << "Koleksi penuh! Tidak bisa menambah Gunpla lagi." << endl;
                }
                break;

            case 3:
                if (jumlahGunpla == 0) {
                    cout << "Belum ada Gunpla untuk diubah." << endl;
                } else {
                    for (int i = 0; i < jumlahGunpla; i++) {
                        cout << "Gunpla ke-" << i + 1 << ": " << koleksi[i].nama << " - " << koleksi[i].seri << " (" << koleksi[i].status << ")" << endl;
                    }
                    cout << "Masukkan nomor Gunpla yang akan diubah: ";
                    cin >> index;
                    if (index > 0 && index <= jumlahGunpla) {
                        cout << "Masukkan status baru: ";
                        cin.ignore();
                        getline(cin, koleksi[index - 1].status);
                        cout << "Status Gunpla berhasil diubah." << endl;
                    } else {
                        cout << "Nomor Gunpla tidak valid." << endl;
                    }
                }
                break;

            case 4:
                if (jumlahGunpla == 0) {
                    cout << "Belum ada Gunpla untuk dihapus." << endl;
                } else {
                    for (int i = 0; i < jumlahGunpla; i++) {
                        cout << "Gunpla ke-" << i + 1 << ": " << koleksi[i].nama << " - " << koleksi[i].seri << " (" << koleksi[i].status << ")" << endl;
                    }
                    cout << "Masukkan nomor Gunpla yang akan dihapus: ";
                    cin >> index;
                    if (index > 0 && index <= jumlahGunpla) {
                        for (int i = index - 1; i < jumlahGunpla - 1; i++) {
                            koleksi[i] = koleksi[i + 1];
                        }
                        jumlahGunpla--;
                        cout << "Gunpla berhasil dihapus." << endl;
                    } else {
                        cout << "Nomor Gunpla tidak valid." << endl;
                    }
                }
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
