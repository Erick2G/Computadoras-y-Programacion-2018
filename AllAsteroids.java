package unam.mx;

import com.badlogic.gdx.physics.box2d.*;

import static unam.mx.DGame.ppm;

//Asteroid´s bodies, using same world box
public class AllAsteroids{
    private World world;
    public Body body;
    public AllAsteroids(World world, int x, int y,float radius){
        this.world=world;

        BodyDef bdef = new BodyDef();
        CircleShape shape = new CircleShape();
        FixtureDef fdef = new FixtureDef();
        bdef.type = BodyDef.BodyType.KinematicBody;
        bdef.position.set(x/ppm,y/ppm);
        body= world.createBody(bdef);
        shape.setRadius(radius/ppm);
        fdef.shape = shape;
        body.createFixture(fdef);
        shape.dispose();
    }
}
