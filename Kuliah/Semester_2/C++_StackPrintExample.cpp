#include <iostream>
#include <stack>

using namespace std;

int main()
{
  stack<char>mystack;
  cout<<"Masukkan Kata : ";
  string input;
  
  getline(cin,input);

  //int top = sizeof(input); salah dalam mencari panjangnya
  /*
  for(int i=0; i<top; i++){//ganti menjadi bawahnya
    mystack.push(input[i]);
  }
  */
  for(int i=0; i<input.size(); i++){
    mystack.push(input[i]);
  }

  while(!mystack.empty())
  {
    cout<<mystack.top();
    mystack.pop();
  }
}