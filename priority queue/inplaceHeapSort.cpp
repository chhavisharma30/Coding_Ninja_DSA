/*Given an integer array of size n. Sort this array (in decreasing order) using heap sort.
Space complexity should be O(1).
Input Format :
Line 1 : Integer n, Array size
Line 2 : Array elements, separated by space

Output Format :
Array elements after sorting

Constraints :
1 <= n <= 10^6

Sample Input:
6 
2 6 8 5 4 3

Sample Output:
8 6 5 4 3 2*/
#include <iostream>
using namespace std;

void inplaceHeapSort(int pq[], int n)
{
    // Build the heap in input array
    for (int i = 1; i < n; i++)
    {

        // up heapify

        int childIndex = i;
        while (childIndex > 0)
        {
            int parentIndex = (childIndex - 1) / 2;

            if (pq[childIndex] < pq[parentIndex])
            {
                int temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
            }
            else
            {
                break;
            }

            childIndex = parentIndex;
        }
    }

    // remove elements
    int size = n;

    while (size > 1)
    {

        int temp = pq[0];
        pq[0] = pq[size - 1];
        pq[size - 1] = temp;

        size--;

        // down heapify
        int parentIndex = 0;
        int lchildIndex = 2 * parentIndex + 1;
        int rchildIndex = 2 * parentIndex + 2;
        int minIndex = 0;

        while (lchildIndex < size)
        { // if left child index is out of size than right will definitly be out

            int minIndex = parentIndex;
            if (pq[minIndex] > pq[lchildIndex])
            {
                minIndex = lchildIndex;
            }
            if (rchildIndex < size && pq[minIndex] > pq[rchildIndex])
            {
                minIndex = rchildIndex;
            }
            if (minIndex == parentIndex)
            {
                break;
            }
            int temp = pq[minIndex];
            pq[minIndex] = pq[parentIndex];
            pq[parentIndex] = temp;

            parentIndex = minIndex;
            lchildIndex = 2 * parentIndex + 1;
            rchildIndex = 2 * parentIndex + 2;
        }
    }
}

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    inplaceHeapSort(a,n);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}