class LRUCache {
public:
    unordered_map<int,list<pair<int,int>>::iterator> i_map; //i_map_iter={key,iterator of lsit}
    list<pair<int,int>> arr;
    int maxsize;
    LRUCache(int capacity):maxsize(capacity) {
        
    }
    
    int get(int key) {
        auto iterator=i_map.find(key);
        if(iterator==i_map.end())
        {
            return -1;
        }

        arr.splice(arr.begin(),arr,iterator->second);  //jo use hua hai use utha ke aage le aao. 

        return iterator->second->second;
    }
    
    void put(int key, int value) {
        //agar already exist krti hai key to
        auto it=i_map.find(key);
        if(it!=i_map.end())
        {
            arr.splice(arr.begin(),arr,it->second);
            it->second->second=value;
            return;
        }

        //agar capacity full hai or already exist ni krta tb
        if(i_map.size()==maxsize)
        {
            auto del_el=arr.back();
            int key_to_del=del_el.first;
            arr.pop_back();
            i_map.erase(key_to_del);

        }

        arr.emplace_front(key,value);
        i_map[key]=arr.begin();

    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */