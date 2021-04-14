//
// Created by software on 14.04.2021.
//

#ifndef UNTITLED_GUESSER_H
#define UNTITLED_GUESSER_H


#include <string>
#include <iostream>

class guesser {
public:
    static void guess();
    static void test(int);
private:
    static inline const std::string quintus = "83621143489848416212";
    static inline const std::string serenus = "298611126818977066911787";
    static inline const std::string sammonicus = "354224848179261908310";

    static int try_number(int);
    static int num_in_seq(const std::string&);
    static std::string build_code(int);
    static std::string sum(const std::string &, const std::string &);
    static int digit_at(const std::string &, size_t);
    static char int_to_ch(int i);
    static int cmp_big_nums(const std::string &, const std::string &);
    static std::string to_big_num(int x);
};


#endif //UNTITLED_GUESSER_H
