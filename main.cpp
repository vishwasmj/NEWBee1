#include <iostream>
#include <string>
#include <opencv2/imgproc.hpp>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include "Action.hpp"
#include "Resize.hpp"
#include "Erosion.hpp"
#include "Lighten.hpp"
#include "Darken.hpp"
#include "Panaroma.hpp"
#include "Dilation.hpp"

using namespace std;
using namespace cv;




 
const String keys =
    "{help  ?        |      | print this message   }"
    "{@image         |<none>| image to resize      }"
    "{@output        |<none>| output resized image }"
    "{w width        |<none>| width size           }"
    "{h height       |<none>| height size          }"
;


int main(int argc, const char** argv )
{
 int ch;
 do
 {
  int choice;
  cout<<"-----------------------NEW BEE----------------------------"<<endl;
  cout<<"-------------MENU---------------"<<endl;
  cout<<"1.Resize"<<endl;
  cout<<"2.Erosion"<<endl;
  cout<<"3.Dilation"<<endl;
  cout<<"4.Lighten"<<endl;
  cout<<"5.Darken"<<endl;
  cout<<"6.Panorama/Stitching"<<endl;
  cout<<"7.Help/Description"<<endl;
  cout<<"Enter your choice"<<endl;
  cin>>choice;
  Action * ptr;
  //Enter your choice
  switch(choice) {
      case 1 :
         cout << "Resize" << endl; 
         ptr=new Resize();
         break;
      case 2 :
         cout << "Erosion" << endl; 
	 ptr=new Erosion();
         break;
      case 3 :
         cout << "Dilation" << endl; 
	 ptr=new Dilation();
         break;
      case 4 :
         cout << "Lighten" << endl; 
	 ptr=new Lighten();
         break;
      case 5 :
         cout << "Dareken" << endl; 
	 ptr=new Darken();
         break;
      case 6 :
         cout << "Panaroma/Stiching" << endl; 
	 ptr=new Panaroma();
         break;
      case 7 :
         cout << "Help/Description\n" << endl;
	 ptr=new help_description();
         break;  
      default :
        cout << "Invalid Option Try again........\n" << endl;
     }
	ptr->run();
        cout<<endl;

        cout<<"DO YOU WANT TO CONTINUE :: press (1)";
        cin>>ch;
    }while(ch == 1);
 cout<<"exit the main class"<<endl;

}

