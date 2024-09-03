#include <bits/stdc++.h>
using namespace std;
class Vector{
private:

    int *arr { nullptr };
    int size { 0 };     // user size
    int capacity { };   // actual size

    void expand_capacity(){
        capacity *= 2;
        int *arr2 = new int[capacity]{ };
        for(int i = 0; i < size; i++){
            arr2[i] = arr[i];
        }
        swap(arr,arr2);
        delete[] arr2;
    }

public:

    Vector(int size) : size(size){
        if(size < 0)
            size = 1;
        capacity = size + 10;
        arr = new int[capacity]{ };
    }

    ~Vector(){
        delete[] arr;
        arr = nullptr;
    }

    int get_size(){
        return size;
    }

    int get_front(){
        return arr[0];
    }

    int get_back(){
        return arr[size - 1];
    }

    int get(int idx){
        assert(0 <= idx && idx < size);
        return arr[idx];
    }

    void set(int idx, int val){
        assert(0 <= idx && idx < size);
        arr[idx] = val;
    }

    void print(){
        for(int i = 0; i < size; i++)
            cout << arr[i] << ' ';
        cout << '\n';
    }

    int find(int val){
        for(int i = 0; i < size; i++)
            if(arr[i] == val)
                return i;
        return -1;
    }

    int find_transposition(int val){
        for(int i = 0; i < size; i++){
            if(arr[i] == val){
                if(i != 0){
                    swap(arr[i], arr[i - 1]);
                    return i - 1;
                }
                return 0;
            }
        }
        return -1;
    }

    void push_back(int val){
        if(size == capacity)
            expand_capacity();
        arr[size++] = val;
    }

    void insert(int idx, int val){
        assert(0 <= idx && idx < size);
        if(size == capacity)
            expand_capacity();

        for(int i = size++; i > idx; i--)
            arr[i] = arr[i - 1];

        arr[idx] = val;
    }

    void right_rotate(){
        if (size <= 1)
            return;
        int last = arr[size - 1];

        for(int i = size - 1; i > 0; i--)
            arr[i] = arr[i - 1];

        arr[0] = last;
    }

    void right_rotate(int times){
        times %= size;
        while (times--)
            right_rotate();
    }

    void left_rotate(){
        if (size <= 1)
            return;
        int first = arr[0];

        for(int i = 0; i < size - 1; i++)
            arr[i] = arr[i + 1];

        arr[size - 1] = first;
    }

    int pop(int idx){
        assert(0 <= idx && idx < size);
        int val = arr[idx];
        for(int i = idx; i < size - 1; i++)
            arr[i] = arr[i + 1];
        size--;
        return val;
    }
};

int main() {
    int n = 5;
    Vector v(n);
    for (int i = 0; i < n; ++i)
        v.set(i, i);

    v.insert(0, 25);	// 25 0 1 2 3 4
    v.print();
    v.insert(5, 13);	// 25 0 1 2 3 13 4
    v.print();
    v.right_rotate();           // 4 25 0 1 2 3 13
    v.print();
    v.left_rotate();            // 25 0 1 2 3 13 4
    v.print();
    cout << v.find_transposition(13) << '\n';
    v.print();
    return 0;
}
