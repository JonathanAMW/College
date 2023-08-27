#include <iostream>
#include <ctime>

#define MAX 20

void InsertionSortDescending(int arr[])
{
    int i, j, key;
    for (i = MAX-1; i >= 0; i--)
    {
        key = arr[i];
        j = i + 1;
        while (j < MAX && arr[j] < key)
        {
            arr[j - 1] = arr[j];
            j++;
        }
        arr[j - 1] = key;
    }
}

void InsertionSortAscending(int arr[])
{
    int i, j, key;
    for (i = MAX-1; i >= 0; i--)
    {
        key = arr[i];
        j = i + 1;
        while (j < MAX && arr[j] > key)
        {
            arr[j - 1] = arr[j];
            j++;
        }
        arr[j - 1] = key;
    }
}

int main()
{
    int data_awal[MAX], data_urut[MAX];
    int i;
    long k1, k2;
    
    std::cout << "Mengurutkan dari kanan!\n";
    printf("Sebelum pengurutan : \n");
    for (i = 0; i < MAX; i++)
    {
        srand(time(NULL) * (i + 1));
        data_awal[i] = rand() % 100 + 1;
        printf("%d ", data_awal[i]);
    }
    for (i = 0; i < MAX; i++)
        data_urut[i] = data_awal[i];
    
    std::cout << std::endl;
    time(&k1);
    InsertionSortAscending(data_urut);
    time(&k2);
    printf("\nSetelah pengurutan Ascending: \n");
    for (i = 0; i < MAX; i++)
        printf("%d ", data_urut[i]);
    printf("\nWaktu = %ld\n", k2 - k1);

    InsertionSortDescending(data_urut);
    printf("\nSetelah pengurutan Descending: \n");
    for (i = 0; i < MAX; i++)
        printf("%d ", data_urut[i]);
    printf("\nWaktu = %ld\n", k2 - k1);
}