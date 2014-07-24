To be able to compile PPJS_Storage project in eclipse you need to do the following things:


1.Go to Project -> Properties -> C/C++ Build -> Settings 
then in Tool Settings select Cross G++ Compiler in "Command" field add -std=c++11.
 
2.In Cross G++ Compiler select Includes and add include path project root folder (to be able to use absolute paths).

3.In Cross G++ Linker select Libraries.
Add following libs:
	mongoclient
	boost_thread
	boost_filesystem
	boost_system

Add following search path:
	/usr/lib

