#include <stdio.h>
int main()
{
    int i, spasi, kolom, k=0, hitung = 0, hitung1 = 0;

    printf("Silakan masukan input: ");
    scanf("%d",&kolom);

    for(i=1; i<=kolom; ++i)
    {
      
        for(spasi=1; spasi <= kolom-i; ++spasi)
        {
            printf("  ");
            ++hitung; 
        }

    
        while(k != 2*i-1)
        {
          
            if (hitung <= kolom-1)
            {
                printf("%d ", i+k);
                ++hitung;
            }
            
            else
            {
                ++hitung1;
                printf("%d ", (i+k-2*hitung1));
            }
            ++k;
        }
       
        hitung1 = hitung = k = 0;

        printf("\n");
    }
    getchar();
    getchar();

    return 0;
}