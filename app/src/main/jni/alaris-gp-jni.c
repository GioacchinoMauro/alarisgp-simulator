/**---------------------------------------------------------------
*   Model: emucharts_AlarisGP_MisraC
*   Author: Gioacchino Mauro
*   Created: 19/05/16
*           <contact>
*  ---------------------------------------------------------------*/

#include <string.h>
#include <assert.h>
#include <math.h>

#include "alaris-gp-jni.h"

/* constants variables */
const D_64 big_step = 10.0f;
const D_64 MAX = 1200.0f;
const D_64 MIN = 0.0f;
const D_64 small_step = 1.0f;
const D_64 tiny_step = 0.1f;
const D_64 infusemin = 0.1f;
const D_64 max_bat = 2999.0f;
const D_64 maxinfuse = 3000.0f;
const D_64 maxtime = 3000.0f;


/**
 * Global variables.
 */
static D_64 infusionrate;
static D_64 Ceil;
static D_64 Floor;
static D_64 vtbi;

static UC_8 ac_connect;
static D_64 battery;
static D_64 elapse;
static D_64 elapsedtime;
static UC_8 infusing;
static UC_8 kvoflag;
static D_64 kvorate;
static UC_8 powered_on;
static UC_8 set_fitted;
static D_64 Time;
static D_64 volumeinfused;
static D_64 vtbi;

static MachineState current_state;  //  Predefined variable for current state.
static MachineState previous_state;  //  Predefined variable for previous state.


/* definition of auxiliary functions */
void enter(const MachineState newStateLabel) {
    current_state = newStateLabel;
}
void leave(const MachineState currentStateLabel) {
    previous_state = currentStateLabel;
}

/* definition of initialisation function */
JNIEXPORT void JNICALL
Java_com_simulator_giocchi27_alarisgp_MainActivity_invoke_1Init(
        JNIEnv *env,
        jobject callingObject,
        jobject obj)
{
    Ceil = 0.0f;
    Floor = 0.0f;
    vtbi = 0.0f;
    ac_connect = FALSE;
    battery = max_bat;
    elapse = 0.0f;
    elapsedtime = 0.0f;
    infusing = FALSE;
    infusionrate = 0.0f;
    kvoflag = FALSE;
    kvorate = 0.0f;
    powered_on = FALSE;
    set_fitted = TRUE;
    Time = 0.0f;
    volumeinfused = 0.0f;


    enter(off);
    assert ( current_state == off );
}

/* definition of transition functions */
JNIEXPORT void JNICALL
Java_com_simulator_giocchi27_alarisgp_MainActivity_invoke_1Click_1DOWN(JNIEnv *env,
                                                                        jobject instance) {
     assert( current_state ==  on );

    if ( (current_state == on) && (infusionrate > MIN) && (infusionrate < 100) ) {
        leave(on);
        Ceil = (infusionrate * 10.0f) -  fmod ((infusionrate * 10.0f) , 1.0f);

#ifdef DEBUG        
        debug_print("Action Ceil = infusionrate - fmod ( infusionrate , 1.0f ) issued.\n");
#endif
        infusionrate = (Ceil - big_step) / 10.0f;
#ifdef DEBUG        
        debug_print("Action infusionrate = Ceil - big_step issued.\n");
#endif       
        enter(on);
        assert( current_state == on );
        return;
    }
    if ( (current_state == on) && (infusionrate <= MIN) ) {
        leave(on);
        infusionrate = MIN;
#ifdef DEBUG        
        debug_print("Action infusionrate = MIN issued.\n");
#endif       
        enter(on);
        assert( current_state == on );
        return;
    }
    if ( (current_state == on) && (( infusionrate >= 100 ) && ( infusionrate < 1000 )) ) {
        leave(on);
        Ceil = ( infusionrate / 10.0f ) - fmod ( ( infusionrate / 10.0f ) , 1.0f );
#ifdef DEBUG        
        debug_print("Action Ceil = ( infusionrate / 10.0f ) - fmod ( ( infusionrate / 10.0f ) , 1.0f ) issued.\n");
#endif 
        infusionrate = ( Ceil - big_step ) * 10;
#ifdef DEBUG        
        debug_print("Action infusionrate = ( Ceil - big_step ) * 10 issued.\n");
#endif       
        enter(on);
        assert( current_state == on );
        return;
    }
    if ( (current_state == on) && (infusionrate >= 1000) ) {
        leave(on);
        Ceil = ( infusionrate / 1000.0f ) - fmod ( ( infusionrate / 1000.0f ) , 1.0f );
#ifdef DEBUG        
        debug_print("Action Ceil = ( infusionrate / 1000.0f ) - fmod ( ( infusionrate / 1000.0f ) , 1.0f ) issued.\n");
#endif 
        infusionrate = Ceil * 1000;
#ifdef DEBUG        
        debug_print("Action infusionrate = Ceil * 1000 issued.\n");
#endif       
        enter(on);
        assert( current_state == on );
        return;
    }
    return;
}

JNIEXPORT void JNICALL
Java_com_simulator_giocchi27_alarisgp_MainActivity_invoke_1Click_1down(JNIEnv *env,
                                                                       jobject instance) {
    assert( current_state ==  on );

    if ( (current_state == on) && (infusionrate <= MIN) ) {
        leave(on);
        infusionrate = MIN;
#ifdef DEBUG        
        debug_print("Action infusionrate = MIN issued.\n");
#endif       
        enter(on);
        assert( current_state == on );
        return;
    }
    if ( (current_state == on) && (( infusionrate >= 100 ) && ( infusionrate < 1000 )) ) {
        leave(on);
        Ceil = ( infusionrate - small_step ) - fmod ( ( infusionrate - small_step ) , 1.0f );
#ifdef DEBUG        
        debug_print("Action Ceil = ( infusionrate - small_step ) - fmod ( ( infusionrate - small_step ) , 1.0f ) issued.\n");
#endif 
        infusionrate = Ceil;
#ifdef DEBUG        
        debug_print("Action infusionrate = Ceil issued.\n");
#endif       
        enter(on);
        assert( current_state == on );
        return;
    }
    if ( (current_state == on) && (infusionrate >= 1000) ) {
        leave(on);
        Ceil = ( infusionrate / 10.0f ) - fmod ( ( infusionrate / 10.0f ) , 1.0f );
#ifdef DEBUG        
        debug_print("Action Ceil = ( infusionrate / 10.0f ) - fmod ( ( infusionrate / 10.0f ) , 1.0f ) issued.\n");
#endif 
        infusionrate = ( Ceil - small_step ) * 10;
#ifdef DEBUG        
        debug_print("Action infusionrate = ( Ceil - big_step ) * 10 issued.\n");
#endif       
        enter(on);
        assert( current_state == on );
        return;
    }
    if ( (current_state == on) && (( infusionrate > MIN ) && ( infusionrate < 100 )) ) {
        leave(on);
        Ceil = ( infusionrate * 10.0f ) - fmod ( ( infusionrate * 10.0f ) , 1.0f );
#ifdef DEBUG        
        debug_print("Action Ceil = ( infusionrate * 10.0f ) - fmod ( ( infusionrate * 10.0f ) , 1.0f ) issued.\n");
#endif 
        infusionrate = ( Ceil - small_step ) / 10;
#ifdef DEBUG        
        debug_print("Action infusionrate = ( Ceil - tiny_step ) / 10 issued.\n");
#endif       
        enter(on);
        assert( current_state == on );
        return;
    }
    return;
}

JNIEXPORT void JNICALL
Java_com_simulator_giocchi27_alarisgp_MainActivity_invoke_1Click_1UP(JNIEnv *env,
                                                                        jobject instance) {
    assert( current_state ==  on );

    if ( (current_state == on) && (infusionrate >= MAX) ) {
        leave(on);
        infusionrate = MAX;
#ifdef DEBUG        
        debug_print("Action infusionrate = MAX issued.\n");
#endif       
        enter(on);
        assert( current_state == on );
        return;
    }
    if ( (current_state == on) && (infusionrate < 100) ) {
        leave(on);
        Floor = ( infusionrate ) - fmod ( ( infusionrate ) , 1.0f );
#ifdef DEBUG
        debug_print("Action Floor = ( infusionrate - fmod ( infusionrate , 1.0f ) ) issued.\n");
#endif
        infusionrate = Floor + small_step;
#ifdef DEBUG
        debug_print("Action infusionrate = Floor + big_step issued.\n");
#endif       
        enter(on);
        assert( current_state == on );
        return;
    }
    if ( (current_state == on) && (( infusionrate >= 100 ) && ( infusionrate < 1000 )) ) {
        leave(on);
        Floor = ( infusionrate / 10.0f ) - fmod ( ( infusionrate / 10.0f ) , 1.0f );
#ifdef DEBUG        
        debug_print("Action Floor = ( infusionrate / 10.0f ) - fmod ( ( infusionrate / 10.0f ) , 1.0f ) issued.\n");
#endif 
        infusionrate = ( Floor + big_step ) * 10;
#ifdef DEBUG        
        debug_print("Action infusionrate = ( Floor + big_step ) * 10 issued.\n");
#endif       
        enter(on);
        assert( current_state == on );
        return;
    }
    if ( (current_state == on) && (( infusionrate >= 1000 ) && ( infusionrate < MAX )) ) {
        leave(on);
        Floor = ( infusionrate / 100.0f ) - fmod ( ( infusionrate / 100.0f ) , 1.0f );
#ifdef DEBUG        
        debug_print("Action Floor = ( infusionrate / 100.0f ) - fmod ( ( infusionrate / 100.0f ) , 1.0f ) issued.\n");
#endif 
        infusionrate = ( Floor + big_step ) * 100;
#ifdef DEBUG        
        debug_print("Action infusionrate = ( Floor + big_step ) * 100 issued.\n");
#endif       
        enter(on);
        assert( current_state == on );
        return;
    }
    return;
}

JNIEXPORT void JNICALL
Java_com_simulator_giocchi27_alarisgp_MainActivity_invoke_1Click_1up(JNIEnv *env,
                                                                     jobject instance) {
    assert( current_state ==  on );

    if ( (current_state == on) && (infusionrate >= MAX) ) {
        leave(on);
        infusionrate = MAX;
#ifdef DEBUG        
        debug_print("Action infusionrate = MAX issued.\n");
#endif       
        enter(on);
        assert( current_state == on );
        return;
    }
    if ( (current_state == on) && (infusionrate < 100) ) {
        leave(on);
        Floor = ( ( infusionrate * 10.0f ) + small_step ) - fmod ( ( ( infusionrate * 10.0f ) + small_step ) , 1.0f );
#ifdef DEBUG        
        debug_print("Action Floor = ( ( infusionrate * 10.0f ) + tiny_step ) - fmod ( ( ( infusionrate * 10.0f ) + tiny_step ) , 1.0f ) issued.\n");
#endif 
        infusionrate = Floor / 10;
#ifdef DEBUG        
        debug_print("Action infusionrate = Floor / 10 issued.\n");
#endif       
        enter(on);
        assert( current_state == on );
        return;
    }
    if ( (current_state == on) && (( infusionrate >= 100 ) && ( infusionrate < 1000 )) ) {
        leave(on);
        Floor = ( infusionrate + small_step ) - fmod ( ( infusionrate + small_step ) , 1.0f );
#ifdef DEBUG        
        debug_print("Action Floor = ( infusionrate + small_step ) - fmod ( ( infusionrate + small_step ) , 1.0f ) issued.\n");
#endif 
        infusionrate = Floor;
#ifdef DEBUG        
        debug_print("Action infusionrate = Floor issued.\n");
#endif       
        enter(on);
        assert( current_state == on );
        return;
    }
    if ( (current_state == on) && (( infusionrate >= 1000 ) && ( infusionrate < MAX )) ) {
        leave(on);
        Floor = ( infusionrate / 10.0f ) - fmod ( ( infusionrate / 10.0f ) , 1.0f );
#ifdef DEBUG        
        debug_print("Action Floor = ( infusionrate / 10.0f ) - fmod ( ( infusionrate / 10.0f ) , 1.0f ) issued.\n");
#endif 
        infusionrate = ( Floor + small_step ) * 10;
#ifdef DEBUG        
        debug_print("Action infusionrate = ( Floor + small_step ) * 10 issued.\n");
#endif       
        enter(on);
        assert( current_state == on );
        return;
    }
    return;
}

JNIEXPORT void JNICALL
Java_com_simulator_giocchi27_alarisgp_MainActivity_invoke_1VTBI_1Click_1DOWN(JNIEnv *env,
                                                                             jobject instance) {
    assert( current_state ==  on );

    if ( (current_state == on) && (vtbi > MIN) && (vtbi < 100) ) {
        leave(on);
        Ceil = (vtbi * 10) -  fmod ((vtbi * 10) , 1.0f);

#ifdef DEBUG
        debug_print("Action Ceil = vtbi - fmod ( vtbi , 1.0f ) issued.\n");
#endif
        vtbi = (Ceil - big_step) / 10;
#ifdef DEBUG
        debug_print("Action vtbi = Ceil - big_step issued.\n");
#endif
        enter(on);
        assert( current_state == on );
        return;
    }
    if ( (current_state == on) && (vtbi <= MIN) ) {
        leave(on);
        vtbi = MIN;
#ifdef DEBUG
        debug_print("Action vtbi = MIN issued.\n");
#endif
        enter(on);
        assert( current_state == on );
        return;
    }
    if ( (current_state == on) && (( vtbi >= 100 ) && ( vtbi < 1000 )) ) {
        leave(on);
        Ceil = ( vtbi / 10.0f ) - fmod ( ( vtbi / 10.0f ) , 1.0f );
#ifdef DEBUG
        debug_print("Action Ceil = ( vtbi / 10.0f ) - fmod ( ( vtbi / 10.0f ) , 1.0f ) issued.\n");
#endif
        vtbi = ( Ceil - big_step ) * 10;
#ifdef DEBUG
        debug_print("Action vtbi = ( Ceil - big_step ) * 10 issued.\n");
#endif
        enter(on);
        assert( current_state == on );
        return;
    }
    if ( (current_state == on) && (vtbi >= 1000) ) {
        leave(on);
        Ceil = ( vtbi / 1000.0f ) - fmod ( ( vtbi / 1000.0f ) , 1.0f );
#ifdef DEBUG
        debug_print("Action Ceil = ( vtbi / 1000.0f ) - fmod ( ( vtbi / 1000.0f ) , 1.0f ) issued.\n");
#endif
        vtbi = Ceil * 100;
#ifdef DEBUG
        debug_print("Action vtbi = Ceil * 1000 issued.\n");
#endif
        enter(on);
        assert( current_state == on );
        return;
    }
    return;
}

JNIEXPORT void JNICALL
Java_com_simulator_giocchi27_alarisgp_MainActivity_invoke_1VTBI_1Click_1down(JNIEnv *env,
                                                                             jobject instance) {
    assert( current_state ==  on );

    if ( (current_state == on) && (vtbi <= MIN) ) {
        leave(on);
        vtbi = MIN;
#ifdef DEBUG
        debug_print("Action vtbi = MIN issued.\n");
#endif
        enter(on);
        assert( current_state == on );
        return;
    }
    if ( (current_state == on) && (( vtbi >= 100 ) && ( vtbi < 1000 )) ) {
        leave(on);
        Ceil = ( vtbi - small_step ) - fmod ( ( vtbi - small_step ) , 1.0f );
#ifdef DEBUG
        debug_print("Action Ceil = ( vtbi - small_step ) - fmod ( ( vtbi - small_step ) , 1.0f ) issued.\n");
#endif
        vtbi = Ceil;
#ifdef DEBUG
        debug_print("Action vtbi = Ceil issued.\n");
#endif
        enter(on);
        assert( current_state == on );
        return;
    }
    if ( (current_state == on) && (vtbi >= 1000) ) {
        leave(on);
        Ceil = ( vtbi / 10.0f ) - fmod ( ( vtbi / 10.0f ) , 1.0f );
#ifdef DEBUG
        debug_print("Action Ceil = ( vtbi / 10.0f ) - fmod ( ( vtbi / 10.0f ) , 1.0f ) issued.\n");
#endif
        vtbi = ( Ceil - small_step ) * 10;
#ifdef DEBUG
        debug_print("Action vtbi = ( Ceil - big_step ) * 10 issued.\n");
#endif
        enter(on);
        assert( current_state == on );
        return;
    }
    if ( (current_state == on) && (( vtbi > MIN ) && ( vtbi < 100 )) ) {
        leave(on);
        Ceil = ( vtbi * 10.0f ) - fmod ( ( vtbi * 10.0f ) , 1.0f );
#ifdef DEBUG
        debug_print("Action Ceil = ( vtbi * 10.0f ) - fmod ( ( vtbi * 10.0f ) , 1.0f ) issued.\n");
#endif
        vtbi = ( Ceil - small_step ) / 10;
#ifdef DEBUG
        debug_print("Action vtbi = ( Ceil - tiny_step ) / 10 issued.\n");
#endif
        enter(on);
        assert( current_state == on );
        return;
    }
    return;
}

JNIEXPORT void JNICALL
Java_com_simulator_giocchi27_alarisgp_MainActivity_invoke_1VTBI_1Click_1UP(JNIEnv *env,
                                                                           jobject instance) {
    assert( current_state ==  on );

    if ( (current_state == on) && (vtbi >= MAX) ) {
        leave(on);
        vtbi = MAX;
#ifdef DEBUG
        debug_print("Action vtbi = MAX issued.\n");
#endif
        enter(on);
        assert( current_state == on );
        return;
    }
    if ( (current_state == on) && (vtbi < 100) ) {
        leave(on);
        Floor = ( vtbi ) - fmod ( ( vtbi ) , 1.0f );
#ifdef DEBUG
        debug_print("Action Floor = ( vtbi - fmod ( vtbi , 1.0f ) ) issued.\n");
#endif
        vtbi = Floor + small_step;
#ifdef DEBUG
        debug_print("Action vtbi = Floor + big_step issued.\n");
#endif
        enter(on);
        assert( current_state == on );
        return;
    }
    if ( (current_state == on) && (( vtbi >= 100 ) && ( vtbi < 1000 )) ) {
        leave(on);
        Floor = ( vtbi / 10.0f ) - fmod ( ( vtbi / 10.0f ) , 1.0f );
#ifdef DEBUG
        debug_print("Action Floor = ( vtbi / 10.0f ) - fmod ( ( vtbi / 10.0f ) , 1.0f ) issued.\n");
#endif
        vtbi = ( Floor + big_step ) * 10;
#ifdef DEBUG
        debug_print("Action vtbi = ( Floor + big_step ) * 10 issued.\n");
#endif
        enter(on);
        assert( current_state == on );
        return;
    }
    if ( (current_state == on) && (( vtbi >= 1000 ) && ( vtbi < MAX )) ) {
        leave(on);
        Floor = ( vtbi / 100.0f ) - fmod ( ( vtbi / 100.0f ) , 1.0f );
#ifdef DEBUG
        debug_print("Action Floor = ( vtbi / 100.0f ) - fmod ( ( vtbi / 100.0f ) , 1.0f ) issued.\n");
#endif
        vtbi = ( Floor + big_step ) * 100;
#ifdef DEBUG
        debug_print("Action vtbi = ( Floor + big_step ) * 100 issued.\n");
#endif
        enter(on);
        assert( current_state == on );
        return;
    }
    return;
}

JNIEXPORT void JNICALL
Java_com_simulator_giocchi27_alarisgp_MainActivity_invoke_1VTBI_1Click_1up(JNIEnv *env,
                                                                           jobject instance) {
    assert( current_state ==  on );

    if ( (current_state == on) && (vtbi >= MAX) ) {
        leave(on);
        vtbi = MAX;
#ifdef DEBUG
        debug_print("Action vtbi = MAX issued.\n");
#endif
        enter(on);
        assert( current_state == on );
        return;
    }
    if ( (current_state == on) && (vtbi < 100) ) {
        leave(on);
        Floor = ( ( vtbi * 10.0f ) + small_step ) - fmod ( ( ( vtbi * 10.0f ) + small_step ) , 1.0f );
#ifdef DEBUG
        debug_print("Action Floor = ( ( vtbi * 10.0f ) + tiny_step ) - fmod ( ( ( vtbi * 10.0f ) + tiny_step ) , 1.0f ) issued.\n");
#endif
        vtbi = Floor / 10;
#ifdef DEBUG
        debug_print("Action vtbi = Floor / 10 issued.\n");
#endif
        enter(on);
        assert( current_state == on );
        return;
    }
    if ( (current_state == on) && (( vtbi >= 100 ) && ( vtbi < 1000 )) ) {
        leave(on);
        Floor = ( vtbi + small_step ) - fmod ( ( vtbi + small_step ) , 1.0f );
#ifdef DEBUG
        debug_print("Action Floor = ( vtbi + small_step ) - fmod ( ( vtbi + small_step ) , 1.0f ) issued.\n");
#endif
        vtbi = Floor;
#ifdef DEBUG
        debug_print("Action vtbi = Floor issued.\n");
#endif
        enter(on);
        assert( current_state == on );
        return;
    }
    if ( (current_state == on) && (( vtbi >= 1000 ) && ( vtbi < MAX )) ) {
        leave(on);
        Floor = ( vtbi / 10.0f ) - fmod ( ( vtbi / 10.0f ) , 1.0f );
#ifdef DEBUG
        debug_print("Action Floor = ( vtbi / 10.0f ) - fmod ( ( vtbi / 10.0f ) , 1.0f ) issued.\n");
#endif
        vtbi = ( Floor + small_step ) * 10;
#ifdef DEBUG
        debug_print("Action vtbi = ( Floor + small_step ) * 10 issued.\n");
#endif
        enter(on);
        assert( current_state == on );
        return;
    }
    return;
}

JNIEXPORT void JNICALL
Java_com_simulator_giocchi27_alarisgp_MainActivity_invoke_1Turn_1ON(
        JNIEnv *env,
        jobject callingObject,
        jobject obj)
{
    assert( current_state == off);
    leave(off);

    powered_on = TRUE;
#ifdef DEBUG        
    debug_print("Action powered_on = TRUE issued.\n");
#endif 
    infusing = FALSE;
#ifdef DEBUG        
    debug_print("Action infusing = FALSE issued.\n");
#endif 
    elapse = 0.0f;
#ifdef DEBUG        
    debug_print("Action elapse = 0.0f issued.\n");
#endif 
    kvoflag = FALSE;
#ifdef DEBUG        
    debug_print("Action kvoflag = FALSE issued.\n");
#endif
    ac_connect = TRUE;
#ifdef DEBUG
    debug_print("Action ac_connect = TRUE issued.\n");
#endif

    enter(on);
    assert( current_state == on );
}

JNIEXPORT void JNICALL
Java_com_simulator_giocchi27_alarisgp_MainActivity_invoke_1Turn_1OFF(
        JNIEnv *env,
        jobject callingObject,
        jobject obj)
{
    assert( current_state == on);
    leave(on);

    powered_on = FALSE;
#ifdef DEBUG        
    debug_print("Action powered_on = FALSE issued.\n");
#endif 
    infusing = FALSE;
#ifdef DEBUG        
    debug_print("Action infusing = FALSE issued.\n");
#endif
    ac_connect = FALSE;
#ifdef DEBUG
    debug_print("Action ac_connect = FALSE issued.\n");
#endif


    enter(off);
    assert( current_state == off );
}

JNIEXPORT void JNICALL
Java_com_simulator_giocchi27_alarisgp_MainActivity_invoke_1pause(
        JNIEnv *env,
        jobject callingObject,
        jobject obj)
{
    assert( current_state == INFUSING_MAINS);
    assert( ( infusing ) && ( powered_on ) );
    if (( infusing ) && ( powered_on )) {
        leave(INFUSING_MAINS);
        infusing = FALSE;
#ifdef DEBUG        
        debug_print("Action infusing = FALSE issued.\n");
#endif
        elapse = 0.0f;
#ifdef DEBUG        
        debug_print("Action elapse = 0.0f issued.\n");
#endif       
        enter(on);
    }
    assert( current_state == on );
    return;
}

JNIEXPORT void JNICALL
Java_com_simulator_giocchi27_alarisgp_MainActivity_invoke_1start(
        JNIEnv *env,
        jobject callingObject,
        jobject obj)
{
    assert( current_state ==  on );

    if ( (current_state == on) && (( ac_connect ) && ( kvoflag ) && ( ( vtbi != 0 ) )) ) {
        leave(on);
        infusing = TRUE;
#ifdef DEBUG        
        debug_print("Action infusing = TRUE issued.\n");
#endif 
        kvoflag = FALSE;
#ifdef DEBUG        
        debug_print("Action kvoflag = FALSE issued.\n");
#endif       
        enter(INFUSING_MAINS);
        assert( current_state == INFUSING_MAINS );
        return;
    }
    if ( (current_state == on) && (( ac_connect ) && ( kvoflag ) && ( ( vtbi == 0 ) )) ) {
        leave(on);
        infusing = TRUE;
#ifdef DEBUG        
        debug_print("Action infusing = TRUE issued.\n");
#endif       
        enter(INFUSING_MAINS);
        assert( current_state == INFUSING_MAINS );
        return;
    }
    if ( (current_state == on) && (( ac_connect ) && ( ! kvoflag ) && ( ( vtbi != 0 ) )) ) {
        leave(on);
        infusing = TRUE;
#ifdef DEBUG        
        debug_print("Action infusing = TRUE issued.\n");
#endif       
        enter(INFUSING_MAINS);
        assert( current_state == INFUSING_MAINS );
        return;
    }
    if ( (current_state == on) && (( ! kvoflag ) && ( ( ( vtbi == 0 ) ) || ( ( infusionrate == 0 ) ) )) ) {
        leave(on);
        infusing = FALSE;
#ifdef DEBUG        
        debug_print("Action infusing = FALSE issued.\n");
#endif       
        enter(on);
        assert( current_state == on );
        return;
    }
    return;
}

JNIEXPORT void JNICALL
Java_com_simulator_giocchi27_alarisgp_MainActivity_invoke_1tick(
        JNIEnv *env,
        jobject callingObject,
        jobject obj)
{
    assert( current_state ==  INFUSING_MAINS );

    if ( (current_state == INFUSING_MAINS) && (( infusing ) && ( infusionrate < vtbi ) && ( ac_connect ) && ( infusionrate == 0 ) && ( battery < max_bat ) && ( elapsedtime + 1 < maxtime )) ) {
        leave(INFUSING_MAINS);
        Time = 0.0f;
#ifdef DEBUG        
        debug_print("Action Time = 0.0f issued.\n");
#endif 
        elapsedtime = elapsedtime + 1.0f;
#ifdef DEBUG        
        debug_print("Action elapsedtime = elapsedtime + 1.0f issued.\n");
#endif 
        battery = battery + 1.0f;
#ifdef DEBUG        
        debug_print("Action battery = battery + 1.0f issued.\n");
#endif       
        enter(INFUSING_MAINS);
        assert( current_state == INFUSING_MAINS );
        return;
    }
    if ( (current_state == INFUSING_MAINS) && (( infusing ) && ( infusionrate < vtbi ) && ( ac_connect ) && ( infusionrate == 0 ) && ( battery < max_bat ) && ( elapsedtime + 1 == maxtime )) ) {
        leave(INFUSING_MAINS);
        Time = 0.0f;
#ifdef DEBUG        
        debug_print("Action Time = 0.0f issued.\n");
#endif 
        battery = battery + 1.0f;
#ifdef DEBUG        
        debug_print("Action battery = battery + 1.0f issued.\n");
#endif       
        enter(INFUSING_MAINS);
        assert( current_state == INFUSING_MAINS );
        return;
    }
    if ( (current_state == INFUSING_MAINS) && (( infusing ) && ( infusionrate < vtbi ) && ( ac_connect ) && ( infusionrate == 0 ) && ( battery == max_bat ) && ( elapsedtime + 1 < maxtime )) ) {
        leave(INFUSING_MAINS);
        Time = 0.0f;
#ifdef DEBUG        
        debug_print("Action Time = 0.0f issued.\n");
#endif 
        elapsedtime = elapsedtime + 1.0f;
#ifdef DEBUG        
        debug_print("Action elapsedtime = elapsedtime + 1.0f issued.\n");
#endif       
        enter(INFUSING_MAINS);
        assert( current_state == INFUSING_MAINS );
        return;
    }
    if ( (current_state == INFUSING_MAINS) && (( infusing ) && ( infusionrate < vtbi ) && ( ac_connect ) && ( infusionrate == 0 ) && ( battery == max_bat ) && ( elapsedtime + 1 == maxtime )) ) {
        leave(INFUSING_MAINS);
        Time = 0.0f;
#ifdef DEBUG        
        debug_print("Action Time = 0.0f issued.\n");
#endif       
        enter(INFUSING_MAINS);
        assert( current_state == INFUSING_MAINS );
        return;
    }
    if ( (current_state == INFUSING_MAINS) && (( infusing ) && ( infusionrate < vtbi ) && ( ac_connect ) && ( infusionrate > 0 ) && ( battery < max_bat ) && ( elapsedtime + 1 < maxtime ) && ( volumeinfused + infusionrate <= maxinfuse )) ) {
        leave(INFUSING_MAINS);
        vtbi = vtbi - infusionrate;
#ifdef DEBUG        
        debug_print("Action vtbi = vtbi - infusionrate issued.\n");
#endif 
        Time = ( vtbi - infusionrate ) / infusionrate;
#ifdef DEBUG        
        debug_print("Action Time = ( vtbi - infusionrate ) / infusionrate issued.\n");
#endif 
        volumeinfused = volumeinfused + infusionrate;
#ifdef DEBUG        
        debug_print("Action volumeinfused = volumeinfused + infusionrate issued.\n");
#endif 
        elapsedtime = elapsedtime + 1.0f;
#ifdef DEBUG        
        debug_print("Action elapsedtime = elapsedtime + 1.0f issued.\n");
#endif 
        battery = battery + 1.0f;
#ifdef DEBUG        
        debug_print("Action battery = battery + 1.0f issued.\n");
#endif       
        enter(INFUSING_MAINS);
        assert( current_state == INFUSING_MAINS );
        return;
    }
    if ( (current_state == INFUSING_MAINS) && (( infusing ) && ( infusionrate < vtbi ) && ( ac_connect ) && ( infusionrate > 0 ) && ( battery < max_bat ) && ( elapsedtime + 1 < maxtime ) && ( volumeinfused + infusionrate > maxinfuse )) ) {
        leave(INFUSING_MAINS);
        vtbi = vtbi - infusionrate;
#ifdef DEBUG        
        debug_print("Action vtbi = vtbi - infusionrate issued.\n");
#endif 
        Time = ( vtbi - infusionrate ) / infusionrate;
#ifdef DEBUG        
        debug_print("Action Time = ( vtbi - infusionrate ) / infusionrate issued.\n");
#endif 
        elapsedtime = elapsedtime + 1.0f;
#ifdef DEBUG        
        debug_print("Action elapsedtime = elapsedtime + 1.0f issued.\n");
#endif 
        battery = battery + 1.0f;
#ifdef DEBUG        
        debug_print("Action battery = battery + 1.0f issued.\n");
#endif       
        enter(INFUSING_MAINS);
        assert( current_state == INFUSING_MAINS );
        return;
    }
    if ( (current_state == INFUSING_MAINS) && (( infusing ) && ( infusionrate < vtbi ) && ( ac_connect ) && ( infusionrate > 0 ) && ( battery < max_bat ) && ( elapsedtime + 1 == maxtime ) && ( volumeinfused + infusionrate <= maxinfuse )) ) {
        leave(INFUSING_MAINS);
        vtbi = vtbi - infusionrate;
#ifdef DEBUG        
        debug_print("Action vtbi = vtbi - infusionrate issued.\n");
#endif 
        Time = ( vtbi - infusionrate ) / infusionrate;
#ifdef DEBUG        
        debug_print("Action Time = ( vtbi - infusionrate ) / infusionrate issued.\n");
#endif 
        volumeinfused = volumeinfused + infusionrate;
#ifdef DEBUG        
        debug_print("Action volumeinfused = volumeinfused + infusionrate issued.\n");
#endif 
        battery = battery + 1.0f;
#ifdef DEBUG        
        debug_print("Action battery = battery + 1.0f issued.\n");
#endif       
        enter(INFUSING_MAINS);
        assert( current_state == INFUSING_MAINS );
        return;
    }
    if ( (current_state == INFUSING_MAINS) && (( infusing ) && ( infusionrate < vtbi ) && ( ac_connect ) && ( infusionrate > 0 ) && ( battery < max_bat ) && ( elapsedtime + 1 == maxtime ) && ( volumeinfused + infusionrate > maxinfuse )) ) {
        leave(INFUSING_MAINS);
        vtbi = vtbi - infusionrate;
#ifdef DEBUG        
        debug_print("Action vtbi = vtbi - infusionrate issued.\n");
#endif 
        Time = ( vtbi - infusionrate ) / infusionrate;
#ifdef DEBUG        
        debug_print("Action Time = ( vtbi - infusionrate ) / infusionrate issued.\n");
#endif 
        battery = battery + 1.0f;
#ifdef DEBUG        
        debug_print("Action battery = battery + 1.0f issued.\n");
#endif       
        enter(INFUSING_MAINS);
        assert( current_state == INFUSING_MAINS );
        return;
    }
    if ( (current_state == INFUSING_MAINS) && (( infusing ) && ( infusionrate < vtbi ) && ( ac_connect ) && ( infusionrate > 0 ) && ( battery == max_bat ) && ( elapsedtime + 1 < maxtime ) && ( volumeinfused + infusionrate <= maxinfuse )) ) {
        leave(INFUSING_MAINS);
        vtbi = vtbi - infusionrate;
#ifdef DEBUG        
        debug_print("Action vtbi = vtbi - infusionrate issued.\n");
#endif 
        Time = ( vtbi - infusionrate ) / infusionrate;
#ifdef DEBUG        
        debug_print("Action Time = ( vtbi - infusionrate ) / infusionrate issued.\n");
#endif 
        volumeinfused = volumeinfused + infusionrate;
#ifdef DEBUG        
        debug_print("Action volumeinfused = volumeinfused + infusionrate issued.\n");
#endif 
        elapsedtime = elapsedtime + 1.0f;
#ifdef DEBUG        
        debug_print("Action elapsedtime = elapsedtime + 1.0f issued.\n");
#endif       
        enter(INFUSING_MAINS);
        assert( current_state == INFUSING_MAINS );
        return;
    }
    if ( (current_state == INFUSING_MAINS) && (( infusing ) && ( infusionrate < vtbi ) && ( ac_connect ) && ( infusionrate > 0 ) && ( battery == max_bat ) && ( elapsedtime + 1 < maxtime ) && ( volumeinfused + infusionrate > maxinfuse )) ) {
        leave(INFUSING_MAINS);
        vtbi = vtbi - infusionrate;
#ifdef DEBUG        
        debug_print("Action vtbi = vtbi - infusionrate issued.\n");
#endif 
        Time = ( vtbi - infusionrate ) / infusionrate;
#ifdef DEBUG        
        debug_print("Action Time = ( vtbi - infusionrate ) / infusionrate issued.\n");
#endif 
        elapsedtime = elapsedtime + 1.0f;
#ifdef DEBUG        
        debug_print("Action elapsedtime = elapsedtime + 1.0f issued.\n");
#endif       
        enter(INFUSING_MAINS);
        assert( current_state == INFUSING_MAINS );
        return;
    }
    if ( (current_state == INFUSING_MAINS) && (( infusing ) && ( infusionrate < vtbi ) && ( ac_connect ) && ( infusionrate > 0 ) && ( battery == max_bat ) && ( elapsedtime + 1 == maxtime ) && ( volumeinfused + infusionrate <= maxinfuse )) ) {
        leave(INFUSING_MAINS);
        vtbi = vtbi - infusionrate;
#ifdef DEBUG        
        debug_print("Action vtbi = vtbi - infusionrate issued.\n");
#endif 
        Time = ( vtbi - infusionrate ) / infusionrate;
#ifdef DEBUG        
        debug_print("Action Time = ( vtbi - infusionrate ) / infusionrate issued.\n");
#endif 
        volumeinfused = volumeinfused + infusionrate;
#ifdef DEBUG        
        debug_print("Action volumeinfused = volumeinfused + infusionrate issued.\n");
#endif       
        enter(INFUSING_MAINS);
        assert( current_state == INFUSING_MAINS );
        return;
    }
    if ( (current_state == INFUSING_MAINS) && (( infusing ) && ( infusionrate < vtbi ) && ( ac_connect ) && ( infusionrate > 0 ) && ( battery == max_bat ) && ( elapsedtime + 1 == maxtime ) && ( volumeinfused + infusionrate > maxinfuse )) ) {
        leave(INFUSING_MAINS);
        vtbi = vtbi - infusionrate;
#ifdef DEBUG        
        debug_print("Action vtbi = vtbi - infusionrate issued.\n");
#endif 
        Time = ( vtbi - infusionrate ) / infusionrate;
#ifdef DEBUG        
        debug_print("Action Time = ( vtbi - infusionrate ) / infusionrate issued.\n");
#endif       
        enter(INFUSING_MAINS);
        assert( current_state == INFUSING_MAINS );
        return;
    }
    if ( (current_state == INFUSING_MAINS) && (( infusing ) && ( infusionrate >= vtbi ) && ( ! kvoflag ) && ( volumeinfused + vtbi <= maxinfuse ) && ( elapsedtime < maxtime - 1 ) && ( infusionrate < infusemin ) && ( ac_connect ) && ( battery == max_bat )) ) {
        leave(INFUSING_MAINS);
        vtbi = 0.0f;
#ifdef DEBUG        
        debug_print("Action vtbi = 0.0f issued.\n");
#endif 
        Time = 0.0f;
#ifdef DEBUG        
        debug_print("Action Time = 0.0f issued.\n");
#endif 
        kvoflag = TRUE;
#ifdef DEBUG        
        debug_print("Action kvoflag = TRUE issued.\n");
#endif 
        volumeinfused = volumeinfused + vtbi;
#ifdef DEBUG        
        debug_print("Action volumeinfused = volumeinfused + vtbi issued.\n");
#endif 
        elapsedtime = elapsedtime + 1.0f;
#ifdef DEBUG        
        debug_print("Action elapsedtime = elapsedtime + 1.0f issued.\n");
#endif 
        kvorate = infusionrate;
#ifdef DEBUG        
        debug_print("Action kvorate = infusionrate issued.\n");
#endif 
        battery = max_bat;
#ifdef DEBUG        
        debug_print("Action battery = max_bat issued.\n");
#endif       
        enter(INFUSING_MAINS);
        assert( current_state == INFUSING_MAINS );
        return;
    }
    if ( (current_state == INFUSING_MAINS) && (( infusing ) && ( infusionrate >= vtbi ) && ( ! kvoflag ) && ( volumeinfused + vtbi <= maxinfuse ) && ( elapsedtime < maxtime - 1 ) && ( infusionrate < infusemin ) && ( ac_connect ) && ( battery < max_bat )) ) {
        leave(INFUSING_MAINS);
        vtbi = 0.0f;
#ifdef DEBUG        
        debug_print("Action vtbi = 0.0f issued.\n");
#endif 
        Time = 0.0f;
#ifdef DEBUG        
        debug_print("Action Time = 0.0f issued.\n");
#endif 
        kvoflag = TRUE;
#ifdef DEBUG        
        debug_print("Action kvoflag = TRUE issued.\n");
#endif 
        volumeinfused = volumeinfused + vtbi;
#ifdef DEBUG        
        debug_print("Action volumeinfused = volumeinfused + vtbi issued.\n");
#endif 
        elapsedtime = elapsedtime + 1.0f;
#ifdef DEBUG        
        debug_print("Action elapsedtime = elapsedtime + 1.0f issued.\n");
#endif 
        kvorate = infusionrate;
#ifdef DEBUG        
        debug_print("Action kvorate = infusionrate issued.\n");
#endif 
        battery = battery + 1.0f;
#ifdef DEBUG        
        debug_print("Action battery = battery + 1.0f issued.\n");
#endif       
        enter(INFUSING_MAINS);
        assert( current_state == INFUSING_MAINS );
        return;
    }
    if ( (current_state == INFUSING_MAINS) && (( infusing ) && ( infusionrate >= vtbi ) && ( ! kvoflag ) && ( volumeinfused + vtbi <= maxinfuse ) && ( elapsedtime < maxtime - 1 ) && ( infusionrate >= infusemin ) && ( ac_connect ) && ( battery < max_bat )) ) {
        leave(INFUSING_MAINS);
        vtbi = 0.0f;
#ifdef DEBUG        
        debug_print("Action vtbi = 0.0f issued.\n");
#endif 
        Time = 0.0f;
#ifdef DEBUG        
        debug_print("Action Time = 0.0f issued.\n");
#endif 
        kvoflag = TRUE;
#ifdef DEBUG        
        debug_print("Action kvoflag = TRUE issued.\n");
#endif 
        volumeinfused = volumeinfused + vtbi;
#ifdef DEBUG        
        debug_print("Action volumeinfused = volumeinfused + vtbi issued.\n");
#endif 
        elapsedtime = elapsedtime + 1.0f;
#ifdef DEBUG        
        debug_print("Action elapsedtime = elapsedtime + 1.0f issued.\n");
#endif 
        kvorate = infusemin;
#ifdef DEBUG        
        debug_print("Action kvorate = infusemin issued.\n");
#endif 
        battery = battery + 1.0f;
#ifdef DEBUG        
        debug_print("Action battery = battery + 1.0f issued.\n");
#endif       
        enter(INFUSING_MAINS);
        assert( current_state == INFUSING_MAINS );
        return;
    }
    if ( (current_state == INFUSING_MAINS) && (( infusing ) && ( infusionrate >= vtbi ) && ( ! kvoflag ) && ( volumeinfused + vtbi <= maxinfuse ) && ( elapsedtime < maxtime - 1 ) && ( infusionrate >= infusemin ) && ( ac_connect ) && ( battery == max_bat )) ) {
        leave(INFUSING_MAINS);
        vtbi = 0.0f;
#ifdef DEBUG        
        debug_print("Action vtbi = 0.0f issued.\n");
#endif 
        Time = 0.0f;
#ifdef DEBUG        
        debug_print("Action Time = 0.0f issued.\n");
#endif 
        kvoflag = TRUE;
#ifdef DEBUG        
        debug_print("Action kvoflag = TRUE issued.\n");
#endif 
        volumeinfused = volumeinfused + vtbi;
#ifdef DEBUG        
        debug_print("Action volumeinfused = volumeinfused + vtbi issued.\n");
#endif 
        elapsedtime = elapsedtime + 1.0f;
#ifdef DEBUG        
        debug_print("Action elapsedtime = elapsedtime + 1.0f issued.\n");
#endif 
        kvorate = infusemin;
#ifdef DEBUG        
        debug_print("Action kvorate = infusemin issued.\n");
#endif 
        battery = max_bat;
#ifdef DEBUG        
        debug_print("Action battery = max_bat issued.\n");
#endif       
        enter(INFUSING_MAINS);
        assert( current_state == INFUSING_MAINS );
        return;
    }
    if ( (current_state == INFUSING_MAINS) && (( infusing ) && ( infusionrate >= vtbi ) && ( ! kvoflag ) && ( volumeinfused + vtbi <= maxinfuse ) && ( elapsedtime >= maxtime - 1 ) && ( infusionrate < infusemin ) && ( ac_connect ) && ( battery < max_bat )) ) {
        leave(INFUSING_MAINS);
        vtbi = 0.0f;
#ifdef DEBUG        
        debug_print("Action vtbi = 0.0f issued.\n");
#endif 
        Time = 0.0f;
#ifdef DEBUG        
        debug_print("Action Time = 0.0f issued.\n");
#endif 
        kvoflag = TRUE;
#ifdef DEBUG        
        debug_print("Action kvoflag = TRUE issued.\n");
#endif 
        volumeinfused = volumeinfused + vtbi;
#ifdef DEBUG        
        debug_print("Action volumeinfused = volumeinfused + vtbi issued.\n");
#endif 
        kvorate = infusionrate;
#ifdef DEBUG        
        debug_print("Action kvorate = infusionrate issued.\n");
#endif 
        battery = battery + 1.0f;
#ifdef DEBUG        
        debug_print("Action battery = battery + 1.0f issued.\n");
#endif       
        enter(INFUSING_MAINS);
        assert( current_state == INFUSING_MAINS );
        return;
    }
    if ( (current_state == INFUSING_MAINS) && (( infusing ) && ( infusionrate >= vtbi ) && ( ! kvoflag ) && ( volumeinfused + vtbi <= maxinfuse ) && ( elapsedtime >= maxtime - 1 ) && ( infusionrate < infusemin ) && ( ac_connect ) && ( battery == max_bat )) ) {
        leave(INFUSING_MAINS);
        vtbi = 0.0f;
#ifdef DEBUG        
        debug_print("Action vtbi = 0.0f issued.\n");
#endif 
        Time = 0.0f;
#ifdef DEBUG        
        debug_print("Action Time = 0.0f issued.\n");
#endif 
        kvoflag = TRUE;
#ifdef DEBUG        
        debug_print("Action kvoflag = TRUE issued.\n");
#endif 
        volumeinfused = volumeinfused + vtbi;
#ifdef DEBUG        
        debug_print("Action volumeinfused = volumeinfused + vtbi issued.\n");
#endif 
        kvorate = infusionrate;
#ifdef DEBUG        
        debug_print("Action kvorate = infusionrate issued.\n");
#endif 
        battery = max_bat;
#ifdef DEBUG        
        debug_print("Action battery = max_bat issued.\n");
#endif       
        enter(INFUSING_MAINS);
        assert( current_state == INFUSING_MAINS );
        return;
    }
    if ( (current_state == INFUSING_MAINS) && (( infusing ) && ( infusionrate >= vtbi ) && ( ! kvoflag ) && ( volumeinfused + vtbi <= maxinfuse ) && ( elapsedtime >= maxtime - 1 ) && ( infusionrate >= infusemin ) && ( ac_connect ) && ( battery < max_bat )) ) {
        leave(INFUSING_MAINS);
        vtbi = 0.0f;
#ifdef DEBUG        
        debug_print("Action vtbi = 0.0f issued.\n");
#endif 
        Time = 0.0f;
#ifdef DEBUG        
        debug_print("Action Time = 0.0f issued.\n");
#endif 
        kvoflag = TRUE;
#ifdef DEBUG        
        debug_print("Action kvoflag = TRUE issued.\n");
#endif 
        volumeinfused = volumeinfused + vtbi;
#ifdef DEBUG        
        debug_print("Action volumeinfused = volumeinfused + vtbi issued.\n");
#endif 
        kvorate = infusemin;
#ifdef DEBUG        
        debug_print("Action kvorate = infusemin issued.\n");
#endif 
        battery = battery + 1.0f;
#ifdef DEBUG        
        debug_print("Action battery = battery + 1.0f issued.\n");
#endif       
        enter(INFUSING_MAINS);
        assert( current_state == INFUSING_MAINS );
        return;
    }
    if ( (current_state == INFUSING_MAINS) && (( infusing ) && ( infusionrate >= vtbi ) && ( ! kvoflag ) && ( volumeinfused + vtbi <= maxinfuse ) && ( elapsedtime >= maxtime - 1 ) && ( infusionrate >= infusemin ) && ( ac_connect ) && ( battery == max_bat )) ) {
        leave(INFUSING_MAINS);
        vtbi = 0.0f;
#ifdef DEBUG        
        debug_print("Action vtbi = 0.0f issued.\n");
#endif 
        Time = 0.0f;
#ifdef DEBUG        
        debug_print("Action Time = 0.0f issued.\n");
#endif 
        kvoflag = TRUE;
#ifdef DEBUG        
        debug_print("Action kvoflag = TRUE issued.\n");
#endif 
        volumeinfused = volumeinfused + vtbi;
#ifdef DEBUG        
        debug_print("Action volumeinfused = volumeinfused + vtbi issued.\n");
#endif 
        kvorate = infusemin;
#ifdef DEBUG        
        debug_print("Action kvorate = infusemin issued.\n");
#endif 
        battery = max_bat;
#ifdef DEBUG        
        debug_print("Action battery = max_bat issued.\n");
#endif       
        enter(INFUSING_MAINS);
        assert( current_state == INFUSING_MAINS );
        return;
    }
    if ( (current_state == INFUSING_MAINS) && (( infusing ) && ( infusionrate >= vtbi ) && ( ! kvoflag ) && ( volumeinfused + vtbi > maxinfuse ) && ( elapsedtime < maxtime - 1 ) && ( infusionrate < infusemin ) && ( ac_connect ) && ( battery < max_bat )) ) {
        leave(INFUSING_MAINS);
        vtbi = 0.0f;
#ifdef DEBUG        
        debug_print("Action vtbi = 0.0f issued.\n");
#endif 
        Time = 0.0f;
#ifdef DEBUG        
        debug_print("Action Time = 0.0f issued.\n");
#endif 
        kvoflag = TRUE;
#ifdef DEBUG        
        debug_print("Action kvoflag = TRUE issued.\n");
#endif 
        elapsedtime = elapsedtime + 1.0f;
#ifdef DEBUG        
        debug_print("Action elapsedtime = elapsedtime + 1.0f issued.\n");
#endif 
        kvorate = infusionrate;
#ifdef DEBUG        
        debug_print("Action kvorate = infusionrate issued.\n");
#endif 
        battery = battery + 1.0f;
#ifdef DEBUG        
        debug_print("Action battery = battery + 1.0f issued.\n");
#endif       
        enter(INFUSING_MAINS);
        assert( current_state == INFUSING_MAINS );
        return;
    }
    if ( (current_state == INFUSING_MAINS) && (( infusing ) && ( infusionrate >= vtbi ) && ( ! kvoflag ) && ( volumeinfused + vtbi > maxinfuse ) && ( elapsedtime < maxtime - 1 ) && ( infusionrate < infusemin ) && ( ac_connect ) && ( battery == max_bat )) ) {
        leave(INFUSING_MAINS);
        vtbi = 0.0f;
#ifdef DEBUG        
        debug_print("Action vtbi = 0.0f issued.\n");
#endif 
        Time = 0.0f;
#ifdef DEBUG        
        debug_print("Action Time = 0.0f issued.\n");
#endif 
        kvoflag = TRUE;
#ifdef DEBUG        
        debug_print("Action kvoflag = TRUE issued.\n");
#endif 
        elapsedtime = elapsedtime + 1.0f;
#ifdef DEBUG        
        debug_print("Action elapsedtime = elapsedtime + 1.0f issued.\n");
#endif 
        kvorate = infusionrate;
#ifdef DEBUG        
        debug_print("Action kvorate = infusionrate issued.\n");
#endif 
        battery = max_bat;
#ifdef DEBUG        
        debug_print("Action battery = max_bat issued.\n");
#endif       
        enter(INFUSING_MAINS);
        assert( current_state == INFUSING_MAINS );
        return;
    }
    if ( (current_state == INFUSING_MAINS) && (( infusing ) && ( infusionrate >= vtbi ) && ( ! kvoflag ) && ( volumeinfused + vtbi > maxinfuse ) && ( elapsedtime < maxtime - 1 ) && ( infusionrate >= infusemin ) && ( ac_connect ) && ( battery < max_bat )) ) {
        leave(INFUSING_MAINS);
        vtbi = 0.0f;
#ifdef DEBUG        
        debug_print("Action vtbi = 0.0f issued.\n");
#endif 
        Time = 0.0f;
#ifdef DEBUG        
        debug_print("Action Time = 0.0f issued.\n");
#endif 
        kvoflag = TRUE;
#ifdef DEBUG        
        debug_print("Action kvoflag = TRUE issued.\n");
#endif 
        elapsedtime = elapsedtime + 1.0f;
#ifdef DEBUG        
        debug_print("Action elapsedtime = elapsedtime + 1.0f issued.\n");
#endif 
        kvorate = infusemin;
#ifdef DEBUG        
        debug_print("Action kvorate = infusemin issued.\n");
#endif 
        battery = battery + 1.0f;
#ifdef DEBUG        
        debug_print("Action battery = battery + 1.0f issued.\n");
#endif       
        enter(INFUSING_MAINS);
        assert( current_state == INFUSING_MAINS );
        return;
    }
    if ( (current_state == INFUSING_MAINS) && (( infusing ) && ( infusionrate >= vtbi ) && ( ! kvoflag ) && ( volumeinfused + vtbi > maxinfuse ) && ( elapsedtime < maxtime - 1 ) && ( infusionrate >= infusemin ) && ( ac_connect ) && ( battery == max_bat )) ) {
        leave(INFUSING_MAINS);
        vtbi = 0.0f;
#ifdef DEBUG        
        debug_print("Action vtbi = 0.0f issued.\n");
#endif 
        Time = 0.0f;
#ifdef DEBUG        
        debug_print("Action Time = 0.0f issued.\n");
#endif 
        kvoflag = TRUE;
#ifdef DEBUG        
        debug_print("Action kvoflag = TRUE issued.\n");
#endif 
        elapsedtime = elapsedtime + 1.0f;
#ifdef DEBUG        
        debug_print("Action elapsedtime = elapsedtime + 1.0f issued.\n");
#endif 
        kvorate = infusemin;
#ifdef DEBUG        
        debug_print("Action kvorate = infusemin issued.\n");
#endif 
        battery = max_bat;
#ifdef DEBUG        
        debug_print("Action battery = max_bat issued.\n");
#endif       
        enter(INFUSING_MAINS);
        assert( current_state == INFUSING_MAINS );
        return;
    }
    if ( (current_state == INFUSING_MAINS) && (( infusing ) && ( infusionrate >= vtbi ) && ( ! kvoflag ) && ( volumeinfused + vtbi > maxinfuse ) && ( elapsedtime >= maxtime - 1 ) && ( infusionrate < infusemin ) && ( ac_connect ) && ( battery < max_bat )) ) {
        leave(INFUSING_MAINS);
        vtbi = 0.0f;
#ifdef DEBUG        
        debug_print("Action vtbi = 0.0f issued.\n");
#endif 
        Time = 0.0f;
#ifdef DEBUG        
        debug_print("Action Time = 0.0f issued.\n");
#endif 
        kvoflag = TRUE;
#ifdef DEBUG        
        debug_print("Action kvoflag = TRUE issued.\n");
#endif 
        kvorate = infusionrate;
#ifdef DEBUG        
        debug_print("Action kvorate = infusionrate issued.\n");
#endif 
        battery = battery + 1.0f;
#ifdef DEBUG        
        debug_print("Action battery = battery + 1.0f issued.\n");
#endif       
        enter(INFUSING_MAINS);
        assert( current_state == INFUSING_MAINS );
        return;
    }
    if ( (current_state == INFUSING_MAINS) && (( infusing ) && ( infusionrate >= vtbi ) && ( ! kvoflag ) && ( volumeinfused + vtbi > maxinfuse ) && ( elapsedtime >= maxtime - 1 ) && ( infusionrate < infusemin ) && ( ac_connect ) && ( battery == max_bat )) ) {
        leave(INFUSING_MAINS);
        vtbi = 0.0f;
#ifdef DEBUG        
        debug_print("Action vtbi = 0.0f issued.\n");
#endif 
        Time = 0.0f;
#ifdef DEBUG        
        debug_print("Action Time = 0.0f issued.\n");
#endif 
        kvoflag = TRUE;
#ifdef DEBUG        
        debug_print("Action kvoflag = TRUE issued.\n");
#endif 
        kvorate = infusionrate;
#ifdef DEBUG        
        debug_print("Action kvorate = infusionrate issued.\n");
#endif 
        battery = max_bat;
#ifdef DEBUG        
        debug_print("Action battery = max_bat issued.\n");
#endif       
        enter(INFUSING_MAINS);
        assert( current_state == INFUSING_MAINS );
        return;
    }
    if ( (current_state == INFUSING_MAINS) && (( infusing ) && ( infusionrate >= vtbi ) && ( kvoflag ) && ( volumeinfused + kvorate <= maxinfuse ) && ( elapsedtime + 1 < maxtime ) && ( battery < max_bat )) ) {
        leave(INFUSING_MAINS);
        volumeinfused = volumeinfused + kvorate;
#ifdef DEBUG        
        debug_print("Action volumeinfused = volumeinfused + kvorate issued.\n");
#endif 
        elapsedtime = elapsedtime + 1.0f;
#ifdef DEBUG        
        debug_print("Action elapsedtime = elapsedtime + 1.0f issued.\n");
#endif 
        battery = battery + 1.0f;
#ifdef DEBUG        
        debug_print("Action battery = battery + 1.0f issued.\n");
#endif       
        enter(INFUSING_MAINS);
        assert( current_state == INFUSING_MAINS );
        return;
    }
    if ( (current_state == INFUSING_MAINS) && (( infusing ) && ( infusionrate >= vtbi ) && ( kvoflag ) && ( volumeinfused + kvorate <= maxinfuse ) && ( elapsedtime + 1 < maxtime ) && ( battery == max_bat )) ) {
        leave(INFUSING_MAINS);
        volumeinfused = volumeinfused + kvorate;
#ifdef DEBUG        
        debug_print("Action volumeinfused = volumeinfused + kvorate issued.\n");
#endif 
        elapsedtime = elapsedtime + 1.0f;
#ifdef DEBUG        
        debug_print("Action elapsedtime = elapsedtime + 1.0f issued.\n");
#endif       
        enter(INFUSING_MAINS);
        assert( current_state == INFUSING_MAINS );
        return;
    }
    if ( (current_state == INFUSING_MAINS) && (( infusing ) && ( infusionrate >= vtbi ) && ( kvoflag ) && ( volumeinfused + kvorate <= maxinfuse ) && ( elapsedtime + 1 == maxtime ) && ( battery < max_bat )) ) {
        leave(INFUSING_MAINS);
        volumeinfused = volumeinfused + kvorate;
#ifdef DEBUG        
        debug_print("Action volumeinfused = volumeinfused + kvorate issued.\n");
#endif 
        battery = battery + 1.0f;
#ifdef DEBUG        
        debug_print("Action battery = battery + 1.0f issued.\n");
#endif       
        enter(INFUSING_MAINS);
        assert( current_state == INFUSING_MAINS );
        return;
    }
    if ( (current_state == INFUSING_MAINS) && (( infusing ) && ( infusionrate >= vtbi ) && ( kvoflag ) && ( volumeinfused + kvorate <= maxinfuse ) && ( elapsedtime + 1 == maxtime ) && ( battery == max_bat )) ) {
        leave(INFUSING_MAINS);
        volumeinfused = volumeinfused + kvorate;
#ifdef DEBUG        
        debug_print("Action volumeinfused = volumeinfused + kvorate issued.\n");
#endif       
        enter(INFUSING_MAINS);
        assert( current_state == INFUSING_MAINS );
        return;
    }
    if ( (current_state == INFUSING_MAINS) && (( infusing ) && ( infusionrate >= vtbi ) && ( kvoflag ) && ( volumeinfused + kvorate > maxinfuse ) && ( elapsedtime + 1 < maxtime ) && ( battery < max_bat )) ) {
        leave(INFUSING_MAINS);
        elapsedtime = elapsedtime + 1.0f;
#ifdef DEBUG        
        debug_print("Action elapsedtime = elapsedtime + 1.0f issued.\n");
#endif 
        battery = battery + 1.0f;
#ifdef DEBUG        
        debug_print("Action battery = battery + 1.0f issued.\n");
#endif       
        enter(INFUSING_MAINS);
        assert( current_state == INFUSING_MAINS );
        return;
    }
    if ( (current_state == INFUSING_MAINS) && (( infusing ) && ( infusionrate >= vtbi ) && ( kvoflag ) && ( volumeinfused + kvorate > maxinfuse ) && ( elapsedtime + 1 < maxtime ) && ( battery == max_bat )) ) {
        leave(INFUSING_MAINS);
        elapsedtime = elapsedtime + 1.0f;
#ifdef DEBUG        
        debug_print("Action elapsedtime = elapsedtime + 1.0f issued.\n");
#endif       
        enter(INFUSING_MAINS);
        assert( current_state == INFUSING_MAINS );
        return;
    }
    if ( (current_state == INFUSING_MAINS) && (( infusing ) && ( infusionrate >= vtbi ) && ( kvoflag ) && ( volumeinfused + kvorate > maxinfuse ) && ( elapsedtime + 1 == maxtime ) && ( battery < max_bat )) ) {
        leave(INFUSING_MAINS);
        battery = battery + 1.0f;
#ifdef DEBUG        
        debug_print("Action battery = battery + 1.0f issued.\n");
#endif       
        enter(INFUSING_MAINS);
        assert( current_state == INFUSING_MAINS );
        return;
    }
    if ( (current_state == INFUSING_MAINS) && (( infusing ) && ( infusionrate >= vtbi ) && ( kvoflag ) && ( volumeinfused + kvorate > maxinfuse ) && ( elapsedtime + 1 == maxtime ) && ( battery == max_bat )) ) {
        leave(INFUSING_MAINS);
        battery = max_bat;
#ifdef DEBUG        
        debug_print("Action battery = max_bat issued.\n");
#endif       
        enter(INFUSING_MAINS);
        assert( current_state == INFUSING_MAINS );
        return;
    }
    return;
}

/* definition of permission function for transition functions */
JNIEXPORT jboolean JNICALL
Java_com_simulator_giocchi27_alarisgp_MainActivity_invoke_1per_1Click_1DOWN(
        JNIEnv *env,
        jobject callingObject,
        jobject obj)
{

    if (current_state ==  on){
        return  JNI_TRUE;
    }
    return JNI_FALSE;
}

JNIEXPORT jboolean JNICALL
Java_com_simulator_giocchi27_alarisgp_MainActivity_invoke_1per_1Click_1down(
        JNIEnv *env,
        jobject callingObject,
        jobject obj)
{

    if (current_state ==  on){
        return JNI_TRUE;
    }
    return JNI_FALSE;
}

JNIEXPORT jboolean JNICALL
Java_com_simulator_giocchi27_alarisgp_MainActivity_invoke_1per_1Click_1UP(
        JNIEnv *env,
        jobject callingObject,
        jobject obj)
{

    if (current_state ==  on){
        return JNI_TRUE;
    }
    return JNI_FALSE;
}

JNIEXPORT jboolean JNICALL
Java_com_simulator_giocchi27_alarisgp_MainActivity_invoke_1per_1Click_1up(
        JNIEnv *env,
        jobject callingObject,
        jobject obj)
{

    if (current_state ==  on){
        return JNI_TRUE;
    }
    return JNI_FALSE;
}

JNIEXPORT jboolean JNICALL
Java_com_simulator_giocchi27_alarisgp_MainActivity_invoke_1per_1Turn_1ON(
        JNIEnv *env,
        jobject callingObject,
        jobject obj)
{
    if(current_state == off){
        return JNI_TRUE;
    }
    return JNI_FALSE;
}

JNIEXPORT jboolean JNICALL
Java_com_simulator_giocchi27_alarisgp_MainActivity_invoke_1per_1Turn_1OFF(
        JNIEnv *env,
        jobject callingObject,
        jobject obj)
{
    if(current_state == on){
        return JNI_TRUE;
    }
    return JNI_FALSE;
}

JNIEXPORT jboolean JNICALL
Java_com_simulator_giocchi27_alarisgp_MainActivity_invoke_1per_1pause(
        JNIEnv *env,
        jobject callingObject,
        jobject obj)
{
    if (current_state == INFUSING_MAINS){
        return JNI_TRUE;
    }
    return JNI_FALSE;
}

JNIEXPORT jboolean JNICALL
Java_com_simulator_giocchi27_alarisgp_MainActivity_invoke_1per_1start(
        JNIEnv *env,
        jobject callingObject,
        jobject obj)
{
    if (current_state ==  on ){
        return JNI_TRUE;
    }
    return JNI_FALSE;
}

JNIEXPORT jboolean JNICALL
Java_com_simulator_giocchi27_alarisgp_MainActivity_invoke_1per_1tick(
        JNIEnv *env,
        jobject callingObject,
        jobject obj)
{
    if (current_state ==  INFUSING_MAINS ){
        return JNI_TRUE;
    }
    return JNI_FALSE;
}


/* definition of utility functions */
JNIEXPORT jfloat JNICALL
Java_com_simulator_giocchi27_alarisgp_MainActivity_invoke_1GetInfusionrate(
        JNIEnv *env,
        jobject callingObject)
{
    return infusionrate;
}

JNIEXPORT jfloat JNICALL
Java_com_simulator_giocchi27_alarisgp_MainActivity_invoke_1GetVTBI(
        JNIEnv *env,
        jobject callingObject)
{
    return vtbi;
}

JNIEXPORT jfloat JNICALL
Java_com_simulator_giocchi27_alarisgp_MainActivity_invoke_1GetVolumeinfused(
        JNIEnv *env,
        jobject callingObject)
{
    return volumeinfused;
}

JNIEXPORT jfloat JNICALL
Java_com_simulator_giocchi27_alarisgp_MainActivity_invoke_1GetTime(
        JNIEnv *env,
        jobject callingObject)
{
    return Time;
}

JNIEXPORT jfloat JNICALL
Java_com_simulator_giocchi27_alarisgp_MainActivity_invoke_1GetElapsedtime(
        JNIEnv *env,
        jobject callingObject)
{
    return elapsedtime;
}

JNIEXPORT void JNICALL
Java_com_simulator_giocchi27_alarisgp_MainActivity_invoke_1SetVTBI(
        JNIEnv* env,
        jobject callingObject,
        jfloat ji)
{
    vtbi = ji;
}