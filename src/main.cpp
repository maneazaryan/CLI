#include <iostream>	
#include <string>
#include <vector>
#include <sstream>
class Base{
	protected :
		int m_id;
		int m_row;
		int m_col;
		int m_parentWindowId;
	public:
		Base(int id ,int row=-1,int col=-1, int parentWindowId=-1): 
			m_id(id), m_row(row), m_col(col),  m_parentWindowId(parentWindowId) {}
		virtual ~Base(){};
		int getParnentWindowId()const { return m_parentWindowId;}
		int getRow()const { return m_row;}
		int getCol()const { return m_col;}
		//virtual void change()=0;
};

class Window: public Base{
	private:
		int m_rowCount;
		int m_colCount;
		std::vector<std::vector<Base*>> m_V;
	public:
		Window(int id, int rowCount, int colCount, int parentWindowId , int row , int col):
			Base( id, row, col, parentWindowId), m_rowCount(rowCount), m_colCount(colCount) {}
		Window(int id, int rowCount, int colCount):
			Base( id, -1, -1, -1), m_rowCount(rowCount), m_colCount(colCount) {}
		Window(int id, int rowCount, int colCount, int parentWindowId):
			Base( id, -1, -1, parentWindowId), m_rowCount(rowCount), m_colCount(colCount) {}

		void AddElement(Base* base){
			int parentWindowId=base->getParnentWindowId();
			int row=base->getRow();
			int col=base->getCol();
			if(m_V.empty() || parentWindowId==-1){
				m_V.push_back(std::vector<Base*>{base});
				return;
			}
			if (!m_V.empty()) {
				for(int i=0; i< static_cast<int>(m_V.size()); i++)
				{
					if(m_V[i][0]->getParnentWindowId()==parentWindowId){
						if(row<=m_V[i][0]->getRow() && col<=m_V[i][0]->getCol()){
							m_V[i].push_back(base);
							return;
						}
						else{

							std::cout<<"Erorr::out of range"<<std::endl;
							return;
						}
					}
				}
			}
			Window* w =dynamic_cast<Window*>(base);
			if(w==nullptr){
				std::cout<<"Erorr::wrong parentWindowId"<<std::endl;
				return;
			}else{
				m_V.push_back(std::vector<Base*>{base});
			}
		}
};
class Text: public Base{
	private:
		std::string m_text;
	public: 
		Text(int id, std::string text, int parentWindowId, int row, int col ):
			Base(id, row, col, parentWindowId), m_text(text) {}
};
class Table: public Base{
	private:
		int m_tableRow;
		int m_tableCol;
	public: 
		Table(int id, int tableRow, int tableCol, int parentWindowId, int row, int col ):
			Base(id, row, col, parentWindowId), m_tableRow(tableRow), m_tableCol(tableCol) {}
};
class Button: public Base{
	private:
		std::string m_button;
	public: 
		Button (int id, std::string button, int parentWindowId, int row, int col ):
			Base(id, row, col, parentWindowId), m_button(button) {}
};
void commandsShow()
{
	std::cout<<"Command Line Application (CLI)"<<std::endl;
	std::cout<<"Available commands ։ "<<std::endl;
	std::cout<<"	add window <id> <rowCount> <colCount> [parentWindowId=-1] [row=-1] [col=-1]"<<std::endl;
	std::cout<<"	add text <id> <text> <parentWindowId> <row> <col>"<<std::endl;
	std::cout<<"	add table <id> <rowCount> <colCount> <parentWindowId> <row> <col>"<<std::endl;
	std::cout<<"	add button <id> <text> <parentWindowId> <row> <col>"<<std::endl;
	std::cout<<"type ctrl+C to quit"<<std::endl;
}
std::vector<std::string> getCommandsLine()
{
	std::string line;
	std::cout<< " < ";
	getline(std::cin, line);

	std::vector<std::string>commandsLine;

	std::string word;
	std::stringstream ss(line);
	while(ss>>word){
		commandsLine.push_back(word);
	}
	return commandsLine;
}
void doCommand(const std::vector<std::string>& v, bool& quit)
{
	if(v[0]=="add"){
		if(v[1]=="window" && v.size()>=5){
//krknvum e yndhanur mi ban anel
			int id=std::stoi(v[2]);
			int rowCount= std::stoi(v[3]);
			int colCount= std::stoi(v[4]);
			if(v.size()==5){
				Base* base = new Window(id,rowCount,colCount);
			}
			else if(v.size()==6){
				int parentWindowId= std::stoi(v[5]);
				Base* base = new Window(id,rowCount,colCount,parentWindowId);
			}
			else if(v.size()==8){
				int parentWindowId= std::stoi(v[5]);
				int row= std::stoi(v[6]);
				int col= std::stoi(v[7]);
				Base* base = new Window(id,rowCount,colCount,parentWindowId,row,col);
			}
		}	
		if(v[1]=="text" && v.size()==7){
			int id=std::stoi(v[2]);
			std::string text=v[3];
			int parentWindowId=std::stoi(v[4]);
			int row= std::stoi(v[5]);
			int col= std::stoi(v[6]);
			Base* base = new Text(id, text,parentWindowId, row, col);
		}	
		if(v[1]=="table" && v.size()==8){
			int id=std::stoi(v[2]);
			int rowCount= std::stoi(v[3]);
			int colCount= std::stoi(v[4]);
			int parentWindowId=std::stoi(v[5]);
			int row= std::stoi(v[6]);
			int col= std::stoi(v[7]);
			Base* base = new Table(id,rowCount, colCount,parentWindowId, row, col);
		}	
		if(v[1]=="button" && v.size()==7){
			int id=std::stoi(v[2]);
			std::string button=v[3];
			int parentWindowId=std::stoi(v[4]);
			int row= std::stoi(v[5]);
			int col= std::stoi(v[6]);
			Base* base = new Button(id, button, parentWindowId, row, col);
		}
	}
	else if(v[0]=="ctrl+C"){
		quit=false;
	}
	else {
		std::cout<<"Error: wrong command"<<std::endl;
		return;
	}
}
Window* getFirstWindow()
{
	bool correct=false;
	std::vector<std::string> v= getCommandsLine();
	do{
		if(v[0]=="add" && v.size()==8)
		{
			int id=std::stoi(v[2]);
			int rowCount= std::stoi(v[3]);
			int colCount= std::stoi(v[4]);
			int parentWindowId= std::stoi(v[5]);
			int row= std::stoi(v[6]);
			int col= std::stoi(v[7]);
			Window* myFirstW=new Window(id,rowCount,colCount,parentWindowId,row,col);
			correct=true;
			return myFirstW;
		}
		else {
			std::cout<<"Error: first command should be add_window"<<std::endl;
		}
	}while(!correct);
	return nullptr;
}
void getCommands(){
	commandsShow();

	bool quit=true;
	while(quit){
	std::vector<std::string> v= getCommandsLine();
	doCommand(v,quit);

}
}
int main()
{
	getCommands();
	return 0;
}	
