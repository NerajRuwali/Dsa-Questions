class Solution {
    struct Node {
        char left, right;
        int pref, suff, best, len;

        Node() {
            left = right = '#';
            pref = suff = best = len = 0;
        }

        Node(char c) {
            left = right = c;
            pref = suff = best = len = 1;
        }
    };

    vector<Node> tree;

    Node merge(Node a, Node b) {
        if (a.len == 0) return b;
        if (b.len == 0) return a;

        Node res;
        res.len = a.len + b.len;
        res.left = a.left;
        res.right = b.right;

        res.pref = a.pref;
        res.suff = b.suff;
        res.best = max(a.best, b.best);

        if (a.right == b.left) {
            res.best = max(res.best, a.suff + b.pref);

            if (a.pref == a.len)
                res.pref = a.len + b.pref;

            if (b.suff == b.len)
                res.suff = b.len + a.suff;
        }

        return res;
    }

    void build(string &s, int idx, int l, int r) {
        if (l == r) {
            tree[idx] = Node(s[l]);
            return;
        }

        int mid = (l + r) / 2;

        build(s, idx * 2, l, mid);
        build(s, idx * 2 + 1, mid + 1, r);

        tree[idx] = merge(tree[idx * 2], tree[idx * 2 + 1]);
    }

    void update(int idx, int l, int r, int pos, char c) {
        if (l == r) {
            tree[idx] = Node(c);
            return;
        }

        int mid = (l + r) / 2;

        if (pos <= mid)
            update(idx * 2, l, mid, pos, c);
        else
            update(idx * 2 + 1, mid + 1, r, pos, c);

        tree[idx] = merge(tree[idx * 2], tree[idx * 2 + 1]);
    }

public:
    vector<int> longestRepeating(string s, string queryCharacters,
                                 vector<int>& queryIndices) {

        int n = s.size();

        tree.resize(4 * n);

        build(s, 1, 0, n - 1);

        vector<int> ans;

        for (int i = 0; i < queryIndices.size(); i++) {
            update(1, 0, n - 1,
                   queryIndices[i],
                   queryCharacters[i]);

            ans.push_back(tree[1].best);
        }

        return ans;
    }
};