#include <graphics.h>
#include <dos.h>
#include <conio.h>
#include <windows.h>
#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <string.h>


using namespace std;
int n;
int x=100,y=100,X=300,Y=400,direction=0, GameOver=0;
int Xpunct=10*(rand()%10),Ypunct=10*(rand()%10);

int tailX[100], tailY[100];

int marime=0;
char score[20];

void draw()
{
 cleardevice();
sprintf(score,"SCOR %d", marime);
outtextxy(330,30,score);

 bar(10,10,X+10,20);
 bar(10,10,20,Y+10);
 bar(10,Y+10,X+10,Y+20);
 bar(X+10,10,X+20,Y+20);


 int i,j;


 for(i=10;i<=Y;i+=10)
 {
     for(j=10;j<=X;j+=10)
     {
         if(y==i && x==j)
         {
           bar(x+10,y+10,x+20,y+20);
         }
         else
         if(Xpunct==i && Ypunct==j) {circle(Xpunct+15,Ypunct+15,5);}
         else
         {
             for(int k=0;k<marime;k++)
             {
                 if(tailX[k]==j && tailY[k]==i)
                 {

                 bar(tailX[k]+11,tailY[k]+11,tailX[k]+19,tailY[k]+19);
                 }
             }
         }
     }

 }
}
void input()
{
 if(_kbhit())
 {
     switch(_getch())
     {
     case 'a':
      if(direction!=3 || marime<2)   direction=1;
        break;

     case 'w':
        if(direction!=4 || marime<2)  direction=2;
        break;

    case 'd':
        if(direction!=1 || marime<2) direction=3;
        break;

        case 's':
        if(direction!=2 || marime<2) direction=4;
        break;
        case 'x':
            GameOver=1;
            break;
     }
 }
}


void logic()
{

    int prevX= tailX[0], prevY =tailY[0];
    int prev2X, prev2Y;
    tailX[0]=x;
    tailY[0]=y;
    for(int i=1;i<marime;i++)
    {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i]=prevX;
        tailY[i]= prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }

     switch(direction)
 {
 case 1:
    x-=10;
    break;

case 2:
    y-=10;
    break;
case 3:
    x+=10;
    break;
case 4:
    y+=10;
    break;

 }
  for (int i = 0; i < marime; i++)
        if (tailX[i] == x && tailY[i] == y)
            GameOver = 1;


 if(x<10 || x>=X || y<10 || y>=Y) GameOver=1;

 if(x==Xpunct && y==Ypunct)
 {
     Xpunct=(10*(rand()%40));
     Ypunct=(10*(rand()%30));
     if(Xpunct>=X) Xpunct=X-20;
     if(Ypunct>=Y) Ypunct=X-20;
     if(Xpunct<10) Xpunct=20;
     if(Ypunct<10) Ypunct=20;

     marime++;
     n--;
 }

}

int main()
{
int gd = DETECT, gm;

system("color f6");
w_number:
cout<<"Introduceti nivelul de joc:"<<endl;
cout<<"1 - usor\n2 - mediu\n3 - greu\n";
cin>>n;

switch(n)
{
case 1:
    n=160;
    break;
case 2:
    n=130;
    break;
case 3:
    n=100;
    break;
default:

cout<<"Introduceti un numar valid"<<endl;
goto w_number;

}
initgraph(&gd,&gm,"C:\\TC\\BGI");
for(int i=1;i<=300;i+=5)
    {

    cleardevice();
    outtextxy(280,400,"LOADING..");
    bar(150,420,150+i,430);
    delay(50);

    }
    cleardevice();
setbkcolor(GREEN);
setcolor(BLUE);
settextstyle(DEFAULT_FONT,HORIZ_DIR,2);

while(!GameOver)
{
draw();
delay(n);
input();
logic();

}
   closegraph();
system("Color 1C");
  system("cls");
for(int h=1;h<=20;h++)
{
    for(int g=1;g<=h;g++)
        cout<<endl;
        cout<<"            >> SNAKE <<\n\n\n            DEVELOPER\n            -Ionut Bosie-\n\n            SPECIAL THANKS\n            -Ionut Bosie-\n\n            END\n";
     Sleep(200);
    system("cls");
}
system("cls");
   return 0;
}
