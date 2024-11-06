#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class OrderedVecInt {
private:
    int capacity = 0; // 동적 배열의 길이
    int size_ = 0; // 저장된 정수 개수
    int *arr = nullptr; // 동적 배열의 시작 주소

    // 배열 크기를 늘리는 함수
    void expand() {
        int newCapacity = (capacity == 0) ? 1 : capacity * 2; // 용량 두 배로 증가
        int *newArr = new int[newCapacity]; // 새로운 배열 할당

        // 기존 데이터 복사
        for (int i = 0; i < size_; ++i) {
            newArr[i] = arr[i];
        }

        // 이전 배열 해제 및 포인터 업데이트
        delete[] arr;
        arr = newArr;
        capacity = newCapacity;
    }

public:
    // 생성자
    OrderedVecInt() {}

    // 소멸자
    ~OrderedVecInt() {
        delete[] arr;
    }

    // 정수 삽입 함수
    void insert(int num) {
        if (size_ == capacity) { // 배열 크기가 부족할 경우 확장
            expand();
        }

        // 정렬된 위치에 삽입
        int index = 0;
        while (index < size_ && arr[index] < num) {
            ++index;
        }

        // 뒤로 한 칸씩 밀고 삽입
        for (int i = size_; i > index; --i) {
            arr[i] = arr[i - 1];
        }
        arr[index] = num;
        ++size_;
    }

    // 정수 삭제 함수 (값에 의한 삭제)
    bool remove_by_val(int num) {
        int index = 0;
        while (index < size_ && arr[index] != num) {
            ++index;
        }

        if (index == size_) { // 값이 없음
            return false;
        }

        // 뒤로 한 칸씩 당기고 크기 감소
        for (int i = index; i < size_ - 1; ++i) {
            arr[i] = arr[i + 1];
        }
        --size_;
        return true;
    }

    // 정수 삭제 함수 (인덱스에 의한 삭제)
    bool remove_by_index(int index) {
        if (index < 0 || index >= size_) { // 유효하지 않은 인덱스
            return false;
        }

        // 뒤로 한 칸씩 당기고 크기 감소
        for (int i = index; i < size_ - 1; ++i) {
            arr[i] = arr[i + 1];
        }
        --size_;
        return true;
    }

    // 인덱스에 해당하는 정수 반환
    int& operator[](int index) {
        return arr[index];
    }

    // 저장된 정수 개수 반환
    int size() const {
        return size_;
    }
};

int main() {
    srand((unsigned int)time(NULL));
    int n;
    OrderedVecInt vec;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int k = rand() % 1000;
        vec.insert(k);
    }

    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << endl;

    if (vec.remove_by_val(vec[2])) {
        cout << "Remove done" << endl;
    } else {
        cout << "Remove failed" << endl;
    }

    if (vec.remove_by_index(4)) {
        cout << "RemoveIndex done" << endl;
    } else {
        cout << "RemoveIndex failed" << endl;
    }

    for (int i = 0; i < vec.size(); i++) {
        vec[i] -= 10;
    }

    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << endl;

    return 0;
}
