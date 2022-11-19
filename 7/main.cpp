#include "PlayerFactory.hpp"

int main() {
  int num;
  if (!(std::cin >> num)) {
    std::cerr << "exepcted number of player to invoke" << std::endl;
    return -1;
  }
  try {
    MediaPlayer * p = PlayerFactory::getInstance().getPlayer(num);
    p->play();
  } catch (std::runtime_error & e) {
    std::cerr << e.what() << std::endl;
    return -1;
  }
}