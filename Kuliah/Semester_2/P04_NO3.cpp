#include <iostream>
#include <stack>

#define MAX 6 //sesuai soal praktikum

typedef struct
{
    int data [MAX];
    int front, rear, count;
}Queue;

void initialize (Queue *mobil)
{
    mobil->front = mobil->rear = -1;
    mobil->count = 0;
}

void enqueue (Queue *mobil, int input) //memasukkan isi kepada elemen terakhir
{
    if(mobil->rear == MAX-1)
    {
        std::cout << "Antrian penuh!\n";
        return;
    }
    mobil->rear++;
    mobil->data[mobil->rear] = input;
    mobil->count++;
    if(mobil->front == -1)
    {
        mobil->front = 0;
    }
}

int dequeue (Queue *mobil) //mengeluarkan isi pada elemen paling depan
{
    int nomor; 
    if(mobil->front == -1)
    {
        std::cout << "Antrian kosong!\n";
        return NULL;
    }
    nomor = mobil->data[mobil->front];
    mobil->count--;

    if (mobil->front == mobil->rear) //jika antrian kosong setelah proses diatas
    {
        mobil->front = mobil->rear = -1;
    }else
        mobil->front++;
        return nomor;
}

void display (Queue *mobil)
{
    std::cout << "Posisi mobil saat ini: " << std::endl;
    for(int i=mobil->front; i<=mobil->rear; i++) //perlu diperbaiki //fix mungkin
    {
        std::cout << mobil->data[i] << " ";
    }
    std::cout << "\n";
}

int dequeue_temp(Queue *mobil, std::stack<int> &temp, int input) //data dikeluarkan dari depan secara sementara
{
    int mobil_temp, i=0;
    do
    {
        if(input==mobil->data[i])
        { 
            return i;
        }else{
            temp.push(mobil->data[i]);
            dequeue(mobil);
        }
        i++;
    }while(i<=mobil->rear);
}

void enqueue_front (Queue *mobil, std::stack<int> &temp, int indeks) //data dimasukkan kembali dari stack
{
    int i=mobil->rear-mobil->front;

    if(mobil->front-1 > -1)
    {
        mobil->front--; //supaya pas dengan menskip indeks tsb agar diisi oleh elemen belakang
    }
    
    if(!temp.empty()) //kalau stack berisi, misal tidak berisi jika mobil 1 diambil
    {
        do{ //memasukkan data stack ke queue
            if(mobil->front == 0)
            {
                mobil->data[mobil->front] = temp.top(); 
                temp.pop();
            }else{
                mobil->data[mobil->front] = temp.top();
                mobil->front--;
                temp.pop();
            }
        }while(!temp.empty());
    }

    if(i != 0) //jika queue masih memiliki anggota belakang, misal mobil 6 diambil
    {
        do{ //memajukan data queue bagian belakang
            mobil->data[indeks] = mobil->data[indeks+1];
            indeks++;
            i--;
        }while(i >= 0);
    }
    
    mobil->rear--;
}

int main()
{
    Queue mobil; //antrian
    std::stack<int> temp; //peletakkan sementara
    char pilihan; //memilih keluar dari loop
    int input, indeks; //nomor mobil yg masuk atau keluar

    std::cout << "================================================================\n";
    std::cout << "\t  MEMNGATUR MOBIL DENGAN KONSEP QUEUE\n";
    std::cout << "================================================================\n";

    initialize(&mobil);
    std::cout << "Silakan menginputkan nomor-nomor mobil(MAX=6): ";
    while(mobil.count != MAX)
    {
        std::cin >> input;
        enqueue(&mobil, input);
    }
    display(&mobil);
    std::cin.ignore();

    do
    {
        std::cout << "\nPilih mobil yang akan dikeluarkan: ";
        std::cin >> input;
        indeks = dequeue_temp(&mobil, temp, input);
        enqueue_front(&mobil, temp, indeks);
        display(&mobil);
        std::cout << "\nMau mengeluarkan mobil lagi?(y/ketik sembarang): ", std::cin >> pilihan;
        std::cin.ignore();
    }while(pilihan == 'y' || pilihan == 'Y');

    std::cout << "================================================================\n";
    std::cout << "\t  TERIMA KASIH DAN MOHON MAAF ATAS BUG\n";
    std::cout << "================================================================\n";
    return 0;
}