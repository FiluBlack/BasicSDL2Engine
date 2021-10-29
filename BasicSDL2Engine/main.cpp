// BasicSDLWindow.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include "pch.h"

#include "Image.h"
#include "Spritesheet.h"
#include "Essentials.h"


int main(int argc, char* args[])
{
    SDL_Init(SDL_INIT_EVERYTHING);
    IMG_Init(IMG_INIT_JPG | IMG_INIT_TIF | IMG_INIT_PNG | IMG_INIT_WEBP);
    SDL_Window* w = SDL_CreateWindow("Test", 50, 50, 800, 600, SDL_WINDOW_RESIZABLE);
    SDL_Renderer* r1 = SDL_CreateRenderer(w, -1, SDL_RENDERER_TARGETTEXTURE);
    
    SDL_SetRenderDrawColor(r1, 0, 0, 255, 255);
    SDL_SetRenderDrawBlendMode(r1, SDL_BLENDMODE_NONE);
    SDL_RenderClear(r1);
    
    Spritesheet s1(r1, "arrow.png"), s2(r1, "arrow2.png");



    Spritesheet s3(Spritesheet(r1, "arrow2.png"));
    s3.log();
    s2.log();


    //Spritesheet s3(s2);


    
    

    ////SDL_SetRenderDrawColor(r1, 255, 255, 255, 0);
    //Image i(r1, "arrow2.png", Position2D<int>(200, 300), Size2D<unsigned int>(46, 56));
    ////i.render(r1);
    ////i.setPosition(200, 400);
    //SDL_Rect r2 = { 0, 0, 230, 200 };
    //Image* i3 = i.getImagePart(r1, &r2);
    //i3->setPosition(200, 400);
    //i3->render(r1);

    SDL_RenderPresent(r1);

    //Vector2D<float> f(2.3, 3.2);
    //Vector2D<int> v = f.convertTo<int>();

    std::cin.get();
    IMG_Quit();
    SDL_Quit();


    
    return 0;
}

// Programm ausführen: STRG+F5 oder Menüeintrag "Debuggen" > "Starten ohne Debuggen starten"
// Programm debuggen: F5 oder "Debuggen" > Menü "Debuggen starten"

// Tipps für den Einstieg: 
//   1. Verwenden Sie das Projektmappen-Explorer-Fenster zum Hinzufügen/Verwalten von Dateien.
//   2. Verwenden Sie das Team Explorer-Fenster zum Herstellen einer Verbindung mit der Quellcodeverwaltung.
//   3. Verwenden Sie das Ausgabefenster, um die Buildausgabe und andere Nachrichten anzuzeigen.
//   4. Verwenden Sie das Fenster "Fehlerliste", um Fehler anzuzeigen.
//   5. Wechseln Sie zu "Projekt" > "Neues Element hinzufügen", um neue Codedateien zu erstellen, bzw. zu "Projekt" > "Vorhandenes Element hinzufügen", um dem Projekt vorhandene Codedateien hinzuzufügen.
//   6. Um dieses Projekt später erneut zu öffnen, wechseln Sie zu "Datei" > "Öffnen" > "Projekt", und wählen Sie die SLN-Datei aus.
