class SegTree {
public:
    int n;
    vector<int> seg;

    SegTree(vector<int> &arr) {
        n = arr.size();
        seg.assign(4 * max(1, n), 0);
        if (n) build(1, 0, n - 1, arr);
    }

    void build(int idx, int l, int r, vector<int> &arr) {
        if (l == r) {
            seg[idx] = arr[l];
            return;
        }

        int mid = (l + r) / 2;

        build(idx * 2, l, mid, arr);
        build(idx * 2 + 1, mid + 1, r, arr);

        seg[idx] = max(seg[idx * 2], seg[idx * 2 + 1]);
    }

    int query(int idx, int l, int r, int ql, int qr) {
        if (ql > r || qr < l) return INT_MIN;

        if (ql <= l && r <= qr)
            return seg[idx];

        int mid = (l + r) / 2;

        return max(query(idx * 2, l, mid, ql, qr),
                   query(idx * 2 + 1, mid + 1, r, ql, qr));
    }

    int query(int l, int r) {
        if (n == 0 || l > r) return 0;
        return query(1, 0, n - 1, l, r);
    }
};

class Solution {
public:
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {

        int active = count(s.begin(), s.end(), '1');

        vector<int> blockStart, blockEnd, blockSize;

        int n = s.size();

        for (int i = 0; i < n;) {

            if (s[i] == '1') {
                i++;
                continue;
            }

            int j = i;

            while (j < n && s[j] == '0')
                j++;

            blockStart.push_back(i);
            blockEnd.push_back(j - 1);
            blockSize.push_back(j - i);

            i = j;
        }

        int m = blockStart.size();

        if (m < 2)
            return vector<int>(queries.size(), active);

        vector<int> pairSum(m - 1);

        for (int i = 0; i < m - 1; i++)
            pairSum[i] = blockSize[i] + blockSize[i + 1];

        SegTree st(pairSum);

        vector<int> ans;

        for (auto &q : queries) {

            int l = q[0];
            int r = q[1];

            int low =
                lower_bound(blockEnd.begin(), blockEnd.end(), l) - blockEnd.begin();

            int high =
                upper_bound(blockStart.begin(), blockStart.end(), r) -
                blockStart.begin() - 1;

            int best = 0;

            if (low < high) {

                int firstLen =
                    blockEnd[low] - max(blockStart[low], l) + 1;

                int lastLen =
                    min(blockEnd[high], r) - blockStart[high] + 1;

                if (high - low == 1) {

                    best = firstLen + lastLen;

                } else {

                    int pair1 = firstLen + blockSize[low + 1];

                    int pair2 = blockSize[high - 1] + lastLen;

                    int pair3 = st.query(low + 1, high - 2);

                    best = max({pair1, pair2, pair3});
                }
            }

            ans.push_back(active + best);
        }

        return ans;
    }
};