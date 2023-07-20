ARCHITECTURE MESH2(20);
#include <math.h>
#include <stdlib.h>
#include <omp.h>

#define num_threads 30;
#define num_intervals 100;


int i,j;
float a, b, result, interval_width;

float f(float t) 
{
    return sqrt(4 - t*t);
}

int main() 
{
    a = 0;
    b = 2;
    interval_width = (b-a)/(num_intervals * num_threads); 

    float global_sum = 0.0;
    #pragma omp parallel num_threads(num_threads)
    {
        float local_sum = 0.0;
        float t = a + omp_get_thread_num() * interval_width;
        
        for (i = 0; i < num_intervals; i++)  
        {
            local_sum += f(t); 
            t += interval_width * num_threads;
        }
        
        #pragma omp critical
        {
            global_sum += local_sum;
        }
    }
    
    result = global_sum * interval_width; 
    result += interval_width/2*(f(b)-f(a)); 
    cout << result;
    
}
