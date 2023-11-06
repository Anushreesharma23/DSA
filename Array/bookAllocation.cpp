class Solution 
{
    public:
      bool isPossible(int A[], int N, int &mid, int M) {
        int studentCount = 1;
        int pageSum = 0;
        
        for(int i = 0; i < N; i++) {
            if(pageSum + A[i] <= mid) {
                pageSum += A[i];
            }
            else {
                studentCount++;
                if(studentCount > M || A[i] > mid) {
                    return false;
                }
                pageSum = A[i];
            }
            if(studentCount > M) {
                return false;
            }
        }
        return true;
    }

    int findPages(int A[], int N, int M) {
        int s = 0;
        int sum = 0;
        
        for(int i = 0; i < N; i++) {
            sum += A[i];
        }
        int e = sum;
        int ans = -1;

        while(s <= e) {
            int mid = s + (e - s) / 2;
            if(isPossible(A, N, mid, M)) {
                ans = mid;
                e = mid - 1;
            }
            else {
                s = mid + 1;
            }
        }
        return ans;
    }
};