#include<iostream>
using namespace std;

int main (int argc,char const *argv[]){
    int number[3]={1,2,4};
    for(int i:number)
        {
        cout<< " nilai array: " << i << endl;
        }
        for(int i =1 ; i <3 ; i++)
        {
            number[i]= number [i+1];
        }
        for(int i :number)
        {
        cout<< " nilai array: " << i << endl;    
        }
    
    //  number[1]=5;
    // int panjangarray = sizeof(number)/sizeof(number[0]);
    // for(int i :number)
    // {
    //     cout<< " nilai array: " << i << endl;    
    // }
    // number[2]=10;
    // int panjangarray = sizeof(number)/sizeof(number[0]);
    // for(int i :number)
    // {
    //     cout<< " nilai array: " << i << endl;    
    // }


    // int totalbyte = sizeof(number);
    // int singlebyte = sizeof(number[0]);
    // int panjangarray = sizeof(number)/sizeof(number[0]);

    // for (int i:number)
    // {
    //     cout << "nilai array: " <<i<< endl;
    // }
    // for (int i = 0; i < panjangarray; i++)
    // {
    //     cout<< " nilai array: " << number[i] << endl;
    // }
    // int panjangarray2 = size(number);

    // cout << totalbyte << "\n"
    //     << singlebyte << "\n"
    //     << panjangarray2;
    // cout << sizeof(number)/sizeof(number[0]);

    // cout << "versi saya: " <<_cplusplus;
    return 0;
}