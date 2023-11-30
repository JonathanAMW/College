//iostream adalah library standard untuk c++
#include <iostream>
#define PI 3.14159f

using namespace std;

//prototype function
float radian (float);

//parameter formal
float radian (float derajat){
    float radian=0;
    
    radian=derajat/180*PI;

    return (radian);
}

int main(){
    float derajat;

    cout<<"MENGHITUNG RADIAN\n";
    cout<<"Masukkan nilai derajat: ", cin>>derajat;

    cout<<"Sudut tersebut dalam Radian bernilai: "<<radian(derajat);

    //system pause
    cin.get();
    cin.get();

    return 0;
}