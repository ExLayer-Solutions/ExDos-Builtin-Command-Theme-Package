#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../commands.h"

const char *ONLINE_CMD_ALIAS[]      = {"online", NULL};
const int ONLINE_CMD_ARGS           = 0;
const int ONLINE_CMD_RANK_LEVEL     = 0;

void online_cmd(ExDos *x, Client *c, str *cmd, Arr *args) {
    ClearScreen(((Client *)c)->sock);
    str *r = string("List Of Users\n");
    for(int i = 0; i < (long)((ExDos *)x)->online_user_count; i++) {
        if(((Client *)((ExDos *)x)->online_users[i]) == NULL)
            break;

        if((str *)((Client *)((ExDos *)x)->online_users[i])->Username == NULL)
            break;

        char *pos = int2ch(i);
        {
            r->AppendString(r, "[");
            r->AppendString(r, pos);
            r->AppendString(r, "] ");
            r->AppendString(r, (char *)((str *)((Client *)((ExDos *)x)->online_users[i])->Username)->data);
            r->AppendString(r, "\n");
        }
        free(pos);
    }

    if(CountBots((ExDos *)x) > 0) {
        r->AppendString(r, "\n\nList Of Bots\n");
        for(int i = 0; i < CountBots((ExDos *)x); i++) {
            char *pos = int2ch(i);
            {
                r->AppendString(r, "[");
                r->AppendString(r, pos);
                r->AppendString(r, "] ");
                r->AppendString(r, (char *)((str *)((Bot *)((uArray *)((ExDos *)x)->online_bots)->arr[i])->Nickname)->data);
                r->AppendString(r, " | ");
                r->AppendString(r, (char *)((str *)((Socket *)((Bot *)((uArray *)((ExDos *)x)->online_bots)->arr[i])->socket)->IP)->data);
                r->AppendString(r, "\n");
            }
            free(pos);
        }
    }


    str *x_pos = string("11");
    str *y_pos = string("25");
    list_text(((Client *)c)->sock, x_pos, y_pos, r);
    free(x_pos);
    free(y_pos);
    free(r);
}