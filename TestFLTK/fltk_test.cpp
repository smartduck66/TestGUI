//
// Book : Version du chapitre 11 de l'ouvrage.
// "Programming -- Principles and Practice Using C++" de Bjarne Stroustrup (2ème édition : 2014)
// Commit initial : 04/03/2018 - Installation FLTK
// Commit en cours : 06/03/2018 - Drill page 437
// Caractères spéciaux : [ ]   '\n'   {  }   ||   ~   _     @

// Librairie indispensable sous Windows et VC++
// #include "stdafx.h"


#include "Graph.h"
#include "Simple_window.h"

int main()
{
	using namespace Graph_lib;

	Point tl{100, 100 };
	Simple_window win(tl, 600, 400, "Ma première fenêtre");
	win.set_label("Canvas n.1");
	win.wait_for_button();

	Axis xa{Axis::x,Point{20,300},280,10,"x axis" };
	win.attach(xa);
	win.set_label("Canvas n.2");
	win.wait_for_button();

	Axis ya{ Axis::y,Point{ 20,300 },280,10,"y axis" };
	ya.set_color(Color::cyan);
	ya.label.set_color(Color::dark_red);
	win.attach(ya);
	win.set_label("Canvas n.3");
	win.wait_for_button();

	Function sine{sin,0,100,Point{ 20,150 },1000,50,50 };
	sine.set_color(Color::blue);
	win.attach(sine);
	win.set_label("Canvas n.4");
	win.wait_for_button();

	Graph_lib::Polygon poly;		// Rajout de Graph_Lib : le namespace ne semble pas fonctionner !!! Ambiguïté avec les nouvelles librairies FLTK ?
	poly.add(Point{ 300,200 });
	poly.add(Point{ 350,100 });
	poly.add(Point{ 400,200 });
	poly.set_color(Color::red);
	poly.set_style(Line_style::dash);
	win.attach(poly);
	win.set_label("Canvas n.5");
	win.wait_for_button();
	

	Graph_lib::Rectangle r{ Point{ 200,200 },100,50 };
	win.attach(r);
	win.set_label("Canvas n.6");
	win.wait_for_button();

	Closed_polyline poly_rect;
	poly_rect.add(Point{ 100,50 });
	poly_rect.add(Point{ 200,50 });
	poly_rect.add(Point{ 200,100 });
	poly_rect.add(Point{ 100,100 });
	poly_rect.add(Point{ 50,75 });
	win.attach(poly_rect);
	win.wait_for_button();

	r.set_fill_color(Color::yellow);
	poly.set_style(Line_style(Line_style::dash, 4));
	poly_rect.set_style(Line_style(Line_style::dash, 2));
	poly_rect.set_fill_color(Color::green);
	win.set_label("Canvas n.7");
	win.wait_for_button();

	Text t{ Point{ 100,150 },"hello, c'est beau !" };
	win.attach(t);
	win.set_label("Canvas n.8");
	win.wait_for_button();

	t.set_font(Font::times_bold);
	t.set_font_size(20);
	win.set_label("Canvas n.9");
	win.wait_for_button();

	Image ii{ Point{ 100,50 },"input_choice.jpg" };
	win.attach(ii);
	win.set_label("Canvas n.10");
	win.wait_for_button();

	ii.move(200,200);
	win.set_label("Canvas n.11");
	win.wait_for_button();

	Circle c{ Point{ 100,200 },50};
	Graph_lib::Ellipse e{ Point{ 100,200 },75,25 };
	e.set_color(Color::dark_red);
	Mark m{ Point{ 100,200 },'x' };
	win.attach(c);
	win.attach(e);
	win.attach(m);
	win.set_label("Canvas n.12");
	win.wait_for_button();


}





// ***********************************************************************************************************************************
/* Test de base livré avec la librairie FLTK : OK !

// Librairies FLTK - Version 1.3.4-2 référencée dans le projet (debug & release)
// #include<FL/Fl.h>
// #include<FL/Fl_Box.h>
// #include<FL/Fl_Window.h>

int main()
{
	/* Test de base
	Fl_Window window(400, 400, "Window title");
	Fl_Box box(0, 0, 400, 400, "Hey, I mean, Hello, World!");
	window.show();
	return Fl::run();
	
}

*/ 
// *************************************************************************************************************************************