class Solution {
public:
    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
        vector<string> ans;
       

        sort(access_times.begin() , access_times.end());

        unordered_map<string,bool> vis;
        for(int i=0;i+2<access_times.size();i++)
        {
            string name=access_times[i][0];

            if(vis[name]!=true)
            {    
                if(name == access_times[i+2][0])
                {
                    if(stoi(access_times[i+2][1]) - stoi(access_times[i][1])<100)
                    {
                        ans.push_back(name);
                        vis[name]=true;
                    }
                }
            }
        }



        return ans;
    }
};