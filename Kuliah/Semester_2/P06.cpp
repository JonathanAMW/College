#include <iostream>

typedef struct node {
    std::string name;
    std::string nrp;
    struct node *next;
    struct node *before;
}Node;
Node *Head; //pangkal
Node *Tail; //ujung
int node_count = 0; //hitung jumlah node


Node *alokasi_node() // alokasi maksimal 3 node
{
    Node *news; // c++ tdk bisa pake new
    news = (Node *)malloc(sizeof(Node));

    if (news == NULL) //gagal diinisialisasi
    {
        return NULL;
    }else //berhasil diinisialisasi
    {
        news->next = NULL;
        news->before = NULL;
        return news;
    }
}

void CariNode (Node *n) //mencari node
{
    std::string input_nrp;
    int count = 0;

    std::cout << "Masukkan nrp yang ingin dicari: ", std::getline(std::cin, input_nrp);
    while (n->nrp != input_nrp)
    {
        n = n->next;
        count ++;
    }

    std::cout << "Data tersebut berada pada: ";
    std::cout << "Indeks ke- " << count << std::endl;
    std::cout << "Bernama: " << n->name << std::endl;
    if(n->before == NULL) //jika merupakan data pertama
    {
        std::cout << "Merupakan data pertama (Head)" << std::endl;
        std::cout << "Sebelum nrp: " << n->next->nrp << std::endl;
    }else if(n->next == NULL){ //jika merupakan data terakhir
        std::cout << "Sesudah nrp: " << n->before->nrp << std::endl;
        std::cout << "Merupakan data terakhir (Tail)" << std::endl;
    }else{
        std::cout << "Sesudah nrp: " << n->before->nrp << std::endl;
        std::cout << "Sebelum nrp: " << n->next->nrp << std::endl;
    }
}

void SisipAwal() //menyisipkan data di awal
{
    std::string input_nama;
    std::string input_nrp;
    Node *temp = alokasi_node();
    if (temp == NULL) //jika alokasi gagal
    {
        std::cout << "Alokasi gagal\n";
        return;
    }else{
        //data dimasukkan
        std::cout << "Nrp: ", std::getline(std::cin, input_nrp);
        std::cout << "Nama: ", std::getline(std::cin, input_nama);
        temp->nrp = input_nrp;
        temp->name = input_nama;

        if(node_count == 0) //jika ini merupakan operasi pertama/data head kosong
        {
            //next dan before masih null
            Head = temp;
            Tail = temp;
            node_count++;

        }else{ //memindahkan posisi pada data serta menyimpan alamatnya terlebih dahulu
            temp->next = Head; //alamat head disimpan dulu
            Head->before = temp; //alamat Head baru disimpan head lama
            Head = temp; //head baru adalah temp
            node_count++;
        }
    }
}

void HapusNode(Node *n)
{
    std::string input_nrp;
    std::cout << "Masukkan nrp yang ingin dihapus: ", std::getline (std::cin, input_nrp);
    while(n->nrp != input_nrp)
    {
        n = n->next;
    }

    if(n->next == NULL || n == Tail) //jika merupakan node terakhir
    {
        Tail=Tail->before;
        Tail->next=NULL;
        free(n);
    }else if (n->before == NULL || n == Head){ //jika merupakan node pertama
        Head=Head->next;
        Head->before=NULL;
        free(n);
    }else{ //jika tengah
        n->before->next=n->next;
        n->next->before=n->before;
        free(n);
    }
}

void printListFIFO(Node *n)
{
    int i = 0; //sebagai penghitung 
    do
    {
        std::cout << "Data ke-" << i+1 << std::endl;
        std::cout << "Nrp: " << n->nrp << std::endl;
        std::cout << "Nama: " << n->name << std::endl;
        std::cout << std::endl;
        
        n = n->next; 
        i++;
        
    }while (n != NULL);
}

void printListLIFO(Node *n)
{
    int i=0; //sebagai penanda saja
    do
    {   
        std::cout << "Data ke-" << i+1 << std::endl;
        std::cout << "Nrp: " << n->nrp << std::endl;
        std::cout << "Nama: " << n->name << std::endl;
        std::cout << std::endl;
        
        n = n->before; 
        i++;
        
    }while (n != NULL);
}

int main()
{
    std::string nrp;
    std::string nama;
    char pilihan; 
    int menu;

    std::cout << "================================================================\n";
    std::cout << "\t\t  DOUBLE LINKED LIST\n";
    std::cout << "================================================================\n";

    std::cout << "Operasi Yang Tersedia\n";
    std::cout << "1\tMenyisipkan data ke awal\n";
    std::cout << "2\tMencari Node/Simpul tertentu\n";
    std::cout << "3\tMenghapus Node/Simpul tertentu\n";
    std::cout << "4\tMenampilkan secara FIFO\n";
    std::cout << "5\tMenampilkan secara LIFO\n";

    do
    {
        std::cout << "Masukkan pilihan(kode angka saja): ", std::cin >> menu;
        std::cin.ignore();

        switch(menu)
        {
            case 1:
                SisipAwal();
                break;
            case 2:
                CariNode(Head);
                break;
            case 3:
                HapusNode(Head);
                break;
            case 4:
                printListFIFO(Head);
                break;
            case 5:
                printListLIFO(Tail);
                break;
            default:
                std::cout << "Operasi tersebut tidak ada!\n";
        }

        std::cout << "Ingin mengoperasikan lagi?(y/others): ", std::cin >> pilihan;
        std::cout << std::endl;
        std::cin.ignore();

    }while (pilihan == 'y' || pilihan == 'Y');

    std::cout << "================================================================\n";
    std::cout << "\t  TERIMA KASIH DAN MOHON MAAF ATAS BUG\n";
    std::cout << "================================================================\n";

    return 0;    
}