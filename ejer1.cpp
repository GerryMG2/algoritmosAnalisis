
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include "quicksort.h"

using namespace std;

long fibo(int x){
    long a[x];
    a[0] = 0;
    a[1] = 1;
    if(x == 0){
        return 0;
    }else{
        if(x == 1){
            return 1;
        }
       
    }
    for (int i = 2; i < x; i++)
    {
        a[i] = a[i-1] + a[i-2];
    }
    return a[x-1];
    
}


int knapSack(int W, int wt[], int val[], int n) 
{ 
    int i, w; 
    int K[n + 1][W + 1]; 
  
    // Build table K[][] in bottom up manner 
    for (i = 0; i <= n; i++)  
    { 
        for (w = 0; w <= W; w++)  
        { 
            if (i == 0 || w == 0) 
                K[i][w] = 0; 
            else if (wt[i - 1] <= w) 
                K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]],
                            K[i - 1][w]); 
            else
                K[i][w] = K[i - 1][w]; 
        } 
    } 

     for (int i = 0; i < n+1; i++)
    {
        for (int j = 0; j < W+1; j++)
        {

            cout << K[i][j] << " ";
           
        }
        cout << endl;
        
    }
  
    return K[n][W]; 
} 

int main(int argc, char const *argv[])
{
    
    int val[] = {10,40,30,50}; 
    int wt[] = {5,4,6,3}; 
    int W = 10; 
    int n = sizeof(val) / sizeof(val[0]); 
    printf("Peso final: %d\n", knapSack(W, wt, val, n)); 
    
    



    return 0;
}
