#include <iostream>
using namespace std;

// 【题目在干什么】
// 数字只能按 1、2、3…n 的顺序 PUSH 进栈。
// 问：能不能通过 PUSH / POP，让弹出顺序正好等于题目给的序列？
// 能 → 打印每一步；不能 → 打印 NO。
//
// 【怎么想（三句话）】
// 1. 现在需要弹出 x：栈顶是 x → 直接 POP。
// 2. 栈顶不是 x → 把还没进栈的数继续 PUSH，直到把 x 推进去（或发现做不到）。
// 3. 数都推完了，栈顶还不是需要的数 → 输出 NO。
int main()
{
	int n;
	int a[10005];   // a[i]：目标序列第 i 个要弹出的数
	int s[10005];   // s：栈；s[top] 是栈顶
	int op[20010];  // 记下每一步：正数 x 表示 PUSH x，负数 -x 表示 POP x
	int top = 0;    // 栈里有几个数；top==0 表示空栈
	int next = 1;   // 下一个还没 PUSH 的数
	int step = 0;   // 已经记了几步操作
	int ok = 1;     // 1=还能做，0=做不到

	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];

	// 目标：依次弹出 a[1], a[2], …, a[n]
	for (int i = 1; i <= n; i++)
	{
		int need = a[i];   // 当前这一步需要弹出的数

		// 栈顶不是 need，就一直 PUSH
		while (top == 0 || s[top] != need)
		{
			if (next > n)   // 没有更多数可以 PUSH 了
			{
				ok = 0;
				break;
			}
			top++;
			s[top] = next;          // PUSH next
			op[step] = next;        // 用正数记下 PUSH
			step++;
			next++;
		}

		if (ok == 0) break;

		// 此时栈顶一定是 need，POP 掉
		op[step] = -s[top];         // 用负数记下 POP
		step++;
		top--;
	}

	if (ok == 0)
		cout << "NO" << endl;
	else
	{
		for (int i = 0; i < step; i++)
		{
			if (op[i] > 0)
				cout << "PUSH " << op[i] << endl;
			else
				cout << "POP " << -op[i] << endl;
		}
	}
	return 0;
}
