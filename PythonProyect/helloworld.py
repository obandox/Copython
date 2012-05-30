'''
Created on 29/05/2012

@author: miguel
from cocos2d import scene
from cocos2d import Default
from cocos2d import MenuItemImage
from cocos2d import menu
import sys

def scene():    
    scene = scene.node()    
    layer = Helloworld.node()
    scene.addChild(layer)
    return scene;

class Helloworld(Default):
    def menuCloseCallback(self):
        print "close!!"
        sys.exit(0)
        
    def init(self):
        self.layerinit();
        closeItem = menu.menuItemImage( "CloseNormal.png", "CloseSelected.png", self, self.menuCloseCallback );        
        closeItem.setPosition( 200 ,20 );
        menu = menu.withItems(closeItem);        
        menu.setPosition( 0,0 );
        self.addChild(menu, 1);

'''