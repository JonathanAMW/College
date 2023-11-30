//stdio.h adalah library standart untuk c
#include <stdio.h> 

int main() {
    int numbers [5], total=0;

    //assignment
    for(int i=1; i<=5; i++){
        numbers[i-1]=i+1;
        printf("Nilai ke-%d: %d\n", i, numbers[i-1]);
    }

    //pentotalan
    for(int j=0; j<5; j++){
        total+=numbers[j];

    }

    //diprint
    printf("Totalnya adalah: %d", total);

    return 0;
}