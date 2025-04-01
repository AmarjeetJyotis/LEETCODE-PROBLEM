class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        int n = distance.size();
        int sum=0,suma=0;
        if(start>destination){
            std::swap(start,destination);
        }
        // int g=min(destination,start);
        // int h = max(destination,start);
        for(int i=start;i<destination;i++){
            sum += distance[i];
        }
        cout<<" sum: "<<sum;
        int ts=0;
        for(int i=0;i<n;i++){
            ts += distance[i];
        }
        cout<<"ts: "<<ts;
        suma=abs(ts-sum);
        return min(sum,suma);
       

        
    }
};