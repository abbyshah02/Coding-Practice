#include <stdio.h>
#include <iostream>
using namespace std;

void largestSum(int arr[], int size)
{
    int max_so_far = 0;
    int max_endingAt = 0;
    int s=0;
       int start = s;
        int end ;
    
    for(int i=0;i<size;i++)
    {
     
        max_endingAt = max_endingAt + arr[i];
        //if max_endingAt is less than zero, make max_endingAt=0
        if(max_endingAt < 0)
        {
            max_endingAt = 0;
            s = i+1;
        }   
        else if(max_endingAt > max_so_far){
            max_so_far = max_endingAt;
            start = s;
            end=i;
        }
        
    }
    if(max_so_far == 0)
    {
        cout << "No positive number in the array" <<endl;
    }else{
        cout << max_so_far << endl;
        cout << "Start Index : "<< start << endl;
        cout << "End Index : " << end << endl;
    }
}

int main() {
	//code
	int inputArray[] = {-2,-3,4,-1,-2,1,5,-3};
	int size = sizeof(inputArray)/sizeof(inputArray[0]);
	
	largestSum(inputArray,size);
	
	
	return 0;
}