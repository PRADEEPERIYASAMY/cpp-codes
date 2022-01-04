// dp
// int superUgly(int n,int primes[],int k){
//     vector<int> nextMultiple (primes,primes+k);
//     int mulptiple[k]={0};
//     set<int> ugly;
//     ugly.insert(1);
//     while(ugly.size() != n){
//         int nex_ugly = *min_element(nextMultiple.begin(),nextMultiple.end());
//         ugly.insert(nex_ugly);
//         for (int i = 0; i < k; i++) {
//             if(nex_ugly == nextMultiple[i]){
//                 mulptiple[i]++;
//                 set<int>::iterator it = ugly.begin();
//                 for (int j = 1; j <= mulptiple[i]; j++) it++;
//                 nextMultiple[i] = primes[i] * (*it);
//                 break;
//             }
//         }
//     }
//     set<int>::iterator it = ugly.end();
//     it--;
//     return *it;
// }

int superUgly(int n,int a[],int k){
    if(n<= 0) return -1;
    if(n == 1) return 1;
    priority_queue<int,vector<int>,greater<int>> pq;
    for (int i = 0; i < k; i++) pq.push(a[i]);
    int count = 1,no;
    while(count<n){
        no = pq.top();
        pq.pop();
        if(no != pq.top()){ // avoid repetitiveness
            count++;
            for (int i = 0; i < k; i++) pq.push(no*a[i]);
        }
    }
    return no;
}


