
#include <iostream>
#include <string>
#include <gtest/gtest.h>
#include "binsearch_collection.h"

using namespace std;
//Test 1
TEST(BasicCollectionTest, CorrectSize){
 BinSearchCollection<string, double> c;
 ASSERT_EQ(c.size(), 0);
 c.insert("a", 10.0);
 ASSERT_EQ(c.size(), 1);
 c.insert("b", 20.0);
 ASSERT_EQ(c.size(), 2);
}

//Test 2
TEST(BasicCollectionTest, InsertAndFind){
  BinSearchCollection<string, double> c;
  double v;
  //ASSERT_EQ(c.find("a", v), false);
  c.insert("a", 10.0);
  ASSERT_EQ(c.find("a", v), true);
  ASSERT_EQ(v, 10.0);
  ASSERT_EQ(c.find("b", v), false);
  c.insert("b", 20.0);
  ASSERT_EQ(c.find("b", v), true);
  ASSERT_EQ(v, 20.0);
}

//Test 3
TEST(BasicCollectionTest, RemoveElems){
  BinSearchCollection<string, double> c;
  c.insert("a", 10.0);
  c.insert("b", 20.0);
  c.insert("c", 30.0);
  double v;
  c.remove("a");
  ASSERT_EQ(c.find("a", v), false);
  c.remove("b");
  ASSERT_EQ(c.find("b", v), false);
  c.remove("c");
  ASSERT_EQ(c.find("c", v), false);
  ASSERT_EQ(c.size(), 0);
}

//Test 4
TEST(BasicCollectionTest, GetKeys){
  BinSearchCollection<string, double> c;
  c.insert("a", 10.0);
  c.insert("b", 20.0);
  c.insert("c", 30.0);
  vector<string> ks;
  c.keys(ks);
  vector<string>::iterator iter;
  iter = find(ks.begin(), ks.end(), "a");
  ASSERT_NE(iter, ks.end());

  iter = find(ks.begin(), ks.end(), "b");
  ASSERT_NE(iter, ks.end());
  iter = find(ks.begin(), ks.end(), "c");
  ASSERT_NE(iter, ks.end());
}

//Test 5
TEST(BasicCollectionTest, GetKeyRange){
  BinSearchCollection<string, double> c;
  c.insert("a", 10.0);
  c.insert("b", 20.0);
  c.insert("c", 30.0);
  c.insert("d", 40.0);
  c.insert("e", 50.0);
  vector<string> ks;
  c.find("b", "d", ks);
  double v;
  ASSERT_EQ(c.find("b", v), true);
  ASSERT_EQ(c.find("c", v), true);
  ASSERT_EQ(c.find("d", v), true);
}

//Test 6
TEST(BasicCollectionTest, KeySort)
{
  BinSearchCollection<string, double> c;
  c.insert("c", 30.0);
  c.insert("b", 20.0);
  c.insert("a", 10.0);
  c.insert("d", 40.0);
  vector<string> sorted_ks;
  c.sort(sorted_ks);

  for (int i = 0; i < int(sorted_ks.size()) - 1; ++i)
    ASSERT_LE(sorted_ks[i], sorted_ks[i+1]);
}


TEST (BasicCollectionTest, BinSearchEven)
{
  BinSearchCollection<string, double> c;
  c.insert("a", 10.0);
  c.insert("b", 20.0);
  c.insert("c", 30.0);
  c.insert("d", 40.0);
  c.insert("e", 50.0);
  c.insert("f", 60.0);
  vector<string> k;
  c.keys(k);
  double v;
  ASSERT_EQ(c.size() % 2, 0);
  ASSERT_EQ(c.find("a", v), true);
  ASSERT_EQ(k[0], "a");
  ASSERT_EQ(v, 10.0);
  ASSERT_EQ(c.find("b", v), true);
  ASSERT_EQ(k[1], "b");
  ASSERT_EQ(v, 20.0);
  ASSERT_EQ(c.find("c", v), true);
  ASSERT_EQ(k[2], "c");
  ASSERT_EQ(v, 30.0);
  ASSERT_EQ(c.find("d", v), true);
  ASSERT_EQ(k[3], "d");
  ASSERT_EQ(v, 40.0);
  ASSERT_EQ(c.find("e", v), true);
  ASSERT_EQ(k[4], "e");
  ASSERT_EQ(v, 50.0);
  ASSERT_EQ(c.find("f", v), true);
  ASSERT_EQ(k[5], "f");
  ASSERT_EQ(v, 60.0);
}


TEST (BasicCollectionTest, BinSearchOdd)
{
  BinSearchCollection<string, double> c;
  c.insert("a", 10.0);
  c.insert("b", 20.0);
  c.insert("c", 30.0);
  c.insert("d", 40.0);
  c.insert("e", 50.0);
  c.insert("f", 60.0);
  c.insert("g", 70.0);
  vector<string> k;
  c.keys(k);
  double v;
  ASSERT_EQ(c.size() % 2, 1);
  ASSERT_EQ(c.find("a", v), true);
  ASSERT_EQ(k[0], "a");
  ASSERT_EQ(v, 10.0);
  ASSERT_EQ(c.find("b", v), true);
  ASSERT_EQ(k[1], "b");
  ASSERT_EQ(v, 20.0);
  ASSERT_EQ(c.find("c", v), true);
  ASSERT_EQ(k[2], "c");
  ASSERT_EQ(v, 30.0);
  ASSERT_EQ(c.find("d", v), true);
  ASSERT_EQ(k[3], "d");
  ASSERT_EQ(v, 40.0);
  ASSERT_EQ(c.find("e", v), true);
  ASSERT_EQ(k[4], "e");
  ASSERT_EQ(v, 50.0);
  ASSERT_EQ(c.find("f", v), true);
  ASSERT_EQ(k[5], "f");
  ASSERT_EQ(v, 60.0);
  ASSERT_EQ(c.find("g", v), true);
  ASSERT_EQ(k[6], "g");
  ASSERT_EQ(v, 70.0);

}


int main(int argc, char** argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
