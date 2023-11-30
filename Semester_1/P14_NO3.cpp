//iostream adalah library standard untuk c++
#include <iostream>

using namespace std;

//prototype function
int prima (int x);

//parameter formal
int prima (int x){
    int cek=0;
    for(int i=1; i<=x; i++){
        if (x%i==0){
            cek++;

        }else 
            continue;

    }

    if(cek==2){
        return 1;

    } else
        return 0;

}

int main(){
    int x;
    int hasil;
    cout<<"MENCARI PRIMA\n";
    cout<<"Masukkan bilangan: ", cin>>x;

    switch(prima(x)){
        case 0:
        cout<<x<<" bukanlah bilangan prima";
        break;

        case 1:
        cout<<x<<" adalah bilangan prima";
        break;

        default:
        cout<<x<<" tidak diketahui";

    }
    
    //system pause
    cin.get();
    cin.get();

    return 0;
}