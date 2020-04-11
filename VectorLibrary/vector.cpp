#include "vector.h"

#include <iostream>

/// Default Constructor
Vector::Vector() : m_size(0), m_capacity(0) {
  m_array = std::make_unique<int[]>(m_capacity);
}

/// Constructor with size
/// \param size of new vector
Vector::Vector(int size)
    : m_size(size), m_capacity(size), m_array(new int[size]) {}

/// Constructor with initializer list
/// \param initializerList of elements for new vector
Vector::Vector(std::initializer_list<int> initializerList)
    : m_array(new int[initializerList.size()]),
      m_size(initializerList.size()),
      m_capacity(initializerList.size()) {
  std::copy(initializerList.begin(), initializerList.end(), m_array.get());
}

/// Copy constructor
/// \param vector to be copy in new vector
Vector::Vector(const Vector& vector)
    : m_size(vector.m_size),
      m_capacity(vector.m_size),
      m_array(new int[vector.m_size]) {
  std::copy(vector.m_array.get(), vector.m_array.get() + vector.m_size,
            m_array.get());
}

/// Move constructor
/// \param vector to be moved in new vector
Vector::Vector(Vector&& vector) noexcept
    : m_size(vector.m_size), m_array(std::move(vector.m_array)) {
  vector.m_size = 0;
  vector.m_capacity = 0;
  vector.m_array = std::make_unique<int[]>(0);
}

/// Get size of vector
/// \return size of vector
int Vector::getSize() const { return m_size; }

/// Get capacity of vector.
/// \return capacity of vector
int Vector::getCapacity() const { return m_capacity; }

/// Add new element at the end of vector.
/// \param value to add
void Vector::append(int value) {
  if (m_capacity == m_size) {
    m_capacity = m_capacity * 2;
    if (!m_capacity) {
      m_capacity = 1;
    }
    int* tmpArray = new int[m_capacity];
    std::copy(m_array.get(), m_array.get() + m_size, tmpArray);
    m_array.reset(tmpArray);
  }
  m_array[m_size++] = value;
}

/// Assignment operator.
/// \param vector to be assigned
/// \return
Vector& Vector::operator=(const Vector& vector) {
  if (this != &vector) {
    if (vector.m_size > m_capacity) {
      m_capacity = vector.m_size;
      m_array.reset(new int[m_capacity]);
    }
    m_size = vector.m_size;
    std::copy(vector.m_array.get(), vector.m_array.get() + m_size,
              m_array.get());
  }
  return *this;
}

/// Move assignment operator.
/// \param vector to be moved
/// \return
Vector& Vector::operator=(Vector&& vector) noexcept {
  if (this != &vector) {
    m_size = vector.m_size;
    m_capacity = vector.m_capacity;
    m_array = std::move(vector.m_array);
    vector.m_size = 0;
    vector.m_capacity = 0;
    vector.m_array = std::make_unique<int[]>(0);
  }
  return *this;
}

/// Operator plus.
/// \param vector - left operand
/// \return vector as result of componentwise addition of two vectors
Vector Vector::operator+(const Vector& vector) const {
  Vector resultVector(m_size);
  std::transform(m_array.get(), m_array.get() + m_size, vector.m_array.get(),
                 resultVector.m_array.get(), std::plus<>{});
  return resultVector;
}

/// Operator minus.
/// \param vector - left operand
/// \return vector as result of componentwise subtraction of two vectors
Vector Vector::operator-(const Vector& vector) const {
  Vector resultVector(m_size);
  std::transform(m_array.get(), m_array.get() + m_size, vector.m_array.get(),
                 resultVector.m_array.get(), std::minus<>{});
  return resultVector;
}

/// Operator multiply.
/// \param operand - right operand
/// \return vector as result of componentwise multiplication of vector and
/// number right
Vector Vector::operator*(int operand) const {
  Vector tmpVector(*this);
  std::transform(m_array.get(), m_array.get() + m_size, tmpVector.m_array.get(),

                 [operand](int value) { return value * operand; });
  return tmpVector;
}

/// Operator multiply.
/// \param operand - left operand
/// \return vector as result of componentwise multiplication of vector and
/// number left
Vector operator*(int operand, const Vector& vector) { return vector * operand; }

/// Operator equal
/// \param vector - left operand
/// \return true if two vectors are equal, false otherwise
bool Vector::operator==(const Vector& vector) const {
  return std::equal(m_array.get(), m_array.get() + m_size,
                    vector.m_array.get()) &&
         m_size == vector.m_size;
}

/// Operator not equal
/// \param vector - left operand
/// \return true if two vectors aren't equal, false otherwise
bool Vector::operator!=(const Vector& vector) const {
  return !(*this == vector);
}

/// Indexing operator.
/// \param i - index of element
/// \return element of vector
int& Vector::operator[](int i) { return m_array[i]; }

/// Const indexing operator.
/// \param i - index of element
/// \return const element of vector
const int& Vector::operator[](int i) const { return m_array[i]; }

/// Output operator.
/// \param out - std::ostream object
/// \param vector to print
/// \return std::ostream object
std::ostream& operator<<(std::ostream& out, const Vector& vector) {
  out << vector.getSize() << " ";
  for (int i = 0; i < vector.m_size; ++i) {
    out << vector.m_array[i] << " ";
  }
  return out;
}

/// Input operator.
/// \param in - std::istream object
/// \param vector to enter
/// \return std::istream object
std::istream& operator>>(std::istream& in, Vector& vector) {
  int size;
  in >> size;
  if (size > vector.m_capacity) {
    vector.m_array.reset(new int[size]);
    vector.m_capacity = size;
    vector.m_size = size;
  }
  std::istream_iterator<int> it(in);
  std::copy_n(it, size, vector.m_array.get());
  return in;
}

/// Destructor
Vector::~Vector() = default;
