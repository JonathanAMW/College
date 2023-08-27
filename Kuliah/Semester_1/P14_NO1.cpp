//iostream adalah library standard untuk c++
#include <iostream>

using namespace std;

//prototype function
int ganjil (int x);

//parameter formal
int ganjil (int x){
   if(x%2==0){
        return 0;

   }else 
        return 1;
   
}

int main(){
    int x, y;
    cout<<"MENENTUKAN BILANGAN GANJIL ATAU GENAP\n";
    cout<<"Masukkan bilangan: ", cin>>y;
    x=y;

    x=ganjil(x);
    switch(x){
        case 0:
        cout<<y<<" adalah bilangan genap";
        break;

        case 1:
        cout<<y<<" adalah bilangan ganjil";
        break;

        default:
        cout<<y<<" tidak diketahui";

    }

    //system pause
    cin.get();
    cin.get();

    return 0;
}