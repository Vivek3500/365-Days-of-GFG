class Solution {
  public:
    int countStrings(string &s) {
        int count=0,l=s.length();
        unordered_map<char,int> u;
        bool flag=false;
        for(char i:s)
        {
            u[i]++;
        }
        for(char ch:s)
        {
            if(u[ch]>1)
            flag=true;
            count+=l-u[ch];
        }
        count/=2;
        if(flag==true)
        count++;
        return count;
    }
};
