#include<SFML/Graphics.hpp>
#include <iostream>
#include <>
using namespace sf;

int main(){
  VideoMode vm(960,540);
  
  RenderWindow window(vm,"Timber Man");
  
  View view(FloatRect(0,0,1920,1080));
  window.setView(view);
  
  Texture textureBackground;
  textureBackground.loadFromFile("graphics/background.png");
  Sprite spriteBackground;
  spriteBackground.setTexture(textureBackground);
  spriteBackground.setPosition(0,0);
  
    
  Texture textureCloud1;
  textureCloud1.loadFromFile("graphics/cloud.png");
  Sprite spriteCloud1;
  spriteCloud1.setTexture(textureCloud1);
  spriteCloud1.setPosition(10,10);
  
  Texture textureCloud2;
  textureCloud2.loadFromFile("graphics/cloud.png");
  Sprite spriteCloud2;
  spriteCloud2.setTexture(textureCloud2);
  spriteCloud2.setPosition(10,150);
  
  Texture textureCloud3;
  textureCloud3.loadFromFile("graphics/cloud.png");
  Sprite spriteCloud3;
  spriteCloud3.setTexture(textureCloud3);
  spriteCloud3.setPosition(10,300);
  spriteCloud3.setScale(0.5f,0.5f);
  
  Texture textureTree;
  textureTree.loadFromFile("graphics/tree.png");
  Sprite spriteTree;
  spriteTree.setTexture(textureTree);
  spriteTree.setPosition(810,0);
  
  
  Texture textureBee;
  textureBee.loadFromFile("graphics/bee.png");
  Sprite spriteBee;
  spriteBee.setTexture(textureBee);
  spriteBee.setPosition(40,700);
  
  RectangleShape timeBar;
  float timeBarStartWidth=350;
  float timeBarHeight=80;
  
  timeBar.setSize(Vector2f(timeBarStartWidth,timeBarHeight));
  timeBar.setFillColor(Color::Red);
  timeBar.setPosition(960-timeBarStartWidth/2,960);
  
  bool beeActive = false;
  float beeSpeed=0.0f;
  
  bool cloud1Active = false;
  float cloud1Speed=0.0f;
  
  bool cloud2Active = false;
  float cloud2Speed=0.0f;
  
  bool cloud3Active = false;
  float cloud3Speed=0.0f;
  
  Time gameTimeTotal;
  float timeRemaining=6.0f;
  float timeBarWidthPerSecond=timeBarStartWidth/timeRemaining;
  bool paused=true;
  int score =0;
  
  Text messageText,scoreText;
  Font font;
  font.loadFromFile("fonts/KOMIKAP_.ttf");
  messageText.setFont(font);
  scoreText.setFont(font);
  
  messageText.setString("press Enter to Start!!");
  scoreText.setString("Score =");
  
  
  messageText.setCharacterSize(75);
  scoreText.setCharacterSize(100);
  
  messageText.setFillColor(Color::White);
  scoreText.setFillColor(Color::White);
  
  FloatRect textRect = messageText.getLocalBounds();
  messageText.setOrigin(textRect.left + textRect.width/2.0f,textRect.top+textRect.height/2.0f);
  
  FloatRect scoreRect = scoreText.getLocalBounds();
  
   
  messageText.setPosition(960,540);
  scoreText.setPosition(0,0);
  
  Clock clock;
  
  while(window.isOpen()){
  
    if(Keyboard :: isKeyPressed(Keyboard::Escape)){
      window.close();
    }
    Time dt = clock.restart();
    
    
    
    if(Keyboard::isKeyPressed(Keyboard::Return)){
	paused=false;
	score=0;
	timeRemaining=6;
	
    }
	
	if(!paused){
	
	timeRemaining-=dt.asSeconds();
	timeBar.setSize(Vector2f(timeBarWidthPerSecond*timeRemaining,timeBarHeight));
	   if(timeRemaining<=0.0f){
		paused=true;
	
	   }
	   if(Keyboard :: isKeyPressed(Keyboard::Right)){
     		
    	   }
	   
	   if(!beeActive){
       srand((int)time(0));
       
       beeSpeed = (rand() % 200 )+200;
       
       float height=(rand()% 500)+400;
       
       spriteBee.setPosition(2000,height);
       
       beeActive=true;
       
    }
    else{
      spriteBee.setPosition(spriteBee.getPosition().x-(beeSpeed*dt.asSeconds()),spriteBee.getPosition().y);
      if(spriteBee.getPosition().x<0){
        beeActive=false;
      }
    }
    
    if(!cloud1Active){
       srand((int)time(0));
       
       cloud1Speed = (rand() % 100 )+110;
       
       float height=(rand()% 10)+20;
       
       spriteCloud1.setPosition(-100,height);
       
       cloud1Active=true;
       
    }
    else{
      spriteCloud1.setPosition(spriteCloud1.getPosition().x+(cloud1Speed*dt.asSeconds()),spriteCloud1.getPosition().y);
      if(spriteCloud1.getPosition().x>1920){
        cloud1Active=false;
      }
    }
    
    if(!cloud2Active){
       srand((int)time(0));
       
       cloud2Speed = (rand() % 150 )+160;
       
       float height=(rand()% 80)+90;
       
       spriteCloud2.setPosition(-100,height);
       
       cloud2Active=true;
       
    }
    else{
      spriteCloud2.setPosition(spriteCloud2.getPosition().x+(cloud2Speed*dt.asSeconds()),spriteCloud2.getPosition().y);
      if(spriteCloud2.getPosition().x>1920){
        cloud2Active=false;
      }
    }
    
    if(!cloud3Active){
       srand((int)time(0));
       
       cloud3Speed = (rand() % 200 )+210;
       
       float height=(rand()% 150)+160;
       
       spriteCloud3.setPosition(-100,height);
       
       cloud3Active=true;
       
    }
    else{
      spriteCloud3.setPosition(spriteCloud3.getPosition().x+(cloud3Speed*dt.asSeconds()),spriteCloud3.getPosition().y);
      if(spriteCloud3.getPosition().x>1920){
        cloud3Active=false;
      }
    }
     std::stringstream ss;
      ss<<"Score="<<score;
      scoreText.setString(ss.str());
    
	   
	}
    //end of paused
    
    Event event;
    while(window.pollEvent(event)){
      if(event.type==Event::Closed){
        window.close();
      }
     
    }
    window.clear();
    window.draw(spriteBackground);
    window.draw(spriteCloud1);
    window.draw(spriteCloud2);
    window.draw(spriteCloud3);
    window.draw(spriteTree);
    window.draw(spriteBee);
    //window.draw(spriteDog);
    window.draw(timeBar);
    if (paused)
    window.draw(messageText);
    window.draw(scoreText);
    window.display();
  }
  return 0;
}
