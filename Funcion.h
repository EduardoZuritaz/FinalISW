#pragma once
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <sstream>

using namespace std;

map<string, vector<string>> DB;

void show_commands();
bool valid_data(const string& date);
void add(const string& date , const string& event);
void print();
void delete_event(const string& date, const string& event);
void remove_all(const string& date);
void find(const string& date);
void ask_for_action(string& command); // extra