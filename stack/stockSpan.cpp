/*Afzal has been working with an organization called 'Money Traders' for the past few years. The organization is into the money trading business. His manager assigned him a task. For a given array/list of stock's prices for N days, find the stock's span for each day.
The span of the stock's price today is defined as the maximum number of consecutive days(starting from today and going backwards) for which the price of the stock was less than today's price.
For example, if the price of a stock over a period of 7 days are [100, 80, 60, 70, 60, 75, 85], then the stock spans will be [1, 1, 1, 2, 1, 4, 6].
Explanation:
On the sixth day when the price of the stock was 75, the span came out to be 4, because the last 4 prices(including the current price of 75) were less than the current or the sixth day's price.

Similarly, we can deduce the remaining results.

Afzal has to return an array/list of spans corresponding to each day's stock's price. Help him to achieve the task.
Input Format:
The first line of input contains an integer N, denoting the total number of days.

The second line of input contains the stock prices of each day. A single space will separate them.

Output Format:
The only line of output will print the span for each day's stock price. A single space will separate them.
*/
#include<iostream>
#include<stack>
using namespace std;

//function to check stock span
void stockSpan(int stock[],int days){

    //creating a stack to store index of best price
    stack<int> storage;

    //storing first element index 
    storage.push(0);

    //print first day stock span
    cout<<"1 ";

    
    for(int i=1;i<days;i++){

        //if current day span is less than previous day span then print the differences of their indexes and push current days index into stack
        if(stock[i]<=stock[storage.top()]){
            cout<<(i-storage.top())<<" ";
            storage.push(i);
        }

        //if current day span is greater than previous day span then traverse the stack while array becomes empty or current day span become less
        else{
            while(!storage.empty() && stock[i]>stock[storage.top()]){
                storage.pop();
            }
            if(storage.empty()){
                cout<<i+1<<" ";
            }
            else if(stock[i]<=stock[storage.top()]){
                cout<<(i-storage.top())<<" ";
            }
            storage.push(i);
        }
    }
}

int main(){
    int days;
    cin>>days;
    int stock[days];
    for(int i=0;i<days;i++){
        cin>>stock[i];
    }
    stockSpan(stock,days);
}