#include <stdio.h>
#define MAX 10
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
        printf("\nAntrian Penuh");
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
        printf("\nAntrian Kosong");
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
        printf("\nData : %d", q->Item[i]);
}
void main()
{
    Queue q;
    int data;
    Inisialisasi(&q);
    Tambah(&q, 11);
    Tambah(&q, 12);
    Tambah(&q, 13);
    Tambah(&q, 14);
    Tambah(&q, 15);
    Tambah(&q, 16);
    Tambah(&q, 17);
    Tambah(&q, 18);
    Tambah(&q, 19);
    Tambah(&q, 20);
    Tambah(&q, 21);
    Tampil(&q);
    data = Hapus(&q);
    printf("\nHapus Item = %d ", data);
    data = Hapus(&q);
    printf("\nHapus Item = %d ", data);
    data = Hapus(&q);
    printf("\nHapus Item = %d ", data);
    Tampil(&q);
}