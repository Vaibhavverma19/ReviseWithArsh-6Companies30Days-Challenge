class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> ans;
        multiset<int> pq{0}; //multiset and not set? because we want duplicate values too
        //priority queue isiliye ni liya kuki erase krna tough ho jata usse
        //btw pq is used to store fallback heights ki agr sbse uchi building ki height khatam  ho gyi to vapis kis building pe girenge akr
        vector<pair<int,int>> points;
        //hr point pr jkr usi x loc and height store karenge 
        //entry point ke liye -ve height and exit pt ke liye +ve point to differentiate
        for(auto b:buildings)
        {
            points.push_back({b[0],-b[2]});
            points.push_back({b[1],b[2]});
        } 
        //sort points based on the x- point
        sort(points.begin(),points.end());

        //now traverse each point and play with heights
        int ongoingheight=0;
        for(int i=0;i<points.size();++i)
        {   //extract data
            int currpoint=points[i].first;
            int currheight=points[i].second;
            //check entry point hai ya exit
            if(currheight < 0) //mtlb entry pt
            {
                pq.insert(-currheight);

            }else{
                pq.erase(pq.find(currheight));
            }
            auto maxheight=*pq.rbegin();
            if(ongoingheight!=maxheight)
            {
                ongoingheight=maxheight;
                ans.push_back({currpoint,ongoingheight});
            }
        }

        return ans;
    }
};