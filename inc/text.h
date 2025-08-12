#pragma once
#include <iostream>	
#include "base.h"
class Text: public Base{
        private:
                std::string m_text;
        public:
                Text(int id, std::string text, int pId, int row, int col ):
                        Base(id, row, col, pId), m_text(text) {}
                virtual void AddElement(Base* base)override;
};
