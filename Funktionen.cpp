#include <iostream>
#include <string>
#include <vector>

// Aufgabe 1: Schreibe eine Funktion, die in einem String die Vokale zählt.

int cntVokale(const std::string& str) {
    int count = 0;
    for (char ch : str) {
        ch = tolower(ch);
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            count++;
        }
    }
    return count;
}

// Aufgabe 2: Implementiere den Bubble- Sort Algorithmus.

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                std::swap(arr[j], arr[j+1]);
            }
        }
    }
}

// Aufgabe 3: Implementiere eine Binärsuche.
int binarySearch(int arr[], int n, int target) {
    int left = 0;
    int right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return mid;
        }
        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1; // Element nicht gefunden
}

// Aufgabe 4: Schreibe eine Funktion mit Rückgabetyp bool, 
//            die als Argument einen Vektor von Integern übernimmt.
//            Von diesen Werten soll das Reziproke gebildet werden (z.B. 8 -> 1/8)
//            Ist der Wert 0, soll er übersprungen werden und die Rückgabe auf 
//            'False' wechseln.

bool reziproke(std::vector<float>& vec){
    bool all_done = true;
    for (auto it = vec.begin(); it != vec.end(); it++){
        if (*it > 0){
            *it = double(1)/(*it);
        }
        else{
            all_done = false;
            continue;
        }
    }

    return all_done;
};


// Aufgabe 5: Implementiere eine Matrixmultiplikation, die als Argumente zwei
//            zweidimensionale Vektoren übernimmt.
std::vector<std::vector<int>> multiplyMatrices(const std::vector<std::vector<int>>& mat1, const std::vector<std::vector<int>>& mat2) {
    int rows1 = mat1.size();
    int cols1 = mat1[0].size();
    int rows2 = mat2.size();
    int cols2 = mat2[0].size();

    // Überprüfen, ob die Matrizen multipliziert werden können
    if (cols1 != rows2) {
        throw std::invalid_argument("Die Anzahl der Spalten der ersten Matrix muss gleich der Anzahl der Zeilen der zweiten Matrix sein.");
    }
};

// Aufgabe 6: Implentiere den Heapsort- Algorithmus.

// Funktion zum Aufbauen des Heaps
void heapify(int arr[], int n, int i) {
    int largest = i; // Initialisiere das größte Element als Wurzel
    int left = 2 * i + 1; // Linkes Kind
    int right = 2 * i + 2; // Rechtes Kind

    // Wenn das linke Kind größer als die Wurzel ist
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    // Wenn das rechte Kind größer als das größte bisherige ist
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    // Wenn das größte Element nicht die Wurzel ist
    if (largest != i) {
        std::swap(arr[i], arr[largest]); // Vertausche die Wurzel mit dem größten Element
        heapify(arr, n, largest); // Rekursiver Aufruf von heapify auf dem betroffenen Unterbaum
    }
}

// Hauptfunktion für Heapsort
void heapSort(int arr[], int n) {
    // Aufbau des Max-Heaps
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // Ein Element nach dem anderen aus dem Heap entfernen
    for (int i = n - 1; i >= 0; i--) {
        std::swap(arr[0], arr[i]); // Vertausche das aktuelle Wurzelelement mit dem letzten Element
        heapify(arr, i, 0); // Rufe heapify auf dem reduzierten Heap auf
    }
}


int main() {

    // Aufgabe 1
    std::cout << "Aufgabe 1" << std::endl;
    std::string str = "Hello World";
    std::cout << "Anzahl der Vokale: " << cntVokale(str) << std::endl;

    std::cout << std::endl;

    // Aufgabe 2
    std::cout << "Aufgabe 2" << std::endl;
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr)/sizeof(arr[0]);
    bubbleSort(arr, n);
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }

    std::cout << std::endl;
    std::cout << std::endl;

    // Aufgabe 3
    std::cout << "Aufgabe 3" << std::endl;
    int arr1[] = {2, 3, 4, 10, 40};
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    int target = 10;
    int result = binarySearch(arr1, n1, target);
    if (result != -1) {
        std::cout << "Element gefunden an Index " << result << std::endl;
    } else {
        std::cout << "Element nicht gefunden" << std::endl;
    }

    std::cout << std::endl;

    // Aufgabe 4:
    std::cout << "Aufgabe 4" << std::endl;    
    std::vector<float> rezip = {1,2,5,8,6,0,4,7};
    std::vector<float> rezip1 = {1,2,5,8,6,9,4,7};   
    bool result_reziproke = reziproke(rezip);
    bool result_reziproke1 = reziproke(rezip1);

    std::cout << "Alle Elemente konnten reziproken Wert bilden: " << (result_reziproke?"Ja":"Nein") << std::endl;    

    for (auto element : rezip){
        std::cout << element << " ";
    }
    std::cout << std::endl;
    std::cout << std::endl;
    
    std::cout << "Alle Elemente konnten reziproken Wert bilden: " << (result_reziproke1?"Ja":"Nein") << std::endl;    

    for (auto element : rezip1){
        std::cout << element << " ";
    }
    std::cout << std::endl;

    // Aufgabe 5
    std::cout << "Aufgabe 5" << std::endl;
    // std::vector<std::vector<int>> mat1 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    // std::vector<std::vector<int>> mat2 = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};
    // // std::vector<std::vector<int>> result = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    // // Matrizen multiplizieren
    // std::vector<std::vector<int>> result1 = multiplyMatrices(mat1, mat2);

    // // Ergebnis ausgeben
    // for (const auto& row : result1) {
    //     for (int val : row) {
    //         std::cout << val << " ";
    //     }
    //     std::cout << std::endl;
    // };

    std::cout << std::endl;

    // Aufgabe 6
    std::cout << "Aufgabe 6" << std::endl;
    int arr2[] = {12, 11, 13, 5, 6, 7};
    int n2 = sizeof(arr2)/sizeof(arr2[0]);
    heapSort(arr2, n2);

    std::cout << "Sortiertes Array: ";
    for (int i = 0; i < n2; i++) {
        std::cout << arr2[i] << " ";
    }

    return 0;
}