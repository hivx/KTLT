#include <iostream>

struct Node {
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        next = NULL;
    }
};

// Thêm một phần tử mới vào đầu danh sách
Node* prepend(Node* head, int data) {
    Node* temp = new Node(data);
    temp->next = head;
    return temp;
}

// In nội dung danh sách liên kết
void print(Node* head) {
    while (head) {
        std::cout << head->data << " ";
        head = head->next; // Di chuyển đến phần tử tiếp theo
    }
    std::cout << std::endl;
}

// Đảo ngược danh sách liên kết và trả về head mới
Node* reverse(Node* head) {
    Node* prev = NULL;
    Node* next = NULL;

    while (head) {
        next = head->next; // Lưu lại nút tiếp theo
        head->next = prev; // Đảo chiều liên kết
        prev = head;       // Di chuyển prev lên head hiện tại
        head = next;       // Di chuyển head đến nút tiếp theo
    }

    return prev; // Trả về head mới của danh sách
}

int main() {
    int n, u;

    std::cin >> n;

    Node* head = NULL;

    for (int i = 0; i < n; ++i) {
        std::cin >> u;
        head = prepend(head, u); // Gán lại head sau khi thêm phần tử
    }

    std::cout << "Original list: ";
    print(head);

    head = reverse(head); // Đảo ngược danh sách

    std::cout << "Reversed list: ";
    print(head);

    return 0;
}
