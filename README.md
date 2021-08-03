#### std::lower_bound https://en.cppreference.com/w/cpp/algorithm/lower_bound
  - It returns the iterator for which the boolean function 'comp' returns false.
  - If function values are monotonic i.e,[true,true,...,true,false,false,...,false],then it returns the first iterator pointing to false.

  Ex. 
```cpp
  int ind=lower_bound(depth[d].begin(),depth[d].end(),T,
    [](const int& node,int time){
      return tin[node]<time;
    }) -depth[d].begin();
```
```cpp
struct PriceInfo { double price; };
 
int main()
{
    const std::vector<int> data = { 1, 2, 4, 5, 5, 6 };
    for (int i = 0; i < 8; ++i) {
        // Search for first element x such that i ≤ x
        auto lower = std::lower_bound(data.begin(), data.end(), i);
 
        std::cout << i << " ≤ ";
        lower != data.end()
            ? std::cout << *lower << " at index " << std::distance(data.begin(), lower)
            : std::cout << "[not found]";
        std::cout << '\n';
    }
 
    std::vector<PriceInfo> prices = { {100.0}, {101.5}, {102.5}, {102.5}, {107.3} };
    for(double to_find: {102.5, 110.2}) {
      auto prc_info = std::lower_bound(prices.begin(), prices.end(), to_find,
          [](const PriceInfo& info, double value){
              return info.price < value;
          });
 
      prc_info != prices.end()
          ? std::cout << prc_info->price << " at index " << prc_info - prices.begin()
          : std::cout << to_find << " not found";
      std::cout << '\n';
    }
}
/*
  output
  102.5 at index 2
  110.2 not found
*/
```
  - Here, depth[d] is a vector in which all nodes at depth 'd' are sorted according to their 'tin' times.
  - So, 'ind' will be the first index of the node in depth[d] array whose 'tin' time is >= T (Or, the first node for which tin[node]<T gets false).

#### std::upper_bound https://en.cppreference.com/w/cpp/algorithm/upper_bound
  - It returns the iterator for which the boolean function 'comp' returns true.
  - If function values are monotonic i.e,[false,false,...,false,true,true,...,true], then it returns the first iterator pointing to true.
  - Here, vector class element is passed in first argument and comparing value class element in second argument.

  Ex. 
                                                                                                                                       
  
```cpp                                                                                                                              
  int ind=upper_bound(depth[d].begin(),depth[d].end(),T,
    [](int time,const int& node){
      return time<tout[node];
    }) -depth[d].begin();
```
```cpp
struct PriceInfo { double price; };
 
int main()
{
    std::vector<PriceInfo> prices = { {100.0}, {101.5}, {102.5}, {102.5}, {107.3} };
    for(double to_find: {102.5, 110.2}) {
      auto prc_info = std::upper_bound(prices.begin(), prices.end(), to_find,
          [](double value, const PriceInfo& info){
              return value < info.price;
          });
 
      prc_info != prices.end()
          ? std::cout << prc_info->price << " at index " << prc_info - prices.begin()
          : std::cout << to_find << " not found";
      std::cout << '\n';
    }
}
/*
  output
  102.5 at index 2
  110.2 not found
*/
 ```

  - Here, depth[d] is a vector in which all nodes at depth 'd' are sorted according to their 'tout' times.
  - So, 'ind' will be the first index of the node in depth[d] array whose 'tout' time is > T (Or, the first node for which tin[node]>T gets true).
  - Here, vector class element is passed in second argument and comparing value class element in first argument.

See https://codeforces.com/contest/208/submission/124785810 for more info on lower_bound/upper_bound
