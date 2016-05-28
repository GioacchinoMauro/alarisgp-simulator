package com.simulator.giocchi27.alarisgp;

import android.app.Activity;
import android.content.Intent;
import android.net.Uri;
import android.os.Bundle;
import android.util.DisplayMetrics;
import android.view.View;
import android.widget.ImageView;

/**
 * Created by giocchi27 on 28/05/16.
 */
public class About extends Activity {
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        setContentView(R.layout.about_window);

        DisplayMetrics dm = new DisplayMetrics();
        getWindowManager().getDefaultDisplay().getMetrics(dm);

        int width = dm.widthPixels;
        int height = dm.heightPixels;

        getWindow().setLayout((int)(width*0.9), (int)(height*0.8));

        ImageView img = (ImageView)findViewById(R.id.imageFacebook);
        img.setOnClickListener(new View.OnClickListener(){
            public void onClick(View v){
                Intent intent = new Intent();
                intent.setAction(Intent.ACTION_VIEW);
                intent.addCategory(Intent.CATEGORY_BROWSABLE);
                intent.setData(Uri.parse("https://www.facebook.com/sharer/sharer.php?u=https://github.com/GioacchinoMauro/alarisgp-simulator"));
                startActivity(intent);
            }
        });
        img = (ImageView)findViewById(R.id.imageTwitter);
        img.setOnClickListener(new View.OnClickListener(){
            public void onClick(View v){
                Intent intent = new Intent();
                intent.setAction(Intent.ACTION_VIEW);
                intent.addCategory(Intent.CATEGORY_BROWSABLE);
                intent.setData(Uri.parse( "https://twitter.com/intent/tweet?text=Look%20at%20this%20nice%20project,%20an%20Android%20open%20source%20app.%20Made%20by%20@giocchi27.%20https://https://github.com/GioacchinoMauro/alarisgp-simulator"));
                startActivity(intent);
            }
        });
        img = (ImageView)findViewById(R.id.imageTwitter);
        img.setOnClickListener(new View.OnClickListener(){
            public void onClick(View v){
                Intent intent = new Intent();
                intent.setAction(Intent.ACTION_VIEW);
                intent.addCategory(Intent.CATEGORY_BROWSABLE);
                intent.setData(Uri.parse("https://plus.google.com/share?url=https://github.com/GioacchinoMauro/alarisgp-simulator"));
                startActivity(intent);
            }
        });
    }
}
