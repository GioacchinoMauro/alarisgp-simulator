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
static D_64 display;
static D_64 Ceil;
static D_64 Floor;

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
    display = 0.0f;
    enter(off);
    assert ( current_state == off );
}

/* definition of transition functions */
JNIEXPORT void JNICALL
Java_com_simulator_giocchi27_alarisgp_MainActivity_invoke_1Click_1DOWN(JNIEnv *env,
                                                                        jobject instance) {
     assert( current_state ==  on );

    if ( (current_state == on) && (display > MIN) && (display < 100) ) {
        leave(on);
        Ceil = display - fmod ( display , 1.0f );
#ifdef DEBUG        
        debug_print("Action Ceil = display - fmod ( display , 1.0f ) issued.\n");
#endif 
        display = Ceil - big_step;
#ifdef DEBUG        
        debug_print("Action display = Ceil - big_step issued.\n");
#endif       
        enter(on);
        assert( current_state == on );
        return;
    }
    if ( (current_state == on) && (display <= MIN) ) {
        leave(on);
        display = MIN;
#ifdef DEBUG        
        debug_print("Action display = MIN issued.\n");
#endif       
        enter(on);
        assert( current_state == on );
        return;
    }
    if ( (current_state == on) && (( display >= 100 ) && ( display < 1000 )) ) {
        leave(on);
        Ceil = ( display / 10.0f ) - fmod ( ( display / 10.0f ) , 1.0f );
#ifdef DEBUG        
        debug_print("Action Ceil = ( display / 10.0f ) - fmod ( ( display / 10.0f ) , 1.0f ) issued.\n");
#endif 
        display = ( Ceil - big_step ) * 10;
#ifdef DEBUG        
        debug_print("Action display = ( Ceil - big_step ) * 10 issued.\n");
#endif       
        enter(on);
        assert( current_state == on );
        return;
    }
    if ( (current_state == on) && (display >= 1000) ) {
        leave(on);
        Ceil = ( display / 100.0f ) - fmod ( ( display / 100.0f ) , 1.0f );
#ifdef DEBUG        
        debug_print("Action Ceil = ( display / 100.0f ) - fmod ( ( display / 100.0f ) , 1.0f ) issued.\n");
#endif 
        display = ( Ceil - big_step ) * 100;
#ifdef DEBUG        
        debug_print("Action display = ( Ceil - big_step ) * 100 issued.\n");
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

    if ( (current_state == on) && (display <= MIN) ) {
        leave(on);
        display = MIN;
#ifdef DEBUG        
        debug_print("Action display = MIN issued.\n");
#endif       
        enter(on);
        assert( current_state == on );
        return;
    }
    if ( (current_state == on) && (( display >= 100 ) && ( display < 1000 )) ) {
        leave(on);
        Ceil = ( display - small_step ) - fmod ( ( display - small_step ) , 1.0f );
#ifdef DEBUG        
        debug_print("Action Ceil = ( display - small_step ) - fmod ( ( display - small_step ) , 1.0f ) issued.\n");
#endif 
        display = Ceil;
#ifdef DEBUG        
        debug_print("Action display = Ceil issued.\n");
#endif       
        enter(on);
        assert( current_state == on );
        return;
    }
    if ( (current_state == on) && (display >= 1000) ) {
        leave(on);
        Ceil = ( display / 10.0f ) - fmod ( ( display / 10.0f ) , 1.0f );
#ifdef DEBUG        
        debug_print("Action Ceil = ( display / 10.0f ) - fmod ( ( display / 10.0f ) , 1.0f ) issued.\n");
#endif 
        display = ( Ceil - big_step ) * 10;
#ifdef DEBUG        
        debug_print("Action display = ( Ceil - big_step ) * 10 issued.\n");
#endif       
        enter(on);
        assert( current_state == on );
        return;
    }
    if ( (current_state == on) && (( display > MIN ) && ( display < 100 )) ) {
        leave(on);
        Ceil = ( display * 10.0f ) - fmod ( ( display * 10.0f ) , 1.0f );
#ifdef DEBUG        
        debug_print("Action Ceil = ( display * 10.0f ) - fmod ( ( display * 10.0f ) , 1.0f ) issued.\n");
#endif 
        display = ( Ceil - small_step ) / 10;
#ifdef DEBUG        
        debug_print("Action display = ( Ceil - tiny_step ) / 10 issued.\n");
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

    if ( (current_state == on) && (display >= MAX) ) {
        leave(on);
        display = MAX;
#ifdef DEBUG        
        debug_print("Action display = MAX issued.\n");
#endif       
        enter(on);
        assert( current_state == on );
        return;
    }
    if ( (current_state == on) && (display < 100) ) {
        leave(on);
        Floor = ( display - fmod ( display , 1.0f ) );
#ifdef DEBUG        
        debug_print("Action Floor = ( display - fmod ( display , 1.0f ) ) issued.\n");
#endif 
        display = Floor + big_step;
#ifdef DEBUG        
        debug_print("Action display = Floor + big_step issued.\n");
#endif       
        enter(on);
        assert( current_state == on );
        return;
    }
    if ( (current_state == on) && (( display >= 100 ) && ( display < 1000 )) ) {
        leave(on);
        Floor = ( display / 10.0f ) - fmod ( ( display / 10.0f ) , 1.0f );
#ifdef DEBUG        
        debug_print("Action Floor = ( display / 10.0f ) - fmod ( ( display / 10.0f ) , 1.0f ) issued.\n");
#endif 
        display = ( Floor + big_step ) * 10;
#ifdef DEBUG        
        debug_print("Action display = ( Floor + big_step ) * 10 issued.\n");
#endif       
        enter(on);
        assert( current_state == on );
        return;
    }
    if ( (current_state == on) && (( display >= 1000 ) && ( display < MAX )) ) {
        leave(on);
        Floor = ( display / 100.0f ) - fmod ( ( display / 100.0f ) , 1.0f );
#ifdef DEBUG        
        debug_print("Action Floor = ( display / 100.0f ) - fmod ( ( display / 100.0f ) , 1.0f ) issued.\n");
#endif 
        display = ( Floor + big_step ) * 100;
#ifdef DEBUG        
        debug_print("Action display = ( Floor + big_step ) * 100 issued.\n");
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

    if ( (current_state == on) && (display >= MAX) ) {
        leave(on);
        display = MAX;
#ifdef DEBUG        
        debug_print("Action display = MAX issued.\n");
#endif       
        enter(on);
        assert( current_state == on );
        return;
    }
    if ( (current_state == on) && (display < 100) ) {
        leave(on);
        Floor = ( ( display * 10.0f ) + small_step ) - fmod ( ( ( display * 10.0f ) + small_step ) , 1.0f );
#ifdef DEBUG        
        debug_print("Action Floor = ( ( display * 10.0f ) + tiny_step ) - fmod ( ( ( display * 10.0f ) + tiny_step ) , 1.0f ) issued.\n");
#endif 
        display = Floor / 10;
#ifdef DEBUG        
        debug_print("Action display = Floor / 10 issued.\n");
#endif       
        enter(on);
        assert( current_state == on );
        return;
    }
    if ( (current_state == on) && (( display >= 100 ) && ( display < 1000 )) ) {
        leave(on);
        Floor = ( display + small_step ) - fmod ( ( display + small_step ) , 1.0f );
#ifdef DEBUG        
        debug_print("Action Floor = ( display + small_step ) - fmod ( ( display + small_step ) , 1.0f ) issued.\n");
#endif 
        display = Floor;
#ifdef DEBUG        
        debug_print("Action display = Floor issued.\n");
#endif       
        enter(on);
        assert( current_state == on );
        return;
    }
    if ( (current_state == on) && (( display >= 1000 ) && ( display < MAX )) ) {
        leave(on);
        Floor = ( display / 10.0f ) - fmod ( ( display / 10.0f ) , 1.0f );
#ifdef DEBUG        
        debug_print("Action Floor = ( display / 10.0f ) - fmod ( ( display / 10.0f ) , 1.0f ) issued.\n");
#endif 
        display = ( Floor + big_step ) * 10;
#ifdef DEBUG        
        debug_print("Action display = ( Floor + big_step ) * 10 issued.\n");
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

    enter(off);
    assert( current_state == off );
}

JNIEXPORT jfloat JNICALL
Java_com_simulator_giocchi27_alarisgp_MainActivity_invoke_1GetDisplay(
        JNIEnv *env,
        jobject callingObject)
{
    return display;
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