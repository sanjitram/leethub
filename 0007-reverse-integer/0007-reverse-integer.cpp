class Solution {
public:
    int reverse(int x) {
        if(x==0)    return 0;
        if(x>0){
        string s=to_string(x);
        ::reverse(s.begin(),s.end());
        if(s.size()<10) return stoi(s);
        else if(s.size()>10)    return 0;

        string ms=to_string(INT_MAX);
        for(int i=0;i<10;i++){
            if(ms[i]<s[i])
                return 0;
            else if(ms[i]>s[i])
                break;
        }
        return stoi(s);
        }
        else{
        string s=to_string(x);
        ::reverse(s.begin(),s.end());
        s=s.substr(0,s.size()-1);
        if(s.size()<10) return ((-1)*stoi(s));
        else if(s.size()>10)    return 0;

        string ms=to_string(INT_MIN);

        for(int i=0;i<10;i++){
            if(ms[i+1]<s[i])
                return 0;
            else if(ms[i+1]>s[i])
                break;
        }
        return ((-1)*stoi(s));
        }
    }
};