#include <iostream>
using namespace std;

#define MAX_GUNPLA 100

struct Gunpla {
    string nama;
    string seri;
    string status;
    int harga;
};

void tampilkanKoleksi(Gunpla* koleksi, int jumlah) {
    if (jumlah == 0) {
        cout << "Belum ada Gunpla dalam koleksi." << endl;
    } else {
        for (int i = 0; i < jumlah; i++) {
            cout << "Gunpla ke-" << i + 1 << ": " << (koleksi + i)->nama
                 << " - " << (koleksi + i)->seri
                 << " (" << (koleksi + i)->status << ")"
                 << " - Rp" << (koleksi + i)->harga << endl;
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
        cout << "Masukkan harga Gunpla: ";
        cin >> (koleksi + *jumlah)->harga;
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

void bubbleSortSeri(Gunpla* koleksi, int jumlah) {
    for (int i = 0; i < jumlah - 1; i++) {
        for (int j = 0; j < jumlah - i - 1; j++) {
            if ((koleksi + j)->seri > (koleksi + j + 1)->seri) {
                swap(*(koleksi + j), *(koleksi + j + 1));
            }
        }
    }
}

int partitionHarga(Gunpla* koleksi, int low, int high) {
    int pivot = (koleksi + (low + high) / 2)->harga;
    int i = low, j = high;
    while (i <= j) {
        while ((koleksi + i)->harga > pivot) i++;
        while ((koleksi + j)->harga < pivot) j--;
        if (i <= j) {
            swap(*(koleksi + i), *(koleksi + j));
            i++;
            j--;
        }
    }
    return i;
}

void quickSortHarga(Gunpla* koleksi, int low, int high) {
    if (low < high) {
        int pi = partitionHarga(koleksi, low, high);
        quickSortHarga(koleksi, low, pi - 1);
        quickSortHarga(koleksi, pi, high);
    }
}

void merge(Gunpla* koleksi, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    Gunpla L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = *(koleksi + left + i);
    for (int j = 0; j < n2; j++)
        R[j] = *(koleksi + mid + 1 + j);

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i].nama <= R[j].nama) {
            *(koleksi + k) = L[i];
            i++;
        } else {
            *(koleksi + k) = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        *(koleksi + k) = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        *(koleksi + k) = R[j];
        j++;
        k++;
    }
}

void mergeSortNama(Gunpla* koleksi, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSortNama(koleksi, left, mid);
        mergeSortNama(koleksi, mid + 1, right);
        merge(koleksi, left, mid, right);
    }
}

int main() {
    Gunpla koleksi[MAX_GUNPLA];
    int jumlahGunpla = 2;
    koleksi[0] = {"Gundam Wing 0", "Wing", "dirakit", 300000};
    koleksi[1] = {"Gundam 00 Diver", "00", "dirakit", 350000};

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
        cout << "5. Sorting Nama Seri" << endl;
        cout << "6. Sorting Harga" << endl;
        cout << "7. Sorting Nama" << endl;
        cout << "8. Keluar" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                tampilkanKoleksi(koleksi, jumlahGunpla);
                break;
            case 2:
                tambahKoleksi(koleksi, &jumlahGunpla);
                break;
            case 3:
                ubahStatusGunpla(koleksi, jumlahGunpla);
                break;
            case 4:
                hapusGunpla(koleksi, &jumlahGunpla);
                break;
            case 5:
                bubbleSortSeri(koleksi, jumlahGunpla);
                cout << "Koleksi sudah disorting berdasarkan Seri" << endl;
                tampilkanKoleksi(koleksi, jumlahGunpla);
                break;
            case 6:
                quickSortHarga(koleksi, 0, jumlahGunpla - 1);
                cout << "Koleksi sudah disorting berdasarkan Harga" << endl;
                tampilkanKoleksi(koleksi, jumlahGunpla);
                break;
            case 7:
                mergeSortNama(koleksi, 0, jumlahGunpla - 1);
                cout << "Koleksi sudah disorting berdasarkan Nama" << endl;
                tampilkanKoleksi(koleksi, jumlahGunpla);
                break;
            case 8:
                cout << "Program selesai." << endl;
                break;
            default:
                cout << "Pilihan tidak valid." << endl;
                break;
        }
    } while (pilihan != 8);

    return 0;
}