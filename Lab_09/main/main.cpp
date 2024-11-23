#include <iostream>
#include "../lib/binarytree.cpp"

using namespace std;

int main()
{
    BinaryTree<int> tree;
    cout << "Simple binary insertion" << endl;
    for(int i = 0; i < 10; i++)
    {
        int a = rand() % 10;
        tree.insert(a);
        cout << a << " ";
    }
    cout << "\n\nPre Order" << endl;
    tree.preTrav(tree.tree);
    cout << "\n\nIn Order" << endl;
    tree.inTrav(tree.tree);
    cout << "\n\nPost Order" << endl;
    tree.postTrav(tree.tree);
    cout << endl;
    system("pause");
    return 0;
}