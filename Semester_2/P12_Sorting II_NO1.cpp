#include <iostream>

#define MAX 10
int Data[MAX];
// Prosedur menukar data
void Tukar(int *a, int *b)
{
    int temp;
    std::cout << "nilai temp: " << temp << std::endl;
    temp = *a;
    std::cout << "nilai temp setelah diassign *a: " << temp << std::endl;
    *a = *b;
    std::cout << "nilai *a setelah diassign *b: " << *a << std::endl;
    *b = temp;
    std::cout << "nilai *b setelah diassign temp: " << *b << std::endl;
}
// Prosedur pengurutan metode Shell
void ShellSort()
{
    std::cout << "\n===========================PERUBAHAN DATA===========================" << std::endl;
    int Jarak, i, j;
    bool Sudah;
    Jarak = MAX;
    while (Jarak > 1)
    {
        std::cout << "Jarak sebelum: " << Jarak << std::endl;
        Jarak = Jarak / 2;
        std::cout << "Jarak sesudah: " << Jarak << std::endl;
        Sudah = false;
        while (!Sudah)
        {
            Sudah = true;
            for (j = 0; j < MAX - Jarak; j++)
            {
                std::cout << "j sebelum: " << j << std::endl;
                i = j + Jarak;
                std::cout << "nilai i adalah j + Jarak: " << std::endl;
                if (Data[j] > Data[i])
                {
                    std::cout << "Nilai Data[j] saat ini: " << Data[j] << std::endl;
                    std::cout << "Nilai Data[i] saat ini: " << Data[i] << std::endl;
                    Tukar(&Data[j], &Data[i]);
                    Sudah = false;
                }
            }
        }
    }
    std::cout << "\n====================================================================" << std::endl;
}

// Prosedur pengurutan metode gelembung
void BubbleSort()
{
    int i, j;
    std::cout << "\n===========================PERUBAHAN DATA===========================" << std::endl;
    for (i = 1; i < MAX - 1; i++){   
        std::cout << "Nilai i saat ini: " << i << std::endl;
        for (j = MAX - 1; j >= i; j--){
            std::cout << "Nilai j saat ini: " << j << std::endl;
            if (Data[j - 1] > Data[j]){
                std::cout << "Nilai Data[j-1] saat ini: " << Data[j-1] << std::endl;
                std::cout << "Nilai Data[j] saat ini: " << Data[j] << std::endl;
                Tukar(&Data[j - 1], &Data[j]);
            }

        }
    }
    std::cout << "\n====================================================================" << std::endl;
}   

int main()
{
    int i;
    srand(0);
    // Membangkitkan bilangan acak
    
    std::cout << "MENGGUNAKAN SHELL SORT" << std::endl;
    printf("DATA SEBELUM TERURUT");
    for (i = 0; i < MAX; i++)
    {
        Data[i] = (int)rand() / 1000 + 1;
        printf("\nData ke %d : %d ", i, Data[i]);
    }
    ShellSort();
    // Data setelah terurut
    printf("\nDATA SETELAH TERURUT");
    for (i = 0; i < MAX; i++)
    {
        printf("\nData ke %d : %d ", i, Data[i]);
    }

    std::cout << "\n\n\nMENGGUNAKAN BUBBLE SORT" << std::endl;
    printf("DATA SEBELUM TERURUT");
    for (i = 0; i < MAX; i++)
    {
        Data[i] = (int)rand() / 1000 + 1;
        printf("\nData ke %d : %d ", i, Data[i]);
    }
    BubbleSort();
    // Data setelah terurut
    printf("\nDATA SETELAH TERURUT");
    for (i = 0; i < MAX; i++)
    {
        printf("\nData ke %d : %d ", i, Data[i]);
    }
}