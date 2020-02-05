#include <stdio.h>
#include <Windows.h>
#include <malloc.h>

#pragma warning(disable:4996)
// 动态内存管理

// (int val = 20) 局部变量在在栈上开辟空间, 函数调用完后释放 
// 空间开辟与释放由系统或编译器完成:val=>自动变量(只要不用人参与就是自动变量)
// 动态内存管理是由系统管理做的

// 在函数里定义一个数组 => 数组在栈上
// 数组大小([]里的值)不能改变 
// 但是我们要是也不知道我们的数组(密码)多大 => 需要一个变长数组

// 空间开辟大小是固定的
// 数组在声明的时候, 必须指定数组的长度, 它所需要的内存在编译时分配
//int main1(){
//	int n = 0;
//	scanf("%d\n", &n);
//
//	char passwd[n];// 不能通过 => 形成变长数组
//
//	system("pause");
//	return 0;
//}

// 在函数内部定义一个数组 由于是在栈上开辟 所以只能开辟较小空间
// 所以需要动态内存分配
// 1. 变长数组
// 2. 大块内存
int main2(){

	int a[1000000];// 太大 4兆 崩了

	system("pause");
	return 0;
}

// malloc
// 地址增长方向:由下往上 
// 代码区>字符常量区>已初始化变量区>未初始化变量区>堆区>  >栈区
// 代码区               数据区                    堆区     栈区
// 栈区(调函数形成临时变量或者是在函数内定义局部变量时用)
// 堆区  (堆栈认为栈区)
// 动态内存变量开辟就是在堆区上开辟的
// 申请空间(几个字节) == 一定要释放 malloc函数的参数只有一个size
// size表明申请空间的大小 
// malloc申请空间失败 返回值为NULL(NULL指针)
// 否则申请成功 => 才能用 => 只要申请内存了 就得检查返回值是否为空
// 最后释放free free的参数为malloc的返回值

int main(){

	int n = 0;
	printf("Please Enter n: ");
	scanf("%d", &n);

	char* p = (char*)malloc(n*sizeof(char)); 
	// n*size 为申请的大小
	// 强转是告诉我们的使用者这块空间我们当char数组看待
	if (NULL == p){
		printf("malloc error!\n");// p=空 申请失败
		return 1;
	}
	//申请成功,可以取数据里 读数据到我们的缓冲区里 
	scanf("%s", p);// 把输入的字符串放到我们的堆空间中
	printf("echo# %s\n", p);// 输入完毕 也打印完毕

	free(p);
	system("pause");
	return 0;
}











































