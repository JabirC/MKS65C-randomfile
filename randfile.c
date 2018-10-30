#include "randfile.h"

int * randomNumGen(){
  int * arr = calloc(10 , sizeof(int));
  int file = open("/dev/random",  O_RDONLY );
  for(int i =0; i < 10; i++){
    read(file, arr + i, sizeof(int));
  }
  close(file);
  return arr;
}

int main(){
  int * randomNums = randomNumGen();
  for(int i =0; i < 10; i++){
    printf("Index[%d] =  %d\n", i, *(randomNums + i));
  }

  int file = open("nums.txt", O_WRONLY);
  printf("file for WRONLY open value : %d\n", file );
  write(file, randomNums, 10 * sizeof(int));
  close(file);

  int * numsFromText = calloc(10, sizeof(int));
  file = open("nums.txt", O_RDONLY);
  printf("file for RDONLY open value : %d\n", file );
  read(file, numsFromText, 10 * sizeof(int));
  close(file);

  for(int i = 0; i <10; i++){
    printf("Index[%d]  :  %d\n", i , *(numsFromText + i));
  }
  free(numsFromText);
  free(randomNums);
}
