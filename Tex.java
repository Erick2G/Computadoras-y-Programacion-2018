package unam.mx;

import com.badlogic.gdx.Gdx;
import com.badlogic.gdx.Screen;
import com.badlogic.gdx.graphics.GL20;
import com.badlogic.gdx.graphics.OrthographicCamera;
import com.badlogic.gdx.graphics.Texture;
import com.badlogic.gdx.graphics.g2d.Sprite;
import com.badlogic.gdx.graphics.g2d.SpriteBatch;
import com.badlogic.gdx.physics.box2d.Box2DDebugRenderer;
import com.badlogic.gdx.physics.box2d.World;
import com.badlogic.gdx.utils.Disposable;

import static unam.mx.DGame.ppm;

public class Tex implements Disposable {
//Textures, images, etc
    private SpriteBatch batch;
    private Texture background;
    public Texture ship;
    public Texture cube;
    public Texture cube2;


    public Sprite shipSprite;
    public Sprite cubeSprite;
    public Sprite cube2sSprite;


//Ship rotation
    public float rotation = 0;
//Constructor
    public Tex(SpriteBatch batch){
        this.batch=batch;
        background = new Texture("fondo1.png");
        ship = new Texture("ship.png");
        shipSprite = new Sprite(ship ,60,80);
        cube = new Texture("cubo.png");
        cubeSprite = new Sprite(cube ,0 ,0 ,50,50);
        cube2 = new Texture("cubo2.png");
        cube2sSprite = new Sprite(cube2 ,0 ,0 ,50 ,50);

     //First positions
        cubeSprite.setPosition(854/ppm,640/ppm);
        cube2sSprite.setPosition(170.8f,640/ppm);
     //New Sizes (so it makes sense for world box xD)
        shipSprite.setSize(8,10);//changed
        cubeSprite.setSize(5.5f,5.5f);
        cube2sSprite.setSize(5.5f,5.5f);
    }
    public void renderer(){
        batch.draw(background,0/ppm,0/ppm,2560/ppm,1920/ppm);
        shipSprite.draw(batch);
        cubeSprite.draw(batch);
        cube2sSprite.draw(batch);
    }

    @Override
    public void dispose() {
        background.dispose();
        ship.dispose();
        cube.dispose();
        cube2.dispose();

    }
}
