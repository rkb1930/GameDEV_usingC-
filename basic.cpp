#include<SFML/Graphics.hpp>
using namespace sf;

int main(){
	VideoMode vm(960,540);
	RenderWindow window(vm,"OUR FIRST GAME");
	
	Texture texture;
	texture.loadFromFile("tim.jpeg");
	
	Sprite player;
	player.setTexture(texture);
		
	
	//center image
	float spriteWidth = player.getGlobalBounds().width;
	float spriteHeight = player.getGlobalBounds().height;
	player.setPosition(480-(spriteWidth/2),275-(spriteHeight/2));
	
	//move 
	player.move(0,0);
	
	//scaling object
	player.setScale(0.2f,0.2f);
	
	//rotating an object
	player.setRotation(45);
	
	
	
	while(window.isOpen()){
		Event event ;
		while(window.pollEvent(event)){
			if(event.type==Event::Closed){
				window.close();
			
			}
		}
		if(Keyboard::isKeyPressed(Keyboard::Right)){
		player.move(10,0);
		}
		window.clear();
		window.draw(player);
		window.display();
	}
}
