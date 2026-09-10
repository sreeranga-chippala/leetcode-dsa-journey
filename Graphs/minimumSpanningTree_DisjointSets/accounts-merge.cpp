/*
Problem: Accounts Merge

LeetCode:
https://leetcode.com/problems/accounts-merge/

Goal:
Merge accounts that belong to the same person.

Two accounts belong to the same person if they share
at least one email address.

Approach:
Disjoint Set Union (DSU) + Hash Map

Treat every account as a DSU node.

For every email:

1. If the email has not appeared before,
   store:

       email → account index

2. If the email already belongs to another account,
   union the two account indices.

After all accounts are processed:

1. Find the root account for every email.
2. Place each email into the vector of its root.
3. Sort the emails of every merged account.
4. Add the person's name at the beginning.
5. Return all merged accounts.

Key Insight:

The email address is the connection between accounts.

If:

    Account 0 → abc@gmail.com

and:

    Account 2 → abc@gmail.com

then:

    Account 0 and Account 2

must belong to the same person.

The DSU allows this relationship to propagate transitively.

For example:

    Account 0 shares email with Account 1
    Account 1 shares another email with Account 2

Then all three accounts belong to the same component.

PseudoCode : 

Create DSU for all accounts

Create a map:
    email → first account containing that email

For every account:

    For every email:

        If email is seen for the first time:
            store email → account

        Otherwise:
            merge current account
            with the account stored for that email

Create a collection for each DSU root

For every email:

    Find its account root
    Add email to that root's collection

For every root account:

    Sort its emails
    Add the account name
    Add the merged account to the answer

Return merged accounts


Complexity Analysis : 

Time Complexity: O(T * α(N) + S log S)
Space Complexity: O(N + T)

where:
N = number of accounts
T = total number of email occurrences
S = total number of emails
α(N) = inverse Ackermann function, practically constant.
*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class DisjointSet {
public:
    vector<int> parent;

    DisjointSet(int n) {
        // Negative value means root + component size
        parent.resize(n, -1);
    }

    // Find root with path compression
    int find(int node) {

        if(parent[node] < 0) {
            return node;
        }

        return parent[node] = find(parent[node]);
    }

    // Merge two components using union by size
    void unionSet(int a, int b) {

        int parent_a = find(a);
        int parent_b = find(b);

        if(parent_a != parent_b) {

            // Attach smaller component to larger component
            if(parent[parent_a] < parent[parent_b]) {

                int temp = parent[parent_b];

                parent[parent_b] = parent_a;
                parent[parent_a] += temp;
            }
            else {

                int temp = parent[parent_a];

                parent[parent_a] = parent_b;
                parent[parent_b] += temp;
            }
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(
        vector<vector<string>>& accounts) {

        int n = accounts.size();

        // Create DSU for all accounts
        DisjointSet dis_set(n);

        // Map each email to the account where it first appeared
        unordered_map<string, int> mp;

        // Connect accounts sharing an email
        for(int i = 0; i < n; i++) {

            int len = accounts[i].size();

            for(int j = 1; j < len; j++) {

                string email = accounts[i][j];

                // First occurrence of this email
                if(mp.find(email) == mp.end()) {

                    mp.insert({email, i});
                }

                // Email already belongs to another account
                else {

                    dis_set.unionSet(i, mp[email]);
                }
            }
        }

        // Store emails according to their root account
        vector<vector<string>> ans(n);

        // Add account names
        for(int i = 0; i < n; i++) {
            ans[i].push_back(accounts[i][0]);
        }

        // Group every email under its DSU root
        for(auto x : mp) {

            string email = x.first;
            int node = x.second;

            int overallParent = dis_set.find(node);

            ans[overallParent].push_back(email);
        }

        vector<vector<string>> ans2;

        // Keep only root accounts
        for(int i = 0; i < n; i++) {

            if(dis_set.parent[i] < 0) {

                // Emails must be sorted
                sort(ans[i].begin() + 1, ans[i].end());

                ans2.push_back(ans[i]);
            }
        }

        return ans2;
    }
};

int main() {

    vector<vector<string>> accounts = {
        {"John", "johnsmith@mail.com", "john_newyork@mail.com"},
        {"John", "johnsmith@mail.com", "john00@mail.com"},
        {"Mary", "mary@mail.com"},
        {"John", "johnnybravo@mail.com"}
    };

    Solution obj;

    vector<vector<string>> result =
        obj.accountsMerge(accounts);

    cout << "Merged Accounts:" << endl;

    for(auto account : result) {

        for(auto value : account) {
            cout << value << " ";
        }

        cout << endl;
    }

    return 0;
}