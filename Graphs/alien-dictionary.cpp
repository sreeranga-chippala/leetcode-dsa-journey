/*
Problem: Alien Dictionary

source : 
https://leetcode.com/problems/alien-dictionary/editorial/

Goal:
Given a sorted dictionary of words written in an
unknown alien language, determine the order of
characters in that language.

Approach:
Graph + Topological Sort using Kahn's Algorithm

Important Observation:

The words are already sorted according to the
alien language.

Therefore, compare every pair of adjacent words.

For two words:

    word1
    word2

Find the first position where they differ.

If:

    word1[j] != word2[j]

then:

    word1[j] comes before word2[j]

So create a directed edge:

    word1[j] → word2[j]

Only the FIRST different character matters.

After constructing the graph:

    Character → Node
    Ordering    → Directed Edge

Then perform topological sorting.

Example:

    words = ["baa", "abcd", "abca"]

Compare:

    baa
    abcd

First difference:

    b vs a

Therefore:

    b → a


Compare:

    abcd
    abca

First difference:

    d vs a

Therefore:

    d → a


Topological sort gives a valid character ordering.


Kahn's Algorithm:

1. Calculate indegree of every character.

2. Add all characters with indegree 0
   to the queue.

3. Remove a character from the queue.

4. Add it to the answer.

5. Reduce indegree of its neighbors.

6. If a neighbor's indegree becomes 0,
   push it into the queue.


PseudoCode : 

create adjacency list of k characters


for every adjacent pair of words:

    word1 = current word
    word2 = next word

    find minimum length


    for every position:

        if word1[position]
           != word2[position]:

            add edge:

                word1[position]
                    →
                word2[position]

            break


create indegree array


for every node:

    for every neighbor:

        increase indegree[neighbor]


create queue


for every character:

    if indegree[character] == 0:

        push character


while queue is not empty:

    remove character

    add character to answer


    for every neighbor:

        decrease indegree[neighbor]

        if indegree[neighbor] == 0:

            push neighbor


convert node numbers to characters

return answer


Complexity Analysis : 

Time Complexity: O(N * L + K + E)

N = number of words
L = maximum word length
K = number of characters
E = number of edges

Space Complexity: O(K + E)
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;


// --------------------------------------------------
// Solution Class
// --------------------------------------------------

class Solution {

public:

    // --------------------------------------------------
    // Kahn's Algorithm
    //
    // Performs Topological Sort on the graph.
    // --------------------------------------------------

    vector<int> topological_sort(
        vector<vector<int>> adj
    ) {

        int n = adj.size();


        // Stores the number of incoming edges
        // for every character.
        vector<int> indegree(
            n,
            0
        );


        // Stores the topological ordering.
        vector<int> ans;


        // --------------------------------------------------
        // Calculate indegree of every node.
        // --------------------------------------------------

        for (int i = 0; i < n; i++) {

            for (auto v : adj[i]) {

                indegree[v]++;
            }
        }


        // --------------------------------------------------
        // Add all characters with indegree 0.
        // --------------------------------------------------

        queue<int> q;


        for (int i = 0; i < n; i++) {

            if (indegree[i] == 0) {

                q.push(i);
            }
        }


        // --------------------------------------------------
        // Perform BFS / Kahn's Algorithm.
        // --------------------------------------------------

        while (!q.empty()) {

            // Take a character with no remaining
            // prerequisites.
            int node = q.front();

            q.pop();


            // Add it to the topological ordering.
            ans.push_back(node);


            // Remove the outgoing edges.
            for (auto neighbour : adj[node]) {

                indegree[neighbour]--;


                // All prerequisites of this character
                // have now been satisfied.
                if (indegree[neighbour] == 0) {

                    q.push(neighbour);
                }
            }
        }


        return ans;
    }


    // --------------------------------------------------
    // Find the order of characters in the alien language.
    // --------------------------------------------------

    string sequenceLetters(
        int n,
        int k,
        vector<string>& words
    ) {

        // Create a graph containing k characters.
        //
        // Character 'a' → node 0
        // Character 'b' → node 1
        // Character 'c' → node 2
        // ...
        vector<vector<int>> adj(k);


        // --------------------------------------------------
        // Compare every pair of adjacent words.
        // --------------------------------------------------

        for (int i = 0; i < n - 1; i++) {

            string s1 = words[i];

            string s2 = words[i + 1];


            // Only compare characters that exist
            // in both words.
            int length = min(
                s1.size(),
                s2.size()
            );


            // --------------------------------------------------
            // Find the first different character.
            // --------------------------------------------------

            for (int j = 0; j < length; j++) {

                if (s1[j] != s2[j]) {

                    /*
                        The first different character
                        determines the ordering.

                        s1[j] comes before s2[j].

                        Example:

                            "abc"
                            "abd"

                        c → d
                    */

                    adj[
                        s1[j] - 'a'
                    ].push_back(
                        s2[j] - 'a'
                    );


                    // Only the first difference matters.
                    break;
                }
            }
        }


        // --------------------------------------------------
        // Perform Topological Sort.
        // --------------------------------------------------

        vector<int> v =
            topological_sort(adj);


        // Convert node numbers back into characters.
        string s;


        for (int i : v) {

            s += char(
                i + 'a'
            );
        }


        return s;
    }
};


// --------------------------------------------------
// Main Function
// --------------------------------------------------

int main() {

    /*
        Alien Dictionary:

        Number of words = 5
        Number of characters = 4

        Words:

            baa
            abcd
            abca
            cab
            cad


        Comparisons:

        baa vs abcd

            b vs a

            b → a


        abcd vs abca

            d vs a

            d → a


        abca vs cab

            a vs c

            a → c


        cab vs cad

            b vs d

            b → d


        Graph:

            b → a
            b → d
            d → a
            a → c


        One valid ordering:

            b d a c

        Therefore:

            "bdac"
    */

    int n = 5;

    int k = 4;


    vector<string> words = {

        "baa",
        "abcd",
        "abca",
        "cab",
        "cad"
    };


    Solution obj;


    // Find alien character ordering.
    string result =
        obj.sequenceLetters(
            n,
            k,
            words
        );


    // Print the result.
    cout << "Alien Character Order: "
         << result
         << endl;


    return 0;
}