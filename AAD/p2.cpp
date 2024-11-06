#include <iostream>
#include <queue>
#include <vector>
#include <memory> // For std::unique_ptr
using namespace std;

class Node
{
public:
    char data;
    int freq;
    Node *left, *right;

    Node(char data, int freq, Node *left = nullptr, Node *right = nullptr)
    {
        this->data = data;
        this->freq = freq;
        this->left = left;
        this->right = right;
    }

    // Destructor to free left and right nodes recursively
    ~Node()
    {
        delete left;
        delete right;
    }
};

// Comparator for the priority queue
struct Compare
{
    bool operator()(Node *a, Node *b)
    {
        return a->freq > b->freq; // Min-heap based on frequency
    }
};

// Recursive function to print Huffman codes
void printCode(Node *head, string code)
{
    if (!head)
        return;

    // If this is a leaf node, print the character and its code
    if (!head->left && !head->right)
    {
        cout << head->data << "  " << code << "  "
             << "Required Bits: " << head->freq * code.length() << endl;
        return;
    }

    // Recur for left and right children
    printCode(head->left, code + '0');
    printCode(head->right, code + '1');
}

int main()
{
    int n;
    cout << "Enter the number of characters: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "The number of characters must be positive." << endl;
        return 1;
    }

    char c;
    int freq;
    priority_queue<Node *, vector<Node *>, Compare> queue;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter the character: ";
        cin >> c;
        cout<< endl;
        cout << "Enter the frequency of " << c << ": ";
        cin >> freq;

        if (freq < 0)
        {
            cout << "Frequency cannot be negative." << endl;
            return 1;
        }

        queue.push(new Node(c, freq));
    }

    // Build the Huffman Tree
    while (queue.size() > 1)
    {
        Node *left = queue.top();
        queue.pop();
        Node *right = queue.top();
        queue.pop();

        // Internal node with frequency equal to the sum of the two child nodes
        queue.push(new Node('$', left->freq + right->freq, left, right));
    }

    cout << "\nCharacter Codes:\n";
    printCode(queue.top(), "");

    // Free the memory allocated for the Huffman Tree
    delete queue.top();

    return 0;
}
