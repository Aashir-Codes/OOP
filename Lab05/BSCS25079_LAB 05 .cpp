#include <iostream>
using namespace std;

class Matrix {
private:
  int rows;
  int cols;
  int **data;

public:
  //<=========================================================================================================================>
  //                                              Constructors
  //<=========================================================================================================================>

  // DEFAULT  CONSTRUCTOR
  Matrix() {

    rows = 0;
    cols = 0;
    data = nullptr;

  } // DEFAULT

  // PARAMATERISED  CONSTRUCTOR
  Matrix(int r, int c) {

    this->rows = r;
    this->cols = c;
    data = new int *[r];

    for (int i = 0; i < r; i++)
      data[i] = new int[c]{};
  }

  // CONVERSION CONSTRUCTOR

  Matrix(int v) {

    rows = 1;
    cols = 1;

    data = new int *[rows];
    data[0] = new int[cols];
    data[0][0] = v;
  }

  // COPY CONSTRUCTOR

  Matrix(const Matrix &other) {

    rows = other.rows;
    cols = other.cols;
    data = new int *[rows];
    for (int i = 0; i < rows; i++) {
      data[i] = new int[cols];
      for (int j = 0; j < cols; j++)
        data[i][j] = other.data[i][j];
    }
  }

  //<=========================================================================================================================>
  //                                                 DESTRUCTOR
  //<=========================================================================================================================>

  ~Matrix() {
    for (int i = 0; i < rows; i++)
      delete[] data[i];

    rows = 0;
    cols = 0;
    delete[] data;

    data = nullptr;
  }

  //<=========================================================================================================================>
  //                                                OPERATOR OVERLOADING
  //<=========================================================================================================================>

  Matrix &operator=(const Matrix &other) {

    if (this == &other)
      return *this;

    for (int i = 0; i < rows; i++)
      delete[] data[i];

    delete[] data;
    data = nullptr;

    rows = other.rows;
    cols = other.cols;
    data = new int *[rows];

    for (int i = 0; i < rows; i++) {
      data[i] = new int[cols];
      for (int j = 0; j < cols; j++) {
        data[i][j] = other.data[i][j];
      }
    }

    return *this;
  }

  Matrix operator+(const Matrix &other) const {
    Matrix result(rows, cols);

    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        result.data[i][j] = this->data[i][j] + other.data[i][j];
      }
    }

    return result;
  }

  Matrix operator-(const Matrix &other) const {

    Matrix result(rows, cols);

    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        result.data[i][j] = this->data[i][j] - other.data[i][j];
      }
    }

    return result;
  }

  Matrix operator*(int scalar) const {
    Matrix result(rows, cols);

    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++)
        result.data[i][j] = scalar * data[i][j];
    }

    return result;
  }

  Matrix operator*(const Matrix &other) const {
    if (cols != other.rows) {
      cout << "Error: Incompatible dimensions for multiplication!\n";
      return *this;
    }
    Matrix result(rows, other.cols);

    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < other.cols; j++) {
        result.data[i][j] = 0;
        for (int k = 0; k < cols; k++) {
          result.data[i][j] += data[i][k] * other.data[k][j];
        }
      }
    }

    return result;
  }

  Matrix operator/(int scalar) const {
    Matrix result(rows, cols);

    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        result.data[i][j] = this->data[i][j] / scalar;
      }
    }

    return result;
  }

  Matrix operator-() const { return *this * -1; }

  Matrix &operator*=(Matrix const &other) {
    if (cols != other.rows) {
      cout << "Error: Incompatible dimensions for multiplication!\n";
      return *this;
    }
    Matrix a = *this * other;
    *this = a;
    return *this;

    // a *= b;  a.operator*(b) ---> a;

    /*

    const operator should be used when u r not modifying
    multiply then assign it to this
    cols of first matrix should be equal to rows of second matrix to multiply

    */
  }

  bool operator==(const Matrix &other) const {
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++)
        if (data[i][j] != other.data[i][j])
          return false;
    }

    return true;
  }

  bool operator!=(const Matrix &other) const {
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++)
        if (data[i][j] != other.data[i][j])
          return true;
    }

    return false;
  }

  //                                             (  POST / PRE  )  INCREMRNT /
  //                                             DECREMENT

  Matrix &operator++() {
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols;
           j++) // Logic Behind this code it ++A we increment and return the
                // incremented matrix

      {
        data[i][j]++;
      }
    }

    return *this;
  }

  Matrix operator++(int) // post increment
  {
    Matrix temp =
        *this; // return by VALUE: temp is local, a reference to it would dangle
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        data[i][j]++; // Logic Behind this code it A++ we save the old A , we
                      // increment A  and return the original matrix,
                      //  how when we are calling A++  from the main function it
                      //  translates to A.operator++() -> returning temp while A
                      //  is incremented
                      // in background
      }
    }

    return temp;
  }

  // pre decrement
  Matrix &operator--() {
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        data[i][j]--;
      }
    }

    return *this;
  }

  // post decrement
  Matrix operator--(
      int) // return by VALUE: returning a reference to local temp would dangle
  {
    Matrix temp = *this;
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        data[i][j]--;
      }
    }

    return temp;
  }

  //<=========================================================================================================================>
  //                                                 FRIENDS FUNCTION
  //<=========================================================================================================================>

  friend ostream &operator<<(ostream &out, const Matrix &m);

  friend istream &operator>>(istream &in, Matrix &m);

  //<=========================================================================================================================>
  //                                                  MEMBER FUNCTIONS
  //<=========================================================================================================================>

  Matrix power(int exponent) const {
    if (!this->isSquare()) {
      cout << "Error:  Not a Square Matrix! " << endl;
      return *this;
    }
    Matrix result(*this);

    for (int i = 1; i < exponent; i++)
      result *= *this;
    /*
    what i learned:

    i was not returning the result. dumbass
    made this *= operator for the matrix class so that it can give us power
    use comst only when you are not
    power: 2^3 = 2*2*2;
    wrt to original destructoe is called when u mess with prototype in this case
    */

    return result;
  }

  Matrix getMinor(int row, int col) const {

    Matrix result(rows - 1, cols - 1);

    for (int i = 0; i + 1 < rows; i++) {
      for (int j = 0; j + 1 < cols; j++) {
        if (i < row) {
          if (j < col)
            result.data[i][j] = data[i][j];
          else
            result.data[i][j] = data[i][j + 1];
        } else {
          if (j < col)
            result.data[i][j] = data[i + 1][j];
          else
            result.data[i][j] = data[i + 1][j + 1];
        }
      }
    }

    return result;
  }

  Matrix Transpose() const {
    Matrix result(cols, rows);

    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        result.data[i][j] = data[j][i];
      }
    }

    return result;
  }

  Matrix identity(int rows) {
    Matrix Identity(rows, rows);

    for (int i = 0; i < rows; i++)
      for (int j = 0; j < rows;
           j++) // square matrix: use the parameter, not member cols
        if (i == j)
          Identity.data[i][j] = 1;
        else
          Identity.data[i][j] = 0;

    return Identity;
  }
  Matrix zeroMatrix(int rows, int cols) {
    Matrix zero(rows, cols);

    for (int i = 0; i < rows; i++)
      for (int j = 0; j < cols; j++)
        zero.data[i][j] = 0;

    return zero;
  }

  int **addRow() {
    int **newptr = new int *[this->rows + 1]{};

    for (int i = 0; i < rows; i++) {
      newptr[i] = new int[cols];
      for (int j = 0; j < cols; j++) {
        newptr[i][j] = data[i][j];
      }
    }

    /*

    declare with a new row
    copy
    delete
    retyurn

    */

    /*

    create a new pointer to pointer
    copy the data
    allocate a new row
    delete the data from the old pointer
    delete the row pointer
    increment row
    return newptr

    */

    newptr[rows] = new int[cols]{};
    cout << endl;
    cout << "Cols Size: " << cols;
    cout << endl;
    cout << "Enter Enteries: ";
    for (int i = 0; i < cols; i++)
      cin >> newptr[rows][i];

    for (int i = 0; i < rows; i++)
      delete[] this->data[i];

    delete[] data;

    rows++;
    return newptr;
  }

  int **shrinkRow(int index) {
    int **newptr = new int *[this->rows - 1]{};

    for (int i = 0; i < rows - 1; i++) {
      newptr[i] = new int[cols];
      for (int j = 0; j < cols; j++) {
        if (i < index) {
          newptr[i][j] = this->data[i][j];
        }

        else {
          newptr[i][j] = this->data[i + 1][j];
        }
      }
    }
    /*
*    create a new pointer to pounter of row-1 size

*    copy the data and mindful of the  index and for loop conditon because you
messed in there

*    delete the data from the clumn arrays

*   decrement row

*   return new ptr

    */

    for (int i = 0; i < rows; i++)
      delete[] this->data[i];

    delete[] data;

    rows--;

    return newptr;
  }

  int **addCols() {
    int **newptr = new int *[this->rows]{};

    for (int i = 0; i < rows; i++) {
      newptr[i] = new int[cols + 1];
      for (int j = 0; j < cols; j++) {
        newptr[i][j] = data[i][j];
      }
    }

    /*

    create a new pointer to pointer
    allocate a new cols
    copy the data wrt previous or orignal pointer
    delete the data from the old pointer
    delete the old pointer
    increment cols
    return newptr

    */

    cout << endl;
    cout << "Rows Size: " << rows;
    cout << endl;
    cout << "Enter Enteries: ";
    for (int i = 0; i < rows; i++)
      cin >> newptr[i][cols];

    for (int i = 0; i < rows; i++)
      delete[] this->data[i];

    delete[] data;

    cols++;
    return newptr;
  }

  int **shrinkCols(int index) {
    int **newptr = new int *[rows]{};

    for (int i = 0; i < rows; i++) {
      newptr[i] = new int[cols - 1];
      for (int j = 0; j < cols - 1; j++) {
        if (j < index) {
          newptr[i][j] = this->data[i][j];
        } else {
          newptr[i][j] = this->data[i][j + 1];
        }
      }
    }
    /*

  *  create a new pointer to pounter of cols-1 size

  *  copy the data and mindful of the  index and for loop conditon because you
  messed up in there

  *  delete the data from the column arrays

  *  decrement cols

  *  return new ptr

    */

    for (int i = 0; i < rows; i++)
      delete[] this->data[i];

    delete[] data;

    cols--;

    return newptr;
  }

  int trace() const {
    int sum = 0;
    for (int i = 0; i < rows; i++)
      for (int j = 0; j < cols; j++)
        if (i == j)
          sum += data[i][j];

    return sum;
  }

  bool isSquare() const { return cols == rows; }

  bool isIdentity() const {
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        if (i == j) {
          if (data[i][j] != 1)
            return false;
        } else {
          if (data[i][j] != 0)
            return false;
        }
      }
    }

    return true;
  }

  bool isSymmetric() { return *this == this->Transpose(); }
};
// datattype & -> because we don't copy , operator for overloading (Paramaters:
// ostream  & out(var name) , Matrix object;

//<=========================================================================================================================>
//                                           FRIENDS FUNCTION IMPLEMENTATION
//<=========================================================================================================================>
ostream &operator<<(ostream &out, const Matrix &m) {
  // learning point --> No this pointer is passed to a friend function

  for (int i = 0; i < m.rows; i++) {
    cout << "[ ";
    for (int j = 0; j < m.cols; j++)
      cout << m.data[i][j] << " ";
    cout << "]";
    cout << endl;
  }

  return out; // what is it returning output
}

istream &operator>>(istream &in, Matrix &m) {

  for (int i = 0; i < m.rows; i++) {
    for (int j = 0; j < m.cols; j++)
      cin >> m.data[i][j];
  }

  return in; // what is it returning input
}
// friend ostream& operator << (ostream & out,const matrix & other)

//<=========================================================================================================================>
//                                                     MAIN
//<=========================================================================================================================>

void line() { cout << "------------------------------" << endl; }

int main() {
  // ---- Input two square matrices so every operator can be exercised ----
  Matrix a(2, 2), b(2, 2);

  cout << "Enter 4 values for matrix A (2x2, row by row): ";
  cin >> a;

  cout << "Enter 4 values for matrix B (2x2, row by row): ";
  cin >> b;

  line();
  cout << "Matrix A:\n" << a;
  cout << "Matrix B:\n" << b;

  // ---- Arithmetic operators ----
  line();
  cout << "A + B =\n" << (a + b);
  cout << "A - B =\n" << (a - b);
  cout << "A * B =\n" << (a * b);
  cout << "A * 3 (scalar) =\n" << (a * 3);
  cout << "A / 2 (scalar) =\n" << (a / 2);
  cout << "-A =\n" << (-a);

  // ---- Compound multiply / power ----
  line();
  Matrix p = a;
  p *= b;
  cout << "A *= B :\n" << p;
  cout << "A ^ 2 (power) =\n" << a.power(2);

  // ---- Comparison operators ----
  line();
  cout << "A == B : " << (a == b ? "true" : "false") << endl;
  cout << "A != B : " << (a != b ? "true" : "false") << endl;

  // ---- Increment / decrement ----
  line();
  Matrix inc = a;
  cout << "Pre-increment ++inc =\n" << ++inc;
  cout << "Post-increment inc++ returns old, then inc becomes:\n";
  Matrix old = inc++;
  cout << "returned (old):\n" << old;
  cout << "inc now:\n" << inc;

  // ---- Member functions ----
  line();
  cout << "Transpose of A =\n" << a.Transpose();
  cout << "Trace of A = " << a.trace() << endl;
  cout << "A is square?    " << (a.isSquare() ? "yes" : "no") << endl;
  cout << "A is identity?  " << (a.isIdentity() ? "yes" : "no") << endl;
  cout << "A is symmetric? " << (a.isSymmetric() ? "yes" : "no") << endl;

  // ---- Minor / identity / zero / conversion constructor ----
  line();
  cout << "Minor of A (remove row 0, col 0) =\n" << a.getMinor(0, 0);
  cout << "3x3 identity =\n" << a.identity(3);
  cout << "2x3 zero matrix =\n" << a.zeroMatrix(2, 3);

  Matrix scalarMat = 7; // conversion constructor
  cout << "Matrix from int 7 =\n" << scalarMat;

  return 0;
}
