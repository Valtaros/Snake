#include <ncurses.h>
//#include <cstdlib>
#include <vector>
using namespace std;


class coordinate
{
private:
int x;
int y;
public:
    int getx(){return x;};
    int gety(){return y;};
    void setx(int i){x=i;};
    void sety(int i){y=i;};
};


void step(char c, vector<coordinate>& snake)
{
    mvaddch(snake[snake.size()-1].gety(), snake[snake.size()-1].getx(), ' ');
    for(int i=snake.size()-2; i>=0; i--){
        snake[i+1]=snake[i];
    }
    if(c=='l'/*KEY_LEFT*/)
    {
        snake[0].setx(snake[0].getx()-1);
    }
    if(c=='r'/*KEY_RIGHT*/)
    {
        snake[0].setx(snake[0].getx()+1);
    }
    if(c=='d'/*KEY_DOWN*/)
    {
        snake[0].sety(snake[0].gety()+1);
    }
    if(c=='u'/*KEY_UP*/)
    {
        snake[0].sety(snake[0].gety()-1);
    }
    mvaddch(snake[0].gety(), snake[0].getx(), 's');
};

void eat(coordinate food, coordinate head)
{
    if(head.getx()==food.getx() && head.gety() == food.gety())
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
    
    int length=5, MaxX, MaxY;
    
    getmaxyx(stdscr, MaxY, MaxX);
    
    coordinate head, food;
    vector<coordinate> snake (5);
    snake[0].setx(17);
    snake[0].sety(20);
    step('l', snake);
    refresh();
    getch();
    
    //mvprintw(10, 10, "%d", snake[0].getx()); 
    
    
    endwin();
}
