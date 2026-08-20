class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        sort(reservedSeats.begin(), reservedSeats.end());

        long long total = 2LL * n;

        int prev_row = -1;

        bool b1 = true;
        bool b2 = true;
        bool b3 = true;

        for (auto &r : reservedSeats) {
            int row = r[0];
            int seat = r[1];

            if (seat == 1 || seat == 10)
                continue;

            if (prev_row != -1 && row != prev_row) {

                int families;

                if (b1 && b3)
                    families++;
                else if (b1 || b2 || b3)
                    families = 1;
                else 
                    families = 0;

                total -= (2 - families);

                b1 = true;
                b2 = true;
                b3 = true;
            }

            prev_row = row;

            if (seat >= 2 && seat <= 5)
                b1 = false;

            if (seat >= 4 && seat <= 7)
                b2 = false;

            if (seat >= 6 && seat <= 9)
                b3 = false;
        }

        if (prev_row != -1) {
            int families;

            if (b1 && b3)
                families++;
            else if (b1 || b2 || b3)
                families = 1;
            else 
                families = 0;

            total -= (2 - families);
        }

        return total;
    }
};