// Workshop 9 - Multi-threading
// TreasureMap.cpp
// Sunny Qi sqi9@myseneca.ca
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <string>
#include <functional>
#include <thread>
#include <future>
#include "TreasureMap.h"

using namespace std;
namespace sdds{

    size_t digForTreasure(const std::string& str, char mark){
        size_t cnt = 0;
        for (auto& x : str){
            if (x == mark){
                cnt++;
            }
        }
        return cnt;
    }

    TreasureMap::TreasureMap(const char* filename){
        std::fstream fin(filename);
        if (fin){
            fin >> rows;
            fin.ignore();
            map = new std::string[rows];
            size_t idx = 0;
            while(fin){
                getline(fin, map[idx]);
                idx++;
            }
            colSize = map[0].length();
        }
        else {
            throw std::string(filename) + " cannot be opened";
        }
    }

    TreasureMap::~TreasureMap(){
        delete [] map;
    }

    std::ostream& TreasureMap::display(std::ostream& os) const{
        if (map){
            for (size_t i = 0; i < rows; ++i){
                os << map[i] << std::endl;
            }
        }
        else 
            os << "The map is empty!" << std::endl;
        return os;
    }

    void TreasureMap::enscribe(const char* filename){
        // Binary write
        if (map){
            // TODO: Open a binary file stream to the filename and
            //         then write the row number to the binary file 
            //         then each of the rows of the map.
            //       If the file cannot be open, raise an exception to
            //         inform the client.
           ofstream os;
           os.open(filename, ios::binary);
           if (os.good())
           {
              // write the row size
              os.write((const char*)&rows, sizeof(rows));
              // write the colsize
              os.write((const char*)&colSize, sizeof(colSize));
              // write the map
              for (size_t i = 0; i < rows; i++)
              {
                 // write each the string
                 os.write(map[i].c_str(), colSize);
              }
              os.close();
              // do we free map here?
           }
           else
           {
              throw std::string(filename) + " cannot be opened";
           }
            // END TODO
        }
        else{
            throw std::string("Treasure map is empty!");
        }
    }

    void TreasureMap::recall(const char* filename){
        // Binary read
        // TODO: Open a binary file stream to the filename
        //         and read from it to populate the current object.
        //       The first 4 bytes of the file will be the number of rows
        //         for the map followed another 4 bytes for the colSize
        //         of each row in the map.
        //       Afterwards is each row of the map itself.
        //       If the file cannot be open, raise an exception to inform
        //         the client.
       ifstream is;
       is.open(filename, ios::binary);
       // do we make sure map is free before doing this?
       if (is.good())
       {
            char current[50] = "";
            // get rows
            is.read((char*)&rows, sizeof(size_t));
            // get colsize
            is.read((char*)&colSize, sizeof(size_t));
            // create map
            map = new string[rows];
            for (size_t i = 0; i < rows; i++)
            {
               is.read((char*)&current, colSize);
               map[i] = current;
               strcpy(current, "");
            }
       }
       else
       {
          throw std::string(filename) + " cannot be opened";
       }


        // END TODO
    }

    void TreasureMap::clear(){
        delete [] map;
        map = nullptr;
        rows = 0;
        colSize = 0;
    }

    size_t TreasureMap::findTreasure(char mark){
        size_t count = 0;

        // TODO: For part 2, comment this "for" loop and write the multihreaded version.
        /*
        for (size_t i = 0; i < rows; ++i){
            count += digForTreasure(map[i], mark);
        }
        */

        auto countTreasure = [&count, mark](string input) {
           count += digForTreasure(input, mark);
        };
        //std::packaged_task<size_t()> pt(digForTreasure(input, mark));
     
        string firstthread;
        string secondthread;
        string thirdthread;
        string fourththread;
        // divide work into 4 evenly split ways
        for (size_t i = 0; i < (rows/4); i++)
        {
           firstthread += map[i];
        }
        for (size_t i = rows/4; i < rows/2; i++)
        {
           secondthread += map[i];
        }
        for (size_t i = rows/2; i < (rows * 3/4); i++)
        {
           thirdthread += map[i];
        }
        for (size_t i = (rows*3/4); i < rows; i++)
        {
           fourththread += map[i];
        }

        // concat the strings into 4 strings
        // create 4 threads to parse each string
        thread t1(countTreasure, firstthread);
        thread t2(countTreasure, secondthread);
        thread t3(countTreasure, thirdthread);
        thread t4(countTreasure, fourththread);

        t1.join();
        t2.join();
        t3.join();
        t4.join();
            // increment the shared count resource
        // wait for each to finish
        // return the the final count
        return count;
    }
}