#include <iostream>
using namespace std;

class String {
private:
  char *str;
  int size;

public:
  //<====================================================>
  //                    Constructors
  //<====================================================>
  String() {
    str = nullptr;
    size = 0;
  }

  String(const char *str) {
    int iterator = 0;
    for (iterator = 0; str[iterator] != '\0'; iterator++)
      ;
    size = iterator;

    this->str = new char[size + 1]{};
    for (int i = 0; i < size; i++)
      this->str[i] = str[i];

    this->str[size] = '\0';
  }

  String(const String &other) {

    size = other.size;

    str = new char[size + 1]{};

    for (int i = 0; i < size; i++)
      this->str[i] = other.str[i];

    str[size] = '\0';
  }

  /*
      * Shallow Copy

      String(const String& other)
      {

              this->size = other.size;
              this->str = other.str;

      }


      */

  String(const char &other) {
    this->size = 2;
    str = new char[size];

    str[0] = other;
    str[1] = '\0';
  }

  String(int SIZE, const char ch) //
  {

    this->size = SIZE;
    str = new char[size + 1];

    for (int i = 0; i < size; i++)
      str[i] = ch;

    str[size] = '\0';
  }

  String(int number) {
    int temp = number;
    size = 0;
    do {
      temp /= 10;
      size++;
    } while (temp != 0);

    str = new char[size + 1];

    for (int i = size - 1; i >= 0; i--) {
      str[i] = number % 10;
      number /= 10;
    }

    str[size] = '\0';
  }

  //<====================================================>
  //                Member Functions
  //<====================================================>

  void ReplaceFirst(char c) {
    if (size == 0) {
      cout << "String is empty" << endl;
      return;
    }

    str[0] = c;
  }

  String itos(int number) {
    String Temp;
    int temp = number;
    Temp.size = 0;
    do {
      temp /= 10;
      Temp.size++;
    } while (temp != 0);

    Temp.str = new char[Temp.size + 1]{};

    for (int i = Temp.size - 1; i >= 0; i--) {
      Temp.str[i] = (number % 10) + '0';
      number /= 10;
    }

    Temp.str[Temp.size] = '\0';

    return Temp;
  }

  int stoi() const {
    int num = 0;
    for (int i = 0; i < size; i++)
      num = (str[i] - '0') + (num * 10);

    return num;
  }

  static int stoi(const String s) {
    int num = 0;
    for (int i = 0; i < s.size; i++)
      num = num * 10 + (s.str[i] - '0');
    return num;
  }

  void All_substring_searching(int *&arr, int &_size, const String &other) {
    for (int i = 0; i < size; i++) {
      bool found = 0;

      if (str[i] == other.str[0]) {

        for (int j = 0; j < other.size; j++) {
          if (str[i + j] != other.str[j]) {
            found = 0;
            break;
          }
          found = 1;
        }
      }
      if (found) {
        arr = Regrow1D(arr, _size);
        arr[_size - 1] = i;
      }
    }
  }

  int find_first(char ch) {
    for (int i = 0; i < size; i++)
      if (str[i] == ch)
        return i;

    return -1;
  }

  int find_last(char ch) {
    for (int i = size - 1; i >= 0; i--)
      if (str[i] == ch)
        return i;

    return -1;
  }

  int find_first(const String &other) const {
    for (int i = 0; i < size; i++) {
      bool found = 0;

      if (str[i] == other.str[0]) {

        for (int j = 0; j < other.size; j++) {
          if (str[i + j] != other.str[j]) {
            found = 0;
            break;
          }
          found = 1;
        }
      }
      if (found) {
        return i;
      }
    }

    return -1;
  }

  int find_last(const String &other) const {
    for (int i = size - 1; i >= 0; i--) {
      bool found = 0;

      if (str[i] == other.str[other.size - 1]) {

        for (int j = other.size - 1; j >= 0; j--) {
          if (str[i - j] != other.str[j]) {
            found = 0;
            break;
          }
          found = 1;
        }
      }
      if (found) {
        return i - (other.size - 1);
      }
    }

    return -1;
  }

  int *find_all(char ch, int &SIZE) {
    int *indexes = nullptr;
    for (int i = 0; i < size; i++) {
      if (str[i] == ch) {
        indexes = Regrow1D(indexes, SIZE);
        indexes[SIZE - 1] = i;
      }
    }

    return indexes;
  }

  int *Regrow1D(int *&arr, int &size) {

    int *ptr = new int[size + 1];

    for (int i = 0; i < size; i++)
      ptr[i] = arr[i];
    if (size != 0)
      delete[] arr;

    size++;

    return ptr;
  }

  String &trim() {

    for (int i = 0; i < size; i++) {
      if (str[i] == ' ' || str[i] == '\n' || str[i] == '\t') {
        Shrink(i);
        i--;
      } else {
        break;
      }
    }

    for (int i = size - 1; i >= 0; i--) {
      if (str[i] == ' ' || str[i] == '\n' || str[i] == '\t') {
        Shrink(i);
      } else {
        break;
      }
    }

    return *this;
  }

  void remove_at(int i) { Shrink(i); }

  void remove_first(char ch) {
    for (int i = 0; i < size; i++)
      if (str[i] == ch) {
        Shrink(i);
        break;
      }
  }

  void remove_last(char ch) {
    for (int i = size - 1; i >= 0; i--)
      if (str[i] == ch) {
        Shrink(i);
        break;
      }
  }

  void remove_all(char ch) {

    for (int i = 0; i < size; i++)
      if (str[i] == ch) {
        Shrink(i);
        i--;
      }
  }

  void clear() {
    delete[] str;

    str = nullptr;
    size = 0;
  }

  static String trim(String &s) {

    for (int i = 0; i < s.size; i++) {
      if (s.str[i] == ' ' || s.str[i] == '\n' || s.str[i] == '\t') {
        s.Shrink(i);
        i--;
      } else {
        break;
      }
    }

    for (int i = s.size - 1; i >= 0; i--) {
      if (s.str[i] == ' ' || s.str[i] == '\n' || s.str[i] == '\t') {
        s.Shrink(i);
      } else {
        break;
      }
    }

    return s;
  }

  String &operator=(const String &other) {
    if (this == &other)
      return *this;

    size = other.size;
    delete[] str;

    str = new char[size + 1]{};

    for (int i = 0; i < size; i++)
      this->str[i] = other.str[i];

    str[size] = '\0';

    return *this;
  }

  char &at(int pos) {
    if (pos < 0 || pos >= size) {
      cout << "Out of bound" << endl;
      return str[size];
    }
    return str[pos];
  }

  char &operator[](int pos) {
    if (pos < 0 || pos >= size) {
      cout << "Out of bound" << endl;
      return str[size];
    }
    return str[pos];
  }

  const char &operator[](int pos) const {
    if (pos < 0 || pos >= size) {
      cout << "Out of bound" << endl;
      return str[size];
    }
    return str[pos];
  }

  char &back() { return str[size - 1]; }

  char &front() { return str[0]; }

  int Size() const {
    int iterator = 0;
    for (iterator = 0; str[iterator] != '\0'; iterator++)
      ;

    return iterator;
  }

  void Regrow() {

    char *newptr = new char[size + 2];

    for (int i = 0; i < size; i++) {
      newptr[i] = str[i];
    }

    delete[] str;

    str = newptr;

    size++;
    str[size] = '\0';
  }

  void Shrink(int index) {
    if (size == 0 || index < 0 || index >= size)
      return;
    char *newptr = new char[size];

    for (int i = 0; i < size; i++) {
      if (i == index) {
        continue;
      }
      if (i < index) {
        newptr[i] = str[i];
      }
      if (i > index) {
        newptr[i - 1] = str[i];
      }
    }
    newptr[size - 1] = '\0';

    delete[] str;
    str = newptr;

    size--;
  }

  bool empty() const { return size == 0; }

  String operator+(const String &rhs) {
    int leftLen = this->Size();

    int rightLen = rhs.Size();

    int totalLen = leftLen + rightLen;

    char *newStr = new char[totalLen + 1];
    for (int i = 0; i < leftLen; i++)
      newStr[i] = str[i];

    for (int i = 0; i < rightLen; i++)
      newStr[i + leftLen] = rhs.str[i];

    newStr[totalLen] = '\0';

    String result(newStr);
    delete[] newStr;

    return result;
  }

  bool operator==(const String &rhs) {
    if (size != rhs.size)
      return false;

    for (int i = 0; i < size; i++)
      if (str[i] != rhs.str[i])
        return false;

    return true;
  }

  bool operator!=(const String &rhs) { return !(*this == rhs); }

  bool operator<(const String &rhs) const {
    int minLen = (size < rhs.size) ? size : rhs.size;
    for (int i = 0; i < minLen; i++) {
      if (str[i] < rhs.str[i])
        return true;
      if (str[i] > rhs.str[i])
        return false;
    }
    return size < rhs.size;
  }

  bool operator>(const String &rhs) const { return rhs < *this; }

  bool operator<=(const String &rhs) const { return !(rhs < *this); }

  bool operator>=(const String &rhs) const { return !(*this < rhs); }

  void Shifting(int index) {

    for (int i = size - 1; i > index; i--)
      str[i] = str[i - 1];
  }

  String &insert(int pos, const char c) {
    Regrow();
    Shifting(pos);
    str[pos] = c;
    return *this;
  }

  String &insert(int pos, const char *first) {
    int iterator = 0;
    for (iterator = 0; first[iterator] != '\0'; iterator++)
      ;

    for (int i = pos, j = 0; j < iterator; i++, j++) {

      Regrow();
      Shifting(i);
      str[i] = first[j];
    }

    return *this;
  }

  String &operator+=(const String &str) {
    *this = *this + str;
    return *this;
  }

  String &operator+=(char c) {
    Regrow();
    str[size - 1] = c;
    str[size] = '\0';
    return *this;
  }

  ~String() { delete[] str; }

  friend ostream &operator<<(ostream &out, const String &a);
  friend istream &operator>>(istream &in, String &a);
};

ostream &operator<<(ostream &out, const String &a) {

  for (int i = 0; i < a.size; i++)
    out << a.str[i];

  return out;
}

istream &operator>>(istream &in, String &a) {
  for (int i = 0; i < a.size; i++)
    in >> a.str[i];

  return in;
}

void printMenu() {
  cout << "\n  ---- String Class ----\n\n";

  cout << "  [1]  Load a new string\n";
  cout << "  [2]  Print current string\n";
  cout << "  [3]  Concatenate strings\n";
  cout << "  [4]  Append a character\n";
  cout << "  [5]  Insert char at index\n";
  cout << "  [6]  Insert substring at index\n";
  cout << "  [7]  Remove first occurrence of char\n";
  cout << "  [8]  Remove last occurrence of char\n";
  cout << "  [9]  Remove all occurrences of char\n";
  cout << " [10]  Remove char at index\n";
  cout << " [11]  Trim whitespace\n";
  cout << " [12]  Find first of char\n";
  cout << " [13]  Find last of char\n";
  cout << " [14]  Find first of substring\n";
  cout << " [15]  Find last of substring\n";
  cout << " [16]  Find all indices of char\n";
  cout << " [17]  Compare with another string\n";
  cout << " [18]  Get char at index\n";
  cout << " [19]  Front and back\n";
  cout << " [20]  Length\n";
  cout << " [21]  Empty check\n";
  cout << " [22]  Clear string\n";
  cout << " [23]  Replace first char\n";
  cout << " [24]  String to int\n";
  cout << " [25]  Int to string\n";
  cout << "  [0]  Quit\n\n";

  cout << "  > ";
}

int main() {
  String current("");
  int choice;

  while (true) {
    system("cls");
    cout << "\n  Active string: \"" << current << "\"" << endl;
    printMenu();
    cin >> choice;

    switch (choice) {

    case 1: {
      char buf[1024];
      cout << "  Enter new string: ";
      cin.ignore();
      cin.getline(buf, 1024);
      current = String(buf);
      cout << "  Set to: \"" << current << "\"\n";
      break;
    }

    case 2: {
      cout << "  \"" << current << "\"\n";
      break;
    }

    case 3: {
      char buf[1024];
      cout << "  Enter string to concatenate: ";
      cin.ignore();
      cin.getline(buf, 1024);
      String other(buf);
      String result = current + other;
      cout << "  Result: \"" << result << "\"\n";
      cout << "  Apply to current? (y/n): ";
      char c;
      cin >> c;
      if (c == 'y' || c == 'Y')
        current = result;
      break;
    }
    case 4: {
      char c;
      cout << "  Char to append: ";
      cin >> c;
      current += c;
      cout << "  Result: \"" << current << "\"\n";
      break;
    }

    case 5: {
      int pos;
      char c;
      cout << "  Position: ";
      cin >> pos;
      cout << "  Char to insert: ";
      cin >> c;
      current.insert(pos, c);
      cout << "  Result: \"" << current << "\"\n";
      break;
    }

    case 6: {
      int pos;
      char buf[1024];
      cout << "  Position: ";
      cin >> pos;
      cout << "  String to insert: ";
      cin.ignore();
      cin.getline(buf, 1024);
      current.insert(pos, buf);
      cout << "  Result: \"" << current << "\"\n";
      break;
    }

    case 7: {
      char c;
      cout << "  Char to remove (first occurrence): ";
      cin >> c;
      current.remove_first(c);
      cout << "  Result: \"" << current << "\"\n";
      break;
    }

    case 8: {
      char c;
      cout << "  Char to remove (last occurrence): ";
      cin >> c;
      current.remove_last(c);
      cout << "  Result: \"" << current << "\"\n";
      break;
    }

    case 9: {
      char c;
      cout << "  Char to remove (all occurrences): ";
      cin >> c;
      current.remove_all(c);
      cout << "  Result: \"" << current << "\"\n";
      break;
    }

    case 10: {
      int idx;
      cout << "  Index to remove: ";
      cin >> idx;
      current.remove_at(idx);
      cout << "  Result: \"" << current << "\"\n";
      break;
    }

    case 11: {
      cout << "  Before: \"" << current << "\"\n";
      current.trim();
      cout << "  After : \"" << current << "\"\n";
      break;
    }

    case 12: {
      char c;
      cout << "  Char to find: ";
      cin >> c;
      int idx = current.find_first(c);
      if (idx == -1)
        cout << "  Not found.\n";
      else
        cout << "  First occurrence of '" << c << "' at index " << idx << "\n";
      break;
    }

    case 13: {
      char c;
      cout << "  Char to find: ";
      cin >> c;
      int idx = current.find_last(c);
      if (idx == -1)
        cout << "  Not found.\n";
      else
        cout << "  Last occurrence of '" << c << "' at index " << idx << "\n";
      break;
    }

    case 14: {
      char buf[1024];
      cout << "  Substring to find: ";
      cin.ignore();
      cin.getline(buf, 1024);
      String sub(buf);
      int idx = current.find_first(sub);
      if (idx == -1)
        cout << "  Not found.\n";
      else
        cout << "  First occurrence of \"" << sub << "\" at index " << idx
             << "\n";
      break;
    }

    case 15: {
      char buf[1024];
      cout << "  Substring to find: ";
      cin.ignore();
      cin.getline(buf, 1024);
      String sub(buf);
      int idx = current.find_last(sub);
      if (idx == -1)
        cout << "  Not found.\n";
      else
        cout << "  Last occurrence of \"" << sub << "\" at index " << idx
             << "\n";
      break;
    }

    case 16: {
      char c;
      cout << "  Char to find all: ";
      cin >> c;
      int sz = 0;
      int *indexes = current.find_all(c, sz);
      if (sz == 0)
        cout << "  Not found.\n";
      else {
        cout << "  '" << c << "' found at indexes: ";
        for (int i = 0; i < sz; i++)
          cout << indexes[i] << " ";
        cout << "\n";
        delete[] indexes;
      }
      break;
    }

    case 17: {
      char buf[1024];
      cout << "  Enter second string to compare: ";
      cin.ignore();
      cin.getline(buf, 1024);
      String other(buf);
      cout << "  \"" << current << "\"  vs  \"" << other << "\"\n";
      cout << "  ==  : " << (current == other ? "T" : "F") << "\n";
      cout << "  !=  : " << (current != other ? "T" : "F") << "\n";
      cout << "  <   : " << (current < other ? "T" : "F") << "\n";
      cout << "  >   : " << (current > other ? "T" : "F") << "\n";
      cout << "  <=  : " << (current <= other ? "T" : "F") << "\n";
      cout << "  >=  : " << (current >= other ? "T" : "F") << "\n";
      break;
    }

      {
        int idx;
        cout << "  Index: ";
        cin >> idx;
        cout << "  str[" << idx << "] = '" << current[idx] << "'\n";
        break;
      }

    case 19: {
      cout << "  front() = '" << current.front() << "'\n";
      cout << "  back()  = '" << current.back() << "'\n";
      break;
    }

    case 20: {
      cout << "  Size = " << current.Size() << "\n";
      break;
    }
    case 21: {
      cout << "  empty() = " << (current.empty() ? "true" : "false") << "\n";
      break;
    }

    case 22: {
      current.clear();
      cout << "  String cleared.\n";
      break;
    }

    case 23: {
      char c;
      cout << "  New first char: ";
      cin >> c;
      current.ReplaceFirst(c);
      cout << "  Result: \"" << current << "\"\n";
      break;
    }
    case 24: {
      cout << "  stoi(\"" << current << "\") = " << current.stoi() << "\n";
      break;
    }

    case 25: {
      int num;
      cout << "  Enter integer: ";
      cin >> num;
      String result = current.itos(num);
      cout << "  itos(" << num << ") = \"" << result << "\"\n";
      break;
    }

    case 0: {
      cout << "\n  Goodbye!\n\n";
      return 0;
    }

    default:
      cout << "  Invalid choice. Try again.\n";
    }
  }

  return 0;
}
