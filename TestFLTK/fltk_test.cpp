//
// Book : Version du chapitre 11 de l'ouvrage.
// "Programming -- Principles and Practice Using C++" de Bjarne Stroustrup (2ème édition : 2014)
// Commit initial : 04/03/2018 - Installation FLTK
// Commit en cours : 06/03/2018 - Drill page 437
// Caractères spéciaux : [ ]   '\n'   {  }   ||   ~   _     @

// Librairie indispensable sous Windows et VC++
// #include "stdafx.h"


// Librairie restreinte fournie par BS
// #include "std_lib_facilities.h"

// Librairies FLTK - Version 1.3.4-2 référencée dans le projet (debug & release)
#include<FL/Fl.h>
#include<FL/Fl_Box.h>
#include<FL/Fl_Window.h>

int main()
{
	Fl_Window window(400, 400, "Window title");
	Fl_Box box(0, 0, 400, 400, "Hey, I mean, Hello, World!");
	window.show();
	return Fl::run();
}