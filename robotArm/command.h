#include <Arduino.h>

#ifndef COMMAND_H_
#define COMMAND_H_

struct Cmd {
  char id;
  int num;
  float valueX;
  float valueY;
  float valueZ;
  float valueF;
  float valueE;
  float valueT; 
};

class Command {
  public:
    Command();
    bool handleGcode();
    bool processMessage(String& msg);
    Cmd getCmd() const;
  private: 
    int pos(String const& s, char c, int start = 0);
    String message;
    Cmd command;
};

void printErr();
void printFault();
void printComment(const char* c);
void printComment(String const& s);
void printStatus(String const& s);
void printStatus(const char* c);

void printOk();

#endif
