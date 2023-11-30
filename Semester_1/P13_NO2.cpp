//iostream adalah library standard untuk c++
#include <iostream>
using namespace std;

//prototype function
void triangular(int n);

void triangular(int n){
    int hasil=0;
    for(int i=n; i>0; i--){
        hasil+=i;
    }
    cout<<"Nilai triangular dari "<<n<<" adalah: "<<hasil;
}

int main(){
    int n;
    cout<<"Masukkan nilai n: ", cin>>n;

    triangular(n);

    //system pause
    cin.get();
    cin.get();
    return 0;

}