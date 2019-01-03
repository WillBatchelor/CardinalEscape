#line 44 "top.org"
#ifndef CARDINAL_ESCAPE_H
#define CARDINAL_ESCAPE_H
#line 106 "top.org"
typedef struct cardinal_d cardinal_d;
#line 44 "top.org"
#line 119 "top.org"
void cardinal_init(cardinal_d *c);
#line 142 "top.org"
int cardinal_is_running(cardinal_d *c);
#line 155 "top.org"
void cardinal_stop_running(cardinal_d *c);
#line 207 "top.org"
void cardinal_update(cardinal_d *c);
#line 267 "display.org"
int cardinal_check_resolution(int min_width, int min_height);
#line 311 "display.org"
void cardinal_display(cardinal_d *c);
#line 347 "display.org"
void cardinal_display_set(cardinal_d *c, int x, int y, char a);
#line 364 "display.org"
void cardinal_display_print(cardinal_d *c, int x, int y, const char *str);
#line 387 "display.org"
void cardinal_display_message(cardinal_d *c, const char *str);
#line 461 "display.org"
void cardinal_display_clear(cardinal_d *c);
#line 484 "display.org"
void cardinal_draw_borders(cardinal_d *c);
#line 525 "input.org"
void cardinal_input_process(cardinal_d *c);
#line 48 "top.org"
#endif
#line 55 "top.org"
#ifndef CARDINAL_ESCAPE_PRIVATE_H
#define CARDINAL_ESCAPE_PRIVATE_H
#line 111 "top.org"
struct cardinal_d {
#line 132 "top.org"
int is_running;
#line 169 "top.org"
int mode;
#line 300 "display.org"
char dbuf[1620];
#line 113 "top.org"
};
#line 58 "top.org"
#endif
