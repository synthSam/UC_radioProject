#include <stdio.h>
#include <stdbool.h>

//intento crear funciones para usar con la grilla la cual es probablemente un vector struct

struct node{
        int a;
        int b;
        int c;
};

void printTime(int hour, int min, int sec);
int printTimeChange(struct node *val){
    
}

int main() {
        struct node val;
        val.a = 23;
        val.b = 58;
        val.c = 50;
    
        printTime(val.a, val.b, val.c);
        return 0;
}

void printTime(int hour, int min, int sec){
        const int max_h = 23;
        const int max_m = 59;
        const int max_s = 60;
            
        while(hour < max_h || min < max_m || sec < max_s){
                if(min == 60){
                    hour++;
                    min = 0;
                }
                if(sec == 60){
                    min++;
                    sec = 0;
                }
                if(hour < 10){
                    printf("0%i\t", hour);
                }else{
                    printf("%i\t", hour);
                }
                if(min < 10){
                    printf("0%i\t", min);
                }else{
                    printf("%i\t", min);
                }
                if(sec < 10){
                    printf("0%i\n", sec);
                }
                else{
                    printf("%i\n", sec);
                }
                sec++;
    }
}
