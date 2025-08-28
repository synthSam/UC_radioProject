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

int main(){
    struct grid data[3];
    
    
    
    return 0;
}

