//
// Created by giocchi27 on 24/05/16.
//

/**---------------------------------------------------------------
*   Model: emucharts_AlarisGH_AsenaCC_MisraC
*   Author: <author name>
*           <affiliation>
*           <contact>
*  ---------------------------------------------------------------*/

#ifndef ALARIS_GP_JNI_H
#define ALARIS_GP_JNI_H

#endif

#include <jni.h>

typedef float D_64;
typedef unsigned char UC_8;

/**
 * Enumeration of state labels.
 */
typedef enum {
    off,on
} MachineState;

/**
 * constants variables
 */
extern const D_64 MAX;
extern const D_64 MIN;
extern const D_64 infusemin;
extern const D_64 max_bat;
extern const D_64 maxinfuse;
extern const D_64 maxtime;

/**
 * Global variables.
 */
D_64 display;
D_64 step;
D_64 Ceil;
D_64 Floor;

MachineState current_state;  //  Predefined variable for current state.
MachineState previous_state;  //  Predefined variable for previous state.

/** 'Enter' auxiliary function.
 *    \param newStateLabel a label to update the current state.
 *    \return void
 *    \sa leave()
 */
void enter(const MachineState newStateLabel);

/** 'Leave' auxiliary function.
 *    \param currentStateLabel a label to update the previous state.
 *    \return void
 *    \sa enter()
 */
void leave(const MachineState currentStateLabel);

/** Initialiser.
 *    \param st a state structure pointer
 *    \return void
 */
JNIEXPORT void JNICALL
Java_com_simulator_giocchi27_alarisgp_MainActivity_invoke_1Init(JNIEnv *env, jobject callingObject, jobject obj);

/** Click_alaris_DN transition function.
 * This function is generated merging two or more homonyms trasitions.
 *    It changes state from "on" to "on" when condition [st->val == min] holds,
 *     from "on" to "on" when condition [st->val < 10] holds,
 *     from "on" to "on" when condition [st->val >= 10 && st->val < 100] holds,
 *     from "on" to "on" when condition [st->val >= 100 && st->val < 1000] holds,
 *     from "on" to "on" when condition [st->val >= 1000] holds
 *
 *    \pre function is called from the right state ("on" in this case)
 *    \post function is moving to the right state ("on" in this case)
 */
JNIEXPORT void JNICALL
Java_com_simulator_giocchi27_alarisgp_MainActivity_invoke_1Click_1DOWN(JNIEnv *env,
       jobject instance);

/** Click_down transition function.
 * This function is generated merging two or more homonyms trasitions.
 *    It changes state from "on" to "on" when condition [st->val == min] holds,
 *     from "on" to "on" when condition [st->val < 10] holds,
 *     from "on" to "on" when condition [st->val >= 10 && st->val < 100] holds,
 *     from "on" to "on" when condition [st->val >= 100 && st->val < 1000] holds,
 *     from "on" to "on" when condition [st->val >= 1000] holds
 *
 *    \pre function is called from the right state ("on" in this case)
 *    \post function is moving to the right state ("on" in this case)
 */
JNIEXPORT void JNICALL
Java_com_simulator_giocchi27_alarisgp_MainActivity_invoke_1Click_1down(JNIEnv *env, jobject instance);

/** Click_UP transition function.
 * This function is generated merging two or more homonyms trasitions.
 *    It changes state from "on" to "on" when condition [st->val == max] holds,
 *     from "on" to "on" when condition [st->val < 10] holds,
 *     from "on" to "on" when condition [st->val >= 10 && st->val < 100] holds,
 *     from "on" to "on" when condition [st->val >= 100 && st->val < 1000] holds,
 *     from "on" to "on" when condition [st->val >= 1000] holds
 *
 *    \pre function is called from the right state ("on" in this case)
 *    \post function is moving to the right state ("on" in this case)
 */
JNIEXPORT void JNICALL
Java_com_simulator_giocchi27_alarisgp_MainActivity_invoke_1Click_1UP(JNIEnv *env, jobject instance);

/** Click_UP transition function.
 * This function is generated merging two or more homonyms trasitions.
 *    It changes state from "on" to "on" when condition [st->val == max] holds,
 *     from "on" to "on" when condition [st->val < 10] holds,
 *     from "on" to "on" when condition [st->val >= 10 && st->val < 100] holds,
 *     from "on" to "on" when condition [st->val >= 100 && st->val < 1000] holds,
 *     from "on" to "on" when condition [st->val >= 1000] holds
 *
 *   \pre function is called from the right state ("on" in this case)
 *    \post function is moving to the right state ("on" in this case)
 */
JNIEXPORT void JNICALL
Java_com_simulator_giocchi27_alarisgp_MainActivity_invoke_1Click_1up(JNIEnv *env, jobject instance);

/** Turn_ON transition function.
 *    It changes state from "off" to "on".
 *    \pre function is called from the right state ("off" in this case)
 *    \post function is moving to the right state ("on" in this case)
 */
JNIEXPORT void JNICALL
Java_com_simulator_giocchi27_alarisgp_MainActivity_invoke_1Turn_1ON(JNIEnv *env,jobject callingObject, jobject obj);

/** Turn_OFF transition function.
 *    It changes state from "on" to "off".
 *    \pre function is called from the right state ("on" in this case)
 *    \post function is moving to the right state ("off" in this case)
 */
JNIEXPORT void JNICALL
Java_com_simulator_giocchi27_alarisgp_MainActivity_invoke_1Turn_1OFF(JNIEnv *env, jobject callingObject, jobject obj);

/** Click_DOWN permission function for transition.
 * Useful to check if functions are invoking on the correct state.
 *    \return a boolean
 */
JNIEXPORT jboolean JNICALL
Java_com_simulator_giocchi27_alarisgp_MainActivity_invoke_1per_1Click_1DOWN(JNIEnv *env, jobject callingObject, jobject obj);

/** Click_down permission function for transition.
 * Useful to check if functions are invoking on the correct state.
 *    \return a boolean
 */
JNIEXPORT jboolean JNICALL
Java_com_simulator_giocchi27_alarisgp_MainActivity_invoke_1per_1Click_1down(JNIEnv *env, jobject callingObject, jobject obj);

/** Click_UP permission function for transition.
 * Useful to check if functions are invoking on the correct state.
 *    \return a boolean
 */
JNIEXPORT jboolean JNICALL
Java_com_simulator_giocchi27_alarisgp_MainActivity_invoke_1per_1Click_1UP(JNIEnv *env, jobject callingObject, jobject obj);

/** Click_up permission function for transition.
 * Useful to check if functions are invoking on the correct state.
 *    \return a boolean
 */
JNIEXPORT jboolean JNICALL
Java_com_simulator_giocchi27_alarisgp_MainActivity_invoke_1per_1Click_1up(JNIEnv *env, jobject callingObject, jobject obj);

/** Turn_ON permission function for transition.
 * Useful to check if functions are invoking on the correct state.
 *    \return a boolean
 */
JNIEXPORT jboolean JNICALL
Java_com_simulator_giocchi27_alarisgp_MainActivity_invoke_1per_1Turn_1ON(JNIEnv *env, jobject callingObject, jobject obj);

/** Turn_OFF permission function for transition.
 * Useful to check if functions are invoking on the correct state.
 *    \return a boolean
 */
JNIEXPORT jboolean JNICALL
Java_com_simulator_giocchi27_alarisgp_MainActivity_invoke_1per_1Turn_1OFF(JNIEnv *env, jobject callingObject, jobject obj);

/** Getter function.
 * Useful to check if functions are invoking on the correct state.
 *    \return a float
 */
JNIEXPORT jfloat JNICALL
Java_com_simulator_giocchi27_alarisgp_MainActivity_invoke_1GetDisplay(JNIEnv *env, jobject callingObject);


/** ---------------------------------------------------------------
*   C code generated using PVSio-web MisraCPrinter ver 0.1
*   Tool freely available at http://www.pvsioweb.org
*  --------------------------------------------------------------*/
