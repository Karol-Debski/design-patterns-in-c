#include <stdlib.h>
#include <string.h>

#include "mapper.h"


int main()
{
    processCommand(MAPPER_COMMAND_ID_1);
    processCommand(MAPPER_COMMAND_ID_4);

    processCommand(10);
    processCommand(-5);

    return 0;
}