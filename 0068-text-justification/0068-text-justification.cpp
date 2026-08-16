class Solution {
public:
string fun(vector<string>& words ,int p  , int i ,int k , int w){
    string ans="";
    if(i!=p){
    int div = (w-k)/(i-p),rem = (w-k)%(i-p);
    for(int j=p;j<i;j++){
        ans+=words[j];ans+=" ";
        for(int h=0;h<div;h++){ans+=" ";}
        if(rem>0){ans+=" ";rem--;}
    }
    }
    ans+=words[i];
    if(i==p){k=w-k;while(k>0){ans+=" ";k--;}}
    return ans;
}
vector<string>ans;
    vector<string> fullJustify(vector<string>& words, int w) {
        int n = words.size();int p=0;int k=0;
        for(int i =0;i<n;i++){
            string s=words[i];
            k+=s.length()+1;
            if(k-1>w){
                string s1 = fun(words,p,i-1,k-s.length()-2,w);
                ans.push_back(s1);
                k=s.length()+1;p=i;
            }
        }
        k=w-k;
        string s1="";
        for(int i=p;i<=n-1 ;i++){s1+=words[i];s1+=" ";}
        s1.pop_back();
        while(k>=0){s1+=" ";k--;}
        ans.push_back(s1);
        return ans;
    }
};