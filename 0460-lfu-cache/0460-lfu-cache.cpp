#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int key, val, freq;
    Node* prev;
    Node* next;

    Node(int _key, int _val) {
        key = _key;
        val = _val;
        freq = 1;
        prev = next = nullptr;
    }
};

class List {
public:
    Node* head;
    Node* tail;

    List() {
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    void addFront(Node* node) {
        Node* temp = head->next;
        head->next = node;
        node->prev = head;
        node->next = temp;
        temp->prev = node;
    }

    void removeNode(Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    bool isEmpty() {
        return head->next == tail;
    }
};

class LFUCache {
private:
    unordered_map<int, Node*> keyNode;      // key -> node
    unordered_map<int, List*> freqList;     // freq -> DLL
    int capacity;
    int minFreq;

    void updateFreq(Node* node) {
        int freq = node->freq;
        freqList[freq]->removeNode(node);

        // Remove the list if it’s empty and update minFreq
        if (freq == minFreq && freqList[freq]->isEmpty()) {
            minFreq++;
        }

        node->freq++;
        int newFreq = node->freq;

        if (freqList.find(newFreq) == freqList.end()) {
            freqList[newFreq] = new List();
        }
        freqList[newFreq]->addFront(node);
    }

public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        minFreq = 0;
    }

    int get(int key) {
        if (keyNode.find(key) == keyNode.end()) {
            return -1;
        }

        Node* node = keyNode[key];
        updateFreq(node);
        return node->val;
    }

    void put(int key, int value) {
        if (capacity == 0) return;

        if (keyNode.find(key) != keyNode.end()) {
            Node* node = keyNode[key];
            node->val = value;
            updateFreq(node);
        } else {
            if (keyNode.size() == capacity) {
                List* list = freqList[minFreq];
                Node* nodeToRemove = list->tail->prev;
                list->removeNode(nodeToRemove);
                keyNode.erase(nodeToRemove->key);
            }

            Node* newNode = new Node(key, value);
            minFreq = 1;

            if (freqList.find(minFreq) == freqList.end()) {
                freqList[minFreq] = new List();
            }

            freqList[minFreq]->addFront(newNode);
            keyNode[key] = newNode;
        }
    }
};
