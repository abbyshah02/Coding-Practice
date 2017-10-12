#include <stdio.h>
// Given an array and a number k, find Pair with sum = k
using namespace std;

int max = 0;
int findMax(int inputArray[])
{
    for(int i=0;i<6;i++)
    {
        if(inputArray[i] > max)
            max = inputArray[i];
    }
}

int findPair(int inputArray[], int num)
{
    int arr[max+1];
    
    for(int i=0;i<6;i++)
    {
        if(arr[num-inputArray[i]] == 1)
        {
            return 1;
        }
        else
        {
            arr[inputArray[i]] = 1;
        }
        
        
    }
    
    return 0;
}


int main() {
	//code
	
	int arr[]={1,4,45,6,10,8};
	int num = 16;
	
	findMax(arr);
	
	if(findPair(arr,num) == 1)
	{
	    printf("Yes");
	}else
	{
	    printf("No");
	}
	
	return 0;
}