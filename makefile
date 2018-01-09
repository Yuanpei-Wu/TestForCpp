delete_test:
	g++ -g -o delete_test delete_test.cpp
move_test:
	g++ -g  -std=c++11 -o  move_test move_test.cpp
sizeof_test:
	g++ -g  -std=c++11 -o  sizeof_test sizeof_test.cpp
stl_config_test:
	g++ -g  -std=c++11 -o  stl_config_test stl_config_test.cpp
stl_iterator_test:
	g++ -g  -std=c++11 -o  stl_iterator_test stl_iterator_test.cpp
set_test:
	g++ -g  -std=c++11 -o  set_test set_test.cpp
private_test:
	g++ -g  -std=c++11 -o  private_test private_test.cpp
ref_test:
	g++ -g  -std=c++11 -o  ref_test ref_test.cpp
backinsert_test:
	g++ -g  -std=c++11 -o  backinsert_test backinsert_test.cpp



clean:
	rm *test
clear:
	rm *~
