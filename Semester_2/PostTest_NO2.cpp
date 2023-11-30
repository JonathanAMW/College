#include <iostream>
#include <vector>


int main()
{
    int size;

    std::cout << "masukkan besar array: ", std::cin >> size;
    size = 5;
    std::vector<int> arr(size, 0);

    std::cout << "\nisikan data array\n";

    for(int i=0; i<size; i++) 
    {
        std::cout << "isi data ke- " << i+1 << ": ",  std::cin >> arr[i];

    }

    for(int i=0; i<size; i++)
    {
        int count = size-1;
        if(i==size-1){
            arr[i] = -1;
            break;
        } //angka terakhir
        for(int j=i+1; j<size; j++)
        {
            if(i==size-1) //angka terakhir
            {
                arr[i] = -1;
                break;
            }else if(arr[i]<arr[j]){
                arr[i]=arr[j];
                break;
            }else if(arr[i]>=arr[j]){
                if(j==size-1){
                    arr[i]=-1;
                    break;
                }
            }
        }
    }

    std::cout << "output: ";

    for(int i=0; i<size; i++)
    {
        std::cout << arr[i] << " ";
    }
}
