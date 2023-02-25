#include <ncurses.h>
#include <string>
#include <iostream>
#include <locale.h>
#include <unistd.h> 

//  g++ gameoflife/gol.cpp -lncursesw -D_XOPEN_SOURCE_EXTENDED -o gameoflife/gol

using namespace std;

void randomgol(int size_x, int size_y);
void drawgol(int size_x, int size_y);
int main(int argc, char ** argv)
{
   setlocale(LC_ALL, "");
   // wchar_t* cell="█";
    // init screen and sets up screen
    
    int size_x = 105;
    int size_y = 50;

    //drawgol(size_x, size_y);

    randomgol(size_x, size_y);

}

void drawgol(int size_x, int size_y) {
    int grid[size_x][size_y];
    int nextgen[size_x][size_y];
    
    for (int y=0; y < size_y; y++) {
        for (int x=0; x < size_x; x++) {
            grid[x][y] = 0;
        }
    }    
    initscr();
    while(true) {
    refresh();
    int cursorx = 0;
    int cursory = 0;
    for (int y=0; y < size_y; y++) {
        for (int x=0; x < size_x; x++) {
            char input = getch();
            getch();
            if (input == 'w') {
            }
            if (grid[x][y] == 1) {
                printw("██");
                //printw("1");
            } else {
                printw("  ");
            }

            if (x == (size_x - 1) ) {
                printw("\n");
            }
    
        }
    }
    }
}

void randomgol(int size_x, int size_y) {
    int grid[size_x][size_y];
    int nextgen[size_x][size_y];

    // initital randomization of grid
    for (int y=0; y < size_y; y++) {
        for (int x=0; x < size_x; x++) {
            grid[x][y] = rand() % 2;

           // if (grid[x][y] == 1) {
              //  printf("██");
          //  } else {
              ///  printf("  ");
           // }

            //if (x == (size - 1) ) {
              //  ("\n");
           // }

        }
    }

    // begin drawing
    initscr();
    curs_set(0);

    for (int y=0; y < size_y; y++) {
        for (int x=0; x < size_x; x++) {

            if (grid[x][y] == 1) {
                printw("██");
                //printw("1");
            } else {
                printw("  ");
            }

            if (x == (size_x - 1) ) {
                printw("\n");
            }

        }
    }
    refresh();
while (true) {
    for (int y=0; y < size_y; y++) {
        for (int x=0; x < size_x; x++) {
            int neighbors = grid[x - 1][y - 1] + grid[x][y - 1] + grid[x + 1][y - 1] + grid[x - 1][y] + grid[x + 1][y] + grid[x - 1][y + 1] + grid[x][y + 1] + grid[x + 1][y + 1];
                 if (grid[x][y] == 0 && neighbors == 3) {
                        nextgen[x][y] = 1;
                }
                
                if (grid[x][y] == 1) {
                        if (neighbors < 2) {
                            nextgen[x][y] = 0;
                        } else if ((neighbors == 2) || (neighbors == 3)) {
                            nextgen[x][y] = 1;
                        } else if (neighbors > 3) {
                            nextgen[x][y] = 0;
                        }
                }
        } 
    }

usleep(70000);
//getch();
clear();
    for (int y=0; y < size_y; y++) {
        for (int x=0; x < size_x; x++) {

            if (nextgen[x][y] == 1) {
                printw("██");
               // printw("1");
            } else {
                printw("  ");
            }

            if (x == (size_x - 1) ) {
                printw("\n");
            }

        }
    }
    refresh();

    for (int y=0; y < size_y; y++) {
        for (int x=0; x < size_x; x++) {
            grid[x][y] = nextgen[x][y];
            nextgen[x][y] = 0;
        }
    }
}
    //pause the screen output
    //waits for user input, returns the ASCII value of that key
    getch();

    // deallocates mem and ends ncurses
    endwin();
}
