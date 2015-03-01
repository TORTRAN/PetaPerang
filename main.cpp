#include "Base.h"
#include "Line.h"
#include "Indonesia.h"
#include "Clipper.h"
#include "View.h"

static struct termios old, New;

//input without enter
void initTermios(int echo) 
{
  tcgetattr(0, &old); /* grab old terminal i/o settings */
  New = old; /* make new settings same as old settings */
  New.c_lflag &= ~ICANON; /* disable buffered i/o */
  New.c_lflag &= echo ? ECHO : ~ECHO; /* set echo mode */
  tcsetattr(0, TCSANOW, &New); /* use these new terminal i/o settings now */
}

/* Restore old terminal i/o settings */
void resetTermios(void) 
{
  tcsetattr(0, TCSANOW, &old);
}

/* Read 1 character - echo defines echo mode */
char getch_(int echo) 
{
  char ch;
  initTermios(echo);
  ch = getchar();
  resetTermios();
  return ch;
}

/* Read 1 character without echo */
char getch(void) 
{
  return getch_(0);
}

/* Read 1 character with echo */
char getche(void) 
{
  return getch_(1);
}

int main(){
  FrameBuffer FB, FB1;
  
  Clipper clipper;
  char temp = 'm';
	while(temp != 'q'){
    Indonesia I;
    View view;
    I.Draw(FB);
    clipper.Draw(FB);
    temp = getche();
    switch(temp){
      case 'w' : clipper.MoveUp(); break;
      case 'a' : clipper.MoveLeft(); break;
      case 's' : clipper.MoveDown(); break;
      case 'd' : clipper.MoveRight(); break;
    }
    clipper.GetContent(I);
    view.Draw(clipper,FB);

    //system("clear");
    clipper.inside.clear();
  }
	return 0;
}