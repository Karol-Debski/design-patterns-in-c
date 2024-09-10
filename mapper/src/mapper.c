#include <stdint.h>
#include <stdio.h>

#include "mapper.h"

void command_1()
{
    printf("%s","Execute command 1\n");
}

void command_2()
{
    printf("%s","Execute command 2\n");
}

void command_3()
{
    printf("%s","Execute command 3\n");
}

void command_4()
{
    printf("%s","Execute command 4\n");
}

void command_5()
{
    printf("%s","Execute command 5\n");
}

typedef void (*commandFun_t)(void);

typedef struct command_t
{
    EMapper_commandsID commandID;
    commandFun_t action;
}command_t;

const command_t commandMapper[] = {
    {MAPPER_COMMAND_ID_1,command_1},
    {MAPPER_COMMAND_ID_2,command_2},
    {MAPPER_COMMAND_ID_3,command_3},
    {MAPPER_COMMAND_ID_4,command_4},
    {MAPPER_COMMAND_ID_5,command_5},
};

#define COMMAND_MAPPER_SIZE (sizeof(commandMapper)/sizeof(commandMapper[0]))


EMapper_callfFunStatus processCommand(EMapper_commandsID commandID)
{
    if(commandID < MAPPER_COMMAND_FIRST || commandID > MAPPER_COMMAND_LAST)
    {
        return MAPPER_COMMAND_NOT_EXIST;
    }

    for(uint32_t i = 0; i < COMMAND_MAPPER_SIZE; i++)
    {
        if(commandMapper[i].commandID == commandID)
        {
            if(commandMapper[i].action == NULL)
            {
                return MAPPER_NULL_PTR_ACTION;
            }

            commandMapper[i].action();
            break;
        }
    }

    return MAPPER_OK;
}

