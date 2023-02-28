/*Given a string S, you need to remove all the duplicates. That means, the output string should contain each character only once. 
The respective order of characters should remain same, as in the input string.
Input format:
The first and only line of input contains a string, that denotes the value of S.

Output format :
The first and only line of output contains the updated string, as described in the task.

Constraints :
0 <= Length of S <= 10^8
Time Limit: 1 sec

Sample Input 1 :
ababacd

Sample Output 1 :
abcd

Sample Input 2 :
abcde

Sample Output 2 :
abcde*/

#include<iostream>
#include<string>
using namespace std;

//node class of buckets
template <typename V>
class MapNode{
    public:
    string key;
    V value;
    MapNode* next;

    //constructor
    MapNode(string key, V value){
        this->key=key;
        this->value=value;
        next=NULL;
    }

    //destructor
    ~MapNode(){
        delete next;
    }
};

//hashmap class
template<typename V>
class ourMap{
    MapNode<V>** buckets;   //array of head pointers to node
    int count;  //to keep count of total no of entries in map
    int numBuckets; //size of array

    public:

        //constructor
        ourMap(){
            count=0;
            numBuckets=5;
            //array initialization
            buckets = new MapNode<V>*[numBuckets]; 
            for(int i=0;i<numBuckets;i++){
                buckets[i]=NULL;
            }
        }

        //destructor
        ~ourMap(){
            for(int i=0;i<numBuckets;i++){
                delete buckets[i];
            }
            delete[] buckets;
        }

        //function to count total entries in hashmap
        int size(){
            return count;
        }

        //function to get value for corresponding key from map
        V getValue(string key){
            int bucketIndex = getBucketIndex(key);
            MapNode<V>* head = buckets[bucketIndex];
            while (head!=NULL)
            {
                if(head->key==key){
                    return head->value;
                }
                head= head->next;
            }
            return 0;
            
        }

    private:
        //function to get hashcode for a key
        int getBucketIndex(string key){
            int hashCode=0;
            int currentCoeff = 1;

            for(int i=key.length();i>=0;i--){
                hashCode+=key[i]*currentCoeff;
                hashCode = hashCode%numBuckets;
                currentCoeff*=37;
                currentCoeff%=numBuckets;
            }

            return hashCode%numBuckets;
        }

        //function for rehashing(more in notes)
        void rehash(){
            MapNode<V>** temp = buckets;    //making a temp pointer pointing to buckets array
            buckets = new MapNode<V>*[2*numBuckets];    //pointing buckets pointer to a new double sized array
            for(int i=0;i<2*numBuckets;i++){
                buckets[i]=NULL;
            }
            int oldBucketCount = numBuckets;
            numBuckets *=2;
            count =0;

            //inserting elements into new array
            for(int i=0;i<oldBucketCount;i++){
                MapNode<V>* head = temp[i];
                while(head!=NULL){
                    string key = head->key;
                    V value = head->value;
                    insert(key,value);
                    head = head->next;
                }
            }

            //deleting previous array
            for(int i=0;i<oldBucketCount;i++){
                delete temp[i];
            }
            delete[] temp;
        }

    public:

        //function to insert a key value in hashmap
        void insert(string key, V value){
            //getting bucket index
            int bucketIndex = getBucketIndex(key);
            MapNode<V>* head = buckets[bucketIndex];
            //to check if this entry already exists in hashmap
            while(head!=NULL){
                if(head->key==key){
                    head->value=value;
                    return;
                }
                head = head->next;
            }

            //inserting new entry
            head = buckets[bucketIndex];
            MapNode<V>* Node = new MapNode<V>(key,value);
            Node->next=head;
            buckets[bucketIndex]=Node;
            count++;
            //checking if rehashing is needed or not
            double loadFactor = (1.0*count)/numBuckets;
            if(loadFactor>0.7){
                rehash();
            }
        }

        //function to remove an entry from map and return corresponding key
        V remove(string key){
            //getting bucket index
            int bucketIndex = getBucketIndex(key);
            MapNode<V>* head = buckets[bucketIndex];
            MapNode<V>* prev = NULL;
            while(head!=NULL){
                if(head->key==key){
                    if(prev==NULL){
                        buckets[bucketIndex]=head->next;
                    }
                    else{
                        prev->next=head->next;
                    }
                V value = head->value;
                head->next=NULL;
                delete head;
                count--;
                return value;
                }
                prev = head;
                head=head->next;
            }
            return 0;
        }
};


//the logic behind solution is to check entry of each character in map, if it doesn't exist then print it, otherwise not
int main(){
    ourMap<int> map;
    string s;
    cout<<"Enter a string: \n";
    cin>>s;
    for(int i=0;i<s.length();i++){
        string c = ""+s[i];
        if(map.getValue(c)==0){
            cout<<s[i];
            map.insert(c,1);
        }
    }
}