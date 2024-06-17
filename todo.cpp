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
void ask_for_action(string& command); // extra

int main(){
    cout << "Hola, Yo soy LUO tu asistente de Eventos, si tienes alguna duda sobre mis comandos escribe: n!commands" << endl << endl;
    while(true){
        string command;
        cin >> command;

        if(command == "n!commands"){
            show_commands();
        } else if(command == "n!add"){
            string date, event;
            cout << "Ingrese la fecha (aaaa-mm-dd): ";
            cin >> date;
            if(valid_data(date)){
                cout << "Ingrese el evento: ";
                cin.ignore();
                getline(cin, event);
                add(date, event);
                cout << "Evento agregado con exito!" << endl;
                ask_for_action(command);
            }
        } else if(command == "n!erase"){
            string date, event;
            cout << "Ingrese la fecha (aaaa-mm-dd): ";
            cin >> date;
            cout << "Ingrese el evento: ";
            cin.ignore();
            getline(cin, event);
            delete_event(date, event);
            ask_for_action(command);
        } else if(command == "n!remove"){
            string date;
            cout << "Ingrese la fecha (aaaa-mm-dd): ";
            cin >> date;
            cin.ignore();
            DB.erase(date);
            cout << "Todos los eventos de la fecha " << date << " han sido eliminados." << endl;
            ask_for_action(command);
        } else if(command == "n!find"){
            // Falta
            ask_for_action(command);
        } else if(command == "n!show"){
            print();
            ask_for_action(command);
        } else if(command == "n!exit"){
            ask_for_action(command);
        } else {
            cout << "Comando no valido\nVuelve a intentarlo: ";
        }
    }
    return 0;
}

//pedido en el documento

void show_commands(){
    cout << " " << endl;
    cout << "COMANDOS" << endl;
    cout << " " << endl;
    cout << "n!add = Agregar evento" << endl;
    cout << "n!erase = Eliminar evento especifico" << endl;
    cout << "n!remove = Eliminar todos los eventos de una fecha" << endl;
    cout << "n!find = Encontrar eventos" << endl;
    cout << "n!show = Mostrar todos los eventos" << endl;
    cout << "n!exit = Salir" << endl << endl;
}

bool valid_data(const string& date){
    int y, m, d;
    char hyp1, hyp2;
    stringstream ss(date);

    if(!(ss >> y >> hyp1 >> m >> hyp2 >> d) || hyp1 != '-' || hyp2 != '-'){
        cout << "Formato de Fecha incorrecto: " << date << endl;
        return false;
    }
    
    if(m < 1 || m > 12){
        cout << "El mes no es valido: " << m << endl;
        return false;
    }

    if(d < 1 || d > 31){
        cout << "El dia no es valido: " << d << endl;
        return false;
    }

    return true;
}

void add(const string& date, const string& event){
    auto& events = DB[date];
    bool event_exist = false;
    for(const auto& i : events){
        if(i == event){
            event_exist = true;
            break;
        }
    }
    if(!event_exist){
        events.push_back(event);
    }
}

void print(){
    for(const auto&[date, events] : DB){
        stringstream ss(date);
        int y;
        int hyp;
        ss >> y >> hyp;
        if(y < 0)
        continue;
        for(const auto& event : events){
            cout << date << " " << event << endl;
        }
    }
}

void delete_event(const string& date, const string& event){
    if(DB.count(date)){
        auto& events = DB[date];
        for(auto i = events.begin(); i != events.end(); ++i){
            if(*i == event){
                events.erase(i);
                cout << "Evento eliminado correctamente!" << endl;
                return;
            }
        }
    }
    cout << "Evento no encontrado" << endl;
}

void remove_all(const string& date){
    if(DB.count(date)){
        int number_events = DB[date].size();
        DB.erase(date);
        cout << "Eliminando " << number_events << " eventos" << endl;
    } else {
        cout << "Eliminado 0 eventos" << endl;
    }
}

// extras mios

void ask_for_action(string& command){
    string answ;
    cout << "No deseas hacer algo mas? (s/n)" << endl;
    cin >> answ;

    if (answ == "s" || answ == "S" || answ == "si" || answ == "Si") {
        show_commands();
    } else if (answ == "n" || answ == "N" || answ == "no" || answ == "No") {
        cout << "Saliendo del programa..." << endl;
        exit(0);
    }
}