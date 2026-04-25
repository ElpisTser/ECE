#include <iostream>
#include <stdexcept>
#include <iomanip>

class ChessBoardArray {
protected:
    class Row {
    public:
        Row(ChessBoardArray& a, int i) : chessBoardArray(a), row(i) {}
        
        int& operator[](int j) {
            return chessBoardArray.select(row, j);
        }

    private:
        ChessBoardArray& chessBoardArray;
        int row;
    };

    class ConstRow {
    public:
        ConstRow(const ChessBoardArray& a, int i) : chessBoardArray(a), row(i) {}

        int operator[](int j) const {
            return chessBoardArray.select(row, j);
        }

    private:
        const ChessBoardArray& chessBoardArray;
        int row;
    };

public:
    ChessBoardArray(unsigned size = 0, unsigned base = 0);
    ChessBoardArray(const ChessBoardArray& a);
    ~ChessBoardArray();

    ChessBoardArray & operator=(const ChessBoardArray &a);

    int& select(int i, int j);
    int select(int i, int j) const;

    Row operator[](int i);
    const ConstRow operator[](int i) const;

    friend std::ostream& operator<<(std::ostream& out, const ChessBoardArray& a);

private:
    int* data;
    unsigned base;
    unsigned size;
    unsigned length;

    // Returns the flat array index for chessboard position (i, j).
    // Throws std::out_of_range if (i, j) is out of bounds or on a black square.
    unsigned loc(int i, int j) const;

    // Returns the number of white squares in an n×n chessboard.
    static unsigned whiteSquareCount(unsigned n);
};

// --- Static helper ---------------------------------------------------------

unsigned ChessBoardArray::whiteSquareCount(unsigned n) {
    if (n % 2 == 0)
        return (n / 2) * n;
    else
        return (n / 2 + 1) * (n / 2 + 1) + (n / 2) * (n / 2);
}

// --- Constructors / destructor ---------------------------------------------

ChessBoardArray::ChessBoardArray(unsigned size, unsigned base)
    : size(size), base(base), length(whiteSquareCount(size))
{
    data = new int[length](); // () zero-initialises the array
}

ChessBoardArray::ChessBoardArray(const ChessBoardArray &a)
    : size(a.size), base(a.base), length(a.length) 
{
    data = new int[length];
    for (unsigned i = 0; i < length; i++) {
        data[i] = a.data[i];
    }
}

ChessBoardArray::~ChessBoardArray() {
    delete[] data;
}

// --- Assignment ------------------------------------------------------------

ChessBoardArray & ChessBoardArray::operator=(const ChessBoardArray &a) {
    if (this == &a)
        return *this;

    delete[] data;
    base = a.base;
    size = a.size;
    length = a.length;
    data = new int[length];
    for (unsigned i = 0; i < length; i++)
        data[i] = a.data[i]; 
    return *this;       
}


// --- Index mapping ---------------------------------------------------------

unsigned ChessBoardArray::loc(int i, int j) const {
    // Translate to 1-based coordinates regardless of the user-chosen base.
    int bi = i - static_cast<int>(base) + 1;
    int bj = j - static_cast<int>(base) + 1;

    if (bi < 1 || bi > static_cast<int>(size) ||
        bj < 1 || bj > static_cast<int>(size) ||
        (bi + bj) % 2 != 0) 
        throw std::out_of_range("ChessBoardArray: index out of range or on black square");

    unsigned location;

    if (size % 2 == 1) {
        // Odd-sized board: odd rows have (size/2 + 1) white squares,
        //                  even rows have (size/2) white squares.
        if (bi % 2 == 1) 
            location = (size/2 + 1) * (bi/2) + (size/2) * (bi/2) + bj/2 + 1;
        else
            location = (size/2 + 1) * (bi/2) + (size/2) * (bi/2 - 1) + bj/2;
    } else {
        // Even-sized board: every row has exactly (size/2) white squares
        if (bi % 2 == 1)
            location = (size/2) * (bi - 1) + bj/2 + 1;
        else
            location = (size/2) * (bi - 1) + bj/2;
    }

    return location - 1; // convert to 0-based array index
} 

// --- Element access --------------------------------------------------------

int& ChessBoardArray::select(int i, int j) {
    return data[loc(i,j)];
}

int ChessBoardArray::select(int i, int j) const {
    return data[loc(i,j)];
}
 
ChessBoardArray::Row ChessBoardArray::operator[](int i) {
    return Row(*this, i);
}

const ChessBoardArray::ConstRow ChessBoardArray::operator[](int i) const{
    return ConstRow(*this, i);
}

std::ostream& operator<<(std::ostream& out, const ChessBoardArray& a) {
    for (unsigned i = 0; i < a.size; i++) { 
        for (unsigned j = 0; j < a.size; j++) {
            if ((i + j) % 2 == 0)
                out << std::setw(4) << a[i + a.base][j + a.base];
            else
                out << std::setw(4) << 0;
        }
        out << std::endl;
    }
    return out;
}