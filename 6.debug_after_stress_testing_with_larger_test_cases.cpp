/*
In general, it is a program that generates random tests in an infinite loop, and for each test, it launches your solution on this test and an alternative solution on the same test and compares the results. This alternative solution you also have to invent and implement yourself, but it is usually easy, because it can be any simple, slow, brute force solution, or just any other solution that you can come up with. The only requirement is that it should be significantly different from your main solution. */

//we have to find a way where borth of aour shows diffrent solutions so that we can understand that which one of them is correct and which is wrong

#include <iostream>
#include <vector>

/*
We have included the cstdlib library to have the ability to generate numbers and test them for our solution whether they are giving correct or wrong solution
*/
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
//The below function is the previous MaxPairwiseProduct function that we used and had time complexity issues.
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
        //if ((numbers[j] != numbers[max_index1]) && ((max_index2 == -1) || (numbers[j] > numbers[max_index2])))
        //in this line the main problem occured, so we commented this line wrote the correct statement below.

        if ((j != max_index1) && ((max_index2 == -1) || (numbers[j] > numbers[max_index2])))
            //so, in this statement, we compared the indexes of j and max_index1 rather than comaparing the values at those indexes just like the previous commented protion.
            max_index2 = j;
    }
    return ((long long)(numbers[max_index1]) * numbers[max_index2]);
}

int main()
{
    /*
    The below portion is for the sake of stress testing,
    At first we will generate the test cases.
    The first line of the test case has the number, which is the cardinality of the numbers in the next line.
    The next will be the numbers which will be tested for both the functions -> MaxPairwiseProduct & MaxPairwiseProductFast

    So, we start with a while loop and generate random number starting with 2
    Next, we'll take a vector a and generate random number in it using the push_back function.
    Next, we'll print all the numbers that was generated for the sake of the running purpose.
    Afterwards, we will run both the functions,
    Two results will be generated from the two functions, we will compare them, if they are same, then it is fine,
    but if they are different then it will be problem for us to look and the stress test will be fruitful.
    */

    while (true)
    {
        int n = rand() % 1000 + 2;
        cout << n << endl;
        vector<int> a;
        for (int i = 0; i < n; i++)
        {
            a.push_back(rand() % 100000);
            cout << a[i] << ' ';
        }
        cout << endl;
        long long int res1 = MaxPairwiseProduct(a);
        long long int res2 = MaxPairwiseProductFast(a);

        if (res1 != res2)
        {
            cout << "Wrong Answer: " << endl
                 << "For MaxPairwiseProduct Function, the output is: " << res1 << endl
                 << "For MaxPairwiseProdcutFast, the output is: " << res2 << endl;
            /*
                After running the program, we find that 
                11
                4 18 18 2 4 5 5 1 7 1 11
                Wrong Answer:
                For MaxPairwiseProduct Function, the output is: 324
                For MaxPairwiseProdcutFast, the output is: 198

                So, in this test case, the MaxPairwiseProdcut function runs successfully but the problem occurs with the MaxPairwisefast fucntion where it ignores the second 18 and goes with multiplying with the 11. It happens because in the code section of the max_index2, we compared the number not to be same instead of the indexes, so we need to fine tune that protion adn the program will be okay.
                 */
            break;
        }
        else
        {
            cout << "OK" << endl;
        }
    }
    int n;
    cin >> n;
    vector<int> numbers(n);
    return 0;
}
