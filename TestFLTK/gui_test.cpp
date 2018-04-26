//
// Book : chapitre 16 de l'ouvrage
// "Programming -- Principles and Practice Using C++" de Bjarne Stroustrup (2ème édition : 2014)
// Commit initial : 22/04/2018 - Drill page 577 - Reprise d'une partie des fichiers de BS présents dans C:\Users\andre\source\ppp2\GUI (problèmes de compilation)
// Commit en cours : 26/04/2018 - exos pages 578 à 579
// Caractères spéciaux : [ ]   '\n'   {  }   ||   ~   _     @

#include <iostream>
#include <sstream>
#include "Graph.h"        // get access to our graphics library facilities
#include "GUI.h"
#include "Window.h"

using namespace Graph_lib;
using namespace std;

// DRILL page 577 **********************************************************************************************************************************

struct Lines_window : Window {
	Lines_window(Point xy, int w, int h, const string& title);
	Open_polyline lines;
	
private:
	Button next_button;        // add (next_x,next_y) to lines
	Button quit_button;
	In_box next_x;
	In_box next_y;
	Out_box xy_out;
	Menu color_menu;
	Menu style_menu;
	Button menu_button;			// Pour masquer ou pas le menu "color"

	void change(Color c) { lines.set_color(c); }
	void style(Line_style l) { lines.set_style(l); }
	void hide_menu() { color_menu.hide(); menu_button.show(); }

	// actions invoked by callbacks
	void red_pressed() { change(Color::red); }
	void blue_pressed() { change(Color::blue); }
	void black_pressed() { change(Color::black); }
	void solid_pressed() { style(Line_style::solid); }
	void dash_pressed() { style(Line_style::dash); }
	void dot_pressed() { style(Line_style::dot); }
	void menu_pressed() { menu_button.hide(); color_menu.show(); }
	void next();
	void quit();

	// callbacks functions
	static void cb_red(Address, Address);		
	static void cb_blue(Address, Address);		
	static void cb_black(Address, Address);	
	static void cb_solid(Address, Address);
	static void cb_dash(Address, Address);
	static void cb_dot(Address, Address);
	static void cb_menu(Address, Address);	
	static void cb_next(Address, Address);	
	static void cb_quit(Address, Address);	
	
};

//------------------------------------------------------------------------------

Lines_window::Lines_window(Point xy, int w, int h, const string& title)		// Constructeur
	:Window(xy, w, h, title),
	next_button(Point(x_max() - 150, 0), 70, 20, "Next point", cb_next),
	quit_button(Point(x_max() - 70, 0), 70, 20, "Quit", cb_quit),
	next_x(Point(x_max() - 310, 0), 50, 20, "next x:"),
	next_y(Point(x_max() - 210, 0), 50, 20, "next y:"),
	xy_out(Point(100, 0), 100, 20, "current (x,y):"),
	color_menu {Point{x_max()-70,30},70,20,Menu::vertical,"color"},
	style_menu{ Point{ x_max() - 70,100 },70,20,Menu::vertical,"style" },
	menu_button{ Point{ x_max() - 80,30 },80,20,"color menu",cb_menu }

{
	attach(next_button);
	attach(quit_button);
	attach(next_x);
	attach(next_y);
	attach(xy_out);
	xy_out.put("no point");
	
	color_menu.attach(new Button{ Point{ 0,0 },0,0,"red",cb_red });
	color_menu.attach(new Button{ Point{ 0,0 },0,0,"blue",cb_blue });
	color_menu.attach(new Button{ Point{ 0,0 },0,0,"black",cb_black });
	attach(color_menu);
	color_menu.hide();
	attach(menu_button);
	
	style_menu.attach(new Button{ Point{ 0,0 },0,0,"solid",cb_solid });
	style_menu.attach(new Button{ Point{ 0,0 },0,0,"dash",cb_dash });
	style_menu.attach(new Button{ Point{ 0,0 },0,0,"dot",cb_dot });
	attach(style_menu);

	attach(lines);

	
}

//------------------------------------------------------------------------------

void Lines_window::cb_quit(Address, Address pw)    // "the usual"
{
	reference_to<Lines_window>(pw).quit();
}

//------------------------------------------------------------------------------

void Lines_window::quit()
{
	hide();        // curious FLTK idiom for delete window
}

//------------------------------------------------------------------------------

void Lines_window::cb_next(Address, Address pw)     // "the usual"
{
	reference_to<Lines_window>(pw).next();
}

//------------------------------------------------------------------------------

void Lines_window::next()
{
	int x = next_x.get_int();
	int y = next_y.get_int();

	lines.add(Point(x, y));

	// update current position readout:
	stringstream ss;
	ss << '(' << x << ',' << y << ')';
	xy_out.put(ss.str());

	redraw();
}

//------------------------------------------------------------------------------

void Lines_window::cb_red(Address, Address pw)      // "the usual"
{
	reference_to<Lines_window>(pw).red_pressed();
}

//------------------------------------------------------------------------------

void Lines_window::cb_blue(Address, Address pw)     // "the usual"
{
	reference_to<Lines_window>(pw).blue_pressed();
}

//------------------------------------------------------------------------------

void Lines_window::cb_black(Address, Address pw)    // "the usual"
{
	reference_to<Lines_window>(pw).black_pressed();
}

//------------------------------------------------------------------------------

void Lines_window::cb_solid(Address, Address pw)      // "the usual"
{
	reference_to<Lines_window>(pw).solid_pressed();
}

//------------------------------------------------------------------------------

void Lines_window::cb_dash(Address, Address pw)     // "the usual"
{
	reference_to<Lines_window>(pw).dash_pressed();
}

//------------------------------------------------------------------------------

void Lines_window::cb_dot(Address, Address pw)    // "the usual"
{
	reference_to<Lines_window>(pw).dot_pressed();
}

//------------------------------------------------------------------------------

void Lines_window::cb_menu(Address, Address pw)     // "the usual"
{
	reference_to<Lines_window>(pw).menu_pressed();
}

// Exercices 1, 2, 3 page 578 **************************************************************************************
struct Simple_window : Window {
	Simple_window(Point xy, int w, int h, const string& title)
		: Window(xy, w, h, title),
		pressions_out(Point(100, 0), 30, 20, "Pressions :"),
		checker_out(Point(300, 0), 30, 20, "Case pressée :"),
		quit_button(Point(x_max() - 70, 0), 70, 20, "Quit", [](Address, Address pw) {reference_to<Simple_window>(pw).quit(); })	// Lambda as a callback : page 560 rather than "the usual callback"

	{
		// Création du damier
		int x_pos = 0;
		int y_pos = 50;
		
		for (int i = 0; i<16; ++i)
		{
			if (i != 0) {	// Gestion de la position
				if (i % 4 == 0) { x_pos = 0; y_pos += 80; } else ++x_pos;
			}
			
			add_checkers(new Button{ Point{ 100 + x_pos * 80,y_pos },80,80,to_string(i),cb_checker_pressed });	// Création des cases du damier
						
		}

		// Attachement de chaque case du damier à la fenêtre
		for (auto p : checkers)
			attach(*p);		 

		// Attachement des boutons de commande à la fenêtre
		attach(pressions_out);
		pressions_out.put("0");
		attach(checker_out);
		checker_out.put("ras");
		attach(quit_button);
	}

	void add_checkers(Graph_lib::Button* s) { checkers.push_back(s); }	// On crée une case du damier en la stockant dans un vecteur qui stocke un objet graphique "bouton"
	int nombre_pressions() const noexcept { return nb_pressions; }		// On retourne le nombre de pressions effectuées sur les cases du damier

	~Simple_window()	// Destructeur
	{

		for (auto p : checkers)
			delete p;

	}
	
private:
	Button quit_button;
	Out_box pressions_out;
	Out_box checker_out;
	vector<Graph_lib::Button*>checkers{};	// Stockage des boutons du damier dans un vecteur
	int nb_pressions = 0;					// Stockage du nombre de pressions effectuées sur les cases du damier

	// actions invoked by callbacks
	void quit();
	void checker_pressed(Address xw);		

	// callbacks functions
	static void cb_checker_pressed(Address, Address);
	
};


void Simple_window::checker_pressed(Address xw)		// On a besoin, contrairement à d'habitude, de récupérer l'adresse du widget qui correspond à l'une des cases du damier
{
	++nb_pressions;
	
	// update current nb checker_pressed readout:
	stringstream ss1;
	ss1 << nombre_pressions() ;
	pressions_out.put(ss1.str());

	// Affichage du numéro de la case du damier pressé -> Le code est trop low level toutefois (inspiration : int In_box::get_int() dans GUI.cpp)
	const Fl_Button& damier = reference_to<Fl_Button>(xw);	// On référence le widget pressé
	const char* p = damier.label();							// On récupère son label (fonction définie dans Fl_Widget.H)
	stringstream ss2;
	ss2 << p;
	checker_out.put(ss2.str());
	   
	// Exo 3 page 579 - NOTE : la référence à damier (ex : damier.label("")) ne fonctionne pas -> je repasse donc par "reference_to<Fl_Button>(xw).", trop low level AGAIN
	reference_to<Fl_Button>(xw).label("");									// On efface le chiffre inscrit dans le bouton
	reference_to<Fl_Button>(xw).color(Color::dark_cyan);					// On change la couleur de fond
	reference_to<Fl_Button>(xw).image(new Fl_JPEG_Image("duck_eye.jpg"));	// On charge une image

	redraw();
}

void Simple_window::cb_checker_pressed(Address xw, Address pw)     // Contrairement à d'habitude (page 557), on "nomme" la première adresse "xw" qui correspond au widget stocké (pw étant l'adresse de la fenêtre)
{
	reference_to<Simple_window>(pw).checker_pressed(xw);
}

//------------------------------------------------------------------------------

void Simple_window::quit()
{
	hide();        // curious FLTK idiom for delete window : cette fonction peut être supprimée et on peut mettre le hide() directement dans le "lambda as a callback" ci-dessus (mais moins flexible si on veut changer de librairie)
}



// ********************************************************************************************************************************************************
int main()
try {
	// Lines_window win(Point(100, 100), 600, 400, "lines");			// Drill page 577

	Simple_window My_window(Point(100, 100), 600, 400, "checkerboard");	// Exo 2 page 578
	
	return gui_main();	// Control inversion page 569
}

catch (exception& e) {
	cerr << "exception: " << e.what() << '\n';
	return 1;
}

catch (...) {
	cerr << "Some exception\n";
	return 2;
}

//------------------------------------------------------------------------------
