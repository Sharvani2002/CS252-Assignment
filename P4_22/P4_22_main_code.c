#include<stdio.h>
#include<stdlib.h>
#include<math.h>
/*
The below header file has been included to use all the functions of the POSIX or pthreads library.
Note that on Linux, programs that use the Pthreads API should be compiled using cc -pthread.
*/
#include <pthread.h>
#include <winpthreads.h>

//Declaring the global variables
int arr[1000];
int n;
//Various statistical values
float averageValue;
int maximumValue;
int minimumValue;
float medianValue;
float standardDeviationValue;

//threadFunction1 to determine the average of the numbers
void *threadFunction1()
{
        int sum=0;
        for(i = 0; i < n; i++)
                sum = sum + arr[i];
        avgValue = sum/n;
        
}
//threadFunction2 to determine the maximum value
void *threadFunction2()
{

        maximumValue=arr[0];
        for(int i=0;i<n;i++)
        {
                if(maximumValue<arr[i])
                {
                        maximumValue=arr[i];
                }
        }
        
        

}
//threadFunction3 to determine the minimum value
void *threadFunction3()
{
        minimumValue=arr[0];
        for(int i=0;i<n;i++)
                if(minimumValue>arr[i])
                        minimumValue=arr[i];
        
                        
}

//threadFunction4 to determine the median value
void *threadFunction4()
{
        /*
        The median is calculated as follows.
        If the input size is
        odd: obtain the middle element of sorted data. 
        even: obtain the average of the middle two elements in the sorted data.
        */

       //sort the array using bubble sort algorithm
       int i;
       int j;
       int temp;
        medianValue = 0.0;
        for (i = 0; i < n; i++) 
        {
                for (j = i + 1; j < n; j++)
                {
                        if (arr[i] > arr[j]) 
                        {

                                temp =  arr[i];
                                arr[i] = arr[j];
                                arr[j] = temp;

                        }
                }
        }
        //if n is even
        if(n%2 == 0 && n!=0)
        {
                medianValue = 0.5*(arr[n/2] + arr[n/2-1]);
        }
        //if n is odd
        else
        {
                medianValue = arr[n/2];
        }
                        
}


//threadFunction5 to determine the standard deviation value
void *threadFunction5()
{
        int sum;
        float meanValue;
        sum=0;
        standardDeviationValue=arr[1];

        //find the mean value
        for(int i=0;i<n;i++)
                sum+=arr[i];
        meanValue = sum/n;

        //find the standard deviation
        for (int i = 0; i <n; i++) 
        {
                standardDeviationValue += pow(arr[i] - meanValue, 2);
        }
        standardDeviationValue = sqrt(standardDeviationValue / n);
        
}

int main()
{
    //Getting the inputs from the command line
    printf("Enter the number of numbers: ");
    scanf("%d", &n);
    printf("Enter the numbers: \n");
        for (int i = 0; i < n; i++)
        {
                scanf("%d", &arr[i]);
        }

    //Declaring the thread ids which are of type pthread_t
    pthread_t threadId1;
    pthread_t threadId2;
    pthread_t threadId3;
    pthread_t threadId4;
    pthread_t threadId5;
    
    int returnValue;
    //creating independent threads as required
    if( (returnValue=pthread_create( &threadId1, NULL, &threadFunction1, NULL)) )
        {
        printf("Thread creation failed: %d\n", returnValue);
        }
    if( (returnValue=pthread_create(&threadId2,NULL,&threadFunction2,NULL)) )
        {
        printf("Thread creation failed: %d\n", returnValue);
        }

    if( (returnValue=pthread_create( &threadId3, NULL, &threadFunction3, NULL)) )
        {
        printf("Thread creation failed: %d\n", returnValue);
        }
    if( (returnValue=pthread_create( &threadId4, NULL, &threadFunction4, NULL)) )
        {
        printf("Thread creation failed: %d\n", returnValue);
        }
    if( (returnValue=pthread_create( &threadId5, NULL, &threadFunction5, NULL)) )
        {
        printf("Thread creation failed: %d\n", returnValue);
        }


        /* 
        Wait till the threads are complete before main thread continues.  
        */
        pthread_join(threadId1,NULL);
        pthread_join(threadId2,NULL);
        pthread_join(threadId3,NULL);
        pthread_join(threadId4,NULL);
        pthread_join(threadId5,NULL);
        
    /*
    The parent or main thread will print the required statistical values after the threads have been joined.
    */
    printf("\nThe average value is %f\n",avgValue);
    printf("The minimum value is %d\n",minValue);
    printf("The maximum value is %d\n",maxValue);
    printf("The median value is %d\n",medianValue);
    printf("The standard deviation is %d\n",standardDeviationValue);
        
return 0;

}