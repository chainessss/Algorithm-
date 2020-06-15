#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int maxSize = 100;

typedef struct Node
{
	int weight, parent, lchild, rchild;
}HTNode, *HfTree;
typedef char** HfCode;

HfTree create_HfTree(int* w, int n);
void select(HfTree HT, int k, int& min1, int& min2);
int min(HfTree HT, int k);
void HfCoding(HfTree HT, HfCode& HC, int n);

int main()
{
	//��ʼ��
	int n = 8, w[] = { 1,5,8,10,10,18,20,28 };//wΪÿ���ַ���Ȩ��
	char s[] = "abcdefgh";
	HfCode HC = NULL;
	HfTree hTree = create_HfTree(w, n);

	//���ù���������
	HfCoding(hTree, HC, n);

	//����ַ���Ӧ�ı���
	printf("�Ӹ���㵽Ҷ�ӽ�������Ϊ��\n");
	for (int i = 0; i < n; ++i) {
		cout << s[i] << "---" << HC[i] << endl;
	}
}

//�����������
HfTree create_HfTree(int* w, int n)
{
	int total = 2 * n - 1;
	HfTree HT = (HfTree)malloc(total * sizeof(HTNode));

	int i;
	for (i = 0; i < n; i++)
	{
		HT[i].parent = HT[i].lchild = HT[i].rchild = -1;
		HT[i].weight = *w;
		w++;
	}
	for (; i < total; i++)
	{
		HT[i].parent = HT[i].lchild = HT[i].rchild = -1;
		HT[i].weight = 0;
	}

	int min1, min2;//���ڱ���ÿ��ѭ��ѡ��������weight��С��parentΪ0�Ľڵ�
	for (i = n; i < total; i++)
	{
		select(HT, i, min1, min2);
		HT[min1].parent = i;
		HT[min2].parent = i;
		HT[i].lchild = min1;
		HT[i].rchild = min2;
		HT[i].weight = HT[min1].weight + HT[min2].weight;
	}
	return HT;
}

//��HT��ǰk��Ԫ����ѡ������weight��С��parentΪ-1�Ľڵ�
void select(HfTree HT, int k, int& min1, int& min2)
{
	min1 = min(HT, k);
	min2 = min(HT, k);
}

//��HT��ǰk��Ԫ����ѡ��weight��С��parentΪ-1�Ľڵ㣬�������±�
int min(HfTree HT, int k)
{
	int i = 0, mini, min_weight;

	while (HT[i].parent != -1)
		i++;
	min_weight = HT[i].weight;
	mini = i;

	for (; i < k; i++)
	{
		if (HT[i].weight < min_weight && HT[i].parent == -1)
		{
			min_weight = HT[i].weight;
			mini = i;
		}
	}

	HT[mini].parent = 1;

	return mini;
}

//�����������
void HfCoding(HfTree HT, HfCode& HC, int n)
{
	HC = (HfCode)malloc(n * sizeof(char*));
	char* code = (char*)malloc(n * sizeof(char));
	int cur = 2 * n - 2, code_len = 0;

	for (int i = 0; i < cur + 1; i++)
	{
		HT[i].weight = 0;
	}

	while (cur != -1)
	{
		if (HT[cur].weight == 0)
		{
			HT[cur].weight = 1;
			if (HT[cur].lchild != -1)
			{
				code[code_len++] = '0';
				cur = HT[cur].lchild;
			}
			else
			{
				code[code_len] = '\0';
				HC[cur] = (char*)malloc((code_len + 1) * sizeof(char));
				if (!HC[cur])
				{
					cout << "HC[cur] malloc faild!" << endl;
					exit(-1);
				}
				strcpy(HC[cur], code);
			}
		}
		else if (HT[cur].weight == 1)
		{
			HT[cur].weight = 2;
			if (HT[cur].rchild != -1)
			{
				code[code_len++] = '1';
				cur = HT[cur].rchild;
			}
		}
		else
		{
			HT[cur].weight = 0;
			cur = HT[cur].parent;
			--code_len;
		}
	}
	free(code);
}