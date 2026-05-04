class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        std::unordered_map<string, std::vector<string>> t; 
        std::vector<std::vector<string>> res;

        // if( strs.size() <= 1){
        //     std::vector<std::vector<string>> r;
        //     r.push_back(strs);
        //     return r;
        // }

        for(string& word: strs){
            string sortedWord = word;
            std::sort(sortedWord.begin(), sortedWord.end());
            if(t.contains(sortedWord)){
                t[sortedWord].push_back(word);
            }else{
                t[sortedWord].push_back(word);
            }
        } 

        for(auto& subA: t ){
            res.push_back(subA.second);
        }
        return res;
    }
};
