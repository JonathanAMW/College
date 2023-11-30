#include <stdio.h>

int main()
{
   float a; //Total harga
   float b; //Total harga setelah diskon
   int c; //Konfirmasi
   int x; //Kode item
   int y; //Total jenis barang yang ingin dibeli
   float z = 1000000; //Total uang

   select:
   printf("Your money: Rp%.2f\n", z);
   printf("Welcome to our shop, weary traveler! May us take your order?\n");
   printf("1.Health Potion, Rp5.000,00\n");
   printf("2.Magic Potion, Rp8.000,00\n");
   printf("Today's News: We got a discount up to 5 percent for order ranged on Rp100.000,00 and higher!\n");

   printf("Choose the item of your choice by its code!\n"), scanf("%d", &x);


    switch(x){
        case 1:
        printf("How many would you like to buy?: "), scanf("%d", &y);
        a = a + 5000 * y;
        //goto kalkulasi;
        break;

        case 2:
        printf("How many would you like to buy?: "), scanf("%d", &y);
        a = a + 8000 * y;
        //goto kalkulasi;
        break;

        default:
        printf("I'm sorry, but there's no such item in our shop!\n ");
        //code untuk kembali ke tempat yang sudah ditentukan
        goto select;
    }

    kalkulasi:
    if (z >= a){
        if (a < 100000){
        printf("Everything will be: Rp%.2f\n", a);
        printf("You got no discount, okay!\n");
        goto pertanyaan;

        } else

        b = a - (5 * a / 100) ;

        printf("Everything will be: Rp%.2f\n", b);
        printf("You got a 5 percent discount, okay!\n");
        goto pertanyaan;

    } else
    printf("Sorry, but you don't have enough money!\n");
    goto select;

    pertanyaan:
        printf("Anything else?\n");
        printf("1.Buy more\n");
        printf("2.Done\n");
        scanf("%d", &c);
        switch(c){
        case 1:
            goto select;
            break;

        case 2:
            printf("Have a nice day, traveler!\n");
            //goto selesai;
            break;

        default:
            printf("What do you mean?\n");
            goto pertanyaan;
        }
    z=z-a;
    printf("Currently you have: Rp%.2f\n", z);

    
    return 0;

}
