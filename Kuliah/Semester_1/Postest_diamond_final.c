#include<stdio.h>

int kar1=1, kar2=1; //variabel global untuk mengatur pembagian karakter

void sayap(int sayap0){ //mengatur spasi pada samping kiri dan kanan
    for(int sayap=sayap0; sayap>0; sayap--){
        printf(" ");
    }
}

void badan(int badan0){ //mengatur spasi dalam badan/tengah
    for(int badan=badan0; badan>0; badan--){
        printf(" ");
    }
}

void spasi(int spasi0){ //mengatur spasi diluar bangun datar
    for(int spasi=spasi0; spasi>0; spasi--){ //spasi awal
        printf(" ");
    }
}

void decide(int i, int input){ //mengatur karakter yang ditampilkan
    if(i==input/2){ //mengatur pusat
        if(i%2==0){ //mengatur
            if(kar1<2){
                printf("#");
                kar1=1;
            }else if(kar1>=2){
                printf("@");
                kar1=2;
            }
        }else 
            if(kar1<2){
                printf("@");
                kar1=1;
            }else if(kar1>=2){
                printf("#");
                kar1=2;
            }

    }else if(i%2==0){ //mengatur lainnya
        if(kar1==0||kar1==1){
            printf("#");
            kar1++;
        }else if (kar1==2){
            printf("@");
            kar1++;
        }else if(kar1==3){
            printf("@");
            kar1=0;
        }else
            printf("trouble");

    }else //mengatur setelah header
        if(kar2==0||kar2==1){
            printf("@");
            kar2++;
        }else if (kar2==2){
            printf("#");
            kar2++;
        }else if(kar2==3){
            printf("#");
            kar2=0;
        }else
            printf("trouble");
        
}

int main(){

    int input; 
    printf("MENAMPILKAN SEGI ENAM/DIAMOND\n");
    printf("Masukkan input: "), scanf("%d", &input);
    
    //spasi0 mengontrol spasi luar, sayap0 mengatur sayap, badan0 mengatur badan
    int spasi0=input/2, sayap0=2, badan0=input-sayap0*2; //karena yang berbah selalu badan

    for(int i=0; i<input; i++){ //tinggi
        spasi(spasi0);

        if(i==0||i==input-1){ //header
            for(int a=input+1; a>=0; a--){ //header dan footer
                if(a%2==0){
                    printf("#");
                }else 
                    printf("@");
            }
            printf("\n");
            spasi0--;

        } else if(i>0 && i<input/2){//bagian atas
            decide(i,input);
            sayap(sayap0);
            decide(i,input);
            badan(badan0);
            decide(i,input);
            sayap(sayap0);
            decide(i,input);
            printf("\n");
            sayap0+=2;
            badan0-=2;
            spasi0--;

        } else if(i==input/2){//pusat
            decide(i,input);
            sayap(sayap0);
            printf("$");
            sayap(sayap0);
            decide(i,input);
            printf("\n");
            spasi0++;

        } else if(i>input/2 && i<input){//bagian bawah
            sayap0-=2;
            badan0+=2;
            spasi0++;
            decide(i,input);
            sayap(sayap0);
            decide(i,input);
            badan(badan0);
            decide(i,input);
            sayap(sayap0);
            decide(i,input);
            printf("\n");

        }
    }

   return 0;
}