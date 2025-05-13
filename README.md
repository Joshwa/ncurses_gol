# ncruses_gol
Conway's Game of Life implementation that uses ncurses and can be ran in a terminal.

# grid size
If your output looks weird, you can edit the variables int size_x and int size_y at the top of the program.

# Dependencies
as long as you have g++ and the ncurses dev library for your distro, this should work

# Compiling
g++ gol.cpp -lncursesw -D_XOPEN_SOURCE_EXTENDED -o gol
