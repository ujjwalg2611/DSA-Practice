class Solution {
public:
    struct Node {
        int pre = 0;
        int suf = 0;
        int mx = 0;
        char lc = 0;
        char rc = 0;
    };

    int n;
    vector<Node> tree;

    Node merge(Node a, Node b, int len1, int len2) {
        Node c;

        c.lc = a.lc;
        c.rc = b.rc;

        c.pre = a.pre;
        if (a.pre == len1 && a.rc == b.lc) {
            c.pre = a.pre + b.pre;
        }

        c.suf = b.suf;
        if (b.suf == len2 && a.rc == b.lc) {
            c.suf = b.suf + a.suf;
        }

        c.mx = max(a.mx, b.mx);

        if (a.rc == b.lc) {
            c.mx = max(c.mx, a.suf + b.pre);
        }

        return c;
    }

    void build(int i, int l, int r, string &s) {
        if (l == r) {
            tree[i] = {1, 1, 1, s[l], s[l]};
            return;
        }

        int m = l + (r - l) / 2;

        build(2 * i + 1, l, m, s);
        build(2 * i + 2, m + 1, r, s);

        tree[i] = merge(tree[2 * i + 1],tree[2 * i + 2],m-l+1,r-m);
    }

    void update(int i, int l, int r, int pos, char ch) {
        if (l == r) {
            tree[i] = {1, 1, 1, ch, ch};
            return;
        }

        int m = l + (r - l) / 2;

        if (pos <= m) {
            update(2 * i + 1, l, m, pos, ch);
        } else {
            update(2 * i + 2, m + 1, r, pos, ch);
        }

        tree[i] = merge(tree[2 * i + 1],tree[2 * i + 2],m-l+1,r-m);
    }

    vector<int> longestRepeating(string s,string queryCharacters,vector<int>& queryIndices) {
        n = s.size();
        tree.assign(4 * n, Node());

        build(0, 0, n - 1, s);

        int k = queryIndices.size();
        vector<int> ans(k);

        for (int i = 0; i < k; i++) {
            update(0, 0, n - 1, queryIndices[i], queryCharacters[i]);
            ans[i] = tree[0].mx;
        }

        return ans;
    }
};