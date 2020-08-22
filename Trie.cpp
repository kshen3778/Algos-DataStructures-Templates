
class TrieNode{
    public:

        map<char, TrieNode*> children;
        bool leaf;

        /** Initialize your data structure here. */
        TrieNode() {
            leaf = false;
        }

        bool containsKey(char ch){
            if(children.count(ch) != 0){
                return true;
            }
            return false;
        }

        TrieNode* get(char ch){
            if(children.count(ch) != 0){
                return children[ch];
            }
            return NULL;
        }

        void put(char ch, TrieNode* node){
            children[ch] = node;
        }

        void makeLeaf(){
            leaf = true;
        }

        bool isLeaf(){
            return leaf;
        }
};

class Trie {
public:
    
    TrieNode* root;
    
    Trie(){
        root = new TrieNode();
    }
    
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* node = root;
        for(int i=0; i<word.size(); i++){
            char currentChar = word[i];
            //not found, so branch and create a new node
            if(!node->containsKey(currentChar)){
                node->put(currentChar, new TrieNode());
            }
            //go to the next node for the next character
            node = node->get(currentChar);
        }
        //the last node is set as a leaf
        node->makeLeaf();
    }
    
    //searches for a string and returns the node where it ends
    TrieNode* searchPrefix(string word){
        TrieNode* node = root;
        for(int i = 0; i < word.size(); i++){
            char curLetter = word[i];
            //if match then continue
            if(node->containsKey(curLetter)){
                node = node->get(curLetter);
            } else {
                //if no match
                return NULL;
            }
        }
        
        //entire word was found, node should be a leaf
        return node;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        //do a searchPrefix and then if not NULL and we've arrived at a leaf then we found the word
        TrieNode* node = searchPrefix(word);
        return node != NULL && node->isLeaf();
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        //basically same as searchPrefix
        TrieNode* node = searchPrefix(prefix);
        return node != NULL;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
