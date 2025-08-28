#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define size 30

typedef int timeCtrl[3];

typedef struct emitionCtrl {
    char type;
    char name[size];
} tag;

struct grid {
    timeCtrl position;
    tag emition;
};

int main(){
    struct grid data[10];
    data[0].position[0] = 10;
    for(int i=0; i<3; i++){
         data[0].position[i] = (i+1) * 10;
    }
    strcpy(data[0].emition.name, "warhammer");
    
    for(int i=0; i<3; i++){
        printf("%i:", data[0].position[i]);
    }
    //printf("%i:%i:%i -- %s",data[0].position[0],data[0].position[1],data[0].position[2], data[0].emition.name);
    return 0;
}
