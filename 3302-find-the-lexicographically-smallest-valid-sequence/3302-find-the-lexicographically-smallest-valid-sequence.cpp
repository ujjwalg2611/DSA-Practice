class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        
        vector<int> right(m, -1);

        int i = n - 1;

        for (int j=m-1;j>=0;j--) {
            while (i >= 0 && word1[i] != word2[j])
                i--;

            if (i < 0) break;

            right[j] = i;
            i--;
        }

        vector<int> ans;

        i = 0;
        bool used = false;

        for (int j=0;j<m;j++) {
            while (i < n) {
                if (word1[i] == word2[j]) {
                    ans.push_back(i);
                    i++;
                    break;
                }
                if (!used &&
                    (j == m-1 || right[j+1] > i)) {

                    ans.push_back(i);
                    used = true;
                    i++;
                    break;
                }

                i++;
            }

            if (ans.size() != j+1) return {};
        }

        return ans;
    }
};