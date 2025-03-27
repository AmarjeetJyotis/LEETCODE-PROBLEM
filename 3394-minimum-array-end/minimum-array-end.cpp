
class Solution {
public:
// can say doing some optimization, will not effet overall time complexity
int findMostSignificantBit(const bitset<64>& temp) {
    for (int i = 63; i >= 0; i--) {
        if (temp[i] == 1) {
            return i;  
        }
    }
    return -1;  
}
    long long minEnd(int n, int x) {
        bitset<64> binary(x); // conversion
        bitset<64> temp(n - 1);
           
           long long bits=findMostSignificantBit(temp);
        long long cnt = 0;
// iterating all 64 bits
        for (int i = 0; i < binary.size()&&cnt<=bits; i++) {
            if (binary[i] == 0) {
                binary[i] = temp[cnt];
                cnt++;
            }
        }

        return binary.to_ullong();  
    }
};