class Solution { 
public: 
    string baseNeg2(int n) { 
        // Special case: if n is 0, return "0"
        if(n == 0) return "0"; 
        
        // Initialize an empty string to store the result
        string res = ""; 
        
        // Repeat division until n becomes 0
        while(n != 0){ 
            // Calculate the remainder when dividing by -2
            int r = n % -2; 
            
            // Divide n by -2
            n /= -2; 
            
            // Adjust the remainder to be in the range [0, 1]
            if(r < 0){ 
                r += 2; 
                n++; // Adjust the quotient when remainder is negative
            } 
            
            // Add the remainder to the result string
            res.push_back(r + '0'); 
        } 
        
        // Reverse the result string to get the correct order
        reverse(res.begin(), res.end()); 
        
        // Return the base -2 representation
        return res; 
    } 
};