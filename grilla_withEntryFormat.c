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
    //c,s,p
    char name[size];
    timeCtrl duration;
    //no emitions have a duration over 30 minutes
    int popularity;
    //in s -> [1,100] in p -> [1,10]
    int repetitions;
} emition;

struct grid {
    timeCtrl position;
    emition tag;
};

void set_type(emition *value){
    if(value->type == 'c'){
        value->repetitions = 0;
        printf("its a song\n");
    }
    if(value->type == 's'){
        value->duration[1] = 0;
        printf("its a radio show\n");
    }
    if(value->type == 'p'){
        printf("ok its an add\n");
    }
}

int main(){
    struct grid data;
    data.tag.type = 'c';
    set_type(&data.tag);
    printf("%i\n", data.tag.repetitions);
    
    return 0;
}

