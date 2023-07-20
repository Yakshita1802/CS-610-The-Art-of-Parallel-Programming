#include <math.h>
#define nproc 40 /*total process in the c program*/
#define npoints 30 /*total points per process*/ 
float a,b,w,total_global,final_answer;
int i;
spinlock L;
float f(float t)  
{ 
  return(sqrt(4 - t*t));
}
void Integrate(int myindex) {
  float lsum = 0;
  float t;
  int j;
  t = a + myindex * (b - a) / nproc; 
  for (j = 1; j <= npoints; j++) {  
    lsum = lsum + f(t); 
    t = t + w;  
  }
  lsum = w * lsum;
  Lock(L); 
  total_global = total_global+lsum;
  Unlock(L);   
}
main( )
{ 
a = 0;
b = 2;
w = (b-a)/(nproc*npoints); /*space points*/
forall i = 0 to nproc-1 do  /*process creations*/
Integrate(i);
final_answer = total_global + w/2*(f(b)-f(a)); /*ending points*/
cout << final_answer;
}