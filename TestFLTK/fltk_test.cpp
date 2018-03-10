//
// Book : Version du chapitre 12 de l'ouvrage.
// "Programming -- Principles and Practice Using C++" de Bjarne Stroustrup (2ème édition : 2014)
// Commit initial : 04/03/2018 - Installation FLTK 1.3.4-2 (http://www.fltk.org) [conseils d'installation du site bumpyroadtocode.com car la librairie utilisée par BS, 1.1.x, était très ancienne]
// Commit en cours : 10/03/2018 - Drill page 437
// Caractères spéciaux : [ ]   '\n'   {  }   ||   ~   _     @


#include "Graph.h"
#include "Simple_window.h"

int main()
{
	
	using namespace Graph_lib;	// Le préfixe Graph_Lib : le namespace ne semble pas fonctionner tout le temps !!! Ambiguïté avec les nouvelles librairies FLTK ?

	/*
	// ***********************************************************************************************************************************************************
	// Drill de la page 437
		
	Point tl{100, 100 };
	Simple_window win(tl, 600, 400, "Ma première fenêtre");	// Inclut un bouton Next qui permet une pause
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

	Graph_lib::Polygon poly;							// Rajout de Graph_Lib 
	poly.add(Point{ 300,200 });
	poly.add(Point{ 350,100 });
	poly.add(Point{ 400,200 });
	poly.set_color(Color::red);
	poly.set_style(Line_style::dash);
	win.attach(poly);
	win.set_label("Canvas n.5");
	win.wait_for_button();
	

	Graph_lib::Rectangle r{ Point{ 200,200 },100,50 };	// Rajout de Graph_Lib
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
	
	*/

	// ***********************************************************************************************************************************************************
	// Exercices page 438 et 439

	Point tl{ 600, 200 };
	Simple_window win(tl, 1200, 800, "Exercice n°1, page 438");	// Inclut un bouton Next qui permet une pause
	
	Graph_lib::Rectangle r{ Point{ 200,200 },100,30 };	// Rajout de Graph_Lib
	r.set_color(Color::blue);
	win.attach(r);
	Text t{ Point{ 230,220 },"Howdy!" };
	win.attach(t);

	Closed_polyline poly_rect;
	poly_rect.add(Point{ 100,50 });
	poly_rect.add(Point{ 200,50 });
	poly_rect.add(Point{ 200,100 });
	poly_rect.add(Point{ 100,100 });
	poly_rect.add(Point{ 50,75 });
	poly_rect.set_color(Color::red);
	win.attach(poly_rect);
	
	
	Open_polyline initialeA; // A
	initialeA.add(Point{ 400,50 });
	initialeA.add(Point{ 425,10 });
	initialeA.add(Point{ 450,50 });
	initialeA.add(Point{ 437,30 });
	initialeA.add(Point{ 412,30 });
	initialeA.set_color(Color::black);
	initialeA.set_style(Line_style(Line_style::solid, 4));
	win.attach(initialeA);

	Open_polyline initialeT; // T
	initialeT.add(Point{ 500,10 });
	initialeT.add(Point{ 550,10 });
	initialeT.add(Point{ 525,10 });
	initialeT.add(Point{ 525,50 });
	initialeT.set_color(Color::green);
	initialeT.set_style(Line_style(Line_style::solid, 4));
	win.attach(initialeT);
	
	// Tic Tac Toe : 9 cases *********************************************************************************************
	// Le stockage en vecteur permettant d'afficher facilement les 9 cases ne fonctionne pas : problème dans Graph.h
	/*
	vector <Graph_lib::Rectangle>ttt{};
	
	ttt.push_back( Graph_lib::Rectangle{ Point{ 400,200 },50,50 } );	// x 9 en faidant varier les coordonnées 400/200
	
	bool white_color = true;
	
	for (auto x:ttt) {
		
		if (white_color) {
			x.set_fill_color(Color::white);
			white_color = false;
		}
		else {
			x.set_fill_color(Color::red);
			white_color = true;
		}
		win.attach(x);
	}
	*/
	
	// La maison
	Graph_lib::Rectangle murs{ Point{ 400,230 },300,150 };	// Rajout de Graph_Lib
	murs.set_color(Color::black);
	win.attach(murs);

	Open_polyline toit;
	toit.add(Point{ 400,230 });
	toit.add(Point{ 550,180 });
	toit.add(Point{ 700,230 });
	toit.set_color(Color::black);
	win.attach(toit);

	Graph_lib::Rectangle porte{ Point{ 530,330 },40,50 };	
	porte.set_color(Color::red);
	win.attach(porte);

	Circle bouton{ Point{ 560,360 },5 };
	bouton.set_fill_color(Color::cyan);
	win.attach(bouton);


	// Les 5 anneaux olympiques entrelacés : bleu, noir, rouge, jaune, vert
	Circle c1{ Point{ 500,500 },50 };
	c1.set_color(Color::blue);
	c1.set_style(Line_style(Line_style::solid, 4));
	win.attach(c1);

	Circle c2{ Point{ 575,500 },50 };
	c2.set_color(Color::black);
	c2.set_style(Line_style(Line_style::solid, 4));
	win.attach(c2);

	Circle c3{ Point{ 650,500 },50 };
	c3.set_color(Color::red);
	c3.set_style(Line_style(Line_style::solid, 4));
	win.attach(c3);

	Circle c4{ Point{ 537,550 },50 };
	c4.set_color(Color::yellow);
	c4.set_style(Line_style(Line_style::solid, 4));
	win.attach(c4);

	Circle c5{ Point{ 612,550 },50 };
	c5.set_color(Color::green);
	c5.set_style(Line_style(Line_style::solid, 4));
	win.attach(c5);

	
	// Photo commentée
	Image canard{ Point{ 800,480 },"canard.jpg" };
	win.attach(canard);
	Text t1{ Point{ 930,500 },"Le beau canard" };
	t1.set_font(Font::times_bold);
	t1.set_color(Color::black);
	t1.set_font_size(20);
	win.attach(t1);
	
	

	win.wait_for_button();
	

}




/*
// ***********************************************************************************************************************************
// Test de base livré avec la librairie FLTK : OK !

// Librairies FLTK - Version 1.3.4-2 référencée dans le projet (debug & release)
#include<FL/Fl.h>
#include<FL/Fl_Box.h>
#include<FL/Fl_Window.h>

int main()
{
	// Test de base
	Fl_Window window(400, 400, "Window title");
	Fl_Box box(0, 0, 400, 400, "Hey, I mean, Hello, World !");
	window.show();
	return Fl::run();
	
}

 */
// *************************************************************************************************************************************