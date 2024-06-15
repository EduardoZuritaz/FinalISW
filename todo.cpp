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
void ask_for_action(string& command); // extra

int main(){
    cout << "Hola, Yo soy tu asistente de Eventos, si tienes alguna duda sobre mis comandos escribe: n!commands" << endl << endl;
    while(true){
        string command;
        cin >> command;

        if(command == "n!commands"){
            show_commands();
            ask_for_action(command);
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
            // Falta
        } else if(command == "n!remove"){
            // Falta
        } else if(command == "n!find"){
            // Falta
        } else if(command == "n!show"){
            // Falta
        } else if(command == "n!off"){
            break;
        } else {
            cout << "Comando no valido" << endl;
        }
    }
    return 0;
}

//pedido en el documento

void show_commands(){
    cout << " " << endl;
    cout << "COMANDOS" << endl;
    cout << "n!add = Agregar evento" << endl;
    cout << "n!erase = Eliminar evento especifico" << endl;
    cout << "n!remove = Eliminar todos los eventos de una fecha" << endl;
    cout << "n!find = Encontrar eventos" << endl;
    cout << "n!show = Mostrar todos los eventos" << endl;
    cout << "n!off = Salir" << endl << endl;
}

bool valid_data(const string& date){
    int y, m, d;
    char dash1, dash2;
    stringstream ss(date);

    if(!(ss >> y >> dash1 >> m >> dash2 >> d) || dash1 != '-' || dash2 != '-'){
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

// extras mios

void ask_for_action(string& command){
    string answ;
    cout << "Deseas hacer algo mas? (s/n)" << endl;
    cin >> answ;

    if (answ == "s" || answ == "S" || answ == "si" || answ == "Si") {
        show_commands();
    } else if (answ == "n" || answ == "N" || answ == "no" || answ == "No") {
        command = "n!off";
    }
}