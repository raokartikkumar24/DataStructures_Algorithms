#include <iostream>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>

using namespace std;
int main() {
    
    key_t key = ftok("shmsend.c",65);
    
    cout << "Generated key : " << key << "\n";
    
    int shmid = shmget(key, 1024, IPC_CREAT | 0666);
    
    char *memory = (char *) shmat(shmid, (void*)0, 0);
    
    cout << "type the msg that has to be sent : ";
    gets(memory);
    
    cout << "wrote : " << memory << "\n";
    
    shmdt(memory);
    
    return 0;
}
