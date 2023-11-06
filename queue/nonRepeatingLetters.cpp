//printing the non repeating letters in the string
class Solution{
    public:
string FirstNonRepeating(string A){
    // Code here
    map<char,int>m;
    string ans="";
    queue<char>q;
    for(int i =0; i<A.length(); i++){
        char ch=A[i];
        q.push(ch);
        m[ch]++;
    
        while(!q.empty()){
            if(m[q.front()]>1){
                q.pop();
            }
            else{
                ans.push_back(q.front());
                break;
            }
        }
        if(q.empty()){
            ans.push_back('#');
        }
    }
    return ans;
}
};
		