#include <stdio.h>

#define fr(i, n) for(int i=0; i<n; i++)

enum value{a=1, b=2, c=3, d=4, e=0};

int chkcel(enum value sudo[4][4], int i, int j) {
    int prob=0, k=0, pssbl[12];
    int box=boxno(i, j);
    fr(num, 4) {
        //check row
        fr(p, 4) {
            if(p==j) continue;
            if(sudo[i][p]==num+1) prob=1;
        }
        //check colm
        fr(q, 4) {
            if(q==i) continue;
            if(sudo[q][j]==num+1) prob=1;
        }
        //check box
        if(box==1) {
            for(int a=0; a<2; a++) {
                for(int b=0; b<2; b++) {
                    if(a==i || b==j) continue;
                    if(sudo[a][b]==num+1) prob=1;
                }
            }
        }
        if(box==2) {
            for(int a=0; a<2; a++) {
                for(int b=2; b<4; b++) {
                    if(a==i || b==j) continue;
                    if(sudo[a][b]==num+1) prob=1;
                }
            }
        }
        if(box==3) {
            for(int a=2; a<4; a++) {
                for(int b=0; b<2; b++) {
                    if(a==i || b==j) continue;
                    if(sudo[a][b]==num+1) prob=1;
                }
            }
        }
        if(box==4) {
            for(int a=2; a<4; a++) {
                for(int b=2; b<4; b++) {
                    if(a==i || b==j) continue;
                    if(sudo[a][b]==num+1) prob=1;
                }
            }
        }
        if(prob==0) {
            pssbl[k]=num+1;
            k++;
        }
        prob=0;
    }
    if(k==1) return pssbl[0];
    else return 0;
}

int boxno(int i, int j) {
    if(i<2 && j<2) return 1;
    if(i<2 && j>1) return 2;
    if(i>1 && j<2) return 3;
    if(i>1 && j>1) return 4;
}

void main() {
    enum value sudo[4][4];
    int n, empty=0;
    printf("Enter Values: \n");
    fr(i, 4) {
        fr(j, 4) {
            scanf("%d", &n);
            if(n==0) empty++;
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
    printf("\nYou entered: \n");
    fr(p, 4) {
        fr(q, 4) {
            if(sudo[p][q]==0) printf("* ");
            else printf("%d ", sudo[p][q]);
        }
        printf("\n");
    }
    while(empty>0) {
        fr(a, 4) {
            fr(b, 4) {
                if(sudo[a][b]==0) {
                    sudo[a][b]=chkcel(sudo, a, b);
                    if(sudo[a][b]!=0) empty--;
                }
                if(empty==0) break;
            }
            if(empty==0) break;
        }
    }
    printf("\nSolved: \n");
    fr(p, 4) {
        fr(q, 4) {
            printf("%d ", sudo[p][q]);
        }
        printf("\n");
    }
    printf("\n%d\n", c);
}