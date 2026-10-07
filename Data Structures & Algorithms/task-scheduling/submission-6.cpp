class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // Count frequencies of each task
        vector<int> freq(26, 0);
        int maxf = 0;
        for (char t : tasks) {
            freq[t - 'A']++;
            maxf = max(maxf, freq[t - 'A']);
        }

        // Count how many tasks have that maximum frequency
        int maxCount = 0;
        for (int f : freq) {
            if (f == maxf) {
                maxCount++;
            }
        }

        // Apply the Grid Trick formula
        int ans = (maxf - 1) * (n + 1) + maxCount;

        // If the grid isn't big enough to hold all tasks, no idling is needed;
        // the total time is just the number of tasks.
        return max(ans, (int)tasks.size());
    }
};
