/* 
Pace University CS610
Yakshita Rakholiya
Project-6 @Dr.Lixin Tao @Kai Wang
*/

#include <stdlib.h>
#include <math.h>

#define num_threads 40 
#define num_intervals 30 

int i;
float a, b, global_sum, result, interval_width;

spinlock L;

float f(float t)  
{ 
  return(sqrt(4 - t*t));
}

void Integrate(int myindex) 
{
  float local_sum = 0;
  float t = a + myindex * (b - a) / num_threads;
  int j;
   
  for (j = 1; j <= num_intervals; j++) 
  {  
    local_sum = local_sum + f(t); 
    t = t + interval_width;  
  }
  local_sum = interval_width * local_sum;
  Lock(L); 
  global_sum = global_sum+local_sum;
  Unlock(L);   
}
main( )
{ 
a = 0;
b = 2;
interval_width = (b-a)/(num_threads*num_intervals); 
forall i = 0 to num_threads-1 do  
Integrate(i);
result = global_sum + interval_width/2*(f(b)-f(a)); 
cout << result;
}