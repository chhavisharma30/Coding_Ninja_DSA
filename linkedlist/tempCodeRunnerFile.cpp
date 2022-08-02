 sort(s.begin(),s.end());
    sort(t.begin(),t.end());

    int flag = 0;
    for(int i=0;i<s.size();i++){
        if(s[i]!=t[i]){
            flag =1;
            break;
        }
    }
    if(flag==0){
        cout<<"true"<<endl;
    }
    else{
        cout<<"false"<<endl;
    }