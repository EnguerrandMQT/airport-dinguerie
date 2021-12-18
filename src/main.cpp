#include "../headers/Airport.hpp"

#define NB_OF_PLANES 5

void showPlane(vector<Plane *> planes, vector<Airport *> airports) {
  RenderWindow window(VideoMode(600, 600), "Airport");

  //! background
  Texture texture;
  texture.loadFromFile("../img/grass2.jpg");
  Sprite sprite;
  Vector2u size = texture.getSize();
  sprite.setTexture(texture);

  //! runway
  RectangleShape runway(Vector2f(100, 5));
  runway.setPosition(260, 305);
  runway.setFillColor(Color::White);

  //! plane
  CircleShape plane(8);
  plane.setFillColor(Color::Red);
  Point2D pos;

  //! plane tag
  Text tag;
  Font font;
  font.loadFromFile("../img/arial.ttf");
  tag.setFont(font);
  tag.setCharacterSize(15);
  tag.setFillColor(Color::White);
  //tag.setStyle(sf::Text::Bold);

  //! draw
  while (window.isOpen()) {
    Event event;
    while (window.pollEvent(event)) {
      if (event.type == Event::Closed) {
        window.close();
      }
    }
    window.clear();
    window.draw(sprite); // background

  /*   for (auto &ap : airports) {
      pos = ap->getPos();
      runway.setPosition(pos.getX()-50, pos.getY());
      window.draw(runway);

    } */
    window.draw(runway);
    for (auto &pl : planes) {
      pos = pl->getPos();
      plane.setPosition(pos.getX()+300, pos.getY()+300);
      window.draw(plane);

      tag.setString(pl->getName() + "\nAlt. : " + to_string(pl->getAlt()));
      tag.setPosition(pl->getPos().getX() + 300, pl->getPos().getY() + 315);
      window.draw(tag);
    }
    window.display();
  }
}

int main(void) {

  srand(time(NULL));
  // Waiting_planes waiting_planes;

  // vector<unique_ptr<Plane>> planes;
  vector<Plane *> planes;
  vector<Airport *> airports;
  Airport *CDG = new Airport();
  Airport *TLS = new Airport();

  airports.push_back(CDG);
  airports.push_back(TLS);

  for (int i = 0; i < NB_OF_PLANES; i++) {
    // auto plane = make_unique<Plane>();
    Plane *plane = new Plane(/* ref(CDG) */);

    planes.push_back(plane);
    CDG->addPlane(plane);
  }

  thread show_thread(showPlane, ref(planes), ref(airports));

  while (1) {
    string i;
    cin >> i;
    if (i == "0") {
      break;
    }
  }

  cout << "Avions dans l'aéroport :" << endl;
  CDG->showPlane();

  show_thread.join();
  return 0;
}
