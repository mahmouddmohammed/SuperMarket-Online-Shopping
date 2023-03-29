#include <iostream>
double discounted_price(int products_count , double total_price)
{

    if(products_count == 2)
        total_price = total_price - (total_price * 0.05);
    else if(products_count == 3)
        total_price = total_price - (total_price * 0.1);
    else if(products_count == 4)
        total_price = total_price - (total_price * 0.15);
    else if(products_count >= 5)
        total_price = total_price - (total_price * 0.2);
    return total_price ;


}
using namespace std;
int main()
{
    // need the total price and no. of products

    double final_price = discounted_price(count_ , total );
    if(count_ == 1 ){
        cout << "There is no discount\n";
        cout << "Total price is : " << final_price ;
    }
    else if(count_ == 2){
        cout << "There is 5% discount\n";
        cout << "Total price is : " << final_price ;
    }
    else if(count_ == 3){
        cout << "There is 10% discount\n";
        cout << "Total price is : " << final_price ;
    }
    else if(count_ == 4 ){
        cout << "There is 15% discount\n";
        cout << "Total price is : " << final_price ;
    }
    else{
        cout << "There is 20% discount\n";
        cout << "Total price is : " << final_price ;
    }
}
