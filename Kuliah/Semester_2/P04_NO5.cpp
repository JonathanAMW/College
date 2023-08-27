#include <iostream>
#include <vector>

typedef struct queue
{
    std::vector<int> priority; //nantinya akan diisi oleh indeks 
    int front, rear;
}QUEUE;

struct mahasiswa
{
    std::string nrp;
    std::string nama;
    int nilai;
};


void initialize (QUEUE *q)
{
    q->priority.push_back(int()); //jumlah priority ditambah
    q->front = q->rear = -1;
}

void enqueue (QUEUE *q, std::vector<mahasiswa> &MHS) //memasukkan isi kepada elemen terakhir
{
    if(q->rear == q->priority.size()-1)
    {
        std::cout << "Antrian penuh!\n";
        return;
    }
    q->rear++;
    q->priority.push_back(int()); //jumlah priority ditambah
    q->priority[q->rear] = MHS.size()-1; //indeks sebagai alternatif alamat
    if(q->front == -1)
    {
        q->front = 0;
    }
}

int dequeue (QUEUE *q, int indeks, std::vector<mahasiswa> &MHS) //mengeluarkan isi pada elemen yang memiliki nilai tertinggi
{
    if(q->front == -1) //jika belum diinisialisasi ataupun kosong
    {
        std::cout << "Antrian kosong!\n";
        return NULL;
    }

    q->priority[indeks] = -1; //setelah dapet, data pada indeks diganti -1

    if (q->front == q->rear) //jika antrian kosong setelah proses diatas
    {
        q->front = q->rear = -1;
    }else
        std::cout << "\nNilai tertinggi saat ini: \n"; 
        std::cout << "Nrp\t: " << MHS[indeks].nrp << std::endl;
        std::cout << "Nama\t: " << MHS[indeks].nama << std::endl;
        std::cout << "nilai\t: " << MHS[indeks].nilai << std::endl;
        
}

void display (QUEUE *q)
{
    std::cout << "\nPosisi queue saat ini(-1 artinya sudah didequeue): " << std::endl;
    for(int i=q->front; i<=q->rear; i++) 
    {
        std::cout << q->priority[i] << "  ";
    }
    std::cout << "\n";
}

int compare (QUEUE *q, std::vector<mahasiswa> &MHS)
{
    int valid = 0, count=0;
    for(int i=0; i<=q->rear; i++) //dicek lagi, rear-1 awalnya teori kalau * bakal bersarang pada rear
                                   //bintang * harus dipop kalau memungkinkan
    {
        for(int j=0; j<=q->rear; j++)
        {
            if(q->priority[i] == -1 || q->priority[j] == -1) //apabila -1 (data sudah didequeue)
            {
                count++;
            }else{
                if(MHS[i].nilai > MHS[j].nilai) //MHS[0||1||2||...] jadi kalau lebih besar dichecklist
                {
                    valid++;
                }
            }
        }
        if(valid == q->rear-count) //sesuai panjang saat itu, -count apabila di queue ada -1
        {
            return i; //mereturn indeks ke variabel indeks fungsi main
        }else //direset
            valid=0;
            count=0;
    }
}


int main()
{
    std::cout << "================================================================\n";
    std::cout << "\t\t  MEMBUAT PRIORITY QUEUE\n";
    std::cout << "================================================================\n";
    
    char pilihan; //agar keluar loop
    QUEUE q;
    std::vector<mahasiswa> MHS; //dynamic array
    MHS.push_back(mahasiswa()); //menambah size array = +1
    
    initialize(&q);

    std::cout << "\n------------------------------------------------------------------------\n";
    std::cout << "Apabila selesai setelah mendequeue, silakan ketik 'done' pada kolom nrp!\n";
    std::cout << "------------------------------------------------------------------------\n";
    do
    {
        std::cout << "Masukkan data mahasiswa ke- " << MHS.size() << " :\n";
        std::cout << "Nrp\t:", std::getline(std::cin, MHS[MHS.size()-1].nrp);
        
        if(MHS[MHS.size()-1].nrp == "*")
        {
            int indeks=compare(&q, MHS); //melakukan operasi untuk meng-compare data yg telah dimasukkan dulu
            //data dari queue tersebut diisi kosong
            //MHS[MHS.size()-1].nama = "-";
            //MHS[MHS.size()-1].nilai = NULL;
            dequeue(&q, indeks, MHS);
            display(&q);//meilhat data queue
            std::cout << std::endl;
            continue; //skip operasi selanjutnya jadi data pada[i] = '*'
        }else if(MHS[MHS.size()-1].nrp == "done"){
            break;
        }

        std::cout << "Nama\t:", std::getline(std::cin, MHS[MHS.size()-1].nama);
        std::cout << "Nilai\t:", std::cin >> MHS[MHS.size()-1].nilai;

        enqueue(&q, MHS); //data dimasukkan ke antrian

        std::cout << "Ingin memasukkan data lagi?(y/sembarang): ", std::cin >> pilihan;
        std::cin.ignore();//agar '\n' tidak masuk
        if(pilihan == 'y' || pilihan == 'Y')//jika ya, anggota array ditambah lagi
        {
            MHS.push_back(mahasiswa());
            std::cout << "\n";
        }
    }while(pilihan == 'y' || pilihan == 'Y');

    std::cout << "\nData yang sudah dimasukkan: \n";

    for(int i=0; i<MHS.size(); i++)
    {
        std::cout << "Data mahasiswa ke-" << i+1 << ": \n";
        std::cout << "Nrp\t: " << MHS[i].nrp << std::endl;
        std::cout << "Nama\t: " << MHS[i].nama << std::endl;
        std::cout << "Nilai\t: " << MHS[i].nilai << std::endl;
        std::cout << "\n";
    }


    std::cout << "================================================================\n";
    std::cout << "\t  TERIMA KASIH DAN MOHON MAAF ATAS BUG\n";
    std::cout << "================================================================\n";
    return 0;
}