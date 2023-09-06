#include <cassert>
#include <chrono>

using namespace std::chrono;

bool IsBisiestoY(year);

int main() {
    assert (IsBisiestoY(1600y));
    assert (IsBisiestoY(1976y));
    assert (IsBisiestoY(1988y));
    assert (IsBisiestoY(2000y));
    assert (IsBisiestoY(2004y));
    assert (IsBisiestoY(2020y));
    assert (not IsBisiestoY(2023y));
    assert (not IsBisiestoY(1700y));
    assert (not IsBisiestoY(1200y));
    assert (not IsBisiestoY(1900y));
}

bool IsBisiestoY(year y){
    int a{y};
    
    if (a <= 1582) return false;
    if (a % 4 != 0) return false;
    if (a % 100 != 0) return true;
    if (a % 400 == 0) return true;
    
    return false;
};

/*
#include <cassert>

int operator ""y(unsigned long long);

bool IsBisiestoY(unsigned year);

int main() {
    // Años bisiestos
    assert(IsBisiestoY(2000y));
    assert(IsBisiestoY(2020y));
    assert(IsBisiestoY(2024y));

    // Años no bisiestos
    assert(not IsBisiestoY(1900y));
    assert(not IsBisiestoY(2001y));
    assert(not IsBisiestoY(2100y));
    assert(not IsBisiestoY(1582y));

}

int operator ""y(unsigned long long year) {
    return unsigned(year);
}

bool IsBisiestoY(unsigned year) {
    return (year>1582 and year%4==0 and (year%100!=0 or year%400==0));
}
*/