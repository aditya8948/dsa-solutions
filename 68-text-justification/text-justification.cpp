class Solution {
public:
    string createLine(int i, int j, int eachSpaceSlot, int extraSpaceSlot, vector<string> & words, int maxWidth){
        string line ;
        
        for(int k = i; k < j; k++){
            line+= words[k];

            if(k == j-1) continue; // it will be last word and no more extra 
            for(int z = 1; z <= eachSpaceSlot; z++) line+= " ";

            if(extraSpaceSlot > 0) {
                line+= " ";
                extraSpaceSlot--;
        }
    }
        while(line.size() < maxWidth) line+= " ";

        return line;
    
}

    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int n = words.size();
        int i = 0;
        while(i < n){
            int letterCount = words[i].size();
            int spaceCount = 0;
            int j = i+1;

            while(j < n && words[j].size() + 1 + letterCount + spaceCount <= maxWidth){
                letterCount+= words[j].size();
                spaceCount++;
                j++;
            }

            int remainingSlot = maxWidth - letterCount;

            int eachSpaceSlot =  spaceCount == 0 ? 0 : remainingSlot / spaceCount;
            int extraSpaceSlot = spaceCount == 0 ? 0 : remainingSlot % spaceCount;

            if(j == n){
                eachSpaceSlot = 1;
                extraSpaceSlot = 0;
            }

            result.push_back(createLine(i, j, eachSpaceSlot, extraSpaceSlot, words , maxWidth));
            
            i = j;
        }
        return result;
    }
};