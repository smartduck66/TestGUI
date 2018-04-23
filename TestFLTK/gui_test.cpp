//
// Book : chapitre 16 de l'ouvrage
// "Programming -- Principles and Practice Using C++" de Bjarne Stroustrup (2ème édition : 2014)
// Commit initial : 22/04/2018 - Drill page 577 - Reprise d'une partie des fichiers de BS présents dans C:\Users\andre\source\ppp2\GUI (problèmes de compilation)
// Commit en cours : 24/04/2018 - exos pages 578 à 579
// Caractères spéciaux : [ ]   '\n'   {  }   ||   ~   _     @

#include <iostream>
#include <sstream>
#include "Graph.h"        // get access to our graphics library facilities
#include "GUI.h"
#include "Window.h"

using namespace Graph_lib;
using namespace std;

//------------------------------------------------------------------------------

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

//------------------------------------------------------------------------------




int main()
try {
	Lines_window win(Point(100, 100), 600, 400, "lines");
	return gui_main();
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
