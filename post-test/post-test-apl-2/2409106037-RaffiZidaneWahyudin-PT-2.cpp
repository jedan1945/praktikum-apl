#include <iostream>
using namespace std;
#define MAX_GUNPLA 100 // Ukuran maksimum array koleksi Gunpla

int main() {
    int jumlahGunpla = 2; // Jumlah elemen saat ini
    string gunpla[MAX_GUNPLA] = {"Gundam Wing 0", "Gundam 00 Diver"}; // Array dengan koleksi Gunpla
    string kondisi[MAX_GUNPLA] = {"dirakit", "dirakit"}; // Array untuk status Gunpla
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
        cout << "Menu Koleksi Gunpla" << endl;
        cout << "1. Tampilkan Koleksi" << endl;
        cout << "2. Tambah Koleksi" << endl;
        cout << "3. Ubah Kondisi Gunpla" << endl;
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
                        cout << "Gunpla ke-" << i + 1 << ": " << gunpla[i] << " (" << kondisi[i] << ")" << endl;
                    }
                }
                break;

            case 2:
                if (jumlahGunpla < MAX_GUNPLA) {
                    cout << "Masukkan nama Gunpla: ";
                    cin.ignore();
                    getline(cin, gunpla[jumlahGunpla]);
                    cout << "Masukkan kondisi Gunpla (dirakit/belum dirakit/second): ";
                    getline(cin, kondisi[jumlahGunpla]);
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
                        cout << "Gunpla ke-" << i + 1 << ": " << gunpla[i] << " (" << kondisi[i] << ")" << endl;
                    }
                    cout << "Masukkan nomor Gunpla yang akan diubah: ";
                    cin >> index;
                    if (index > 0 && index <= jumlahGunpla) {
                        cout << "Masukkan kondisi baru: ";
                        cin.ignore();
                        getline(cin, kondisi[index - 1]);
                        cout << "Kondisi Gunpla berhasil diubah." << endl;
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
                        cout << "Gunpla ke-" << i + 1 << ": " << gunpla[i] << " (" << kondisi[i] << ")" << endl;
                    }
                    cout << "Masukkan nomor Gunpla yang akan dihapus: ";
                    cin >> index;
                    if (index > 0 && index <= jumlahGunpla) {
                        for (int i = index - 1; i < jumlahGunpla - 1; i++) {
                            gunpla[i] = gunpla[i + 1];
                            kondisi[i] = kondisi[i + 1];
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