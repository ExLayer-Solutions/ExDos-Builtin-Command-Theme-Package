#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "commands.h"

/*
*
*           [ UPON NEW CONNECTED SOCKET ]
*
* - Set terminal size and change terminal title
*
*/
void new_connection_handler(ExDos *x, Client *c) {
    changeTerminalSize((Socket *)c, string("28"), string("91"));
    ChangeTermTitle((Socket *)c, string("Login | ExDos | Version: 1.0.0"));
}