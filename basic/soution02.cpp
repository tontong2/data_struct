#include <iostream>
using namespace std;

void BOJ_10871(){
    int n, x; 
    std::cin >> n >> x;
    int* a = new int[n];
    for(int i=0; i< n; i++){
        std::cin >> a[i];
    }
    for(int i=0; i<n; i++){
        if(a[i] < x){
            std::cout << a[i] << " ";
        }
    }
    delete[] a;
}

void Boj_10871(){
    int n, x;
    std::cin >> n >> x;

    for (int i = 0; i < n; i++) {
    int a;
    std::cin >> a;

    if (a < x)
        std::cout << a << " ";
    }
}

// 배열 삽입 (ver1)
void insert(int idx, int num, int arr[], int &len){
    int temp1 = 0;
    int temp2 = 0;
    len += 1;
    for(int i=idx; i<len; i++){
        if(i == idx){
            temp1 = arr[i];
            arr[i] = num;
        }
        temp2 = arr[i];
        arr[i] = temp1;
        temp1 = temp2;
    }
}

// 배열 삽입 (ver 2)
// 배열 끝 부터 시작하기!!
void insert2(int idx, int num, int arr[], int &len){
    for(int i=len; i>idx; i--){
        arr[i] = arr[i-1];
    }
    arr[idx] = num;
    len++;
}

void erase(int idx, int arr[], int&len){
    len--;
    for(int i=idx; i<len; i++){
        arr[i] = arr[i+1];
    }
   
}

void printArr(int arr[], int& len){
    for(int i=0; i<len; i++){
        cout << arr[i] << ' ';
    }
            cout << "\n\n";
}


//알파벳 소문자로만 이루어진 단어 S가 주어졌을 때, 
//각 알파벳이 단어에 몇 번 등장하는지 출력하는 프로그램을 작성하시오.
void BOJ_10808(){
    int freq[26] = {0};
    string s;
    cin >> s;
    for(auto ch : s){
        freq[ch-'a']++;
    }
    for(int i=0; i<26; i++){
        cout << freq[i] << " ";
    }
    cout << "\n";
}

// 배열에서 합이 100인 서로 다른 위치의 두 원소가 존재하면 1, 아니면 0
// 시간복잡도 O(n) 으로 해결해보기
void func2(int arr[], int N){
    int numbers[101] = {0}; // 0-100까지의 배열
    for(int i=0; i<N; i++){
        int num = arr[i];
        if(arr[100-num]){
            cout << 1 << " \n";
            return;
        }
        arr[num] = 1;
    }
    cout << 0 << "\n";
}


int main(void){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
   
    int arr[5] = {1, 23, 53, 77, 60}; 
    func2(arr, 5);
    return 0;
}