#pragma once
#include <iostream>	
#include "base.h"
#include <sstream>
#include <window.h>
#include <manage.h>
#include <table.h>
#include <text.h>
#include <button.h>

void commandsShow();
std::vector<std::string> getCommandsLine();
void doCommand(const std::vector<std::string>& v,Manage& m, bool& quit);
void getFirstWindow(Manage& m);
void getCommands(Manage& m);
