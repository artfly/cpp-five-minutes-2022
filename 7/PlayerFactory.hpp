
#pragma once

#include <unordered_map>
#include <iostream>

class MediaPlayer {
  public:
    virtual ~MediaPlayer() {
      std::cout << "MediaPlayer dtor" << std::endl;
    }
    virtual void play() = 0;
};

class MP3Player: public MediaPlayer {
  public:

    ~MP3Player() override {
      std::cout << "MP3Player dtor" << std::endl;
    }

    void play() override {
      std::cout << "MP3" << std::endl;
    }
};

class MidiPlayer: public MediaPlayer {
  public:
    void play() override {
      std::cout << "Midi" << std::endl;
    }
};

class PlayerFactory {
  public:

    ~PlayerFactory() {
      for (const auto & entry : players_) {
        delete entry.second;
      }
    }

    static PlayerFactory & getInstance() {
      static PlayerFactory f;
      return f;
    }

    bool registerPlayer(MediaPlayer * player, int i) {
      players_[i] = player;
      return true;
    }

    MediaPlayer * getPlayer(int i) {
      auto it = players_.find(i);
      if (it == players_.end()) {
        throw std::runtime_error("no player with id = " + std::to_string(i));
      }
      return (*it).second;
    }
  private:
    PlayerFactory() = default;
    PlayerFactory(PlayerFactory & other) = delete;
    PlayerFactory & operator=(PlayerFactory & other) = delete;

    std::unordered_map<int, MediaPlayer *> players_;
};

namespace {
  bool mp3player_register = PlayerFactory::getInstance().registerPlayer(new MP3Player(), 0);
  bool midiplayer_register = PlayerFactory::getInstance().registerPlayer(new MidiPlayer(), 1);
}