#include <ncurses.h>
#include <unistd.h>

#define DELAY 30000

void drawBoard(int start_x, int start_y, int width, int height);
void drawfh(int start_x, int start_y, int width);
void drawdh(int start_x, int start_y, int width);
void drawfv(int start_x, int start_y, int height);
void drawtb(int start_x, int start_y, const char text[]);

int main(int argc, char *argv[]) {
  int x = 0, y = 0;
  int max_y = 0, max_x = 0;
  int next_x = 0;
  int direction = 1;

  initscr();
  noecho();
  curs_set(FALSE);
  
  //while(1) {
    // stdscr is a global variable created by initscr
    getmaxyx(stdscr, max_y, max_x);
    
    clear();
    drawBoard(10, 4, 13, 10);
    drawtb(10, 2, "Hello World!");
    refresh();
    
    sleep(2);
  //}
  
  endwin(); // Restore normal terminal behavior
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