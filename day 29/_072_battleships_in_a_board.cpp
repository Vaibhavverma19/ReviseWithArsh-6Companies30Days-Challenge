class Solution {
public:
    int countBattleships(vector<vector<char>>& A) {
        
        int n = A.size(),m = A[0].size(),count=0;
        
        for( int i=0; i<n; i++ ){
            for( int j=0; j<m; j++ ){
                
                if( A[i][j]=='X' ){ // battleship start only from X, we do need to worry about "."
                    
                    if( i==0 && j==0 ) count++; // for edge case ( 0,0 )
                    
                    else if( i==0 ) {           // for edge case of 0th row 
                        if( A[i][j-1]!='X' )
                            count++;
                    }
                     
                    else if( j==0 ){            // for edge case of 0th column 
                        if( A[i-1][j]!='X' )
                            count++;
                    }
                    
                    // case 1st which marks the starting point of battleship
                    else if( A[i-1][j]=='.' && A[i][j-1]=='.') 
                        count++;
                }
            }
        }
        return count;
    }
};