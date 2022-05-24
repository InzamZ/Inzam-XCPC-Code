---
title: 快速排序
date: 2020-10-29 22:36:23
updated: 2021-10-23 17:47:00
categories:
  - XCPC
  - 学习笔记
tags:
  - 分治
  - 排序
---
初三暑假, 师兄师姐在上面讲排序, 我就知道睡觉. ~~(不愧是你)~~ 到后来, 又知道了 algorithm 里面的 sort 函数. 所以模版题也用 sort 水过了. 但是, 出来混迟早要还. 所以, 我来补课了. 
<!-- more -->
## 快速排序基础

第一次想排序算法, 我的想法是找第 i 小的元素放在 i 处, 这样就实现了. 这算法效率极低. ~~优点是时间复杂度稳定(bushi)~~ 时间复杂度是O(n<sup>2</sup>), 于是后来我们学了插入排序, 冒泡排序, 还有现在的快速排序.

### 思路

选一个基准数, 我们把比它大的数放在右边, 比它小的放在左边, 将它放在两组数中间, 对左右两组数重复上述过程即可(递归). 而且它把一组数分成两组数, 这其实是一种分治思想. 

### 代码实现

本文 [图片来源](https://www.sohu.com/a/246785807_684445) 于网络, 可以看看, 感觉讲的不错. 

#### 挖坑法

![001](https://p.130014.xyz/2020/10/29/001.png)

先看懂方法， 再读代码。 先选一个数作为基准数, 为了方便选第一个, 现在基准值为 4 . 在 4 所在位置挖一个"坑".我们打算把比 4 小的数放在里面.

![002](https://p.130014.xyz/2020/10/29/002.png)

此时 right 从右边开始向左移动, 要找第一个比 4 小的数, 放入上面挖的"坑", 我们发现 1 满足了, 于是把 1 换到第一位. 1已经移动了,  1 原来的位置就变成坑了,  那么再找下一个数填"坑". 因为在右边, 所以我们要把左边比 4 大的数换到"坑"里. 

![003](https://p.130014.xyz/2020/10/29/003.png)

注意, 这样处理后 left 左边都是比 4 小的, right 右边都是比 4 大的. 我们要在左边找比 4 大的数, 于是找到了7. 放到"坑"里. 以此类推.

![004](https://p.130014.xyz/2020/10/29/004.png)

![005](https://p.130014.xyz/2020/10/29/005.png)

![006](https://p.130014.xyz/2020/10/29/006.png)
![007](https://p.130014.xyz/2020/10/29/007.png)

![008](https://p.130014.xyz/2020/10/29/008.png)

最后, left 和 right 重合,把 4 放进去, 实现了比它大的数在右边, 比它小的在左边 ,它在两组数中间. 那么递归对左右作相同操作即可. 

#### 指针法

有兴趣可以自行度娘, 核心思路不变.

### Code

代码仅供参考, 建议手打.

[洛谷【模板】快速排序](https://www.luogu.com.cn/problem/P1177) 

可以提交看是否正确, 测试点#1, #2 AC 应该就是正确的了. 想要通过全部测试点需要优化提高效率. 

```cpp
void Quicksort(int s[],int l,int r)
{
	if (l<r) 
	{
		int i=l,j=r,index=s[l];
		while (i<j)
		{
			//to find the first number which is smaller than x
			while ( i<j && s[j]>=index ) 	j--;
			if ( i<j && s[j]<index ) s[i++]=s[j];
			
			////to find the first number which is larger than x
			while ( i<j && s[i]<=index ) 	i++;
			if ( i<j && s[i]>index ) s[j--]=s[i];
		}
		//now i=j
		s[i]=index;
        //recurse to sort the right subarray and left subarray
		Quicksort(s,l,i-1);
		Quicksort(s,i+1,r);
	}
}
```

## 优化处理

快速排序的不稳定性在于基准值的选取,选的好效率高, 不好的话时间复杂度会到 O(n<sup>2</sup>) . 因此可以进行优化. 
以下优化方法参考和引用于 [yuebaii的博文](https://blog.csdn.net/qq_19525389/article/details/81436838)。

### 随机选取基准

#### 思路

我们随机选取一个数, 让它作为基准即可. 这在数组原本有一定顺序情况下很好用. 核心代码不变, 我们交换一下随机选取的数和数组的第一个数即可.

#### Code

此时提交到 [洛谷](https://www.luogu.com.cn/problem/P1177) 通过 4 个测试点, 还剩一个. 

```cpp
void Quicksort_Rand(int s[],int l,int r)
{
	if (l<r) 
	{
		int x=rand_l2r(l,r);
        //rand_l2r will return a random number between l and r
        
		swap(s[x],s[l]);
		int i=l,j=r,index=s[l];
		while (i<j)
		{
			//to find the first number which is smaller than x
			while ( i<j && s[j]>=index ) 	j--;
			if ( i<j && s[j]<index ) s[i++]=s[j];
			
			////to find the first number which is larger than x
			while ( i<j && s[i]<=index ) 	i++;
			if ( i<j && s[i]>index ) s[j--]=s[i];
		}
		//now i=j
		s[i]=index;
		quicksort(s,l,i-1);
		quicksort(s,i+1,r);
	}
}

```



#### 速度对比

| 单位：ms | 随机数据 | 上升序列 | 下降序列 | 重复数据 |
| :------: | :------: | :------: | :------: | :------: |
| 固定基准 |   794    |  109935  |  105949  |  51280   |
| 随机基准 |   946    |   575    |   601    |  25970   |

就很看脸的，脸黑的话随机就emm……

说明我的生成数据和测试方法。这里生成了1000组数据，每组数据10000个数。各个类型生成规则如下

- 随机数据，就是 rand() 生成的，每组数据刷新一次随机种子。
- 上升序列：1-10000
- 下降序列：10000-1
- 重复数据：随机数生成5个数，每个数重复2000次，连在一起。~~突然想到可以生成不连在一起的，但懒得写了。~~

### 三数取中法

#### 思路

随机选取虽然有效, 但最坏情况（选到区间内最大或最小数）仍会发生, 于是我们能不能找个方法, 让我们不会取到最大（或最小）的数呢? 这就是三数取中法. 我们选取 l, r, 以及中间的数m, 选择中间的数, 就能使取的基准尽量合适. ( 注意尽量, 因为可以看到速度对比中最恶心的是重复数组 )

因为自己沙壁，写错了，后面复制粘贴也没debug出来。惨

####  Code

```cpp
void Quicksort_MoT (int s[],int l,int r)
{
    //Mediam of Three
	if (l<r) 
	{
	   if (r-l>2)
	   {
			int x=( s[l] >= s[r] ) ? l : r ;
			x= ( s[x] <= s[(l+r)/2] ) ? x : (l+r)/2 ;
			swap(s[l],s[x]);
		}
		
		int i=l,j=r,index=s[l];
		while (i<j)
		{
			//to find the first number which is smaller than x
			while ( i<j && s[j]>=index ) 	j--;
			if ( i<j && s[j]<index ) s[i++]=s[j];
			
			//to find the first number which is larger than x
			while ( i<j && s[i]<=index ) 	i++;
			if ( i<j && s[i]>index ) s[j--]=s[i];
		}
		//now i=j
		s[i]=index;
		Quicksort_MoT(s,l,i-1);
		Quicksort_MoT(s,i+1,r);
	}
}

```
#### 速度对比
| 单位：ms | 随机数据 | 上升序列 | 下降序列 | 重复数据 |
| :------: | :------: | :------: | :------: | :------: |
| 固定基准 |   794    |  109935  |  105949  |  51280   |
| 随机基准 |   946    |   575    |   601    |  25970   |
| 三数取中 |   829    |  33900   |   277    |   286    |

诚然，三数取中在随机数组上优化明显，然而对于降序反而是要低于随机取数的，而且面对重复数组仍然束手无策。洛谷提交后 #1～3 AC #4～5 TLE #4其实是降序重复混合数组。



### 三数取中法+插排
#### 思路
在部分有序且较小的数组中，插入排序的效率要比快速排序高，我们不妨让数组小于某个值（5～20）时，采用插入排序代替快速排序。这里我们取10。
#### Code

```Cpp

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

void Quicksort_MoT_ISTSORT (int s[],int l,int r)
{
	if (l<r) 
	{
	  	if(r-l+1<10) 
	  	{
	  	  Insertsort(s,l,r);
	  	}
	  	else 
	  	{
    		//Mediam of Three
		   if (r-l>2)
		   {
				int x=(s[l]>=s[r])?l:r;
				x=(s[x]<=s[(l+r)/2])?x:(l+r)/2;
				swap(s[l],s[x]);
			}
			
			int i=l,j=r,index=s[l];
			while (i<j)
			{
				//to find the first number which is smaller than x
				while ( i<j && s[j]>=index ) j--;
				if ( i<j && s[j]<index ) s[i++]=s[j];
				
				//to find the first number which is larger than x
				while ( i<j && s[i]<=index ) i++;
				if ( i<j && s[i]>index ) s[j--]=s[i];
			}
			//now i=j
			s[i]=index;
			Quicksort_MoT_ISTSORT (s,l,i-1);
			Quicksort_MoT_ISTSORT (s,i+1,r);
		}
	}
}
```
#### 速度对比

|   单位：ms    | 随机数据 | 上升序列 | 下降序列 | 重复数据 |
| :-----------: | :------: | :------: | :------: | :------: |
|   固定基准    |   794    |  109935  |  105949  |  51280   |
|   随机基准    |   946    |   575    |   601    |  25970   |
|   三数取中    |   829    |   277    |   286    |  33900   |
| 三数取中+插排 |   795    |   223    |   229    |  31670   |

洛谷数据中包含了重复序列，所以这种方法#4 #5 还都过不了。

### 三数取中法+插排+聚合重复元素

#### 思路

既然重复元素成为我们效率的最大障碍，那就想办法解决它。重复元素是和 index 基准值相同的，即位置就在基准值旁边，所以我们想办法让重复元素不参与后续排序。
#### Fake Code

```cpp
void FQuicksort_MoT_ISTSORT_DEREP (int s[],int l,int r)
{
	if (l<r) 
	{
	  	if(r-l+1<5) 
	  	{
	  	  Insertsort(s,l,r);
	  	}
	  	else 
	  	{
  			//Mediam of Three
		   if (r-l>2)
		   {
				int x=(s[l]>=s[r])?l:r;
				x=(s[x]<=s[(l+r)/2])?x:(l+r)/2;
				swap(s[l],s[x]);
			}
			
			int i=l,j=r,index=s[l];
			while (i<j)
			{
				//to find the first number which is smaller than x
				while ( i<j && s[j]>=index ) j--;
				if ( i<j && s[j]<index ) s[i++]=s[j];
				
				//to find the first number which is larger than x
				while ( i<j && s[i]<=index ) i++;
				if ( i<j && s[i]>index ) s[j--]=s[i];
			}
			//now i=j
			s[i]=index;
            //This is fake DEREP
			while (i>=l && s[i]==index) i--;
			while (j<=r && s[j]==index) j++;
			FQuicksort_MoT_ISTSORT_DEREP (s,l,i);
			FQuicksort_MoT_ISTSORT_DEREP (s,j,r);
		}
	}
}
```
#### 问题
上面是我自己理解的，问题在于只是在周围聚合，我们要的是对整个数组聚合。应该把所有与基准值相等的值聚合起来。然而就把洛谷的题AC过去了 (《 _《 ) 
#### True Code

```cpp
void Quicksort_MoT_ISTSORT_DEREP (int s[],int l,int r)
{
	if (l<r) 
	{
	  	if(r-l+1<10) 
	  	{
	  		Insertsort (s,l,r);
	  	}
	  	else 
	  	{
  			//Mediam of Three
		   if (r-l>2)
		   {
				int x=(s[l]>=s[r])?l:r;
				x=(s[x]<=s[(l+r)/2])?x:(l+r)/2;
				swap(s[l],s[x]);
			}
			
			int i=l,j=r,index=s[l];
			while (i<j)
			{
				//to find the first number which is smaller than x
				while ( i<j && s[j]>=index ) j--;
				if ( i<j && s[j]<index ) s[i++]=s[j];
				
				//to find the first number which is larger than x
				while ( i<j && s[i]<=index ) i++;
				if ( i<j && s[i]>index ) s[j--]=s[i];
			}
			//now i=j
			s[i]=index;
			for (int p=i-1;p>l;p--) 
			{
				if (s[p]==index) swap(s[--i],s[p]);
			}
			for (int p=j+1;p<r;p++) 
			{
				if (s[p]==index) swap(s[++j],s[p]);
			}
			Quicksort_MoT_ISTSORT_DEREP (s,l,i-1);
			Quicksort_MoT_ISTSORT_DEREP (s,j+1,r);
		}
	}
}
```

#### 速度对比

|     优化类型\单位：ms      | 随机数据 | 上升序列 | 下降序列 | 重复数据 |
| :------------------------: | :------: | :------: | :------: | :------: |
|          固定基准          |   794    |  109935  |  105949  |  51280   |
|          随机基准          |   946    |   575    |   601    |  25970   |
|          三数取中          |   829    |   277    |   286    |  33900   |
|       三数取中+插排        |   795    |   223    |   229    |  31670   |
| 三数取中+插排+聚合重复元素 |   1029   |   408    |   429    |   132    |

随机数上的速度其实并没有很快，关键这个优化牺牲了几乎可以忽略的速度，换来了重复元素多的情况下的高效，使在实际处理中算法效率更高。

### 优化递归过程
其实这个优化效果不大，可以看看我参考的[博文](https://blog.csdn.net/insistgogo/article/details/7785038)。
#### 速度对比
|     优化类型\单位：ms      | 随机数据 | 上升序列 | 下降序列 | 重复数据 |
| :------------------------: | :------: | :------: | :------: | :------: |
|          固定基准          |   794    |  109935  |  105949  |  51280   |
|          随机基准          |   946    |   575    |   601    |  25970   |
|          三数取中          |   829    |   277    |   286    |  33900   |
|       三数取中+插排        |   795    |   223    |   229    |  31670   |
| 三数取中+插排+聚合重复元素 |   1029   |   408    |   429    |   132    |
|            sort            |   1101   |   471    |   378    |   603    |

## 总结
一个优秀排序算法，不是针对于某种特定序列排序的，而应该对各种序列都要有较优的效率，如：STL中的 sort。在实际运用中，有时并不能知道数据的概况，那就要选一个全面高效的算法。
### [洛谷 P1177 快速排序](https://www.luogu.com.cn/record/40798949) Solution

```cpp
#define AWSL <bits/stdc++.h>
#define awei_sine using namespace std
#define reg register
#define F(i,b,n)  for(reg int i=(b);i<(n);i++)
#define f(i,b,n)  for(reg int i=(b);i<=(n);i++)

#include AWSL
awei_sine;

const int maxn=1e5+10;
int s[maxn];

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

void Quicksort_MoT_ISTSORT_DEREP (int s[],int l,int r)
{
	if (l<r) 
	{
	  	if(r-l+1<10) 
	  	{
	  		Insertsort (s,l,r);
	  	}
	  	else 
	  	{
  			//Mediam of Three
		   if (r-l>2)
		   {
				int x=(s[l]>=s[r])?l:r;
				x=(s[x]<=s[(l+r)/2])?x:(l+r)/2;
				swap(s[l],s[x]);
			}
			
			int i=l,j=r,index=s[l];
			while (i<j)
			{
				//to find the first number which is smaller than x
				while ( i<j && s[j]>=index ) j--;
				if ( i<j && s[j]<index ) s[i++]=s[j];
				
				//to find the first number which is larger than x
				while ( i<j && s[i]<=index ) i++;
				if ( i<j && s[i]>index ) s[j--]=s[i];
			}
			//now i=j
			s[i]=index;
			for (int p=i-1;p>l;p--) 
			{
				if (s[p]==index) swap(s[--i],s[p]);
			}
			for (int p=j+1;p<r;p++) 
			{
				if (s[p]==index) swap(s[++j],s[p]);
			}
			Quicksort_MoT_ISTSORT_DEREP (s,l,i-1);
			Quicksort_MoT_ISTSORT_DEREP (s,j+1,r);
		}
	}
}

int main()
{
	int n;
	scanf ("%d",&n);
	F(i,0,n) scanf ("%d",&s[i]);
	Quicksort_MoT_ISTSORT_DEREP (s,0,n-1);
	F(i,0,n) printf("%d ",s[i]); 
	return 0;
}
```

终于，补课完成。<span class="heimu" title="你知道的太多了"> ~~当然有机会我会自己测试一下代码效率，因为我还是觉得我的插排哪个地方写丑了。~~</span>~~不知道要鸽多久（逃~~

<div align=center>
![](https://p.130014.xyz/2020/10/30/4BB59D37-8C77-4164-8D91-92976B8FFAEC.th.jpg)
</div>

我居然没有鸽，<span class="heimu" title="你知道的太多了"> 主要是最近水课多。</span>之前居然是三数取中法有个地方写反了.总之,正式结束了.



<!-- Q.E.D. -->