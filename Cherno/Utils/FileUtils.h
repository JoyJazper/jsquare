#pragma once
/*
#include <string>
#include <fstream>

namespace JSquare { namespace utils {
	class FileReader {

		static std::string ReadFile(const char* filepath)
		{
			FILE* file = fopen(filepath, "rb");
			if (file == nullptr)
				std::cout << "Could not open file '" << filepath << "'!" << std::endl;

			fseek(file, 0, SEEK_END);
			unsigned long length = ftell(file);
			char* data = new char[length + 1];
			memset(data, 0, length + 1);
			fseek(file, 0, SEEK_SET);
			fread(data, 1, length, file);
			fclose(file);

			std::string result(data);
			delete[] data;
			return result;
		}


		// std::string ReadFile(const std::string& filepath);
	};
} }