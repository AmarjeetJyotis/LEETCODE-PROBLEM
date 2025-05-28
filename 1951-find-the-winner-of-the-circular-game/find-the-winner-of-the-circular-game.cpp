class Solution {
public:

    int findTheWinner(int n, int k) {

        // queue<int> q;

        // // insert 1->n in queue
        // for (int i = 1; i<=n; i++) {
        //     q.push(i);
        // }

        // // traverse and remove after k element including curr element 
        // // till single element found
        // int gap = 1;
        // while (q.size() > 1) {
        //     // remove curr front element
        //     if (gap == k) {
        //         // cout << i << "->" << q.front() << "->";
        //         q.pop();
        //         // reset gap
        //         gap = 1;
        //         cout << gap << " ";
        //     }
        //     // to traverse
        //     else {
        //         q.push(q.front());
        //         q.pop();
        //         gap++;
        //     }
        // }

        // return q.front();



        // // can also be written
        // queue<int> q;

        // // insert 1->n in queue
        // for (int i = 1; i<=n; i++) {
        //     q.push(i);
        // }

        // // traverse and remove after k element including curr element 
        // // till single element found
        // int gap = 1;
        // while (q.size() > 1) {
        //     // stimulate the game
        //     for (int i = 1; i<k; i++) {
        //         // no eliminated yet
        //         q.push(q.front());
        //         q.pop();
        //     }
        //     // eliminate kth player
        //     q.pop();
        // }

        // return q.front();


        // 02 approach - tc = o(n), sc = o(1)
        int ans = 0;
        for (int i = 1; i<=n; i++) {
            ans = (ans+k)%i;
        }
        return ans+1;
    }
};