//
//  main.cpp
//  lww
//
//  Created by Kevin on 21/05/2018.
//  Copyright © 2018 Kevin. All rights reserved.
//

#include <iostream>
#include "lww_set.hpp"

int main(int argc, const char * argv[]) {
  
  lww_set LWW;
  
  LWW.add("Kevin",5);
  LWW.add("Kevin",4);
  LWW.add("Avengers", 5);
  LWW.remove("Avengers", 4);
  LWW.remove("Avengers", 3);
  LWW.add("Avengers", 3);
  LWW.remove("Avengers", 5);
  
  cout << LWW.exist("Kevin") << endl;

  LWW.get();
  
  LWW.showAll();
  
  return 0;
}
