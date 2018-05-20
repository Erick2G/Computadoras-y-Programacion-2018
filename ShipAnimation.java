package unam.mx;

import com.badlogic.gdx.Gdx;
import com.badlogic.gdx.graphics.Texture;
import com.badlogic.gdx.graphics.g2d.Animation;
import com.badlogic.gdx.graphics.g2d.SpriteBatch;
import com.badlogic.gdx.graphics.g2d.TextureRegion;

public class ShipAnimation {
    public int x,y;
    public Animation animation;
    private float tiempo;
    private TextureRegion[] regionMov;
    public Texture imagen;
    public TextureRegion frameActual;

    public ShipAnimation(int x, int y){
        this.x=x;
        this.y=y;
        imagen = new Texture("serie_naves.png");
        TextureRegion[][] tmp = TextureRegion.split(imagen ,imagen.getWidth()/4,imagen.getHeight());
        regionMov = new TextureRegion[4];

        regionMov[0]=tmp[0][0];
        regionMov[1]=tmp[0][1];
        regionMov[2]=tmp[0][2];
        regionMov[3]=tmp[0][3];
        //regionMov[4]=tmp[0][4];

        animation = new Animation(6f/30f,regionMov);
        tiempo =0f;

    }
    public void render(SpriteBatch batch){
        tiempo+= Gdx.graphics.getDeltaTime();
        frameActual= (TextureRegion) animation.getKeyFrame(tiempo,true);
        batch.draw(frameActual,x,y);
    }
    public void coordenadas(int newX,int newY, SpriteBatch batch){
        batch.draw(frameActual,x+newX,y+newY);
    }

}
