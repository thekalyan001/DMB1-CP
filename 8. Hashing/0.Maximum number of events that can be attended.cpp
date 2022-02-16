//https://practice.geeksforgeeks.org/problems/ea8230731ccb057120bafb351c10c48b2d496125/1#

int maxEvents(int start[], int end[], int N) {
        priority_queue <int, vector<int>, greater<int>> pq;
        vector<pair<int,int>> A(N);
        for(int i=0; i<N; i++)
        {
            A[i].first = start[i];
            A[i].second = end[i];
        }
        sort(A.begin(),A.end());
        // sort all the meeting according to first and then second day
        
        int i = 0, res = 0, d = 0;
        while (pq.size() > 0 || i < N) {
            if (pq.size() == 0)
                d = A[i].first;
                
           /* inserting all the meetings whose starting day is smaller than
           the current day.
           */
            while (i < N && A[i].first <= d)
                pq.push(A[i++].second);
                
            // removing the meeting that we have taken into in our count(cnt)
            pq.pop();
            ++res, ++d;// incrementing the max count & current day
            
            /* removing all the meetings whose ending time is smaller than d
            because those meetings can not be taken into the answer */
            while (pq.size() > 0 && pq.top() < d)
                pq.pop();
        }
        return res;
    }