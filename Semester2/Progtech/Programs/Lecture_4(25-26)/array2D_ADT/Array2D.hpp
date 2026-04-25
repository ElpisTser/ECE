#ifndef ARRAY2D_HPP
#define ARRAY2D_HPP

#include <stdexcept>

template <typename T>
class Array2D {
public:

    // -----------------------------------------------------------------------
    // INJECTED CLASS NAME
    // Inside this class body, the compiler automatically makes the bare name
    // "Array2D" mean "Array2D<T>". This is called the injected class name.
    // So inside here, writing "Array2D" and "Array2D<T>" are identical.
    // This is why Row and ConstRow can use "Array2D" in their private fields
    // without any template syntax — they are nested inside Array2D<T>'s scope
    // and the injected class name applies to them as well.
    // -----------------------------------------------------------------------

    // -----------------------------------------------------------------------
    // TWO-STEP INDEXING: arr[i][j]
    //
    // The goal is to support the natural arr[i][j] syntax, equivalent to
    // arr.select(i, j). This works as a two-step process:
    //
    //   Step 1: arr[i]
    //     Array2D::operator[](i) is called. It returns a Row object that
    //     holds a reference back to the original Array2D and the row index i.
    //
    //   Step 2: arr[i][j]
    //     operator[](j) is called on the Row object returned in step 1.
    //     This calls array2D.select(row, j) using the stored reference and
    //     row index, which ultimately retrieves the correct element.
    //
    // ConstRow works identically but is used when the Array2D object is
    // const, ensuring the returned reference is also const and the original
    // array cannot be modified through it.
    // -----------------------------------------------------------------------

    class Row {
    public:
        Row(Array2D& a, int i) : array2D(a), row(i) {}
        //       ^^^^^^^
        // "Array2D" here means "Array2D<T>" thanks to the injected class name.
        // Writing "Array2D<T>& a" would also be valid and mean the same thing.

        T& operator[](int i) const {
            return array2D.select(row, i);
        }
        
    private:
        Array2D &array2D;
        //^^^^^^^
        // Again, bare "Array2D" is valid here because we are still inside
        // Array2D<T>'s scope. The injected class name is in effect.
        int row;
    };

    class ConstRow {
    public:
        ConstRow(const Array2D& a, int i) : array2D(a), row(i) {}

        const T& operator[](int i) const {
            return array2D.select(row, i);
        }
    private:
        const Array2D& array2D;
        // Same as above — "Array2D" means "Array2D<T>" inside this scope.
        int row;
    };

    // Default values for n, m, bi, bj allow constructing an empty Array2D.
    // bi and bj are the base (starting) indices — they don't have to be 0.
    // For example, Array2D<int>(3, 3, 1, 1) creates a 3x3 array whose
    // valid indices start at 1 instead of 0.
    
    Array2D(unsigned n = 0, unsigned m = 0, int bi = 0, int bj = 0);
    Array2D(const Array2D& a);
    ~Array2D();

    Array2D& operator=(const Array2D& a);


    // select() is the core element accessor. It calls loc() internally,
    // so it will throw std::out_of_range if i or j are invalid.
    // Inside the class body, "Row" and "ConstRow" are found directly in the
    // current scope, so no qualification or typename is needed here.
    T& select(int i, int j);
    const T& select(int i, int j) const;

    Row operator[](int i);
    ConstRow operator[](int i) const;
private:
    T* data;
    int baseRow, baseCol;
    unsigned numRows, numCols;

    // loc() computes the flat array index for logical position (i, j),
    // accounting for the base offsets. It throws std::out_of_range if
    // the indices fall outside the valid range.
    unsigned loc(int i, int j) const;
};

// ---------------------------------------------------------------------------
// OUT-OF-CLASS DEFINITIONS
//
// Every function definition outside the class body requires:
//
//   1. template<typename T>
//      Reintroduces T as the type parameter for this definition.
//      Without this, T would be an unknown identifier.
//
//   2. Array2D<T>::
//      Qualifies which class this function belongs to.
//      We are no longer inside the class body, so the injected class name
//      is gone — we must write Array2D<T> explicitly every time.
// ---------------------------------------------------------------------------

template<typename T>
Array2D<T>::Array2D(unsigned n, unsigned m, int bi, int bj)
    : data(new T[n * m]), baseRow(bi), baseCol(bj), numRows(n), numCols(m) {}

template<typename T>
Array2D<T>::Array2D(const Array2D& a)
    : data(new T[a.numRows * a.numCols]),
      baseRow(a.baseRow),
      baseCol(a.baseCol),
      numRows(a.numRows),
      numCols(a.numCols) {
    for (int i = 0; i < numRows * numCols; i++) {
        data[i] = a.data[i];
    }
}

template<typename T>
Array2D<T>::~Array2D() {
    delete[] data;
}

template<typename T>
Array2D<T>& Array2D<T>::operator=(const Array2D& a) {
    // Guard against self-assignment (e.g. arr = arr), which would delete
    // data before copying it, causing undefined behaviour.
    if (this == &a)
        return *this;
    delete[] data;
    baseRow = a.baseRow;
    baseCol = a.baseCol;
    numRows = a.numRows;
    numCols = a.numCols;
    data = new T[numRows * numCols];
    for (int i = 0; i < numRows * numCols; i++) 
        data[i] = a.data[i];
    return *this;
}

template <typename T>
unsigned Array2D<T>::loc(int i, int j) const {
    // Compute offsets relative to the base indices.
    // If baseRow is 1 and i is 1, di is 0 — the first valid row.
    int di = i - baseRow;
    int dj = j - baseCol;
    if (di < 0 || unsigned(di) >= numRows ||
        dj < 0 || unsigned(dj) >= numCols)
        throw std::out_of_range("invalid index");
    return di * numCols + dj;
}

template <typename T>
T& Array2D<T>::select(int i, int j) {
    return data[loc(i, j)];
}

template <typename T>
const T& Array2D<T>::select(int i, int j) const {
    return data[loc(i, j)];
}

// ---------------------------------------------------------------------------
// THE typename KEYWORD
//
// The return type here is "Array2D<T>::Row". Because we are in a template and
// T is not yet known, the compiler cannot look inside Array2D<T> to check
// what Row actually is. It might be a nested type (as it is here), but a
// template specialization like Array2D<SomeType> could theoretically define
// Row as a static variable instead. The compiler cannot rule that out.
//
// Faced with this ambiguity, C++ defaults to assuming that anything after
// "::" is a VALUE, not a type. So without typename, the compiler would
// misparse the return type and produce an error.
//
// Writing "typename Array2D<T>::Row" is your explicit instruction:
// "whatever T turns out to be, treat Array2D<T>::Row as a TYPE".
//
// Note that this is a separate concern from template<typename T> above.
// That line tells the compiler what T is (a type parameter).
// The typename here tells the compiler what Array2D<T>::Row is (a type).
// They answer two different questions.
// ---------------------------------------------------------------------------

template<typename T>
typename Array2D<T>::Row Array2D<T>::operator[](int i) {
    // Inside this function body we are considered "inside" Array2D<T>'s scope
    // again, so we can refer to Row directly without any qualification.
    return Row(*this, i);
}

template<typename T>
typename Array2D<T>::ConstRow Array2D<T>::operator[](int i) const {
    return ConstRow(*this, i);
}

#endif