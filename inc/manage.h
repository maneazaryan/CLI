#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "base.h"
#include "window.h"

class Manage{
	private:
		std::vector<std::vector<Base*>> m_V;
	public:
		Manage(){}
		virtual~Manage(){
			for(int i=0; i<static_cast<int>(m_V.size());i++){
				for(int j=0; j<static_cast<int>(m_V[i].size());j++){
					delete m_V[i][j];
					m_V[i][j]=nullptr;
				}
			}
		}

		bool checkId(int id);
		bool checkPid(int pId);
		void AddElement(Base* base);

};
