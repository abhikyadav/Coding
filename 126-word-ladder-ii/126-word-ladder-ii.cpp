class Solution {
public:
    
    vector<int> neibs(string& a, unordered_map<string, int>& words) {
        vector<int> ret;
        for(char& x:a) {
            char save = x;
            for(char i='a';i<='z';i++) {
                if(i!=save) {
                    x = i;
                    auto it = words.find(a);
                    if(it!=words.end()) ret.push_back(it->second);
                }
            }
            x = save;
        }
        return ret;
    };
    
    struct step {
        string & w;
        vector<step*> prev;
        int i = -1;
        int depth = 0;
        
        step(string & word) : w(word) {};
        step(string & word, int ci, step* p) : w(word), i(ci), prev({p}), depth(p->depth+1) {};
    };
    
public:
    void result(step* curr, vector<string>& path, vector<vector<string>>& ret) {
        path.push_back(curr->w);
        if(empty(curr->prev)) {
            ret.push_back(vector<string>(path.rbegin(), path.rend()));
        } else {
            for(auto p:curr->prev) {
                result(p, path, ret);
            }
        }
        path.pop_back();
    };
    
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();
        vector<bool> seen(n);
        queue<step*> q;
        vector<step*> reached(n);
        
        if(beginWord.back()=='"') beginWord.pop_back();
        if(endWord.back()=='"') endWord.pop_back();

        unordered_map<string, int> words;
        for(int i=0;i<n;i++) {
            words[wordList[i]] = i;
        }
        if(words.count(beginWord)) seen[words[beginWord]] = true;
        if(!words.count(endWord)) return {};
        int endi = words[endWord];
        
        q.push(new step(beginWord));
        while(!empty(q) && !reached[endi]) {
            int s = q.size();
            while(s--) {
                step* curr = q.front();
                q.pop();
                if(curr->i>=0) seen[curr->i] = true;
                
                auto nbs = neibs(curr->w, words);
                for(int i:nbs) {
                    if(seen[i]) continue;
                    if(reached[i]) {
                        if(reached[i]->depth>curr->depth)
                            reached[i]->prev.push_back(curr);
                    } else {
                        reached[i] = new step(wordList[i], i, curr);
                        q.push(reached[i]);
                    }
                }
            }
        }

        vector<vector<string>> ret;
        if(reached[endi]) {
            vector<string> path;
            result(reached[endi], path, ret);
        }
        
        return ret;
    }
};