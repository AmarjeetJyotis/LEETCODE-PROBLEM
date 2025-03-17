class Solution 
{
    public String frequencySort(String s) 
    {
        StringBuilder sb = new StringBuilder();
        int[] freq = new int[128];
        for(char c : s.toCharArray())
        {
            freq[c-'0']++;
        }

        for(int k = 0; k < s.length(); k++)
        {
            int max = 0;
            int ind = 0;
            for(int j = 0; j < freq.length; j++)
            {
                if(freq[j] != 0 && freq[j] > max)
                {
                    max = freq[j];
                    ind = j;
                }
            }
            for(int i = 0; i < max; i++)
            {
                sb.append((char)('0'+ind));
            }
            freq[ind] = 0;
            k += --max;
        }
        return sb.toString();
    }
}