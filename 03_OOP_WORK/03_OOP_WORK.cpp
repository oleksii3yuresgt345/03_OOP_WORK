#include <iostream>
using namespace std;

class Array
{
    long* arr;
    int size;
public:
    Array()
    {
        size = 3;
        arr = new long[size] {1, 2, 3};
    }
    Array(int size)
    {
        this->size = size;
        arr = new long[size] {};
    }

    void FillRandom()
    {
        srand(time(0));
        long* temp = new long[size];
        for (int i = 0; i < size; i++)
        {
            temp[i] = rand() % 100;
        }
        delete[]arr;
        arr = temp;
    }

    void FillUser()
    {
        int num = 0;
        for (int i = 0; i < size; i++)
        {
            cout << "Enter " << i << " of array : "; cin >> num;
            arr[i] = num;
        }
    }

    void Add()
    {
        int num;
        cout << "Enter number to add : "; cin >> num;
        long* temp = new long[size + 1];
        for (int i = 0; i < size; i++)
        {
            temp[i] = arr[i];
        }
        temp[size] = num;
        delete[]arr;
        arr = temp;
        size++;
    }

    void Delete() //to dooooooooooooo
    {
        int choice;
        cout << "By what to delete in array?\n0 - by number\n1 - by number's index\nEnter : "; cin >> choice;
        if (choice == 0)
        {
            int number;
            cout << "What number do you want to delete?\nEnter : "; cin >> number;
            int index;

            for (int i = 0; i < size; i++)
            {
                if (arr[i] == number)
                    index = i;
            }

            long* temp = new long[size - 1];
            for (int i = 0; i < index; i++)
            {
                temp[i] = arr[i];
            }
            for (int i = index; i < size; i++)
            {
                temp[i] = arr[i+1];
            }
            delete[]arr;
            arr = temp;
            size--;

        }
        else if (choice == 1)
        {
            int index;
            cout << "Enter index : "; cin >> index;
            long* temp = new long[size - 1];
            for (int i = 0; i < index; i++)
            {
                temp[i] = arr[i];
            }
            for (int i = index; i < size; i++)
            {
                temp[i] = arr[i+1];
            }
            delete[]arr;
            arr = temp;
            size--;
        }
        else
            cout << "Error" << endl;
    }

    void Show()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    ~Array()
    {
        if (arr != nullptr)
            delete[]arr;
    }
};

int main()
{
    Array list;
    list.Show();

    Array list2(5);
    //list2.FillUser();
    //list2.Show();
    list2.FillRandom();
    list2.Show();
    list2.Add();
    list2.Show();
    list2.Delete();
    list2.Show();
    list2.Delete();
    list2.Show();
}