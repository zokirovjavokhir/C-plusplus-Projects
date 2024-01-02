#include "Entry.h"
#include "Directory.h"
#include "File.h"

#include <sstream>
#include <string>

Entry* find_directory(Directory* root, const std::string& path)
{
    std::string delimiter = "/";
    std::string pathname = path;
    size_t pos = 0;
    std::string component;
    Directory *object = root;
    if (pathname == root->name()) {
        return root;
    }
    else {
        if (pathname.find(delimiter) != std::string::npos) {
            int flag = 0;
            while ((pos = pathname.find(delimiter)) != std::string::npos) {
                component = pathname.substr(0, pos);
                if (flag != 0) { 
                    object = dynamic_cast<Directory*>(object->find(component));
                    if (object == NULL) {
                        break;
                    }   
                }
                pathname.erase(0, pos + delimiter.length());
                flag++;
            }
            if (object != NULL) {
                object = dynamic_cast<Directory*>(object->find(pathname));
                if (object != NULL)
                    return object;
                else {
                    return NULL;
                } 
            }
            else {  
                return NULL;
            }  
        }
        else {  
            return NULL;
        }
    }
}
void exec_cmd(Directory* root,std::string cmd)
{
    //*****Do NOT MODIFY START*****
    std::istringstream iss1(cmd), iss2(cmd);
    std::string token;
    std::getline(iss2, token, ' ');
    std::getline(iss1, token, ' ');
    //*****DO NOT MODIFY END*****

    //Implement your code here
    //...
  std::string str;
  std::getline(iss2, str, ' ');
  
  Entry* object;

  if (token == "tree") {
     Entry* object1 = find_directory(root, str);
      if (object1 != NULL)
          std::cout << *object1 << std::endl;
      else
          std::cout << "no such directory" << std::endl << std::endl;
  }
  else if (token == "ls") {
      Entry* object1 = find_directory(root, str);
      if (object1 != NULL) {
          std::string no_beaches =  object1->content();
          std::cout << no_beaches << std::endl;
          std::cout << std::endl;
      }   
      else
          std::cout << "no such directory" << std::endl << std::endl;
  }
  else if (token == "cat") {
      std::string delimiter = "/";
      if (str.find(delimiter) != std::string::npos) {
          std::string direct;
          auto pos1 = str.find_last_of('/');
          if (pos1 != std::string::npos)
              direct = str.substr(0, pos1);
          size_t pos2 = 0;
        
          while ((pos2 = str.find(delimiter)) != std::string::npos) {     
              str.erase(0, pos2 + delimiter.length());
          }
          Directory* object1 = dynamic_cast<Directory*>(find_directory(root, direct));
          File* fileObject;
          if (object1 != NULL) {
              fileObject = dynamic_cast<File*>(object1->find(str));
              if (fileObject != NULL) {
                  std::string no_beaches = fileObject->content();
                  std::cout << no_beaches << std::endl;
                  std::cout << std::endl;
              }
              else
                  std::cout << "no such file" << std::endl << std::endl;
          }
          else
              std::cout << "no such path" << std::endl << std::endl;     
      }
      else {
          std::cout << "no such path" << std::endl;
          std::cout << std::endl;
      }
  }
  else if (token == "mkdir") {
      std::string delimiter = "/";
      Entry* object1 = find_directory(root, str);
      if (object1 != NULL)
          std::cout << "directory already exists" << std::endl << std::endl;
      else {
          std::string direct;
          auto pos1 = str.find_last_of('/');
          if (pos1 != std::string::npos)
              direct = str.substr(0, pos1);
          size_t pos2 = 0;

          while ((pos2 = str.find(delimiter)) != std::string::npos) {
              str.erase(0, pos2 + delimiter.length());
          }
          Directory* object1 = dynamic_cast<Directory*>(find_directory(root, direct));
          if (object1 != NULL) {
              object1->add(new Directory(str));
          }
          else
              std::cout << "no such path" << std::endl << std::endl;
      }  
  }
  else if (token == "touch") {
      std::string delimiter = "/";
      if (str.find(delimiter) != std::string::npos) {
          std::string direct;
          auto pos1 = str.find_last_of('/');
          if (pos1 != std::string::npos)
              direct = str.substr(0, pos1);
          size_t pos2 = 0;
        
          while ((pos2 = str.find(delimiter)) != std::string::npos) {  
              str.erase(0, pos2 + delimiter.length());
          }
          Directory* object1 = dynamic_cast<Directory*>(find_directory(root, direct));
          File* fileObject;
          if (object1 != NULL) {
              fileObject = dynamic_cast<File*>(object1->find(str));
              if (fileObject != NULL) {
                  std::cout << "file already exists" << std::endl << std::endl;
              }
              else {
                  object1->add(new File(str));
              }
          }
          else
              std::cout << "no such path" << std::endl << std::endl;    
      }
      else {
          std::cout << "no such path" << std::endl;
          std::cout << std::endl;
      }
  }
  else if (token == "echo") {
    std::string delimiter = "/";
    size_t pos3 = cmd.find(" ");
    pos3 = cmd.find(" ", pos3 + 1);
    std::string text = cmd.substr(pos3+1, std::string::npos);
      if (str.find(delimiter) != std::string::npos) {
          std::string direct;
          auto pos1 = str.find_last_of('/');
          if (pos1 != std::string::npos)
              direct = str.substr(0, pos1);
          size_t pos2 = 0;
        
          while ((pos2 = str.find(delimiter)) != std::string::npos) {     
              str.erase(0, pos2 + delimiter.length());
          }
          Directory* object1 = dynamic_cast<Directory*>(find_directory(root, direct));
          File* fileObject;
          if (object1 != NULL) {
              fileObject = dynamic_cast<File*>(object1->find(str));
              if (fileObject != NULL) {
                  std::string update = fileObject->content(text);
                  std::cout << update << std::endl << std::endl;
              }
              else {
                  object1->add(new File(str,text));
              }
          }
          else
              std::cout << "no such path" << std::endl << std::endl;   
      }
      else {
          std::cout << "no such path" << std::endl;
          std::cout << std::endl;
      }
  }
  else if (token == "mv") {
  std::string delimiter = "/";
  size_t pos3 = cmd.find(" ");
  pos3 = cmd.find(" ", pos3 + 1);
  std::string text = cmd.substr(pos3 + 1, std::string::npos);
  if (str.find(delimiter) != std::string::npos) {
      std::string direct;
      auto pos1 = str.find_last_of('/');
      if (pos1 != std::string::npos)
          direct = str.substr(0, pos1);
      size_t pos2 = 0;

      while ((pos2 = str.find(delimiter)) != std::string::npos) {
          str.erase(0, pos2 + delimiter.length());
      }
      Directory* object1 = dynamic_cast<Directory*>(find_directory(root, direct));
      Entry* entryObject;
      if (object1 != NULL) {
          entryObject = object1->find(str);
          if (entryObject != NULL) {
              Entry* entryCopy = entryObject->clone();
                  Directory* objectDirect = dynamic_cast<Directory*>(find_directory(root, text));
                      if (objectDirect != NULL) {
                          if (objectDirect->add(entryCopy)) {
                              object1->remove(entryObject->name());
                          }  
                      }
                      else {
                          std::cout << "no such file or directory" << std::endl << std::endl;
                      }  
          }
          else {
              std::cout << "no such file or directory" << std::endl << std::endl;
          }
      }
      else
          std::cout << "no such source path" << std::endl << std::endl;
  }
  else {
      std::cout << "no such source path" << std::endl;
      std::cout << std::endl;
  }
  }
  else if (token == "cp") {
  std::string delimiter = "/";
  size_t pos3 = cmd.find(" ");
  pos3 = cmd.find(" ", pos3 + 1);
  std::string text = cmd.substr(pos3 + 1, std::string::npos);
  if (str.find(delimiter) != std::string::npos) {
      std::string direct;
      auto pos1 = str.find_last_of('/');
      if (pos1 != std::string::npos)
          direct = str.substr(0, pos1);
      size_t pos2 = 0;

      while ((pos2 = str.find(delimiter)) != std::string::npos) {
          str.erase(0, pos2 + delimiter.length());
      }
      Directory* object1 = dynamic_cast<Directory*>(find_directory(root, direct));
      Entry* entryObject;
      if (object1 != NULL) {
          entryObject = object1->find(str);
          if (entryObject != NULL) {
              Entry* entryCopy = entryObject->clone();
              Directory* objectDirect = dynamic_cast<Directory*>(find_directory(root, text));
              if (objectDirect != NULL) {                 
                  objectDirect->add(entryCopy);
              }
              else {
                  std::cout << "no such file or directory" << std::endl << std::endl;
              }
          }
          else {
              std::cout << "no such file or directory" << std::endl << std::endl;
          }
      }
      else
          std::cout << "no such source path" << std::endl << std::endl;
  }
  else {
      std::cout << "no such source path" << std::endl;
      std::cout << std::endl;
  }
  }
  else if (token == "rmdir") {
  std::string delimiter = "/";
  if (str.find(delimiter) != std::string::npos) {
      std::string direct;
      auto pos1 = str.find_last_of('/');
      if (pos1 != std::string::npos)
          direct = str.substr(0, pos1);
      size_t pos2 = 0;

      while ((pos2 = str.find(delimiter)) != std::string::npos) {
          str.erase(0, pos2 + delimiter.length());
      }
      Directory* object1 = dynamic_cast<Directory*>(find_directory(root, direct));
      Directory* directObject;
      if (object1 != NULL) {
          directObject = dynamic_cast<Directory*>(object1->find(str));
          if (directObject != NULL) {
              object1->remove(directObject->name());
          }
          else {
              std::cout << "no such directory" << std::endl << std::endl;
          }
      }
      else
          std::cout << "no such path" << std::endl << std::endl;
  }
  else {
      std::cout << "no such path" << std::endl;
      std::cout << std::endl;
  }
  }
  else if (token == "rm") {
  std::string delimiter = "/";
  if (str.find(delimiter) != std::string::npos) {
      std::string direct;
      auto pos1 = str.find_last_of('/');
      if (pos1 != std::string::npos)
          direct = str.substr(0, pos1);
      size_t pos2 = 0;

      while ((pos2 = str.find(delimiter)) != std::string::npos) {

          str.erase(0, pos2 + delimiter.length());
      }
      Directory* object1 = dynamic_cast<Directory*>(find_directory(root, direct));
      File* fileObject;
      if (object1 != NULL) {
          fileObject = dynamic_cast<File*>(object1->find(str));
          if (fileObject != NULL) {
              object1->remove(fileObject->name());
          }
          else {
              std::cout << "no such file" << std::endl << std::endl;
          }
      }
      else
          std::cout << "no such path" << std::endl << std::endl;
  }
  else {
      std::cout << "no such path" << std::endl;
      std::cout << std::endl;
  }
  }
  else {
  std::cout << "wrong command" << std::endl << std::endl;
}
}
int main()
{
    //*****Do NOT MODIFY START*****
    Directory root("root");
    root.add(new Directory("hello"));
    std::cout << root << std::endl; //this prints all the directories and files in root directory. (the result of tree command)

    std::string inputBuffer;
    while (1) {
        std::getline(std::cin, inputBuffer);
        if (inputBuffer.compare("exit") == 0) break;
        exec_cmd(&root, inputBuffer);
    }
    //*****DO NOT MODIFY END*****
}