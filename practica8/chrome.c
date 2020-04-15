#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
    int shmid = shmget(200,100,0644|IPC_CREAT);//creamos bloque de memoria
    char *var;

    var= (char *)shmat(shmid, NULL , 0);//nos conectamos a ese bloque
    int hijos[5];
    for(int i = 0; i < 5; i++){
        int pid = fork();
        hijos[i]=pid;
        if(pid != 0){
            shmid=shmget(200,100,0644);
            char *var = (char *)shmat(shmid,NULL,0);
            var= &var[10*i];
            for(int j = 0; j < 10; j++){
                var[j] = i + '0';
            }
            return 0;
        }
    }
    for(int i = 0; i < 5; i++){
        waitpid(hijos[i],0,0);

    }
    //sprintf(var,"hola mundo");
    printf("Esto tiene var %s",var);
    return 0;

}