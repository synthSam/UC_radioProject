#include <stdio.h>
#include <stdbool.h>

#define name_size 30
#define max_list 10

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
} emition;

struct grid {
    timeCtrl position;
    emition tag;
};

void pArr(struct grid arr[], int size){
  int stop = size-1;
  
  for(int i=0; i<stop; i++){
    printf("%i ", arr[i].tag.popularity);
  }
  printf("--\n");
}
//prints the array elements

bool sorted(struct grid arr[], int size){
  bool value = true; 
  
  for(int i=0; i<size-2; i++){
    if(arr[i].tag.popularity < arr[i+1].tag.popularity){
      value = false;
    }
  }
  
  return value;
}
//returns true if the array is sorted from max to min value

void bubbleSortMm(struct grid arr[], int size){
  int change;
  int stop = size-1;
  
  for(int i=0; i<stop; i++){
    for(int j=0; j<stop-i; j++){
      
      if(arr[i].tag.popularity < arr[i+1].tag.popularity){
        change = arr[i].tag.popularity;
        arr[i].tag.popularity = arr[i+1].tag.popularity;
        arr[i+1].tag.popularity = change;
      }
    }
  }
}

void sortMn(struct grid arr[], int size){
  while(!sorted(arr, size)){
    bubbleSortMm(arr, size);
    printf("1\n");
  }
}
//aplasy the bubblesort in an array until is fully sorted

int main(){
  FILE *fp;
  fp = fopen("file.txt", "r");
  if(fp == NULL) printf("ERROR\n"); else printf("run\n");
  
  struct grid list[max_list];
  int i = 0;
  int pass = 0;
  
  while(fscanf(fp, "%i", &pass) == 1 && i < 10){
    //printf("--%i pass\n", pass);
    list[i].tag.popularity = pass;
    //printf("list %i_%i\n", i, list[i].tag.popularity);
    i++;
  }
  

  pArr(list, max_list);
  printf("%i\n", sorted(list, max_list));
  sortMn(list, max_list);
  pArr(list, max_list);
  printf("%i\n", sorted(list, max_list));


  
  
  return 0;
}
