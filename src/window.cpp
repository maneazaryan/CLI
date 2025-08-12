#include "window.h"

//code a poxvel, es masy nayel
void Window::AddElement(Base* base){
	int pId=base->getpId();
	int id=base->getId();
	int row=base->getRow();
	int col=base->getCol();
	if(m_V.empty() || pId==-1){
		m_V.push_back(std::vector<Base*>{base});
	}
	if (!m_V.empty()) {
		for(int i=0; i< static_cast<int>(m_V.size()); i++)
		{
			if(m_V[i][0]->getpId()==pId){
				if(row<=m_V[i][0]->getRow() && col<=m_V[i][0]->getCol()){
					m_V[i].push_back(base);
				}
				else{

					std::cout<<"Erorr::out of range"<<std::endl;
					return ;
				}
			}
		}
	}
	Window* w =dynamic_cast<Window*>(base);
	if(w==nullptr){
		std::cout<<"Erorr::wrong pId"<<std::endl;
		return ;
	}else{
		m_V.push_back(std::vector<Base*>{base});
	}
}
