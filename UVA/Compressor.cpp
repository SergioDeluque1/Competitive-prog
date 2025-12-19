#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include <unordered_map>
#include <bitset>
#include <sstream>
#include <string>

// Node structure for the Huffman Tree
struct Node {
    char ch;
    unsigned freq;
    Node* left;
    Node* right;

    Node(char c, unsigned frequency) : ch(c), freq(frequency), left(nullptr), right(nullptr) {}
    Node(Node* l, Node* r) : ch(0), freq(l->freq + r->freq), left(l), right(r) {}

    // Comparator for priority queue to build the tree using min-heap
    struct Compare {
        bool operator()(const Node* lhs, const Node* rhs) const {
            return lhs->freq > rhs->freq;
        }
    };
};

// Recursive function to generate Huffman codes
void generateHuffmanCodes(Node* root, const std::string& code, std::unordered_map<char, std::string>& huffmanCodes) {
    if (!root) return;
    
    // If leaf node, store the code
    if (!root->left && !root->right) {
        huffmanCodes[root->ch] = code;
    }

    // Recur for left and right subtrees
    generateHuffmanCodes(root->left, code + "0", huffmanCodes);
    generateHuffmanCodes(root->right, code + "1", huffmanCodes);
}

// Function to build the Huffman tree from the character frequencies
Node* buildHuffmanTree(const std::unordered_map<char, unsigned>& freqMap) {
    // Create a priority queue to store nodes of the tree
    std::priority_queue<Node*, std::vector<Node*>, Node::Compare> pq;

    // Insert all characters and their frequencies as nodes into the priority queue
    for (const auto& pair : freqMap) {
        pq.push(new Node(pair.first, pair.second));
    }

    // Combine the nodes until only one node (the root) remains
    while (pq.size() > 1) {
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();

        // Create a new internal node with combined frequency
        Node* parent = new Node(left, right);
        pq.push(parent);
    }

    // The last remaining node is the root of the Huffman Tree
    return pq.top();
}

// Function to compress a file
void compressFile(const std::string& inputFileName, const std::string& outputFileName) {
    // Read the input file
    std::ifstream inputFile(inputFileName, std::ios::in);
    if (!inputFile) {
        std::cerr << "Error opening file: " << inputFileName << std::endl;
        return;
    }

    // Frequency map to store frequency of each character
    std::unordered_map<char, unsigned> freqMap;
    char ch;
    while (inputFile.get(ch)) {
        freqMap[ch]++;
    }

    // Build the Huffman tree based on character frequencies
    Node* root = buildHuffmanTree(freqMap);

    // Generate the Huffman codes from the tree
    std::unordered_map<char, std::string> huffmanCodes;
    generateHuffmanCodes(root, "", huffmanCodes);

    // Close the input file
    inputFile.close();

    // Now, write the compressed data to an output file
    std::ofstream outputFile(outputFileName, std::ios::out | std::ios::binary);
    if (!outputFile) {
        std::cerr << "Error opening output file: " << outputFileName << std::endl;
        return;
    }

    // Write the frequency map to the output file (for decompression)
    for (const auto& pair : freqMap) {
        outputFile.put(pair.first);  // Write the character
        outputFile.write(reinterpret_cast<const char*>(&pair.second), sizeof(pair.second));  // Write the frequency
    }

    // Write the actual compressed data (encoded as Huffman codes)
    inputFile.open(inputFileName, std::ios::in);
    std::ostringstream encodedStream;
    while (inputFile.get(ch)) {
        encodedStream << huffmanCodes[ch];
    }

    // Convert the binary string into actual bits and write them
    std::string encodedStr = encodedStream.str();
    size_t padding = 8 - encodedStr.size() % 8;  // Add padding to make the length a multiple of 8
    for (size_t i = 0; i < padding; ++i) {
        encodedStr = "0" + encodedStr;
    }

    // Write padding info to the output file
    outputFile.put(static_cast<char>(padding));

    // Write the actual bits
    for (size_t i = 0; i < encodedStr.size(); i += 8) {
        std::bitset<8> byte(encodedStr.substr(i, 8));
        outputFile.put(static_cast<unsigned char>(byte.to_ulong()));
    }

    // Close the output file
    outputFile.close();

    std::cout << "File compressed successfully!" << std::endl;
}

// Main function
int main() {
    std::string inputFileName = "input.txt";
    std::string outputFileName = "compressed.bin";
    
    compressFile(inputFileName, outputFileName);

    return 0;
}

