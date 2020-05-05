#include <string>
using namespace std;

struct Node{
    string ssn;
    string name;
    Node* succ;
    Node* pred;
};

class DLL{
    private:
    Node* headPtr;
    int itemCount;
    
    public:
    DLL();
    DLL(DLL& n);
    virtual ~DLL();
    Node* getHeadPtr();
    int search(string ss) const;
    bool insert(string ss, string name, int & count);
    bool remove(string ss, int & count);
    int size();
    void display();
};