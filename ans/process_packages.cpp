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
typedef   long long int               ll;

//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
using namespace std;


struct Request
{
    Request(int arrival_time, int process_time) : arrival_time(arrival_time),
                                                  process_time(process_time)
    {
    }

    int arrival_time;
    int process_time;
};

struct Response
{
    Response(bool dropped, int start_time) : dropped(dropped),
                                             start_time(start_time)
    {
    }

    bool dropped;
    int start_time;
};

class Buffer
{
public:
    Buffer(int size) : size_(size),
                       finish_time_()
    {
    }

    Response Process(const Request &request)
    {

        while (finish_time_.empty() == false && finish_time_.front() <= request.arrival_time)
        {
            finish_time_.pop_front();
        }

        if (finish_time_.empty())
        {
            finish_time_.emplace_back(request.arrival_time + request.process_time);
            return Response(false, request.arrival_time);
        }
        if (finish_time_.size() >= size_)
            return Response(true, -1);
        finish_time_.emplace_back(max(request.arrival_time, finish_time_.back()) + request.process_time);
        return Response(false, finish_time_.back() - request.process_time);
    }

private:
    int size_;
    std::deque<int> finish_time_;
};

std::vector<Request> ReadRequests()
{
    std::vector<Request> requests;
    int count;
    std::cin >> count;
    for (int i = 0; i < count; ++i)
    {
        int arrival_time, process_time;
        std::cin >> arrival_time >> process_time;
        requests.push_back(Request(arrival_time, process_time));
    }
    return requests;
}

std::vector<Response> ProcessRequests(const std::vector<Request> &requests, Buffer *buffer)
{
    std::vector<Response> responses;
    for (int i = 0; i < requests.size(); ++i)
        responses.push_back(buffer->Process(requests[i]));
    return responses;
}

void PrintResponses(const std::vector<Response> &responses)
{
    for (int i = 0; i < responses.size(); ++i)
        std::cout << (responses[i].dropped ? -1 : responses[i].start_time) << std::endl;
}

int main()
{
    int size;
    std::cin >> size;
    std::vector<Request> requests = ReadRequests();

    Buffer buffer(size);
    std::vector<Response> responses = ProcessRequests(requests, &buffer);

    PrintResponses(responses);
    return 0;
}
