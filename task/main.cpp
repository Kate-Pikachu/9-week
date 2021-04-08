#include <iostream>
#include <string>

#include <boost/interprocess/managed_shared_memory.hpp>
#include <boost/interprocess/allocators/allocator.hpp>
#include <boost/interprocess/containers/string.hpp>
#include <boost/interprocess/containers/vector.hpp>




// задача: создать мессенджер

// реализовать одно приложение из двух экземпляров, которые могут быть запущены одновременно
// запуск 1 экземпляра - создание участка с общимим данными - принимает сообщение
//		реализация: межпроцессорное отображение (ключ - ID, значение - сообщение, хранящееся в виде межпроцессорной строки) - получим межпроцессорные контейнер контейнеров

//			сделать большой размер разделяемой памяти
//			взаимодействие с пользователем через стандартные потоки ввода - вывода
//		ввод сообщения в 1 экземпляре - отображение во 2 экземпляре, извлечение из него
//	запуск нового экземпляра - вывод истории сообщений, хранящуюя в разделяемой памяти 


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

	typedef int key;  // создали ключ
	typedef std::string message; // и создали значение для обеспечения межпроцессорного отображения









	boost::interprocess::shared_memory_object::remove(shared_memory_name.c_str());

	system("pause");
	return EXIT_SUCCESS;
}
