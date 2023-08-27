#include <iostream>
#include <ctime>

#define MAX 10

typedef struct mahasiswa{
    std::string nrp;
    std::string nama;
    int kelas;
}MHS;

void InsertionSortAscending(MHS arr[])
{
    std::string key;

    for(int i=0; i<MAX; i++)
    {
        key = arr[i].nrp;
        int j = i-1;
        while(j>=0 && arr[j].nrp>key)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1].nrp = key;
    }
}

void InsertionSortDescending(MHS arr[])
{
    std::string key;

    for(int i=0; i<MAX; i++)
    {
        key = arr[i].nrp;
        int j = i-1;
        while(j>=0 && arr[j].nrp<key)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1].nrp = key;
    }
}

void SelectionSortAscending(MHS arr[])
{
    int i, j, min_id;
    std::string min, temp;
    i = 0;
    while (i < MAX - 1)
    {
        min_id = i;
        min = arr[i].nrp;
        for (j = i + 1; j < MAX; j++)
            if (arr[j].nrp < min)
            {
                min = arr[j].nrp;
                min_id = j;
            }
        temp = arr[min_id].nrp;
        arr[min_id] = arr[i];
        arr[i].nrp = temp;
        i++;
    }
}

void SelectionSortDescending(MHS arr[])
{
    int i, j, min_id;
    std::string min, temp;
    i = 0;
    while (i < MAX - 1)
    {
        min_id = i;
        min = arr[i].nrp;
        for (j = i + 1; j < MAX; j++)
            if (arr[j].nrp > min)
            {
                min = arr[j].nrp;
                min_id = j;
            }
        temp = arr[min_id].nrp;
        arr[min_id] = arr[i];
        arr[i].nrp = temp;
        i++;
    }
}

int main()
{
    //Mengisi data
    MHS p1;
    p1.nrp = "21001";
    p1.nama = "Mana";
    p1.kelas = 1;
    MHS p2;
    p2.nrp = "21002";
    p2.nama = "Bunga";
    p2.kelas = 2;
    MHS p3;
    p3.nrp = "21003";
    p3.nama = "Rusadri";
    p3.kelas = 3;
    MHS p4;
    p4.nrp = "21004";
    p4.nama = "Kunto";
    p4.kelas = 2;
    MHS p5;
    p5.nrp = "21005";
    p5.nama = "Nyoman";
    p5.kelas = 3;
    MHS p6;
    p6.nrp = "21006";
    p6.nama = "Akuta";
    p6.kelas = 3;
    MHS p7;
    p7.nrp = "21007";
    p7.nama = "Narto";
    p7.kelas = 1;
    MHS p8;
    p8.nrp = "21008";
    p8.nama = "Mustadah";
    p8.kelas = 2;
    MHS p9;
    p9.nrp = "21009";
    p9.nama = "Ricardo";
    p9.kelas = 1;
    MHS p10;
    p10.nrp = "21010";
    p10.nama = "Budi";
    p10.kelas = 3;

    MHS dataMahasiswa [MAX] = {p1, p3, p2, p10, p5, p4, p7, p9, p8, p6};

    int i;
    char pilihan;
    long k1, k2;
    
    std::cout << "Mengurutkan Data Mahasiswa berdasarkan NRP\n";
    printf("Sebelum pengurutan : \n");
    for (i = 0; i < MAX; i++)
    {
       std::cout << "Pegawai ke-" << i+1 << ":\n";
        std::cout << "NIP\t:\t" << dataMahasiswa[i].nrp << '\n';
        std::cout << "Nama\t:\t" << dataMahasiswa[i].nama << '\n';
        std::cout << "Alamat\t:\t" << dataMahasiswa[i].kelas << '\n';
        std::cout << '\n';
    }

    std::cout << "1. Insertion Sort\n";
    std::cout << "2. Selection Sort\n";
    std::cout << "Ingin menampilkan data menggunakan apa?(1/2): ", std::cin >> pilihan;

    switch(pilihan)
    {
        case '1':
            std::cout << "\n1. Ascending\n";
            std::cout << "2. Descending\n";
            std::cout << "Ingin menampilkan data secara apa?(1/2): ", std::cin >> pilihan;
            switch(pilihan)
            {
                case '1':
                    InsertionSortAscending(dataMahasiswa);
                    break;
                case '2':
                    InsertionSortDescending(dataMahasiswa);
                    break;
                default:
                    std::cout << "Pilihan tidak ada!\n";
                    return 0;
            }
            break;

        case '2':
            std::cout << "\n1. Ascending\n";
            std::cout << "2. Descending\n";
            std::cout << "Ingin menampilkan data secara apa?(1/2): ", std::cin >> pilihan;
            switch(pilihan)
            {
                case '1':
                    SelectionSortAscending(dataMahasiswa);
                    break;
                case '2':
                    SelectionSortDescending(dataMahasiswa);
                    break;
                default:
                    std::cout << "Pilihan tidak ada!\n";
                    return 0;
            }
            break;

        default:
            std::cout << "Pilihan tidak ada!\n";
            return 0;
    }

    std::cout << std::endl;
    time(&k1);
    time(&k2);
    printf("\nSetelah pengurutan: \n");
    for (i = 0; i < MAX; i++)
    {
        std::cout << "Pegawai ke-" << i+1 << ":\n";
        std::cout << "NIP\t:\t" << dataMahasiswa[i].nrp << '\n';
        std::cout << "Nama\t:\t" << dataMahasiswa[i].nama << '\n';
        std::cout << "Alamat\t:\t" << dataMahasiswa[i].kelas << '\n';
        std::cout << '\n';
    }
    printf("\nWaktu = %ld\n", k2 - k1);
    return 0;
}