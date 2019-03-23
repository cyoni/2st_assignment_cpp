/**
 * Examples of automatic tests for the exercise on binary trees.
 *
 * @author Erel Segal-Halevi
 * @since 2019-02
 */

#include <iostream>
using std::cout, std::endl;
#include "badkan.hpp"
#include "Tree.hpp"

int main() {
  ariel::Tree emptytree;
  ariel::Tree threetree;  
  threetree.insert(5);
  threetree.insert(7);
  threetree.insert(3);
  
  ariel::Tree mytree;  

  mytree.insert(46);
  mytree.insert(72);
  mytree.insert(13);
  mytree.insert(7);
  mytree.insert(11);
  mytree.insert(30);
  mytree.insert(27);
  mytree.insert(25);
  mytree.insert(17);
  mytree.insert(20);
  mytree.insert(19);
  mytree.insert(21);


  badkan::TestCase tc("Binary tree");
  tc
  .CHECK_EQUAL (emptytree.size(), 0)
  .CHECK_OK    (emptytree.insert(5))
  .CHECK_EQUAL (emptytree.size(), 1)
  .CHECK_EQUAL (emptytree.contains(5), true)
  .CHECK_OK    (emptytree.remove(5))
  .CHECK_EQUAL (emptytree.contains(5), false)
  .CHECK_THROWS(emptytree.remove(5))
  .CHECK_EQUAL (emptytree.size() ,0)
  
  .CHECK_EQUAL (threetree.size(), 3)
  .CHECK_EQUAL (threetree.root(), 5)
  .CHECK_EQUAL (threetree.parent(3), 5)
  .CHECK_EQUAL (threetree.parent(7), 5)
  .CHECK_EQUAL (threetree.left(5), 3)
  .CHECK_EQUAL (threetree.right(5), 7)
  .CHECK_THROWS(threetree.insert(3))
  .CHECK_THROWS(threetree.left(6))
  .CHECK_OK    (threetree.print())

// my tests
  .CHECK_EQUAL (mytree.size() ,12)
  .CHECK_EQUAL (mytree.parent(21), 20)
  .CHECK_EQUAL (mytree.left(20), 19)
  .CHECK_THROWS(mytree.insert(20))
  .CHECK_THROWS(mytree.parent(100))
  .CHECK_THROWS(mytree.left(19))
  .CHECK_THROWS(mytree.parent(46))
  .CHECK_OK    (mytree.remove(27))
  .CHECK_EQUAL (mytree.parent(17), 25)
  .CHECK_THROWS    (mytree.right(30))
  .CHECK_EQUAL (mytree.left(30), 25)
  .CHECK_OK    (mytree.remove(13))
  .CHECK_EQUAL (mytree.left(46), 17)
  .CHECK_EQUAL (mytree.right(46), 72)
  .CHECK_OK    (mytree.remove(30))
  .CHECK_EQUAL (mytree.right(17), 25)
  .CHECK_OK    (mytree.remove(20).remove(19).remove(21).remove(17).remove(7).remove(25))
  .CHECK_EQUAL (mytree.left(46), 11)
  .CHECK_OK(mytree.remove(46))
  .CHECK_EQUAL (mytree.root(), 72)
  .CHECK_EQUAL (mytree.size(), 2)
  .CHECK_OK(mytree.remove(72).remove(11))
  .CHECK_EQUAL (emptytree.contains(46), false)
  .CHECK_OK(mytree.insert(10).insert(2).insert(5))
  .CHECK_THROWS(mytree.left(5))
  .CHECK_EQUAL (mytree.size() ,3)
  .CHECK_OK    (mytree.print());
  
  cout << "You have " << tc.right() << " right answers and " << tc.wrong() << " wrong answers so your grade is " << tc.grade() << ". Great!" << endl;
}
