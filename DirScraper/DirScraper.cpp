
#include "pch.h"
#include <iostream>
#include <fstream>
#include <experimental/filesystem>

using namespace std;
namespace fs = std::experimental::filesystem;

void scraper_dir(string path);

int main(int argc, char* argv[])
{
	std::cout << argv[1] << std::endl;
	scraper_dir(argv[1]);
	return 0;
}

void scraper_dir(std::string path)
{
	std::ofstream writer;
	writer.open(path + "/list.txt");
	if (!writer)
	{
		std::cerr << "Error opening file " << path+"/list.txt" << endl;
		exit(1);
	}
	for (fs::recursive_directory_iterator iter(path), end; iter != end; ++iter)
	{
		std::string file_path = iter->path().string();
		writer << file_path << endl;
	}
	writer.close();
}

