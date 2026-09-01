class Solution {
public:
    int minBishopMoves(vector<int>& source, vector<int>& target) {
        if(source[0]+source[1]==target[0]+target[1]  || source[0]-source[1]==target[0]-target[1]){
            return 1;
        }
        int s1=source[0]+source[1];
        int s2=target[0]+target[1];
        if((s1%2!=0 && s2%2==0) ||(s1%2==0 && s2%2!=0)){
            return -1;
        } 

        return 2;
    }
};