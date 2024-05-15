#include <fstream>
#include <iostream>
#include <map>
#include <queue>

struct Node {
    char chr;
    int freq;
    Node *left, *right;

    Node(char chr = '\0', int freq = 0, Node* left = nullptr,
         Node* right = nullptr)
        : chr(chr), freq(freq), left(left), right(right) {}
};

struct compare {
    bool operator()(Node* a, Node* b) {
        if (a->freq == b->freq) return a->chr > b->chr;
        return a->freq > b->freq;
    }
};

Node* buildHuffmanTree(const std::map<char, int>& frequencies) {
    std::priority_queue<Node*, std::vector<Node*>, compare> pq;
    for (auto& p : frequencies) {
        pq.push(new Node(p.first, p.second));
    }

    while (pq.size() > 1) {
        Node* left = pq.top();
        pq.pop();
        Node* right = pq.top();
        pq.pop();
        Node* merged = new Node('\0', left->freq + right->freq, left, right);
        pq.push(merged);
    }

    return pq.top();
}

std::string decodeHuffman(Node* root, const std::string& encodedStr) {
    std::string decodedText;
    Node* current = root;
    for (char bit : encodedStr) {
        if (bit == '0')
            current = current->left;
        else
            current = current->right;

        if (!current->left && !current->right) {
            decodedText += current->chr;
            current = root;
        }
    }
    return decodedText;
}

int main() {
    std::ifstream in("input.txt");

    int N;
    in >> N;

    std::map<char, int> frequencies;
    char ch;
    int freq;
    for (int i = 0; i < N; ++i) {
        in >> ch >> freq;
        frequencies[ch] = freq;
    }

    std::string encodedString;
    in >> encodedString;
    in.close();

    Node* root = buildHuffmanTree(frequencies);
    std::string decodedString = decodeHuffman(root, encodedString);
    std::cout << decodedString << '\n';

    return 0;
}
