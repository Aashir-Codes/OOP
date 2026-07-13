#include <iostream>
using namespace std;

//<==========================================================>
//                          Functions Prototypes
//<==========================================================>

void Pause() {
  cout << "\n Enter any key to continue!" << endl;
  cin.ignore();
  cin.get();
}

void system_Clear() {
#ifdef _WIN32
  system_Clear();
#else
  system("clear");
#endif
}
void print(const char[], int *, int);
int *regrow1D(int *&, int &);
int *shrink1D(int *&, int &, int);
void shifting(int *, int, int);
void print(int **, int *, int);
void Enter_Enteries(int **&, int *&, int, int &);
int **add_row(int **&, int *&, int &, int &);
int **shrink_row(int **&, int *&, int &, int &);
void Swap(int &, int &);
bool bubbling(int *, int);
void Bubble_Sort(int *, int);

bool Validation_down(int arr[][10], int row, int col);
bool Validation_up(int arr[][10], int row, int col);
bool Validation_right(int arr[][10], int row, int col);
bool Validation_left(int arr[][10], int row, int col);
void Regrow(int *&arr, int &size);

void print_2d(int **arr);
void print_3d(int n, int ***arr, int *rows);
void print_3d(int n, int ***arr, int *rows);
int **_3d_to_2d(int n, int ***&arr, int *&rows);
void destructor_2d(int **&arr);
void destructor_3d(int n, int ***&arr, int *&rows);
void init(int n, int ***&arr, int *&rows);

//  ------------------------  Tasks -------------------------
void Task1();
void Task2();
void Task3();
void Task4();
void Task5();
void Task6();
void add_element(int **&, int *&, int &);
void shrink_element(int **&, int *&, int &);

//<-------------------------   Main -------------------------->
int main() {

  int choice = 0;
  do {

    cout << "\n<---------------------------------->" << endl;
    cout << "                 Menu" << endl;
    cout << "<---------------------------------->" << endl;

    cout << "1. Task 1" << endl;
    cout << "2. Task 2" << endl;
    cout << "3. Task 3" << endl;
    cout << "4. Task 4" << endl;
    cout << "5. Task 5" << endl;
    cout << "6. Task 6" << endl;
    cout << "<---------------------------------->" << endl;

    cout << "Choice: ";
    cin >> choice;
    switch (choice) {
    case 0:
      system_Clear();
      cout << "Exiting!" << endl;
      break;
    case 1:
      system_Clear();
      Task1();
      Pause();
      break;
    case 2:
      system_Clear();
      Task2();
      Pause();
      break;
    case 3:
      system_Clear();
      Task3();
      Pause();
      break;
    case 4:
      system_Clear();
      Task4();
      Pause();
      break;
    case 5:
      system_Clear();
      Task5();
      Pause();
      break;
    case 6:
      system_Clear();
      Task6();
      Pause();
      break;
    default:
      cout << "Invalid Choice!" << endl;
      Pause();
      break;
    }

  } while (choice != 0);

  return 0;
}

void Task3() {
  int n = 0;

  cout << "Enter number of matrix: ";
  cin >> n;
  int ***arr = nullptr;
  int *rows = nullptr;
  init(n, arr, rows);
  print_3d(n, arr, rows);
  int **_2d = _3d_to_2d(n, arr, rows);
  cout << "Merged Matrix: \n";
  print_2d(_2d);
  destructor_3d(n, arr, rows);
  destructor_2d(_2d);
}

int task4() {
  int n = 0;
  int ***arr = nullptr;
  int *rows = nullptr;

  cout << "Enter number of matrix: ";
  cin >> n;
  cout << endl;

  arr = new int **[n] {};
  rows = new int[n]{};
  for (int i = 0; i < n; i++) {
    cout << "Enter how many rows in Matrix: " << i + 1 << " : ";
    cin >> rows[i];

    arr[i] = new int *[rows[i]]{};

    for (int j = 0; j < rows[i]; j++) {
      int cols = 0;
      cout << "\nEnter Cols: ";
      cin >> cols;
      arr[i][j] = new int[cols + 1]{};

      arr[i][j][0] = cols;

      cout << "\n  :Enter Enteries:\n ";
      for (int k = 1; k <= arr[i][j][0]; k++) {
        cin >> arr[i][j][k];
      }
    }
  }

  int **_2d = new int *[rows[0]]{};
  for (int i = 0; i < rows[0]; i++)
    _2d[i] = new int[arr[0][0][0] * n]{};

  int colOffset = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < rows[i]; j++) {
      for (int k = 1; k <= arr[i][j][0]; k++) {
        _2d[j][colOffset + k - 1] = arr[i][j][k]; // ✅ offset applied
      }
    }
    colOffset += arr[i][0][0]; // move offset forward by this matrix's col count
  }
  int totalCols = arr[0][0][0] * n;
  cout << "\nMerged 2D Matrix:\n";
  for (int i = 0; i < rows[0]; i++) {
    cout << "[";
    for (int j = 0; j < totalCols; j++) {
      cout << _2d[i][j];
      if (j < totalCols - 1)
        cout << ", ";
    }
    cout << "]\n";
  }

  return 0;
}
//<==========================================================>
//                      Functions
//<==========================================================>
void ADD_ROW(int **&arr, int &rows, const int *&cols) {

  int **newptr = new int *[rows + 1]{};

  for (int i = 0; i < rows; i++)
    newptr[i] = new int[cols[i]];

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols[i]; j++)
      newptr[i][j] = arr[i][j];
  }

  for (int i = 0; i < rows; i++)
    delete[] arr[i];

  delete[] arr;
  arr = nullptr;

  arr = newptr;
}

void ADD_COLUMN(int **&arr, int *&cols, int row_index) {

  arr[row_index] = regrow1D(arr[row_index], cols[row_index]);
}

void Task1() {
  int size = 0;

  cout << "Enter the size: ";
  cin >> size;

  int *arr = new int[size]{};

  cout << "\nEnter Enteries: ";

  for (int i = 0; i < size; i++)
    cin >> arr[i];

  int choice = 0;

  do {
    system_Clear();

    cout << "<----------------------- Menu ----------------------->" << endl;
    cout << " 1. Insert" << endl;
    cout << " 2. Shrink" << endl;
    cout << " 3. Exit" << endl;
    cout << "<----------------------------------------------------->" << endl;

    cout << "Size: " << size << endl;
    print("The Array :  ", arr, size);
    cout << "Choice: ";
    cin >> choice;
    cout << endl;

    int index = 0;
    int num = 0;

    switch (choice) {
    case 1:

      cout << "\nEnter the number you want to add: ";
      cin >> num;
      cout << "\nEnter the index : ";
      cin >> index;
      arr = regrow1D(arr, size);
      shifting(arr, size, index);
      arr[index] = num;
      break;

    case 2:
      index = 0;
      cout << "\nEnter the index : ";
      cin >> index;
      arr = shrink1D(arr, size, index);
      break;
    case 3:
      cout << "Exiting" << endl;
      delete[] arr;
      break;
    default:
      cout << "Invalid Choice" << endl;
      break;
    }

  } while (choice != 3);
}

void Task2() {

  cout << " <===================  Initial Setup ====================>" << endl;
  int rows = 0;
  int Columns = 0;

  cout << "Enter number of Rows : ";
  cin >> rows;
  cout << endl;

  int **arr = new int *[rows]{};
  int *cols = nullptr;

  Enter_Enteries(arr, cols, rows, Columns);

  int choice = 0;
  do {
    print(arr, cols, rows);
    cout << "<================================>" << endl;
    cout << "Rows: " << rows << endl;
    cout << "<================================>" << endl;
    cout << "1.Add an index" << endl;
    cout << "2.Shrink an index" << endl;
    cout << "3.Add a row" << endl;
    cout << "4.Shrink a row" << endl;
    cout << "5.Free Memory and exit" << endl;
    cout << "<================================>" << endl;
    cout << "Choice: ";
    cin >> choice;
    cout << endl;

    switch (choice) {
    case 1:
      add_element(arr, cols, rows);
      break;
    case 2:
      shrink_element(arr, cols, rows);
      break;
    case 3:
      arr = add_row(arr, cols, rows, Columns);

      break;
    case 4:

      arr = shrink_row(arr, cols, rows, Columns);

      break;

    case 5:

      for (int i = 0; i < rows; i++)
        delete[] arr[i];

      delete[] arr;
      arr = nullptr;
      cout << "Memory Freed" << endl;
      cout << "Exiting!" << endl;
      break;
    }

  } while (choice != 5);
}

void Task4() {
  int size = 0;
  cout << "Enter how many Patients are there: ";
  cin >> size;
  cout << endl;

  int *arr = new int[size]{};

  cout << "Enter The Critical Scores: ";
  for (int i = 0; i < size; i++)
    cin >> arr[i];

  Bubble_Sort(arr, size);

  cout << "\nPrint: [";
  for (int i = 0; i < size; i++)
    cout << arr[i] << " ";

  cout << "]" << endl;

  delete[] arr;
}

void Task5() {

  int Array[10][10] = {};
  bool arr[10][10] = {}; // visited
  cout << " (Max 10 by 10) Enter (Rows,Cols)  : ";
  int Rows, Cols;
  cin >> Rows >> Cols;

  for (int i = 0; i < Rows; i++)
    for (int j = 0; j < Cols; j++)
      cin >> Array[i][j];

  int start_r = 0, start_c = 0;

  bool flag = 0;

  // Check 2 by 2 box
  for (int i = 0; i < Rows - 1; i++) {
    for (int j = 0; j < Cols - 1; j++) {
      if (Array[i][j] == 1 && Array[i + 1][j] == 1 && Array[i][j + 1] == 1 &&
          Array[i + 1][j + 1] == 1) {
        cout << "Water leak detected (2x2 block found)" << endl;
        return;
      }
    }
  }

  for (int i = 0; i < Rows; i++) {
    for (int j = 0; j < Cols; j++) {
      if (Array[i][j] == 1) {
        start_r = i;
        start_c = j;
        flag = true;
        break;
      }
      arr[i][j] = 1;
    }
    if (flag)
      break;
  }
  int c_r = start_r, c_c = start_c;

  flag = false;
  while (true) {
    if (flag) {
      if (c_r == start_r && c_c == start_c) {
        cout << "No water leak " << endl;
        return;
      }
    }

    flag = true;

    if (Validation_right(Array, c_r, c_c) && arr[c_r][c_c + 1] == 0) {

      arr[c_r][c_c + 1] = true;
      c_c++;
    } else if (Validation_left(Array, c_r, c_c) && arr[c_r][c_c - 1] == 0) {

      arr[c_r][c_c - 1] = true;
      c_c--;
    } else if (Validation_up(Array, c_r, c_c) && arr[c_r - 1][c_c] == 0) {

      arr[c_r - 1][c_c] = true;
      c_r--;

    } else if (Validation_down(Array, c_r, c_c) && arr[c_r + 1][c_c] == 0) {

      arr[c_r + 1][c_c] = true;
      c_r++;
    }

    else {
      cout << "waterleak detected" << endl;
      return;
    }
  }
}

void Task6() {
  int Array[10][10] = {};
  cout << " (Max 10 by 10) Enter (Rows,Cols)  : ";
  int Rows, Cols;
  cin >> Rows >> Cols;

  for (int i = 0; i < Rows; i++)
    for (int j = 0; j < Cols; j++)
      cin >> Array[i][j];

  int *boundary = nullptr;
  int size = 0;
  // first row
  for (int i = 0; i < Cols; i++) {
    Regrow(boundary, size);
    boundary[size - 1] = Array[0][i];
  }
  // last col after 1 row and last row
  for (int i = 1; i < Rows - 1; i++) {
    Regrow(boundary, size);
    boundary[size - 1] = Array[i][Cols - 1];
  }
  // last row
  for (int i = Cols - 1; i >= 0; i--) {
    Regrow(boundary, size);
    boundary[size - 1] = Array[Rows - 1][i];
  }
  // first col after 1 row and last row
  for (int i = Rows - 2; i >= 1; i--) {
    Regrow(boundary, size);
    boundary[size - 1] = Array[i][0];
  }

  int temp = Array[1][0];
  for (int i = size - 1; i > 0; i--) {
    boundary[i] = boundary[i - 1];
  }
  boundary[0] = temp;

  int pointer = 0;
  for (int i = 0; i < Cols; i++) {

    Array[0][i] = boundary[pointer];
    pointer++;
  }

  for (int i = 1; i < Rows - 1; i++) {

    Array[i][Cols - 1] = boundary[pointer];
    pointer++;
  }

  for (int i = Cols - 1; i >= 0; i--) {

    Array[Rows - 1][i] = boundary[pointer];
    pointer++;
  }

  for (int i = Rows - 2; i >= 1; i--) {

    Array[i][0] = boundary[pointer];
    pointer++;
  }
  delete[] boundary;

  for (int i = 0; i < Rows; i++) {
    for (int j = 0; j < Cols; j++)
      cout << Array[i][j] << " ";
    cout << endl;
  }
}

int *regrow1D(int *&arr, int &size) {

  int *newptr = new int[size + 1]{};

  for (int i = 0; i < size; i++)
    newptr[i] = arr[i];

  if (size != 0)
    delete[] arr;

  size++;
  return newptr;
}

int *shrink1D(int *&arr, int &size, int index) {

  int *newptr = new int[size - 1]{};

  int j = 0;

  for (int i = 0; i < size; i++) {
    if (i == index)
      continue;

    newptr[j] = arr[i];
    j++;
  }

  size--;

  return newptr;
}

void print(const char msg[], int *arr, int size) {

  cout << msg << " [ ";

  for (int i = 0; i < size; i++)
    cout << arr[i] << " ";

  cout << "]" << endl;
}

void shifting(int *arr, int size, int index) {

  for (int i = size - 1; i > index; i--)
    arr[i] = arr[i - 1];
}

void print(int **arr, int *cols, int rows) {

  for (int i = 0; i < rows; i++) {
    cout << "Row no " << i << " : ";
    for (int j = 0; j < cols[i]; j++)
      cout << arr[i][j] << " ";

    cout << endl;
  }
}

void Enter_Enteries(int **&arr, int *&cols, int rows, int &Columns) {

  for (int i = 0; i < rows; i++) {
    cout << "Row : " << i << " " << endl;
    cout << "Enter the Cols: ";
    cols = regrow1D(cols, Columns);
    cin >> cols[i];
    Columns++;
    arr[i] = new int[cols[i]]{};
    cout << endl;
  }

  cout << "      < ----- Enter Enteries ----- > " << endl;
  for (int i = 0; i < rows; i++) {

    for (int j = 0; j < cols[i]; j++) {
      cin >> arr[i][j];
    }
  }
  cout << endl;
}

int **add_row(int **&arr, int *&cols, int &rows, int &columns) {

  int index = 0;
  cout << "Enter the index you want add the row : ";
  cin >> index;
  cout << "Enter How many columns you want: ";
  cols = regrow1D(cols, columns);
  shifting(cols, columns, index);
  cin >> cols[index];
  cout << endl;
  int oldRows = rows;
  rows++;

  int **newptr = new int *[rows];

  for (int i = 0; i < rows; i++)
    newptr[i] = new int[cols[i]];

  for (int i = 0; i < rows; i++) {
    if (i < index) {
      for (int j = 0; j < cols[i]; j++)
        newptr[i][j] = arr[i][j];
    } else if (i == index) {
      cout << "Enter entries for new row:\n";
      for (int j = 0; j < cols[index]; j++)
        cin >> newptr[i][j];
    } else {
      for (int j = 0; j < cols[i]; j++)
        newptr[i][j] = arr[i - 1][j];
    }
  }

  for (int i = 0; i < oldRows; i++)
    delete[] arr[i];
  delete[] arr;
  arr = nullptr;

  return newptr;
}

int **shrink_row(int **&arr, int *&cols, int &rows, int &columns) {
  int index = 0;
  cout << "Enter the index you want add the row : ";
  cin >> index;
  cols = shrink1D(cols, columns, index);
  int oldRows = rows;
  rows--;

  int **newptr = new int *[rows];

  for (int i = 0; i < rows; i++)
    newptr[i] = new int[cols[i]];

  for (int i = 0; i < rows; i++) {
    if (i < index) {
      for (int j = 0; j < cols[i]; j++)
        newptr[i][j] = arr[i][j];
    } else if (i == index) {
      continue;
    } else {
      for (int j = 0; j < cols[i]; j++)
        newptr[i][j] = arr[i][j];
    }
  }

  for (int i = 0; i < oldRows; i++)
    delete[] arr[i];
  delete[] arr;
  arr = nullptr;

  return newptr;
}

void add_element(int **&arr, int *&cols, int &rows) {
  system_Clear();
  print(arr, cols, rows);
  int Row_index = 0;
  int column_index = 0;
  int num = 0;

  arr[Row_index] = regrow1D(arr[Row_index], cols[Row_index]);
  cout << "\nEnter the number you want to add: ";
  cin >> num;
  cout << "\nEnter the index of Row : ";
  cin >> Row_index;
  cout << "\nEnter the column index: ";
  cin >> column_index;
  shifting(arr[Row_index], cols[Row_index], column_index);
  arr[Row_index][column_index] = num;
}

void shrink_element(int **&arr, int *&cols, int &rows) {

  system_Clear();
  print(arr, cols, rows);
  int Row_index = 0;
  int column_index = 0;

  cout << "\nEnter the index of Row : ";
  cin >> Row_index;
  cout << "\nEnter the column index: ";
  cin >> column_index;
  arr[Row_index] = shrink1D(arr[Row_index], cols[Row_index], column_index);
}

void Swap(int &a, int &b) {
  int temp = a;
  a = b;
  b = temp;
}

bool bubbling(int *arr, int size) {

  int BH = 0;
  for (int i = 0; i + 1 < size; i++) {

    if ((arr[i + 1] > 80 && arr[i] < arr[i + 1])) {
      Swap(arr[i], arr[i + 1]);
      BH = true;
    }
  }
  return BH;
}

void Bubble_Sort(int *arr, int size) {
  while (bubbling(arr, size)) {
  }
}

void init(int n, int ***&arr, int *&rows) {
  arr = new int **[n] {};
  rows = new int[n]{};

  for (int i = 0; i < n; i++) {
    cout << "\n Matrix: " << i + 1 << endl;

    cout << " Enter number of rows: ";
    cin >> rows[i];

    arr[i] = new int *[rows[i]]{};
    for (int j = 0; j < rows[i]; j++) {
      cout << "\n Enter number of columns: ";
      int cols = 0;
      cin >> cols;
      arr[i][j] = new int[cols + 1]{cols};

      cout << "\n Enter elements [ Row: " << j << "]:  ";
      for (int k = 1; k <= cols; k++) {

        cin >> arr[i][j][k];
      }
    }
  }
}

void destructor_3d(int n, int ***&arr, int *&rows) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < rows[i]; j++) {
      delete[] arr[i][j];
    }
    delete[] arr[i];
  }
  delete[] arr;
  delete[] rows;
}

void destructor_2d(int **&arr) {
  int rows = arr[0][0];
  for (int i = 0; i <= rows; i++) {
    delete[] arr[i];
  }
  delete[] arr;
}

int **_3d_to_2d(int n, int ***&arr, int *&rows) {
  int max_row = rows[0];
  for (int i = 0; i < n; i++)
    if (max_row < rows[i])
      max_row = rows[i];

  int **_2d = new int *[max_row + 1]{};
  _2d[0] = new int[1]{max_row};

  for (int i = 0; i < max_row; i++) {
    int cols_size = 0;
    for (int j = 0; j < n; j++) {
      if (i < rows[j])
        cols_size += arr[j][i][0];

      _2d[i + 1] = new int[cols_size + 1]{cols_size};
    }
    int idx = 1;
    for (int j = 0; j < n; j++) {
      if (i < rows[j])
        for (int k = 1; k <= arr[j][i][0]; k++)
          _2d[i + 1][idx++] = arr[j][i][k];
    }
  }
  return _2d;
}

void print_3d(int n, int ***arr, int *rows) {
  for (int i = 0; i < n; i++) {
    cout << "\n Matrix: " << i + 1 << endl;
    for (int j = 0; j < rows[i]; j++) {
      int cols = arr[i][j][0];
      cout << "\t";
      for (int k = 1; k <= cols; k++) {
        cout << arr[i][j][k] << " ";
      }
      cout << endl;
    }
  }
}

void print_2d(int **arr) {

  int rows = arr[0][0];

  for (int i = 1; i <= rows; i++) {
    int cols = arr[i][0];
    cout << "\t";
    for (int j = 1; j <= cols; j++) {
      cout << arr[i][j] << " ";
    }
    cout << endl;
  }
}

bool Validation_down(int arr[][10], int row, int col) {

  if (row < 0 or row >= 10 or col < 0 or col >= 10)
    return false;
  if (arr[row + 1][col] == 1)
    return true;

  return false;
}
bool Validation_up(int arr[][10], int row, int col) {

  if (row < 0 or row >= 10 or col < 0 or col >= 10)
    return false;
  if (arr[row - 1][col] == 1)
    return true;

  return false;
}
bool Validation_right(int arr[][10], int row, int col) {

  if (row < 0 or row >= 10 or col < 0 or col >= 10)
    return false;
  if (arr[row][col + 1] == 1)
    return true;

  return false;
}
bool Validation_left(int arr[][10], int row, int col) {

  if (row < 0 or row >= 10 or col < 0 or col >= 10)
    return false;
  if (arr[row][col - 1] == 1)
    return true;

  return false;
}

void Regrow(int *&arr, int &size) {
  int newSize = size * 2;
  int *temp = new int[newSize]{};
  for (int i = 0; i < size; i++) {
    temp[i] = arr[i];
  }

  delete[] arr;

  size *= 2;
  arr = temp;
}
