class Solution {
public:
    int longestString(int x, int y, int z) {
        if(x==y) return 4*x + 2*z;
        else{
            return 4*(min(x,y)) + 2*z + 2; //(aabb...) + (ababab..) + if we have extra aa left so we can add them at last after ab aa....and if we have extra bb left then we will place ababab.. in the beginning and before that we can place bb at the starting. 
        }
    }
};