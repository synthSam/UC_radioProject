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

bool isNumeral(char x){
    bool valid = false;
    if(x >= '0' && x <= '9'){
        valid = true;
    }
    return valid;
}

int main(){
    //48-57
    struct grid data[3];
    char str[size] = "Ciencia Critica 10 00 4 8";
    int stop = strlen(str);
    int ctrlChar;
    printf("%i\n", stop);
    
        for(int i=0; i<stop; i++){
            ctrlChar = str[i];
            if(isNumeral(ctrlChar)){
                printf("%c", ctrlChar);
            }
            if(ctrlChar == ' ' && isNumeral(str[i-1])){
                printf("%c", ctrlChar);
            }
            
        }
    return 0;
}
