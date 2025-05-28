class Solution {
public:
    long long int mx=9999999999; // as max of s.size()==20 so if any number exceeds mx it will not be valid as we will not be able to make two partitions then, according to the situation given. 
    bool helper(string& s,int i,int j,long long int prev,int n)
    {
       // if we are at the last index then, we have to just check if the (prev-pres)==1.
       // if that condition is true, then it means we got a correct match
        if(j==n-1)
        {
            string str=s.substr(i,j-i+1);
            long long int pres=stoll(str);
            if(prev-pres==1)
                return true;
            return false;
        }
           bool m=false;
           string str=s.substr(i,j-i+1);
           long long int pres=stoll(str); 
           if(pres>mx)
               return false;
            if(prev==-1 || prev-pres==1)
                m=m || helper(s,j+1,j+1,pres,n); // in this step we are calling the function  keeping in mind that we have found the integer till this index and freshly calculating the integer from the next index, that's why passed (j+1,j+1) inside the function. 
            
        m=m || helper(s,i,j+1,prev,n);  // in this step we are calling the function keeping in mind that we will extend the integer to the next index and passing the prev val as it is. 
        
        return m; 
    }
    bool splitString(string s) {
        int n=s.size();
        long long int prev=-1;
        return helper(s,0,0,prev,n);
    }
};