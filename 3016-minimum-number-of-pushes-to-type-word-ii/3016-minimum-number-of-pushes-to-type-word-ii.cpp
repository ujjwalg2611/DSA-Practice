class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        vector<int> hash(26, 0);
        for(int i=0;i<n;i++){
            hash[word[i] - 'a']++;
        }

        sort(hash.begin(), hash.end(), [&](int a, int b){
            return a > b;
        });

        int pushes = 0;
        for(int i=0;i<26;i++){
            if(hash[i] == 0) continue;
            if(i < 8) {
                pushes += hash[i];
            } else if(i < 16) {
                pushes += 2 * hash[i];
            } else if(i < 24) {
                pushes += 3 * hash[i];
            } else {
                pushes += 4 * hash[i];
            }
        }

        return pushes;



    }
};