#include <iostream>
#include <string>

#include <boost/interprocess/managed_shared_memory.hpp>
#include <boost/interprocess/allocators/allocator.hpp>
#include <boost/interprocess/containers/string.hpp>
#include <boost/interprocess/containers/vector.hpp>




// ������: ������� ����������

// ����������� ���� ���������� �� ���� �����������, ������� ����� ���� �������� ������������
// ������ 1 ���������� - �������� ������� � ������� ������� - ��������� ���������
//		����������: ��������������� ����������� (���� - ID, �������� - ���������, ���������� � ���� ��������������� ������) - ������� ��������������� ��������� �����������

//			������� ������� ������ ����������� ������
//			�������������� � ������������� ����� ����������� ������ ����� - ������
//		���� ��������� � 1 ���������� - ����������� �� 2 ����������, ���������� �� ����
//	������ ������ ���������� - ����� ������� ���������, ��������� � ����������� ������ 


int main(int argc, char** argv)
{
	setlocale(LC_ALL, "Russian");
	using allocator = boost::interprocess::allocator < char,
		boost::interprocess::managed_shared_memory::segment_manager >;

	using string = boost::interprocess::basic_string < char,
		std::char_traits < char >, allocator>;

	const std::string shared_memory_name = "memory";

	boost::interprocess::shared_memory_object::remove(shared_memory_name.c_str());

	boost::interprocess::managed_shared_memory shared_memory(
		boost::interprocess::open_or_create, shared_memory_name.c_str(), 1024);

	typedef int key; // ������� ����
	typedef std::string message; // � ������� �������� ��� ����������� ���������������� �����������










	boost::interprocess::shared_memory_object::remove(shared_memory_name.c_str());

	system("pause");
	return EXIT_SUCCESS;
}