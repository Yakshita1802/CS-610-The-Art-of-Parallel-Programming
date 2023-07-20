
#include<stdlib.h>
#include<math.h>
#define numproc 100
#define numpoints 30 
float a,b,globalsum,answer,localsum,w,t;
float stream gs1;
float stream gs2;
int i;
spinlock L;
float f(float t) 
{
	return( sqrt(4 - t*t) );
}
void Integrate(int myindex)
{
	float localsum = 0;
	float t,a,b,w,globalsum;
	int j;
	t = a + myindex*(b-a)/numproc; 
	for (j = 1; j <= numpoints; j++)  
	{
		localsum = localsum + f(t); 
		t = t + w;
	}
	localsum = w * localsum;
 	globalsum = globalsum+localsum; 
	
	
}
main( )
{
	a=0;
	b=2;
	w = (b-a)/(numproc*numpoints); 
	forall i = 0 to numproc-1 do 
		Integrate(i);
	
	globalsum = globalsum+localsum; 

	answer = globalsum + w/2*(f(b)-f(a)); 
 
	cout<<answer;
}

