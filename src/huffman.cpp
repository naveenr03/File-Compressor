// src/huffman.cpp
#include "huffman.h"
#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <queue>
#include <vector>
#include <bitset>

// Node structure for the Huffman tree
struct Node {
    char character;
    int frequency;
    Node* left;
    Node* right;

    Node(char ch, int freq) : character(ch), frequency(freq), left(nullptr), right(nullptr) {}
};

// Comparator for the priority queue
struct Compare {
    bool operator()(Node* left, Node* right) {
        return left->frequency > right->frequency; // Min-heap
    }
};

// Function to generate the Huffman codes
void generateCodes(Node* root, const std::string& str, std::unordered_map<char, std::string>& huffmanCodes) {
    if (!root) return;

    if (root->left == nullptr && root->right == nullptr) {
        huffmanCodes[root->character] = str;
    }

    generateCodes(root->left, str + "0", huffmanCodes);
    generateCodes(root->right, str + "1", huffmanCodes);
}

// Function to compress the input file
void Huffman::compress(const std::string& inputFile, const std::string& outputFile) {
    std::cout << "Compressing " << inputFile << " using Huffman encoding to " << outputFile << std::endl;

    // Step 1: Calculate frequency of each character
    std::ifstream inFile(inputFile);
    if (!inFile) {
        std::cerr << "Error: Could not open input file " << inputFile << std::endl;
        return;
    }

    std::unordered_map<char, int> frequency;
    char ch;
    while (inFile.get(ch)) {
        frequency[ch]++;
    }
    inFile.close();

    // Step 2: Create a priority queue to build the Huffman tree
    std::priority_queue<Node*, std::vector<Node*>, Compare> minHeap;
    for (const auto& pair : frequency) {
        minHeap.push(new Node(pair.first, pair.second));
    }

    // Step 3: Build the Huffman tree
    while (minHeap.size() > 1) {
        Node* left = minHeap.top(); minHeap.pop();
        Node* right = minHeap.top(); minHeap.pop();
        Node* newNode = new Node('\0', left->frequency + right->frequency);
        newNode->left = left;
        newNode->right = right;
        minHeap.push(newNode);
    }

    Node* root = minHeap.top();

    // Step 4: Generate Huffman codes
    std::unordered_map<char, std::string> huffmanCodes;
    generateCodes(root, "", huffmanCodes);

    // Step 5: Encode the input file
    std::string encodedString;
    inFile.open(inputFile);
    while (inFile.get(ch)) {
        encodedString += huffmanCodes[ch];
    }
    inFile.close();

    std::cout << "Character frequencies:" << std::endl;
    for (const auto& pair : frequency) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    std::cout << "Huffman Codes:" << std::endl;
    for (const auto& pair : huffmanCodes) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    std::cout << "Encoded string size: " << encodedString.size() << std::endl;

    // Step 6: Write the encoded data to the output file
    std::ofstream outFile(outputFile, std::ios::binary);
    if (outFile.is_open()) {
        // Write the size of the encoded string
        outFile << encodedString.size() << std::endl;
        outFile << encodedString; // Write the encoded string
        outFile.close();
        std::cout << "Output written to " << outputFile << std::endl;
    } else {
        std::cerr << "Error: Could not open output file " << outputFile << std::endl;
    }
}