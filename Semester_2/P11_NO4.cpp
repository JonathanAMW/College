#include <iostream>

#define N 7
#define M 1000

//prototype function
class Simpul;
class IntStack;

class Simpul{ //untuk membuat Node
    public:
        typedef struct Node{ //simpul
            int x; //namaNode
            int y; //beban minimal atau cos
            Node *z; //node sebelumnya
            bool visited;
        }Node;

        static void InitializeNode(Node *arr[], int input[][N], int nama, int count, int asal)
        {
            Node *temp = new Node();
            
            temp->x = nama;
            if (count == asal-1){
                temp->y = 0;
            } //jika merupakan node awal/asal
            else{
                temp->y = M;
            }
        
            temp->z = nullptr;
            temp->visited = false;
            arr[count] = temp;
        }
};

class IntStack{ //untuk memasukkan nilai z
    public:
        typedef struct{ //antrian
            int item[N];
            int count;
        }Stack;

        static void InitializeStack(Stack *s)
        {
            s->count = 0;
        }

        static int Empty(Stack *s)
        {
            return s->count == 0;
        }

        static int Full(Stack *s)
        {
            return s->count == N;
        }

        static void Push(Stack *s, int x)
        {
            if(Full(s)){
                std::cout << "Stack Penuh !\n";
                exit(1);

            }else{
                s->item[s->count] = x;
                s->count++;
    
            }
        }

        static int Pop(Stack *s)
        {
            int temp;
            if(Empty(s)){
                std::cout << "Stack kosong !\n";
                exit(1);

            }else{
                s->count--;
                temp = s->item[s->count];
                return temp;

            }
        }

        static int Size(Stack *s)
        {
            return s->count;
        }
};

void inisialisasi(int a, int Q[])
{
    for(int i=0; i<N; i++)
        if((i+1) == a)
            Q[i]=0;
        else
            Q[i]=M;
}

void Tampil(int data[N], std::string judul)
{
    std::cout << judul << ": ";
        for(int i=0; i<N; i++)
            if(data[i] >= M)
                std::cout << "M ";
            else
                std::cout << data[i] << " ";
    std::cout << "\n";
}

void RouteSearch(Simpul::Node *arr[], Simpul::Node *currentNode, int input[][N], int asal, int tujuan)
{
    for(int i=0; i<N; i++)
    {   
        if(input[currentNode->x-1][i]!=M){ //jika node memiliki jalur
            if(!currentNode->visited){ //jika node belum dikunjungi
                if(currentNode->y+input[currentNode->x-1][i] <= arr[i]->y && !arr[i]->visited){ //jika akumulasi beban node dengan matriks beban kurang dari beban node tujuan dan node tujuan belum dikunjungi 
                    arr[i]->y = currentNode->y+input[currentNode->x-1][i]; //menjadikan beban node tujuan menjadi akumulasi beban node saat ini dengan matriks beban
                    arr[i]->z = currentNode; //me-assign node saat ini sebagai node sebelumnya node tujuan
                }           
            }
        }
    }
    currentNode->visited = true; //mengeset node sudah dikunjungi setelah semua jalur dicoba
}

void Djikstra(IntStack::Stack *intS, int input[][N], int Beban[], int Rute[], int asal, int tujuan, int *p) //fungsi Djikstra
{   
    Simpul::Node *address[N]; //array untuk menyimpan alamat

    for(int i=0; i<N; i++)//inisialisasi Node
    {
        Simpul::InitializeNode(address, input, i+1, i, asal); //memasukkan alamat ke array
    }

    int valid = 0, i = asal-1;
    while(valid<N-1) //selama semua node belum dikunjungi
    {
        valid = 0; //mengecek apakah semua node sudah dikunjungi
        for(int j=0; j<N; j++)
        {
            if(address[j]->visited)
                valid++;
        }

        RouteSearch(address, address[i], input, asal, tujuan); //mencari node yang terhubung
        
        i++;
        if(i>N-1){ //mereset indeks ke 0, apabila node awal bukan indeks 0
            i=0;
        }
    }

    for(int a=0; a<N; a++) //memasukkan data ke array
    {
        Beban[a] = address[a]->y;
        if(address[a]->z == nullptr) //jika node tidak bisa dikunjungi
            Rute[a] = 0;
        else
            Rute[a] = address[a]->z->x;
    }

    *p = address[tujuan-1]->y; //memasukkan data beban minimal menggunakan pointer

    //memasukkan data rute terpendek menggunakan stack
    Simpul::Node *temp = address[tujuan-1];
    while(temp!=nullptr)
    {
        IntStack::Push(intS, temp->x);
        temp = temp->z;
    }
}

int main()
{
    IntStack::Stack tumpukan;
    IntStack::InitializeStack(&tumpukan);

    int input[N][N]={M,2,M,M,M,M,M,
                    1,M,3,1,M,M,M,
                    M,3,M,7,3,5,M,
                    M,1,7,M,4,M,5,
                    M,M,3,4,M,M,M,
                    M,M,5,M,M,M,8,
                    M,M,M,5,M,8,M};
    int Beban[N]={M}, Rute[N]={0};
    int asal, tujuan, bebanMinimal;
    int *p;
    p=&bebanMinimal; 

    std::cout << "Masukkan node asal : ", std::cin >> asal;
    std::cout << "Masukkan node tujuan : ", std::cin >> tujuan;
    inisialisasi(asal, Beban);
    std::cout << "Beban dan Rute awal\n";
    Tampil(Beban, "Beban");
    Tampil(Rute, "Rute");
    Djikstra(&tumpukan, input, Beban, Rute, asal, tujuan, p);
    std::cout << "Beban dan Rute akhir\n";
    Tampil(Beban, "Beban");
    Tampil(Rute, "Rute");

    std::cout << "Beban minimum: " << bebanMinimal << std::endl; //entah mengapa harus memakai pointer biar value pada fungsi Djikstra dapat di-assign
    std::cout << "Rute Terpendek: ";
    while(!IntStack::Empty(&tumpukan))
    {
        std::cout << IntStack::Pop(&tumpukan);
        if(IntStack::Size(&tumpukan) == 0)
            std::cout << "";
        else
            std::cout << "->";
    }

    return 0;
}