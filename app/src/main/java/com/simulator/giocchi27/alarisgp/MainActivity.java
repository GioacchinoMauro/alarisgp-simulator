package com.simulator.giocchi27.alarisgp;

import android.os.Bundle;
import android.support.design.widget.Snackbar;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.Toolbar;
import android.view.View;
import android.view.Menu;
import android.view.MenuItem;
import android.view.animation.AnimationUtils;
import android.widget.Button;
import android.widget.TextView;

import android.widget.Toast;

public class MainActivity extends AppCompatActivity
    implements View.OnClickListener{

    TextView t;
    TextView val_using;
    TextView val_other;
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

    private static final String TAG = "MyActivity";

    static {
        System.loadLibrary("alaris-gp-jni");
    }

    public native void invoke_Init();
    public native void invoke_Click_UP();
    public native void invoke_Click_up();
    public native void invoke_Click_DOWN();
    public native void invoke_Click_down();
    public native void invoke_Turn_ON();
    public native void invoke_Turn_OFF();
    public native boolean invoke_per_Click_UP();
    public native boolean invoke_per_Click_up();
    public native boolean invoke_per_Click_DOWN();
    public native boolean invoke_per_Click_down();
    public native boolean invoke_per_Turn_ON();
    public native boolean invoke_per_Turn_OFF();
    public native float invoke_GetDisplay();


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

        t = (TextView)findViewById(com.simulator.giocchi27.alarisgp.R.id.display);
        val_using = (TextView)findViewById(R.id.val_using);
        val_other = (TextView)findViewById(R.id.val_other);
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


        //new AlertDialog.Builder(this).setMessage(msg).show();
    }

    public void onClick(View v) {

        switch(v.getId()){

            case R.id.but_VB_A: /** Virtual Button A Clicked */
                t.setText("Button A");
                val_using = (TextView)findViewById(R.id.val_using);
                val_other = (TextView)findViewById(R.id.val_other);
                break;

            case R.id.but_VB_B: /** Virtual Button B Clicked */
                t.setText("Button B");
                val_using = (TextView)findViewById(R.id.val_other);
                val_other = (TextView)findViewById(R.id.val_using);
                break;

            case R.id.but_VB_C: /** Virtual Button C Clicked */
                t.setText("Button C");
                break;

            case R.id.but_ONOFF: /** Button ON/OFF Clicked */
                if (invoke_per_Turn_ON()) {
                    invoke_Turn_ON();
                    t.setText("Turn ON!");
                    val_using.setText("" + String.format("%.01f", invoke_GetDisplay())); // it starts with volume
                    val_other.setText("0,00");
                    val_volume.setText("0,00");
                    setView("RATE:","VTBI:","VOLUME","Vol","VTBI","","ml/h","ml","ml");
                    Snackbar.make(v, "Device turned on", Snackbar.LENGTH_LONG).setAction("Action", null).show();;
                }
                else if (invoke_per_Turn_OFF()) {
                    invoke_Turn_OFF();
                    t.setText("");
                    val_using.setText("");
                    val_other.setText("");
                    val_volume.setText("");
                    setView("","","","","","","","","");
                    Snackbar.make(v, "Device turned off", Snackbar.LENGTH_LONG).setAction("Action", null).show();;
                }
                break;

            case R.id.but_UP: /** Button UP Clicked */
                if (invoke_per_Click_UP()) {
                    invoke_Click_UP();
                    t.setText("Button UP!");
                    val_using.setText("" + String.format("%.01f", invoke_GetDisplay()));
                }
                break;

            case R.id.but_up: /** Button up Clicked */
                if (invoke_per_Click_up()) {
                    invoke_Click_up();
                    t.setText("Button up!");
                    val_using.setText("" + String.format("%.01f", invoke_GetDisplay()));
                }
                break;

            case R.id.but_DOWN: /** Button DOWN Clicked */
                if (invoke_per_Click_DOWN()) {
                    invoke_Click_DOWN();
                    t.setText("Button DOWN!");
                    val_using.setText("" + String.format("%.01f", invoke_GetDisplay()));
                }
                break;

            case R.id.but_down: /** Button down Clicked */
                if (invoke_per_Click_down()) {
                    invoke_Click_down();
                    t.setText("Button down!");
                    val_using.setText("" + String.format("%.01f", invoke_GetDisplay()));
                }
                break;
        } // end switch
    }

    /*public boolean onTouch (View v, MotionEvent ev)
    {
        boolean handledHere = false;

        final int action = ev.getAction();

        final int evX = (int) ev.getX();
        final int evY = (int) ev.getY();

        // If we cannot find the imageView, return.
        ImageView imageView = (ImageView) v.findViewById (com.simulator.giocchi27.alarisgp.R.id.image);
        if (imageView == null) return false;

        // When the action is Down, see if we should show the "pressed" image for the default image.
        // We do this when the default image is showing. That condition is detectable by looking at the
        // tag of the view. If it is null or contains the resource number of the default image, display the pressed image.
        Integer tagNum = (Integer) imageView.getTag ();
        int currentResource = (tagNum == null) ? com.simulator.giocchi27.alarisgp.R.drawable.bkg : tagNum.intValue ();


        // Now that we know the current resource being displayed we can handle the DOWN and UP events.

        switch (action) {
            case MotionEvent.ACTION_DOWN :
                if (currentResource == com.simulator.giocchi27.alarisgp.R.drawable.bkg) {
                    handledHere = true;

                } else handledHere = true;
                break;

            case MotionEvent.ACTION_UP :

                // On the UP, we do the click action.
                // The hidden image (image_areas) has three different hotspots on it.
                // The colors are red, blue, and yellow.
                // Use image_areas to determine which region the user touched.
                int touchColor = getHotspotColor (com.simulator.giocchi27.alarisgp.R.id.image_areas, evX, evY);

                //Log.v(TAG, "Touch coordinates : " + String.valueOf(ev.getX()) + "," + String.valueOf(ev.getY()) + "and pixelcolor is: " + touchColor);

                // Compare the touchColor to the expected values. Switch to a different image, depending on what color was touched.
                // Note that we use a Color Tool object to test whether the observed color is close enough to the real color to
                // count as a match. We do this because colors on the screen do not match the map exactly because of scaling and
                // varying pixel density.
                ColorTool ct = new ColorTool ();
                int tolerance = 50;

                if (ct.closeMatch (Color.RED, touchColor, tolerance)) {
                    //Button UP
                    if (invoke_per_Click_UP()) {
                        invoke_Click_UP();
                        t.setText("Button UP!");
                        volumeD.setText("" + String.format("%.02f", invoke_GetDisplay()));
                    }
                }
                else if (ct.closeMatch (Color.BLUE, touchColor, tolerance)) {
                    //ON - OFF
                    if (invoke_per_Turn_ON()) {
                        invoke_Turn_ON();
                        t.setText("Turn ON!");
                        volumeD.setText("" + String.format("%.02f", invoke_GetDisplay()));
                        vtbiD.setText("0.00");
                        setView("Vollume:","VTBI:","A","B","C");
                        Snackbar.make(v, "Device turned on", Snackbar.LENGTH_LONG).setAction("Action", null).show();;
                    }
                    else if (invoke_per_Turn_OFF()) {
                        invoke_Turn_OFF();
                        t.setText("");
                        volumeD.setText("");
                        vtbiD.setText("");
                        setView("","","","","");
                        Snackbar.make(v, "Device turned off", Snackbar.LENGTH_LONG).setAction("Action", null).show();;
                    }
                }
                else if (ct.closeMatch (Color.YELLOW, touchColor, tolerance)) {
                    //Button DOWN
                    if (invoke_per_Click_DOWN()) {
                        invoke_Click_DOWN();
                        //volume--;
                        t.setText("Button DOWN!");
                        volumeD.setText("" + String.format("%.02f", invoke_GetDisplay()));
                    }
                }
                *//*else if ((Color.BLACK -  touchColor) < tolerance) { //TODO fix it!
                    //Buttons UP
                    //volume++;
                    //t.setText("Button UP!");
                    //volumeD.setText("" +volume);
                }
                else if (ct.closeMatch (Color.WHITE, touchColor, tolerance)) {
                    //Button DOWN
                    invokeClick_DOWN();

                    //volume--;
                    t.setText("Button DOWN!");
                    volumeD.setText("" +invokeGetDisplay());
                }*//*

                handledHere = true;
                break;

            default:
                handledHere = false;
        } // end switch

        return handledHere;
    }

    *//**
     * Get the color from the hotspot image at point x-y.
     *
     *//*

    public int getHotspotColor (int hotspotId, int x, int y) {
        ImageView img = (ImageView) findViewById (hotspotId);
        if (img == null) {
            Log.d ("ImageAreasActivity", "Hot spot image not found");
            return 0;
        } else {
            img.setDrawingCacheEnabled(true);
            Bitmap hotspots = Bitmap.createBitmap(img.getDrawingCache());
            if (hotspots == null) {
                Log.d ("ImageAreasActivity", "Hot spot bitmap was not created");
                return 0;
            } else {
                img.setDrawingCacheEnabled(false);
                return hotspots.getPixel(x, y);
            }
        }
    }
*/

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
        label_VB_C.setText(""+ Text_VB_C);
        ml_labelA.setText(Text_ml_labelA);
        ml_labelB.setText(Text_ml_labelB);
        ml_labelC.setText(Text_ml_labelC);
    }


}
