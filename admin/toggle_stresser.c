#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../commands.h"

const char *TOGGLE_STRESSER_CMD_ALIAS[]      = {"toggle_stresser", NULL};
const int TOGGLE_STRESSER_CMD_ARGS           = 4;
const int TOGGLE_STRESSER_CMD_RANK_LEVEL     = 3;

void toggle_stresser_cmd(ExDos *x, Client *c, str *cmd, Arr *Args) {
    ClearScreen(((Client *)c)->sock);
    toggle_stresser((ExDos *)x);

    
    str *x_pos = string("11");
    str *y_pos = string("40");
    str *buff = string( ((ExDos *)c)->AttackToggle ? "Attack Toggle: Enabled" : "Attack Toggle: Disabled" );
    place_text(((Client *)c)->sock, x_pos, y_pos, buff);
    free(x_pos);
    free(y_pos);
    free(buff);
}