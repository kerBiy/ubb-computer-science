#include <fstream>
#include <iostream>
#include <map>
#include <queue>
#include <sstream>
#include <vector>

struct Node {
    char chr;
    int freq;
    Node *left, *right;

    Node(char chr, int freq, Node* left = nullptr, Node* right = nullptr)
        : chr(chr), freq(freq), left(left), right(right) {}
};

struct compare {
    bool operator()(Node* a, Node* b) {
        if (a->freq == b->freq) return a->chr > b->chr;
        return a->freq > b->freq;
    }
};

void encode(Node* root, const std::string& str,
            std::map<char, std::string>& huffman) {
    if (root == nullptr) return;

    if (!root->left && !root->right) {
        huffman[root->chr] = str;
    }

    encode(root->left, str + "0", huffman);
    encode(root->right, str + "1", huffman);
}

void Huffman(const std::string& text) {
    std::map<char, int> freq_chr;
    for (char character : text) {
        freq_chr[character]++;
    }

    std::priority_queue<Node*, std::vector<Node*>, compare> pq;

    for (auto pair : freq_chr) {
        pq.push(new Node(pair.first, pair.second));
    }

    while (pq.size() != 1) {
        Node* left = pq.top();
        pq.pop();
        Node* right = pq.top();
        pq.pop();

        int sum = left->freq + right->freq;
        pq.push(new Node('\0', sum, left, right));
    }

    Node* root = pq.top();

    std::map<char, std::string> huffman;
    encode(root, "", huffman);

    std::cout << freq_chr.size() << '\n';
    for (auto pair : freq_chr) {
        std::cout << pair.first << " " << pair.second << '\n';
    }

    std::string new_string;
    for (char ch : text) {
        new_string += huffman[ch];
    }
    std::cout << new_string << '\n';
}

int main() {
    std::ifstream in("input.txt");

    std::stringstream ss;
    ss << in.rdbuf();
    std::string text = ss.str();
    in.close();

    Huffman(text);

    return 0;
}