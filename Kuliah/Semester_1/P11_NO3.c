#include<stdio.h>
 
int main(){
    awalan:
    int i,j,n;
    char pilihan;
    
    printf("Silakan masukkan input: "), scanf("%d",&n);
      
    for(i=2;i<=n;i++){
        int c=0;
        for(j=1;j<=i;j++){
            if(i%j==0){
                c++;
            }
        }
         
       if(c==2){
            printf("%d ",i);
        }
    }
    
    pertanyaan:
    printf("\napakah anda ingin keluar (y/t)?\n"), scanf(" %c", &pilihan);
    switch(pilihan){
      case 'y':
      goto done;
      break;

      case 't':
      goto awalan;
      break;

      default:
      goto pertanyaan;
      break;
    
    }
    
    done:
    printf("Mematikan sistem, silakan menekan tombol apapun!\n");
    //pause system
    getchar();
    getchar();  
   
    return 0;
}