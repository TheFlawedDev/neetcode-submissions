class Solution {
public:
    int maxArea(vector<int>& heights) {
        int i = 0; // starting pointer
        int j = heights.size()-1; // ending pointer

        int cM = 0; // max volume the container can hold

        while ( i < j) 
        {
            int hM = std::min(heights[i], heights[j]); // The maximum heigh between both of the pointers
            
            // The current maximum volume the container can hold
            // with the current pointers
            int tM = hM * (j-i) ;

            // update global maximum container value
            if(tM > cM) cM = tM;

            // update the left pointer if its height is smaller than the left
            // or if they're equal
            if(heights[i] <=  heights[j]){
                i++;
            }else{
                j--;
            }

        }
        return cM;
    }
};
