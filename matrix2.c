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
  
  // workload ana grammi                                  ana grammi
	for (i=0; i<NCOLS; i++) {
		for (j=0; j<NROWS; j++) {
			table[i*NROWS +j]=table[i*NROWS +j]+13;              
		}	
	} 

  // ...your code here...

  // get ending time  
  get_walltime(&te);

  // check results
  
  // ...your code here...
	for (i=0; i<NROWS*NCOLS; i++) {
			if (table[i]!=14.0) { //an den einai iso me to arxiko+13 pou tou edwsa 
				printf("There was a problem!");		
			}
			
			
	}
  // print time elapsed and/or Maccesses/sec
  double timepassed= te-ts; //orizo timepassed=end-start
	printf("\n\ntimepassed: %lf\n",timepassed);		
  // ...your code here...  
  
  free(table);

  return 0;
}

