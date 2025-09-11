#include <stdio.h>
#include <stdbool.h>

//global constants
#define MAX_SONGS 1000
//song constants
#define song_name_max 50
#define song_min 15
#define song_sec 59
#define song_score_max 100
#define song_score_min 1
//add constants
#define add_companie_name_max 30
#define add_sec 60
//show contants
#define show_name 100
#define show_minutes_max 120
#define show_seconds_max 60
#define show_pref_min 1
#define show_pref_max 10

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
    //in c -> [1,100] in s -> [1,10]
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


