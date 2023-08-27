#include <stdio.h>

int main() {
    int bil;
    int cek = 0;
    int counter = 2;
    printf("Masukkan bilangan : "), scanf("%d", &bil);

    if (counter <= bil) {
        if (bil == 2){
            printf("%d adalah bilangan prima\n", bil);

        } else
            while (bil >= counter ) { //atau counter+1 karena takutnya while akan berhenti ketika counter mencapai bil tanpa melakukan proses terlebih dahulu
            ++counter;

                if (bil % counter == 0){
                ++cek;
                ++counter;//maybe?

                    if (cek > 1){
                        printf("%d bukanlah bilangan prima\n", bil);
                        //break;
                        goto done;

                    } else 
                        continue;

                } else
                continue;
            
            } 
            printf("%d adalah bilangan prima\n", bil);
            goto done;

    } else
        printf("%d bukanlah bilangan prima\n", bil);

    done:
    //hanya untuk pause
    getchar();
    getchar();

    return 0;

}
