package unam.mx;

import com.badlogic.gdx.graphics.Texture;
import com.badlogic.gdx.graphics.g2d.Sprite;
import com.badlogic.gdx.utils.Disposable;

public class AsteroidTex implements Disposable {
    public Texture asteroid1;
    public Texture asteroid2;
    public Texture greenAsteroid;
    public Sprite texAsArray[]= new Sprite[15];

    public AsteroidTex(){
        asteroid1=new Texture("asteroid.png");
        asteroid2=new Texture("asteroid2.png");
        greenAsteroid=new Texture("green_asteroid.png");

        for(int i=0;i<=7;i++){
            texAsArray[i]= new Sprite(asteroid1,50,60);
            texAsArray[i].setSize(5.5f,5.5f);
        }
        for(int i=8;i<15;i++){
            texAsArray[i]= new Sprite(asteroid2,60,60);
            texAsArray[i].setSize(5.5f,5.5f);
        }
    }


    @Override
    public void dispose() {
        asteroid1.dispose();
        asteroid2.dispose();
        greenAsteroid.dispose();
    }
}
