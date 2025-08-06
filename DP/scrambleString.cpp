class Solution {
public:
unordered_map<string,bool> mp;

bool solve(string a,string b){
    // base condn.
    if(a.compare(b)==0)
    return true;
  
    if(a.length()<=1)
     return false;
     
     string key=a+""+b;
     if(mp.find(key)!=mp.end())
     return mp[key];

     int n=a.length();
     bool flag=false;

     for(int i=1;i<=n-1;i++){
          bool condition1= (solve(a.substr(0,i),b.substr(n-i,i))&& solve(a.substr(i,n-i),b.substr(0,n-i)));
          bool condition2= (solve(a.substr(0,i),b.substr(0,i))&& solve(a.substr(i,n-i),b.substr(i,n-i)));
          if (condition1||condition2)
          {
           flag =true;
           break;
          }
      }
     
     return mp[key]=flag;
     
}

    bool isScramble(string s1, string s2) {


    if(s1==""||s2=="")
    return false;

    else if(s1.length()==s2.length())
      return solve(s1,s2);
     else      
      return false;
    }
};