#include <stdio.h>
#include <stdbool.h>

//global constants
#define MAX_SONGS 1000
#define 
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

struct song{
        char name[];
        int min;
        int sec;
        int popularity;
}

struct add{
        char companie[];
        int sec;
        int repetitions;
}

struct show{
        char name[]
        int min;
        int sec;
        int segments;
        int preferencia;
}

int main() {
    printf("%i\n", true);
    
    return 0;
}
