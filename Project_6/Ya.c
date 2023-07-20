/* 
Pace University CS610
Yakshita Rakholiya
Project-6 @Dr.Lixin Tao @Kai Wang
*/
#include <math.h>
#include <stdlib.h>


#define N 100
#define numpoints 30

using namespace std;

float f(float x, float y) {
  return sqrt(4.0 - x * x - y * y);
}

int a, b;
int i, j;

float integrate() {
  float h = (b - a) / (N * numpoints);
  float localsum = 0.0;

  for (i = 0; i < N * numpoints; i++) {
    float x = a + i * h;
    for (j = 0; j < N * numpoints; j++) {
      float y = a + j * h;
      localsum += f(x, y);
    }
  }

  return localsum;
}

int main(int argc, char** argv) {
  float globalsum = 0.0;

  for (i = 0; i < N * N; i++) {
    globalsum += integrate();
  }

  float h = (b - a) / (N * numpoints);
  float answer = globalsum * h * h;
  cout << "The approximation to pi is: " << answer << endl;

  return 0;
}

