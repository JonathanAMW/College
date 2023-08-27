#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10
int Data[MAX];
// Prosedur menukar data
void Tukar(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
// Prosedur pengurutan metode Shell
void ShellSort()
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
                if (Data[j] > Data[i])
                {
                    Tukar(&Data[j], &Data[i]);
                    Sudah = false;
                }
            }
        }
    }
}

// Prosedur pengurutan metode gelembung
void BubbleSort()
{
    int i, j;
    for (i = 1; i < MAX - 1; i++)
        for (j = MAX - 1; j >= i; j--)
            if (Data[j - 1] > Data[j])
                Tukar(&Data[j - 1], &Data[j]);
}

void main()
{
    int i;
    srand(0);
    // Membangkitkan bilangan acak
    
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
}