//iostream adalah library standard untuk c++
#include <iostream>
using namespace std;

//prototype function
void menu();

void menu(){;
    cout<<"Pilihan Menu\n";

}

int main(){
    int input;
    cout<<"Berapa kali memanggil fungsi menu?: ", cin>>input;

    for(int i=input; i>0; i--){
    menu();

    }

    //system pause
    cin.get();
    cin.get();
    return 0;

}