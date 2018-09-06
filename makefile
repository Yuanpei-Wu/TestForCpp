delete_test:
	g++ -g -o delete_test delete_test.cpp
move_test:move_test.cpp
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
ref_test:ref_test.cpp
	g++ -g  -std=c++11 -o  ref_test ref_test.cpp
backinsert_test:
	g++ -g  -std=c++11 -o  backinsert_test backinsert_test.cpp
compare_between_size_t_and_int:compare_between_size_t_and_int.cpp
	g++ -g  -std=c++11 -o  compare_between_size_t_and_int_test compare_between_size_t_and_int.cpp
function_parameter:function_parameter.cpp
	g++ -g -std=c++11 -o function_parameter_test function_parameter.cpp
pass_by_reference_or_value:pass_by_reference_or_value.cpp
	g++ -g -std=c++11 -o pass_by_reference_or_value_test pass_by_reference_or_value.cpp
inherit_test:inherit_test.cpp
	g++ -g -std=c++11 -o inherit_test inherit_test.cpp
vector_valid_test:vector_valid.cpp
	g++ -g -std=c++11 -o vector_valid_test vector_valid.cpp
vector_check_test:vector_check.cpp
	g++ -g -std=c++11 -o vector_check_test vector_check.cpp
typeid_test:typeid_test.cpp
	g++ -g -std=c++11 -o typeid_test typeid_test.cpp
type_minus_test:type_minus.cpp
	g++ -std=c++11 -o type_minus_test type_minus.cpp
member_function_test:member_function_test.cpp
	g++ -std=c++11 -o member_function_test member_function_test.cpp
shared_ptr_test:shared_ptr_test.cpp
	g++ -std=c++11 -o shared_ptr_test shared_ptr_test.cpp
virtual_table_test:virtual_table_test.cpp
	g++ -std=c++11 -o virtual_table_test virtual_table_test.cpp
member_construct_test:member_construct_test.cpp
	g++ -std=c++11 -o member_construct_test member_construct_test.cpp
data_member_layout_test:data_member_layout.cpp
	g++ -std=c++11 -o data_member_layout_test data_member_layout.cpp
clean:
	rm *test *~
