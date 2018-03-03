#include <iostream>
#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string>

using namespace std;


typedef struct MyMsg {

        int type;
        char msg[10];

}MyMsg;

int main()
{
        int msg_id;
        key_t key = ftok("msgqfile",65);

        msg_id = msgget(key, IPC_CREAT | 0666);

        MyMsg objMsg;

        int returnVal = msgrcv(msg_id, &objMsg, 128, 1,0);

        if(returnVal > 0 )
        cout << "Message : " << objMsg.msg << " sent \n";


        return 0;

}
