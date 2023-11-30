/* Implementasi algoritma utk mengubah infix menjadi postfix */
#include <stdio.h>
#include <string.h>
#define MAXSTACK 100
typedef char ItemType;
typedef struct
{
    char item[MAXSTACK]; /* Array yg berisi data tumpukan */
    int count;           /* menunjukkan indeks data paling atas dari stack
                          */
} Stack;
Stack tumpukan;
void InitializeStack(Stack *);
int Empty(Stack *);
int Full(Stack *);

void Push(ItemType, Stack *);
ItemType Pop(Stack *);
int drjt(char);
void konversi_cetak(char[]);

main(void)
{
    char tampung[MAXSTACK], jawab;
    puts("MENGUBAH NOTASI INFIX MENJADI PSOTFIX");
    puts("DENGAN MEMANFAATKAN STRUKTUR STACK");
    do
    {
        InitializeStack(&tumpukan);
        fflush(stdin);
        puts("");
        printf("Masukan ekspresi dalam notasi infix : ");
        fgets(tampung, sizeof(tampung), stdin);
        printf("Ungkapan postfixnya = ");
        konversi_cetak(tampung);
        puts("");
        fflush(stdin);
        printf("\nMau mencoba lagi (y/t) ? ");
        scanf("%c", &jawab);
        getchar();
    } while ((jawab == 'y') || (jawab == 'Y'));
}

void InitializeStack(Stack *S)
{
    S->count = 0;
}

int Empty(Stack *S)
{
    return (S->count == 0);
}

int Full(Stack *S)
{
    return (S->count == MAXSTACK);
}

void Push(ItemType x, Stack *S)
{
    if (Full(S)) // stack penuh
        printf("Stack penuh! Data tidak dapat masuk!");
    else
    {
        ++(S->count);
        S->item[S->count] = x;
    }
}

ItemType Pop(Stack *S)
{
    ItemType x;
    if (Empty(S))
    { // stack kosong
        printf("STACK KOSONG!");
        return 0;
    }
    else
    {

        x = (S->item[S->count]);
        --(S->count);
        return x;
    }
}

int drjt(char x) // menentukan derajat operator
{
    if (x == '(')
        return 0;
    else if ((x == '+') || (x == '-'))
        return 1;
    else if ((x == '*') || (x == '/'))
        return 2;
    else if (x == '^')
        return 3;
    else
        return -1; // invalid operator
}

void konversi_cetak(char temp[])
{
    int kurungbuka=0, kurungtutup=0, operator=0, operand=0;
    int i, pjg, valid = 1;
    char kar, smtr;
    pjg = strlen(temp) - 1;

  for(i = 0; i < pjg; i++)
    {
      kar = temp[i]; // membaca input per karakter
        switch (kar)
        {
        case '(':
          kurungbuka++;
          break;
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            operand++;
            break;
        case '+':
        case '-':
        case '*':
        case '/':
          operator++;
          break;
        case ')':
            kurungtutup++;      
            break;
        } // end of switch-case
         // end of looping for
    }

    //menentukan apakah error tidak
    if(kurungbuka != kurungtutup){
      printf("Notasi infix salah, kurung tidak lengkap\n");
      goto end;
    }else if(operand == operator){
      printf("Notasi infix salah, operand tidak lengkap\n");
      goto end;
    }else if(operator != operand-1){
      printf("Notasi infix salah, operator tidak lengkap\n");
      goto end;
    }else{
      
    }  
  
    for (i = 0; i < pjg; i++)
    {
        kar = temp[i]; // membaca input per karakter
        switch (kar)
        {
        // if kar = '(' -> push ke dalam tumpukan
        case '(':
            Push(kar, &tumpukan);
            break;
        // if kar = operand -> langsung ditulis
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':

            printf("%c", kar);
            break;
        /* if kar = operator -> jika tumpukan kosong atau derajad
        kar lbh tinggi dibanding derajad ujung tumpukan, push
        operator ke dalam tumpukan. Jika tidak, pop ujung
        tumpukan dan tulis;

        Ulangi pembandingan kar dengan ujung tumpukan.
        Kemudian kar di-push
        */
        case '+':
        case '-':
        case '*':
        case '/':
        case '^':
            if ((Empty(&tumpukan)) ||
                ((drjt(kar) > drjt(tumpukan.item[tumpukan.count]))))
                Push(kar, &tumpukan);
            else
            {
                do
                {
                    smtr = Pop(&tumpukan);
                    printf("%c", smtr);

                } while (drjt(kar) <
                         drjt(tumpukan.item[tumpukan.count]));

                Push(kar, &tumpukan);
            }
            break;
        /* if kar = ')' -> pop dan tulis semua isi tumpukan sampai

        ujung tumpukan = '('.

        Pop juga tanda '(' ini, tetapi tidak usah ditulis
        */
        case ')':
            while (tumpukan.item[tumpukan.count] != '(')
            {
                smtr = Pop(&tumpukan);
                printf("%c", smtr);
            }
            Pop(&tumpukan);
            break;
        default: // selain dari kar yang diijinkan
            valid = 0;
            puts("INVALID STSTEMEN");
            break;
        } // end of switch-case
    }     // end of looping for

    end: //statement kosong
      
    /*
    Jika statemen valid, akhir notasi infix telah tercapai,
    sedangkan tumpukan masih belum kosong, pop semua isi tumpukan
    dan tulis hasilnya
    */
    if ((valid != 0) && (!Empty(&tumpukan)))
    {
        smtr = Pop(&tumpukan);
        printf("%c", smtr);
    }
}