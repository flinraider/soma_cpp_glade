#include <iostream>
#include <gtkmm.h>
#include <regex>

using namespace Gtk;

Window * pWindow;
Entry * num_1, * num_2, * result;
Button * btn_soma;
Label * titulo;

bool validar(std::string str){
    std::regex re("^[0-9]+$");
    std::smatch match;
    return std::regex_search(str, match, re);
}

void on_btn_soma_clicked(){
    std::string a = num_1->get_text();
    std::string b = num_2->get_text();

    if(validar(a) && validar(b)){
     int x = std::stoi(a);
     int y = std::stoi(b);

     result-> set_text(std::to_string(x + y));

     num_1->set_text("");
     num_2->set_text("");   
     titulo->set_text("Soma Efetuada!");
    }else{
     titulo->set_text("Digite Apenas Numeros");
    }
}
 
int main( int argc, char *argv[] ) {

    auto app = Application::create(argc, argv, "org.gtkmm.exemple");
    auto refBuilder = Builder::create();
    
    refBuilder->add_from_file("gui.glade");
    refBuilder->get_widget( "window", pWindow);

    if(pWindow){
        refBuilder->get_widget("titulo", titulo);
        refBuilder->get_widget("num_1", num_1);
        refBuilder->get_widget("num_2", num_2);
        refBuilder->get_widget("result", result);
        refBuilder->get_widget("btn_soma", btn_soma); 
    }
    if(btn_soma){
        btn_soma->signal_clicked().connect(sigc::ptr_fun( on_btn_soma_clicked ));
    }

    app->run(*pWindow);

    delete pWindow;
    return 0;
}
//compilar
//g++ soma.cpp -o soma $(pkg-config gtkmm-3.0 --cflags --libs) -export-dynamic