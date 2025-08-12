#include "manage.h"

bool Manage::checkId(int id) 
{
        for(int i=0 ; i<static_cast<int>((m_V).size()); i++)
        {
                for(int j=0; j<static_cast<int>(m_V[i].size()); j++)
                {
                        if(m_V[i][j]!=nullptr && m_V[i][j]->getId()==id)
                        {
                                std::cout<<"Error : id has already existed"<<std::endl;
                                return false;
                        }
                }
        }
        return true;
}
bool Manage::checkPid(int pId)
{
        for(int i=0 ; i<static_cast<int>((m_V).size()); i++)
        {
                for(int j=0; j<static_cast<int>(m_V[i].size()); j++)
                {
                        if(m_V[i][j]!=nullptr && m_V[i][j]->getpId()==pId)
                        {
                                std::cout<<"Error : parentWindowId has already existed"<<std::endl;
                                return false;
                        }
                }
        }
	return true;
}
void Manage::AddElement(Base* base){
	int pId=base->getpId();
	int id=base->getId();
	int row=base->getRow();
	int col=base->getCol();

	if(!checkId(id)){
		std::cout<<"Error:: id has already used"<<std::endl;
		return ;
	}
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
	//nayelu, tesaky window e pid nor
	Window* w =dynamic_cast<Window*>(base);
	if(w==nullptr){
		std::cout<<"Erorr::wrong pId"<<std::endl;
		return;
	}else{
		m_V.push_back(std::vector<Base*>{base});
	}
}
