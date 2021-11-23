#include <stdio.h>
#include <stdlib.h>
/*
Note that on Linux, -lm needs to be appended to the end of the gcc command to explicitly link the math library.
*/
#include <math.h>
/*
The below header file has been included to use all the functions of the POSIX or pthreads library.
Note that on Linux, programs that use the Pthreads API should be compiled using cc -pthread.
*/
#include <pthread.h>
// #include <winpthreads.h>
//Defining the maximum limit for the length of the g_array
#define MAX_LIMIT 1000

//Declaring the global variables
int g_array[MAX_LIMIT];
int g_n;
//Various statistical values
float g_averageValue;
int g_maximumValue;
int g_minimumValue;
float g_medianValue;
float g_standardDeviationValue;

//threadFunction1 to determine the average of the numbers
void*
ThreadFunction1 ()
{
  int m_sum = 0;
  for (int m_i = 0; m_i < g_n; m_i++)
    {
      m_sum = m_sum + g_array[m_i];
    }
  g_averageValue = (float)(m_sum) / g_n;

}
//threadFunction2 to determine the maximum value
void*
ThreadFunction2 ()
{

  g_maximumValue = g_array[0];
  for (int m_i = 0; m_i < g_n; m_i++)
    {
      if (g_maximumValue < g_array[m_i])
        {
          g_maximumValue = g_array[m_i];
        }
    }



}
//threadFunction3 to determine the minimum value
void*
ThreadFunction3 ()
{
  g_minimumValue = g_array[0];
  for (int m_i = 0; m_i < g_n; m_i++)
    {
      if (g_minimumValue > g_array[m_i])
        {
          g_minimumValue = g_array[m_i];
        }

    }



}

//threadFunction4 to determine the median value
void*
ThreadFunction4 ()
{
  /*
  The median is calculated as follows.
  If the input size is
  odd: obtain the middle element of sorted data.
  even: obtain the average of the middle two elements in the sorted data.
  */

  //sort the g_array using bubble sort algorithm
  int m_i;
  int m_j;
  int temp;
  g_medianValue = 0.0;
  for (m_i = 0; m_i < g_n; m_i++)
    {
      for (m_j = m_i + 1; m_j < g_n; m_j++)
        {
          if (g_array[m_i] > g_array[m_j])
            {

              temp =  g_array[m_i];
              g_array[m_i] = g_array[m_j];
              g_array[m_j] = temp;

            }
        }
    }
  //if n is even
  if (g_n % 2 == 0 && g_n != 0)
    {
      g_medianValue = 0.5 * (g_array[g_n / 2] + g_array[g_n / 2 - 1]);
    }
  //if n is odd
  else
    {
      g_medianValue = g_array[g_n / 2];
    }

}


//threadFunction5 to determine the standard deviation value
void*
ThreadFunction5 ()
{
  int m_sum;
  float m_meanValue;
  m_sum = 0;
  g_standardDeviationValue = 0;

  //find the mean value
  for (int m_i = 0; m_i < g_n; m_i++)
    {
      m_sum += g_array[m_i];
    }
  m_meanValue = (float)m_sum / g_n;

  //find the standard deviation
  for (int m_i = 0; m_i < g_n; m_i++)
    {
      g_standardDeviationValue += (float)pow ((float)g_array[m_i] - m_meanValue, 2);
    }
  g_standardDeviationValue = (float)sqrt ((float) g_standardDeviationValue / g_n);

}

int
main ()
{
  //Getting the inputs from the command line
  printf ("Enter the number of numbers: ");
  scanf ("%d", &g_n);
  printf ("Enter the numbers: \n");
  for (int m_i = 0; m_i < g_n; m_i++)
    {
      scanf ("%d", &g_array[m_i]);
    }

  //Declaring the thread ids which are of type pthread_t
  pthread_t threadId1;
  pthread_t threadId2;
  pthread_t threadId3;
  pthread_t threadId4;
  pthread_t threadId5;

  int returnValue;
  //creating independent threads as required
  if ( (returnValue = pthread_create ( &threadId1, 0, ThreadFunction1, 0)) )
    {
      printf ("Thread creation failed: %d\n", returnValue);
    }
  if ( (returnValue = pthread_create (&threadId2,0,ThreadFunction2,0)) )
    {
      printf ("Thread creation failed: %d\n", returnValue);
    }

  if ( (returnValue = pthread_create ( &threadId3, 0, ThreadFunction3, 0)) )
    {
      printf ("Thread creation failed: %d\n", returnValue);
    }
  if ( (returnValue = pthread_create ( &threadId4, 0, ThreadFunction4, 0)) )
    {
      printf ("Thread creation failed: %d\n", returnValue);
    }
  if ( (returnValue = pthread_create ( &threadId5, 0, ThreadFunction5, 0)) )
    {
      printf ("Thread creation failed: %d\n", returnValue);
    }


  /*
  Wait till the threads are complete before main thread continues.
  */
  pthread_join (threadId1,0);
  pthread_join (threadId2,0);
  pthread_join (threadId3,0);
  pthread_join (threadId4,0);
  pthread_join (threadId5,0);

  /*
  The parent or main thread will print the required statistical values after the threads have been joined.
  */
  printf ("\nThe average value is %f\n",g_averageValue);
  printf ("The minimum value is %d\n",g_minimumValue);
  printf ("The maximum value is %d\n",g_maximumValue);
  printf ("The median value is %f\n",g_medianValue);
  printf ("The standard deviation is %f\n",g_standardDeviationValue);

  return 0;

}