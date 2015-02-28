#include "clipper.h"
#include "base.h"

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
	FrameBuffer FB;

	Clipper clip;
	char input='s';

	while(input!='q'){
		system("clear");

		clip.Draw(FB);
		input=getche();

		if(input=='i'){
			clip.ZoomIn();
		}else if(input=='o'){
			clip.ZoomOut();
		}else if(input=='w'){
			clip.MoveUp();
		}else if(input=='d'){
			clip.MoveRight();
		}else if(input=='x'){
			clip.MoveDown();
		}else if(input=='a'){
			clip.MoveLeft();
		}
		munmap(FB.fbp, FB.screensize);
	}
	munmap(FB.fbp, FB.screensize);
	close(FB.fbfd);
	return 0;
}
