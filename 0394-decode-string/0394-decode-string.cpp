class Solution {
public:
    string decodeString(string s) {
        stack<int>numstack;
        stack<string>stringstack;
        int k=0;
        for(auto ch : s){
            if(isdigit(ch)){
                k=(k*10)+(ch-'0');
                continue;
            }
            if(ch=='['){
                numstack.push(k);
                k=0;
                stringstack.push("[");
                continue;
            }
            if(ch!=']'){
                string temp(1,ch);
                stringstack.push(temp);
                continue;
            }
            string temp="";
            while(stringstack.top()!="["){
                temp=stringstack.top()+temp;
                stringstack.pop();
            }
            stringstack.pop();
            string replacement = "";
            int count = numstack.top();
            numstack.pop();
            for(int i=0;i<count;i++){
                replacement +=temp;
            }
            stringstack.push(replacement);
        }
        string result="";
        while(!stringstack.empty()){
            result = stringstack.top()+result;
            stringstack.pop();
        }
        return result;
    }
};