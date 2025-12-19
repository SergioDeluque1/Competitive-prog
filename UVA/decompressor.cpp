#include <iostream>
#include <fstream>
#include <queue>
#include <unordered_map>
#include <bitset>
#include <vector>

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

// Function to build the Huffman tree from the frequency map
Node* buildHuffmanTree(const std::unordered_map<char, unsigned>& freqMap) {
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

// Function to decode the binary stream using the Huffman tree
std::string decodeHuffmanTree(Node* root, std::ifstream& inputFile, size_t bitLength) {
    Node* current = root;
    std::string decodedText = "";
    unsigned char byte;
    size_t bitsRead = 0;

    while (bitsRead < bitLength) {
        inputFile.read(reinterpret_cast<char*>(&byte), 1); // Read one byte (8 bits)
        for (int i = 7; i >= 0; --i) {
            bool bit = (byte >> i) & 1; // Extract the bit (0 or 1)
            if (bit) {
                current = current->right;
            } else {
                current = current->left;
            }

            // If we've reached a leaf node, append the character and reset to the root
            if (!current->left && !current->right) {
                decodedText += current->ch;
                current = root; // Go back to the root of the tree
            }

            ++bitsRead;
            if (bitsRead >= bitLength) {
                break;
            }
        }
    }

    return decodedText;
}

// Function to decompress the binary file
void decompressFile(const std::string& inputFileName, const std::string& outputFileName) {
    std::ifstream inputFile(inputFileName, std::ios::in | std::ios::binary);
    if (!inputFile) {
        std::cerr << "Error opening file: " << inputFileName << std::endl;
        return;
    }

    // Read the frequency table from the input file
    std::unordered_map<char, unsigned> freqMap;
    char ch;
    unsigned freq;
    while (inputFile.read(reinterpret_cast<char*>(&ch), sizeof(ch))) {
        inputFile.read(reinterpret_cast<char*>(&freq), sizeof(freq));
        freqMap[ch] = freq;
    }

    // Rebuild the Huffman tree using the frequency map
    Node* root = buildHuffmanTree(freqMap);

    // Read the padding info (the number of bits of padding added during compression)
    char padding;
    inputFile.read(&padding, 1); // The padding byte

    // Get the total number of bits in the compressed data (excluding padding)
    std::streampos filePosition = inputFile.tellg(); // Get current file position
    size_t bitLength = static_cast<size_t>(filePosition) - sizeof(padding); // Convert streampos to size_t
    bitLength = (bitLength * 8) - static_cast<size_t>(padding); // Adjust bitLength by padding

    // Now, read the binary data and decode it
    std::string decodedText = decodeHuffmanTree(root, inputFile, bitLength);

    // Write the decompressed data to the output file
    std::ofstream outputFile(outputFileName, std::ios::out);
    if (!outputFile) {
        std::cerr << "Error opening output file: " << outputFileName << std::endl;
        return;
    }

    outputFile << decodedText;

    // Clean up the tree
    delete root;

    std::cout << "File decompressed successfully!" << std::endl;
}

// Main function
int main() {
    std::string inputFileName = "compressed.bin";
    std::string outputFileName = "decompressed.txt";

    decompressFile(inputFileName, outputFileName);

    return 0;
}

