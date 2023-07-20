/* 
Pace University CS610
Yakshita Rakholiya
Project-6 @Dr.Lixin Tao @Kai Wang
*/

ARCHITECTURE MESH2(20);
#include <stdlib.h>
#include <math.h>

#define numproc 40 
#define numpoints 30 

float a , b ,w , globalsum;
int i;


float f(float t) 
{
 return (sqrt (4-t*t)); 
}


void Integrate( int myindex) {
  float localsum = 0;
  float t;
  int j;
 t = a + myindex*(b-a)/numproc; 
 for (j = 1; j <= numpoints; j++) {
 localsum = localsum + f(t); 
 t = t + w;
 }
 localsum = w * localsum;
 globalsum = globalsum+localsum; 
 return globalsum;
 }


main( )
{
 float answer;
 cout << " Enter"<<endl;
 cin>> a>> b;
 
 w = (b-a)/(numproc*numpoints); 

 forall i = 0 to numproc-1 do 
   Integrate(i);
 
 answer = globalsum + w/(2)*(f(b)-f(a)); 
 cout<< answer;
 
}


