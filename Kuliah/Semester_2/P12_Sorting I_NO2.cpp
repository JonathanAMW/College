#include <iostream>
#include <ctime>

#define MAX 20

void SelectionSort(int arr[])
{
    int i, j, temp, min, min_id;
    i = MAX - 1;
    while (i >= 0)
    {
        min_id = i;
        min = arr[i];
        for (j = i - 1; j >= 0; j--)
            if (arr[j] < min)
            {
                min = arr[j];
                min_id = j;
            }
        temp = arr[min_id];
        arr[min_id] = arr[i];
        arr[i] = temp;
        i--;
    }
}


int main()
{
    int data_awal[MAX], data_urut[MAX];
    int i;
    long k1, k2;
    printf("Sebelum pengurutan : \n");
    for (i = 0; i < MAX; i++)
    {
        srand(time(NULL) * (i + 1));
        data_awal[i] = rand() % 100 + 1;
        printf("%d ", data_awal[i]);
    }
    printf("\nSetelah pengurutan : \n");
    for (i = 0; i < MAX; i++)
        data_urut[i] = data_awal[i];
    time(&k1);
    SelectionSort(data_urut);
    time(&k2);
    for (i = 0; i < MAX; i++)
        printf("%d ", data_urut[i]);
    printf("\nWaktu = %ld\n", k2 - k1);
}