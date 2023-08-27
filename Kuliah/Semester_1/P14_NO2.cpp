//iostream adalah library standard untuk c++
#include <iostream>

using namespace std;

//prototype function
int faktorial (int x, long int hasil);

//parameter formal
int faktorial (int x, long int hasil){
    for(int i=x; i>0; i--){
       hasil*=i;

    }

    return (x, hasil);
}

int main(){
    int x;
    int hasil=1;
    cout<<"MNEGHITUNG FAKTORIAL\n";
    cout<<"Masukkan bilangan: ", cin>>x;

    hasil=faktorial(x, hasil);
    cout<<"Faktorial dari "<<x<<" adalah "<<hasil;

    //system pause
    cin.get();
    cin.get();

    return 0;
}