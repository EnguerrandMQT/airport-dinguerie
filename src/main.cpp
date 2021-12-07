#include "../headers/Airport.hpp"

#define NB_OF_PLANES 5

void showPlane(vector<Plane *> planes) {
  RenderWindow window(VideoMode(600, 600), "Ca marche !");

  //! background
  Texture texture;
  texture.loadFromFile("../img/France.jpg");
  Sprite sprite;
  Vector2u size = texture.getSize();
  sprite.setTexture(texture);

  //! runway
  RectangleShape runway(Vector2f(100, 5));
  runway.setFillColor(Color::White);
  runway.setPosition(250, 305);

  //! plane
  CircleShape plane(8);
  plane.setFillColor(Color::Red);
  Point2D pos;

  //! plane tag
  Text tag;
  // tag.setFont(font);
  tag.setCharacterSize(40);
  tag.setFillColor(Color::White);
  // tag.setStyle(sf::Text::Bold | sf::Text::Underlined);

  //! draw
  // while (!stop_thread) {
  while (window.isOpen()) {
    Event event;
    while (window.pollEvent(event)) {
      if (event.type == Event::Closed) {
        window.close();
      }
    }
    window.clear();
    window.draw(sprite);
    window.draw(runway);
    for (auto &pl : planes) {
      pos = pl->getPos();
      plane.setPosition(pos.getX() + 300, pos.getY() + 300);
      window.draw(plane);

      tag.setString(pl->getName());
      tag.setPosition(pos.getX() +300, pos.getY()+300);
      window.draw(tag);
    }
    window.display();
  }
}

int main(void) {

  srand(time(NULL));
  Airport CDG = Airport();
  // Waiting_planes waiting_planes;

  // vector<unique_ptr<Plane>> planes;
  vector<Plane *> planes;

  for (int i = 0; i < NB_OF_PLANES; i++) {
    // auto plane = make_unique<Plane>();
    Plane *plane = new Plane();

    planes.push_back(plane);
    CDG.addPlane(plane);
  }

  thread show_thread(showPlane, ref(planes));

  while (1) {
    string i;
    cin >> i;
    if (i == "0") {
      break;
    }
  }

  cout << "Avions dans l'aéroport :" << endl;
  CDG.showPlane();

  show_thread.join();
  return 0;
}
