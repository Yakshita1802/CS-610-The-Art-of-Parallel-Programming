/* 
Pace University CS610
Yakshita Rakholiya
Project- 3 @Dr.Lixin Tao @Kai Wang
*/

#include<stdlib.h>
#include<math.h>
#define n 100
boolean Prime_number[n+1];
int i,num,loc,j,k;
main( ) 
{
 	for (i = 1; i <= n; i++)
	
 		Prime_number[i]=TRUE;

 	for (num = 2; num <= Sqrt(n); num++)
	{
		if(Prime_number[num]) 
	     {
 			loc=num+num;
 			while(loc <= 10) 
			{
cout<<loc<<endl;
cout<<" is not a prime"<<endl;
 				Prime_number[loc] = False;
 				loc+=num;
 			}
 		}
		forall j=11 to 100 grouping 10 do
		{
			if(j%num==0)
			{
				Prime_number[j]=FALSE;
 			}
		}
	}
	for(k=1;k<=n;k++)
	{
		if(Prime_number[k])
		{
			cout<< k << endl;
			cout<<" is a prime number"<<endl;
		}
		else
		{
			cout << k << endl;
			cout<<" is not a prime number"<<endl ;
		}
	}
	
}