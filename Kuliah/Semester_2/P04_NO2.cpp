#include <iostream>
#include <stack>

int addQ(char x, std::stack<char> &s1)
{
    s1.push(x);
}

void removeQ(std::stack<char> &s1, std::stack<char> &s2)
{
    if (s2.empty())
    {
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
    }
    else
        s2.pop();
}

void front(std::stack<char> &s1, std::stack<char> &s2)
{
    if (s2.empty())
    {
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
    }
    else
        std::cout << "Kata depan saat ini adalah: " << s2.top() << std::endl;
}

void display(std::stack<char> s1, std::stack<char> s2) // karena tdk di &, operasi ini tidak mengubah nilai/elemen stack
{
    std::cout << "Stack 1: ";
    while (!s1.empty())
    {
        std::cout << s1.top() << " ";
        s1.pop();
    }

    std::cout << "\nStack 2: ";
    while (!s2.empty())
    {
        std::cout << s2.top() << " ";
        s2.pop();
    }
}

int main()
{
    std::string input;
    char pilihan, x;
    std::stack<char> s1;
    std::stack<char> s2;
    int error = 0; // ==1 ada error, ==0 || ==2 tidak ada error

    std::cout << "================================================================\n";
    std::cout << "\t\t  MENGGUNAKAN STACK SEBAGAI QUEUE\n";
    std::cout << "================================================================\n";

    do
    {
        std::cout << "Masukkan karakter (spasi terhitung!): ";
        std::getline(std::cin, input);
        for (int i = 0; i < input.size(); i++)
        {
            x = input[i];
            addQ(x, s1);
        }

        std::cout << "Ingin mengulangi?(y/t): ", std::cin >> pilihan;
        std::cin.ignore();

    } while (pilihan == 'y' || pilihan == 'Y');

    std::cout << "\nSetelah penginputan: \n";
    display(s1, s2); // menunjukkan isi stack tanpa mem-pop di stack asli

    std::cout << std::endl;

    // meminta operasi dari user
    std::cout << "\nKode\tOperasi: \n";
    std::cout << "f\tfront, menampilkan kata depan \n";
    std::cout << "r\tremoveQ, menghilangkan kata depan \n";
    std::cout << "Note: Pada awalnya, operasi ini hanya akan memindahkan semua isi stack 1 pada stack 2!\n";

    do
    {
        error = 0;
        std::cout << "Pilih operasi yang diinginkan!: ", std::cin >> pilihan;

        switch (pilihan)
        {
        case 'r':
        case 'R':
            removeQ(s1, s2);
            std::cout << "\nSetelah dioperasi removeQ : \n";
            display(s1, s2);
            break;

        case 'f':
        case 'F':
            std::cout << "\nSetelah dioperasi front : \n";
            front(s1, s2);
            break;

        default:
            std::cout << "Operasi tersebut tidak ada!\n";
            error = 1;
        }

        while (error == 0) //kalau tidak ada error baru masuk ke sini
        {
            std::cout << "\nAda lagi?(y/t): ", std::cin >> pilihan;
            std::cin.ignore(); // cin.ignore menghilangkan input selanjutnya, biasanya '\n'
            switch (pilihan)
            {
            case 'y': // keluar dari loop ini saja
            case 'Y':
                error = 1;
                break;
            case 't': // keluar dari semua loop
            case 'T':
                error = 2;
                break;
            default: //
                std::cout << "Respon tersebut tidak ada!\n";
            }
        }

    } while (error == 1 || error != 2);

    std::cout << "================================================================\n";
    std::cout << "\t  TERIMA KASIH DAN MOHON MAAF ATAS BUG\n";
    std::cout << "================================================================\n";
    return 0;
}