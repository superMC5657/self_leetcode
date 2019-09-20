/* -*- coding: utf-8 -*-
  !@time: 2019-09-19 01:03
  !@author: superMC @email: 18758266469@163.com
  !@fileName: 133_clone.cpp
 */

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
#include <environment.h>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <deque>
#include <string>
#include <sstream>


class Solution {
    unordered_map<Node *, Node *> map;

    void dfs(Node *node) {
        if (map.find(node) != map.end()) return;
        map[node] = new Node(node->val);
        for (Node *neighbor : node->neighbors) {
            dfs(neighbor);
            map[node]->neighbors.push_back(map[neighbor]);
        }
    }

public:
    Node *cloneGraph(Node *node) {
        if (!node) return node;
        dfs(node);
        return map[node];
    }
};


void printUndirectedGraph(Node *node) {
    std::ostringstream out;
    std::unordered_map<int, std::unordered_set<int>> map{{0, std::unordered_set<int>()}};
    std::deque<Node *> cache;
    cache.push_back(node);
    do {
        std::sort(cache.begin(), cache.end(), [](Node *n1, Node *n2) {
            return n1->val < n2->val;
        });
        Node *node = cache.front();
        cache.pop_front();
        out << node->val;
        auto found = map.find(node->val);
        for (Node *neighbor : node->neighbors) {
            if (map.find(neighbor->val) == map.end()) cache.push_back(neighbor);
            if (found != map.end()) {
                std::unordered_set<int> &exist = found->second;
                if (exist.find(neighbor->val) == exist.end()) out << "," << neighbor->val;
            }
            map[neighbor->val].emplace(node->val);
        }
        out << "#";
    } while (!cache.empty());
    std::string out_str = out.str();
    std::cout << out_str.substr(0, out_str.size() - 1) << std::endl;
}

int fun() {
    Solution s;

    Node node0(0);
    Node node1(1);
    Node node2(2);
    Node node3(3);
    Node node4(4);
    Node node5(5);
    node0.neighbors.push_back(&node1);
    node0.neighbors.push_back(&node5);
    node1.neighbors.push_back(&node0);
    node1.neighbors.push_back(&node2);
    node1.neighbors.push_back(&node5);
    node2.neighbors.push_back(&node1);
    node2.neighbors.push_back(&node3);
    node3.neighbors.push_back(&node2);
    node3.neighbors.push_back(&node4);
    node3.neighbors.push_back(&node4);
    node4.neighbors.push_back(&node3);
    node4.neighbors.push_back(&node3);
    node4.neighbors.push_back(&node5);
    node4.neighbors.push_back(&node5);
    node5.neighbors.push_back(&node0);
    node5.neighbors.push_back(&node1);
    node5.neighbors.push_back(&node4);
    node5.neighbors.push_back(&node4);

    printUndirectedGraph(&node0);
    Node *node = s.cloneGraph(&node0);
    printUndirectedGraph(node);
    return 0;
}