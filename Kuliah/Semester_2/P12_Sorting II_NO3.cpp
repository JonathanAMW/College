#include <iostream>

#define MAX 10


typedef struct pegawai{
    int nip;
    std::string nama;
    std::string alamat;
    char golongan;

}PGW;



// Prosedur menukar data
void Tukar(PGW *a, PGW *b)
{
    PGW temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

class SortNama{
    public:
    static void ShellSortAscending(PGW Data[])
    {
        int Jarak, i, j;
        bool Sudah;
        Jarak = MAX;
        while (Jarak > 1)
        {
            Jarak = Jarak / 2;
            Sudah = false;
            while (!Sudah)
            {
                Sudah = true;
                for (j = 0; j < MAX - Jarak; j++)
                {
                    i = j + Jarak;
                    if (Data[j].nama > Data[i].nama)
                    {
                        Tukar(&Data[j], &Data[i]);
                        Sudah = false;
                    }
                }
            }
        }
    }

    static void ShellSortDescending(PGW Data[])
    {
        int Jarak, i, j;
        bool Sudah;
        Jarak = MAX;
        while (Jarak > 1)
        {
            Jarak = Jarak / 2;
            Sudah = false;
            while (!Sudah)
            {
                Sudah = true;
                for (j = 0; j < MAX - Jarak; j++)
                {
                    i = j + Jarak;
                    if (Data[j].nama < Data[i].nama)
                    {
                        Tukar(&Data[j], &Data[i]);
                        Sudah = false;
                    }
                }
            }
        }
    }

    // Prosedur pengurutan metode gelembung
    static void BubbleSortAscending(PGW data[])
    {
        int i, j;
        for (i = 1; i < MAX - 1; i++){   
            for (j = MAX - 1; j >= i; j--){
                if (data[j - 1].nama < data[j].nama){
                    Tukar(&data[j - 1], &data[j]);
                }

            }
        }
    }   

    static void BubbleSortDescending(PGW data[])
    {
        int i, j;
        for (i = 1; i < MAX - 1; i++){   
            for (j = MAX - 1; j >= i; j--){
                if (data[j - 1].nama > data[j].nama){
                    Tukar(&data[j - 1], &data[j]);
                }

            }
        }
    }   
};

class SortNIP{
    public:
    static void ShellSortAscending(PGW Data[])
    {
        int Jarak, i, j;
        bool Sudah;
        Jarak = MAX;
        while (Jarak > 1)
        {
            Jarak = Jarak / 2;
            Sudah = false;
            while (!Sudah)
            {
                Sudah = true;
                for (j = 0; j < MAX - Jarak; j++)
                {
                    i = j + Jarak;
                    if (Data[j].nip > Data[i].nip)
                    {
                        Tukar(&Data[j], &Data[i]);
                        Sudah = false;
                    }
                }
            }
        }
    }

    static void ShellSortDescending(PGW Data[])
    {
        int Jarak, i, j;
        bool Sudah;
        Jarak = MAX;
        while (Jarak > 1)
        {
            Jarak = Jarak / 2;
            Sudah = false;
            while (!Sudah)
            {
                Sudah = true;
                for (j = 0; j < MAX - Jarak; j++)
                {
                    i = j + Jarak;
                    if (Data[j].nip < Data[i].nip)
                    {
                        Tukar(&Data[j], &Data[i]);
                        Sudah = false;
                    }
                }
            }
        }
    }

    // Prosedur pengurutan metode gelembung
    static void BubbleSortAscending(PGW data[])
    {
        int i, j;
        for (i = 1; i < MAX - 1; i++){   
            for (j = MAX - 1; j >= i; j--){
                if (data[j - 1].nip < data[j].nip){
                    Tukar(&data[j - 1], &data[j]);
                }

            }
        }
    }   

    static void BubbleSortDescending(PGW data[])
    {
        int i, j;
        for (i = 1; i < MAX - 1; i++){   
            for (j = MAX - 1; j >= i; j--){
                if (data[j - 1].nip > data[j].nip){
                    Tukar(&data[j - 1], &data[j]);
                }

            }
        }
    }   
};


int main()
{
    //Mengisi data
    PGW p1;
    p1.nip = 21001;
    p1.nama = "Mana";
    p1.alamat = "Surabaya";
    p1.golongan = 'A';
    PGW p2;
    p2.nip = 21002;
    p2.nama = "Bunga";
    p2.alamat = "Surakarta";
    p2.golongan = 'O';
    PGW p3;
    p3.nip = 21003;
    p3.nama = "Rusadri";
    p3.alamat = "Solo";
    p3.golongan = 'A';
    PGW p4;
    p4.nip = 21004;
    p4.nama = "Kunto";
    p4.alamat = "Yogyakarta";
    p4.golongan = 'B';
    PGW p5;
    p5.nip = 21005;
    p5.nama = "Nyoman";
    p5.alamat = "Aceh";
    p5.golongan = 'O';
    PGW p6;
    p6.nip = 21006;
    p6.nama = "Akuta";
    p6.alamat = "Jakarta";
    p6.golongan = 'B';
    PGW p7;
    p7.nip = 21007;
    p7.nama = "Narto";
    p7.alamat = "Lampung";
    p7.golongan = 'B';
    PGW p8;
    p8.nip = 21008;
    p8.nama = "Mustadah";
    p8.alamat = "Kediri";
    p8.golongan = 'A';
    PGW p9;
    p9.nip = 21009;
    p9.nama = "Ricardo";
    p9.alamat = "Bogor";
    p9.golongan = 'O';
    PGW p10;
    p10.nip = 21010;
    p10.nama = "Budi";
    p10.alamat = "Padang";
    p10.golongan = 'B';

    PGW dataPegawai[MAX] = {p1, p3, p2, p10, p5, p4, p7, p9, p8, p6};

    int i;
    char pilihan;

    std::cout << "1.\tShell Sort\n";
    std::cout << "2.\tBubble Sort\n";
    std::cout << "Ingin menampilkan data menggunakan apa?(1/2): ", std::cin >> pilihan;

    switch(pilihan)
    {
        case '1':
            std::cout << "MENGGUNAKAN SHELL SORT" << std::endl;
            printf("DATA SEBELUM TERURUT\n");
            for (i = 0; i < MAX; i++)
            {
                std::cout << "Pegawai ke-" << i+1 << ":\n";
                std::cout << "NIP\t:\t" << dataPegawai[i].nip << std::endl;
                std::cout << "Nama\t:\t" << dataPegawai[i].nama << std::endl;
                std::cout << "Alamat\t:\t" << dataPegawai[i].alamat << std::endl;
                std::cout << "Golongan:\t" << dataPegawai[i].golongan << std::endl;
                std::cout << std::endl;
            }
            std::cout << "1.\tAscending\n";
            std::cout << "2.\tDescending\n";
            std::cout << "Ingin menampilkan data secara apa?(1/2): ", std::cin >> pilihan;
            switch(pilihan)
            {
                case '1':
                    std::cout << "1.\tNIP\n";
                    std::cout << "2.\tNama\n";
                    std::cout << "Ingin menampilkan data berdasarkan apa?(1/2): ", std::cin >> pilihan;
                    switch(pilihan)
                    {
                        case '1':
                            SortNIP::ShellSortAscending(dataPegawai);
                            break;

                        case '2':
                            SortNama::ShellSortAscending(dataPegawai);
                            break;

                        default:
                            std::cout << "Pilihan tidak ada!" << std::endl;
                            return 0;
                    }
                    break;

                case '2':
                    std::cout << "1.\tNIP\n";
                    std::cout << "2.\tNama\n";
                    std::cout << "Ingin menampilkan data berdasarkan apa?(1/2): ", std::cin >> pilihan;
                    switch(pilihan)
                    {
                        case '1':
                            SortNIP::BubbleSortDescending(dataPegawai);
                            break;

                        case '2':
                            SortNama::BubbleSortDescending(dataPegawai);
                            break;

                        default:
                            std::cout << "Pilihan tidak ada!" << std::endl;
                            return 0;
                    }
                    break;

                default:
                    std::cout << "Pilihan tidak ada!" << std::endl;
                    return 0;
            }
            break;
            
        case '2':
            std::cout << "MENGGUNAKAN BUBBLE SORT" << std::endl;
            printf("DATA SEBELUM TERURUT\n");
            for (i = 0; i < MAX; i++)
            {
                std::cout << "Pegawai ke-" << i+1 << ":\n";
                std::cout << "NIP\t:\t" << dataPegawai[i].nip << std::endl;
                std::cout << "Nama\t:\t" << dataPegawai[i].nama << std::endl;
                std::cout << "Alamat\t:\t" << dataPegawai[i].alamat << std::endl;
                std::cout << "Golongan:\t" << dataPegawai[i].golongan << std::endl;
                std::cout << std::endl;
            }
            std::cout << "1.\tAscending\n";
            std::cout << "2.\tDescending\n";
            std::cout << "Ingin menampilkan data secara apa?(1/2): ", std::cin >> pilihan;
            switch(pilihan)
            {
                case '1':
                    std::cout << "1.\tNIP\n";
                    std::cout << "2.\tNama\n";
                    std::cout << "Ingin menampilkan data berdasarkan apa?(1/2): ", std::cin >> pilihan;
                    switch(pilihan)
                    {
                    case '1':
                        SortNIP::BubbleSortAscending(dataPegawai);
                        break;

                    case '2':
                        SortNama::BubbleSortAscending(dataPegawai);
                        break;

                    default:
                        std::cout << "Pilihan tidak ada!" << std::endl;
                        return 0;
                    }
                    break;

                case '2':
                    std::cout << "1.\tNIP\n";
                    std::cout << "2.\tNama\n";
                    std::cout << "Ingin menampilkan data berdasarkan apa?(1/2): ", std::cin >> pilihan;
                    switch(pilihan)
                    {
                    case '1':
                        SortNIP::BubbleSortDescending(dataPegawai);
                        break;

                    case '2':
                        SortNama::BubbleSortDescending(dataPegawai);
                        break;

                    default:
                        std::cout << "Pilihan tidak ada!" << std::endl;
                        return 0;
                    }
                    break;

                default:
                    std::cout << "Pilihan tidak ada!" << std::endl;
                    return 0;
            }
        break;

        default:
            std::cout << "Pilihan tidak ada!" << std::endl;
            return 0;
    }
    
    printf("DATA SETELAH TERURUT\n");
    for (i = 0; i < MAX; i++)
    {
        std::cout << "Pegawai ke-" << i+1 << ":\n";
        std::cout << "NIP\t:\t" << dataPegawai[i].nip << std::endl;
        std::cout << "Nama\t:\t" << dataPegawai[i].nama << std::endl;
        std::cout << "Alamat\t:\t" << dataPegawai[i].alamat << std::endl;
        std::cout << "Golongan:\t" << dataPegawai[i].golongan << std::endl;
        std::cout << std::endl;
    }
    
}