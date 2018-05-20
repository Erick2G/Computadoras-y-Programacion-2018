package unam.mx;

import com.badlogic.gdx.graphics.Color;
import com.badlogic.gdx.graphics.OrthographicCamera;
import com.badlogic.gdx.graphics.g2d.BitmapFont;
import com.badlogic.gdx.graphics.g2d.SpriteBatch;
import com.badlogic.gdx.scenes.scene2d.Stage;
import com.badlogic.gdx.scenes.scene2d.ui.Label;
import com.badlogic.gdx.scenes.scene2d.ui.Table;
import com.badlogic.gdx.utils.Disposable;
import com.badlogic.gdx.utils.viewport.FitViewport;
import com.badlogic.gdx.utils.viewport.Viewport;


public class Stages implements Disposable {
    public Stage stage;
    public Viewport viewport;
    private Integer worldTimer;
    private float timeCount;
    private Integer score;
//Score´s camera
    public OrthographicCamera camera = new OrthographicCamera();

    Label countdownLabel;
    Label scoreLabel;
    Label timeLabel;
    Label levelLabel;
    Label worldLabel;
    Label shipLabel;
//Constructor
    public Stages(SpriteBatch sprite){
        worldTimer=0;
        timeCount =0;
        score=0;

    //Camera
        viewport = new FitViewport(640,480);  //Changed
        stage = new Stage(viewport,sprite);           //Issue Stage

        Table table = new Table();
        table.top();
        table.setFillParent( true ); //makes our table the size of our stage
//%03d is how many numbers are going to be in our counter.
        countdownLabel= new Label(String.format("%03d",worldTimer),
                                 new Label.LabelStyle(new BitmapFont(),Color.WHITE));
        scoreLabel=new Label(String.format("%06d",score),
                             new Label.LabelStyle(new BitmapFont(),Color.WHITE));
        timeLabel= new Label("Time", new Label.LabelStyle(new BitmapFont(),Color.WHITE));
        levelLabel=new Label("1-1", new Label.LabelStyle(new BitmapFont(),Color.WHITE));
        worldLabel= new Label("World", new Label.LabelStyle(new BitmapFont(), Color.WHITE));
        shipLabel=new Label("Run ship run", new Label.LabelStyle(new BitmapFont(), Color.WHITE));

        table.add(shipLabel).expandX().padTop(20);     //Changed
        table.add(worldLabel).expandX().padTop(20);    //Changed
        table.add(timeLabel).expandX().padTop(20);     //Changed
        table.row();
        table.add(scoreLabel).expandX();
        table.add(levelLabel).expandX();
        table.add(countdownLabel).expandX();          //Issue score/level/countdown position

        stage.addActor(table);
    }
    public void renderer(){

    }
    public void moveCam(int xx,int yy){
        viewport.setScreenPosition(xx,yy);

        stage.setViewport(viewport);
    }

    @Override
    public void dispose() {
        stage.dispose();
    }
}
