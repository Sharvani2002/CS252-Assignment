#include <iostream>
#include <cmath> 
#include <vector>
#include <cstring>
//Implementing threads using the thread library
#include <thread>
//Include this if you are using windows
// #include "mingw.thread.h"

int n;
std::vector<int> primeNumbers;

void startProgram()
{
    std::cout << "Enter the value of the number for which all the prime numbers until that number (inclusive) would be printed: ";
    std::cin >> n;
}


//find the prime numbers using Sieve of eratosthenes method
void findPrimes()
{
    if(n <= 1) 
    {
        return;
    }
    
    bool prime[n + 1];
    std::memset(prime, true, sizeof(prime));
 
    for (int i = 2; i*i <= n; i++)
    {
        if (prime[i] == true)
        {
        
            /*
            Mark all multiples of the prime number (i) greater than or equal to the square of it as false.
            As numbers which are multiple of the prime number(i) and are less than i^2 are already marked.
            */
            for (int k = i*i; k <= n; k += i)
                prime[k] = false;
        }
    }
    //push all the prime numbers to the vector
    for(int i = 2; i<=n; i++)
    {
        if(prime[i])
        {
            primeNumbers.emplace_back(i);
        }
        
    }


}


int main() {
    std::thread t1(startProgram);
    t1.join();
    std::thread t2(findPrimes);
    t2.join();
    for(unsigned int i = 0; i < primeNumbers.size(); i++) {
        std::cout << primeNumbers[i] << ' ';
        if(i%20==0 && i!= 0)
        {
            std::cout << '\n';
        }
    }

    return 0;
}
