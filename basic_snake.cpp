#include<bits/stdc++.h>
#include<conio.h>
#include<windows.h>
using namespace std;
bool gameover;
const int width=20;
const int height=20;
int x,y,fruit_x,fruit_y,score;
int tail_x[100],tail_y[100],length;
enum edirection{stop=0,LEFT,RIGHT,UP,DOWN};
edirection dir;
void initialise()
{
    gameover=false;
    x=width/2;
    y=height/2;
    dir=stop;
    fruit_x=rand()%width-1;
    fruit_y=rand()%height;
    score=0;
    length=0;
}
void draw()
{
    system("cls");
    for(int i=0;i<height;i++)
    {
        for(int j=0;j<width+1;j++)
        {
            if(i==0||i==height-1)
            {
                cout<<"#";
            }
           else{
               if(j==0||j==height-1)
               {
                   cout<<"#";
               }
               if(i==y&&j==x)
               {
                   cout<<"O";
               }
               else if(i==fruit_y&&j==fruit_x)
               {
                   cout<<"F";
               }
               else{
                   for(int k=0;k<length;k++)
                   {
                       if(j==tail_x[i]&&i==tail_y[i])
                       {
                           cout<<"o";
                       }
                   }
                   cout<<" ";
               }
           }
            
        }
        cout<<endl;
    }
   // gameover=true;
}
void take_input()
{
    if(_kbhit())
    {
        switch (_getch())
        {
        case 'a':
        dir=LEFT;
            break;
        case 'd':
        dir=RIGHT;
        break;
        case 'w':
        dir=UP;
        break;
        case 's':
        dir=DOWN;
        break;
        case 'x':
        gameover=true;
        cout<<"\nSCORE: "<<score;
            break;
         }
    }
}
void logic()
{
    int prev_x=x;
    int prev_y=y;
    tail_x[0]=prev_x;
    tail_y[0]=prev_y;
    for(int i=length-1;i>0;i--)
    {
        tail_x[i]=tail_x[i-1];
        tail_y[i]=tail_y[i-1];
    }
     switch (dir)
        {
        case LEFT:
        x--;
        break;
        case RIGHT:
        x++;
        break;
        case UP:
        y--;
        break;
        case DOWN:
        y++;
        break;
        default:
        break;
        
        }
        if(x>=width||x<-1||y>=height||y<0)
        {
            gameover=true;
            cout<<"\nSCORE: "<<score;
        }
        if(x==fruit_x&&y==fruit_y)
        {
            score=score+10;
            fruit_x = rand() %width+1;
            fruit_y = rand() %height+1;
            length++;
        }

}

int main()
{
    initialise();
    while(gameover!=true)
    {
        system("cls");
        draw();
        take_input();
        logic();
        Sleep(100);
    }



    return 0;
}