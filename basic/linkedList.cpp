#include <iostream>

using namespace std;

// 노드 만들기
struct Node{
    int data; // 값 저장
    Node* next; // 다음 노드를 가리키는 포인터
};

// 임의의 위치에 값 추가하기
void push_back(Node* place, int value){
    Node* temp = new Node;
    Node* current = place;
    temp->data = value;
    temp->next = nullptr;
    while(current->next != nullptr){
        current = current->next;
    }
    current->next = temp;
}

// 맨 앞에 추가하기
void push_front(Node*&head, int value){
    Node* temp = new Node;
    temp->data = value;
    temp->next = head;
    head = temp;
}

void delete_value(Node*&head, int value){
    // head를 지운다면
    if(head != nullptr && head->data == value){
        Node* toDelete = head;
        head = head->next;
        delete toDelete;
        return;
    }
    // 중간/끝 삭제
    Node* prev = head;
    Node* current = head->next;
    while( current != nullptr && current->data != value){
        prev = current;
        current = current->next;
    }

    // 만약 위 루프에서 값을 못찾고 반복문을 탈출 했다면, current == nullptr;
    // 그때 current->data 로 접근하면 에러가 발생
    // 따라서 먼저 리스트에 삭제할 값이 없는지 체크 먼저 해야함

    if(current == nullptr){
        cout << "리스트에 값이 없음" << "\n";
    }else{
        prev->next = current->next;
        delete current;
    }
}

int main(void){

    Node* newNode = new Node;
    newNode->data = 10;
    newNode->next = nullptr;

    // 노드 두개 연결하기
    Node* secondNode = new Node; 
    secondNode->data = 20;
    secondNode->next = nullptr;
    newNode->next = secondNode;

    // 노드끼리 연결되면 이런식으로도 접근이 가능해짐
    //cout << newNode->next->data << " ";

    // 만약 이제 노드가 100개 정도 된다면, 100개를 하나씩 다 만들수는 없으니,
    // 리스트의 첫번쨰 노드 주소만 변수 하나로 기억한다. 이 변수를 보통 Head라고 부름.

    Node* head = newNode;
    Node* current = head;

    // 자동으로 노드 만들기
    push_back(current, 30);
    push_back(current, 40);
    push_front(head, 5);
    

    current = head;
    while(current != nullptr){
        cout << current->data << " \n";
        current = current->next;
    }

    cout << "삭제 연산 후 " << "\n";
    delete_value(head, 30);

    current = head;
    while(current != nullptr){
        cout << current->data << " \n";
        current = current->next;
    }

    
    return 0;
}