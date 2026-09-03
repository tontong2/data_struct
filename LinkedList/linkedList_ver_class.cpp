#include <iostream>
using namespace std;

// 노드 정의는 클래스 밖에 그대로 둬도 되고, 클래스 안에 넣어도 됩니다.
struct Node {
    int data;
    Node* next;
};

class LinkedList {
private:
    // 외부에서 건들이지 말 것
    Node* head;   // 더 이상 매개변수로 돌아다니지 않고, 클래스가 직접 소유

public:
    // 외부에서 써야 하는 것들 (인터페이스)
    // 생성자: 객체가 만들어질 때 자동 실행 -> 빈 리스트로 시작
    LinkedList() {
        head = nullptr;
    }

    // 소멸자: 객체가 사라질 때 자동 실행 -> 남은 노드들 메모리 정리
    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* toDelete = current;
            current = current->next;
            delete toDelete;
        }
    }

    // 맨 뒤에 삽입
    void push_back(int value) {
        Node* temp = new Node;
        temp->data = value;
        temp->next = nullptr;

        if (head == nullptr) {          // 빈 리스트일 때는 head 자체가 새 노드
            head = temp;
            return;
        }

        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = temp;
    }

    // 맨 앞에 삽입 (참조 & 필요 없음 - head가 이미 이 객체 소속)
    void push_front(int value) {
        Node* temp = new Node;
        temp->data = value;
        temp->next = head;
        head = temp;
    }

    // 값으로 삭제
    void delete_value(int value) {
        if (head != nullptr && head->data == value) {
            Node* toDelete = head;
            head = head->next;
            delete toDelete;
            return;
        }

        Node* prev = head;
        Node* current = (head == nullptr) ? nullptr : head->next;

        while (current != nullptr && current->data != value) {
            prev = current;
            current = current->next;
        }

        if (current == nullptr) {
            cout << "리스트에 값이 없음\n";
        } else {
            prev->next = current->next;
            delete current;
        }
    }

    // 전체 출력
    void print() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << "\n";
    }
};

int main(void) {
    LinkedList list;   // head가 자동으로 nullptr로 초기화됨 (생성자 덕분)

    list.push_back(10);
    list.push_back(20);
    list.push_back(30);
    list.push_back(40);
    list.push_front(5);

    cout << "초기: ";
    list.print();

    list.delete_value(30);
    cout << "30 삭제 후: ";
    list.print();

    list.delete_value(5);
    cout << "5(head) 삭제 후: ";
    list.print();

    list.delete_value(999);
    cout << "999(없는값) 시도 후: ";
    list.print();

    return 0;
    // list가 여기서 스코프를 벗어나면서 소멸자가 자동 호출 -> 남은 노드 메모리 정리
}