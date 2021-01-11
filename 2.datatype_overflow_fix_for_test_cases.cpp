#include <iostream>
#include <vector>
using namespace std;

/*
In this Solution, we fixed the Dat type Overlfow problem for the Previous Solution
*/

long long int MaxPairwiseProduct(vector<int> &numbers)
{
    long long int result = 0;
    int n = numbers.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if ((long long int)numbers[i] * numbers[j] > result)
                result = (long long int)numbers[i] * numbers[j];
        }
    }
    return result;
}

int main()
{
    int n;
    cin >> n;
    vector<int> numbers(n);
    for (int i = 0; i < n; i++)
    {
        cin >> numbers[i];
    }
    long long int result = MaxPairwiseProduct(numbers);
    cout << result << endl;
    return 0;
}