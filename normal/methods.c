#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../commands.h"

const char *METHOD_CMD_ALIAS[]      = {"methods", NULL};
const int METHOD_CMD_ARGS           = 0;
const int METHOD_CMD_RANK_LEVEL     = 0;
const char *METHODS[]               = { "udp", "tcp", "http" };

void methods_cmd(ExDos *x, Client *c, str *input, Arr *args) {
    ClearScreen(((Client *)c)->sock);
    str *method_list = string(NULL);
    
    for(int i = 0; i < count_arr((char **)METHODS); i++) {
        if(METHODS[i] == NULL)
            break;

        char *pos = int2ch(i);
        {
            method_list->AppendString(method_list, "[");
            method_list->AppendString(method_list, pos);
            method_list->AppendString(method_list, "] ");
            method_list->AppendString(method_list, METHODS[i]);
            method_list->AppendString(method_list, "\n");
        }
        free(pos);
    }

    str *x_pos = string("11");
    str *y_pos = string("35");
    place_text(((Client *)c)->sock, x_pos, y_pos, string("[ Methods ]"));
    free(x_pos);
    free(y_pos);

    x_pos = string("13");
    y_pos = string("37");
    list_text(((Client *)c)->sock, x_pos, y_pos, method_list);
    free(x_pos);
    free(y_pos);
    free(method_list);
}