#include<stdio.h>
#include<stdlib.h>
/*
The below header file has been included to use all the functions of the POSIX or pthreads library.
Note that on Linux, programs that use the Pthreads API should be compiled using cc -pthread.
*/
#include<pthread.h>
#define BUCKETSIZE 50

struct ArgStruct {
    int low;
    int high;
}args;

void *findPrimes(void *arg)
{
    struct ArgStruct* params = (struct ArgStruct *)arg;
    int low = params->low;
    int high = params->high;
    int flag;


    for(int i = low; i<= high; i++)
    {
        flag = 0;
        for(int j=2; j<=high/2; j++)
        {
            if(i % j == 0)
            {
                flag = 1;
                break;
            }
        }
        if(flag != 1)
        {
            printf("%d ", i);
        }
    }

    //free the arguements
}


int main()
{
    int n;
    printf("Enter the value of the number for which all the prime numbers until that number (inclusive) would be printed: ");
    scanf("%d", &n);

    //Passing upto BUCKETSIZE numbers or a bucket of numbers to each thread
    int k;
    int numBuckets;
    numBuckets = n/BUCKETSIZE;
    if(n%BUCKETSIZE !=0)
    {
        numBuckets +=1;
    }
    
    pthread_t threadId[numBuckets];
    struct ArgStruct *arguement = malloc(sizeof(*ArgStruct)*numBuckets);
    int returnValue;

    printf("The prime numbers are:\n");
    k=0;
    while(k < numBuckets-1)
    {
        arguement[k]->low = BUCKETSIZE*k +1;
        arguement[k]->high = BUCKETSIZE*(k+1);

        if( (returnValue=pthread_create( &threadId[k], NULL, &findPrimes, (void *)arguement[k])) )
        {
            printf("Thread creation failed: %d\n", returnValue);
        }

        k++;
    }
    
    //k = numBuckets
    arguement[k]->low = BUCKETSIZE*k +1;
    arguement[k]->high = n;

        if( (returnValue=pthread_create( &threadId[k], NULL, &findPrimes, (void *)arguement[k])) )
        {
            printf("Thread creation failed: %d\n", returnValue);
        }



    k=0;
    while(k < numBuckets)
    {
    pthread_join(threadId[k], NULL);
    }


    return 0;
}