//
// Created by Alex Balta on 15.06.2024.
//

#pragma once

#include <vector>
#include <algorithm>

class Observer {
  public:
    virtual void update() = 0;
};

class Subject {
  private:
    std::vector<Observer *> listeners;
  protected:
    void notify() {
        for (auto l : listeners) {
            l->update();
        }
    }
  public:

    void addListener(Observer *obs) {
        listeners.push_back(obs);
    }
    void deleteListener(Observer *obs) {
        listeners.erase(std::remove(listeners.begin(), listeners.end(), obs), listeners.end());
    }
};
