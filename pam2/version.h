#ifndef VERSION_H
#define VERSION_H

namespace AutoVersion{
	
	//Date Version Types
	static const char DATE[] = "26";
	static const char MONTH[] = "08";
	static const char YEAR[] = "2018";
	static const char UBUNTU_VERSION_STYLE[] =  "18.08";
	
	//Software Status
	static const char STATUS[] =  "Release";
	static const char STATUS_SHORT[] =  "r";
	
	//Standard Version Type
	static const long MAJOR  = 1;
	static const long MINOR  = 0;
	static const long BUILD  = 595;
	static const long REVISION  = 3396;
	
	//Miscellaneous Version Types
	static const long BUILDS_COUNT  = 1638;
	#define RC_FILEVERSION 1,0,595,3396
	#define RC_FILEVERSION_STRING "1, 0, 595, 3396\0"
	static const char FULLVERSION_STRING [] = "1.0.595.3396";
	
	//These values are to keep track of your versioning state, don't modify them.
	static const long BUILD_HISTORY  = 0;
	

}
#endif //VERSION_H
