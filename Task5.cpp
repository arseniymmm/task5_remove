#include <iostream>
#include <iomanip>

using namespace std;
struct bin_tree
{
    int weight;
    int id;
    struct bin_tree* left;
    struct bin_tree* right;
};

bin_tree* head = NULL;

void push(bin_tree*& head, int x, int w)
{
    if (!head)
    {
        bin_tree* t = new bin_tree;
        t->weight = w;
        t->id = x;
        t->left = NULL;
        t->right = NULL;
        head = t;
    }
    else
    {
        if (x < head->id)
            push(head->left, x, w);
        else
            push(head->right, x, w);
    }
}

void print(bin_tree*& head, int n)
{
    if (head != NULL)
    {
        print(head->left, n + 1);
        cout << setw(n * 3) << head->id << '(' << head->weight << ')' << endl;
        print(head->right, n + 1);
    }
}

bin_tree* del(bin_tree*& head, int x)
{
    bin_tree* P, * v;
    if (!head) cout << "takogo net" << endl;
    else if (x < head->id) head->left = del(head->left, x);
    else if (x > head->id) head->right = del(head->right, x);
    else {
        P = head;
        if (!head->right) head = head->left;
        else if (!head->left) head = head->right;
        else {
            v = head->left;
            if (v->right)
            {
                while (v->right->right)
                    v = v->right;
                head->id = v->right->id;
                head->weight = v->right->weight;
                P = v->right; v->right = v->right->left;
            }
            else
            {
                head->id = v->id;
                head->weight = v->weight;
                P = v;
                head->left = head->left->left;
            }
        }
    }
    return head;
}

void printGivenLevel(bin_tree* root, int level, int weight)
{
    if (root == NULL)
        return;
    if (level == 1) {
        if (root->weight == weight)
            cout << root->id << " ";
    }
    else if (level > 1)
    {
        printGivenLevel(root->left, level - 1, weight);
        printGivenLevel(root->right, level - 1, weight);
    }
}



void menu() {
    std::cout << "1 - dobavit'" << std::endl;
    std::cout << "2 - udalit'" << std::endl;
    std::cout << "3 - napechatat'" << std::endl;
    std::cout << "4 - Vivod vershini opred. urodnya i vesa" << std::endl;
    std::cout << "0 - viyti" << std::endl;
}

int main()
{
    push(head, 6, 1);
    push(head, 3, 0);
    push(head, 2, -1);
    push(head, 7, -1);
    push(head, 5, 1);
    push(head, 9, 0);
    push(head, 1, -1);
    push(head, 11, -1);
    push(head, 14, 0);
    int action, w, x, level,weight, s; s = 0;
    while (true) {
        menu();
        int action;
        std::cin >> action;
        switch (action) {
        case(1):
            std::cout << "dobavit':" << std::endl;
            cin >> x;
            cin >> w;
            push(head, x, w);
            break;
        case(2):
            std::cout << "udalit'" << std::endl;
            cin >> x;
            del(head, x);
            break;
        case(3):
            print(head, 1);
            break;
        case(4):
            std::cout << "Level':" << std::endl;
            cin >> level;
            std::cout << "weight:" << std::endl;
            cin >> weight;
            printGivenLevel(head, level, weight);
            std::cout << "\n" << std::endl;
            break;
        case(0):
            return 0;
        
        }
    }
}