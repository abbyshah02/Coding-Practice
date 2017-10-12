public class subArrayCount{
    
    public static int findMaxSubArrays(int[] array, int maxProduct)
    {
        if(array == null)
        {
            throw new IllegalArgumentException("Array cannot be null");
        }
        
        int n = array.length;
        int product = 1;
        int noOfSubArrays = 0;
        
        for(int left=0, right=-1; left < n; left++)
        {
            
            
            while(right+1 < n && array[right+1]<Math.ceil((double)maxProduct/product))
            {
                right = right + 1;
                product *= array[right];
            }
            
            int subArrayCount = right - left + 1; 
            noOfSubArrays += subArrayCount;
            
            product /= array[left];
            
            
        }
        return noOfSubArrays;
    }
    
    public static void main(String[] args)
    {
        int[] array = {2,4,6};
        int maxProduct = 10;
        int maxSubarrays = findMaxSubArrays( array, maxProduct );
        System.out.println(maxSubarrays);
    }
    
    
    
}