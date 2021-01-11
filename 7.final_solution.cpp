#include <iostream>
#include <vector>
using namespace std;

long long int MaxPairwiseProduct(const vector<int> &numbers)
{
    long long int result = 0;
    int n = numbers.size();
    int max_index1 = -1;
    for (int i = 0; i < n; i++)
    {
        if (max_index1 == -1 || (long long int)numbers[i] > numbers[max_index1])
            max_index1 = i;
    }
    int max_index2 = -1;
    for (int j = 0; j < n; j++)
    {
        if ((j != max_index1) && ((max_index2 == -1) || (long long int)numbers[j] > numbers[max_index2]))
            max_index2 = j;
    }
    return ((long long int)numbers[max_index1]) * numbers[max_index2];
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