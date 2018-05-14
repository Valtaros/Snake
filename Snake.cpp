#include <ncurses.h>
#include <cstdlib>


void move(char c);
{
    if(c==KEY_LEFT)
    {
        mvaddch((snakey[lenght]))
    }
}

int main(){
    initscr();
    for(int i=0; i<COLS; i++){
        mvaddch(0, i, 'x');
        mvaddch(LINES-1, i, 'x');
    }
    for(int i=1; i<LINES; i++){
        mvaddch(i, 0, 'x');
        mvaddch(i, COLS-1, 'x');
    }
    
    int length=5, *snakex, *snakey, MaxX, MaxY;
    
    getmaxyx(stdscr, MaxY, MaxX);
    
    snakex = (int*) malloc (length);
    snakey = (int*) malloc (length);
    
    for(int i=0; i<length; i++){
        snakex[i]=COLS/2;
        snakey[i]=LINES/2;
        //mvaddch((snakey[i]+i), (snakex[i]+i), '0');
    }
    refresh();
    getch();
    
    free (snakey);
    free (snakex);
    
    endwin();
}
