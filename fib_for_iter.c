#include <stdio.h>

int fib(int );

int main()
{
    int k;

    while(1){
        scanf("%d", &k);
        if(k==-1) break;
        printf("fib(%d) = %d\n", k, fib(k));
    }
    return 0;
}

int fib(int n){
    if(n<2) return n;
    else{
        int tmp, p = 0, pp = 1;

        for(int i=1; i<n; i++){
            tmp = p + pp;
            p = pp;
            pp = tmp;
        }
        return tmp;
    }
}
