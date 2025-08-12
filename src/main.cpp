#include <iostream>	
#include <string>
#include <vector>
#include <sstream>
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
		int getpId()const { return m_pId;}
		int getId()const { return m_id;}
		int getRow()const { return m_row;}
		int getCol()const { return m_col;}
		virtual void AddElement(Base* base)=0;
		bool checkId(int id)
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
		bool checkPid(int pId)
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
};

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

		void AddElement(Base* base)override{
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
};
class Text: public Base{
	private:
		std::string m_text;
	public: 
		Text(int id, std::string text, int pId, int row, int col ):
			Base(id, row, col, pId), m_text(text) {}
		virtual void AddElement(Base* base)override
		{
		}
};
class Table: public Base{
	private:
		int m_tableRow;
		int m_tableCol;
	public: 
		Table(int id, int tableRow, int tableCol, int pId, int row, int col ):
			Base(id, row, col, pId), m_tableRow(tableRow), m_tableCol(tableCol) {}
		virtual void AddElement(Base* base)override
		{
		}
};
class Button: public Base{
	private:
		std::string m_button;
	public: 
		Button (int id, std::string button, int pId, int row, int col ):
			Base(id, row, col, pId), m_button(button) {}
		virtual void AddElement(Base* base)override
		{
		}
};
void commandsShow()
{
	std::cout<<"Command Line Application (CLI)"<<std::endl;
	std::cout<<"Available commands ։ "<<std::endl;
	std::cout<<"	add window <id> <rowCount> <colCount> [pId=-1] [row=-1] [col=-1]"<<std::endl;
	std::cout<<"	add text <id> <text> <pId> <row> <col>"<<std::endl;
	std::cout<<"	add table <id> <rowCount> <colCount> <pId> <row> <col>"<<std::endl;
	std::cout<<"	add button <id> <text> <pId> <row> <col>"<<std::endl;
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
//id unique linel stugel
//pid ete chexav erorr tpel
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

				if(base->checkId(id)){
					base->AddElement(base);
				}else{
					delete base;
				}
			}
			else if(v.size()==6){
				int pId= std::stoi(v[5]);
				Base* base = new Window(id,rowCount,colCount,pId);
				base->AddElement(base);
			}
			else if(v.size()==8){
				int pId= std::stoi(v[5]);
				int row= std::stoi(v[6]);
				int col= std::stoi(v[7]);
				Base* base = new Window(id,rowCount,colCount,pId,row,col);
				base->AddElement(base);
			}
		}	
		if(v[1]=="text" && v.size()==7){
			int id=std::stoi(v[2]);
			std::string text=v[3];
			int pId=std::stoi(v[4]);
			int row= std::stoi(v[5]);
			int col= std::stoi(v[6]);
			Base* base = new Text(id, text,pId, row, col);
				base->AddElement(base);
		}	
		if(v[1]=="table" && v.size()==8){
			int id=std::stoi(v[2]);
			int rowCount= std::stoi(v[3]);
			int colCount= std::stoi(v[4]);
			int pId=std::stoi(v[5]);
			int row= std::stoi(v[6]);
			int col= std::stoi(v[7]);
			Base* base = new Table(id,rowCount, colCount,pId, row, col);
				base->AddElement(base);
		}	
		if(v[1]=="button" && v.size()==7){
			int id=std::stoi(v[2]);
			std::string button=v[3];
			int pId=std::stoi(v[4]);
			int row= std::stoi(v[5]);
			int col= std::stoi(v[6]);
			Base* base = new Button(id, button, pId, row, col);
				base->AddElement(base);
		}
	}
	else if(v[0]=="ctrl+C"){
		quit=false;
	}
	else {
		std::cout<<"88Error: wrong command"<<std::endl;
		return;
	}
}
void getFirstWindow()
{
	bool correct=true;
	while(correct){
	std::vector<std::string> v= getCommandsLine();
		if(v[0]=="add" && v.size()==8)
		{
			int id=std::stoi(v[2]);
			int rowCount= std::stoi(v[3]);
			int colCount= std::stoi(v[4]);
			int pId= std::stoi(v[5]);
			int row= std::stoi(v[6]);
			int col= std::stoi(v[7]);
			Window* base=new Window(id,rowCount,colCount,pId,row,col);
			base->AddElement(base);
			correct=true;
		}
		else {
			std::cout<<"Error: first command should be add window"<<std::endl;
		}
	}
}
void getCommands(){
	commandsShow();
	getFirstWindow();
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
