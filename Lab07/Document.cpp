#include "Document.h"
#include <iostream>
using namespace std;

Document::Document() : lines(nullptr), tracker(0) {};

Document::~Document() { delete[] lines; }

Document::Document(String Line) {
  tracker = 1;
  lines = new String[1]{};
  lines[tracker - 1] = Line;
}

Document::Document(String *arr, int count) {
  tracker = count;
  lines = new String[tracker];

  for (int i = 0; i < count; i++)
    lines[i] = arr[i];
}

void Document::addLine(String _line) {

  Regrow();

  lines[tracker - 1] = _line;
}

void Document::Regrow() {
  String *newptr = new String[tracker + 1];

  for (int i = 0; i < tracker; i++)
    newptr[i] = lines[i];

  delete[] lines;

  tracker++;

  lines = newptr;
}

void Document::Shrink(int index) {
  if (tracker == 0 || index < 0 || index >= tracker)
    return;

  String *newptr = new String[tracker - 1];

  for (int i = 0; i < tracker; i++) {
    if (i == index)
      continue;
    if (i < index)
      newptr[i] = lines[i];
    if (i > index)
      newptr[i - 1] = lines[i];
  }

  delete[] lines;

  tracker--;

  lines = newptr;
}

void Document::removeLine(int idx) { Shrink(idx); }

void Document::insertline(String _line, int idx) {
  if (idx < 0 or idx > tracker + 1)
    return;
  Regrow();
  for (int i = tracker - 1; i > idx; i--)
    lines[i] = lines[i - 1];

  lines[idx] = _line;
}

void Document::display() {
  for (int i = 0; i < tracker; i++)
    cout << lines[i] << "\n";
}
