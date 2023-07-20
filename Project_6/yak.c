/* 
Pace University CS610
Yakshita Rakholiya
Project-6 @Dr.Lixin Tao @Kai Wang
*/

ARCHITECTURE MESH2(20);
#include <math.h>
#include <stdlib.h>

#define num_threads 30;
#define num_intervals 100;


int i,j;
float a, b, global_sum, result, interval_width;

float f(float t) 
{
    return sqrt(4 - t*t);
}

void Integrate(int myindex) 
{
    float local_sum = 0;
    float t = a + myindex*(b-a)/num_intervals; 
	
    for (j = 1; j <= num_threads; j++)  
	{
        local_sum = local_sum + f(t); 
        t = t + interval_width;
    }
    local_sum = interval_width * local_sum;
    global_sum = global_sum + local_sum; 
}

int main() 
{
    a = 0;
    b = 2;
    interval_width = (b-a)/(num_intervals * num_threads); 
	
    for (i = 0; i < num_intervals; i++) 
    {
        Integrate(i);
    }
    result = global_sum + interval_width/2*(f(b)-f(a)); 
    cout << result;
    
}
