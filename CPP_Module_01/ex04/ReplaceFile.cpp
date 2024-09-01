/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ReplaceFile.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momari <momari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 14:14:42 by momari            #+#    #+#             */
/*   Updated: 2024/09/01 16:43:33 by momari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ReplaceFile.hpp"

void readAllLine(std::istream& inFile, std::string &fileContent)
{
    char c;

    while (inFile.get(c)) {
        fileContent += c;
    }
}


static void openInFile(char *fileName, std::string &fileContent)
{
    std::string line;

    std::ifstream inFile(fileName);
    if (!inFile.is_open())
    {
        std::cout << "Error: opening infile ";
        std::cout << fileName;
        std::cout << std::endl;
        exit (1);
    }
    readAllLine(inFile, fileContent);
    inFile.close();
}

void findAndReplace(std::string &fileContent, std::string s1, std::string s2)
{
    size_t i = 0;
    if (s1.empty())
        return ;
    std::cout << "test" << std::endl;
    while ((i = fileContent.find(s1, i)) != std::string::npos) {
        fileContent.erase(i, s1.length());
        fileContent.insert(i, s2);
        i += s2.length();
    }
}

void openOutFile(std::string fileContent, std::string fileName)
{
    (void) fileContent;
    std::string outFileName = fileName + ".replace";
    std::fstream outFile(outFileName, std::ios::out | std::ios::app);
    if (!outFile.is_open())
    {
        std::cout << "Error: opening outfile ";
        std::cout << outFileName;
        std::cout << std::endl;
        exit (1);
    }
    
}

void replaceFile(char **av)
{
    std::string fileContent;

    openInFile(av[1], fileContent);
    findAndReplace(fileContent, av[2], av[3]);
    openOutFile(fileContent, av[1]);
}