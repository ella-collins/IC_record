#include<bits/stdc++.h>
#include<cstdio>
using namespace std;

void problem4(){
    int x = 1;
    (--x)||(x--);
    printf("%d\n", x);  //-1
}

void problem5(){
    int x = 2;
    int y = (x--)||(--x);
    printf("%d\n", x*y); //1
}

void problem6(){
    int x = 1;
    (x--)||(--x);
    printf("%d\n", x);  //0
}

void problem9(){
    int x = 1;
    int y = (--x)||(x--);        //y==0,x==-1
    printf("%d\n", x*y);  //0
}

int main(){
    problem4();
    problem5();
    problem6();
    problem9();
    return 0;
}