#include "snake.h"

snakepart::snakepart(int col, int row){

	x = col;
	y = row;
}
snakepart::snakepart(){

	x = 0;
	y= 0;
}

snakeclass::snakeclass(){
	initscr();
	nodelay(stdscr,true); //the program doesn't wait until user press
	keypad(stdscr,true); //initializes the keyboard
	noecho();
	curse_set(0); //makes cursor invisible
	getmaxyx(stdscr,maxheight,maxwidth);
	//initialize variables
	partchar = 'x';
	oldalchar=(char)219;
	foo= '*';
	food.x=0;
	food.y=0;
	for(int i = 0; i < 5; i++){
		snake.push_back(snakepart(40+i,10));
	}
	points = 0;
	del = 110000;
	get = false;
	direction = 'l';
	srand(time(0));
	putfood();
	for(int i = 0; i < maxwidth-1; i++){
		move(0,i);
		addch(oldalchar);
	}
	for(int i = 0; i < maxwidth-1; i++){
		move(maxheight-2,i);
		addch(oldalchar);
	}
	for(int i = 0; i < maxheight-1; i++){
		move(i,0);
		addch(oldalchar);
	}
	for(int i = 0; i < maxheight-1; i++){
		move(i,maxwidth-2);
		addch(oldalchar);
	}
	for(int i = 0; i < snake.size(); i++){
		move(snake[i].y,snake[i].x);
		addch(partchar);
	}
	move(maxheight-1,0);
	printw("%d",points);
	move(food.y,food.x);
	add(ch);
	refresh();
}
snakeclass::~snakeclass(){
	nodelay(stdscr,false);
	getch();
	endwin();
}

void snakeclass::putfood(){
	food.x = 10;
	food.y = 10;
}