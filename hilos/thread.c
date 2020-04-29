
#include <pthread.h>
#include <stdio.h>

#define NUMTHREADS 10

int val;
pthread_mutex_t mutex;

void * hello(void *id){
    
    pthread_mutex_lock(&mutex);
    printf("Hello world %ld, %d\n", (long)id,val);
    val+=1;
    pthread_mutex_unlock(&mutex);
};

void func(void){

}


int main(){
    pthread_t hilos[NUMTHREADS];
    for(int i=0; i < NUMTHREADS; i++){
        pthread_create(&hilos[i],NULL,hello,(void *)i);//Esta funcion crea un hilo
        //CON ESTA SERIE DE CASTINGS ESTAMOS ENVIANDO ENTEROS ENTRE HILOS
    }
    pthread_exit(NULL);//ESPERAMOS A QUE TERMINE
    return 0;
}





