using namespace std;

long long solution(int price, int money, int count)
{
    long long totalPrice = 0;
    
    for(int i = 1; i <= count; i++){
        totalPrice += i * price ;
    }
    
    long long remain = money - totalPrice;
    return remain < 0 ? -remain : 0;
}