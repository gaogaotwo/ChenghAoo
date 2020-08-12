#include <windows.h>
#include <conio.h>
#include<time.h>
#include<stdio.h>
#define PrintAt(c,s) SetConsoleCursorPosition(hO,c),puts(s)
int main(){
    COORD s[800] = { 0 }, h, f;
    int d = 'd', l = 2, k, i = 0;
    HANDLE hO = GetStdHandle(STD_OUTPUT_HANDLE);
    srand((unsigned)time(NULL));
F:; 
    for (f.X = rand() % 41, f.Y = rand() % 21; i < l; i++) if (f.X == s[i].X && f.X == s[i].Y)goto F;
    for ((h = *s), PrintAt(f, "$");1; Sleep(100)){
        if (kbhit() && (k = getch()))
            switch (k){
            case 'a':case 'A': d - 'd'&& (d = 'a'); break;
            case 'd':case 'D': d - 'a'&& (d ='d'); break;
            case 'w':case 'W': d - 's'&& (d ='w'); break;
            case 's':case 'S': d - 'w'&& (d = 's'); break;
        }
        switch (d){
        case 'a':h.X += (h.X) ? (-1) : (40); break;
        case 'd':h.X += (h.X - 40) ? (1) : (-40); break;
        case 'w':h.Y += (h.Y) ? (-1) : (20); break;
        case 's':h.Y += (h.Y - 20) ? (1) : (-20); break;
        }
        f.X == h.X&&f.Y == h.Y && (i = 0) || (PrintAt(s[l - 1], " "));
        if (!i && l++) goto F;
        for (i = l; --i || (PrintAt(*s = h, "@"), 0); s[i] = s[i - 1]);
        for (i = 4; i < l; i++) if (h.X == s[i].X&&h.Y == s[i].Y) return 0;
    }
}
