ARCHITECTURE HYPERCUBE(5);
#include <stdlib.h> 
#include <math.h> 
#define n 32 /*number of processors*/ 
#define d 5 /*dimension of Hypercube*/ 
#define numiter 2*d /*iterations before termination test*/ 
#define tolerance .1 
typedef float rowtype[n+2]; 
rowtype A[n+2]; /*main data array*/ 
rowtype stream upchan[n+1], stream downchan[n+1]; /*Communication*/ 
int GrayCode[n+1]; 
int i; 
boolean stream inchan[n][d+1]; /*for Aggregation*/ 

boolean Aggregate(boolean mydone) { 
  /*Multiple Aggregation function from Fig 8.11*/ 
  return true;
} 
   
void Updaterow(int me, value rowtype myrow, rowtype out) { 
  int j, k; 
  float maxchange, change; 
  rowtype newrow, uprow, downrow; 
  boolean done; 
  newrow[0] = myrow[0]; 
  newrow[n+1] = myrow[n+1]; 
  if (me == 1) recv(downchan[me], downrow); 
  if (me == n) recv(upchan[me], uprow); 
  do { 
    for (k=1; k<=numiter; k++) { 
	  /*Several iterations before term. test*/ 
	  if (me > 1) 
		send(upchan[me-1], myrow); /*Send to me-1*/ 
	  if (me < n) { 
	    send(downchan[me+1], myrow); /*Send to me+1*/ 
		recv(upchan[me], uprow); /*Receive new uprow*/ 
	  }
	  if (me > 1) 
		recv(downchan[me], downrow); /*New downrow*/ 
	  maxchange = 0;
      for (j = 1; j <= n; j++) { 
	    /*Compute average of neighboring points*/ 
		newrow[j] = ( myrow[j-1]+myrow[j+1] 
		             +downrow[j]+uprow[j] ) / 4; 
		change = fabs(newrow[j]-myrow[j]); 
		if (change > maxchange) maxchange = change; 
	  }
	  myrow = newrow; 
	}
	/*termination test*/ 
	done = Aggregate(maxchange < tolerance);
  } while (!done); 
  out = myrow; /*Write final answer back to F*/ 
}

/* generate dim-bit gray code in array GrayCode[] */
void ComputeGray(int dim) {
  int len;   /*number of elements in code so far*/
  int bits;  /*number of bits in code so far*/
  int base;  /*end of code in the array*/
  int i;
  GrayCode[0] = 0; /*starting code*/
  base = 1; len = 1; bits = 0;
  for (bits = 1; bits <= dim; bits++) {
	for (i = 1; i <= len; i++)
      GrayCode[base+i-1] = GrayCode[base-i] + len;
    base = base + len;
    len = 2*len;	
  }
}

main( ) { 
  int c, r;
  /*Initialize values for array A*/ 
  for (c = 0; c <= n+1; c++)
	for (r = 0; r <= n+1; r++)
	  A[c][r] = (rand() % 100)/10.0;
 
  ComputeGray(d);  /*Initialize Gray Code array for Hypercube*/ 
  cout << "5-Bit Gray Code:" << endl;
  for (i = 0; i < 32; i++) { 
	cout << GrayCode[i];
    if ((i % 10) == 9) cout << endl;
  }
  cout << endl << endl;

  send(downchan[1], A[0]); 
  send(upchan[n], A[n+1]); /*Fixed boundary values*/ 
  forall i = 1 to n 
    @GrayCode[i] do Updaterow(i, A[i], A[i]); 
	
  /*Output values in array A*/ 
  cout.precision(2); /* use 2 significant digits for float output */
  cout << "Output:" << endl;
  for (c = 0; c <= n+1; c++){
	for (r = 0; r <= n+1; r++) {
	  cout << A[c][r] << ", ";
	  if (((r+1) % 12) == 0) cout << endl;
	}
	cout << endl;
  }
}
