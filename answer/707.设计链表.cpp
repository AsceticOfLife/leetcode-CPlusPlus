/*
 * @lc app=leetcode.cn id=707 lang=cpp
 *
 * [707] 设计链表
 */

// @lc code=start
class MyLinkedList {
private:
    struct Node {
        int val;
        Node *next;
        Node(int val = 0, Node *p = nullptr) : val(val), next(p) {}
    };
    int length;
    Node *head;
public:
    MyLinkedList() {
        // 初始化头结点
        length = 0;
        head = new Node;
    }
    ~MyLinkedList() {
        if (length != 0) {
            Node *temp = head->next;
            while (temp) {
                head->next = temp->next;
                delete temp;
                temp = head->next;
            }
        }

        delete head;
    }
    
    int get(int index) {
        ++index;
        // 判断是否越界
        if (index < 1 || index > length) return -1;

        int i = 1;
        Node *p = head->next;
        while (i++ < index) p = p->next;

        return p->val;
    }
    
    void addAtHead(int val) {
        // 创建新节点
        Node *temp = new Node(val, head->next);
        head->next = temp;
        length++;
    }
    
    void addAtTail(int val) {
        // 创建新节点
        Node *temp = new Node(val, nullptr);

        // 寻找尾结点
        Node *rear = head;
        while (rear->next) rear = rear->next;

        rear->next = temp;
        length++;
    }
    
    void addAtIndex(int index, int val) {
        ++index;
        if (index < 1 || index > length + 1) return;
        // 应该找到第index-1个元素
        int i = 1;
        Node *s = head;
        while (i++ < index) s = s->next;

        // 创建结点
        Node *temp = new Node(val, s->next);
        s->next = temp;
        length++;
    }
    
    void deleteAtIndex(int index) {
        ++index;
        if (index < 1 || index > length) return;

        Node *s = head;
        int i = 1;
        // 找到index-1个元素
        while (i++ < index) s = s->next;

        Node *temp = s->next;
        s->next = temp->next;
        delete temp;
        length--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
// @lc code=end
