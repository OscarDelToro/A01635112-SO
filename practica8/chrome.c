#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
    int shmid = shmget(200,400,0644|IPC_CREAT);//creamos bloque de memoria
    int *var;

    var= (int *)shmat(shmid, NULL , 0);//nos conectamos a ese bloque
    int hijos[5];
    for(int i = 0; i < 5; i++){
        int pid = fork();
        hijos[i]=pid;
        if(pid != 0){
            shmid=shmget(200,400,0644);
            int *var = (int *)shmat(shmid,NULL,0);
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
    //int *var = (int *)shmat(shmid,NULL,0);
    for(int i=0; i<100; i++){
        printf("%d,",var[i]);
    }
    printf("\n");
    return 0;

}