import sys
sys.path.append('app/native/PythonProyect/')	
sys.path.append('shared/documents')

import datetime
import main

def _main():
	main.main()

if __name__ == "__main__":
	#print 'start:', datetime.datetime.now()		
	#print '-' * 40
	_main()
	#print '-' * 40
	#print 'end:', datetime.datetime.now()