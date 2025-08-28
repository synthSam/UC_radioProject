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

int main(){
    struct grid data[MAXDATA];
    
    
    
    return 0;
}

