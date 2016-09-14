/**
*** source for freenect2 eventlistener ***

Copyright 2016, Daniel Obermaier

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.
This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.
You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.

@Author Daniel Obermaier
*/

//include own headers first
#include "eventlistener.hpp"

#include <pcl/visualization/pcl_visualizer.h>

#include <iostream>
#include <string.h>


void f2g::eventlistener::KeyboardInputEvent(char arg){
    switch (arg){
        case 27:
            closeKinectGrabber();
            std::cout<<"Escape KeyEvent called, try to close program... "<<std::endl;
            break;
        case 'x':
            std::cout<<"keyboard Event on X called"<<std::endl;
            std::cout<<"no function implemented on key 'x'"<< std::endl;
            break;
    }
}


void f2g::eventlistener::closeKinectGrabber(void){
    cv::destroyAllWindows();
    std::cout<<"OpenCV Window destroyed"<<std::endl;
    //TODO: free usb slot
}

void f2g::eventlistener::cvWindowCallback(int event, int x, int y, int flags, void *username){

}

void f2g::eventlistener::cvMouseCallback(int event, int x, int y, int flags, void *username){

}


void f2g::eventlistener::pclKeyboardEvent(const pcl::visualization::KeyboardEvent &event, void *vwr){
    std::cout<<"Keyboard event called"<<std::endl;
    std::cout<<event.getKeySym()<<" pressed"<<std::endl;

    //hack to get a static viewer
    pcl::visualization::PCLVisualizer *view = static_cast<pcl::visualization::PCLVisualizer *>(vwr);

    if (event.getKeySym() == "Escape" && event.keyDown()){
        //try to close pclviewer window
        std::cout<<"ESC pressed"<<std::endl;
        std::cout<<"exiting pcl viewer"<<std::endl;
        view->close();
    }
    if (event.getKeySym() == "c" && event.keyDown() && event.isCtrlPressed()){
        //close on ctrl+c as well
         std::cout<<"ctrl+c pressed... "<<std::endl;
         std::cout<<"exiting pcl viewer"<<std::endl;
         view->close();
    }



}

void f2g::eventlistener::pclMouseEvent(const pcl::visualization::MouseEvent &event, void *vwr){
    std::cout<<"Mouse event called"<<std::endl;
}


void f2g::eventlistener::QTButtonClickedEvent(){
    std::cout<<"qt button event called" <<std::endl;
}
