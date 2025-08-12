#pragma once
#include <iostream>	
#include "base.h"
#include <sstream>
#include <window.h>
#include <table.h>
#include <text.h>
#include <button.h>

void commandsShow();
std::vector<std::string> getCommandsLine();
void doCommand(const std::vector<std::string>& v, bool& quit);
void getFirstWindow();
void getCommands();

