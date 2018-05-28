//
//  lww_set.hpp
//  lww
//
//  Created by Kevin on 23/05/2018.
//  Copyright © 2018 Kevin. All rights reserved.
//
//  Reference: lww-element-set in Python https://github.com/junjizhi/lww-element-set

#ifndef lww_set_hpp
#define lww_set_hpp

#include <iostream>
#include <map>
#include <string>

using namespace std;

class lww_set {
private:
  const int MAX_STRING = 29;
  map<string, float>::iterator iter; // map<key, value>
  
  map<string, float> add_set;
  map<string, float> remove_set;
  
public:
  bool testAndExecute(map<string, float> &target_set, string element, float current_timestamp);
  void add(string element, float current_timestamp);
  void remove(string element, float current_timestamp);
  bool exist(string element);
  void get();
  void showAll();
};

#endif /* lww_set_hpp */
