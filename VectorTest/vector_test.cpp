#include "vector.h"
#include <iostream>
#include "gtest/gtest.h"

TEST(DefaultConstructorTest, Positive) {
  Vector vector;
  ASSERT_EQ(vector.getCapacity(), 0);
  ASSERT_EQ(vector.getSize(), 0);
}

TEST(ConstructorWithSize, Positive) {
  Vector vector(3);
  ASSERT_EQ(vector.getSize(), 3);
  ASSERT_EQ(vector.getCapacity(), 3);
}

TEST(ContructorInitListTest, Positive) {
  Vector vectorActual({1, 2, 3});
  ASSERT_EQ(vectorActual[0], 1);
  ASSERT_EQ(vectorActual[1], 2);
  ASSERT_EQ(vectorActual[2], 3);
  ASSERT_EQ(vectorActual.getSize(), 3);
  ASSERT_EQ(vectorActual.getCapacity(), 3);
}

TEST(CopyConstructorTest, Positive) {
  Vector vector({1, 2, 3});
  Vector vectorCopy(vector);
  ASSERT_EQ(vector, vectorCopy);
}

TEST(MoveConsturctorTest, Positive) {
  Vector vector({1, 2, 3});
  Vector vectorMove(std::move(vector));
  ASSERT_EQ(vectorMove.getSize(), 3);
  ASSERT_EQ(vectorMove[0], 1);
  ASSERT_EQ(vectorMove[1], 2);
  ASSERT_EQ(vectorMove[2], 3);
  ASSERT_EQ(vector.getSize(), 0);
  ASSERT_EQ(vector.getCapacity(), 0);
}

TEST(GetSizeTest, Positive) {
  Vector vector({1, 2, 3});
  ASSERT_EQ(vector.getSize(), 3);
}

TEST(GetCapacityTest, Positive) {
  Vector vector;
  vector.append(1);
  vector.append(2);
  vector.append(3);
  ASSERT_EQ(vector.getCapacity(), 4);
}

TEST(AppendTest, Positive) {
  Vector vector;
  vector.append(1);
  vector.append(2);
  vector.append(3);
  ASSERT_EQ(vector[0], 1);
  ASSERT_EQ(vector[1], 2);
  ASSERT_EQ(vector[2], 3);
}

TEST(AssignmentOperatorTest, Positive) {
  Vector vector({1, 2, 3});
  Vector vectorAssigned;
  vectorAssigned = vector;
  ASSERT_EQ(vector, vectorAssigned);
}

TEST(MoveAssignmentOperatorTest, Positive) {
  Vector vector({1, 2, 3});
  Vector vectorMove;
  vectorMove = std::move(vector);
  ASSERT_EQ(vectorMove.getSize(), 3);
  ASSERT_EQ(vectorMove[0], 1);
  ASSERT_EQ(vectorMove[1], 2);
  ASSERT_EQ(vectorMove[2], 3);
  ASSERT_EQ(vector.getSize(), 0);
  ASSERT_EQ(vector.getCapacity(), 0);
}

TEST(OperatorPlusTest, Positive) {
  Vector vector({1, 2, 3});
  Vector vector1({4, 5, 6});
  Vector vectorExpected({5, 7, 9});
  ASSERT_EQ(vector + vector1, vectorExpected);
}

TEST(OperatorMinusTest, Positive) {
  Vector vector({1, 2, 3});
  Vector vector1({4, 5, 6});
  Vector vectorExpected({3, 3, 3});
  ASSERT_EQ(vector1 - vector, vectorExpected);
}

TEST(OperatorMultiplyLeftConstTest, Positive) {
  Vector vector({1, 2, 3});
  Vector vectorExpected({2, 4, 6});
  ASSERT_EQ(2 * vector, vectorExpected);
}

TEST(OperatorMultiplyRightConstTest, Positive) {
  Vector vector({
      1,
      2,
      3,
  });
  Vector vectorExpected({2, 4, 6});
  ASSERT_EQ(vector * 2, vectorExpected);
}

TEST(OperatorEqualTest, Positive) {
  Vector vector({1, 2, 3});
  Vector vector1({1, 2, 3});
  ASSERT_TRUE(vector == vector1);
}

TEST(OperatorNotEqualTest, Positive) {
  Vector vector({1, 2, 3});
  Vector vector1({3, 2, 1});
  ASSERT_TRUE(vector != vector1);
}

TEST(OperatorIndexTest, Positive) {
  Vector vector({1, 2, 3});
  vector[0] = 3;
  vector[1] = 2;
  vector[2] = 1;
  Vector vectorExpected({3, 2, 1});
  ASSERT_EQ(vector, vectorExpected);
}

TEST(OperatorIndexConstTest, Positive) {
  const Vector vector({1, 2, 3});
  ASSERT_EQ(vector[0], 1);
  ASSERT_EQ(vector[1], 2);
  ASSERT_EQ(vector[2], 3);
}

TEST(OperatorOutTest, Positive) {
  Vector vector({1, 2, 3});
  std::stringstream out;
  out << vector;
  ASSERT_EQ(out.str(), "3 1 2 3 ");
}

TEST(OperatorInTest, Positive) {
  Vector vector;
  std::stringstream in("3 1 2 3");
  in >> vector;
  ASSERT_EQ(vector[0], 1);
  ASSERT_EQ(vector[1], 2);
  ASSERT_EQ(vector[2], 3);
  ASSERT_EQ(vector.getSize(), 3);
  ASSERT_EQ(vector.getCapacity(), 3);
}
