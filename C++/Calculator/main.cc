#include <iostream>
#include "calculator.h"
#include <cmath>

using namespace std;


float xx,yy,zz;
int counterX,counterY,counterZ;
int main(){

    string s;
    double result;
	string a;
    bool status= true;
    string front;
    string back;
	Calculator c;

  while(status){
  
        int i=0;
        int j=0;
   
        cout<<"Enter your equation to calculate: ";
        getline(cin, s);
        if ((s == "x" && xx == 0) || (s == "y" && yy == 0) || (s == "z" && zz == 0)) {
            cout << "Answer: 0" << endl;
        } else if (s == "x" && counterX == 1) {
            cout << "Answer: " << xx << endl;
        } else if (s == "y" && counterY == 1) {
            cout << "Answer: " << yy << endl;
        } else if (s == "z" && counterZ == 1) {
            cout << "Answer: " << zz << endl;
        }     
        else if((s[0]=='x'&&s[1]=='+'&&s[2]=='y')||(s[0]=='x'&&s[1]=='-'&&s[2]=='y')||(s[0]=='x'&&s[1]=='*'&&s[2]=='y')||(s[0]=='x'&&s[1]=='/'&&s[2]=='y')||(s[0]=='x'&&s[1]=='%'&&s[2]=='y')||(s[0]=='x'&&s[1]=='^'&&s[2]=='y')){

            if(s[1]=='+'){
                result=c.add(xx,yy);
                cout<<"Answer: "<<result<<endl;
                }
            else if(s[1]=='-'){
                result=c.sub(xx,yy);
                cout<<"Answer: "<<result<<endl;
            }else if(s[1]=='*'){
                result=c.mul(xx,yy);
                cout<<"Answer: "<<result<<endl;
            }else if(s[1]=='%'){
                int(result)=c.mod(int(xx),int(yy));
                cout<<"Answer: "<<result<<endl;
            }else if(s[1]=='^'){
                result=c.poly(xx,int(yy));
                cout<<"Answer: "<<result<<endl;
            }else if(s[1]=='/'&&yy!=0){
                result=c.div(xx,yy);
                cout<<"Answer: "<<result<<endl;
            }
            else{
                cout<<"Operation Disallowed"<<endl;
				exit(0);
            }
        }
        else if((s[0]=='y'&&s[1]=='+'&&s[2]=='z')||(s[0]=='x'&&s[1]=='-'&&s[2]=='y')||(s[0]=='x'&&s[1]=='*'&&s[2]=='y')||(s[0]=='x'&&s[1]=='/'&&s[2]=='y')||(s[0]=='x'&&s[1]=='%'&&s[2]=='y')||(s[0]=='x'&&s[1]=='^'&&s[2]=='y')){

            if(s[1]=='+'){
                result=c.add(yy,zz);
                cout<<"Answer: "<<result<<endl;
                }
            else if(s[1]=='-'){
                result=c.sub(yy,zz);
                cout<<"Answer: "<<result<<endl;
            }else if(s[1]=='*'){
                result=c.mul(yy,zz);
                cout<<"Answer: "<<result<<endl;
            }else if(s[1]=='%'){
                int(result)=c.mod(int(yy),int(zz));
                cout<<"Answer: "<<result<<endl;
            }else if(s[1]=='^'){
                result=c.poly(yy,int(zz));
                cout<<"Answer: "<<result<<endl;
            }else if(s[1]=='/'&&zz!=0){
                result=c.div(yy,zz);
                cout<<"Answer: "<<result<<endl;
            }
            else{
                cout<<"Operation Disallowed"<<endl;
				exit(0);
            }
        }
        else if((s[0]=='y'&&s[1]=='+'&&s[2]=='x')||(s[0]=='y'&&s[1]=='-'&&s[2]=='x')||(s[0]=='y'&&s[1]=='*'&&s[2]=='x')||(s[0]=='y'&&s[1]=='/'&&s[2]=='x')||(s[0]=='y'&&s[1]=='%'&&s[2]=='x')||(s[0]=='y'&&s[1]=='^'&&s[2]=='x')){

            if(s[1]=='+'){
                result=c.add(yy,xx);
                cout<<"Answer: "<<result<<endl;
                }
            else if(s[1]=='-'){
                result=c.sub(yy,xx);
                cout<<"Answer: "<<result<<endl;
            }else if(s[1]=='*'){
                result=c.mul(yy,xx);
                cout<<"Answer: "<<result<<endl;
            }else if(s[1]=='%'){
               int(result)=c.mod(int(yy),int(xx));
                cout<<"Answer: "<<result<<endl;
            }else if(s[1]=='^'){
                result=c.poly(yy,int(xx));
                cout<<"Answer: "<<result<<endl;
            }else if(s[1]=='/'&&xx!=0){
                result=c.div(yy,xx);
                cout<<"Answer: "<<result<<endl;
            }
            else{
                cout<<"Operation Disallowed"<<endl;
				exit(0);
            }   
        }
        else if((s[0]=='x'&&s[1]=='+'&&s[2]=='z')||(s[0]=='x'&&s[1]=='-'&&s[2]=='z')||(s[0]=='x'&&s[1]=='*'&&s[2]=='z')||(s[0]=='x'&&s[1]=='/'&&s[2]=='z')||(s[0]=='x'&&s[1]=='%'&&s[2]=='z')||(s[0]=='x'&&s[1]=='^'&&s[2]=='z')){

            if(s[1]=='+'){
                result=c.add(xx,zz);
                cout<<"Answer: "<<result<<endl;
                }
            else if(s[1]=='-'){
                result=c.sub(xx,zz);
                cout<<"Answer: "<<result<<endl;
            }else if(s[1]=='*'){
                result=c.mul(xx,zz);
                cout<<"Answer: "<<result<<endl;
            }else if(s[1]=='%'){
               int(result)=c.mod(int(xx),int(zz));
                cout<<"Answer: "<<result<<endl;
            }else if(s[1]=='^'){
                result=c.poly(xx,int(zz));
                cout<<"Answer: "<<result<<endl;
            }else if(s[1]=='/'&&zz!=0){
                result=c.div(xx,zz);
                cout<<"Answer: "<<result<<endl;
            }
            else{
                cout<<"Operation Disallowed"<<endl;
				exit(0);
            }
        }
         else if((s[0]=='z'&&s[1]=='+'&&s[2]=='x')||(s[0]=='z'&&s[1]=='-'&&s[2]=='x')||(s[0]=='z'&&s[1]=='*'&&s[2]=='x')||(s[0]=='z'&&s[1]=='/'&&s[2]=='x')||(s[0]=='z'&&s[1]=='%'&&s[2]=='x')||(s[0]=='z'&&s[1]=='^'&&s[2]=='x')){

            if(s[1]=='+'){
                result=c.add(zz,xx);
                cout<<"Answer: "<<result<<endl;
                }
            else if(s[1]=='-'){
                result=c.sub(zz,xx);
                cout<<"Answer: "<<result<<endl;
            }else if(s[1]=='*'){
                result=c.mul(zz,xx);
                cout<<"Answer: "<<result<<endl;
            }else if(s[1]=='%'){
                int(result)=c.mod(int(zz),int(xx));
                cout<<"Answer: "<<result<<endl;
            }else if(s[1]=='^'){
                result=c.poly(zz,int(xx));
                cout<<"Answer: "<<result<<endl;
            }else if(s[1]=='/'&&xx!=0){
                result=c.div(zz,xx);
                cout<<"Answer: "<<result<<endl;
            }
            else{
                cout<<"Operation Disallowed"<<endl;
				exit(0);
            }
        }
        else if((s[0]=='z'&&s[1]=='+'&&s[2]=='y')||(s[0]=='z'&&s[1]=='-'&&s[2]=='y')||(s[0]=='z'&&s[1]=='*'&&s[2]=='y')||(s[0]=='z'&&s[1]=='/'&&s[2]=='y')||(s[0]=='z'&&s[1]=='%'&&s[2]=='y')||(s[0]=='z'&&s[1]=='^'&&s[2]=='y')){

            if(s[1]=='+'){
                result=c.add(zz,yy);
                cout<<"Answer: "<<result<<endl;
                }
            else if(s[1]=='-'){
                result=c.sub(zz,yy);
                cout<<"Answer: "<<result<<endl;
            }else if(s[1]=='*'){
                result=c.mul(zz,yy);
                cout<<"Answer: "<<result<<endl;
            }else if(s[1]=='%'){
               int(result)=c.mod(int(zz),int(yy));
                cout<<"Answer: "<<result<<endl;
            }else if(s[1]=='^'){
                result=c.poly(zz,int(yy));
                cout<<"Answer: "<<result<<endl;
            }else if(s[1]=='/'&&yy!=0){
                result=c.div(zz,yy);
                cout<<"Answer: "<<result<<endl;
            }
            else{
                cout<<"Operation Disallowed"<<endl;
				exit(0);
            } 
        }
        else if((s[j]=='x'&&s[j+1]=='+'&&counterX==1)||(s[j]=='x'&&s[j+1]=='-'&&counterX==1)||(s[j]=='x'&&s[j+1]=='*'&&counterX==1)||(s[j]=='x'&&s[j+1]=='/'&&counterX==1)||(s[j]=='x'&&s[j+1]=='%'&&counterX==1)||(s[j]=='x'&&s[j+1]=='^'&&counterX==1)){
         
            front=s.substr(0,i);
            back=s.substr(2,s.length());
            float p=stof(back);
		
            if(s[j+1]=='+'){
                result=c.add(xx,p);
                cout<<"Answer: "<<result<<endl;
                }
            else if(s[j+1]=='-'){
                result=c.sub(xx,p);
                cout<<"Answer: "<<result<<endl;
            }else if(s[j+1]=='*'){
                result=c.mul(xx,p);
                cout<<"Answer: "<<result<<endl;
            }else if(s[j+1]=='%'){
                int(result)=c.mod(int(xx),int(p));
                cout<<"Answer: "<<result<<endl;
            }else if(s[j+1]=='^'){
                result=c.poly(xx,int(p));
                cout<<"Answer: "<<result<<endl;
            }else if(s[j+1]=='/'&&p!=0){
                result=c.div(xx,p);
                cout<<"Answer: "<<result<<endl;
            }
            else{
              
			   cout<<"Operation Disallowed"<<endl;
				exit(0);
            }
        }
        else if((s[j]=='y'&&s[j+1]=='+'&&counterX==1)||(s[j]=='y'&&s[j+1]=='-'&&counterX==1)||(s[j]=='y'&&s[j+1]=='*'&&counterX==1)||(s[j]=='y'&&s[j+1]=='/'&&counterX==1)||(s[j]=='y'&&s[j+1]=='%'&&counterX==1)||(s[j]=='y'&&s[j+1]=='^'&&counterX==1)){
          
            front=s.substr(0,i);
            back=s.substr(2,s.length());
            float p=stof(back);
         
            if(s[2]=='+'){
                result=c.add(yy,p);
                cout<<"Answer: "<<result<<endl;
                }
            else if(s[2]=='-'){
                result=c.sub(yy,p);
                cout<<"Answer: "<<result<<endl;
            }else if(s[2]=='*'){
                result=c.mul(yy,p);
                cout<<"Answer: "<<result<<endl;
            }else if(s[2]=='%'){
               int(result)=c.mod(int(yy),int(p));
                cout<<"Answer: "<<result<<endl;
            }else if(s[2]=='^'){
               result=c.poly(yy,int(p));
                cout<<"Answer: "<<result<<endl;
            }else if(s[2]=='/'&&p!=0){
                result=c.div(yy,p);
                cout<<"Answer: "<<result<<endl;
            }
            else{
                cout<<"Operation Disallowed"<<endl;
				exit(0);
            }
        }
        else if((s[j]=='z'&&s[j+1]=='+'&&counterX==1)||(s[j]=='z'&&s[j+1]=='-'&&counterX==1)||(s[j]=='z'&&s[j+1]=='*'&&counterX==1)||(s[j]=='z'&&s[j+1]=='/'&&counterX==1)||(s[j]=='z'&&s[j+1]=='%'&&counterX==1)||(s[j]=='z'&&s[j+1]=='^'&&counterX==1)){
            front=s.substr(0,i);
            back=s.substr(2,s.length());
            float p=stof(back);

            if(s[2]=='+'){
                result=c.add(zz,p);
                cout<<"Answer: "<<result<<endl;
                }
            else if(s[2]=='-'){
                result=c.sub(zz,p);
                cout<<"Answer: "<<result<<endl;
            }else if(s[2]=='*'){
                result=c.mul(zz,p);
                cout<<"Answer: "<<result<<endl;
            }else if(s[2]=='%'){
                int(result)=c.mod(int(zz),int(p));
                cout<<"Answer: "<<result<<endl;
            }else if(s[2]=='^'){
                result=c.poly(zz,int(p));
                cout<<"Answer: "<<result<<endl;
            }else if(s[2]=='/'&&p!=0){
                result=c.div(zz,p);
                cout<<"Answer: "<<result<<endl;
            }
            else{
                cout<<"Operation Disallowed"<<endl;
				exit(0);
            }
        }
		else if(s=="quit" || s=="Quit"){
			exit(0);
		}
        else{     
		int l=s.length();
            for(i=0; i<l; i++){
        
                if(s[i]=='+' ||s[i]=='-' ||s[i]=='*' ||s[i]=='/' ||s[i]=='%' ||s[i]=='^'){
                  
                    a=s[i];
                    float x=stod(s.substr(0,i));
                    float y=stod(s.substr(i+1, s.length()));
                    if((x<0||x>255) && (y<0||y>255)){
                        cout<<"Input out of range"<<endl;
                    }
                    else{
                    if(s[i]=='+'){
                        result=c.add(x,y);
                        cout<<"Answer: "<<result<<endl;
                    }
                    else if(s[i]=='-'){
                        result=c.sub(x,y);
                        cout<<"Answer: "<<result<<endl;
                    }else if(s[i]=='*'){
                        result=c.mul(x,y);
                        cout<<"Answer: "<<result<<endl;
                    }else if(s[i]=='%'){
                        int(result)=c.mod(int(x),int(y));
                        cout<<"Answer: "<<result<<endl;
                    }else if(s[i]=='^'){
                        result=c.poly(x,int(y));
                        cout<<"Answer: "<<result<<endl;
                    }else if(s[i]=='/'&&y!=0){
                        result=c.div(x,y);
                        cout<<"Answer: "<<result<<endl;
                    }
                    else{
                        cout<<"Operation Disallowed"<<endl;
						exit(0);
                    }
                }
            }
                else if((s[i]=='x'&&s[++i]=='=')||(s[i]=='y'&&s[++i]=='=')||(s[i]=='z'&&s[++i]=='=')){
                    
                        front=s.substr(0, i);
                        back=s.substr(i+1,s.length());
                        float p=stof(back);
                            
                        if(p<0||p>255){
                            cout<<"Input out of range";
                        }
                        else{
                        if(front.compare("x")==0){
                            xx=stof(back);
                            counterX=1;
                        }
                        else if(front.compare("y")==0){
                            yy=stof(back);
                            counterY=1;
                        }
                        else if(front.compare("z")==0){
                            zz=stof(back);
                            counterZ=1;
                        }
                    }
                }
				else if(s=="quit" || s=="Quit"){
					exit(0);
				}
                else if(s[i]=='a'||s[i]=='b'||s[i]=='c'||s[i]=='d'||s[i]=='e'||s[i]=='f'||s[i]=='g'||s[i]=='h'||s[i]=='i'||s[i]=='j'||s[i]=='k'||s[i]=='l'||
                     s[i]=='m'||s[i]=='n'||s[i]=='o'||s[i]=='p'||s[i]=='q'||s[i]=='r'||s[i]=='s'||s[i]=='t'||s[i]=='u'||s[i]=='v'||s[i]=='w'){
                    cout<<"Invalid Input"<<endl;
					exit(0);
                }
            }
        }
    }
}
