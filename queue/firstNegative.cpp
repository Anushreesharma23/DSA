vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) {
        deque<long long int>dq;
        vector<long long>ans;
        int negative = -1;
        
        //process  for first window
        for(int i =0; i<K; i++){
            if(A[i]<0){
                dq.push_back(i);
            }
        }
        //push answer for the first window
        if(dq.size()>0){
            ans.push_back(A[dq.front()]);
        }
        else{
            ans.push_back(0);
        }
        
        //for pocessing the rest of the wondows
        for(int i = K; i<N; i++){
            if(!dq.empty()&& (i-dq.front())>=K){
                dq.pop_front();
            }
            if(A[i]<0){
                dq.push_back(i);
            }
            if(dq.size()>0){
                ans.push_back(A[dq.front()]);
            }
            else{
                ans.push_back(0);
            }
        }
        return ans;
 }