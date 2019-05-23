#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int GCD(int n, int m)
{
    int index;
    
    if (n < m)
        index = n / 2;
    else
        index = m / 2;
    
    for (;index > 1; index--)
    {
        if (n % index == 0 && m % index == 0)
            return index;
    }
    
    return index;
}

bool isPrime(int n)
{
    int index = sqrt(n);
    
    for (;index > 1; index--)
        if (n % index == 0)
            return false;
    
    return true;
}

void primeFactor(int n)
{
    vector<int> factors;
    int temp = n + 1;
    
    for (;temp > 0; temp--)
        if (n % temp == 0)
            factors.push_back(temp);
    
    cout << "The prime factors of " << n << " are: ";        
    for (int i = factors.size() - 1; i >= 0; i--)
    {
        cout << factors.at(i) << " ";
    }
    cout << endl;
}

int main()
{
    int n, m, gcd;
    
    cout <<"Choose 2 numbers: ";
    cin >> n >> m;
    
    gcd = GCD(n, m);

    if (gcd == 1)
        cout << n << " does not share a greatest common denominator to " << m << endl;
    else
        cout << gcd << " is the greatest common denominator to " << n << " and " << m << endl;
        
    if (isPrime(n))
        cout << n << " is prime" << endl;
    primeFactor(n);
        
    if (isPrime(m))
        cout << n << " is prime" << endl;
    primeFactor(m);
        
    return 0;
}
