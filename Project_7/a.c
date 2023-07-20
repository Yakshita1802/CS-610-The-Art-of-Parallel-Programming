
ARCHITECTURE TORUS(7);

#define p_arr_size 7 
#define p_arr 5 

typedef float my_arr[p_arr+1][p_arr+1]; 
my_arr a[p_arr_size][p_arr_size], b[p_arr_size][p_arr_size], c[p_arr_size][p_arr_size]; 
my_arr stream One[p_arr_size][p_arr_size], stream Two[p_arr_size][p_arr_size]; 
int x,y; 

void my_func(int i, int j, 
       value my_arr var_A, value my_arr var_B, 
	   my_arr var_C) { 
  int x,y,k,iter,u,l; 
  my_arr myC = {0}; 
  if (i > 0) u = i-1; else u = p_arr_size-1; 
  if (j > 0) l = j-1; else l = p_arr_size-1; 
  for (iter = 1; iter <= p_arr_size; iter++) { 
    send(One[i][l], var_A); 
	send(Two[u][j], var_B); 
	
	for (x = 1; x <= p_arr; x++) 
	  for (y = 1; y <= p_arr; y++) 
		for (k = 1; k <= p_arr; k++) 
		  myC[x][y] = myC[x][y] + var_A[x][k]*var_B[k][y]; 
	recv(One[i][j], var_A); 
	recv(Two[i][j], var_B); 
  }
  var_C = myC; 
}

main( ) { 
  
  int k, l;
  for (x = 0; x < p_arr_size; x++)
	for (y = 0; y < p_arr_size; y++)
	  for (k = 1; k <= p_arr; k++) 
	    for (l = 1; l <= p_arr; l++) {
		  a[x][y][k][l] = (rand() % 100)/10.0;
		  b[x][y][k][l] = (rand() % 100)/10.0;
	  }
		
  
  for (x = 0; x < p_arr_size; x++) 
	for (y = 0; y < p_arr_size; y++) 
	  fork (@x*p_arr_size+y) 
        my_func(x, y, a[x][(y+x)%p_arr_size], b[(x+y)%p_arr_size][y], c[x][y]); 
	
  for (x = 0; x < p_arr_size; x++) 
	for (y = 0; y < p_arr_size; y++) 
	  join;

  cout.precision(4); 
  for (x = 0; x < p_arr_size; x++) {
	for (y = 0; y < p_arr_size; y++) {
	  cout << "my_arr["<< x << ", " << y <<"]" << endl;
	  for (k = 1; k <= p_arr; k++) {
		for (l = 1; l <= p_arr; l++) 
		  cout << c[x][y][k][l] << ", ";
	    cout << endl;
	  }	  
	}
  }
}
