---
title: 排序算法
date: 2020-10-31 23:22:18
updated: 2021-10-23 17:47:00
categories:
  - XCPC
  - 学习笔记
tags:
  - 分治
  - 排序
---
补完排序算法的课后, 自然地就会想到其他算法了, 所以我搞了归并排序, Shell 排序, 以及堆排序. 
<!-- more -->

## 插入排序

### 核心思想

插入排序是将元素与排序好的元素一一比对, 找到元素应该在的位置, 将其插入. 就像打扑克牌是顺牌一样.

### Code 

```cpp
void Insertsort (int s[],int l,int r)
{
	for(int i=l+1;i<=r;i++)
	{
   		int j=i-1,key=s[i];
   		while (j>=l && s[j]>key)
   		{
   			s[j+1]=s[j];
   			j--;
   		}
   		s[j+1]=key;
	}
}
```

### 优化一：二分插入排序

其实找元素的位置可以不用从后往前, 可以二分查找, 然后再移动数组.这样可以加快速度, 数据小时不明显.

```cpp
int BinarySearchPos(int s[],int l,int r,int key)
{
	int i=l,j=r,mid;
	while (i<=j)
	{
		mid=(i+j)/2;
		if (key==s[mid]) 
		{
			//return the biggest subscript of value 'key'
			while (key==s[mid+1]) mid++;
			return mid;
		}
		else if (s[mid]>key) j=mid-1;
		else i=mid+1;
	}
	return i;
 } 
 
void BinarySort (int s[],int l,int r)
{
	for(int i=l+1;i<=r;i++)
	{
		int pos=BinarySearchPos(s,l,i-1,s[i]);
		int j=i,key=s[i];
		while (j>pos)
		{
			s[j]=s[j-1];
			j--;
		}
		s[j]=key;
	}
}

```

### 优化二：Shell 排序

Shell 排序，又称缩小增量排序。出自 D.L.Shell ，因此得名。它的核心思想先取增量 d<sub>1</sub> ,将间隔为 d<sub>1</sub> 的数分为一组, 总共 d<sub>1</sub> 组. 对各组插入排序, 然后缩小增量, 重复此过程, 最后增量为1时, 最后一次插入排序.

该算法优点在于它能让数组尽可能先有序, 使插入排序的效率更高.

Shell 排序很依赖增量的选法, 一开始 D.L.Shell 直接取 n/2 , 然而会导致有些情况, 奇数位置和偶数位置直到1时才比较, 效率不高.所以其他大佬们提出了各种方法, 有人提出都要用奇数, 有人提出.要用互质的数等等……此处我们采用 Knuth 算法 ,他建议在 n<1000 时使用. 

```cpp
void KnuthShellSort(int* s,int length)
{
	int h;
	for (h=1;h<=length/9;h=h*3+1);
	for (;h>0;h=h/3)
	{
		for (int i=h;i<length;i++)
		{
			int key=s[i],j=i;
			for ( j=i-h ; j>=0 && s[j]>key ; j-=h ) s[j+h]=s[j];
			s[j+h]=key;
		}
	}
}
```

### 速度对比

使用 1000 组 10000 个随机数. 同一套数据. 

| 单位: ms | 插入排序 | 二分插入排序 | Shell Knuth | 快速排序 |
| :------: | :------: | :----------: | :---------: | :------: |
|   时间   |  50157   |    40869     |    6079     |   5841   |



## 归并排序

### 核心思想

归并排序也是一种分治思想, 它把数组平分为小数组, 分别让子数组有序, 然后合并两个子区间. 两个有序的子数组排序比较简单, 让两个光标分别指向子数组开头, 比较光标指向的数, 把小的数放在新数组前面并移动光标. 当有一个数组到达边界是, 另外一个数组的只需依次全部放进新数组即可.(因为之后的数都大于前面数组的最大值) 而递归平分数组的边界刚好是只有一个元素, 必然有序. 所以问题就解决了. 

### Code

```cpp
void MergeArray(int* s,int l,int r,int* temp)
{
	int i=l,m=(l+r)/2,j=m+1,k=l;
	while ( i<=m && j<=r )
	{
		if (s[i]<=s[j]) temp[k]=s[i++];
		else temp[k]=s[j++];
		k++;
	}
	while (i<=m) temp[k]=s[i++],k++;
	while (j<=r) temp[k]=s[j++],k++;
	i=l;
	while (i<=r)
	{
		s[i]=temp[i];
		i++;
	}
}

void Mergesort(int* s,int l, int r,int* temp)
{
	if (r<=l) return ;
	int m=(l+r)/2;
	Mergesort(s,l,m,temp);
	Mergesort(s,m+1,r,temp);
	MergeArray(s,l,r,temp);
}

```

### 复杂度分析

归并排序的时间复杂度是 O(n*logn) , 比较稳定, 理论上速度优于快速排序, 因为快速排序效率取决于基准数的选取. 那实际情况呢, 我测试了一下. 1000 组 10000 个随机数的数据.

| 单位: ms | 归并排序 | Shell Knuth | 快速排序 |
| :------: | :------: | :---------: | :------: |
|   时间   |   5900   |    6079     |   5841   |

然而发现并没有很大的速度差距. 原因是归并排序需要在数组间转来转去, 这个并没有算入时间复杂度, 这是个常数, 但这个常数大到不可忽略. 而且你需要一个临时数组(可以共用), 空间复杂度应该是 O(N).

其实有可以实现 O(1) 的代码,但代码复杂度会变高. 有时间再研究, 毕竟<span class="heimu">期中考迫近,作业写不完</span>

## 堆排序

### 原理
利用堆这一结构进行排序，堆是一种数据结构，结构保证节点值大于其子树的所有值。利用堆来排序，先要构造一个堆，然后将堆顶元素与最后一个节点交换，最后一个节点已经为最大值，不参与接下来堆的构造。再维护一下堆，直到整个数组排序完成。

因为一开始整个数组都是无序的，所以要对非叶子节点都进行构造堆，从下往上，从右往左。如果父节点和子节点发生交换，那么新的子节点也要和孙节点再次比较，因为换下来的数比原来的子节点小，那么需要再次比较。当然，循环到这个数比子节点大时就可以停止了。

交换堆顶和最后一个元素后，其实根节点的左右子树都是一个堆，所以，只需要对堆顶(刚换上来的数)构造堆即可。

### 演示
举个例子：
找到第一个非叶子节点，图中是6.
![](https://p.130014.xyz/2020/11/03/7724107A-AAFF-4FB2-A07D-305831F0B238.png)
和两个叶子节点比较后发现，8比6大，于是交换。

![](https://p.130014.xyz/2020/11/03/F9341DE5-25A5-47E8-8218-10C552046FCD.png)

下一个节点是5，5<8,交换。

![](https://p.130014.xyz/2020/11/03/EED43B5F-C82D-4B96-BF3B-AC05E304388E.png)

此处因为8和5交换，对5新的位置要再次进行节点维护，6>5,交换。

![](https://p.130014.xyz/2020/11/03/sort001.png)

接下来把8换到最后一个节点，5换到堆顶，维护堆。

![](https://p.130014.xyz/2020/11/03/sort002.png)

6>5 ，交换。

![](https://p.130014.xyz/2020/11/03/sort003.png)

堆维护完毕，6与2交换。

![](https://p.130014.xyz/2020/11/03/sort004.png)

5>2，5和2交换。

![](https://p.130014.xyz/2020/11/03/sort005.png)

堆生成完毕。5和4交换。

![](https://p.130014.xyz/2020/11/03/sort006.png)

交换完还是满足堆的定义，于是交换2和4，排序完成。

![](https://p.130014.xyz/2020/11/03/sort007.png)

### Code
```cpp
void IfyMaxHeap(int* s,int start,int end)
{
    int dad=start,son=dad*2+1;
    while (son<=end)
  	{
  	     if (s[son+1]>s[son] && son+1<=end) son++;
  	     if (s[dad]>=s[son]) return ;
  	     std::swap(s[son],s[dad]);
  	     dad=son;
  	     son=dad*2+1;
  	}
}

void HeapSort(int* s,int len)
{
    for (int i=len/2-1;i>=0;i--)
  	{
  	     IfyMaxHeap(s,i,len-1);
  	}
  	
  	for (int i=len-1;i>0;i--)
  	{
  	     std::swap(s[i],s[0]);
  	     IfyMaxHeap(s,0,i-1);
  	}
}
```
### 复杂度分析
时间复杂度O(nlogn) 。第一次构造堆nlogn，第二次到第n次，每次logn，最终和近似 2nlogn，是nlogn级别的。
### 反思优化

问题来了，好像慢了点？就是常数大的问题，quicksort甚至跑出了10s以内的好成绩，那为什么呢。原因就在我们总是把最小数换到堆顶，这样会比较很多次，要不我们把它存到另一个数组，然后把左右节点大的换到堆顶进行维护。

```cpp
void IfyMaxHeap(int* s,int start,int end)
{
    int dad=start,son=dad*2+1;
    while (son<=end)
        {
             if (s[son+1]>s[son] && son+1<=end) son++;
             if (s[dad]>=s[son]) return ;
             std::swap(s[son],s[dad]);
             dad=son;
             son=dad*2+1;
        }
}

void IfyMaxHeapAdd(int* s,int start,int end)
{
    int dad=start,son=dad*2+1;
    while (son<=end)
        {
             if (s[son+1]>s[son] && son+1<=end) son++;
             s[dad]=s[son];
             s[son]=-1000000;
             dad=son;
             son=dad*2+1;
        }
}

void HeapSortAdd(int* s,int len,int* temp)
{
    for (int i=len/2-1;i>=0;i--)
        {
             IfyMaxHeap(s,i,len-1);
        }

        for (int i=len;i>0;i--)
        {
             temp[i-1]=s[0];
             IfyMaxHeapAdd(s,0,len-1);
        }
}
```

### 速度对比

使用 10000 组10000个随机数。（运行环境有别于上面的测试环境）

| 单位: ms | HeapSort  | HeapSortAdd | MergeSort | Shell Knuth | Quicksort |
| :------: | :-------: | :---------: | :-------: | :---------: | :-------: |
|   时间   | 22146.036 |  12042.721  | 12320.506 |  11911.036  | 11750.599 |

​	发现常数下来了. <span class="heimu">煞笔我居然因为一个小错误写了一下午.</span>



## 总结

​	排序算法基本就结束了, 而公认的最高效的还是快速排序, 其他或多或少都有些缺点. 如果允许还是尽量使用 STL 里的 sort , 毕竟结构体的排序...