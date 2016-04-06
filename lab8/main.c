#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

#define DATASIZE 500

int priority (const void *a, const void *b){
  int* first = (int*)a;
  int* second = (int*)b;

  return second[2] - first[2];
}

int arrivaltime (const void *a, const void *b){
  int* first = (int*)a;
  int* second = (int*)b;

  return first[1] - second[1];
}


int main (int argc, char *argv[]){
  //void qsort(void *base, size_t nmemb, size_t size, int (*compar) (const void *, const void *)

  int* readdata = (int*)malloc(DATASIZE*sizeof(int));


  FILE* file = fopen ("process.txt", "r");
  int value = 0;
  int counter = 0;

  fscanf (file, "%d", &value);
  while (!feof (file)){  
    readdata[counter] = value;
    fscanf (file, "%d", &value);
    counter++;
  }
  fclose (file); 

  int array[DATASIZE][3];
  int newcounter = 0;
  for(int i = 0; i < counter/3; i++){
    for(int j = 0; j < 3; j++){
      array[i][j] = readdata[newcounter];
      newcounter++;
    }
  }
  //free(readdata);

  printf("\nSorting by priority, descending.\n");
  qsort((void*) array, counter/3, 3*sizeof(int), priority);

  for(int i = 0; i < counter/3; i++){
    for(int j = 0; j < 3; j++){
      printf("%d ", array[i][j]);
    }
    printf("\n");
  }

  printf("\nSorting by arrival time, ascending.\n");
  qsort((void*) array, counter/3, 3*sizeof(int), arrivaltime);

  for(int i = 0; i < counter/3; i++){
    for(int j = 0; j < 3; j++){
      printf("%d ", array[i][j]);
    }
    printf("\n");
  }


  return 0;
}

