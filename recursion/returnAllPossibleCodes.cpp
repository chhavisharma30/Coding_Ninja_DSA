#include<iostream>
using namespace std;

int stoi(char s){
    int i = s -'0';
    return i;
}

char itos(int i){
    char s = 'a'+i-1;
    return s;
}

int getcodes(string ip,string op[]){
    if(ip.empty()){
        op[0]="";
        return 1;
    }
    if(ip.length()==1){
        op[0]=itos(stoi(ip[0]));
        return 1;
    }
    string op1[1000];
    string op2[1000];

    int size2=0;

    int size1 = getcodes(ip.substr(1),op1);

    if(ip.size()>1){
    if(stoi(ip[0])*10 + stoi(ip[1])>=10 && stoi(ip[0])*10 + stoi(ip[1])<27){
        size2=getcodes(ip.substr(2),op2);
    }
    }

    int k=0;

    for(int i=0;i<size1;i++){
        op[k++]=itos(stoi(ip[0]))+op1[i];
    }
    for(int i=0;i<size2;i++){
        op[k++]=itos(stoi(ip[0])*10 +stoi(ip[1]))+op2[i];
    }

    return k;
}

int main(){
    string s;
    cin>>s;
    string op[1000];
    int count = getcodes(s,op);
    for(int i=0;i<count && i<100000;i++){
        cout<<op[i]<<endl;
    }
}