#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../commands.h"

const char *CLEAR_CMD_ALIAS[] = {"clear", "cls", "c", NULL};
const int CLEAR_CMD_ARGS = 0;
const int CLEAR_CMD_RANK_LEVEL = 0;

void ClearScreenUI(ExDos *x, Client *c, str *cmd, Arr *Args) {
    clear_term(c->sock);
    set_ui(x, c);

    /* Clear Command Input Line*/
    place_text(c->sock, string("27"), string("17"), string("                                        "));
}