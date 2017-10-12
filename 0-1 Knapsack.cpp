#include <iostream>
using namespace std;

int max(int a, int b)
{
    if(a>b)
    return a;
    else 
    return b;
}
void knapsack(int sack_wt,int noOfItems, int value[], int wt[])
{
    int knapsackArray[noOfItems][sack_wt+1];
    // row(i) represents items
    // column(j) represents sack weight
    for(int i=0;i < noOfItems;i++)
    {
        for(int j=0;j<sack_wt+1;j++)
        {
            if(j==0 )
            {
                knapsackArray[i][j] = 0;
            }else if(i==0) // For the first row, previous best value is not calculated; hence it is considered 0;
            {
              if(j < wt[i]) // sack weight is less than Item weight, Item cannot be included . Use the previous weight
                {
                    knapsackArray[i][j] = 0;
                }else // sack weight is greater  than Item weight so Item can be included. Decide to include or not
                {
                    
                    knapsackArray[i][j] = value[i] ; 
                    
                }  
            }else{
                if(j < wt[i]) // sack weight is less than Item weight, Item cannot be included . Use the previous weight
                {
                    knapsackArray[i][j] = knapsackArray[i-1][j];
                }else // sack weight is greater  than Item weight so Item can be included. Decide to include or not
                {
                    
                    knapsackArray[i][j] = 
                    max(knapsackArray[i-1][j] , value[i] + knapsackArray[i-1][j-wt[i]]);
                    
                }
            }
        }
    }
    
   for(int i=0;i < noOfItems;i++)
    {
        for(int j=0;j<sack_wt+1;j++)
        {
            cout << knapsackArray[i][j] << "  ";
        }
        cout << "\n" ;
    }
    cout << knapsackArray[noOfItems-1][sack_wt] << endl;
}

int main() {
	//code
	int sack_wt = 4;
	int noOfItems = 3;
	int value[] = {1,2,3};
	int wt[] = {4,5,1};
	
	knapsack(sack_wt,noOfItems,value,wt);
	
	return 0;
}