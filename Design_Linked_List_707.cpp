class Node{
public:
    int val;
    Node* next;

    Node(int val){
      this->val = val;
      this->next = NULL;
    }
};
class MyLinkedList {
public:
    int size;
    Node* head;
    Node* tail;

    MyLinkedList() {
        size = 0;
        head = NULL;
        tail = NULL;
    }
    
    int get(int index) {
        if(index<0 || index > size-1){
            return -1;
        }

        Node* temp = head;
        for(int i = 0; i<index; i++){
            temp = temp->next;
        }

        return temp->val;
    }
    
    void addAtHead(int val) {
        Node* newNode = new Node(val);
        size++;
        if(head == NULL){
            head = newNode;
            tail = newNode;
            return;
        }

        newNode->next = head;
        head = newNode;
    }
    
    void addAtTail(int val) {
        Node* newNode = new Node(val);
        size++;
        if(head == NULL){
            head = newNode;
            tail = newNode;
            return;
        }

        tail->next = newNode;
        tail = newNode;
        
    }
    
    void addAtIndex(int index, int val) {
        if(index<0 || index>size){
            return;
        }

        if(index == 0){
            addAtHead(val);
            return;
        }
        if(index == size){
            addAtTail(val);
            return;
        }

        Node* temp = head;
        for(int i = 1; i<index; i++){
            temp = temp->next;
        }
        Node* newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
        size++;

    }
    
    void deleteAtIndex(int index) {
        if(index<0 || index>size-1){
            return;
        }
        if(index == 0){
            Node* del = head;
            head = head->next;
            delete del;

            if(head == NULL){
                tail = NULL;
            }
            size--;
            return;
        }
        
        Node* temp = head;
        for(int i = 1; i<index;i++){
            temp = temp->next;
        }
        Node* del = temp->next;
        temp->next = del->next;
        if(del == tail){
            tail = temp;
        }
        delete del;
        size--;
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