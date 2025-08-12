#pragma once
#include <iostream>
#include <vector>

class Base{
        protected :
                int m_id;
                int m_row;
                int m_col;
                int m_pId;
                std::vector<std::vector<Base*>> m_V;
        public:
                Base(int id ,int row=-1,int col=-1, int pId=-1):
                        m_id(id), m_row(row), m_col(col),  m_pId(pId) {}
                virtual ~Base(){};
                int getpId()const;
                int getId()const;
                int getRow()const;
                int getCol()const;
                virtual void AddElement(Base* base)=0;
                bool checkId(int id);
                bool checkPid(int pId);
};
