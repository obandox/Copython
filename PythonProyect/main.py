
import cocos2d
import helloworld
from cocos2d import director
from cocos2d import EGLView
from cocos2d import fileUtils
import helloworld


class AppDelegate(cocos2d.Application):
    def initInstance(self):
        """la configuracion es automatica sin embargo este metodo 
        sigue siendo quien decide si la applicacion levanta o no """
        print "iniciado el AppDelegate!! "
        return True
    def applicationDidFinishLaunching(self):
        director.setDisplayFPS(True);
        director.setAnimationInterval(1.0 / 60);
        #default scene
        director.runWithScene()#helloworld.scene());
        return True
        
def main():
    point = AppDelegate()
    point.run()
    
