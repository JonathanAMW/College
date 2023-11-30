#include <iostream>

#define MAX 5
#define NULL 0

typedef struct
{
    int Item[MAX];
    int Front;
    int Rear;
    int Count;
} Queue;

// Inisialisasi antrian
void Inisialisasi(Queue *q)
{
    q->Front = q->Rear = -1;
    q->Count = 0;
}

// Prosedur untuk menyisipkan data pada antrian
void Tambah(Queue *q, int item)
{
    if ((q->Rear == MAX - 1 && q->Front == 0) || (q->Rear + 1 == q->Front)) //jika queue penuh
    {
        std::cout << "\nAntrian Penuh";
        return;
    }
    if (q->Rear == MAX - 1) //jika rear mencapai max tapi front masih ada yg kosong
        q->Rear = 0;
    else
        q->Rear++; //panjang rear akan bertambah
    q->Item[q->Rear] = item; //item dimasukkan pada indeks rear
    q->Count++; //panjang queue bertambah
    if (q->Front == -1) //kalau Front belum diinisialisasi???
        q->Front = 0;
}

// Prosedur untuk menghapus data dari antrian
int Hapus(Queue *q)
{
    int data;
    if (q->Front == -1) //jika Front belum diinisialisasi
    {
        std::cout << "\nAntrian Kosong";
        return NULL;
    }
    else
    {
        data = q->Item[q->Front]; //item dicopy ke dalam data
        q->Count--; //panjang queue berkurang
        if (q->Front == q->Rear) //jika queue sudah kosong
            q->Front = q->Rear = -1;
        else
        {
            if (q->Front == MAX - 1) //jika Front sudah maks tapi queue memiliki anggota kosong
                q->Front = 0;
            else
                q->Front++; //Front ditambah
        }
    }
    return data;
}

void Tampil(Queue *q)
{
    for (int i = 0; i < q->Count; i++)
        std::cout << "\nData : "<< q->Item[i];
}

int main() //c++ perlu main bersifat int! (perlu konfirmasi!!!)
{
    Queue q;
    int data;
    Inisialisasi(&q);
    Tambah(&q, 5); //5
    Tambah(&q, 6); //5, 6
    Tambah(&q, 7); //5, 6, 7
    Hapus(&q);     //6, 7
    Tambah(&q, 8); //6, 7, 8
    Hapus(&q);     //7, 8
    Tambah(&q, 9); //7, 8, 9
    Tambah(&q, 10);//10, , 7, 8, 9
    Tambah(&q, 11);//10, 11, 7, 8, 9
    std::cout << "Hasil sementara: "; 
    Tampil(&q);
    std::cout << "\n\nSetelah ditambah: ";
    Tambah(&q, 12);//penuh
    Tampil(&q);
}