class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> cur;
        function<void(int, int)> dfs = [&](int start, int remain) {
            if (remain == 0) { res.push_back(cur); return; }
            if (remain < 0) return;
            for (int i = start; i < candidates.size(); i++) {
                cur.push_back(candidates[i]);
                dfs(i, remain - candidates[i]);
                cur.pop_back();
            }
        };
        dfs(0, target);
        return res;
    }
};