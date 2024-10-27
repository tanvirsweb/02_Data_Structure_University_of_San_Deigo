#include <iostream>
#include <cmath>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <iomanip>
#include <assert.h>
#include <vector>
#include <cstring>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <set>
#include <complex>
#include <list>
#include <climits>
#include <cctype>
#include <bitset>
#include <numeric>
#include <array>
#include <tuple>
#include <stdexcept>
#include <utility>
#include <functional>
#include <locale>
#define     all(v)            v.begin(),v.end()
#define     mp                     make_pair
#define     pb                     push_back
#define     endl                     '\n'

typedef   long long int               ll;

//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
using namespace std;
void max_sliding_window_naive(vector<int> const & A, int k);


int main() {
    int n = 0;
    cin >> n;

    vector<int> A(n);
    for (size_t i = 0; i < n; ++i)
        cin >> A.at(i);

    int w = 0;
    cin >> w;

    max_sliding_window_naive(A, w);

    return 0;
}

//.............................

void max_sliding_window_naive(vector<int> const & A, int k) {
    deque<int> dq;
    for(int i=0;i<A.size();i++){
        if(!dq.empty() && i-dq.front()==k) dq.pop_front();
        while(!dq.empty() && A[i]>A[dq.back()])
            dq.pop_back();
        dq.emplace_back(i);
        if(i-k+1>=0) cout<<A[dq.front()]<<" ";
    }
    cout<<endl;
    return;
}
