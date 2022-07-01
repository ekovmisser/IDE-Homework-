#include <iostream>
#include <fstream>

int main(int argc, char** argv)
{
    std::ifstream fin("in.txt");
    std::ofstream fout("out.txt");
    if (fin.is_open()) {
        std::cout << "It turned out to open the file!" << std::endl;
        std::cout << "Array updated!" << std::endl;
        // Служебные сообщения об успешном открытии файла
        int size1 = 0;
        fin >> size1;
        int* dinamich_array = new int[size1];
        for (int i = 0; i < size1; i++) {
            fin >> dinamich_array[i];
        }
        // Чтение 1-го одномерного динамического массива
        for (int i = 0; i < size1 - 1; i++)
        {
            int temp;
            temp = dinamich_array[i];
            dinamich_array[i] = dinamich_array[i + 1];
            dinamich_array[i + 1] = temp;
        }
        // Сортировка 1-го одномерного динамического массива
        int size2 = 0;
        fin >> size2;
        int* dinamich_array2 = new int[size2];
        for (int i = 0; i < size2; i++) {
            fin >> dinamich_array2[i];
        }
        // Чтение 2-го одномерного динамического массива
        int last, temp;
        last = dinamich_array2[size2 - 1];
        for (int i = size2 - 1; i > 0; i--) {
            temp = dinamich_array2[i - 1];
            dinamich_array2[i - 1] = dinamich_array2[i];
            dinamich_array2[i] = temp;
        }
        dinamich_array2[0] = last;
        // Сортировка 2-го динамического массива
        fout << size2 << std::endl;
        for (int i = 0; i < size2; i++) {
            fout << dinamich_array2[i] << " ";
        }
        fout << std::endl;
        // Запись 2-го динамического массива
        fout << size1 << std::endl;
        for (int i = 0; i < size1; i++) {
            fout << dinamich_array[i] << " ";
        }
        fout << std::endl;
        // Запись 1-го динамического массива
        delete[] dinamich_array;
        delete[] dinamich_array2;
        // Удаление 2-х динамических массивов
        dinamich_array = nullptr;
        dinamich_array2 = nullptr;
    } else {
            std::cout << "Couldn't open the file!" << std::endl;
        }
        fin.close(); // Закрытие файла на чтение
        fout.close(); // Закрытие файла на запись
        return 0;
    }