class node {
public:
    char data;
    bool end;
    unordered_map<char, node*> child;
    node(char c) {
        this->data = c;
        end = false;
    }
    void maketerminal() { this->end = true; }
};

class Trie {
public:
    node* root;
    Trie() { root = new node('\0'); }
    void insert(string word) {
        node* temp = root;
        for (char& c : word) {
            if (temp->child.find(c) == temp->child.end()) {
                node* n = new node(c);
                temp->child[c] = n;
                temp = n;
            } else {
                temp = temp->child[c];
            }
        }
        temp->end = true;
    }

    bool search(string word) {
        node* temp = root;
        for (char& c : word) {
            if (temp->child.find(c) == temp->child.end()) {
                return false;
            } else {
                temp = temp->child[c];
            }
        }
        return temp->end;
    }
    bool startsWith(string prefix) {
        node* temp = root;
        for (char& c : prefix) {
            if (temp->child.find(c) == temp->child.end()) {
                return false;
            } else {
                temp = temp->child[c];
            }
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
