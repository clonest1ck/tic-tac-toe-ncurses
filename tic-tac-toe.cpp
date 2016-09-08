#include <ncurses.h>
#include <unistd.h>

#define DELAY 30000

const char welc[] = "Hello and welcome to Tic-Tac-Toe!";
const char help[] = "Play by writing the number for each corresponding square";
char* game;


void drawBoard(int start_x, int start_y, int width, int height);
void drawfh(int start_x, int start_y, int width);
void drawdh(int start_x, int start_y, int width);
void drawfv(int start_x, int start_y, int height);
void drawtb(int start_x, int start_y, const char text[]);
void setup(void);
void cleanup(void);
void gameLoop(void);
bool gameOver(void);
bool makeMove(int p, int i);

int main(int argc, char *argv[]) {
  setup();
  gameLoop();
  cleanup();
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

void gameLoop() {
  return;
}

bool makeMove(int p, int i) {
  char g;
  
  if(game[i])
    return false;
  
  if(p == 1)
    g = 'x';
  else
    g = 'o';
  
  game[i] = g;
  return true;
}

bool gameOver() {
  // Check horizontal lines
  for(int i = 0; i < 9; i += 3) {
    if(game[i] == game[i+1] && game[i] == game[i+2] && game[i])
      return true;
  }
  
  // Check vertical lines
  for(int i = 0; i < 4; i ++) {
    if(game[i] == game[i+3] && game[i] == game[i+6] && game[i])
      return true;
  }
  
  // Check crosses
  if(game[0] == game[5] && game[0] == game[9] && game[0])
    return true;
  else if(game[3] == game[5] && game[3] == game[9] && game[3])
    return true;
  else
    return false;
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