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
	objMsg.type = 1;

	strncpy(objMsg.msg, "1234567890", 10);

	size_t msg_len = strlen(objMsg.msg) + 1;

	int returnVal = msgsnd(msg_id, &objMsg, msg_len, IPC_NOWAIT);

	if(returnVal > 0 )
	cout << "Message : " << objMsg.msg << " sent \n";


	return 0;

}
