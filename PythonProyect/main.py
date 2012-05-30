
import cocos2d
import helloworld
from cocos2d import Director
from cocos2d import EGLView
from cocos2d import fileUtils



class AppDelegate(cocos2d.Application):
    
    def initInstance(self):
        mainWnd = EGLView();
        mainWnd.Create(1024, 600);        
        fileUtils.setResourcePath("app/native/Resources");
        
    def applicationDidFinishLaunching(self):
        director = cocos2d.director.shared()
    
        director.setOpenGLView(EGLView.sharedOpenGLView())
    
        # enable High Resource Mode(2x, such as iphone4) and maintains low resource on other devices.
        # pDirector->enableRetinaDisplay(true);
    
        # turn on display FPS
        director.setDisplayFPS(True)
    
        # pDirector->setDeviceOrientation(kCCDeviceOrientationLandscapeLeft);
    
        # set FPS. the default value is 1.0/60 if you don't call this
        director.setAnimationInterval(1.0 / 60)
    
        # create a scene. it's an autorelease object
        #scene = helloworld.scene()
    
        # run
        #director.runWithScene(scene)

    def applicationDidEnterBackground(self):
        cocos2d.director.shared().pause();

    def applicationWillEnterForeground(self):
        cocos2d.director.shared().resume();

def main():
    point = AppDelegate()
    point.run()
    
