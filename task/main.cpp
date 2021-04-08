#include <iostream>
#include <string>

#include <boost/interprocess/managed_shared_memory.hpp>
#include <boost/interprocess/allocators/allocator.hpp>
#include <boost/interprocess/containers/string.hpp>
#include <boost/interprocess/containers/vector.hpp>




// задача: создать мессенджер

// реализовать одно приложение из двух экземпл€ров, которые могут быть запущены одновременно
// запуск 1 экземпл€ра - создание участка с общимим данными - принимает сообщение
//		реализаци€: межпроцессорное отображение (ключ - ID, значение - сообщение, хран€щеес€ в виде межпроцессорной строки) - получим межпроцессорные контейнер контейнеров

//			сделать большой размер раздел€емой пам€ти
//			взаимодействие с пользователем через стандартные потоки ввода - вывода
//		ввод сообщени€ в 1 экземпл€ре - отображение во 2 экземпл€ре, извлечение из него
//	запуск нового экземпл€ра - вывод истории сообщений, хран€щую€ в раздел€емой пам€ти 


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

	typedef int key; // создали ключ
	typedef std::string message; // и создали значение дл€ обеспечени€ межпроцессорного отображени€










	boost::interprocess::shared_memory_object::remove(shared_memory_name.c_str());

	system("pause");
	return EXIT_SUCCESS;
}