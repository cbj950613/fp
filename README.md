# fp
final project
I created a rectangle.cpp and rectangle.h to hopefully emulate the SNAKE game as my final project. Currently I just got it to move from Qt using Qkeyevent.

March 22

Started watching ncurses tutorials. So far I know that the ncurse is supposed to be defined between 
initscr() and endwin(). 

it took me some good time to realize how to install ncurses on mac. 
$ curl -O ftp://ftp.gnu.org/gnu/ncurses/ncurses-5.9.tar.gz
$ tar -xzvf ncurses-5.9.tar.gz
$ cd ./ncurses-5.9
$ ./configure --prefix=/usr/local \
  --without-cxx --without-cxx-binding --without-ada --without-progs --without-curses-h \
  --with-shared --without-debug \
  --enable-widec --enable-const --enable-ext-colors --enable-sigwinch --enable-wgetch-events \
&& make
$ sudo make install

is the instruction that i found on github, but it strangely couldn't find the ncurses-5.9.tar.gz file.
I went directly to GNU and downloaded ncurses-6.1 and installed it through terminal. Now I had some trouble
because it was compiling my code but not actually showing me the other console when I ran it. That was when I
used g++ [file name] -lncurses instead of clang++ and now it works fine.

April 1

#include <ncurses.h>

int main(){
	initscr();
	printw("Hello World");
	refresh();
	getch();

	endwin();
	return 0;
}

was the first.cpp file that i made. I ran it with g++ first.cpp -lncurses on terminal, and it ran without any problem.

move(int, int); moves the cursor to a place on the console.
mvprintw(int,int,*char); does the same thing.


April 3


{
#include <ncurses.h>

int main(){
	initscr();
	int x,y;
	getmaxyx(stdscr,y,x);
	move(y/2,x/2);
	printw("a");
	refresh();
	getch();
	endwin(); //deallocate memory
	return 0;
}
}


the getmaxyx() function calculated the max of x and y values and by moving the cursor to y/2,x/2, I was able to
estimate the center of the screen.

attron(%char_BOLD) and attroff(%char_BOLD) allows the character on display to be bolded at command.


April 5

code:



#include <ncurses.h>

int main(){
	initscr();
	start_color();
	init_pair(1,COLOR_RED,COLOR_BLACK);
	attron(COLOR_PAIR(1));
	printw("Something");
	attroff(COLOR_PAIR(1));
	refresh();
	getch();
	endwin(); //deallocate memory
	return 0;
}

init_pair() initilizes a pair of the color. Like on the previous code example, attron() and attroff() allows the text to be changed in its nature.
For example, attron(COLOR_PAIR(2)) will make the text black instead because the color pair is (red,black).

-----starting with the snake.cpp-----


