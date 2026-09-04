class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        vector<pair<int,ListNode*>> vec;

        for(int i = 0; i < lists.size(); i++) {
            ListNode* cur = lists[i];

            while(cur) {
                vec.push_back({cur->val, cur});
                cur = cur->next;
            }
        }

        if(vec.empty()) return nullptr;

        sort(vec.begin(), vec.end(),
             [](auto &a, auto &b){
                 return a.first < b.first;
             });

        int n = vec.size();

        for(int i = 1; i < n; i++) {
            vec[i-1].second->next = vec[i].second;
        }

        vec[n-1].second->next = nullptr;

        return vec[0].second;
    }
};