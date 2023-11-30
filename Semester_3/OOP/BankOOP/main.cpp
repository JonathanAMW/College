#include <iostream>
#include "BankAccount.h"

using namespace std;
int main() {
	cout << "Hello World!\n";

	// instantiate obyek
	BankAccount accRizky(1,100000), accYudi(2,200000), accDimas(3,300000);

	// tampilkan saldo awal
	cout << "Saldo Awal Rizky = " << accRizky.GetCurrentBalance() << endl;
	cout << "Saldo Awal Yudi = " << accYudi.GetCurrentBalance() << endl;

	// dua object deposit
	accRizky.Deposit(100);
	accYudi.Deposit(2000);

	// tampilkan saldo setelah deposit
	cout << "Saldo Setelah deposit Rizky = " << accRizky.GetCurrentBalance() << endl;
	cout << "Saldo Setelah deposit Yudi = " << accYudi.GetCurrentBalance() << endl;

	// dua object withdrawal
	accRizky.Withdrawal(5000);
	accYudi.Withdrawal(20000);

	// tampilkan saldo setelah withdrawal
	cout << "Saldo Setelah ambil Rizky = " << accRizky.GetCurrentBalance() << endl;
	cout << "Saldo Setelah ambil Yudi = " << accYudi.GetCurrentBalance() << endl;

	int n;
	cin >> n;
}