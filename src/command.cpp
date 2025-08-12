#include "command.h"
void commandsShow()
{
        std::cout<<"Command Line Application (CLI)"<<std::endl;
        std::cout<<"Available commands ։ "<<std::endl;
        std::cout<<"    add window <id> <rowCount> <colCount> [pId=-1] [row=-1] [col=-1]"<<std::endl;
        std::cout<<"    add text <id> <text> <pId> <row> <col>"<<std::endl;
        std::cout<<"    add table <id> <rowCount> <colCount> <pId> <row> <col>"<<std::endl;
        std::cout<<"    add button <id> <text> <pId> <row> <col>"<<std::endl;
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
void doCommand(const std::vector<std::string>& v,Manage& m , bool& quit)
{
        if(v[0]=="add"){
                if(v[1]=="window" && v.size()>=5){
                        //krknvum e yndhanur mi ban anel
                        int id=std::stoi(v[2]);
                        int rowCount= std::stoi(v[3]);
                        int colCount= std::stoi(v[4]);
                        if(v.size()==5){
                                Base* base = new Window(id,rowCount,colCount);
				
                                if(m.checkId(id)){
                                        m.AddElement(base);
                                }else{
                                        delete base;
                                }
                        }
                        else if(v.size()==6){
                                int pId= std::stoi(v[5]);
                                Base* base = new Window(id,rowCount,colCount,pId);
                                if(m.checkId(id)){
                                        m.AddElement(base);
                                }else{
                                        delete base;
                                }
                        }
                        else if(v.size()==8){
                                int pId= std::stoi(v[5]);
                                int row= std::stoi(v[6]);
                                int col= std::stoi(v[7]);
                                Base* base = new Window(id,rowCount,colCount,pId,row,col);
                                if(m.checkId(id)){
                                        m.AddElement(base);
                                }else{
                                        delete base;
                                }
                        }
                }
                if(v[1]=="text" && v.size()==7){
                        int id=std::stoi(v[2]);
                        std::string text=v[3];
                        int pId=std::stoi(v[4]);
                        int row= std::stoi(v[5]);
                        int col= std::stoi(v[6]);
                        Base* base = new Text(id, text,pId, row, col);
                                m.AddElement(base);
                }
                if(v[1]=="table" && v.size()==8){
                        int id=std::stoi(v[2]);
                        int rowCount= std::stoi(v[3]);
                        int colCount= std::stoi(v[4]);
                        int pId=std::stoi(v[5]);
                        int row= std::stoi(v[6]);
                        int col= std::stoi(v[7]);
                        Base* base = new Table(id,rowCount, colCount,pId, row, col);
                                m.AddElement(base);
                }
                if(v[1]=="button" && v.size()==7){
                        int id=std::stoi(v[2]);
                        std::string button=v[3];
                        int pId=std::stoi(v[4]);
                        int row= std::stoi(v[5]);
                        int col= std::stoi(v[6]);
                        Base* base = new Button(id, button, pId, row, col);
                                m.AddElement(base);
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
void getFirstWindow(Manage& m)
{
        bool correct=true;
        bool quitF=true;
        while(correct){
        std::vector<std::string> v= getCommandsLine();
                if(v[0]=="add" && (v.size()==5 || v.size()==6))
                {
                        int id=std::stoi(v[2]);
                        int rowCount= std::stoi(v[3]);
                        int colCount= std::stoi(v[4]);
                        if(v.size()==6){
                        	int pId= std::stoi(v[5]);
                        	Window* base=new Window(id,rowCount,colCount,pId);
                        m.AddElement(base);
			}else{
                        	Window* base=new Window(id,rowCount,colCount);
                        m.AddElement(base);
			}
                        correct=true;
                }
                else if(v[0]=="ctrl+C"){
                        quitF=false;
                }
                else {
                        std::cout<<"Error: first command should be add window and doesn't have row and col"<<std::endl;
                }
        }
}
void getCommands(Manage& m){
        commandsShow();
        getFirstWindow(m);
        bool quit=true;
        while(quit){
        	std::vector<std::string> v= getCommandsLine();
        	doCommand(v,m,quit);
	}
}
