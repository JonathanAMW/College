#include <stdio.h>

void avg_sum(double *a, int n, double *avg, double *sum){
    int i; *sum=0.0;
    for(i=0; i<n; i++){
        *sum+=a[i];
    }

    *avg=*sum/n;
}

int main(){
    double a[]={1.0,2.0,3.0};
    int n = sizeof(a) / sizeof(a[0]);
    double average=0.0, sum0;
    double *avg = &average;
    double *sum = &sum0;
    
    avg_sum(a, n, avg, sum);

    printf("average=%f, sum=%f", *avg, *sum);

}