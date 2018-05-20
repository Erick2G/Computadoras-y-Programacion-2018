package unam.mx;

import com.badlogic.gdx.Gdx;
import com.badlogic.gdx.Input;
import com.badlogic.gdx.Screen;
import com.badlogic.gdx.graphics.GL20;
import com.badlogic.gdx.graphics.OrthographicCamera;
import com.badlogic.gdx.graphics.Texture;
import com.badlogic.gdx.graphics.g2d.Sprite;
import com.badlogic.gdx.math.Vector2;
import com.badlogic.gdx.physics.box2d.Box2DDebugRenderer;
import com.badlogic.gdx.physics.box2d.World;

import static unam.mx.DGame.ppm;


public class PlayScreen implements Screen {
    private DGame game;
//Camera
    private OrthographicCamera camera;
//From other classes
    private Stages stages;
    private Tex tex;
    private WorldBox worldBox;
//Constructor
    public PlayScreen(DGame game){
        this.game = game;
    //Camera
        camera= new OrthographicCamera(832/ppm,624/ppm);
        camera.position.set(DGame.screenX/ppm,DGame.screenY/ppm,0);  // 8
    //From other classes
        stages = new Stages(game.batch);
        tex = new Tex(game.batch);
        worldBox = new WorldBox();//game.batch
    }
    @Override
    public void show() {

    }

    @Override
    public void render(float delta){
        Movements(delta);
        camera.update();
        Gdx.gl.glClear(GL20.GL_COLOR_BUFFER_BIT);
        game.batch.setProjectionMatrix(camera.combined);
        worldBox.asteroidsEjecution(delta);
        game.batch.begin();
        tex.renderer();
        game.batch.end();
        stages.stage.draw();
        worldBox.renderer(camera,delta);
    }

    public void Movements(float dt){

        boolean derecha = Gdx.input.isKeyPressed(Input.Keys.D)
                ||Gdx.input.isKeyPressed(Input.Keys.RIGHT);
        boolean izquierda = Gdx.input.isKeyPressed(Input.Keys.A)
                ||Gdx.input.isKeyPressed(Input.Keys.LEFT);
        boolean arriba = Gdx.input.isKeyPressed(Input.Keys.W)
                ||Gdx.input.isKeyPressed(Input.Keys.UP);
        boolean abajo = Gdx.input.isKeyPressed(Input.Keys.S)
                ||Gdx.input.isKeyPressed(Input.Keys.DOWN);

        if(tex.rotation>360||tex.rotation<-360)tex.rotation=0;
        if(derecha){
            tex.rotation-=2;
            if(worldBox.bodyS.getLinearVelocity().x<0)worldBox.bodyS.applyLinearImpulse(new Vector2(1,0)
                    ,worldBox.bodyS.getWorldCenter(),true);
            if(worldBox.bodyS.getLinearVelocity().x>0)worldBox.bodyS.applyLinearImpulse(new Vector2(-1,0)
                    ,worldBox.bodyS.getWorldCenter(),true);
            if(worldBox.bodyS.getLinearVelocity().y<0)worldBox.bodyS.applyLinearImpulse(new Vector2(0,1)
                    ,worldBox.bodyS.getWorldCenter(),true);
            if(worldBox.bodyS.getLinearVelocity().y>0)worldBox.bodyS.applyLinearImpulse(new Vector2(0,-1)
                    ,worldBox.bodyS.getWorldCenter(),true);
        }
        if(izquierda){
            tex.rotation+=2;
            if(worldBox.bodyS.getLinearVelocity().x<0)worldBox.bodyS.applyLinearImpulse(new Vector2(1,0)
                    ,worldBox.bodyS.getWorldCenter(),true);
            if(worldBox.bodyS.getLinearVelocity().x>0)worldBox.bodyS.applyLinearImpulse(new Vector2(-1,0)
                    ,worldBox.bodyS.getWorldCenter(),true);
            if(worldBox.bodyS.getLinearVelocity().y<0)worldBox.bodyS.applyLinearImpulse(new Vector2(0,1)
                    ,worldBox.bodyS.getWorldCenter(),true);
            if(worldBox.bodyS.getLinearVelocity().y>0)worldBox.bodyS.applyLinearImpulse(new Vector2(0,-1)
                    ,worldBox.bodyS.getWorldCenter(),true);
        }
    // First positive = first negative
        if((tex.rotation>=0&&tex.rotation<=90)^(tex.rotation<0&&tex.rotation>-90)){
            if(arriba){
                worldBox.bodyS.applyLinearImpulse(new Vector2(tex.rotation*(-1/50f),1/2f)//(109/3125)
                        ,worldBox.bodyS.getWorldCenter(),true);
            }
            if(abajo){
                worldBox.bodyS.applyLinearImpulse(new Vector2(tex.rotation*(1/60f),-1/2f)
                        ,worldBox.bodyS.getWorldCenter(),true);
            }
        }
     //Second positive
        if((tex.rotation>90&&tex.rotation<180)^(tex.rotation<-90&&tex.rotation>-180)){
            if(abajo){
                worldBox.bodyS.applyLinearImpulse(new Vector2(55f/tex.rotation,1/2f)//(109/3125)
                        ,worldBox.bodyS.getWorldCenter(),true);
            }
            if(arriba){
                worldBox.bodyS.applyLinearImpulse(new Vector2(-55f/tex.rotation,-1/2f)
                        ,worldBox.bodyS.getWorldCenter(),true);
            }
        }
     // Third one, positive
        if((tex.rotation>180&&tex.rotation<270)^(tex.rotation<-180&&tex.rotation>-270)){
            if(abajo){
                worldBox.bodyS.applyLinearImpulse(new Vector2(tex.rotation*(-1/300f),1/2f)//(109/3125)
                        ,worldBox.bodyS.getWorldCenter(),true);
            }
            if(arriba){
                worldBox.bodyS.applyLinearImpulse(new Vector2(tex.rotation*(1/340f),-1/2f)
                        ,worldBox.bodyS.getWorldCenter(),true);
            }
        }
    //Forth one positive
        if((tex.rotation>270&&tex.rotation<360)^(tex.rotation<-270&&tex.rotation>-360)){
            if(arriba){
                worldBox.bodyS.applyLinearImpulse(new Vector2(tex.rotation*(1/400f),1/2f)//(109/3125)
                        ,worldBox.bodyS.getWorldCenter(),true);
            }
            if(abajo){
                worldBox.bodyS.applyLinearImpulse(new Vector2(tex.rotation*(-1/460f),-1/2f)
                        ,worldBox.bodyS.getWorldCenter(),true);
            }
        }

    //Updates, new chordates, angle
        camera.position.x=worldBox.bodyS.getPosition().x;
        camera.position.y=worldBox.bodyS.getPosition().y;
        worldBox.world.step(1/90f,4,1);
        //Ship rotation
        tex.shipSprite.setOrigin(tex.shipSprite.getWidth()/2,tex.shipSprite.getHeight()/2);
        //tex.shipSprite.rotate(tex.rotation);     This way works as an impulse
        tex.shipSprite.setRotation(tex.rotation);
        tex.shipSprite.setPosition( worldBox.bodyS.getWorldCenter().x-39/ppm,
                                    worldBox.bodyS.getWorldCenter().y-49/ppm);


    }

    @Override
    public void resize(int width ,int height) {

    }

    @Override
    public void pause() {

    }

    @Override
    public void resume() {

    }

    @Override
    public void hide() {

    }

    @Override
    public void dispose(){
        game.batch.dispose();

    }
}
