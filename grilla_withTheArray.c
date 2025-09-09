#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define MAXDATA 999
#define size 30

//structures definitions
typedef int timeCtrl[3];
//timeCtrl[hour, min, sec]

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
//prints the time stamp of the info entry
void p_name(struct grid info);
//prints the name of the info emition

int main(){
    struct grid data[MAXDATA];
    //this is exit format
    //position in
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            data[i].position[j] = (j+1)*10;
        }
    }
    
    //emition in
    for(int i=0; i<3; i++){
        data[i].emition.type = 'S';
        strcpy(data[i].emition.name, "warhammer radio");
    }
   
    //print this thing
    for(int i=0; i<3; i++){
        p_time(data[i]);
        p_name(data[i]);
    }
    
    
    return 0;
}

void p_time(struct grid info){
    for(int i=0; i<3; i++){
        printf("%i", info.position[i]);
        if(i != 2) printf(":");
    }
    printf(" ");
}

void p_name(struct grid info){
    printf("%c %s\n", info.emition.type, info.emition.name);
}
