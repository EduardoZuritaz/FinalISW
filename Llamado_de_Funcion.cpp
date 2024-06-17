#include "Cuerpo.cpp"

int main(){
    cout << "Hola, Yo soy tu asistente de Eventos, si tienes alguna duda sobre mis comandos escribe: n!commands" << endl << endl;
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
            string date;
            cout << "Ingrese la fecha (aaaa-mm-dd): ";
            cin >> date;
            cin.ignore();
            if(DB.count(date)){
            const auto& events = DB.at(date);
            for(const auto& event : events){
                cout << event << endl;
                }
                } else {
                    cout << "No hay eventos para esta fecha" << endl;
                    }
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