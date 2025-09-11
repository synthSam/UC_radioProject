#include <stdio.h>
#include <stdbool.h>

//global constants
#define MAX_SONGS 1000
//song constants
#define SONG_NAME_MAX 50
#define SONG_MIN 15
#define SONG_SEC 59
#define SONG_SCORE_MAX 100
#define SONG_SCORE_MIM 1
//add constants
#define ADD_COMPANIE_NAME_MAX 30
#define ADD_SEC 60
//show contants
#define SHOW_NAME 100
#define SHOW_MINUTES_MAX 120
#define SHOW_SECONDS_MAX 60
#define SHOW_PREF_MIN 1
#define SHOW_PREF_MAX 10

#define name_size 30

//structures definitions
typedef int timeCtrl[3];
//timeCtrl[hour, min, sec]

typedef struct emitionCtrl {
    char type;
    //c,s,p
    char name[name_size];
    timeCtrl duration;
    //no emitions have a duration over 30 minutes
    int popularity;
    //in c -> [1,100] in p -> [1,10]
    int repetitions;
    //in c -> [0,6] in order of popularity
} emition;

struct grid {
    timeCtrl position;
    emition tag;
};

//establece el tipo de emicion de la entrada
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

//encuentra la entrada mas popular
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

int main() {
    printf("%i\n", true);
    return 0;
}


