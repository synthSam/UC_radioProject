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
    //in c -> [1,100] in p -> [1,10]
    int repetitions;
} emition;

struct grid {
    timeCtrl position;
    emition tag;
};

void set_type(emition *value);

void thePopular(struct grid arr[], int limit);

int main(){
    struct grid data[5];
    data[0].tag.type = 'c';
    data[0].tag.popularity = 10;
    
    data[1].tag.type = 'c';
    data[1].tag.popularity = 60;
    
    data[2].tag.type = 's';
    data[2].tag.popularity = 10;
    
    data[3].tag.type = 's';
    data[3].tag.popularity = 6;
    
    data[4].tag.type = 'c';
    data[4].tag.popularity = 85;
    
    thePopular(data, 5);
    return 0;
}

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

void thePopular(struct grid arr[], int limit){
    int discarted[limit];
    int discard_i = 0;
    
    struct grid popSon;
    struct grid popShw;
    popSon.tag.popularity = 0;
    popShw.tag.popularity = 0;
    
    for(int i=0; i<limit; i++){
        if(arr[i].tag.type == 'c'){
            if(arr[i].tag.popularity > popSon.tag.popularity){
                popSon.tag.popularity = arr[i].tag.popularity;
                discarted[discard_i] = i;
                discard_i++;
            }
        }
        
        if(arr[i].tag.type == 's'){
            if(arr[i].tag.popularity > popShw.tag.popularity){
                popShw.tag.popularity = arr[i].tag.popularity;
                discarted[discard_i] = i;
                discard_i++;
            }
        }
    }
    
    printf("pop c %i\n", popSon.tag.popularity);
    printf("pop s %i\n", popShw.tag.popularity);
}
