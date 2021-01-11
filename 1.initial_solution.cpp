#include <iostream>
#include <vector>
using namespace std;

/*
For the MaxPairwiseProduct function, we iterated i from 0 to n and j from the immediate increment of i to n,
hence we got to do the comparison between the current result and the multiplication between numbers[i]*numbers[j] and updated the result accordingly.
*/

int MaxPairwiseProduct(vector<int> &numbers)
{
    int result = 0;
    int n = numbers.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (numbers[i] * numbers[j] > result)
                result = numbers[i] * numbers[j];
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
    int result = MaxPairwiseProduct(numbers);
    cout << result << endl;
    return 0;
}