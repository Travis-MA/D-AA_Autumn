problemA: 简单的list使用， 简单的merge算法（归并）

problemB：list使用，merge算法，重复元素消除，结构体使用

problemC：list使用，动态链表缓存

problemD：list使用，完整的归并排序，和重复元素消除，结构体使用

problemE：双向循环链表，迭代器的一些骚操作





新知识：

​	1.如何使用容器类list

​		-list<int> name = XXX;

​		.push_back,  .sort, .erase, .insert

​	2.指针基础

​		int &r = i;  // &紧跟类型名出现，因此是声明的一部分，r是一个引用

​		int × p;      // ×紧随类型名出现，因此是声明的一部分，p是一个指针

​		p = &i;       // &出现在表达式中，是一个取地址符

​		×p = i;        // *出现在表达式中，是一个解引用符

​		int &r2 = ×p;   // &是声明的一部分， ×是一个解引用符

​	3.迭代器思想

​		list<int> :: iterator iter = man.empty(); //  man 是一个list，传统迭代器声明方法

​		auto iter = man.empty(); // 自动迭代器声明方法

​		iter++

​		iter->x =  相当于  *iter.x =

​		erase(p)    删除迭代器p所指定的元素，返回一个指向被删元素之后的迭代器，若p指向尾元素

​				则返回尾后（off-the-end）迭代器。

​		erase(b，e)    删除迭代器b和e之间的元素，其余同上。

​	4.结构体的使用

​		看B，D代码

