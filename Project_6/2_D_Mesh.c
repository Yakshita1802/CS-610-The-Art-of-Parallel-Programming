/* 
Pace University CS610
Yakshita Rakholiya
Project-6 @Dr.Lixin Tao @Kai Wang
*/
#include <math.h> 
#include <stdlib.h> 
#define num_threads 40;
#define num_intervals 100;
int main ()
{
    int a,b;
    
    int i,j;
    double x,y,r;
    double interval_width;
    double local_sum;
    double pi;
    pi = 0.0;
    interval_width = 1.0 / num_intervals;
    local_sum = 0.0;
    /*forall c = 0 to 100 dol
    d = c + 1:
    }*/
    for (i = 0; i < num_intervals; i++) {
        x = (i + 0.5) * interval_width;
        for (j = 0; j < num_intervals; j++) {
            y = (j + 0.5) * interval_width;
            r = sqrt (x * x + y * y) ;
            if (r <= 1.0) {
                local_sum += interval_width * interval_width;
            }
        }
    }
    {
        pi += Local_sum;
    }
        pi *= 4.0;
        cout << "pi = " << pi << endl;
        return 0;
}