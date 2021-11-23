#include <stdio.h>
#include <stdlib.h>
/*
The below header file has been included to use all the functions of the POSIX or pthreads library.
Note that on Linux, programs that use the Pthreads API should be compiled using cc -pthread.
*/
#include <pthread.h>
//Defining the size of each part or bucket
#define BUCKET_SIZE 50

//Defining structure to pass the arguments of th function FindPrimes to the pthread_create method
struct ArgStruct
{
  int low;
  int high;
} Args;

//FindPrimes method to find the prime numbers in different buckets
void*
FindPrimes (void *arg)
{
  struct ArgStruct* m_params = (struct ArgStruct *)arg;
  int m_low = m_params->low;
  int m_high = m_params->high;
  int m_flag;


  for (int m_i = m_low; m_i <= m_high; m_i++)
    {
      m_flag = 0;
      for (int m_j = 1; m_j <= m_i / 2; m_j++)
        {

          if (m_i % m_j == 0 && m_j != 1)
            {
              m_flag = 1;
              break;
            }
        }
      if (m_flag != 1 && m_i != 1 )
        {
          printf ("%d ", m_i);
        }
    }
}


int
main ()
{
  int n;
  printf ("Enter the value of the number: ");
  scanf ("%d", &n);

  //Passing upto BUCKET_SIZE numbers or a bucket of numbers to each thread
  int k;
  int numBuckets;
  numBuckets = n / BUCKET_SIZE;
  if (n % BUCKET_SIZE != 0)
    {
      numBuckets += 1;
    }

  pthread_t* threadId = (pthread_t *)malloc (sizeof(pthread_t) * numBuckets);
  struct ArgStruct* arguement = (struct ArgStruct *)malloc (sizeof(struct ArgStruct*) * numBuckets);
  int returnValue;

  printf ("The prime numbers less than or equal to %d are:\n", n);

  /*
  Finding the prime numbers in the buckets of size BUCKET_SIZE
  Where the index of the buckets would vary from 0 to numBuckets-1
  Note that all buckets in this range have size BUCKET_SIZE
  */
  k = 0;
  while (k < numBuckets - 1)
    {


      (arguement[k]).low = BUCKET_SIZE * k + 1;
      arguement[k].high = BUCKET_SIZE * (k + 1);

      if ( (returnValue = pthread_create ( &threadId[k], 0, FindPrimes, (void *)&arguement[k])) )
        {
          printf ("Thread creation failed: %d\n", returnValue);
        }

      k++;
    }
  /*
  Finding the prime numbers in last bucket of size n%BUCKET_SIZE
  */
  arguement[k].low = BUCKET_SIZE * k + 1;
  arguement[k].high = n;
  pthread_t threadid_temp = threadId[k];

  if ( (returnValue = pthread_create (&threadId[k], 0, FindPrimes, (void *)&arguement[k])) )
    {
      printf ("Thread creation failed: %d\n", returnValue);
    }

  /*
  The main thread will terminate after the worker threads have been joined.
  */
  k = 0;
  while (k < numBuckets)
    {
      pthread_join (threadId[k], 0);
      k++;
    }
  printf ("\n");

  return 0;
}