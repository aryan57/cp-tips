class TrieNode{
public:
	static const int child = 26;
	vector<TrieNode*> next;
	int endcount;
	TrieNode():next(child){
		endcount=0;
		for(int i=0;i<child;i++){
			next[i]=nullptr;
		}
	}
};

class Trie{
public:
	TrieNode* root;
	Trie(){
		root = new TrieNode();
	}

	void insert(const string &s){
		int n = s.size();
		TrieNode* head = root;

		for(const char &c : s){
			if(head->next[c-'a']==nullptr){
				head->next[c-'a'] = new TrieNode();
			}
			head = head->next[c-'a'];
		}

		head->endcount++;
	}

	bool query(const string &s){
		int n = s.size();
		TrieNode* head = root;

		for(const char &c : s){
			if(head->next[c-'a']==nullptr){
				return false;
			}
			head = head->next[c-'a'];
		}

		return head->endcount > 0;
	}
};
