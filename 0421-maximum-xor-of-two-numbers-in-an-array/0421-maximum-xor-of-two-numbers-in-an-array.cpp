class Node {
public:
    Node* links[2];  // Since binary: 0 or 1

    Node() {
        links[0] = nullptr;
        links[1] = nullptr;
    }

    bool containsKey(int bit) {
        return links[bit] != nullptr;
    }

    void put(int bit, Node* node) {
        links[bit] = node;
    }

    Node* get(int bit) {
        return links[bit];
    }
};

class Trie {
public:
    Node* root;

    Trie() {
        root = new Node();
    }

    void insert(int num) {
        Node* node = root;
        for (int i = 31; i >= 0; i--) {  // 32-bit representation
            int bit = (num >> i) & 1;
            if (!node->containsKey(bit)) {
                node->put(bit, new Node());
            }
            node = node->get(bit);
        }
    }

    int getMaxXOR(int num) {
        Node* node = root;
        int maxXOR = 0;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            int opp = 1 - bit;
            if (node->containsKey(opp)) {
                maxXOR |= (1 << i);
                node = node->get(opp);
            } else {
                node = node->get(bit);
            }
        }
        return maxXOR;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie trie;
        for (int num : nums) {
            trie.insert(num);
        }

        int maxResult = 0;
        for (int num : nums) {
            maxResult = max(maxResult, trie.getMaxXOR(num));
        }

        return maxResult;
    }
};
