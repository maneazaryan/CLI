#include "base.h"
int Base::getpId()const { return m_pId;}
int Base::getId()const { return m_id;}
int Base::getRow()const { return m_row;}
int Base::getCol()const { return m_col;}
bool Base::checkId(int id)
{
	for(int i=0 ; i<static_cast<int>((m_V).size()); i++)
	{
		for(int j=0; j<static_cast<int>(m_V[i].size()); j++)
		{
			if(m_V[i][j]->getId()==id)
			{
				std::cout<<"Error : id has already existed"<<std::endl;
				return false;
			}
		}
	}
	return true;
}
bool Base::checkPid(int pId)
{
	for(int i=0 ; i<static_cast<int>((m_V).size()); i++)
	{
		for(int j=0; j<static_cast<int>(m_V[i].size()); j++)
		{
			if(m_V[i][j]->getpId()==pId)
			{
				std::cout<<"Error : id has already existed"<<std::endl;
				return false;
			}
		}
	}
	return true;
}
