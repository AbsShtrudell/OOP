#include <iostream>
#include <conio.h>
#include "Tree.h"

using namespace std;

int main()
{
	char input;
	int n;
	Tree<int> tree(10);
	TreeNode<int>* a;

	while (true)
	{
		cout << "1.Add node\n2.Show Postorder\n3.Show Preorder\n4.Find min node\n5.Find max node\n6.Exit" << endl;
		input = _getch();
		switch (input)
		{
		case '1':
			cout << "\nEnter value\n";
			cin >> n;
			a = new TreeNode<int>(n);
			tree.addNode(a);
			break;
		case'2':
			tree.viewPostorder();
			cout << endl;
			break;
		case'3':
			tree.viewPreorder();
			cout << endl;
			break;
		case'4':
			cout << tree.getMinNode()->getInfo() << endl;
			break;
		case'5':
			cout << tree.getMaxNode()->getInfo() << endl;
			break;
		case'6':
			exit(0);
		}
	}
}