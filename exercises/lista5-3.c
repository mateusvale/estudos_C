#include<stdio.h>

unsigned setabits(unsigned x,int p,int n,unsigned y);

int main(void){
    printf("%u\n",setabits((unsigned)95,6,2,(unsigned)51));
}

unsigned setabits(unsigned x,int p,int n,unsigned y){
    return (x & ~(~(~0 << n)) << (p+1-n)) | ( y & (~(~0<<n)) << (p+1-n));
}