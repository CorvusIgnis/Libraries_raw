/*
  Version 1.0.0
  anmapping.h - Library for reading analog inputs and returning the mapped value.
  Created by ChatGPT.
  Knowledge cutoff: 2021-09
  Current date: 2023-04-02
*/

#ifndef anmapping_h
#define anmapping_h

#include "Arduino.h"

class Anmapping {
  public:
    Anmapping(int pin, int inMin, int inMax, int outMin, int outMax, const char* name);
    int read();
    void printMappedValue();
  private:
    int _pin;
    int _inMin;
    int _inMax;
    int _outMin;
    int _outMax;
    const char* _name;
};

Anmapping::Anmapping(int pin, int inMin, int inMax, int outMin, int outMax, const char* name) {
  _pin = pin;
  _inMin = inMin;
  _inMax = inMax;
  _outMin = outMin;
  _outMax = outMax;
  _name = name;
}

int Anmapping::read() {
  int val = analogRead(_pin);
  int mappedVal = map(val, _inMin, _inMax, _outMin, _outMax);
  return mappedVal;
}

void Anmapping::printMappedValue() {
  int val = read();
  Serial.print(_name);
  Serial.print(": ");
  Serial.print(val);
  Serial.println("%");
  Serial1.print(_name);
  Serial1.print(": ");
  Serial1.print(val);
  Serial1.println("%");
}

#endif
 