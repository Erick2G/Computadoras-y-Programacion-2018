package unam.mx;

import com.badlogic.gdx.graphics.OrthographicCamera;
import com.badlogic.gdx.graphics.g2d.SpriteBatch;
import com.badlogic.gdx.math.Vector2;
import com.badlogic.gdx.physics.box2d.*;
import com.badlogic.gdx.utils.Disposable;

import java.util.Random;

import static unam.mx.DGame.ppm;

//Only bodies for physic world
public class WorldBox implements Disposable {
    private SpriteBatch batch;
    public World world;
    private Box2DDebugRenderer b2dr;
//Bodies
    public Body body;
    public Body bodyCubo;
    public Body bodyFloor;
    public Body bodyS;
    public Body bodyLeft;
    public Body bodyRight;
    public Body bodyTop;
//Asteroids array
    private AllAsteroids asteroidsArray[]= new AllAsteroids[15];

    public WorldBox(){    //SpriteBatch batch this.batch=batch;
        world = new World(new Vector2(0/ppm,0/ppm),true);    //Changed
              //Vector 2 : gravity
        b2dr = new Box2DDebugRenderer();
        firstCube();
        secondCube();
        boxBoundaries();
        circleShip();
        //asteroidsEjecution();
    }

    public void firstCube(){
        BodyDef bdef = new BodyDef();
        PolygonShape shape = new PolygonShape();
        FixtureDef fdef  = new FixtureDef();
        bdef.type = BodyDef.BodyType.StaticBody;
        bdef.position.set((854+25)/ppm,(640+25)/ppm);
        body= world.createBody(bdef);
        shape.setAsBox(25/ppm,25/ppm);
        fdef.shape = shape;
        body.createFixture(fdef);
        shape.dispose();
    }
    public void secondCube(){
        BodyDef bdefCubo = new BodyDef();
        PolygonShape shape2 = new PolygonShape();
        FixtureDef fdefCubo = new FixtureDef();
        bdefCubo.type = BodyDef.BodyType.StaticBody;
        bdefCubo.position.set((1708+25)/ppm,(640+25)/ppm);
        bodyCubo= world.createBody(bdefCubo);
        shape2.setAsBox(25/ppm,25/ppm);
        fdefCubo.shape = shape2;
        bodyCubo.createFixture(fdefCubo);
        shape2.dispose();
    }
    public void boxBoundaries(){
     //Floor
        BodyDef bdefFloor = new BodyDef();
        PolygonShape shapeFloor = new PolygonShape();
        FixtureDef fdefFloor = new FixtureDef();
        bdefFloor.type = BodyDef.BodyType.StaticBody;
        bdefFloor.position.set(1265/ppm,1/ppm);
        bodyFloor= world.createBody(bdefFloor);
        shapeFloor.setAsBox(1290/ppm,1/ppm);
        fdefFloor.shape = shapeFloor;
        bodyFloor.createFixture(fdefFloor);
     // Left wall
        BodyDef bdefLeft = new BodyDef();
        PolygonShape shapeLeft = new PolygonShape();
        FixtureDef fdefLeft = new FixtureDef();
        bdefLeft.type = BodyDef.BodyType.StaticBody;
        bdefLeft.position.set(1/ppm,1265/ppm);
        bodyLeft= world.createBody(bdefLeft);
        shapeLeft.setAsBox(1/ppm,1265/ppm);
        fdefLeft.shape = shapeLeft;
        bodyLeft.createFixture(fdefLeft);
    //Right wall
        BodyDef bdefRight = new BodyDef();
        PolygonShape shapeRight = new PolygonShape();
        FixtureDef fdefRight = new FixtureDef();
        bdefRight.type = BodyDef.BodyType.StaticBody;
        bdefRight.position.set(2560/ppm,1265/ppm);
        bodyRight= world.createBody(bdefRight);
        shapeRight.setAsBox(1/ppm,1265/ppm);
        fdefRight.shape = shapeRight;
        bodyRight.createFixture(fdefRight);
     //Top
        BodyDef bdefTop = new BodyDef();
        PolygonShape shapeTop = new PolygonShape();
        FixtureDef fdefTop = new FixtureDef();
        bdefTop.type = BodyDef.BodyType.StaticBody;
        bdefTop.position.set(1265/ppm,1920/ppm);
        bodyTop= world.createBody(bdefTop);
        shapeTop.setAsBox(1290/ppm,1/ppm);
        fdefTop.shape = shapeTop;
        bodyTop.createFixture(fdefTop);

        shapeFloor.dispose();
        shapeLeft.dispose();
        shapeRight.dispose();
        shapeTop.dispose();
    }
    public void circleShip(){
        BodyDef bdefShip;
        bdefShip = new BodyDef();
        CircleShape shapeS = new CircleShape();
        shapeS.setRadius(28/ppm);
        FixtureDef fdefShip = new FixtureDef();
        bdefShip.type = BodyDef.BodyType.DynamicBody;
        bdefShip.position.set(1400/ppm,260/ppm);
        bodyS = world.createBody(bdefShip);
        fdefShip.shape = shapeS;
        bodyS.createFixture(fdefShip);
        shapeS.dispose();
    }

//Asteroids arrays
    public void asteroidsEjecution(float delta){
        Random r = new Random();
        int x, y, radius,sector;
        float velX,velY;
        for(int i=0;i<15;i++){
            x=0;
            y=0;
            sector=0;
            radius=0;
            velX=0;
            velY=0;
            sector=r.nextInt(4);
            radius= r.nextInt(30);
            switch (sector){
                case 0: x=0;
                        y=r.nextInt(1920);
                        if(y>960){  //Third Quadrant
                            velX=r.nextInt(91)+180;//tex.rotation*(-1/300f),1/2f
                            velY=-1.5f;
                            asteroidsArray[i]=new AllAsteroids(world,x,y,radius);
                            asteroidsArray[i].body.setLinearVelocity(velX*(1/300f),velY);
                        }else{  //As forth quadrant
                            velX=r.nextInt(91)+270;  //tex.rotation*(1/400f),1/2f
                            velY=1/2;
                            asteroidsArray[i]=new AllAsteroids(world,x,y,radius);
                            asteroidsArray[i].body.setLinearVelocity(velX*(1/400f),velY);
                        }
                        break;
                case 1: x=2560;
                        y=r.nextInt(1920);
                        if(y>960){  //Second quadrant
                            velX=r.nextInt(91)+90;//-55f/tex.rotation,-1/2f
                            velY=-1.5f;
                            asteroidsArray[i]=new AllAsteroids(world,x,y,radius);
                            asteroidsArray[i].body.setLinearVelocity(-55f/velX,velY);
                        }else{  //As first quadrant
                            velX=r.nextInt(91);  //tex.rotation*(-1/50f),1/2f
                            velY=1;
                            asteroidsArray[i]=new AllAsteroids(world,x,y,radius);
                            asteroidsArray[i].body.setLinearVelocity(velX*(-1/50f),velY);
                        }
                        break;
                case 2: y=0;
                        x=r.nextInt(2560);
                        if(x<1280){// Forth quadrant
                            velX=r.nextInt(91)+270;  //tex.rotation*(1/400f),1/2f
                            velY=1.5f;
                            asteroidsArray[i]=new AllAsteroids(world,x,y,radius);
                            asteroidsArray[i].body.setLinearVelocity(velX*(1/400f),velY);
                        }else{ //First quadrant
                            velX=r.nextInt(91);  //tex.rotation*(-1/50f),1/2f
                            velY=1.5f;
                            asteroidsArray[i]=new AllAsteroids(world,x,y,radius);
                            asteroidsArray[i].body.setLinearVelocity(velX*(-1/50f),velY);
                        }
                        break;
                case 3: y=1920;
                        x=r.nextInt(2560);
                        if(x<1280){// Third quadrant
                            velX=r.nextInt(91)+180;//tex.rotation*(-1/300f),1/2f
                            velY=-1f;
                            asteroidsArray[i]=new AllAsteroids(world,x,y,radius);
                            asteroidsArray[i].body.setLinearVelocity(velX*(1/300f),velY);
                        }else{
                            velX=r.nextInt(91)+90;//-55f/tex.rotation,-1/2f
                            velY=-1f;
                            asteroidsArray[i]=new AllAsteroids(world,x,y,radius);
                            asteroidsArray[i].body.setLinearVelocity(-55f/velX,velY);
                        }
                        break;
            }


        }

    }
    public void renderer(OrthographicCamera newcamera, float delta){
        //After batch.end, shows the images
        b2dr.render(world, newcamera.combined);

    }

    @Override
    public void dispose(){
        world.dispose();

    }
}

