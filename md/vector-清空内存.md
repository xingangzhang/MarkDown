#### vector::capacity
返回当前为vector分配的存储空间的大小，用元素表示。这个capacity(容量)不一定等于vector的size。它可以相等或更大，额外的空间允许适应增长，而不需要重新分配每个插入。
```cpp
size_type capacity() const noexcept;
```
Example
```cpp
#include <iostream>
#include <vector>

int main ()
{
  std::vector<int> myvector;

  // set some content in the vector:
  for (int i=0; i<100; i++) myvector.push_back(i);

  std::cout << "size: " << (int) myvector.size() << '\n';
  std::cout << "capacity: " << (int) myvector.capacity() << '\n';
  std::cout << "max_size: " << (int) myvector.max_size() << '\n';
  return 0;
}
```
A possible output for this program could be:
```
size: 100
capacity: 128
max_size: 1073741823
```

#### vector::clear
从vector中删除所有的元素（被销毁），留下size为0的容器。

不保证重新分配，并且由于调用此函数， vector的capacity不保证发生变化。强制重新分配的典型替代方法是使用swap：`vector<T>().swap(x);   // clear x reallocating `
```cpp
void clear() noexcept;
```
Example
```cpp
#include <iostream>
#include <vector>

void printVector(const std::vector<int> &v)
{
	for (auto it = v.begin(); it != v.end(); ++it)
	{
		std::cout << *it << ' ';
	}
	std::cout << std::endl;
}

int main()
{
	std::vector<int> v1(5, 50);

	printVector(v1);
	std::cout << "v1 size  = " << v1.size() << std::endl;
	std::cout << "v1 capacity  = " << v1.capacity() << std::endl;

	v1.clear();

	printVector(v1);
	std::cout << "v1 size  = " << v1.size() << std::endl;
	std::cout << "v1 capacity  = " << v1.capacity() << std::endl;

	v1.push_back(11);
	v1.push_back(22);

	printVector(v1);
	std::cout << "v1 size  = " << v1.size() << std::endl;
	std::cout << "v1 capacity  = " << v1.capacity() << std::endl;

	return 0;
}
```
Output
```
50 50 50 50 50
v1 size  = 5
v1 capacity  = 5

v1 size  = 0
v1 capacity  = 5
11 22
v1 size  = 2
v1 capacity  = 5
```

- vector容器的内存自增长 

与其他容器不同，其内存空间只会增长，不会减小。先来看看"C++ Primer"中怎么说：为了支持快速的随机访问，vector容器的元素以连续方式存放，每一个元素都紧挨着前一个元素存储。设想一下，当vector添加一个元素时，为了满足连续存放这个特性，都需要重新分配空间、拷贝元素、撤销旧空间，这样性能难以接受。因此STL实现者在对vector进行内存分配时，其实际分配的容量要比当前所需的空间多一些。就是说，vector容器预留了一些额外的存储区，用于存放新添加的元素，这样就不必为每个新元素重新分配整个容器的内存空间。

关于vector的内存空间，有两个函数需要注意：size()成员指当前拥有的元素个数；capacity()成员指当前(容器必须分配新存储空间之前)可以存储的元素个数。reserve()成员可以用来控制容器的预留空间。vector另外一个特性在于它的内存空间会自增长，每当vector容器不得不分配新的存储空间时，会以加倍当前容量的分配策略实现重新分配。例如，当前capacity为50，当添加第51个元素时，预留空间不够用了，vector容器会重新分配大小为100的内存空间，作为新连续存储的位置。

- vector内存释放

由于vector的内存占用空间只增不减，比如你首先分配了10,000个字节，然后erase掉后面9,999个，留下一个有效元素，但是内存占用仍为10,000个。所有内存空间是在vector析构时候才能被系统回收。empty()用来检测容器是否为空的，clear()可以清空所有元素。但是即使clear()，vector所占用的内存空间依然如故，无法保证内存的回收。

如果需要空间动态缩小，可以考虑使用deque。如果非vector不可，可以用swap()来帮助你释放内存。具体方法如下：
```cpp
#include <iostream>
#include <vector>

void printVector(const std::vector<int> &v)
{
    for (auto it = v.begin(); it != v.end(); ++it)
    {
        std::cout << *it << ' ';
    }
    std::cout << std::endl;
}

int main()
{
    std::vector<int> v1(5, 50);

    printVector(v1);
    std::cout << "v1 size  = " << v1.size() << std::endl;
    std::cout << "v1 capacity  = " << v1.capacity() << std::endl;

    v1.clear();

    printVector(v1);
    std::cout << "v1 size  = " << v1.size() << std::endl;
    std::cout << "v1 capacity  = " << v1.capacity() << std::endl;

    v1.push_back(11);
    v1.push_back(22);

    printVector(v1);
    std::cout << "v1 size  = " << v1.size() << std::endl;
    std::cout << "v1 capacity  = " << v1.capacity() << std::endl;

    std::vector<int>().swap(v1);
    printVector(v1);
    std::cout << "v1 size  = " << v1.size() << std::endl;
    std::cout << "v1 capacity  = " << v1.capacity() << std::endl;

    return 0;
}
```
Output
```
50 50 50 50 50 
v1 size  = 5
v1 capacity  = 5

v1 size  = 0
v1 capacity  = 5
11 22 
v1 size  = 2
v1 capacity  = 5

v1 size  = 0
v1 capacity  = 0
```