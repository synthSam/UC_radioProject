#include <stdio.h>
#include <stdbool.h>

struct node{
    int h;
    int m;
    int s;
};

void printTime(int hour, int min, int sec);
int printTimeChange(struct node *val){
    
}

int main() {
    struct node origin;
    origin.h = 1; origin.m = 5; origin.s = 0;
    
    struct node new1;
    new1.h = 0; new1.m = 3; new1.s = 20;
    
    printf("0%i 0%i 0%i\n", origin.h, origin.m, origin.s);
    printf("0%i %i %i\n", origin.h + new1.h, origin.h + new1.m, origin.s + new1.s);
    
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
