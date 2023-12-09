#include <iostream>
#include <exception>
class smart_array {
private:
    int* arr;
    int logic_size;
    int phys_size;
    smart_array() {};
public:
    smart_array(const smart_array&) = delete;
    smart_array& operator=(const smart_array&) = delete;
    //конструктор
    smart_array(int size) {
        arr = new int[size];//создает динам массив
        logic_size = 0;//при создании не будет элементов в массиве(поэтому 0)
        phys_size = size;//фактический размер массива
    }
    //добавляет элемент в массив
    void add_element(int number) {
        logic_size++;
        if (logic_size > phys_size) {
            throw std::out_of_range("Превышено допустимое количество элементов массива!");
        }
        arr[logic_size - 1] = number;
    }
    //возвращает элемент по индексу
    int get_element(int num) {
        if (num > logic_size || num < 0) {
            throw std::out_of_range("Указанный индекс вне зоны массива!");
        }
        return arr[num];
    }
    ~smart_array() {
        delete[] arr;
    }
};
int main() {
    try {
        smart_array arr(5);
        arr.add_element(1);
        arr.add_element(4);
        arr.add_element(155);
        arr.add_element(14);
        arr.add_element(15);
        //arr.add_element(15);
        std::cout << arr.get_element(1) << std::endl;

        //smart_array arr2 = arr;
        //smart_array arr3(arr);
    }
    catch (const std::exception& ex) {
        std::cout << ex.what() << std::endl;
    }
    return 0;
}