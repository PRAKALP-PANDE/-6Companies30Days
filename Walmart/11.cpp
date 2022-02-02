class Solution {
public:
    int p=1e9+7;
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        long long maxi=0, sum=0;
        vector<pair<int, int>>v;
        for(int i=0; i<n; i++)
            v.push_back({efficiency[i], speed[i]});
        sort(v.rbegin(), v.rend());
        priority_queue<int, vector<int>, greater<int> >pq;
        for(int i=0; i<v.size(); i++)
        {
            pq.push(v[i].second);
            sum+=v[i].second;
            if(pq.size()>k)
            {
                sum-=pq.top();
                pq.pop();
            }
            maxi=max(maxi, sum*v[i].first);
        }
        return maxi%p;
    }
};