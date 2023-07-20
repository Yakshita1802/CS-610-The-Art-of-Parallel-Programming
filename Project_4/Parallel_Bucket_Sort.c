/* 
Pace University CS610
Yakshita Rakholiya
Project-4 @Dr.Lixin Tao @Kai Wang
*/

#include <stdlib.h>
#define n 100;
int arrBefore[n + 1];
int arrAfter[n + 1];
int bucket_list[n + 1];
spinlock K[n + 1];
spinLock K2;
int i, j;

main () {
    
    int index = 1;
    forall i = 1 to n grouping 10 do
        arrBefore[i] = rand() % 100 + 1;
    
    forall i = 1 to n grouping 10 do
        bucket_list[i] = 0;

    for(i = 1; i<=n; i++) {
        Lock(K[arrBefore[i]]);
        bucket_list[arrBefore[i]] += 1;
        Unlock(K[arrBefore[i]]);
    }

    for(i = 1; i<=n; i++) {
        Lock(K2);
        int x = bucket_list[i];
        for(j = 1; i<i; j++) {
            index += bucket_list[j];
        }
        while(x > 0) {
            arrAfter[index] = i;
            x--;
            index++;
        }
        Unlock(K2);
    }
    
    for(i = 1; i<=n; i++) {
        cout << arrBefore[i];
        if(i % 10 == 0) cout << endl;
    }    
    
    cout << "Sorting Array";
    cout << endl;

    for(i=1; i<=n; i++) {
        cout << arrAfter[i];
        if(i % 10 == 0) cout << endl;
    }
}