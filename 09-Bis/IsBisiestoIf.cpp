// Credito Extra 2

#include<cassert>

bool IsBisiestoIf(int);

int main(){
	
    assert (IsBisiestoIf(1600));
    assert (IsBisiestoIf(1976));
    assert (IsBisiestoIf(1988));
    assert (IsBisiestoIf(2000));
    assert (IsBisiestoIf(2004));
    assert (IsBisiestoIf(2020));
    assert (not IsBisiestoIf(2023));
    assert (not IsBisiestoIf(1700));
    assert (not IsBisiestoIf(1200));
    assert (not IsBisiestoIf(1900));
}

bool IsBisiestoIf(int a){
    if (a <= 1582) return false;
    if (a % 4 != 0) return false;
    if (a % 100 != 0) return true;
    if (a % 400 == 0) return true;
    
    return false;
};