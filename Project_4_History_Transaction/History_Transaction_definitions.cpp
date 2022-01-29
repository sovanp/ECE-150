#include <cassert>
#include <iomanip>
#include <iostream>
#include <utility>

#include "project4.hpp"
#include "History.hpp"
#include "Transaction.hpp"

////////////////////////////////////////////////////////////////////////////////
// Definitions for Transaction class
////////////////////////////////////////////////////////////////////////////////
//
//

// Constructor
// TASK
//
Transaction::Transaction( std::string ticker_symbol,  unsigned int day_date,
unsigned int month_date,  unsigned year_date,
bool buy_sell_trans,  unsigned int number_shares,
double trans_amount ) {
    symbol = std::move(ticker_symbol);
    day = day_date;
    month = month_date;
    year = year_date;
    shares = number_shares;
    amount = trans_amount;
    //Set buy_sell_trans depending on if transaction is buy or sell -- buy = true
    if (buy_sell_trans) {
        trans_type = "Buy";
    }
    else {
        trans_type = "Sell";
    }
    //Set trans_id --> already initialized in main();
    trans_id = assigned_trans_id;
    assigned_trans_id++;
    //Private members
    acb = 0.0;
    acb_per_share = 0.0;
    share_balance = 0;
    cgl = 0.0;
    p_next = nullptr;
}


// Destructor
// TASK
//
Transaction::~Transaction() = default;

// TASK
// Overloaded < operator.
//
bool Transaction::operator<( Transaction const &other ) {
    if (year < other.year) {
        return true;
    }
    else if ((year == other.year) && (month < other.month)) {
        return true;
    }
    else if ((year == other.year) && (month == other.month) && (day < other.day)) {
        return true;
    }
    else {
        //Dates are equal
        return false;
    }
}

// GIVEN
// Member functions to get values.
//
std::string Transaction::get_symbol() const { return symbol; }
unsigned int Transaction::get_day() const { return day; }
unsigned int Transaction::get_month() const { return month; }
unsigned int Transaction::get_year() const { return year; }
unsigned int Transaction::get_shares() const { return shares; }
double Transaction::get_amount() const { return amount; }
double Transaction::get_acb() const { return acb; }
double Transaction::get_acb_per_share() const { return acb_per_share; }
unsigned int Transaction::get_share_balance() const { return share_balance; }
double Transaction::get_cgl() const { return cgl; }
bool Transaction::get_trans_type() const { return (trans_type == "Buy") ? true: false ; }
unsigned int Transaction::get_trans_id() const { return trans_id; }
Transaction *Transaction::get_next() { return p_next; }

// GIVEN
// Member functions to set values.
//
void Transaction::set_acb( double acb_value ) { acb = acb_value; }
void Transaction::set_acb_per_share( double acb_share_value ) { acb_per_share = acb_share_value; }
void Transaction::set_share_balance( unsigned int bal ) { share_balance = bal ; }
void Transaction::set_cgl( double value ) { cgl = value; }
void Transaction::set_next( Transaction *p_new_next ) { p_next = p_new_next; }

// GIVEN
// Print the transaction.
//
void Transaction::print() {
  std::cout << std::fixed << std::setprecision(2);
  std::cout << std::setw(4) << get_trans_id() << " "
    << std::setw(4) << get_symbol() << " "
    << std::setw(4) << get_day() << " "
    << std::setw(4) << get_month() << " "
    << std::setw(4) << get_year() << " ";


  if ( get_trans_type() ) {
    std::cout << "  Buy  ";
  } else { std::cout << "  Sell "; }

  std::cout << std::setw(4) << get_shares() << " "
    << std::setw(10) << get_amount() << " "
    << std::setw(10) << get_acb() << " " << std::setw(4) << get_share_balance() << " "
    << std::setw(10) << std::setprecision(3) << get_acb_per_share() << " "
    << std::setw(10) << std::setprecision(3) << get_cgl()
    << std::endl;
}


////////////////////////////////////////////////////////////////////////////////
// Definitions for the History class
////////////////////////////////////////////////////////////////////////////////
//
//


// Constructor
// TASK
//
History::History() {
    p_head = nullptr;
}

// Destructor
// TASK
//
History::~History() {
    Transaction *p_temp = p_head;
    Transaction *p_next_node = nullptr;
    //Check if list is empty
    if (p_temp != nullptr) {
        while (p_temp != nullptr) {
            p_next_node = p_temp->get_next();
            delete p_temp;
            p_temp = p_next_node;
        }
        delete p_temp;
        p_temp = nullptr;
        delete p_next_node;
        p_head = nullptr;
    }
}

// TASK
// read_history(...): Read the transaction history from file.
//
void History::read_history() {
    //Open file
    ece150::open_file();
    //Do until the last entry
    while (ece150::next_trans_entry()) {
        Transaction *p_new_trans = new Transaction(ece150::get_trans_symbol(), ece150::get_trans_day(),
                                                   ece150::get_trans_month(), ece150::get_trans_year(),
                                                   ece150::get_trans_type(), ece150::get_trans_shares(),
                                                   ece150::get_trans_amount());
        //Insert into list
        History::insert(p_new_trans);
    }
    //Close file
    ece150::close_file();
}

// insert(...): Insert transaction into linked list.
//
void History::insert(Transaction *p_new_trans) {
    //If list is empty, make p_new_trans the head
    if (p_head == nullptr) {
        //Empty case
        p_head = p_new_trans;
    }
    else {
        //Create traversal pointer to walk through list and point p_traverse to p_head
        Transaction *p_traverse = p_head;
        //Traverse nodes until the last transaction
        while (p_traverse->get_next() != nullptr) {
            //Get next node
            p_traverse = p_traverse->get_next();
        }
        //Set the last transaction as the tail, which actually inserts node at end of list
        p_traverse->set_next(p_new_trans);
    }
}


// TASK
// sort_by_date(): Sort the linked list by trade date.
//
void History::sort_by_date() {
    //Check if list is empty or has one node
    if ((p_head == nullptr) || (p_head->get_next() == nullptr)) {
        return;
    }
    else {
        //Create handling pointer
        Transaction *p_sorted = nullptr;
        //Repeat until no nodes left
        while (p_head != nullptr) {
            //Step: Remove node from original list
            Transaction *p_temp1 = p_head;
            //Move p_head to second node
            p_head = p_head->get_next();
            //Detach first node from the p_head list
            p_temp1->set_next(nullptr); //Set next is what us to set what the node is pointing to
            //Case 1: Add p_temp1 node to front of p_sorted list
            if (p_sorted == nullptr) {
                //Move p_sorted to new start of list
                p_sorted = p_temp1;
            }
            else if (*p_temp1 < *p_sorted) {
                //Point p_next of new node to front node of p_sorted
                p_temp1->set_next(p_sorted);
                //Move p_sorted to new start of list
                p_sorted = p_temp1;
            }
                //Case 2: Inset p_temp1 node somewhere other than front
            else {
                //Create pointer to track previous transaction
                Transaction *p_previous = nullptr;
                //Create another pointer to iterate over sorted list and start it at the front of sorted list
                Transaction *p_temp2 = p_sorted;
                while (p_temp2 != nullptr) {
                    //Insert in middle of list
                    if (!(*p_temp2 < *p_temp1)) {
                        p_previous->set_next(p_temp1);
                        p_temp1->set_next(p_temp2);
                        break;
                    }
                    p_previous = p_temp2;
                    p_temp2 = p_temp2->get_next();
                }
                //Insert at end of list
                if (p_temp2 == nullptr) {
                    p_previous->set_next(p_temp1);
                }
            }
        }
        //Move p_head to p_sorted
        p_head = p_sorted;
    }
}


// TASK
// update_acb_cgl(): Updates the ACB and CGL values.
//
void History::update_acb_cgl() {
    //Sort the list
    sort_by_date();
    //Check if list is not empty
    if (p_head != nullptr) {
        //Create handling pointers to traverse list
        Transaction *p_current = p_head;
        Transaction *p_ahead = p_head;
        //Set initial values for transactions
        p_current->set_acb(p_current->get_amount()); //Set acb
        p_current->set_share_balance(p_current->get_shares()); //Set share balance
        p_current->set_acb_per_share(p_current->get_acb() / p_current->get_share_balance()); //Set acb/share
        //Traverse list
        while (p_ahead->get_next() != nullptr) {
            //Copy p_current to p_ahead
            p_current = p_ahead;
            //Advance p_ahead to node next node
            p_ahead = p_ahead->get_next();
            //If transaction is a buy
            if (p_ahead->get_trans_type()) {
                p_ahead->set_acb(p_current->get_acb() + p_ahead->get_amount()); //Compute acb
                p_ahead->set_share_balance(p_current->get_share_balance() + p_ahead->get_shares()); //Compute share balance
                p_ahead->set_acb_per_share(p_ahead->get_acb() / p_ahead->get_share_balance()); //Compute acb/share
            }
            //Transaction is a sell
            else {
                p_ahead->set_acb(p_current->get_acb() - (p_current->get_acb_per_share()*p_ahead->get_shares())); //Compute acb
                p_ahead->set_share_balance(p_current->get_share_balance() - p_ahead->get_shares()); //Compute share balance
                p_ahead->set_acb_per_share(p_current->get_acb_per_share()); //Compute acb/share
                p_ahead->set_cgl(p_ahead->get_amount() - (p_ahead->get_shares()*p_ahead->get_acb_per_share()));
            }
        }
    }
}


// TASK
// compute_cgl(): )Compute the ACB, and CGL.1
//
double History::compute_cgl(unsigned int year) {
    //Check if list is empty
    if (p_head != nullptr) {
        //Variable to store total cgl
        double total_cgl = 0.0;
        //Create pointer to traverse list and start at head
        Transaction *p_temp = p_head;
        while (p_temp->get_next() != nullptr) {
            if ((p_temp->get_year() == year) && (!p_temp->get_trans_type())) {
                //Keep track of total cgl
                total_cgl += p_temp->get_cgl();
            }
            //Advance the node
            p_temp = p_temp->get_next();
        }
        return total_cgl;
    }
}


// TASK
// print() Print the transaction history.
//
void History::print() {
    std::cout << "========== BEGIN TRANSACTION HISTORY ============" << std::endl;
    //Traverse the list
    while (p_head != nullptr) {
        //Print the transaction
        p_head->print();
        //Advance the node
        p_head = p_head->get_next();
    }
    std::cout << "========== END TRANSACTION HISTORY ============" << std::endl;
}


// GIVEN
// get_p_head(): Full access to the linked list.
//
Transaction *History::get_p_head() { return p_head; }
