#include "Copython/Copython.h"

int main(int argc, char ** argv) {
      Py_Initialize();
      cocos2d::initCoco2d();
	  FILE * bbxmain = fopen("app/native/CoMain.py", "r");
	  PyRun_SimpleFile(bbxmain, "__main__");
	  Py_Finalize();
	  return 0;

}
