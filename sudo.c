#include <stdio.h>

#define fr(i, n) for(int i=0; i<n; i++)

typedef struct treenode {
    int sol[9][9];
    struct treenode * br[9];
} node;

int chkcel(int sudo[9][9], int i, int j) {
    int prob=0, k=0, pssbl[30];
    int box=boxno(i, j);
    fr(num, 9) {
        //check row
        fr(p, 9) {
            if(p==j) continue;
            if(sudo[i][p]==num+1) prob=1;
        }
        //check colm
        fr(q, 9) {
            if(q==i) continue;
            if(sudo[q][j]==num+1) prob=1;
        }
        //check box
        if(box==1) {
            for(int a=0; a<3; a++) {
                for(int b=0; b<3; b++) {
                    if(a==i || b==j) continue;
                    if(sudo[a][b]==num+1) prob=1;
                }
            }
        }
        if(box==2) {
            for(int a=0; a<3; a++) {
                for(int b=3; b<6; b++) {
                    if(a==i || b==j) continue;
                    if(sudo[a][b]==num+1) prob=1;
                }
            }
        }
        if(box==3) {
            for(int a=0; a<3; a++) {
                for(int b=6; b<9; b++) {
                    if(a==i || b==j) continue;
                    if(sudo[a][b]==num+1) prob=1;
                }
            }
        }
        if(box==4) {
            for(int a=3; a<6; a++) {
                for(int b=0; b<3; b++) {
                    if(a==i || b==j) continue;
                    if(sudo[a][b]==num+1) prob=1;
                }
            }
        }
        if(box==5) {
            for(int a=3; a<6; a++) {
                for(int b=3; b<6; b++) {
                    if(a==i || b==j) continue;
                    if(sudo[a][b]==num+1) prob=1;
                }
            }
        }
        if(box==6) {
            for(int a=3; a<6; a++) {
                for(int b=6; b<9; b++) {
                    if(a==i || b==j) continue;
                    if(sudo[a][b]==num+1) prob=1;
                }
            }
        }
        if(box==7) {
            for(int a=6; a<9; a++) {
                for(int b=0; b<3; b++) {
                    if(a==i || b==j) continue;
                    if(sudo[a][b]==num+1) prob=1;
                }
            }
        }
        if(box==8) {
            for(int a=6; a<9; a++) {
                for(int b=3; b<6; b++) {
                    if(a==i || b==j) continue;
                    if(sudo[a][b]==num+1) prob=1;
                }
            }
        }
        if(box==9) {
            for(int a=6; a<9; a++) {
                for(int b=6; b<9; b++) {
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
    if(i<3 && j<3) return 1;
    if(i<3 && j>2 && j<6) return 2;
    if(i<3 && j>5) return 3;
    if(i>2 && i<6 && j<3) return 4;
    if(i>2 && i<6 && j>2 && j<6) return 5;
    if(i>2 && i<6 && j>5) return 6;
    if(i>5 && j<3) return 7;
    if(i>5 && j>2 && j<6) return 8;
    if(i>5 && j>5) return 9;
}

void printsudo(int sudo[9][9]) {
    fr(p, 9) {
        fr(q, 9) {
            if(sudo[p][q]==0) printf("*");
            else printf("%d ", sudo[p][q]);
        }
        printf("\n");
    }
}

void main() {
    int sudo[9][9];
    int empty=0;
    printf("Enter Values: \n");
    fr(i, 9) {
        fr(j, 9) {
            scanf("%d", &sudo[i][j]);
            if(sudo[i][j]==0) empty++;
        }
    }
    printf("\nYou entered: \n");
    printsudo(sudo);
    int c=0;
    while(empty>0) {
        c++;
        printf("%d\n", c);
        fr(a, 9) {
            fr(b, 9) {
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
    printsudo(sudo);

}