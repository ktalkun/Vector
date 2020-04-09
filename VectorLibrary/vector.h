#ifndef VECTORLIBRARY_LIBRARY_H
#define VECTORLIBRARY_LIBRARY_H

#include <algorithm>
#include <iostream>
#include <memory>
#include <regex>
#include <vector>

class Vector {
  std::unique_ptr<int[]> m_array;
  size_t m_size;
  size_t m_capacity;

 public:
  Vector();

  explicit Vector(int size);

  Vector(std::initializer_list<int> initializerList);

  Vector(const Vector &vector);

  Vector(Vector &&vector) noexcept;

  int getSize() const;

  int getCapacity() const;

  void append(int value);

  Vector &operator=(const Vector &vector);

  Vector &operator=(Vector &&vector) noexcept;

  Vector operator+(const Vector &vector) const;

  Vector operator-(const Vector &vector) const;

  Vector operator*(int operand) const;

  friend Vector operator*(int operand, const Vector &vector);

  bool operator==(const Vector &vector) const;

  bool operator!=(const Vector &vector) const;

  int &operator[](int i);

  const int &operator[](int i) const;

  friend std::ostream &operator<<(std::ostream &out, const Vector &vector);

  friend std::istream &operator>>(std::istream &in, Vector &vector);

  ~Vector();
};

#endif  // VECTORLIBRARY_LIBRARY_H
