/* 
Pace University CS610
Yakshita Rakholiya
Project-2 @Dr.Lixin Tao @Kai Wang
*/

#define n 5
#include<stdlib.h>
float arr1[n+2][n+2], arr2[n+2][n+2];
int v1,v2,v3;
main( ) 
{
	cout<<"Enter Sample Data"<<endl;
	for(v3=0;v3<n;v3++)
	{
		int m;
		for(m=0;m<n;m++)
		{
			cin>>arr1[v3][m];
		}
	}	
 	arr2 = arr1;
 	forall v1 = 1 to n-2 do 
	{ 
		int v2;
 		for (v2 = 1; v2 < n-1; v2++)
		{
		 	arr2[v1][v2] =(arr1[v1-1][v2] + arr1[v1+1][v2] +
 			arr1[v1][v2-1] + arr1[v1][v2+1]+ arr1[v1-1][v2-1]+arr1[v1+1][v2-1]+arr1[v1+1][v2+1]+arr1[v1-1][v2+1]+arr1[v1][v2]) / 9;
 		}
	}
 	cout<<"Output after precision Smoothing Algorithm"<<endl;
	for(v3=0;v3<n;v3++)
	{
		int l;
		for(l=0;l<n;l++)
		{
			cout.precision(3);
			cout<<arr2[v3][l]<<" ";
		}
		cout<<endl;
	}
}
