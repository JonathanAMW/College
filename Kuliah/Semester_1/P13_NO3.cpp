//iostream adalah library standard untuk c++
#include <iostream>
//iomanip berguna memanggil setprecision dan fixed
#include <iomanip> 
using namespace std;

//prototype function
float kuadrat(float x);

float kuadrat(float x){
    return x*x;

}

int main(){
    float x, hasil;
    cout<<"Masukkan nilai x: ", cin>>x;

    cout<<fixed<<setprecision(2)<<"Nilai kuadrat dari "<<x<<" adalah: "<<kuadrat(x);

    //system pause
    cin.get();
    cin.get();
    return 0;

}