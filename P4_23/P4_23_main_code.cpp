#include <iostream>
#include <cmath>
#include <thread>
#include <vector>
std::vector<int> primes;


void calculatePrimes (int how_many)
{
  if (how_many == 1)
    {
      primes.emplace_back (2);
      return;
    }
  int generated_numbers = 1;
  primes.emplace_back (2);
  int prime_candidate = 3;

  while (generated_numbers < how_many)
    {
      bool is_prime = true;
      for (int i = 3; i <= std::sqrt (prime_candidate); i += 2)
        {
          if (prime_candidate % i == 0)
            {
              is_prime = false;
              break;
            }
        }
      if (is_prime)
        {
          primes.emplace_back (prime_candidate);
          generated_numbers++;
        }
      prime_candidate += 2;
    }



}


int main ()
{
  int how_many_primes;
  std::cout << "Enter the number of primes you wish to generate\n";
  std::cin >> how_many_primes;
  std::thread t1 (calculatePrimes,how_many_primes);
  t1.join ();
  for (unsigned int i = 0; i < primes.size (); i++)
    {
      std::cout << primes[i] << ' ';
      if (i % 10 == 0 && i != 0)
        {
          std::cout << '\n';
        }
    }

  return 0;
}
