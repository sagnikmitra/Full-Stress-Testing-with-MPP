#include <iostream>
#include <vector>
using namespace std;

/*
Here we use the trick to find the two maximum numbers to avoid the time problems.
So what we do is we do two check. One for each of the maximum numbers.
For the first number,
    we check if its index value is -1 or if it is greater than the index value of that particualr vector, then we assign i to max_index1

For the second number,
    we check two things
    1. it in unequal to the previous max number which has the index max_index1
    2. Then we check if it has the index value -1 or it is greater than the value at max_index2
*/

long long int MaxPairwiseProductFast(const vector<int> &numbers)
{
    long long int result = 0; //long long int is used to take care of large number to be multiplied for result like in millions and billions
    int n = numbers.size();   //This is for the declaration of the n variable, which is the size of the numbers vector declared in the main function below.
    int max_index1 = -1;      //we set it -1 and start the loop from the first index 0
    for (int i = 0; i < n; i++)
    {
        if (max_index1 == -1 || numbers[i] > numbers[max_index1])
            max_index1 = i;
    }
    int max_index2 = -1;
    for (int j = 0; j < n; j++)
    {
        if ((numbers[j] != numbers[max_index1]) && ((max_index2 == -1) || (numbers[j] > numbers[max_index2])))
            max_index2 = j;
    }
    return ((long long)(numbers[max_index1]) * numbers[max_index2]);
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
    long long int result = MaxPairwiseProductFast(numbers);
    cout << result << endl;
    return 0;
}