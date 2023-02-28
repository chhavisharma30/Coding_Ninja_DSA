/*Given an array consisting of positive and negative integers, find the length of the longest subarray whose sum is zero.
Input Format:
The first line of input contains an integer, that denotes the value of the size of the array. Let us denote it with the symbol N.
The following line contains N space separated integers, that denote the value of the elements of the array.

Output Format
The first and only line of output contains length of the longest subarray whose sum is zero.

Constraints:
0 <= N <= 10^8
Time Limit: 1 sec

Sample Input 1:
10 
 95 -97 -387 -435 -5 -70 897 127 23 284

Sample Output 1:
5

Explanation:
The five elements that form the longest subarray that sum up to zero are: -387, -435, -5, -70, 897*/

//Array solution will take O(n^2) time.

#include <iostream>
#include <unordered_map>
using namespace std;
int main()
{
    unordered_map<int, int> map;
    int n;
    cout << "Enter size of array : \n";
    cin >> n;
    int a[n];
    cout << "Enter array elements : \n";
    int sum = 0, length = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
        if (sum == 0)
        {
            if (length < i + 1)
            {
                length = i + 1;
            }
        }
        else
        {
            if (map.count(sum) > 0)
            {
                int start = map[sum];
                if (length < i - start)
                {
                    length = i - start;
                }
            }
            else
            {
                map[sum] = i;
            }
        }
    }
    cout << "Length of longest subset having sum 0 is : " << length << endl;
}