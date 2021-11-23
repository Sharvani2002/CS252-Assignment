#include<stdio.h>
#include<stdlib.h>
/*
Note that on Linux, -lm needs to be appended to the end of the gcc command to explicitly link the math library.
*/
#include<math.h>
/*
The below header file has been included to use all the functions of the POSIX or pthreads library.
Note that on Linux, programs that use the Pthreads API should be compiled using cc -pthread.
*/
#include <pthread.h>
// #include <winpthreads.h>

//Declaring the global variables
int array[1000];
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
        for(int i = 0; i < n; i++)
                sum = sum + array[i];
        averageValue = (float)(sum)/n;
        
}
//threadFunction2 to determine the maximum value
void *threadFunction2()
{

        maximumValue=array[0];
        for(int i=0;i<n;i++)
        {
                if(maximumValue<array[i])
                {
                        maximumValue=array[i];
                }
        }
        
        

}
//threadFunction3 to determine the minimum value
void *threadFunction3()
{
        minimumValue=array[0];
        for(int i=0;i<n;i++)
                if(minimumValue>array[i])
                        minimumValue=array[i];
        
                        
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

       //sort the arrayay using bubble sort algorithm
       int i;
       int j;
       int temp;
        medianValue = 0.0;
        for (i = 0; i < n; i++) 
        {
                for (j = i + 1; j < n; j++)
                {
                        if (array[i] > array[j]) 
                        {

                                temp =  array[i];
                                array[i] = array[j];
                                array[j] = temp;

                        }
                }
        }
        //if n is even
        if(n%2 == 0 && n!=0)
        {
                medianValue = 0.5*(array[n/2] + array[n/2-1]);
        }
        //if n is odd
        else
        {
                medianValue = array[n/2];
        }
                        
}


//threadFunction5 to determine the standard deviation value
void *threadFunction5()
{
        int sum;
        float meanValue;
        sum=0;
        standardDeviationValue=0;

        //find the mean value
        for(int i=0;i<n;i++)
                sum+=array[i];
        meanValue = (float)sum/n;

        //find the standard deviation
        for (int i = 0; i <n; i++) 
        {
                standardDeviationValue += (float)pow((float)array[i] - meanValue, 2);
        }
        standardDeviationValue = (float)sqrt((float) standardDeviationValue / n);
        
}

int main()
{
    //Getting the inputs from the command line
    printf("Enter the number of numbers: ");
    scanf("%d", &n);
    printf("Enter the numbers: \n");
        for (int i = 0; i < n; i++)
        {
                scanf("%d", &array[i]);
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
    printf("\nThe average value is %f\n",averageValue);
    printf("The minimum value is %d\n",minimumValue);
    printf("The maximum value is %d\n",maximumValue);
    printf("The median value is %f\n",medianValue);
    printf("The standard deviation is %f\n",standardDeviationValue);
        
return 0;

}