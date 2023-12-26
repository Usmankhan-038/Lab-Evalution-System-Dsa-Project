
#include<iostream> 
using namespace std;

#define ALPHABET_SIZE (27)
#define CHAR_TO_INDEX(c) ((int)c - (int)'a') 

class Trie
{
private:
    struct TrieNode
    {
        struct TrieNode* children[ALPHABET_SIZE];

        // isWordEnd is true if the node represents 
        // end of a word 
        bool isWordEnd;
    };
    // Returns new trie node (initialized to NULLs) 
    struct TrieNode* getNode(void)
    {
        struct TrieNode* pNode = new TrieNode;
        pNode->isWordEnd = false;

        for (int i = 0; i < ALPHABET_SIZE; i++)
            pNode->children[i] = NULL;

        return pNode;
    };
    struct TrieNode* root;
    // If not present, inserts key into trie.  If the 
    // key is prefix of trie node, just marks leaf node 
    void insert(struct TrieNode* root, const string key)
    {
        struct TrieNode* pCrawl = root;

        for (int level = 0; level < key.length(); level++)
        {
            int index = CHAR_TO_INDEX(key[level]);
            if (!pCrawl->children[index])
                pCrawl->children[index] = getNode();

            pCrawl = pCrawl->children[index];
        }

        // mark last node as leaf 
        pCrawl->isWordEnd = true;
    }
    // Returns 0 if current node has a child 
    // If all children are NULL, return 1. 
    bool isLastNode(struct TrieNode* root)
    {
        for (int i = 0; i < ALPHABET_SIZE; i++)
            if (root->children[i])
                return 0;
        return 1;
    }
    // Recursive function to print auto-suggestions for given 
    // node. 
    void suggestionsRec(struct TrieNode* root, string currPrefix, int& j)
    {
        // found a string in Trie with the given prefix 
        if (root->isWordEnd && j < 5)
        {
            cout << "\t\t\t\t\t";
            for (int i = 0; i < currPrefix.length(); i++)
            {
                if (currPrefix[i] == '{') {
                    cout << " ";
                }
                else {
                    cout << currPrefix[i];
                }
            }
            cout << endl;
            // cout << currPrefix; 
            // cout << endl; 
            j++;
        }

        // All children struct node pointers are NULL 
        if (isLastNode(root))
        {
            return;
        }
        for (int i = 0; i < ALPHABET_SIZE; i++)
        {
            if (root->children[i])
            {
                // append current character to currPrefix string 
                currPrefix.push_back(97 + i);

                // recur over the rest 
                suggestionsRec(root->children[i], currPrefix, j);
                // remove last character 
                currPrefix.pop_back();
            }
        }
    }
    void display(std::string& prefix, struct TrieNode const* node) {
        if (node->isWordEnd)
            cout << prefix << endl;

        for (char index = 0; index < ALPHABET_SIZE; ++index) {
            char next = 'a' + index;
            struct TrieNode const* pChild = node->children[index];
            if (pChild) {
                prefix.push_back(next);
                display(prefix, pChild);
                prefix.pop_back();
            }
        }
    }
public:
    Trie()
    {
        root = getNode();
    }
    void insert(string query)
    {
        insert(root, query);
    }
    // Returns true if key presents in trie, else false 
    bool search(const string key)
    {
        int length = key.length();
        struct TrieNode* pCrawl = root;
        for (int level = 0; level < length; level++)
        {
            int index = CHAR_TO_INDEX(key[level]);

            if (!pCrawl->children[index])
                return false;

            pCrawl = pCrawl->children[index];
        }

        return (pCrawl != NULL && pCrawl->isWordEnd);
    }

    // print suggestions for given query prefix. 
    int printAutoSuggestions(const string query)
    {
        struct TrieNode* pCrawl = root;

        // Check if prefix is present and find the 
        // the node (of last level) with last character 
        // of given string. 
        int level;
        int n = query.length();
        for (level = 0; level < n; level++)
        {
            int index = (query[level] - 'a');

            // no string in the Trie has this prefix 
            if (!pCrawl->children[index])
                return 0;

            pCrawl = pCrawl->children[index];
        }

        // If prefix is present as a word. 
        bool isWord = (pCrawl->isWordEnd == true);

        // If prefix is last node of tree (has no 
        // children) 
        bool isLast = isLastNode(pCrawl);

        // If prefix is present as a word, but 
        // there is no subtree below the last 
        // matching node. 
        if (isWord && isLast)
        {

            for (int i = 0; i < query.length(); i++)
            {
                if (query[i] == '{') {
                    cout << " ";
                }
                else {
                    cout << query[i];
                }
            }
            cout << endl;
            // cout << query << endl; 
            return -1;
        }

        // If there are are nodes below last 
        // matching character. 
        if (!isLast)
        {
            int j = 0;
            string prefix = query;
            suggestionsRec(pCrawl, prefix, j);
            return 1;
        }
    }
    void traverse()
    {
        string str;
        display(str, root);
    }
};