#ifndef OBSERVER_H
#define OBSERVER_H

typedef enum EMapper_callfFunStatus
{
    MAPPER_OK = 0,
    MAPPER_COMMAND_NOT_EXIST,
    MAPPER_NULL_PTR_ACTION,
}EMapper_callfFunStatus;

typedef enum EMapper_commandsID
{
    MAPPER_COMMAND_FIRST = 0,

    MAPPER_COMMAND_ID_1 = MAPPER_COMMAND_FIRST,
    MAPPER_COMMAND_ID_2,
    MAPPER_COMMAND_ID_3,
    MAPPER_COMMAND_ID_4,
    MAPPER_COMMAND_ID_5,

    /*add commands before*/
    MAPPER_COMMAND_LAST = MAPPER_COMMAND_ID_5,
}EMapper_commandsID;

EMapper_callfFunStatus processCommand(EMapper_commandsID commandID);

#endif //OBSERVER_H