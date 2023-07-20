
/* 
Pace University CS610
Yakshita Rakholiya
Project-6 @Dr.Lixin Tao @Kai Wang
*/

ARCHITECTURE TORUS(7);
#include <stdlib.h>
#include <math.h> 
#define n 10;
float A[n][n],B[n][n],C[n][n]; /*master data arrays*/
float stream Achan[n][n];
float stream Bchan[n][n];
int i,j;

void Multiply(int row, int col, float myA, float myB, float *mainC) {
 int n=10;
 int iter, above, left;
 float myC;
 if (row > 0) above = row-1;
 else above = n-1; /*up neighbor*/

 if (col > 0) left = col-1;
 else left = n-1; /*left neighbor*/
 myC = 0;
 for (iter = 1; iter <= n; iter++) {
 send(Achan[row][left], myA); /*Send myA left*/
 send(Bchan[above][col], myB); /*Send myB up*/
 myC = myC + myA*myB;
 recv(Achan[row][col], myA); /*Receive new myA*/
 recv(Bchan[row][col], myB); /*Receive new myB*/
 }
 *mainC = myC; /*Send final value to main process*/
}

main( ) {
  int n=10;
  cout.precision(8); /* use 8 significant digits for float output */
  for (i = 0; i < n; i++){
    for (j = 0; j < n; j++) {
      A[i][j] = (rand()%1000);
      B[i][j] = (rand()%1000);
    }
 }
forall i = 0 to n-1 do
 forall j = 0 to n-1 do
  fork (@i*n+j)
  Multiply(i,j,A[i][(j+i)%n],B[(i+j)%n][j],&C[i][j]);
  cout << "arr[" << i << ", " << j << "] = " << C[i][j] << endl;


}
