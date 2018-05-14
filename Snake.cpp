#include <ncurses.h>
#include <cstdlib>


void move(/*char c,*/ int y[], int x[], int l)
{
    mvaddch(y[l-1], x[l-1], ' ');
    if(c==KEY_LEFT)
    {
        
    }
    if(c==KEY_RIGHT)
    {
        
    }
    if(c==KEY_DOWN)
    {
        
    }
    if(c==KEY_UP)
    {
        
    }
    
};

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
        snakex[i]=COLS/2+i;
        snakey[i]=LINES/2+i;
        mvaddch((snakey[i]), (snakex[i]), '0');
    }
    refresh();
    getch();
    move(snakey, snakex, length);
    refresh();
    getch();
    free (snakey);
    free (snakex);
    
    endwin();
}
