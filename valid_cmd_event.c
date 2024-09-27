#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "commands.h"

/*
*
*           [ UPON VALID COMMAND ]
*
* - Log Command To Console
* - Clear Prompt Line
* - Update Statistics
*
*/
void valid_cmd_event(ExDos *x, Client *c, str *cmd, Arr *Args) {
    printf("[ + ] New Input: %s => %s\n", c->account->USERNAME->data, cmd->data);
    
    /* Clear Command Input Line*/
    place_text(((Client *)c)->sock, string("27"), string("17"), string("                                        "));

    /* Update Statistics */
    str *user_count = string(int2ch((int)((ExDos *)x)->online_user_count));
    user_count->AppendString(user_count, "/");
    user_count->AppendString(user_count, int2ch((int)((ExDos *)x)->user_idx - 1));
    place_text(((Client *)c)->sock, string("6"), string(int2ch(user_count->idx > 1 ? 35 - (user_count->idx/2) : 35)), user_count);
    free(user_count);

    place_text(((Client *)c)->sock, string("6"), string("55"), string(int2ch((int)((ExDos *)x)->online_bots->idx)));
    place_text(((Client *)c)->sock, string("6"), string("75"), string(int2ch((int)((ExDos *)x)->LogCount)));

}