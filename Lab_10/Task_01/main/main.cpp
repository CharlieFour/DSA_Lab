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
    cout << "\n\nEnter the number to find: ";
    int b;
    cin >> b;
    if (tree.find(b) == b)
    {
        cout << "\nNumber found" << endl;
    }
    else if (tree.find(b) == -1)
    {
        cout << "\nNumber not found" << endl;
    }
    cout << endl;
    system("pause");
    return 0;
}