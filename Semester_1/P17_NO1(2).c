//stdio.h adalah library standart dari bahasa c 
#include <stdio.h>

int main(){
    int bil, array[10],arraypenentu[10] , n=0, m=0;

    printf("Masukkan bilangan(maks 10 baris dan harus bilangan bulat): "), scanf("%d", &bil);

    //pengambilan angka
    while(bil!=0){
        int angka=0;
        angka=bil%10;
        array[n]=angka;
        bil/=10;
        n++;

    }
    
    int x=0;
    for(int i = 0; i < n; i++) {    
        for(int j = i + 1; j < n; j++) {    
            if(array[i] == array[j]){  
                //menentukan duplikasi pada arraypenentu  
                int counter=0;
                for(int y=0; y<10; y++){ 
                    if(array[j]==arraypenentu[y]){ 
                        counter++;;
                    }
                }
                if(counter==0){
                    arraypenentu[x]=array[j];
                    x++;
                    m++;

                }else
                    continue;
            }     
        }    
    }  

    printf("\nAngka tersebut adalah: \n");
    for(int d=0; d<m; d++){
        printf("%d ", arraypenentu[d]);

    }

    return 0;
}