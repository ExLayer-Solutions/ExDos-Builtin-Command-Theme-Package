#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../commands.h"
#include <clib/String/str.h>

const char *PASSWD_CMD_ALIAS[]      = {"passwd", NULL};
const int PASSWD_CMD_ARGS           = 0;
const int PASSWD_CMD_RANK_LEVEL     = 0;

/* Change Password Command */
// Usage: acc passwd <new> 
// Prompt user for new password if its not provided @ command
void passwd_cmd(ExDos *x, Client *c, str *cmd, Arr *Args) {
    ClearScreen(((Client *)c)->sock);
    /* Prompt user for the new password */
    str *new_p = (Args->idx < 2 ? prompt_new_passwd((ExDos *)x, (Client *)c, cmd, Args) : string(Args->arr[2]));
    if(!new_p) {
        return;
    }

    int check = ChangePassword(((ExDos *)x)->DB[((Client *)c)->account->idx], string(new_p->data));
    if(check) {
        place_text(((Client *)c)->sock, string("17"), string("30"), string("Password successfully changed"));
        SaveDB(((ExDos *)x)->DB, ((ExDos *)x)->user_idx);
        return;
    }
        
    str *x_pos = string("17");
    str *y_pos = string("30");
    str *buff = string("Unable to change password");
    place_text(((Client *)c)->sock, x_pos, y_pos, buff);
    free(x_pos);
    free(y_pos);
    free(buff);
    free(new_p);
}

static str *prompt_new_passwd(ExDos *x, Client *c, str *cmd, Arr *Args) {
    str *x_pos = string("17");
    str *y_pos = string("35");
    str *buff = string("New Password?: ");
    place_text(((Client *)c)->sock, x_pos, y_pos, buff);
    free(x_pos);
    free(y_pos);
    free(buff);

    str *new_p = Read(((Client *)c)->sock);
    
    x_pos = string("17");
    y_pos = string("30");
    buff = string("Confirm Password?: ");
    place_text(((Client *)c)->sock, x_pos, y_pos, buff);
    free(x_pos);
    free(y_pos);
    free(buff);

    str *confirm_p = Read(((Client *)c)->sock);

    if(strcmp(new_p->data, confirm_p->data)) {
        x_pos = string("17");
        y_pos = string("30");
        buff = string("Password did not match!");
        place_text(((Client *)c)->sock, x_pos, y_pos, buff);
        free(x_pos);
        free(y_pos);
        free(buff);
        return NULL;
    }

    free(confirm_p);
    return new_p;
}