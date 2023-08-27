//iostream adalah library standard untuk c++
#include <iostream>

using namespace std;

//prototype function
float konversi (float, char, char);

//parameter formal
float konversi (float suhu, char asal, char tujuan){
    float hasil=0;
    int pembanding, penyebut, fahrenheitawal=0, fahrenheitakhir=0;

    //penentuan pembanding
    if(asal=='C' || asal=='c'){ //dari celcius
        penyebut=5;

    }else if(asal=='R' || asal=='r'){ //dari reamur
        penyebut=4;

    }else if(asal=='F' || asal=='f'){ //dari fahrenheit
        penyebut=9;
        fahrenheitawal=32;

    }else 
        cout<<"Tidak ada";

    //penentuan penyebut
    if(tujuan=='C' || tujuan=='c'){ //dari celcius
        pembanding=5;

    }else if(tujuan=='R' || tujuan=='r'){ //dari reamur
        pembanding=4;

    }else if(tujuan=='F' || tujuan=='f'){ //dari fahrenheit
        pembanding=9;
        fahrenheitakhir=32;

    }else 
        cout<<"Tidak ada";

    //penghitungan
    hasil=(suhu-fahrenheitawal)*pembanding/penyebut+fahrenheitakhir;
    

    return(hasil);
}

int main(){
    float suhu;
    char asal, tujuan;

    cout<<"MENGKONVERSI SUHU\n";
    cout<<"Masukkan suhu sumber: ", cin>>suhu;
    cout<<"Masukkan satuan asal: ", cin>>asal;
    cout<<"Masukkan satuan tujuan: ", cin>>tujuan;

    cout<<"Hasil koversi suhu "<<suhu<<" "<<asal<<" = "<<konversi(suhu, asal, tujuan)<<" "<<tujuan;

    //system pause
    cin.get();
    cin.get();

    return 0;
}