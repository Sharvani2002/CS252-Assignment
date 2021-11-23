#include <iostream>
#include <cmath>
#include <vector>
#include <cstring>
//Implementing threads using the thread library which got included in C++11
#include <thread>
//Include this if you are using windows
// #include "mingw.thread.h"

//Declaring the global variables
int g_n;
std::vector<int> g_primeNumbers;

//StartProgram method to get the input from the user
void StartProgram ()
{
  std::cout << "Enter the value of the number: ";
  std::cin >> g_n;
}


//FindPrimes method to find the prime numbers using Sieve of eratosthenes method
void
FindPrimes ()
{
  //Numbers less than or equal to 1 are not considered as prime
  if (g_n <= 1)
    {
      return;
    }
  //Initialize all the numbers to be prime
  bool m_prime[g_n + 1];
  std::memset (m_prime, true, sizeof(m_prime));

  for (int m_i = 2; m_i * m_i <= g_n; m_i++)
    {
      if (m_prime[m_i] == true)
        {

          /*
          Mark all multiples of the prime number (i) greater than or equal to the square of it as false.
          As numbers which are multiple of the prime number(i) and are less than i^2 are already marked.
          */
          for (int m_k = m_i * m_i; m_k <= g_n; m_k += m_i)
            {
              m_prime[m_k] = false;
            }
        }
    }
  //push all the prime numbers to the vector
  for (int m_i = 2; m_i <= g_n; m_i++)
    {
      if (m_prime[m_i])
        {
          g_primeNumbers.emplace_back (m_i);
        }

    }


}


int
main ()
{
  //Create a thread to get the input from the user
  std::thread thread1 (StartProgram);
  //Create a thread to wait for the thread thread1 to complete
  thread1.join ();
  //Create a thread to find the prime numbers using seive of eratosthenes method.
  std::thread thread2 (FindPrimes);
  //Wait for the thread thread2 to complete
  thread2.join ();
  //Print all the prime numbers
  std::cout << "The prime numbers less than or equal to " << g_n << " are:\n";
  for (unsigned int i = 0; i < g_primeNumbers.size (); i++)
    {
      std::cout << g_primeNumbers[i] << ' ';
    }
  std::cout << '\n';

  return 0;
}
