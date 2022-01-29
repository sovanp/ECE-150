#include <iostream>
#include "History.hpp"
#include "Transaction.hpp"
#include "project4.hpp"
#include "History_Transaction_definitions.cpp"
#include "project4.cpp"



#ifndef MARMOSET_TESTING
unsigned int Transaction::assigned_trans_id = 0;
int main() {

    Transaction *Transaction1 = new Transaction("Test1", 11, 07, 2020, true, 0, 0);
    Transaction *Transaction2 = new Transaction("Test2", 5, 01, 2020, true, 0, 0);
    Transaction *Transaction3 = new Transaction("Test3", 15, 10, 2020, true, 0, 0);
    Transaction *Transaction4 = new Transaction("Test4", 15, 01, 2020, true, 0, 0);

    History main_history;
    main_history.insert(Transaction1);
    main_history.insert(Transaction2);
    main_history.insert(Transaction3);
    main_history.insert(Transaction4);



    main_history.sort_by_date();
    main_history.print();

//    History trans_history{};
//    trans_history.read_history();

//    std::cout << "[Starting history]:" << std::endl;
//    trans_history.print();
//    trans_history.sort_by_date();
//
//    std::cout << "[Sorted          ]:" << std::endl;
//    trans_history.print();
//
//    trans_history.update_acb_cgl();
//    trans_history.print();
//
//    std::cout << "[CGL for 2018    ]: " << trans_history.compute_cgl(2018) << std::endl;
//    std::cout << "[CGL for 2019    ]: " << trans_history.compute_cgl(2019) << std::endl;

  return 0;
}
#endif
