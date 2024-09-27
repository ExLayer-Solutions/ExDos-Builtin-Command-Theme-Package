#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../commands.h"

const char *INFO_CMD_ALIAS[]      = {"info", NULL};
const int INFO_CMD_ARGS           = 0;
const int INFO_CMD_RANK_LEVEL     = 0;

void info_cmd(ExDos *x, Client *c, str *cmd, Arr *Args) {
    ClearScreen(((Client *)c)->sock);
    str *output = string("Username: ");

    char *acc_p         = int2ch(((Client *)c)->account->PLAN);
    char *max_time      = int2ch(((Client *)c)->account->MAX_TIME);
    char *max_cons      = int2ch(((Client *)c)->account->MAX_CONCURRENTS);
    char *acc_vip       = int2ch(((Client *)c)->account->VIP);
    char *acc_r         = int2ch(((Client *)c)->account->RANK);

    char *arr[] = {
        ((Client *)c)->account->USERNAME->data,
        "\nPlan: ",
        acc_p,
        "\nMax Time: ",
        max_time,
        "\nMax Concurrents: ",
        max_cons,
        "\nVIP: ",
        acc_vip,
        "\nExpiry: ",
        ((Client *)c)->account->EXPIRY->data,
        "\nRank: ",
        acc_r,
        "\n"
    };

    for(int i = 0; i < 6; i++)
        output->AppendString(output, arr[i]);

    free(acc_p);
    free(max_time);
    free(max_cons);
    free(acc_vip);
    free(acc_r);
    
    str *x_pos = string("9");
    str *y_pos = string("37");
    str *buff = string("[ Account Information ]");
    place_text(((Client *)c)->sock, x_pos, y_pos, buff);
    free(x_pos);
    free(y_pos);
    free(buff);
    
    x_pos = string("13");
    y_pos = string("35");
    list_text(((Client *)c)->sock, string("13"), string("35"), output);
    free(x_pos);
    free(y_pos);
    free(output);
}