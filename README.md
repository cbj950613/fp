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
