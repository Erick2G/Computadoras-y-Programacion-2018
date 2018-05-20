package unam.mx;

import com.badlogic.gdx.ApplicationAdapter;
import com.badlogic.gdx.Game;
import com.badlogic.gdx.Gdx;
import com.badlogic.gdx.graphics.GL20;
import com.badlogic.gdx.graphics.Texture;
import com.badlogic.gdx.graphics.g2d.SpriteBatch;
import com.badlogic.gdx.graphics.OrthographicCamera;

public class DGame extends Game{
	public SpriteBatch batch; //public so all classes can use it
	public static final float ppm=10;
	public static final int screenX =2560;
	public static final int screenY=1920;

	
	@Override
	public void create () {
		batch = new SpriteBatch();
		setScreen((new PlayScreen(this)));
	}

	@Override
	public void render () {
		super.render();
	}
	
	@Override
	public void dispose () {
		batch.dispose();

	}
}
