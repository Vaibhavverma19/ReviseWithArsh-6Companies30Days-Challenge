class Solution {
public:
    long long condition(pair<int,int> p1,pair<int,int> p2,pair<int,int> p3)
    {
        long long x1=p1.first;
        long long x2=p2.first;
        long long x3=p3.first;

        long long y1=p1.second;
        long long y2=p2.second;
        long long y3=p3.second;

        return (y3-y2)*(x2-x1) - (y2-y1)*(x3-x2);
    }
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        sort(begin(trees),end(trees));

        vector<vector<int>> result;

        deque<pair<int,int>> lower;
        deque<pair<int,int>> upper;

        //iterate everypoint 
        
        for(auto &point: trees)
        {   int l=lower.size();
            int u=upper.size();
            while( l >=2 && condition(lower[l-2],lower[l-1],{point[0],point[1]}) < 0 )
            {
                cout<<"removing point from lower"<<lower[l-1].first<<","<<lower[l-1].second;
                l--;
                lower.pop_back();
            }
            while( u >=2 && condition(upper[u-2],upper[u-1],{point[0],point[1]}) > 0 )
            {   cout<<"removing point from upper "<<upper[l-1].first<<","<<upper[l-1].second;
                u--;
                upper.pop_back();
            }
            cout<<endl;

            lower.push_back({point[0],point[1]});
            upper.push_back({point[0],point[1]});
        }

        set<pair<int,int>> temp;
        for(auto &point: lower)
        {
            temp.insert(point);
            
        }
        for(auto &point: upper)
        {
            temp.insert(point);

        }

        for(auto &point: temp)
        {
            result.push_back({point.first,point.second});
        }

        return result;

    }
};