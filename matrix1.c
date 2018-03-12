#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

// compile like:  gcc -Wall -O2 -DNROWS=10000 matrix1.c -o matrix1


#define NCOLS 100

void get_walltime(double *wct) {
  struct timeval tp;
  gettimeofday(&tp,NULL);
  *wct = (double)(tp.tv_sec+tp.tv_usec/1000000.0);
}


int main() {
double *table;
double ts,te;
int i,j;

  table = (double *)malloc(NROWS*NCOLS*sizeof(double)); 
  if (table==NULL) {
    printf("alloc error!\n");
    exit(1);
  }

  // warmup

  // ...your code here..
	for (i=0; i<NROWS*NCOLS; i++) {
		table[i]=1.0;
	}

  // get starting time (double, seconds) 
  get_walltime(&ts);
  
  // workload

  // ...your code here...

	for (i=0; i<NROWS; i++) {
		for (j=0; j<NCOLS; j++) {
			table[i*NCOLS + j];        
		}	
	} 

  // get ending time  
  get_walltime(&te);

  // check results
  
  // ...your code here...

  // print time elapsed and/or Maccesses/sec
  
  // ...your code here...  
  
  free(table);

  return 0;
}

