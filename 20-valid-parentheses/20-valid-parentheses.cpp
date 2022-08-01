class Solution {
public:
    bool isValid(string x) {
        stack <char> s;
       s.push('#');
       for (int i = 0 ; i < x.length() ; i++){
           if ((x[i] == '(') || (x[i] == '[') || (x[i] == '{')){
               s.push(x[i]);
           }
           else if (x[i] == ')'){
               char ch = s.top();
               if (ch != '(') return false;
               else s.pop();
           }
           else if (x[i] == ']'){
               char ch = s.top();
               if (ch != '[') return false;
               else s.pop();
           }
           else{
               char ch = s.top();
               if (ch != '{') return false;
               else s.pop();
           }
       }
       if (s.top()!='#') return false;
       else return true;
   }
};