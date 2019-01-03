#line 67 "top.org"
#include <ncurses.h>
#include <string.h>
#include "cardinalescape.h"
#include "cardinalescape_private.h"

#line 176 "top.org"
enum {
#line 192 "top.org"
MODE_WELCOME,
#line 199 "top.org"
MODE_NORMAL,
#line 178 "top.org"
MODE_NONE
};
#line 73 "top.org"

#define WIDTH 80
#define HEIGHT 20

#line 124 "top.org"
void cardinal_init(cardinal_d *c)
{
#line 137 "top.org"
c->is_running = 1;
#line 187 "top.org"
c->mode = MODE_WELCOME;
#line 306 "display.org"
memset(c->dbuf, 0, 1600);
#line 127 "top.org"
}
#line 147 "top.org"
int cardinal_is_running(cardinal_d *c)
{
    return c->is_running;
}
#line 160 "top.org"
void cardinal_stop_running(cardinal_d *c)
{
    c->is_running = 0;
}
#line 212 "top.org"
void cardinal_update(cardinal_d *c)
{
    switch(c->mode) {
        case MODE_WELCOME:
            c->mode = MODE_NORMAL;
            break;
        default:
            break;

    }
}
#line 272 "display.org"
int cardinal_check_resolution(int min_width, int min_height)
{
    int w, h;
    getmaxyx(stdscr, h, w);

    if(w < min_width || h < min_height) return 0;
    else return 1;
}
#line 316 "display.org"
void cardinal_display(cardinal_d *c)
{
    int line;
    cardinal_display_clear(c);

    switch(c->mode) {
        case MODE_WELCOME:
            cardinal_display_print(c, 2, 1,
                                   "Welcome to Cardinal Escape! Hit any key to continue\n");
            break;
        default:
            cardinal_draw_borders(c);
            cardinal_display_message(c,
                                     "Good luck getting out of this one, nerd!");
            break;

    }
    for(line = 0; line < HEIGHT; line++) {
        mvprintw(line, 0, c->dbuf + (line * (WIDTH + 1)));
    }
    refresh();
}
#line 352 "display.org"
void cardinal_display_set(cardinal_d *c, int x, int y, char a)
{
    if(x >= WIDTH || y >= HEIGHT) return;
    c->dbuf[(y * (WIDTH + 1)) + x] = a;
}
#line 369 "display.org"
void cardinal_display_print(cardinal_d *c, int x, int y, const char *str)
{
    int len;
    int s;
    len = strlen(str);

    for(s = 0; s < len; s++) {
        cardinal_display_set(c, x + s, y, str[s]);
    }
}
#line 392 "display.org"
static void print_word(cardinal_d *c,
                       const char *w, int size,
                       int row, int col,
                       int offx, int offy)
{
    int n;
    for(n = 0; n < size; n++) {
        cardinal_display_set(c, col + n + offx, row + offy, w[n]);
    }
}

static int word_exceeds_bounds(const char *w, int size, int pos, int mw)
{
    if((pos + size) > mw) return 1;
    return 0;
}

void cardinal_display_message(cardinal_d *c, const char *str)
{
    int off_x;
    int off_y;
    int size;
    const char *word_start;
    int word_size;
    int n;
    char prev;
    int col;
    int row;
    int max_width;

    max_width = 37;
    off_x = 42;
    off_y = 1;
    size = strlen(str);

    word_start = str;
    word_size = 0;
    prev = 0;
    row = 0;
    col = 0;
    for(n = 0; n < size; n++) {
        if(str[n] == ' ')  {
            if(word_exceeds_bounds(word_start, word_size, col, max_width)) {
                row++;
                col = 0;
            }
            print_word(c, word_start, word_size, row, col, off_x, off_y);
            col += word_size + 1;
            cardinal_display_set(c, col + off_x, row + off_y, ' ');
        } else if (prev == ' ' && str[n] != ' ') {
            word_size = 0;
            word_start = &str[n];
        }

        prev = str[n];
        word_size++;
    }
    if(word_exceeds_bounds(word_start, word_size, col, max_width)) {
        row++;
        col = 0;
    }
    print_word(c, word_start, word_size, row, col, off_x, off_y);
}
#line 466 "display.org"
void cardinal_display_clear(cardinal_d *c)
{
    int x;
    int y;

    for(y = 0; y < HEIGHT; y++) {
        for(x = 0; x < WIDTH; x++) {
            cardinal_display_set(c, x, y, ' ');
        }
    }
}
#line 489 "display.org"
void cardinal_draw_borders(cardinal_d *c)
{
    int n;
    int center;
    cardinal_display_set(c, 0, 0, '+');
    cardinal_display_set(c, WIDTH - 1, 0, '+');
    cardinal_display_set(c, 0, HEIGHT - 1, '+');
    cardinal_display_set(c, WIDTH - 1, HEIGHT - 1, '+');

    for(n = 1; n < WIDTH - 1; n++) {
        cardinal_display_set(c, n, 0, '-');
        cardinal_display_set(c, n, HEIGHT - 1, '-');
    }

    center = WIDTH / 2;
    for(n = 1; n < HEIGHT - 1; n++) {
        cardinal_display_set(c, 0, n, '|');
        cardinal_display_set(c, WIDTH - 1, n, '|');
        cardinal_display_set(c, center - 1, n, '|');
        cardinal_display_set(c, center, n, '|');
    }
}
#line 530 "input.org"
void cardinal_input_process(cardinal_d *c)
{
    int x;
    x = getch();

    switch(c->mode) {
        case MODE_WELCOME:
            break;
        default:
            if(x == 'q') {
                cardinal_stop_running(c);
            }
            break;
    }

}
#line 78 "top.org"

int main(int argc, char *argv[])
{
    cardinal_d card;
    cardinal_init(&card);
    initscr();
    curs_set(0); /* hide the cursor */
    noecho();

    if(!cardinal_check_resolution(WIDTH, HEIGHT)) {
        mvprintw(0, 0, "Improper resolution. Quitting.");
        endwin();
    }

    while(cardinal_is_running(&card)) {
        cardinal_display(&card);
        cardinal_input_process(&card);
        cardinal_update(&card);
    }

    endwin();
    return 0;
}
