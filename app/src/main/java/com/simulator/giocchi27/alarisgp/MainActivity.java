package com.simulator.giocchi27.alarisgp;

import android.content.Intent;
import android.graphics.Color;
import android.os.Bundle;
import android.os.CountDownTimer;
import android.support.design.widget.Snackbar;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.Toolbar;
import android.util.Log;
import android.view.View;
import android.view.Menu;
import android.view.MenuItem;
import android.view.animation.AnimationUtils;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.ListView;
import android.widget.TextView;

import android.widget.Toast;

public class MainActivity extends AppCompatActivity
    implements View.OnClickListener{

    TextView t;
    TextView val_infusing;
    TextView val_vtbi;
    TextView val_volume;
    TextView labelA;
    TextView labelB;
    TextView labelC;
    TextView label_VB_A;
    TextView label_VB_B;
    TextView label_VB_C;
    TextView ml_labelA;
    TextView ml_labelB;
    TextView ml_labelC;

    ImageView led_HOLD;
    ImageView led_START;
    ImageView led_ON;

    ListView VTBIlist;

    private static final String TAG = "AlarisGPSimulator";

    private enum Mode{
        INFUSING, VTBI, VTBIDONE, VTBIBAGS
    }

    public Mode mode = Mode.INFUSING;

    static {
        System.loadLibrary("alaris-gp-jni");
    }

    public native void invoke_Init();
    public native void invoke_Click_UP();
    public native void invoke_Click_up();
    public native void invoke_Click_DOWN();
    public native void invoke_Click_down();
    public native void invoke_VTBI_Click_UP();
    public native void invoke_VTBI_Click_up();
    public native void invoke_VTBI_Click_DOWN();
    public native void invoke_VTBI_Click_down();
    public native void invoke_Turn_ON();
    public native void invoke_Turn_OFF();
    public native void invoke_pause();
    public native void invoke_start();
    public native void invoke_tick();
    public native boolean invoke_per_Click_UP();
    public native boolean invoke_per_Click_up();
    public native boolean invoke_per_Click_DOWN();
    public native boolean invoke_per_Click_down();
    public native boolean invoke_per_Turn_ON();
    public native boolean invoke_per_Turn_OFF();
    public native boolean invoke_per_pause();
    public native boolean invoke_per_start();
    public native boolean invoke_per_tick();
    public native float invoke_GetInfusionrate();
    public native float invoke_GetVTBI();
    public native float invoke_GetVolumeinfused();
    public native void invoke_SetVTBI(float jf);

    CountDownTimer tick;

    int indexVTBIBags = 5;
    float[] VTBIvalues = {3000.0f,2000.0f,1500.0f,1000.0f,500.0f,250.0f,200.0f,100.0f,50.0f,0.0f};

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(com.simulator.giocchi27.alarisgp.R.layout.activity_main);
        Toolbar toolbar = (Toolbar) findViewById(com.simulator.giocchi27.alarisgp.R.id.toolbar);
        setSupportActionBar(toolbar);

        //Initialising data
        invoke_Init();

        //((TextView) findViewById(R.id.jni_msgView)).setText(getMsgFromJni());

        /*ImageView iv = (ImageView) findViewById (com.simulator.giocchi27.alarisgp.R.id.image);
        if (iv != null) {
            iv.setOnTouchListener (this);
        }*/

        VTBIlist = (ListView)findViewById(R.id.VTBIlistView);
        VTBIlist.setVisibility((View.INVISIBLE));
        String[] VTBIstrings = new String[]{
                "3000 ml",
                "2000 ml",
                "1500 ml",
                "1000 ml",
                "500 ml",
                "250 ml",
                "200 ml",
                "100 ml",
                "50 ml",
                "0 ml"
        };
        ArrayAdapter<String> adapter = new ArrayAdapter<String>(MainActivity.this, R.layout.custom_listview, VTBIstrings);

        VTBIlist.setAdapter(adapter);
        VTBIlist.setChoiceMode(ListView.CHOICE_MODE_SINGLE);

        t = (TextView)findViewById(com.simulator.giocchi27.alarisgp.R.id.display);
        val_infusing = (TextView)findViewById(R.id.val_infusing);
        val_vtbi = (TextView)findViewById(R.id.val_vtbi);
        val_volume = (TextView)findViewById(R.id.val_volume);
        labelA = (TextView)findViewById(R.id.labelA);
        labelB = (TextView)findViewById(R.id.labelB);
        labelC = (TextView)findViewById(R.id.labelC);
        label_VB_A = (TextView)findViewById(R.id.disp_VB_A);
        label_VB_B = (TextView)findViewById(R.id.disp_VB_B);
        label_VB_C = (TextView)findViewById(R.id.disp_VB_C);
        ml_labelA = (TextView)findViewById(R.id.ml_labelA);
        ml_labelB = (TextView)findViewById(R.id.ml_labelB);
        ml_labelC = (TextView)findViewById(R.id.ml_labelC);

        led_HOLD = (ImageView) findViewById(R.id.led_HOLD);
        led_START = (ImageView) findViewById(R.id.led_START);
        led_ON = (ImageView) findViewById(R.id.led_ON);

        led_HOLD.setVisibility(View.INVISIBLE);
        led_START.setVisibility(View.INVISIBLE);
        led_ON.setVisibility(View.INVISIBLE);

        t.setAnimation(AnimationUtils.loadAnimation(this, R.anim.blink));

        Button b = (Button)findViewById(R.id.but_VB_A);
        b.setOnClickListener((View.OnClickListener)this);

        b = (Button)findViewById(R.id.but_VB_B);
        b.setOnClickListener((View.OnClickListener)this);

        b = (Button)findViewById(R.id.but_VB_C);
        b.setOnClickListener((View.OnClickListener)this);

        b = (Button)findViewById(R.id.but_DOWN);
        b.setOnClickListener((View.OnClickListener)this);

        b = (Button)findViewById(R.id.but_down);
        b.setOnClickListener((View.OnClickListener)this);

        b = (Button)findViewById(R.id.but_UP);
        b.setOnClickListener((View.OnClickListener)this);

        b = (Button)findViewById(R.id.but_up);
        b.setOnClickListener((View.OnClickListener)this);

        b = (Button)findViewById(R.id.but_ONOFF);
        b.setOnClickListener((View.OnClickListener)this);

        b = (Button)findViewById(R.id.but_START);
        b.setOnClickListener((View.OnClickListener)this);

        b = (Button)findViewById(R.id.but_HOLD);
        b.setOnClickListener((View.OnClickListener)this);

    }

    public void onClick(View v) {

        switch(v.getId()){

            case R.id.but_VB_A: /** Virtual Button A Clicked */
                if (mode == Mode.VTBIBAGS){
                    //TODO setVTBI with value VTBIvalues[indexVTBIBags]
                    invoke_SetVTBI(VTBIvalues[indexVTBIBags]);
                    Log.v(TAG, "VTBI should be: " + VTBIvalues[indexVTBIBags]);
                }
                t.setText("ON HOLD - SET RATE");
                mode = Mode.INFUSING;       //to unlock infusing change
                val_infusing.setText("" + String.format("%.01f", invoke_GetInfusionrate()));
                val_vtbi.setText("" + String.format("%.01f", invoke_GetVTBI()));
                val_volume.setText("" + String.format("%.01f", invoke_GetVolumeinfused()));
                VTBIlist.setVisibility((View.INVISIBLE));
                setView("RATE:","VTBI:","VOLUME:","Vol","VTBI","","ml/h","ml","ml");
                break;

            case R.id.but_VB_B: /** Virtual Button B Clicked */
                t.setText("ON HOLD - SET VTBI");
                mode = Mode.VTBI;       // to unlock vtbi change
                t.setText("VTBI");
                val_infusing.setText("");
                val_vtbi.setText("" + String.format("%.01f", invoke_GetVTBI()));
                val_volume.setText("");
                setView("","VTBI:","","OK","","BAGS","","ml","");
                break;

            case R.id.but_VB_C: /** Virtual Button C Clicked */
                if ( mode == Mode.VTBIDONE){
                    val_infusing.setText("" + String.format("%.01f", invoke_GetInfusionrate()));
                    val_vtbi.setText("" + String.format("%.01f", invoke_GetVTBI()));
                    val_volume.setText("" + String.format("%.01f", invoke_GetVolumeinfused()));
                    setView("RATE:","VTBI:","VOLUME:","Vol","VTBI","","ml/h","ml","ml");
                    mode = Mode.INFUSING;
                }
                if ( mode == Mode.VTBI){
                    t.setText("");
                    val_infusing.setText("");
                    val_vtbi.setText("");
                    val_volume.setText("");
                    VTBIlist.setVisibility((View.VISIBLE));
                    VTBIlist.getChildAt(indexVTBIBags).setBackgroundColor(Color.DKGRAY);
                    setView("","","","OK","","","","","");
                    mode = Mode.VTBIBAGS;
                }
                break;

            case R.id.but_ONOFF: /** Button ON/OFF Clicked */
                if (invoke_per_Turn_ON()) {
                    invoke_Turn_ON();
                    t.setText("ON HOLD - SET RATE");
                    val_infusing.setText("" + String.format("%.01f", invoke_GetInfusionrate()));
                    val_vtbi.setText("" + String.format("%.01f", invoke_GetVTBI()));
                    val_volume.setText("" + String.format("%.01f", invoke_GetVolumeinfused()));
                    setView("RATE:","VTBI:","VOLUME:","Vol","VTBI","","ml/h","ml","ml");
                    led_HOLD.setVisibility(View.VISIBLE);
                    led_ON.setVisibility(View.VISIBLE);
                    Snackbar.make(v, "Device turned on", Snackbar.LENGTH_LONG).setAction("Action", null).show();;
                }
                else if (invoke_per_Turn_OFF()) {
                    invoke_Turn_OFF();
                    t.setText("");
                    val_infusing.setText("");
                    val_vtbi.setText("");
                    val_volume.setText("");
                    setView("","","","","","","","","");
                    led_HOLD.setVisibility(View.INVISIBLE);
                    led_ON.setVisibility(View.INVISIBLE);
                    Snackbar.make(v, "Device turned off", Snackbar.LENGTH_LONG).setAction("Action", null).show();;
                }
                break;

            case R.id.but_START: /** Button START Clicked */
                if (mode == Mode.INFUSING) {
                    if (invoke_per_start()) {
                        //led_START.setVisibility(View.VISIBLE);
                        led_START.setAnimation(AnimationUtils.loadAnimation(this, R.anim.blink));
                        invoke_start();
                        tick = new CountDownTimer(300000, 1000) {

                            public void onTick(long millisUntilFinished) {
                                t.setText("INFUSING");
                                val_vtbi.setText("" + String.format("%.01f", invoke_GetVTBI()));
                                val_volume.setText("" + String.format("%.01f", invoke_GetVolumeinfused()));
                                if (!infusing()) {
                                    this.cancel();
                                    t.setText("VTBIDONE");
                                    val_infusing.setText("");
                                    val_vtbi.setText("");
                                    val_volume.setText("");
                                    setView("", "", "", "", "", "CANCEL", "", "", "");
                                }
                            }

                            public void onFinish() {
                                Log.v(TAG, "VTBIDONE");
                            }
                        }.start();
                    }
                }
                break;

            case R.id.but_HOLD: /** Button HOLD Clicked */
                if (mode == Mode.INFUSING) {
                    if (invoke_per_pause()) {
                        t.setText("ON HOLD");
                        led_HOLD.setVisibility(View.VISIBLE);
                        //led_START.setVisibility(View.INVISIBLE);
                        led_START.clearAnimation();
                        invoke_pause();
                        tick.cancel();
                    }
                }
                break;

            case R.id.but_UP: /** Button UP Clicked */
                if (mode == Mode.INFUSING) {
                    if (invoke_per_Click_UP()) {
                        invoke_Click_UP();
                        //t.setText("Button UP!");
                        val_infusing.setText("" + String.format("%.01f", invoke_GetInfusionrate()));
                    }
                }
                if (mode == Mode.VTBI) {
                    if (invoke_per_Click_UP()) {
                        invoke_VTBI_Click_UP();
                        //t.setText("Button UP!");
                        val_vtbi.setText("" + String.format("%.01f", invoke_GetVTBI()));
                    }
                }
                if (mode == Mode.VTBIBAGS){
                    VTBIlist.getChildAt(indexVTBIBags).setBackgroundColor(Color.TRANSPARENT);
                    indexVTBIBags = 0;
                    VTBIlist.getChildAt(indexVTBIBags).setBackgroundColor(Color.DKGRAY);
                }
                break;

            case R.id.but_up: /** Button up Clicked */
                if (mode == Mode.INFUSING) {
                    if (invoke_per_Click_up()) {
                        invoke_Click_up();
                        //t.setText("Button up!");
                        val_infusing.setText("" + String.format("%.01f", invoke_GetInfusionrate()));
                    }
                }
                if (mode == Mode.VTBI) {
                    if (invoke_per_Click_up()) {
                        invoke_VTBI_Click_up();
                        //t.setText("Button up!");
                        val_vtbi.setText("" + String.format("%.01f", invoke_GetVTBI()));
                    }
                }
                if (mode == Mode.VTBIBAGS){
                    if ( (indexVTBIBags - 1 ) >= 0 ) {
                        VTBIlist.getChildAt(indexVTBIBags).setBackgroundColor(Color.TRANSPARENT);
                        VTBIlist.getChildAt(--indexVTBIBags).setBackgroundColor(Color.DKGRAY);
                    }
                }
                break;

            case R.id.but_DOWN: /** Button DOWN Clicked */
                if (mode == Mode.INFUSING) {
                    if (invoke_per_Click_DOWN()) {
                        invoke_Click_DOWN();
                        //t.setText("Button DOWN!");
                        val_infusing.setText("" + String.format("%.01f", invoke_GetInfusionrate()));
                    }
                }
                if (mode == Mode.VTBI) {
                    if (invoke_per_Click_DOWN()) {
                        invoke_VTBI_Click_DOWN();
                        //t.setText("Button DOWN!");
                        val_vtbi.setText("" + String.format("%.01f", invoke_GetVTBI()));
                    }
                }
                if (mode == Mode.VTBIBAGS){
                    VTBIlist.getChildAt(indexVTBIBags).setBackgroundColor(Color.TRANSPARENT);
                    indexVTBIBags = VTBIlist.getChildCount() - 1 ;
                    VTBIlist.getChildAt(indexVTBIBags).setBackgroundColor(Color.DKGRAY);
                }
                break;

            case R.id.but_down: /** Button down Clicked */
                if (mode == Mode.INFUSING) {
                    if (invoke_per_Click_down()) {
                        invoke_Click_down();
                        //t.setText("Button down!");
                        val_infusing.setText("" + String.format("%.01f", invoke_GetInfusionrate()));
                    }
                }
                if (mode == Mode.VTBI) {
                    if (invoke_per_Click_down()) {
                        invoke_VTBI_Click_down();
                        //t.setText("Button down!");
                        val_vtbi.setText("" + String.format("%.01f", invoke_GetVTBI()));
                    }
                }
                if (mode == Mode.VTBIBAGS){
                    if ( (indexVTBIBags + 1) < VTBIlist.getChildCount()){
                        VTBIlist.getChildAt(indexVTBIBags).setBackgroundColor(Color.TRANSPARENT);
                        VTBIlist.getChildAt(++indexVTBIBags).setBackgroundColor(Color.DKGRAY);
                    }
                }
                break;
        } // end switch
    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        // Inflate the menu; this adds items to the action bar if it is present.
        getMenuInflater().inflate(com.simulator.giocchi27.alarisgp.R.menu.menu_main, menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        // Handle action bar item clicks here. The action bar will
        // automatically handle clicks on the Home/Up button, so long
        // as you specify a parent activity in AndroidManifest.xml.
        int id = item.getItemId();

        //noinspection SimplifiableIfStatement
        if (id == com.simulator.giocchi27.alarisgp.R.id.action_settings) {
            startActivity(new Intent(MainActivity.this, About.class)) ;
            return true;
        }

        return super.onOptionsItemSelected(item);
    }

    public void toast (String msg)
    {
        Toast.makeText (getApplicationContext(), msg, Toast.LENGTH_SHORT).show ();
    }

    public void setView(String TextLabelA, String TextLabelB, String TextLabelC, String Text_VB_A, String Text_VB_B, String Text_VB_C,
                        String Text_ml_labelA, String Text_ml_labelB, String Text_ml_labelC){
        labelA.setText(TextLabelA);
        labelB.setText(TextLabelB);
        labelC.setText(TextLabelC);
        label_VB_A.setText(Text_VB_A);
        label_VB_B.setText(Text_VB_B);
        label_VB_C.setText(Text_VB_C);
        ml_labelA.setText(Text_ml_labelA);
        ml_labelB.setText(Text_ml_labelB);
        ml_labelC.setText(Text_ml_labelC);
    }

    public boolean infusing ()
    {
        if (invoke_GetVTBI() == 0) {
            if (invoke_per_pause()) {
                led_HOLD.setVisibility(View.VISIBLE);
                //led_START.setVisibility(View.INVISIBLE);
                led_START.clearAnimation();
                invoke_pause();
            }
            mode = Mode.VTBIDONE;
            return false;
        }
        if(invoke_per_tick()){
            invoke_tick();
            return true;
        }
        return false;
    }

}
