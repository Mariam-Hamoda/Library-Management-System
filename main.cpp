#include <iostream>
#include "Library/clsLibrary.h"
using namespace std;
int main(){
    clsBookManager bookManager;
    clsLibrary library(bookManager);
    library.menu();
}
