// 소프트웨어학부 2021203034 허찬영

#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
#include <vector>
#include <iomanip>
#include <cmath>

using namespace std;

typedef struct node {
	struct node* next;
	char data;
}node;

typedef struct Tree {
	node nodes;
	struct Tree* left;
	struct Tree* right;
	char data;
}Tree;

char H_tree[15][15];
int ssize = 0, n = 0;
int V[4][2] = { {-1, 0}, {1, 0}, {0, 1}, {0, -1} };
string str;
node* root = NULL;

node* insert(node* root, int data) {
	if (root == NULL) {
		root = new node;
		root->next = NULL;
		root->data = data;
		ssize++;
		return root;
	}
	else {
		root->next = insert(root->next, data);
		return root;
	}
}

void print(Tree* tree, int depth) {
	if (tree) {
		print(tree->right, depth + 1);
		cout << setw(2 * depth) << "" << tree->data << endl;
		print(tree->left, depth + 1);
	}
}

void H(int node, int i, int j, int d, int U, int D, int R, int L)
{
	if (node > n) return;

	H_tree[i][j] = str[node - 1];

	if (2 * node <= n) {
		H_tree[i + d * V[L][0]][j + d * V[L][1]] = str[2 * node - 1];
		H(4 * node, i + d * (V[L][0] + V[U][0]),
			j + d * (V[L][1] + V[U][1]), d / 2, D, U, L, R);
		H(4 * node + 1, i + d * (V[L][0] + V[D][0]),
			j + d * (V[L][1] + V[D][1]), d / 2, U, D, R, L);
	}
	if (2 * node + 1 <= n) {
		H_tree[i + d * V[R][0]][j + d * V[R][1]] = str[2 * node];
		H(4 * node + 2, i + d * (V[R][0] + V[D][0]),
			j + d * (V[R][1] + V[D][1]), d / 2, U, D, R, L);
		H(4 * node + 3, i + d * (V[R][0] + V[U][0]),
			j + d * (V[R][1] + V[U][1]), d / 2, D, U, L, R);
	}
}

int center(int n) { return n <= 1 ? 0 : 2 * center(n / 4) + 1; }
int depth(int n) { return n <= 7 ? 1 : 2 * depth(n / 4); }

int main() {
	char word;
	int i = 0, key, cnt = 1, ndepth = 0, sum = 0;;
	vector<char> v, rotate_opt, nrotate_opt, Htree_opt;
	Tree binaryTree[210];
	string command = "";
	
	while(true) {
		cin >> command;
		if (!command.compare("EOI"))
			break;
		else if (!command.compare("INS")) {
			cin >> word;

			v.push_back(word);
			push_heap(v.begin(), v.end());
		}
		else if (!command.compare("DEL")) {
			pop_heap(v.begin(), v.end());
			v.pop_back();
		}
	} 

	// rotate_form
	rotate_opt = v;
	for (int i = 0; i < rotate_opt.size(); i++) {

		key = rotate_opt[i];

		root = insert(root, key);

		binaryTree[cnt].data = root->data;
		binaryTree[cnt].left = NULL;
		binaryTree[cnt].right = NULL;
		root = root->next;

		if (cnt % 2 == 0) {
			binaryTree[cnt / 2].left = &binaryTree[cnt];
		}
		else {
			binaryTree[cnt / 2].right = &binaryTree[cnt];
		}
		cnt++;

	}
	printf("___ROTATE_FORM___\n");
	print(&binaryTree[1], 0);
	cout << endl << endl;

	// not-rotate form
	nrotate_opt = v;
	while (sum < nrotate_opt.size()) {
		sum += pow(2, ndepth);
		ndepth++;
	}

	printf("___NOT-ROTATE_FORM___\n");
	int ncnt = 0;
	for (i = 0; i < ndepth - 2; i++) {
		cout << setw(pow(2, ndepth - i -1) - 1) << "";

		for (int j = 0; j < pow(2, i); j++) {
			if (ncnt < nrotate_opt.size()) {
				cout << nrotate_opt[ncnt++] << setw(pow(2, ndepth - i) - 1) << "";
			}
		}
		cout << endl;
	}

	if (ndepth - i == 2) {
		cout << setw(1) << "";
		for (int j = 0; j < pow(2, i); j++) {
			if (ncnt < nrotate_opt.size()) {
				cout << nrotate_opt[ncnt++] << setw(pow(2, ndepth - i) - 1) << "";
			}
		}
		cout << endl;
		i++;
	}

	if (ndepth - i == 1) {
		for (int j = 0; j < pow(2, i); j++) {
			if (ncnt < nrotate_opt.size()) {
				cout << nrotate_opt[ncnt++] << setw(pow(2, ndepth - i) - 1) << "";
			}
		}
		cout << endl;
		i++;
	}
	cout << endl << endl;

	// H-tree form
	Htree_opt = v;
	printf("___H-TREE_FORM___\n");
	for (int i = 0; i < Htree_opt.size(); i++) {
		str.push_back(Htree_opt[i]);
		n++;
	}

	H(1, center(n), center(n), depth(n), 0, 1, 2, 3);

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if ((H_tree[i][j] >= '0' && H_tree[i][j] <= '9') || (H_tree[i][j] >= 'A' && H_tree[i][j] <= 'z')
				|| H_tree[i][j] == '?')
				cout << H_tree[i][j] << " ";
			else
				cout << "  ";
		}
		cout << endl;
	}

	return 0;
}