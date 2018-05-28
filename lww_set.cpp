//
//  lww_set.cpp
//  lww
//
//  Created by Kevin on 23/05/2018.
//  Copyright © 2018 Kevin. All rights reserved.
//
//  Reference: lww-element-set in Python https://github.com/junjizhi/lww-element-set

#include "lww_set.hpp"

bool lww_set::testAndExecute(map<string, float> &target_set, string element, float current_timestamp) {
  /*  update timestamp if same element is found and current timestamp is higher or identical
   (and return true to provide clue for remove operation)
   insert element and timestamp if the element does not exist in target set (either add or remove)
   */
  bool flag = false;
  for (iter = target_set.begin(); iter != target_set.end(); iter++) {
    if ((*iter).first == element) { // same element found
      if ((*iter).second <= current_timestamp) {
        (*iter).second = current_timestamp; // update timestamp
        flag = true; // clue for remove function
      }
    }
  }
  if (flag == false) { // insert element
    // member function insert() itself ignores lower timestamp
    target_set.insert(pair<string, double>(element, current_timestamp));
  }
  return flag;
}

void lww_set::add(string element, float current_timestamp) {
  testAndExecute(add_set, element, current_timestamp); // update add_set
}

void lww_set::remove(string element, float current_timestamp) {
  testAndExecute(remove_set, element, current_timestamp); // update remove_set
  if (testAndExecute(add_set, element, current_timestamp)) { // remove from add_set
    add_set.erase(element); // erase element from map
  }
}

bool lww_set::exist(string element) {
  bool flag = false;
  for (iter = add_set.begin(); iter != add_set.end(); iter++) {
    if ((*iter).first == element) { // same element found
      flag = true;
    }
  }
  return flag;
}

void lww_set::get() {
  for (iter = add_set.begin(); iter != add_set.end(); iter++) {
    cout << "[" << (*iter).first << ", " << (*iter).second << "]" << " " ;
  }
  cout << endl;
}

void lww_set::showAll() {
  cout << "===== SHOW ALL =====" << endl;
  cout << "A: ";
  for (iter = add_set.begin(); iter != add_set.end(); iter++) {
    cout << "[" << (*iter).first << ", " << (*iter).second << "]" << " " ;
  }
  cout << endl;
  cout << "R: ";
  for (iter = remove_set.begin(); iter != remove_set.end(); iter++) {
    cout << "[" << (*iter).first << ", " << (*iter).second << "]" << " " ;
  }
  cout << endl;
}
