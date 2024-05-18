#include <iostream>
#include <algorithm>
#include <exception>

using namespace std;

class exceptie2 : public exception {
public:
    virtual const char* what() const throw() {
        return "Indexul este inafara domeniului!";
    }
};

class Compare
{
public:
    virtual int CompareElements(void* e1, void* e2) = 0;
};
template<class T>
class ArrayIterator
{
private:
    int Current, Size; // mai adaugati si alte date si functii necesare pentru iterator
    T** CurrentPtr;
public:
    ArrayIterator()
    {
        Current = 0;
        Size = 0;
        CurrentPtr = nullptr;
    }
    ArrayIterator(T** CurrentPtr, int Current, int Size)
    {
        this->CurrentPtr = CurrentPtr;
        this->Current = Current;
        this->Size = Size;
    }
    ArrayIterator& operator ++ ()
    {
        if (Current < Size)
        {
            Current++;
            CurrentPtr++;
        }
        return (*this);
    }
    ArrayIterator& operator -- ()
    {
        if (Current > 0)
        {
            Current--;
            CurrentPtr--;
        }
        return (*this);
    }
    bool operator==(ArrayIterator<T>& other)
    {
        return Current == other.Current && CurrentPtr==other.CurrentPtr;
    }
    bool operator!=(ArrayIterator<T>& other)
    {
        return Current != other.Current || CurrentPtr!=other.CurrentPtr;
    }
    T* GetElement()
    {
        if (CurrentPtr != nullptr && Current < Size)
            return *CurrentPtr;
        return nullptr;
    }
};
template<class T>
class Array
{
private:
    T** List; // lista cu pointeri la obiecte de tipul T*
    int Capacity; // dimensiunea listei de pointeri
    int Size; // cate elemente sunt in lista
public:
    Array() :List(nullptr), Capacity(0), Size(0) {}; // Lista nu e alocata, Capacity si Size = 0
    ~Array()// destructor
    {
        int i;
        for (i = 0; i < Size; i++)
            delete List[i];
        delete[] List;
        Size = 0;
        Capacity = 0;
    }
    Array(int capacity) // Lista e alocata cu 'capacity' elemente
    {
        this->Capacity = capacity;
        Size = 0;
        List = new T * [Capacity];
    }
    Array(const Array<T>& otherArray) // constructor de copiere
    {
        int i;
        Capacity = otherArray.Capacity;
        Size = otherArray.Size;
        List = new T * [Capacity];
        for (i = 0; i < Capacity; i++)
            List[i] = otherArray.List[i];
    }

    T& operator[] (int index) // arunca exceptie daca index este out of range
    {
        try
        {
            exceptie2 e;
            if (index<0 || index>Size)
                throw e;
        }
        catch (exceptie2& e)
        {
            cout << e.what() << '\n';
        }
        return *List[index];
    }

    const Array<T>& operator+=(const T& newElem) // adauga un element de tipul T la sfarsitul listei si returneaza this
    {
        if (Size == Capacity)
        {
            Capacity+=2;
            T** temp = new T * [Capacity];
            for (int i = 0; i < Size; i++)
                temp[i] = List[i];
            delete[] List;
            List = temp;
        }
        List[Size] = new T(newElem);
        Size++;
        return *this;
    }
    const Array<T>& Insert(int index, const T& newElem) // adauga un element pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie
    {
        try
        {
            exceptie2 e;
            if (index<0 || index>Size)
                throw e;
        }
        catch(exceptie2& e)
        {
            cout << e.what() << '\n';
        }
        int i;
        if (Size == Capacity)
        {
            Capacity += 2;
            T** temp = new T*[Capacity];
            for (i = 0; i < Size; i++)
                temp[i] = List[i];
            delete[] List;
            List = temp;
        }
        for (i = Size; i > index; i--)
            List[i] = List[i - 1];
        List[index] = new T(newElem);
        Size++;
        return (*this);
    }
    const Array<T>& Insert(int index, const Array<T> otherArray) // adauga o lista pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie
    {
        try
        {
            exceptie2 e;
            if (index<0 || index>Size)
                throw e;
        }
        catch (exceptie2& e)
        {
            cout << e.what() << '\n';
        }
        int i;
        if (Size+otherArray.Size == Capacity)
        {
            Capacity =Capacity+otherArray.Size+ 2;
            T** temp = new T * [Capacity];
            for (i = 0; i < Size; i++)
                temp[i] = List[i];
            delete[] List;
            List = temp;
        }
        for (i = Size - 1; i >= index; i--)
            List[i + otherArray.Size] = List[i];
        for (i = 0; i < otherArray.Size; i++)
             List[index + i] = new T(*otherArray.List[i]);
        Size += otherArray.Size;
        return *this;
    }
    const Array<T>& Delete(int index) // sterge un element de pe pozitia index, returneaza this. Daca index e invalid arunca o exceptie
    {
        try
        {
            exceptie2 e;
            if (index<0 || index>Size)
                throw e;
        }
        catch (exceptie2& e)
        {
            cout << e.what() << '\n';
        }
        int i;
        delete List[index];
        for (i = index; i < Size; i++)
            List[i] = List[i + 1];
        Size--;
        return (*this);
    }

    bool operator==(const Array<T>& otherArray)
    {
        if (Size != otherArray.Size)
            return false;
        int i;
        for (i = 0; i < Size; i++)
            if (List[i] != otherArray.List[i])
                return false;
        return true;
    }

    bool operator=(const Array<T>& otherArray)
    {
        int i;
        if (List != nullptr)
        {
            for (i = 0; i < Size; i++)
                delete List[i];
            delete[] List;
        }
        Size = otherArray.Size;
        Capacity = otherArray.Capacity;
        List = new T * [Capacity];
        for (i = 0; i < Size; i++)
            List[i] = otherArray.List[i];
        return true;
    }

    void Sort() // sorteaza folosind comparatia intre elementele din T
    {
        sort(List, List + Size, [](T* a, T* b) { return *a < *b; });
    }
    void Sort(int(*compare)(const T&, const T&)) // sorteaza folosind o functie de comparatie
    {
        sort(List, List + Size, [compare](T* a, T* b) { return compare(*a, *b) < 0; });
    }
    void Sort(Compare* comparator) // sorteaza folosind un obiect de comparatie
    {
        if (Size <= 1) return;
        for (int i = 0; i < Size - 1; i++)
            for (int j = i + 1; j < Size; j++)
                if (comparator->CompareElements(List[i], List[j]) > 0)
                    swap(List[i], List[j]);
    }

    // functii de cautare - returneaza pozitia elementului sau -1 daca nu exista
    int BinarySearch(const T& elem) // cauta un element folosind binary search in Array
    {
        int left = 0, right = Size - 1;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (*List[mid] == elem)
                return mid;
            if (*List[mid] < elem)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return -1;
    }
    int BinarySearch(const T& elem, int(*compare)(const T&, const T&))//  cauta un element folosind binary search si o functie de comparatie
    {
        int left = 0, right = Size - 1;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            int comp = compare(*List[mid], elem);
            if (comp == 0)
                return mid;
            if (comp < 0)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return -1;
    }
    int BinarySearch(const T& elem, Compare* comparator)//  cauta un element folosind binary search si un comparator
    {
        int left = 0, right = Size - 1;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            int comp = comparator->CompareElements(List[mid], &elem);
            if (comp == 0)
                return mid;
            if (comp < 0)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return -1;
    }

    int Find(const T& elem) // cauta un element in Array
    {
        int i;
        for (i = 0; i < Size; i++)
            if (*List[i] == elem)
                return i;
        return -1;
    }
    int Find(const T& elem, int(*compare)(const T&, const T&))//  cauta un element folosind o functie de comparatie
    {
        int i;
        for (i = 0; i < Size; i++)
        {
            int comp = compare(*List[i], elem);
            if (comp==0)
                return i;
        }
        return -1;
    }
    int Find(const T& elem, Compare* comparator)//  cauta un element folosind un comparator
    {
        int i;
        for (i = 0; i < Size; i++)
            if (comparator->CompareElements(*List[i], elem) == 0)
                return i;
        return -1;
    }

    int GetSize()
    {
        return Size;
    }
    int GetCapacity()
    {
        return Capacity;
    }

    ArrayIterator<T> GetBeginIterator()
    {
        ArrayIterator<T> it(List, 0, Size);
        return it;
    }
    ArrayIterator<T> GetEndIterator()
    {
        ArrayIterator<T> it(List+Size, Size, Size);
        return it;
    }

    void afisare()
    {
        int i;
        for(i=0; i<Size; i++)
            cout << *List[i] << " ";
        cout << '\n';
    }
};

int main()
{
    Array<int> intArray(5);
    intArray += 3;
    intArray += 1;
    intArray += 2;
    intArray += 5;
    intArray += 4;

    intArray.afisare();
    cout << "Numarul 3 se afla pe pozitia: " << intArray.Find(3) << '\n';
    intArray.Sort();
    intArray.afisare();
    cout << "Numarul 3, gasit cu,,,,, cautarea binara se afla pe pozitia: " << intArray.BinarySearch(3) << '\n';

    intArray.Delete(1);
    ArrayIterator<int> it = intArray.GetBeginIterator();
    ArrayIterator<int> id = intArray.GetEndIterator();

    while (it != id)
    {
        cout << *(it.GetElement()) << " ";
        ++it;
    }
    cout << '\n';
    cout << "Numarul 3 se afla acum, dupa stergerea lui 2 pe pozitia: " << intArray.BinarySearch(3) << '\n';
    return 0;
}