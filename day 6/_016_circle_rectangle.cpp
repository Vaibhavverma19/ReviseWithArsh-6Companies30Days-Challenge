/// ********* o(1) space ******************
class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int closest_X,closest_Y;
        if(x1 >= xCenter)
        {
            closest_X=x1;
        }else if(x2 <= xCenter)
              {
                 closest_X=x2;
              }else{
                  closest_X=xCenter;
              }
        if(y1 >= yCenter)
        {
            closest_Y=y1;
        }else if(y2 <= yCenter)
              {
                 closest_Y=y2;
              }else{
                  closest_Y=yCenter;
              }
        

        int x=closest_X - xCenter;
        int y=closest_Y - yCenter;

        if(x*x + y*y <= radius*radius)
        {
            return true;
        }

        return false;

    }
};