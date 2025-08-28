#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define MAXDATA 999
#define size 30

typedef int timeCtrl[3];
//timeCtrl[] --> 0.hours 1.min 2.sec

typedef struct emitionCtrl {
    char type;
    char name[size];
} tag;

struct grid {
    timeCtrl position;
    tag emition;
};

//funcitions
void p_time(struct grid info);

int main(){
    struct grid data[MAXDATA];
    
    //position in
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            data[i].position[j] = (j+1)*10;
        }
    }
    
    //emition in
    for(int i=0; i<3; i++){
        data[i].emition.type = 'S';
        strcpy(data[i].emition.name, "warhammer");
    }
    
    //print this thing
    for(int i=0; i<3; i++){
        p_time(data[i]);
        printf("%c %s\n", data[i].emition.type, data[i].emition.name);
    }
    
    
    
    return 0;
}

void p_time(struct grid info){
    for(int i=0; i<3; i++){
        printf("%i:", info.position[i]);
    }
    printf("\t");
}
