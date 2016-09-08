#include <ncurses.h>
#include <unistd.h>

#define DELAY 30000

const char welc[] = "Hello and welcome to Tic-Tac-Toe!";
const char help[] = "Play by writing the number for each corresponding square";
char game;


void drawBoard(int start_x, int start_y, int width, int height);
void drawfh(int start_x, int start_y, int width);
void drawdh(int start_x, int start_y, int width);
void drawfv(int start_x, int start_y, int height);
void drawtb(int start_x, int start_y, const char text[]);
void setup(void);
void cleanup(void);
void game(void);

int main(int argc, char *argv[]) {
  setup();
  game();
  
  cleanup();
  //while(1) {
    // stdscr is a global variable created by initscr
    // getmaxyx(stdscr, max_y, max_x);
    
  //}
}

void setup() {
  initscr();
  noecho();
  raw();
  curs_set(FALSE);
  drawBoard(10, 4, 13, 10);
  drawtb(10, 2, welc);
  refresh();
  game = new char[9];
  sleep(2);
}

void cleanup() {
  sleep(2);
  endwin();
}

void game() {
  
}

// Draw Tic-Tac-Toe Board
void drawBoard(int start_x, int start_y, int width, int height) {
  drawfh(start_x, start_y, width);
  
  for(int i = 3; i < height; i += 3) {
    drawdh(start_x, start_y + i, width);
  }
  
  for(int i = 0; i < width; i += 4) {
    drawfv(start_x + i, start_y, height);
  }  
}

// Draw a line of '_'
void drawfh(int start_x, int start_y, int width) {
  for(int x = start_x; x < (start_x + width); x++) {
    mvprintw(start_y, x, "_");
  }
}

void drawdh(int start_x, int start_y, int width) {
  int offset = (width - 1) / 3;
  for(int x = (start_x + 1); x < (start_x + width - 1); x++) {
    if(x != (start_x + offset) && x != (start_x + (2 * offset))) {
      mvprintw(start_y, x, "_");
    }
  }
}

void drawfv(int start_x, int start_y, int height) {
  for(int y = start_y + 1; y < (start_y + height); y++) {
    mvprintw(y, start_x, "|");
  }
}

void drawtb(int start_x, int start_y, const char text[]) {
  mvprintw(start_y, start_x, text);
}