#include <iostream>
#include <ctime>

#define MAX 20

void InsertionSort(int arr[])
{
    int key;

    for(int i=0; i<MAX; i++)
    {
        key = arr[i];
        int j = i-1;
        while(j>=0 && arr[j]<key)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}


int main()
{
    int data_awal[MAX], data_urut[MAX];
    int i;
    printf("Sebelum pengurutan : \n");
    for (i = 0; i < MAX; i++)
    {
        srand(time(NULL) * (i + 1));
        data_awal[i] = rand() % 100 + 1;
        printf("%d ", data_awal[i]);
    }
    printf("\n");
    for (i = 0; i < MAX; i++)
        data_urut[i] = data_awal[i];
    
    InsertionSort(data_urut);

    std::cout << "\nSetelah dilakukan Insertion Sort (Ascending):\n";
    for(int j=0; j<MAX; j++)
        std::cout << data_urut[j] << " ";

    return 0;
}