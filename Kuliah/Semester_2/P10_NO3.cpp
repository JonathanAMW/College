#include <iostream>
#include <stack>

#define N 4
#define M 1000

void Tampil(int data[N][N], char *judul) //sama seperti sebelumnya
{
    printf("%s = \n", judul);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            if (data[i][j] >= M)
                printf("M ");
            else
                printf("%d ", data[i][j]);
        printf("\n");
    }
}

void Warshall(int Q[N][N], int P[N][N], int R[N][N])
{
    for (int k = 0; k < N; k++) //loop sampai k mencapai satu kurang N
        for (int i = 0; i < N; i++) //loop sampai i mencapai satu kurang N
            for (int j = 0; j < N; j++) //loop sampai j mencapai satu kurang N
            {
                P[i][j] = P[i][j] | (P[i][k] & P[k][j]); //menentukan apakah ada jalur yang tersedia
                if ((Q[i][k] + Q[k][j]) < Q[i][j]) //jika Q[i][k] + Q[k][j] lebih kecil dari Q[i][j]
                {
                    Q[i][j] = Q[i][k] + Q[k][j]; //Q[i][j] dimasukkan nilai penjumlahan Q[i][k] + Q[k][j]
                    if (R[k][j] == 0) //jika rute kosong
                        R[i][j] = k + 1; //rute dimasukkan nilai k+1
                    else //selain itu
                        R[i][j] = R[k][j]; //rute dimasukkan nilai dari rute R[k][j]
                }
            }
}

void RouteSearch(std::stack<int> S, int from, int to, int Q[N][N], int R[N][N])
{
    for (int i=to-1; i>=0; i--){
        if(R[from-1][i]==0)
            break;

        S.push(R[from-1][i]);
    }

    std::cout << "Rutenya adalah: ";
    std::cout << from << "-" ;
    while(!S.empty()){
        std::cout << S.top() << "-";
        S.pop();
    }
    std::cout << to << std::endl;

    //beban minimal yang diambil dari matriks beban dengan indeks asal dan tujuan
    std::cout << "Beban minimal: " << Q[from-1][to-1] << std::endl; 

}

int main()
{
    char input;
    int from, to;
    std::stack<int> Stack;

    int Beban[N][N] = {M, 3, 5, M,
                       M, M, M, 6,
                       M, M, M, 5, 
                       M, M, M, M};
    int Jalur[N][N] = {0, 1, 1, 0,
                       0, 0, 0, 1,
                       0, 0, 0, 1, 
                       0, 0, 0, 0};
    int Rute[N][N] =  {M, 0, 0, M,
                       M, M, M, 0,
                       M, M, M, 0, 
                       M, M, M, M};
    Tampil(Beban, "Beban");
    Tampil(Jalur, "Jalur");
    Tampil(Rute, "Rute");
    Warshall(Beban, Jalur, Rute);
    printf("Matriks setelah Algoritma Warshall : \n");
    Tampil(Beban, "Beban");
    Tampil(Jalur, "Jalur");
    Tampil(Rute, "Rute");

    std::cout << "Masukkan asal: ", std::cin >> input;
    switch(input)
    {
        case 'A':
            from = 1;
            break;
        case 'B':
            from = 2;
            break;
        case 'C':
            from = 3;
            break;
        case 'D':
            from = 4;
            break;
        default:
            std::cout << "error\n";
            return 0;
    }

    std::cout << "Masukkan tujuan: ", std::cin >> input;
    switch(input)
    {
        case 'A':
            to = 1;
            break;
        case 'B':
            to = 2;
            break;
        case 'C':
            to = 3;
            break;
        case 'D':
            to = 4;
            break;
        default:
            std::cout << "error\n";
            return 0;
    }

    RouteSearch(Stack, from, to, Beban, Rute);
}