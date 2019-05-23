#include <iostream>

using namespace std;

void solveTOH(int n, int src, int mid, int dest)
{
    
    if (n == 1)
        cout << "Move " << n << " from " << src << " to " << dest << endl;
    else
        {
         solveTOH(n-1, src, dest, mid);
         cout << "Move " << n << " from " << src << " to " << dest << endl;
         solveTOH(n-1, mid, src, dest);
        }
}

int main() {
    int n = 0;
    
    cout << "How many discs to solve for? (Must be greater than 0)" << endl;
    cin >> n;
    
    while (n < 1)
    {
        cout << "MUST be greater than 1\n";
        cout << "How many discs to solve for?" << endl;
        cin >> n;
    }
    
    solveTOH(n,1,2,3);
    
    return 0;   
}
