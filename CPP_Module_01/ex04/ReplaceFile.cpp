/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ReplaceFile.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momari <momari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 14:14:42 by momari            #+#    #+#             */
/*   Updated: 2024/09/01 15:53:43 by momari           ###   ########.fr       */
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


static void openFile(char *fileName, std::string &fileContent)
{
    std::string line;

    std::ifstream inFile(fileName);
    if (!inFile.is_open())
    {
        std::cout << "Error: opening file ";
        std::cout << fileName;
        std::cout << std::endl;
        exit (1);
    }
    readAllLine(inFile, fileContent);
}

void findAndReplace(std::string &fileContent, std::string s1, std::string s2)
{
    size_t i = 0;
    while ((i = fileContent.find(s1, i)) != std::string::npos) {
        fileContent.replace(i, s1.length(), s2);
        i += s2.length();
    }
}

void replaceFile(char **av)
{
    std::string fileContent;

    openFile(av[1], fileContent);
    findAndReplace(fileContent, av[2], av[3]);
    std::cout << fileContent << std::endl;
}