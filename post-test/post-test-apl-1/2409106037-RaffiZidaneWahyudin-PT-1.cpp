#include <iostream>
using namespace std;

void tampilkanMenu() {
    cout<<"|==== KONVERSI  SUHU ====|"<<endl;
    cout<<"|1. Celcius ke lainnya   |"<<endl;
    cout<<"|2. Fahrenheit ke lainnya|"<<endl;
    cout<<"|3. Reamur ke lainnya    |"<<endl;
    cout<<"|4. Kelvin ke lainnya    |"<<endl;
    cout<<"|5. Keluar               |"<<endl;
    cout<<"|========================|"<<endl;
}

void konversiSuhu(int pilihan) {
    double suhu;
    cout<<"Masukkan suhu: ";
    cin>>suhu;

    switch (pilihan) {
        case 1: //c
            cout<<"Fahrenheit: "<<(suhu * 9/5) + 32<<endl;
            cout<<"Reamur    : "<<suhu * 4/5<<endl;
            cout<<"Kelvin    : "<<suhu + 273.15<<endl;
            break;
        case 2: //f
            cout<<"Celcius: "<<(suhu - 32) * 5/9<<endl;
            cout<<"Reamur : "<<(suhu - 32) * 4/9<<endl;
            cout<<"Kelvin : "<<(suhu - 32) * 5/9 + 273.15<<endl;
            break;
        case 3: // r
            cout<<"Celcius   : "<<suhu * 5/4<<endl;
            cout<<"Fahrenheit: "<<(suhu * 9/4) + 32<<endl;
            cout<<"Kelvin    : "<<(suhu * 5/4) + 273.15<<endl;
            break;
        case 4: // K
            cout<<"Celcius   : "<<suhu - 273.15<<endl;
            cout<<"Fahrenheit: "<<(suhu - 273.15) * 9/5 + 32<<endl;
            cout<<"Reamur    : "<<(suhu - 273.15) * 4/5<<endl;
            break;
    }
}

bool login() {
    string nama, password;
    int kesempatan = 3;
    while (kesempatan > 0) {
        cout<<"Masukkan Nama AI(Asli Ini): "; 
        cin>>nama;
        cout<<"Password (3 digit NIM terakhir): "; 
        cin>>password;
        if (nama == "Raffi" && password == "037") return true;
        cout<<"Salah! Sisa percobaan: "<<--kesempatan<<endl;
    }
    return false;
}

int main() {
    if (!login()) {
        cout<<"Akses ditolak!"<<endl;
        return 0;
    }
    int pilihan;
    do {
        tampilkanMenu();
        cout<<"Pilih menu: ";
        cin>>pilihan;
        if (pilihan >= 1 && pilihan <= 4) konversiSuhu(pilihan);
    } while (pilihan != 5);
    return 0;
}
