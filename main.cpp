#include <iostream>
#include <vector>
#include <iterator>
#include <set>
#include <list>
#include <map>
#include "printVector.h"

/* Создать шаблонную функцию, которая принимает итераторы на начало и конец последовательности слов,
 * и выводящую в консоль список уникальных слов (если слово повторяется больше 1 раза, то вывести его
 * надо один раз). Продемонстрировать работу функции, передав итераторы различных типов.
*/
template<typename T>
void printUniq(T iterBegin,
               T iterEnd) {
    std::set<std::string> autoUnique;
    for (auto i=iterBegin; i != iterEnd; ++i) {
        autoUnique.insert(*i);
    }
    std::copy(autoUnique.begin(),autoUnique.end(),
              std::ostream_iterator<std::string>(std::cout," "));
    std::cout << std::endl;
}

/* Используя ассоциативный контейнер, напишите программу, которая будет считывать данные введенные
 * пользователем из стандартного потока ввода и разбивать их на предложения.
 *  Далее программа должна вывести пользователю все предложения, отсортировав их по длине.
 * */
void sentenceSplitter() {
    std::cout << "Please enter English text. " << std::endl <<
    "Each sentence must end with either '.' or '!' or '?' " << std::endl <<
    "Unfinished sentences are ignored." << std::endl <<
    "Type ' QUIT' uppercase, with leading space to stop input): "  << std::endl  << std::endl;
    std::string chars;
    typedef std::pair<size_t, size_t> numSizePair;
    std::map<numSizePair, std::string> phrases;
    size_t stringNumber=0;
    std::string phrase;
    while(std::cin >> chars) {
        phrase = phrase + " " + chars;
        if (chars.ends_with('.')
            ||
            chars.ends_with('!')
            ||
            chars.ends_with('?')
            ) {
                ++stringNumber;
                phrases.emplace(std::make_pair(stringNumber, phrase.size()), phrase);
                phrase="";
        }
        if (chars == "QUIT") break;
    }

    std::vector<numSizePair> toPrint;
    for (auto [numberSizePair,sentence]:phrases) { // хотелось бы вместо sentence std::ignore, но не даёт.
      toPrint.emplace_back(numberSizePair);
    }
    std::sort(toPrint.begin(),toPrint.end(),[](numSizePair left, numSizePair right){
        return left.second < right.second;
    });
    std::cout << "Sentences sorted by size:" << std::endl;
    for(auto numberSizePair:toPrint){
        std::cout << phrases[numberSizePair] << std::endl;
    }
}


int main() {
    sentenceSplitter();

    std::vector<std::string> seqVector{"first", "first", "second", "third", "forth", "fifth", "sixth"};
    std::cout << "====> Original data (same for Vector and List): " << std::endl;
    printVector(seqVector);
    std::list<std::string> seqList{"first", "first", "second", "third", "forth", "fifth", "sixth"};
    std::cout << "====> Sorted and unique using std::vector iterators:" << std::endl;
    printUniq(seqVector.begin(), seqVector.end());
    std::cout << "====> Sorted and unique using std::list iterators:" << std::endl;
    printUniq(seqList.begin(), seqList.end());

    return 0;
}
