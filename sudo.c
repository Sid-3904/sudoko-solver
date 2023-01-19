#include <stdio.h>
#include <windows.h>
#include <conio.h>

#define for(i, n) for(int i=0; i<n; i++)



void main() {
    enum value{a=1, b=2, c=3, d=4, e=0};
    enum value sudo[4][4];
    int n;
    printf("Enter Values: \n");
    for(i, 4) {
        for(j, 4) {
            scanf("%d", &n);
            switch(n) {
                case 1 :
                    sudo[i][j]=a;
                    break;
                case 2 :
                    sudo[i][j]=b;
                    break;
                case 3 :
                    sudo[i][j]=c;
                    break;
                case 4 :
                    sudo[i][j]=d;
                    break;
                case 0 :
                    sudo[i][j]=e;
                    break;
            }
        }
    }
    printf("\nYou Entered: \n");
    for(p, 4) {
        for(q, 4) {
            if(sudo[p][q]==0) printf("* ");
            else printf("%d ", sudo[p][q]);
        }
        printf("\n");
    }
    // if(n>0 && n<5) printf("%d", val);
    // else printf("*");
}