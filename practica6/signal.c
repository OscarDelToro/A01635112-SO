#include <signal.h>
#include <stdio.h>
#include <unistd.h>
void processSignal(int s){
    printf("Recibi señal" );
}
void nelbro(int s){
    printf("Wish you better luck for the next time, you missed");
}

int main(){
    signal(10, processSignal);
    signal(15,nelbro);
    while(1){
        sleep(3);
        printf("Trabajando\n");

    }
    return 1;
}