#include "../headers/Airport.hpp"
//#include <SFML/Graphics/Texture.hpp>

#define NB_OF_PLANES 5

/*void showPlane(vector<unique_ptr<Plane>> &planes) {
  RenderWindow window(VideoMode(600, 600), "Ca marche !");

  Texture texture;
  texture.loadFromFile("../img/France.jpg");
  Sprite sprite;
  Vector2u size = texture.getSize();
  sprite.setTexture(texture);

  RectangleShape runway(Vector2f(100, 5));
  runway.setFillColor(Color::White);
  runway.setPosition(250, 305);

  CircleShape plane(8);
  plane.setFillColor(Color::Red);

  Point2D pos;
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
    }
    window.display();
  }
}
*/
int main(void) {

  srand(time(NULL));
  Airport CDG = Airport();
  // Waiting_planes waiting_planes;

  vector<unique_ptr<Plane>> planes;

  for (int i = 0; i < NB_OF_PLANES; i++) {
    planes.push_back(make_unique<Plane>());
  }
  //thread show_thread(showPlane, ref(planes));

  while (1) {
    string i;
    cin >> i;
    if (i == "0") {
      break;
    }
  }

  cout << "Avions dans l'aéroport :" << endl;
  for (auto &pl : planes) {
    cout << pl->getName() << endl;
  }

  //show_thread.join();
  return 0;
}
