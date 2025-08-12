#pragma once
#include <iostream>	
#include <vector>
#include "base.h"
#include "manage.h"
class Window: public Base{
        private:
                int m_rowCount;
                int m_colCount;
        public:
                Window(int id, int rowCount, int colCount, int pId , int row , int col):
                        Base( id, row, col, pId), m_rowCount(rowCount), m_colCount(colCount) {}
                Window(int id, int rowCount, int colCount):
                        Base( id, -1, -1, -1), m_rowCount(rowCount), m_colCount(colCount) {}
                Window(int id, int rowCount, int colCount, int pId):
                        Base( id, -1, -1, pId), m_rowCount(rowCount), m_colCount(colCount) {}

		void Print(Base* base)const override;
};
