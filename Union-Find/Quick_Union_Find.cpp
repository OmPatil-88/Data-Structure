#include <iostream>
using namespace std;

class QuickFind
{
private:
    int *array;
    int N;

public:
    QuickFind(int n = 0) : N(n)
    {
        array = new int[n];
        for (int i = 0; i < n; i++)
        {
            array[i] = i;
        }
    }

    bool isConnected(int p, int q)
    {
        return (array[p] == array[q]);
    }

    void Union(int p, int q)
    {

        int p_id = array[p];
        int q_id = array[q];

        for (int i = 0; i < N; i++)
        {
            if (array[i] == p_id)
            {
                array[i] = q_id;
            }
        }
    }

    void printArray()
    {
        for (int i = 0; i < N; i++)
        {
            std::cout << "|" << array[i];
        }
        std::cout << "|" << std::endl;
    }

    ~QuickFind()
    {
        delete array;
        array = NULL;
    }
};

class QuickUnion
{
private:
    int *array;
    int N;

public:
    QuickUnion(int n = 0) : N(n)
    {
        array = new int[n];
        for (int i = 0; i < n; i++)
        {
            array[i] = i;
        }
    }

    bool isConnected(int p, int q)
    {
        return (array[p] == array[q]);
    }

    int root(int i)
    {

        while (i != array[i])
        {
            i = array[i];
        }
        return i;
    }
    void Union(int p, int q)
    {

        int p_root = this->root(p);
        int q_root = this->root(q);

        array[p_root] = q_root;
    }

    void printArray()
    {
        for (int i = 0; i < N; i++)
        {
            std::cout << "|" << array[i];
        }
        std::cout << "|" << std::endl;
    }

    ~QuickUnion()
    {
        delete array;
        array = NULL;
    }
};

class QuickUnionFindWeighted
{
private:
    int *array;
    int *sz;
    int N;

public:
    QuickUnionFindWeighted(int n = 0) : N(n)
    {
        array = new int[n];
        sz = new int[n];

        for (int i = 0; i < n; i++)
        {
            array[i] = i;
            sz[i] = 1;
        }
    }

    bool isConnected(int p, int q)
    {
        return (array[p] == array[q]);
    }

    int root(int i)
    {

        while (i != array[i])
        {
            array[i] = array[array[i]];
            i = array[i];
        }
        return i;
    }
    void Union(int p, int q)
    {

        int p_root = this->root(p);
        int q_root = this->root(q);
        if (p_root == q_root)
        {
            return;
        }

        if (sz[p_root] < sz[q_root])
        {
            array[p_root] = q_root;
            sz[q_root] += sz[p_root];
        }
        else
        {
            array[q_root] = p_root;
            sz[p_root] += sz[q_root];
        }
    }

    void printArray()
    {
        for (int i = 0; i < N; i++)
        {
            std::cout << "|" << array[i];
        }
        std::cout << "|" << std::endl;
    }

    ~QuickUnionFindWeighted()
    {
        delete array;
        array = NULL;
    }
};

int main()
{

    // Quick Union
    QuickFind qf(10);
    qf.printArray();
    qf.Union(4, 3);
    qf.Union(3, 8);
    qf.Union(6, 5);
    qf.Union(9, 4);
    qf.Union(2, 1);
    qf.Union(5, 0);
    qf.Union(7, 2);
    qf.Union(6, 1);
    qf.Union(1, 0);
    qf.printArray();

    // Quick Find
    QuickUnion qu(10);
    qu.printArray();
    qu.Union(3, 4);
    qu.Union(4, 9);
    qu.Union(2, 3);
    qu.Union(5, 6);
    qu.printArray();

    //Quick Find Weighted
    QuickUnionFindWeighted qufw(10);
    qufw.printArray();
    qufw.Union(3, 4);
    qufw.Union(4, 9);
    qufw.Union(2, 3);
    qufw.Union(5, 6);
    qufw.printArray();

    return 0;
}
