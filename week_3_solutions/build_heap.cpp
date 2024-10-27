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

//#include <iostream>
//#include <vector>
//#include <algorithm>

using std::vector;
using std::cin;
using std::cout;
using std::swap;
using std::pair;
using std::make_pair;

class HeapBuilder {
  private:
    vector<int> data;
    vector< pair<int, int> > swaps;

    void WriteResponse() const {
        cout << swaps.size() << "\n";
        for (int i = 0; i < swaps.size(); ++i) {
            cout << swaps[i].first << " " << swaps[i].second << "\n";
        }
    }

    void ReadData() {
        int n;
        cin >> n;
        data.resize(n);
        for (int i = 0; i < n; ++i) {
            cin >> data[i];
        }
    }

    void GenerateSwaps() {
        swaps.clear();
        // The following naive implementation just sorts
        // the given sequence using selection sort algorithm
        // and saves the resulting sequence of swaps.
        // This turns the given array into a heap,
        // but in the worst case gives a quadratic number of swaps.
        //
        // TODO: replace by a more efficient implementation
        for (int i = 0; i < data.size(); ++i)
            for (int j = i + 1; j < data.size(); ++j) {
                if (data[i] > data[j]) {
                    swap(data[i], data[j]);
                    swaps.push_back(make_pair(i, j));
                }
            }
    }

  public:
    void Solve() {
        ReadData();
        GenerateSwaps();
        WriteResponse();
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    HeapBuilder heap_builder;
    heap_builder.Solve();
    return 0;
}
