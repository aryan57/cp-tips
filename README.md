#### std::lower_bound https://en.cppreference.com/w/cpp/algorithm/lower_bound
---
  - It returns the iterator for which the boolean function 'comp' returns false.
  - If function values are monotonic i.e,[true,true,...,true,false,false,...,false],then it returns the first iterator pointing to false.
  - Here, vector class element is passed in first argument and comparing value class element in second argument.

  Ex. 
```cpp
  int ind=lower_bound(depth[d].begin(),depth[d].end(),T,
    [](const int& node,int time){
      return tin[node]<time;
    }) -depth[d].begin();
```
  - Here, depth[d] is a vector in which all nodes at depth 'd' are sorted according to their 'tin' times.
  - So, 'ind' will be the first index of the node in depth[d] array whose 'tin' time is >= T (Or, the first node for which tin[node]<T gets false).

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

#### std::upper_bound https://en.cppreference.com/w/cpp/algorithm/upper_bound
---
  - It returns the iterator for which the boolean function 'comp' returns true.
  - If function values are monotonic i.e,[false,false,...,false,true,true,...,true], then it returns the first iterator pointing to true.
  - Here, vector class element is passed in second argument and comparing value class element in first argument.

  Ex.                                                                                                                       
  
```cpp                                                                                                                              
  int ind=upper_bound(depth[d].begin(),depth[d].end(),T,
    [](int time,const int& node){
      return time<tout[node];
    }) -depth[d].begin();
```
  - Here, depth[d] is a vector in which all nodes at depth 'd' are sorted according to their 'tout' times.
  - So, 'ind' will be the first index of the node in depth[d] array whose 'tout' time is > T (Or, the first node for which tin[node]>T gets true).
 
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

See https://codeforces.com/contest/208/submission/124785810 for more info on lower_bound/upper_bound

#### 0-1 BFS https://codeforces.com/blog/entry/22276
---
```
for all v in vertices:
	dist[v] = inf
dist[source] = 0;
deque d
d.push_front(source)
while d.empty() == false:
	vertex = get front element and pop as in BFS.
	for all edges e of form (vertex , u):
		if travelling e relaxes distance to u:
			relax dist[u]
			if e.weight = 1:
				d.push_back(u)
			else:
				d.push_front(u)
```

- Can we apply the same trick if our edge weights can only be 0 and x (x >= 0) ? (Yes)
- Can we apply the same trick if our edge weights are x and x+1 (x >= 0) ? (No) https://codeforces.com/blog/entry/22276?#comment-268701
- Can we apply the same trick if our edge weights are x and y (x,y >= 0) ? (No)

![162843415495961947](https://user-images.githubusercontent.com/55305876/128636279-17568633-af97-4c08-be72-f8db1ccb6722.png)


- Why dont we use a visited array in 0-1 BFS but use in a normal BFS ? (https://codeforces.com/blog/entry/22276?#comment-610031)

If initially any vertex is added in dequeue as dist[u], then it can be added again in dequeue if relaxing edge makes distance as dis[u]-1(it cannot make less than that). so any vertex cannot be added more than twice.

![tuxpi com 1628434353](https://user-images.githubusercontent.com/55305876/128636283-24272aa8-4969-4e4b-b007-9767462243a1.jpg)

#### Recursive Lambda Function with void return
 We can't use the `auto` keyword for any recusive function having void return, so write like this:
 ```cpp
 function<void(int)> dfs = [&](int u){
            ans.push_back(u);
            for(int to : adj[u]){
                dfs(to);
            }
        };
```

#### Set/Priority Queue with custom comparator
 
 ```cpp
 struct Edge {
 	int a,b,w;
 };

 struct cmp {
 	bool operator()(const Edge& x, const Edge& y) const { return x.w < y.w; }
 };
 
 int main(){
 	set<Edge,cmp> s;
		priority_queue<Edge,vector<Edge>,cmp> pq; // since priority queue stores element in reverse, you will get edge with max weight first
 }
```



#### Unordered Map for custom class
 
 ```cpp
struct Key{
	string name;
	int age;
	bool operator==(const Key &rhs) const{
		return name == rhs.name && age == rhs.age;
	}
	struct KeyHash{
		size_t operator()(const Key &k) const{
			size_t x1 = hash<string>()(k.name);
			size_t x2 = hash<int>()(k.age);
			return (x1) ^ (x2 << 1);
		}
	};
}; //https://en.cppreference.com/w/cpp/container/unordered_map/unordered_map

int main(){
	unordered_map<Key, string, Key::KeyHash> mp = {
		{{"Aryan", 20}, "India"},
		{{"Mary", 30}, "USA"}};
}
```


#### Get First and Last Occurence of an element

```cpp
int first = find(s.begin(),s.end(),'a')-s.begin(); // first = n, if not found
int last = find(s.rbegin(),s.rend(),'a')-s.rbegin(); // this will give index starting from back
last=n-1-last; // last=-1, if not found
```


#### Get Random integers
```cpp
#include <random>
#include <iostream>
 
int main()
{
    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> distrib(1, 6);
 
    for (int n=0; n<10; ++n)
        //Use `distrib` to transform the random unsigned int generated by gen into an int in [1, 6]
        std::cout << distrib(gen) << ' ';
    std::cout << '\n';
}
```
