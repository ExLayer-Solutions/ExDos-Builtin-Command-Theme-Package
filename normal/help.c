#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../commands.h"

const char *HELP_CMD_ALIAS[]    = {"help", "?", NULL};
const int HELP_CMD_ARGS         = 0;
const int HELP_CMD_RANK_LEVEL   = 0;

void help_cmd(ExDos *x, Client *c, str *input, Arr *args) {
    ClearScreen(c->sock);
    
    str *x_pos = string("9");
    str *y_pos = string("45");
    str *buff = string("[ Commands ]");
    place_text(c->sock, x_pos, y_pos, buff);
    free(x_pos);
    free(y_pos);
    free(buff);

    x_pos = string("11");
    y_pos = string("22");
    list_text(c->sock, string("11"), string("22"), ((ExDos *)x)->Theme->Help);
    free(x_pos);
    free(y_pos);
}