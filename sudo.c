#include <stdio.h>
#include <windows.h>
#include <conio.h>

void gotoxy(int X, int Y) {
    HANDLE Screen;
    Screen = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD Position = {X, Y};
    SetConsoleCursorPosition(Screen, Position);
}

void main() {
    int x=2, y=1;
    system("cls");
    printf("-------------\n");
    printf("| * * | * * |\n");
    printf("| * * | * * |\n");
    printf("-------------\n");
    printf("| * * | * * |\n");
    printf("| * * | * * |\n");
    printf("-------------\n");
    gotoxy(x, y);
    while(1) {
        if(kbhit()) {
            char a;
            a=getch();
            char buff;
            while(kbhit() == 1) buff=getch();
            switch (a) {
                case 'a' :
                    if(x>2) {
                        x-=2;
                        if(x==6) x-=2;
                    }
                    break;
                case 'd' :
                    if(x<10) {
                        x+=2;
                        if(x==6) x+=2;
                    }
                    break;
                case 's' :
                    if(y<5) {
                        y++;
                        if(y==3) y++;
                    }
                    break;
                case 'w' :
                    if(y>1) {
                        y--;
                        if(y==3) y--;
                    }
                    break;
                case 27 :
                    exit(0);
            }
        }
        gotoxy(x, y);
        // if(kbhit()) {
        //     char a;
        //     a=getch();
        //     char buff;
        //     while(kbhit() == 1) buff=getch();
        //     if(a=='e') {
        //         printf("\b _");
        //         int num;
        //         scanf("%d", &num);
        //         printf("\b\b%d", num);
        //     }
        // }
    }
}