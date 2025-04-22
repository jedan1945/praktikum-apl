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