class Solution {
private:
    unordered_set<string> validExpressions;
    int minimumRemoved;

    void reset() {
        validExpressions.clear();
        minimumRemoved = INT_MAX;
    }

    void recurse(string &s, int index, int leftCount, int rightCount,string &expression, int removedCount) {
        if (index == s.length()) {
            if (leftCount == rightCount) {
                if (removedCount <= minimumRemoved) {
                    string possibleAnswer = expression;
                    if (removedCount < minimumRemoved) {
                        validExpressions.clear();
                        minimumRemoved = removedCount;
                    }

                    validExpressions.insert(possibleAnswer);
                }
            }
            return;
        }

        char currentCharacter = s[index];
        int length = expression.length();

        if (currentCharacter != '(' && currentCharacter != ')') {
            expression.push_back(currentCharacter);
            recurse(s, index + 1, leftCount, rightCount,expression, removedCount);
            expression.pop_back();
        } else {
            recurse(s, index + 1, leftCount, rightCount,expression, removedCount + 1);

            expression.push_back(currentCharacter);

            if (currentCharacter == '(') {
                recurse(s, index + 1, leftCount + 1, rightCount,expression, removedCount);
            } else if (rightCount < leftCount) {
                recurse(s, index + 1, leftCount, rightCount + 1,expression, removedCount);
            }

            expression.pop_back();
        }
    }

public:
    vector<string> removeInvalidParentheses(string s) {
        reset();

        string expression;
        recurse(s, 0, 0, 0, expression, 0);

        return vector<string>(validExpressions.begin(), validExpressions.end());
    }
};