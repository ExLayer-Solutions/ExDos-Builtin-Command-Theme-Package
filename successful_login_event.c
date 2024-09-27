#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>

#include "commands.h"

/*
*       [ UPON SUCCESSFUL LOGINS ]
*
* - IP Lock Checks Upon Login
* - Start title writer thread
* - Set UI, Statistics and Acc Plan
*
*/
void successful_login_event(ExDos *x, Client *c) {
    printf("[ + ] New User Connected: %s => %s...!\n", ((Client *)c)->account->USERNAME->data, ((Client *)c)->sock->IP->data);
    ClearScreen(((Client *)c)->sock);
    if(strcmp(((Client *)c)->account->IP_ADDR->data, ((Client *)c)->sock->IP->data) && strcmp(((Client *)c)->account->IP_ADDR->data, "0.0.0.0")) {
        Write(((Client *)c)->sock, string("[ x ] Error, Unable to login due to a mismatch IP....\nAccounts are IP Locked to the registered IP by default, Message owner for IP Lock Reset\n"));
        close(((Client *)c)->sock->SockFD);
        return;
    }

    if(!strcmp(((Client *)c)->account->IP_ADDR->data, "0.0.0.0")) {
        printf("Invalid IP Match: %s\n", ((Client *)c)->sock->IP->data);
        ChangeIPAddress(((Client *)c)->account, ((Client *)c)->sock->IP);
        SaveDB(((ExDos *)x)->DB, ((ExDos *)x)->user_idx);
    }


    /* Thread Title Updater For User */
    void **new = (void **)malloc(sizeof(void *) * 2);
    new[0] = x;
    new[1] = c;
    pthread_t gg;
    pthread_create(&gg, NULL, (void *)title_updater, new);
    clear_term(c->sock);
    set_ui(x, c);
}