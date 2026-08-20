#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <windows.h> // Thay ncurses bằng windows.h

#define cols 25
#define rows 25
#define foods 50

char board[cols * rows];
int isGameOver = 0;

// Hàm thay thế cho move(0,0) của ncurses
void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void fill_board() {
    int x,y;
    for(y=0; y<rows; y++) {
        for(x=0; x<cols; x++) {
            if(x==0||y==0||x==cols-1||y==rows-1) board[y*cols + x] = '#';
            else board[y*cols + x] = ' ';
        }
    }
}

void print_board() {
    int x,y;
    for(y=0; y<rows; y++) {
        for(x=0; x<cols; x++) {
            _putch(board[y*cols + x]); // Dùng _putch của windows
        }
        _putch('\n');
    }    
}

#define SNAKE_MAX_LEN 256
struct SnakePart { int x, y; };
struct Snake {
    int length;
    struct SnakePart part[SNAKE_MAX_LEN];
};
struct Snake snake;

struct Food { int x, y; int consumed; };
struct Food food[foods];

void draw_snake() {
    int i;
    for(i=snake.length-1; i>0; i--) {
        board[snake.part[i].y*cols + snake.part[i].x] = '*';
    }
    board[snake.part[0].y*cols + snake.part[0].x] = '@';
}

void move_snake(int deltaX, int deltaY) {
    int i;
    for(i=snake.length-1; i>0; i--) {
        snake.part[i] = snake.part[i-1];
    }
    snake.part[0].x += deltaX;
    snake.part[0].y += deltaY;
}

void read_keyboard(int *dx, int *dy) {
    if (_kbhit()) {
        int ch = _getch();
        switch(ch) {
            case 'w': *dx = 0; *dy = -1; break;
            case 's': *dx = 0; *dy =  1; break;
            case 'a': *dx =-1; *dy =  0; break;
            case 'd': *dx = 1; *dy =  0; break;        
        }
    }
}

void setup_food() {
    for(int i=0; i<foods; i++) {
        food[i].x = 1 + rand() % (cols-2);
        food[i].y = 1 + rand() % (rows-2);
        food[i].consumed = 0;
    }
}

void setup_snake() {
    snake.length = 1;
    snake.part[0].x = cols/2;
    snake.part[0].y = rows/2;
}

void game_rules() {
    int i;
    for(i=0; i<foods; i++) {
        if(!food[i].consumed && food[i].x == snake.part[0].x && food[i].y == snake.part[0].y) {
            food[i].consumed = 1;
            snake.length++;
        }
    }
    if(snake.part[0].x == 0 || snake.part[0].x == cols-1 || snake.part[0].y == 0 || snake.part[0].y == rows-1) isGameOver = 1;
    for(i=1; i<snake.length; i++) {
        if(snake.part[0].x == snake.part[i].x && snake.part[0].y == snake.part[i].y) isGameOver = 1;
    }
}

int main() {   
    srand(time(0));
    int dx = 0, dy = 0;

    // Ẩn con trỏ chuột cho đỡ nháy
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = FALSE;
    SetConsoleCursorInfo(consoleHandle, &info);

    setup_snake();
    setup_food();
    
    while(!isGameOver) {
        gotoxy(0,0); // Thay thế move(0,0)
        fill_board();
        for(int i=0; i<foods; i++) if(!food[i].consumed) board[food[i].y*cols + food[i].x] = '+';
        draw_snake();
        game_rules();
        
        printf("Snake Game, Score: %d\n", snake.length * 100);
        print_board();
        
        read_keyboard(&dx, &dy);
        move_snake(dx, dy);
        Sleep(100); // Tốc độ game
    }
    
    gotoxy(0, rows + 2);
    printf("Game Over, Final score: %d\n", snake.length * 100);
    _getch();
    return 0;
}