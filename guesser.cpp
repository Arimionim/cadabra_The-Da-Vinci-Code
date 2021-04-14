#include "guesser.h"

void guesser::guess() {
    std::cout << "Hi! I'm ready for the Challenge?\n";

    int num = 6765; // just random number

    int l = 1, r = 10000;

    while (l < r) {
        int m = (r + l) / 2;

        int result = try_number(m);
        if (result == 0) {
            std::cout << "Great! ";
            num = m;
            break;
        } else if (result == -1) {
            r = m;
        } else {
            l = m + 1;
        }
    }

    std::cout << "Your promocode is: ";
    std::cout << build_code(num);
    std::cout << ". Enjoy your pizza!" << std::endl;
}

int guesser::num_in_seq(const std::string &x) {
    std::string a = "0";
    std::string b = "1";
    int idx = 0;

    while (cmp_big_nums(a, x) == -1) {
        a = sum(a, b);
        std::swap(a, b);
        ++idx;
    }

    return x == a ? idx : int('_');
}

int guesser::cmp_big_nums(const std::string& a, const std::string& b) {
    if (a.size() != b.size()) {
        return a.size() < b.size() ? -1 : 1;
    }

    return a < b ? -1 : 1;
}

int guesser::try_number(int x) {
    std::cout << "Your number is " << x << "?\n";
    std::string res;

    while (true) {
        std::cin >> res;

        if (res == "less") {
            return -1;
        } else if (res == "more") {
            return 1;
        } else if (res == "yep") {
            return 0;
        } else {
            std::cout << R"(Sorry, I not understand you. Please, type "less", "more" or "yep")" << std::endl;
        }
    }
}

std::string guesser::build_code(int x) {
    std::string res(11, ' ');
    std::string x_big = to_big_num(x);
    char first = (char) num_in_seq(sum(x_big, quintus));
    char second = (char) (first + 1);
    char third = (char) num_in_seq(sum(x_big, serenus));
    char fifth = (char) num_in_seq(sum(x_big, sammonicus));
    char forth = (char) (fifth - 1);

    return {
        first,
        second,
        third,
        first,
        forth,
        first,
        fifth,
        first,
        second,
        third,
        first};
}

std::string guesser::sum(const std::string &a, const std::string &b) {
    size_t idx_a = 0;
    size_t idx_b = 0;

    std::string res;
    int add = 0;
    while (idx_a < a.size() || idx_b < b.size()) {
        int num = digit_at(a, idx_a++) + digit_at(b, idx_b++) + add;
        add = num / 10;
        res += int_to_ch(num % 10);
    }

    if (add) {
        res += '1';
    }

    reverse(res.begin(), res.end());
    return res;
}

std::string guesser::to_big_num(int x) {
    if (x == 0) {
        return "0";
    }

    std::string res;
    while (x > 0) {
        res += int_to_ch(x % 10);
        x /= 10;
    }
    reverse(res.begin(), res.end());
    return res;
}

int guesser::digit_at(const std::string &num, size_t idx) {
    if (idx >= num.size()) {
        return 0;
    }

    return num[num.size() - idx - 1] - '0';
}

char guesser::int_to_ch(int i) {
    return char('0' + i);
}

void guesser::test(int x) {

    std::cout << "test: " << x << ' ' << build_code(x) << "\n";
}

