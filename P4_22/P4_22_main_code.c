#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


int arr[1000], i;
int n;


/*
 average, minimum, and maximum
 values will be stored globally
*/
float avgValue;
int minValue;
int maxValue;

//thread1 for calculating average
void * thread1 ()
{
  int sum = 0;
  for (i = 1; i <= n; i++)
    {
      sum = sum + arr[i];
    }
  avgValue = sum / n;

}
//thread2 for calculating minimum value
void * thread2 ()
{


  minValue = arr[1];
  for (int i = 1; i < n; i++)
    {
      if (minValue > arr[i])
        {
          minValue = arr[i];
        }
    }


}
//thread3 for calculating maximum value
void * thread3 ()
{

  maxValue = arr[1];
  for (int i = 1; i <= n; i++)
    {
      if (maxValue < arr[i])
        {
          maxValue = arr[i];
        }
    }

}
int main (int argc, char *argv[])
{
  int count = 0;
  /*
   a series of numbers on the command line is passing
  */
  for (int i = 1; i < argc; i++)
    {
      arr[i] =  atoi (argv[i]);
      count++;
    }
  n = count;
  printf ("%d command line arguement are passed \n", count);
  for (int i = 1; i <= n; i++)
    {
      printf ("%d\t",arr[i]);
    }


  printf ("\n\n");
  int t,i;
  //three objectof worker threads are t1 ,t2 and t3
  pthread_t t1;
  pthread_t t2;
  pthread_t t3;

  //creating threads
  t = pthread_create (&t1,NULL,&thread1,NULL);
  pthread_join (t1,NULL);

  t = pthread_create (&t2,NULL,&thread2,NULL);
  pthread_join (t2,NULL);

  t = pthread_create (&t3,NULL,&thread3,NULL);
  pthread_join (t3,NULL);


  /*main is the parent thread.
  the parent thread will output the values
  once the workers have exited.
  */
  printf ("The average value is %f",avgValue);
  printf ("\nThe Minimum  value is %d",minValue);
  printf ("\nThe Maximum  value is %d",maxValue);

  return 0;

}