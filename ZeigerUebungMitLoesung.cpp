#include <iostream>
#include <vector>
#include <map>

class A{

    public:
    A(){
        std::cout << "Ich bin geboren." << std::endl;
    }

    ~A(){
        std::cout << "Ich bin gestorben." << std::endl;        
    }
};

int main() {

    char a = 'a';
    char* ptr_a = &a;
    std::cout << sizeof(a) << std::endl;
    std::cout << sizeof(ptr_a) << std::endl;

    std::cout << std::endl;

    int array[] = {1,2,3,4,5};
    int* array_ptr = array;
    std::cout << *array_ptr << std::endl;
    for(int i = 0; i < 5; i++){
        std::cout << *array_ptr << " ";
        array_ptr++;
    }

    std::cout << std::endl;

    std::cout << *array_ptr << std::endl;
    array_ptr--;
    std::cout << *array_ptr << std::endl;

    std::cout << std::endl;

    {
    A a_objekt;
    }

    std::cout << std::endl;

    A* a_objekt2 = new A();

    // delete a_objekt2; 

    std::cout << std::endl;

//  Aufgabe 1: Erstelle ein Array von 5 ganzen Zahlen auf dem Stack und durchlaufe es mit einem rohen Zeiger.
//             Lege das Array nun auf den Heap und beachte das Speichermanagement.

    int arr[5] = {1, 2, 3, 4, 5};
    int* ptr = arr;

    for (int i = 0; i < 5; ++i) {
        std::cout << *(ptr + i) << " ";
    }
    std::cout << std::endl;


    int* arr1 = new int[5]{1, 2, 3, 4, 5};
    ptr = arr1;

    for (int i = 0; i < 5; ++i) {
        std::cout << *(ptr + i) << " ";
    }
    std::cout << std::endl;

    delete[] arr1;


//  Aufgabe 2: Erstelle einen Vektor auf dem Stack und durchlaufe ihn mit einem Iterator.
//             Lege den Vector nun auf den Heap, durchlaufe ihn mit dem Iterator und
//             beachte das Speichermanagement.

    std::vector<int> vec = {1, 2, 3, 4, 5};
    std::vector<int>::iterator vec_it;

    std::cout << "Vektor auf Stack" << std::endl;

    for (vec_it = vec.begin(); vec_it != vec.end(); vec_it++) {
        std::cout << *vec_it << " ";
    }
    std::cout << std::endl;


    std::vector<int>* vec1 = new std::vector<int>{1, 2, 3, 4, 5};

    std::cout << "Vektor auf dem Heap" << std::endl;

    for (vec_it = vec1->begin(); vec_it != vec1->end(); ++vec_it) {
        std::cout << *vec_it << " ";
    }

    std::cout << std::endl;

    delete vec1;

    std::cout << std::endl;

//  Aufgabe 3: Erstelle eine Map auf dem Stack und durchlaufe sie mit einem Iterator.
//             Lege die Map nun auf den Heap, durchlaufe sie mit dem Iterator und
//             beachte das Speichermanagement.


    std::map<int, std::string> mp = {{1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"}};
    std::map<int, std::string>::iterator map_it;

    for (map_it = mp.begin(); map_it != mp.end(); ++map_it) {
        std::cout << map_it->first << ": " << map_it->second << std::endl;
    }
        std::cout << std::endl;


    std::map<int, std::string>* mp1 = new std::map<int, std::string>{{1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"}};

    for (map_it = mp1->begin(); map_it != mp1->end(); ++map_it) {
        std::cout << map_it->first << ": " << map_it->second << std::endl;
    }

    delete mp1;

    std::cout << std::endl;


//  Aufgabe 4: Erstelle ein zweidimensionales Array auf dem Stack und durchlaufe es
//             mit einem rohen Zeiger. Lege es anschließend vollständig(!) auf den Heap
//             und beachte das Speichermanagement.

    int arr2[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int (*ptr_arr2)[3] = arr2;

    std::cout << "Zweidimensionales Array auf Stack" << std::endl;

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cout << ptr_arr2[i][j] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;

    int** arr3 = new int*[3];
    for (int i = 0; i < 3; ++i) {
        arr3[i] = new int[3];
    }

    int value = 1;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            arr3[i][j] = value++;
        }
    }

    std::cout << "Zweidimensionales Array auf dem Heap" << std::endl;

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cout << arr3[i][j] << " ";
        }
        std::cout << std::endl;
    }

    for (int i = 0; i < 3; ++i) {
        delete[] arr3[i];
    }
    delete[] arr3;

    std::cout << std::endl;

//  Aufgabe 5: Das Ganze nochmal mit einem dreidimensionalen Array. ;)

    int arr4[2][2][2] = {{{1, 2}, {3, 4}}, {{5, 6}, {7, 8}}};
    int (*ptr_arr4)[2][2] = arr4;

    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < 2; ++k) {
                std::cout << ptr_arr4[i][j][k] << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;

    int*** arr5 = new int**[2];
    for (int i = 0; i < 2; ++i) {
        arr5[i] = new int*[2];
        for (int j = 0; j < 2; ++j) {
            arr5[i][j] = new int[2];
        }
    }

    int value2 = 1;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < 2; ++k) {
                arr5[i][j][k] = value2++;
            }
        }
    }

    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < 2; ++k) {
                std::cout << arr5[i][j][k] << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }

    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            delete[] arr5[i][j];
        }
        delete[] arr5[i];
    }
    delete[] arr5;

    std::cout << std::endl;

// Aufgabe 6: Erstelle einen zweidimensionalen Vektors auf dem Heap, fülle ihn mit Werten von 1 bis 9, 
//            gebe ihn aus und beachte das Speichermanagement.


    std::vector<std::vector<int>>* vec3 = new std::vector<std::vector<int>>(3, std::vector<int>(3));

    int value1 = 1;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            (*vec3)[i][j] = value1++;
        }
    }


    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cout << (*vec3)[i][j] << " ";
        }
        std::cout << std::endl;
    }

    delete vec3;

    return 0;
}
