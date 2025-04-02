class Solution {
public:
    int balancedString(string s) {
        int q=0, w=0, e=0, r=0;
        
      //counting initial count of all characters in array
      
        for(int i=0;i<s.size();i++)
        {
          if(s[i]=='Q')q++;     
          if(s[i]=='W')w++;  
          if(s[i]=='E')e++;
          if(s[i]=='R')r++; 
        }
      
      //required size
      
        int req=s.size()/4;
      
      //base condition
      if(q==req&&w==req&&e==req&&r==req)return 0;  
       
      //2 pointer approach, i slow and j fast variable
        int i=0;
     //qc, wc, ec and rc denote the count of the characters outside the region of pointers
      int qc=q, wc=w, ec=e, rc=r, minlength=1000001;
        
      for(int j=0;j<s.size()+1;j++)
        { 
         
        //if the count of characters outside the region of 2 pointer is 
        //less than or equal to required limit, this is a valid case
        if(qc<=req&&wc<=req&&ec<=req&&rc<=req)
          {
            if(j-i<=minlength)minlength=j-i;
         //will be moving i ahead so increment the count of character 
          //on which i was sitting because from now it will be outside the region
            if(s[i]=='Q')qc++;     
            if(s[i]=='W')wc++;  
            if(s[i]=='E')ec++;
            if(s[i]=='R')rc++;
          //j-- to retain the position of second pointer to find a smaller
          //length in same valid case
          
            i++;j--;
        }
        else
        if(j<s.size()){
        
        //j is going to increase and character on which j sits currently will be 
        //removed from outside and included into the region between pointers
            if(s[j]=='Q')qc--;     
            if(s[j]=='W')wc--;  
            if(s[j]=='E')ec--;
            if(s[j]=='R')rc--;
          }

        }
        return minlength;
    }
};