/**---------------------------------------------------------------
*   Model: emucharts_AlarisGP_MisraC
*   Author: Gioacchino Mauro
*   Created: 24/05/16
*           <contact>
*  ---------------------------------------------------------------*/

#ifndef ALARIS_GP_JNI_H
#define ALARIS_GP_JNI_H
#endif

#include <jni.h>

typedef float D_64;
typedef unsigned char UC_8;
#define true 1
#define false 0
#define TRUE 1
#define FALSE 0

/**
 * Enumeration of state labels.
 */
typedef enum {
    INFUSING_BATT,INFUSING_MAINS,off,on
} MachineState;

/**
 * constants variables
 */
extern const D_64 big_step;
extern const D_64 MAX;
extern const D_64 MIN;
extern const D_64 small_step;
extern const D_64 tiny_step;
extern const D_64 infusemin;
extern const D_64 max_bat;
extern const D_64 maxinfuse;
extern const D_64 maxtime;

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

/** Click_alaris_DOWN transition function.
 * This function is generated merging two or more triggers with the same name.
 *    It changes state from "on" to "on" when condition [val == min] holds,
 *     from "on" to "on" when condition [val < 10] holds,
 *     from "on" to "on" when condition [val >= 10 && val < 100] holds,
 *     from "on" to "on" when condition [val >= 100 && val < 1000] holds,
 *     from "on" to "on" when condition [val >= 1000] holds
 *
 *    \pre function is called from the right state ("on" in this case)
 *    \post function is moving to the right state ("on" in this case)
 */
JNIEXPORT void JNICALL
Java_com_simulator_giocchi27_alarisgp_MainActivity_invoke_1Click_1DOWN(JNIEnv *env,
       jobject instance);

/** Click_down transition function.
 * This function is generated merging two or more triggers with the same name.
 *    It changes state from "on" to "on" when condition [val == min] holds,
 *     from "on" to "on" when condition [val < 10] holds,
 *     from "on" to "on" when condition [val >= 10 && val < 100] holds,
 *     from "on" to "on" when condition [val >= 100 && val < 1000] holds,
 *     from "on" to "on" when condition [val >= 1000] holds
 *
 *    \pre function is called from the right state ("on" in this case)
 *    \post function is moving to the right state ("on" in this case)
 */
JNIEXPORT void JNICALL
Java_com_simulator_giocchi27_alarisgp_MainActivity_invoke_1Click_1down(JNIEnv *env, jobject instance);

/** Click_UP transition function.
 * This function is generated merging two or more triggers with the same name.
 *    It changes state from "on" to "on" when condition [val == max] holds,
 *     from "on" to "on" when condition [val < 10] holds,
 *     from "on" to "on" when condition [val >= 10 && val < 100] holds,
 *     from "on" to "on" when condition [val >= 100 && val < 1000] holds,
 *     from "on" to "on" when condition [val >= 1000] holds
 *
 *    \pre function is called from the right state ("on" in this case)
 *    \post function is moving to the right state ("on" in this case)
 */
JNIEXPORT void JNICALL
Java_com_simulator_giocchi27_alarisgp_MainActivity_invoke_1Click_1UP(JNIEnv *env, jobject instance);

/** Click_up transition function.
 * This function is generated merging two or more triggers with the same name.
 *    It changes state from "on" to "on" when condition [val == max] holds,
 *     from "on" to "on" when condition [val < 10] holds,
 *     from "on" to "on" when condition [val >= 10 && val < 100] holds,
 *     from "on" to "on" when condition [val >= 100 && val < 1000] holds,
 *     from "on" to "on" when condition [val >= 1000] holds
 *
 *    \pre function is called from the right state ("on" in this case)
 *    \post function is moving to the right state ("on" in this case)
 */
JNIEXPORT void JNICALL
Java_com_simulator_giocchi27_alarisgp_MainActivity_invoke_1Click_1up(JNIEnv *env, jobject instance);

/** VTBI_Click_alaris_DOWN transition function.
 * This function is generated merging two or more triggers with the same name.
 *    It changes state from "on" to "on" when condition [val == min] holds,
 *     from "on" to "on" when condition [val < 10] holds,
 *     from "on" to "on" when condition [val >= 10 && val < 100] holds,
 *     from "on" to "on" when condition [val >= 100 && val < 1000] holds,
 *     from "on" to "on" when condition [val >= 1000] holds
 *
 *    \pre function is called from the right state ("on" in this case)
 *    \post function is moving to the right state ("on" in this case)
 */
JNIEXPORT void JNICALL
Java_com_simulator_giocchi27_alarisgp_MainActivity_invoke_1VTBI_1Click_1DOWN(JNIEnv *env,
                                                                               jobject instance);

/** VTBI_Click_down transition function.
 * This function is generated merging two or more triggers with the same name.
 *    It changes state from "on" to "on" when condition [val == min] holds,
 *     from "on" to "on" when condition [val < 10] holds,
 *     from "on" to "on" when condition [val >= 10 && val < 100] holds,
 *     from "on" to "on" when condition [val >= 100 && val < 1000] holds,
 *     from "on" to "on" when condition [val >= 1000] holds
 *
 *    \pre function is called from the right state ("on" in this case)
 *    \post function is moving to the right state ("on" in this case)
 */
JNIEXPORT void JNICALL
Java_com_simulator_giocchi27_alarisgp_MainActivity_invoke_1VTBI_1Click_1down(JNIEnv *env, jobject instance);

/** VTBI_Click_UP transition function.
 * This function is generated merging two or more triggers with the same name.
 *    It changes state from "on" to "on" when condition [val == max] holds,
 *     from "on" to "on" when condition [val < 10] holds,
 *     from "on" to "on" when condition [val >= 10 && val < 100] holds,
 *     from "on" to "on" when condition [val >= 100 && val < 1000] holds,
 *     from "on" to "on" when condition [val >= 1000] holds
 *
 *    \pre function is called from the right state ("on" in this case)
 *    \post function is moving to the right state ("on" in this case)
 */
JNIEXPORT void JNICALL
Java_com_simulator_giocchi27_alarisgp_MainActivity_invoke_1VTBI_1Click_1UP(JNIEnv *env, jobject instance);

/** VTBI_Click_up transition function.
 * This function is generated merging two or more triggers with the same name.
 *    It changes state from "on" to "on" when condition [val == max] holds,
 *     from "on" to "on" when condition [val < 10] holds,
 *     from "on" to "on" when condition [val >= 10 && val < 100] holds,
 *     from "on" to "on" when condition [val >= 100 && val < 1000] holds,
 *     from "on" to "on" when condition [val >= 1000] holds
 *
 *    \pre function is called from the right state ("on" in this case)
 *    \post function is moving to the right state ("on" in this case)
 */
JNIEXPORT void JNICALL
Java_com_simulator_giocchi27_alarisgp_MainActivity_invoke_1VTBI_1Click_1up(JNIEnv *env, jobject instance);

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

/** pause transition function.
 * This function is generated merging two or more triggers with the same name.
 *    It changes state from "INFUSING_BATT" to "on" when condition [( infusing ) && ( powered_on )] holds,
 *
 *     from "INFUSING_MAINS" to "on" when condition [( infusing ) && ( powered_on )] holds
 *
 *    
 *    \param st state structure pointer
 *    \pre function is called from the right state ("INFUSING_BATT" or "INFUSING_MAINS" )
 *    \post function is moving to the right state ("on" )
 */
JNIEXPORT void JNICALL
Java_com_simulator_giocchi27_alarisgp_MainActivity_invoke_1pause(JNIEnv *env,jobject callingObject, jobject obj);

/** start transition function.
 * This function is generated merging two or more triggers with the same name.
 *    It changes state from "on" to "INFUSING_BATT" when condition [( ! ac_connect ) && ( kvoflag ) && ( ( vtbi != 0 ) )] holds,
 *
 *     from "on" to "INFUSING_BATT" when condition [( ! ac_connect ) && ( kvoflag ) && ( ( vtbi == 0 ) )] holds,
 *
 *     from "on" to "INFUSING_BATT" when condition [( ! ac_connect ) && ( ! kvoflag ) && ( ( vtbi != 0 ) )] holds,
 *
 *     from "on" to "INFUSING_MAINS" when condition [( ac_connect ) && ( kvoflag ) && ( ( vtbi != 0 ) )] holds,
 *
 *     from "on" to "INFUSING_MAINS" when condition [( ac_connect ) && ( kvoflag ) && ( ( vtbi == 0 ) )] holds,
 *
 *     from "on" to "INFUSING_MAINS" when condition [( ac_connect ) && ( ! kvoflag ) && ( ( vtbi != 0 ) )] holds,
 *
 *     from "on" to "on" when condition [( ! kvoflag ) && ( ( ( vtbi == 0 ) ) || ( ( infusionrate == 0 ) ) )] holds
 *
 *    
 *    \param st state structure pointer
 *    \pre function is called from the right state ("on" )
 *    \post function is moving to the right state ("INFUSING_BATT" or "INFUSING_MAINS" or "on" )
 */
JNIEXPORT void JNICALL
Java_com_simulator_giocchi27_alarisgp_MainActivity_invoke_1start(JNIEnv *env,jobject callingObject, jobject obj);

/** tick transition function.
 * This function is generated merging two or more triggers with the same name.
 *    It changes state from "INFUSING_MAINS" to "INFUSING_BATT" when condition [! ac_connect] holds,
 *
 *     from "INFUSING_BATT" to "INFUSING_MAINS" when condition [ac_connect] holds,
 *
 *     from "INFUSING_BATT" to "INFUSING_BATT" when condition [( infusing ) && ( infusionrate < vtbi ) && ( ! ac_connect ) && ( infusionrate == 0 ) && ( battery - 1 == 0 ) && ( elapsedtime + 1 < maxtime )] holds,
 *
 *     from "INFUSING_BATT" to "INFUSING_BATT" when condition [( infusing ) && ( infusionrate < vtbi ) && ( ! ac_connect ) && ( infusionrate == 0 ) && ( battery - 1 == 0 ) && ( elapsedtime + 1 == maxtime )] holds,
 *
 *     from "INFUSING_BATT" to "INFUSING_BATT" when condition [( infusing ) && ( infusionrate < vtbi ) && ( ! ac_connect ) && ( infusionrate == 0 ) && ( battery - 1 > 0 ) && ( elapsedtime + 1 < maxtime )] holds,
 *
 *     from "INFUSING_BATT" to "INFUSING_BATT" when condition [( infusing ) && ( infusionrate < vtbi ) && ( ! ac_connect ) && ( infusionrate == 0 ) && ( battery - 1 > 0 ) && ( elapsedtime + 1 == maxtime )] holds,
 *
 *     from "INFUSING_BATT" to "INFUSING_BATT" when condition [( infusing ) && ( infusionrate < vtbi ) && ( ! ac_connect ) && ( infusionrate > 0 ) && ( battery - 1 == 0 ) && ( elapsedtime + 1 < maxtime ) && ( volumeinfused + infusionrate <= maxinfuse )] holds,
 *
 *     from "INFUSING_BATT" to "INFUSING_BATT" when condition [( infusing ) && ( infusionrate < vtbi ) && ( ! ac_connect ) && ( infusionrate > 0 ) && ( battery - 1 == 0 ) && ( elapsedtime + 1 < maxtime ) && ( volumeinfused + infusionrate > maxinfuse )] holds,
 *
 *     from "INFUSING_BATT" to "INFUSING_BATT" when condition [( infusing ) && ( infusionrate < vtbi ) && ( ! ac_connect ) && ( infusionrate > 0 ) && ( battery - 1 == 0 ) && ( elapsedtime + 1 == maxtime ) && ( volumeinfused + infusionrate <= maxinfuse )] holds,
 *
 *     from "INFUSING_BATT" to "INFUSING_BATT" when condition [( infusing ) && ( infusionrate < vtbi ) && ( ! ac_connect ) && ( infusionrate > 0 ) && ( battery - 1 == 0 ) && ( elapsedtime + 1 == maxtime ) && ( volumeinfused + infusionrate > maxinfuse )] holds,
 *
 *     from "INFUSING_BATT" to "INFUSING_BATT" when condition [( infusing ) && ( infusionrate < vtbi ) && ( ! ac_connect ) && ( infusionrate > 0 ) && ( battery - 1 > 0 ) && ( elapsedtime + 1 < maxtime ) && ( volumeinfused + infusionrate <= maxinfuse )] holds,
 *
 *     from "INFUSING_BATT" to "INFUSING_BATT" when condition [( infusing ) && ( infusionrate < vtbi ) && ( ! ac_connect ) && ( infusionrate > 0 ) && ( battery - 1 > 0 ) && ( elapsedtime + 1 < maxtime ) && ( volumeinfused + infusionrate > maxinfuse )] holds,
 *
 *     from "INFUSING_BATT" to "INFUSING_BATT" when condition [( infusing ) && ( infusionrate < vtbi ) && ( ! ac_connect ) && ( infusionrate > 0 ) && ( battery - 1 > 0 ) && ( elapsedtime + 1 == maxtime ) && ( volumeinfused + infusionrate <= maxinfuse )] holds,
 *
 *     from "INFUSING_BATT" to "INFUSING_BATT" when condition [( infusing ) && ( infusionrate < vtbi ) && ( ! ac_connect ) && ( infusionrate > 0 ) && ( battery - 1 > 0 ) && ( elapsedtime + 1 == maxtime ) && ( volumeinfused + infusionrate > maxinfuse )] holds,
 *
 *     from "INFUSING_MAINS" to "INFUSING_MAINS" when condition [( infusing ) && ( infusionrate < vtbi ) && ( ac_connect ) && ( infusionrate == 0 ) && ( battery < max_bat ) && ( elapsedtime + 1 < maxtime )] holds,
 *
 *     from "INFUSING_MAINS" to "INFUSING_MAINS" when condition [( infusing ) && ( infusionrate < vtbi ) && ( ac_connect ) && ( infusionrate == 0 ) && ( battery < max_bat ) && ( elapsedtime + 1 == maxtime )] holds,
 *
 *     from "INFUSING_MAINS" to "INFUSING_MAINS" when condition [( infusing ) && ( infusionrate < vtbi ) && ( ac_connect ) && ( infusionrate == 0 ) && ( battery == max_bat ) && ( elapsedtime + 1 < maxtime )] holds,
 *
 *     from "INFUSING_MAINS" to "INFUSING_MAINS" when condition [( infusing ) && ( infusionrate < vtbi ) && ( ac_connect ) && ( infusionrate == 0 ) && ( battery == max_bat ) && ( elapsedtime + 1 == maxtime )] holds,
 *
 *     from "INFUSING_MAINS" to "INFUSING_MAINS" when condition [( infusing ) && ( infusionrate < vtbi ) && ( ac_connect ) && ( infusionrate > 0 ) && ( battery < max_bat ) && ( elapsedtime + 1 < maxtime ) && ( volumeinfused + infusionrate <= maxinfuse )] holds,
 *
 *     from "INFUSING_MAINS" to "INFUSING_MAINS" when condition [( infusing ) && ( infusionrate < vtbi ) && ( ac_connect ) && ( infusionrate > 0 ) && ( battery < max_bat ) && ( elapsedtime + 1 < maxtime ) && ( volumeinfused + infusionrate > maxinfuse )] holds,
 *
 *     from "INFUSING_MAINS" to "INFUSING_MAINS" when condition [( infusing ) && ( infusionrate < vtbi ) && ( ac_connect ) && ( infusionrate > 0 ) && ( battery < max_bat ) && ( elapsedtime + 1 == maxtime ) && ( volumeinfused + infusionrate <= maxinfuse )] holds,
 *
 *     from "INFUSING_MAINS" to "INFUSING_MAINS" when condition [( infusing ) && ( infusionrate < vtbi ) && ( ac_connect ) && ( infusionrate > 0 ) && ( battery < max_bat ) && ( elapsedtime + 1 == maxtime ) && ( volumeinfused + infusionrate > maxinfuse )] holds,
 *
 *     from "INFUSING_MAINS" to "INFUSING_MAINS" when condition [( infusing ) && ( infusionrate < vtbi ) && ( ac_connect ) && ( infusionrate > 0 ) && ( battery == max_bat ) && ( elapsedtime + 1 < maxtime ) && ( volumeinfused + infusionrate <= maxinfuse )] holds,
 *
 *     from "INFUSING_MAINS" to "INFUSING_MAINS" when condition [( infusing ) && ( infusionrate < vtbi ) && ( ac_connect ) && ( infusionrate > 0 ) && ( battery == max_bat ) && ( elapsedtime + 1 < maxtime ) && ( volumeinfused + infusionrate > maxinfuse )] holds,
 *
 *     from "INFUSING_MAINS" to "INFUSING_MAINS" when condition [( infusing ) && ( infusionrate < vtbi ) && ( ac_connect ) && ( infusionrate > 0 ) && ( battery == max_bat ) && ( elapsedtime + 1 == maxtime ) && ( volumeinfused + infusionrate <= maxinfuse )] holds,
 *
 *     from "INFUSING_MAINS" to "INFUSING_MAINS" when condition [( infusing ) && ( infusionrate < vtbi ) && ( ac_connect ) && ( infusionrate > 0 ) && ( battery == max_bat ) && ( elapsedtime + 1 == maxtime ) && ( volumeinfused + infusionrate > maxinfuse )] holds,
 *
 *     from "INFUSING_BATT" to "INFUSING_BATT" when condition [( infusing ) && ( infusionrate >= vtbi ) && ( ! kvoflag ) && ( volumeinfused + vtbi <= maxinfuse ) && ( elapsedtime < maxtime - 1 ) && ( infusionrate < infusemin ) && ( ! ac_connect ) && ( battery == 1 )] holds,
 *
 *     from "INFUSING_MAINS" to "INFUSING_MAINS" when condition [( infusing ) && ( infusionrate >= vtbi ) && ( ! kvoflag ) && ( volumeinfused + vtbi <= maxinfuse ) && ( elapsedtime < maxtime - 1 ) && ( infusionrate < infusemin ) && ( ac_connect ) && ( battery == max_bat )] holds,
 *
 *     from "INFUSING_BATT" to "INFUSING_BATT" when condition [( infusing ) && ( infusionrate >= vtbi ) && ( ! kvoflag ) && ( volumeinfused + vtbi <= maxinfuse ) && ( elapsedtime < maxtime - 1 ) && ( infusionrate < infusemin ) && ( ! ac_connect ) && ( ( battery - 1 ) > 0 )] holds,
 *
 *     from "INFUSING_MAINS" to "INFUSING_MAINS" when condition [( infusing ) && ( infusionrate >= vtbi ) && ( ! kvoflag ) && ( volumeinfused + vtbi <= maxinfuse ) && ( elapsedtime < maxtime - 1 ) && ( infusionrate < infusemin ) && ( ac_connect ) && ( battery < max_bat )] holds,
 *
 *     from "INFUSING_BATT" to "INFUSING_BATT" when condition [( infusing ) && ( infusionrate >= vtbi ) && ( ! kvoflag ) && ( volumeinfused + vtbi <= maxinfuse ) && ( elapsedtime < maxtime - 1 ) && ( infusionrate >= infusemin ) && ( ! ac_connect ) && ( ( battery - 1 ) > 0 )] holds,
 *
 *     from "INFUSING_BATT" to "INFUSING_BATT" when condition [( infusing ) && ( infusionrate >= vtbi ) && ( ! kvoflag ) && ( volumeinfused + vtbi <= maxinfuse ) && ( elapsedtime < maxtime - 1 ) && ( infusionrate >= infusemin ) && ( ! ac_connect ) && ( battery == 1 )] holds,
 *
 *     from "INFUSING_MAINS" to "INFUSING_MAINS" when condition [( infusing ) && ( infusionrate >= vtbi ) && ( ! kvoflag ) && ( volumeinfused + vtbi <= maxinfuse ) && ( elapsedtime < maxtime - 1 ) && ( infusionrate >= infusemin ) && ( ac_connect ) && ( battery < max_bat )] holds,
 *
 *     from "INFUSING_MAINS" to "INFUSING_MAINS" when condition [( infusing ) && ( infusionrate >= vtbi ) && ( ! kvoflag ) && ( volumeinfused + vtbi <= maxinfuse ) && ( elapsedtime < maxtime - 1 ) && ( infusionrate >= infusemin ) && ( ac_connect ) && ( battery == max_bat )] holds,
 *
 *     from "INFUSING_BATT" to "INFUSING_BATT" when condition [( infusing ) && ( infusionrate >= vtbi ) && ( ! kvoflag ) && ( volumeinfused + vtbi <= maxinfuse ) && ( elapsedtime >= maxtime - 1 ) && ( infusionrate < infusemin ) && ( ! ac_connect ) && ( ( battery - 1 ) > 0 )] holds,
 *
 *     from "INFUSING_BATT" to "INFUSING_BATT" when condition [( infusing ) && ( infusionrate >= vtbi ) && ( ! kvoflag ) && ( volumeinfused + vtbi <= maxinfuse ) && ( elapsedtime >= maxtime - 1 ) && ( infusionrate < infusemin ) && ( ! ac_connect ) && ( battery == 1 )] holds,
 *
 *     from "INFUSING_MAINS" to "INFUSING_MAINS" when condition [( infusing ) && ( infusionrate >= vtbi ) && ( ! kvoflag ) && ( volumeinfused + vtbi <= maxinfuse ) && ( elapsedtime >= maxtime - 1 ) && ( infusionrate < infusemin ) && ( ac_connect ) && ( battery < max_bat )] holds,
 *
 *     from "INFUSING_MAINS" to "INFUSING_MAINS" when condition [( infusing ) && ( infusionrate >= vtbi ) && ( ! kvoflag ) && ( volumeinfused + vtbi <= maxinfuse ) && ( elapsedtime >= maxtime - 1 ) && ( infusionrate < infusemin ) && ( ac_connect ) && ( battery == max_bat )] holds,
 *
 *     from "INFUSING_BATT" to "INFUSING_BATT" when condition [( infusing ) && ( infusionrate >= vtbi ) && ( ! kvoflag ) && ( volumeinfused + vtbi <= maxinfuse ) && ( elapsedtime >= maxtime - 1 ) && ( infusionrate >= infusemin ) && ( ! ac_connect ) && ( ( battery - 1 ) > 0 )] holds,
 *
 *     from "INFUSING_BATT" to "INFUSING_BATT" when condition [( infusing ) && ( infusionrate >= vtbi ) && ( ! kvoflag ) && ( volumeinfused + vtbi <= maxinfuse ) && ( elapsedtime >= maxtime - 1 ) && ( infusionrate >= infusemin ) && ( ! ac_connect ) && ( battery == 1 )] holds,
 *
 *     from "INFUSING_MAINS" to "INFUSING_MAINS" when condition [( infusing ) && ( infusionrate >= vtbi ) && ( ! kvoflag ) && ( volumeinfused + vtbi <= maxinfuse ) && ( elapsedtime >= maxtime - 1 ) && ( infusionrate >= infusemin ) && ( ac_connect ) && ( battery < max_bat )] holds,
 *
 *     from "INFUSING_MAINS" to "INFUSING_MAINS" when condition [( infusing ) && ( infusionrate >= vtbi ) && ( ! kvoflag ) && ( volumeinfused + vtbi <= maxinfuse ) && ( elapsedtime >= maxtime - 1 ) && ( infusionrate >= infusemin ) && ( ac_connect ) && ( battery == max_bat )] holds,
 *
 *     from "INFUSING_BATT" to "INFUSING_BATT" when condition [( infusing ) && ( infusionrate >= vtbi ) && ( ! kvoflag ) && ( volumeinfused + vtbi > maxinfuse ) && ( elapsedtime < maxtime - 1 ) && ( infusionrate < infusemin ) && ( ! ac_connect ) && ( ( battery - 1 ) > 0 )] holds,
 *
 *     from "INFUSING_MAINS" to "INFUSING_MAINS" when condition [( infusing ) && ( infusionrate >= vtbi ) && ( ! kvoflag ) && ( volumeinfused + vtbi > maxinfuse ) && ( elapsedtime < maxtime - 1 ) && ( infusionrate < infusemin ) && ( ac_connect ) && ( battery < max_bat )] holds,
 *
 *     from "INFUSING_BATT" to "INFUSING_BATT" when condition [( infusing ) && ( infusionrate >= vtbi ) && ( ! kvoflag ) && ( volumeinfused + vtbi > maxinfuse ) && ( elapsedtime < maxtime - 1 ) && ( infusionrate < infusemin ) && ( ! ac_connect ) && ( battery == 1 )] holds,
 *
 *     from "INFUSING_MAINS" to "INFUSING_MAINS" when condition [( infusing ) && ( infusionrate >= vtbi ) && ( ! kvoflag ) && ( volumeinfused + vtbi > maxinfuse ) && ( elapsedtime < maxtime - 1 ) && ( infusionrate < infusemin ) && ( ac_connect ) && ( battery == max_bat )] holds,
 *
 *     from "INFUSING_BATT" to "INFUSING_BATT" when condition [( infusing ) && ( infusionrate >= vtbi ) && ( ! kvoflag ) && ( volumeinfused + vtbi > maxinfuse ) && ( elapsedtime < maxtime - 1 ) && ( infusionrate >= infusemin ) && ( ! ac_connect ) && ( ( battery - 1 ) > 0 )] holds,
 *
 *     from "INFUSING_BATT" to "INFUSING_BATT" when condition [( infusing ) && ( infusionrate >= vtbi ) && ( ! kvoflag ) && ( volumeinfused + vtbi > maxinfuse ) && ( elapsedtime < maxtime - 1 ) && ( infusionrate >= infusemin ) && ( ! ac_connect ) && ( battery == 1 )] holds,
 *
 *     from "INFUSING_MAINS" to "INFUSING_MAINS" when condition [( infusing ) && ( infusionrate >= vtbi ) && ( ! kvoflag ) && ( volumeinfused + vtbi > maxinfuse ) && ( elapsedtime < maxtime - 1 ) && ( infusionrate >= infusemin ) && ( ac_connect ) && ( battery < max_bat )] holds,
 *
 *     from "INFUSING_MAINS" to "INFUSING_MAINS" when condition [( infusing ) && ( infusionrate >= vtbi ) && ( ! kvoflag ) && ( volumeinfused + vtbi > maxinfuse ) && ( elapsedtime < maxtime - 1 ) && ( infusionrate >= infusemin ) && ( ac_connect ) && ( battery == max_bat )] holds,
 *
 *     from "INFUSING_BATT" to "INFUSING_BATT" when condition [( infusing ) && ( infusionrate >= vtbi ) && ( ! kvoflag ) && ( volumeinfused + vtbi > maxinfuse ) && ( elapsedtime >= maxtime - 1 ) && ( infusionrate < infusemin ) && ( ! ac_connect ) && ( ( battery - 1 ) > 0 )] holds,
 *
 *     from "INFUSING_BATT" to "INFUSING_BATT" when condition [( infusing ) && ( infusionrate >= vtbi ) && ( ! kvoflag ) && ( volumeinfused + vtbi > maxinfuse ) && ( elapsedtime >= maxtime - 1 ) && ( infusionrate < infusemin ) && ( ! ac_connect ) && ( battery == 1 )] holds,
 *
 *     from "INFUSING_MAINS" to "INFUSING_MAINS" when condition [( infusing ) && ( infusionrate >= vtbi ) && ( ! kvoflag ) && ( volumeinfused + vtbi > maxinfuse ) && ( elapsedtime >= maxtime - 1 ) && ( infusionrate < infusemin ) && ( ac_connect ) && ( battery < max_bat )] holds,
 *
 *     from "INFUSING_MAINS" to "INFUSING_MAINS" when condition [( infusing ) && ( infusionrate >= vtbi ) && ( ! kvoflag ) && ( volumeinfused + vtbi > maxinfuse ) && ( elapsedtime >= maxtime - 1 ) && ( infusionrate < infusemin ) && ( ac_connect ) && ( battery == max_bat )] holds,
 *
 *     from "INFUSING_BATT" to "INFUSING_BATT" when condition [( infusing ) && ( infusionrate >= vtbi ) && ( kvoflag ) && ( volumeinfused + kvorate <= maxinfuse ) && ( elapsedtime + 1 < maxtime ) && ( battery - 1 > 0 )] holds,
 *
 *     from "INFUSING_MAINS" to "INFUSING_MAINS" when condition [( infusing ) && ( infusionrate >= vtbi ) && ( kvoflag ) && ( volumeinfused + kvorate <= maxinfuse ) && ( elapsedtime + 1 < maxtime ) && ( battery < max_bat )] holds,
 *
 *     from "INFUSING_BATT" to "INFUSING_BATT" when condition [( infusing ) && ( infusionrate >= vtbi ) && ( kvoflag ) && ( volumeinfused + kvorate <= maxinfuse ) && ( elapsedtime + 1 < maxtime ) && ( battery <= 1 )] holds,
 *
 *     from "INFUSING_MAINS" to "INFUSING_MAINS" when condition [( infusing ) && ( infusionrate >= vtbi ) && ( kvoflag ) && ( volumeinfused + kvorate <= maxinfuse ) && ( elapsedtime + 1 < maxtime ) && ( battery == max_bat )] holds,
 *
 *     from "INFUSING_BATT" to "INFUSING_BATT" when condition [( infusing ) && ( infusionrate >= vtbi ) && ( kvoflag ) && ( volumeinfused + kvorate <= maxinfuse ) && ( elapsedtime + 1 == maxtime ) && ( battery - 1 > 0 )] holds,
 *
 *     from "INFUSING_MAINS" to "INFUSING_MAINS" when condition [( infusing ) && ( infusionrate >= vtbi ) && ( kvoflag ) && ( volumeinfused + kvorate <= maxinfuse ) && ( elapsedtime + 1 == maxtime ) && ( battery < max_bat )] holds,
 *
 *     from "INFUSING_BATT" to "INFUSING_BATT" when condition [( infusing ) && ( infusionrate >= vtbi ) && ( kvoflag ) && ( volumeinfused + kvorate <= maxinfuse ) && ( elapsedtime + 1 == maxtime ) && ( battery <= 1 )] holds,
 *
 *     from "INFUSING_MAINS" to "INFUSING_MAINS" when condition [( infusing ) && ( infusionrate >= vtbi ) && ( kvoflag ) && ( volumeinfused + kvorate <= maxinfuse ) && ( elapsedtime + 1 == maxtime ) && ( battery == max_bat )] holds,
 *
 *     from "INFUSING_BATT" to "INFUSING_BATT" when condition [( infusing ) && ( infusionrate >= vtbi ) && ( kvoflag ) && ( volumeinfused + kvorate > maxinfuse ) && ( elapsedtime + 1 < maxtime ) && ( battery - 1 > 0 )] holds,
 *
 *     from "INFUSING_MAINS" to "INFUSING_MAINS" when condition [( infusing ) && ( infusionrate >= vtbi ) && ( kvoflag ) && ( volumeinfused + kvorate > maxinfuse ) && ( elapsedtime + 1 < maxtime ) && ( battery < max_bat )] holds,
 *
 *     from "INFUSING_BATT" to "INFUSING_BATT" when condition [( infusing ) && ( infusionrate >= vtbi ) && ( kvoflag ) && ( volumeinfused + kvorate > maxinfuse ) && ( elapsedtime + 1 < maxtime ) && ( battery <= 1 )] holds,
 *
 *     from "INFUSING_MAINS" to "INFUSING_MAINS" when condition [( infusing ) && ( infusionrate >= vtbi ) && ( kvoflag ) && ( volumeinfused + kvorate > maxinfuse ) && ( elapsedtime + 1 < maxtime ) && ( battery == max_bat )] holds,
 *
 *     from "INFUSING_BATT" to "INFUSING_BATT" when condition [( infusing ) && ( infusionrate >= vtbi ) && ( kvoflag ) && ( volumeinfused + kvorate > maxinfuse ) && ( elapsedtime + 1 == maxtime ) && ( battery - 1 > 0 )] holds,
 *
 *     from "INFUSING_MAINS" to "INFUSING_MAINS" when condition [( infusing ) && ( infusionrate >= vtbi ) && ( kvoflag ) && ( volumeinfused + kvorate > maxinfuse ) && ( elapsedtime + 1 == maxtime ) && ( battery < max_bat )] holds,
 *
 *     from "INFUSING_BATT" to "INFUSING_BATT" when condition [( infusing ) && ( infusionrate >= vtbi ) && ( kvoflag ) && ( volumeinfused + kvorate > maxinfuse ) && ( elapsedtime + 1 == maxtime ) && ( battery <= 1 )] holds,
 *
 *     from "INFUSING_MAINS" to "INFUSING_MAINS" when condition [( infusing ) && ( infusionrate >= vtbi ) && ( kvoflag ) && ( volumeinfused + kvorate > maxinfuse ) && ( elapsedtime + 1 == maxtime ) && ( battery == max_bat )] holds
 *
 *    
 *    \param st state structure pointer
 *    \pre function is called from the right state ("INFUSING_MAINS" or "INFUSING_BATT" )
 *    \post function is moving to the right state ("INFUSING_BATT" or "INFUSING_MAINS" )
 */
JNIEXPORT void JNICALL
Java_com_simulator_giocchi27_alarisgp_MainActivity_invoke_tick(JNIEnv *env,jobject callingObject, jobject obj);

/** Click_DOWN permission function for transition.
 * Use to check if functions can be performed, it controls if the current state is eligible.
 * (i.e., current state is "on")
 *    \param st state structure pointer
 *    \return boolean
 */
JNIEXPORT jboolean JNICALL
Java_com_simulator_giocchi27_alarisgp_MainActivity_invoke_1per_1Click_1DOWN(JNIEnv *env, jobject callingObject, jobject obj);

/** Click_down permission function for transition.
 * Use to check if functions can be performed, it controls if the current state is eligible.
 * (i.e., current state is "on")
 *    \param st state structure pointer
 *    \return boolean
 */
JNIEXPORT jboolean JNICALL
Java_com_simulator_giocchi27_alarisgp_MainActivity_invoke_1per_1Click_1down(JNIEnv *env, jobject callingObject, jobject obj);

/** Click_UP permission function for transition.
 * Use to check if functions can be performed, it controls if the current state is eligible.
 * (i.e., current state is "on")
 *    \param st state structure pointer
 *    \return boolean
 */
JNIEXPORT jboolean JNICALL
Java_com_simulator_giocchi27_alarisgp_MainActivity_invoke_1per_1Click_1UP(JNIEnv *env, jobject callingObject, jobject obj);

/** Click_up permission function for transition.
 * Use to check if functions can be performed, it controls if the current state is eligible.
 * (i.e., current state is "on")
 *    \param st state structure pointer
 *    \return boolean
 */
JNIEXPORT jboolean JNICALL
Java_com_simulator_giocchi27_alarisgp_MainActivity_invoke_1per_1Click_1up(JNIEnv *env, jobject callingObject, jobject obj);

/** Turn_ON permission function for transition.
 * Use to check if functions can be performed, it controls if the current state is eligible.
 * (i.e., current state is "off")
 *    \param st state structure pointer
 *    \return boolean
 */
JNIEXPORT jboolean JNICALL
Java_com_simulator_giocchi27_alarisgp_MainActivity_invoke_1per_1Turn_1ON(JNIEnv *env, jobject callingObject, jobject obj);

/** Turn_OFF permission function for transition.
 * Use to check if functions can be performed, it controls if the current state is eligible.
 * (i.e., current state is "on")
 *    \param st state structure pointer
 *    \return boolean
 */
JNIEXPORT jboolean JNICALL
Java_com_simulator_giocchi27_alarisgp_MainActivity_invoke_1per_1Turn_1OFF(JNIEnv *env, jobject callingObject, jobject obj);

/** pause permission function for transition.
 *  Use to check if functions can be performed, it controls if the current state is eligible.
 *  (i.e., current state is "INFUSING_BATT" or "INFUSING_MAINS")
 *    \param st state structure pointer
 *    \return boolean
 */
JNIEXPORT jboolean JNICALL
Java_com_simulator_giocchi27_alarisgp_MainActivity_invoke_1per_1pause(JNIEnv *env, jobject callingObject, jobject obj);

/** start permission function for transition.
 *  Use to check if functions can be performed, it controls if the current state is eligible.
 *  (i.e., current state is "on")
 *    \param st state structure pointer
 *    \return boolean
 */
JNIEXPORT jboolean JNICALL
Java_com_simulator_giocchi27_alarisgp_MainActivity_invoke_1per_1start(JNIEnv *env, jobject callingObject, jobject obj);

/** tick permission function for transition.
 *  Use to check if functions can be performed, it controls if the current state is eligible.
 *  (i.e., current state is "INFUSING_MAINS" or "INFUSING_BATT")
 *    \param st state structure pointer
 *    \return boolean
 */
JNIEXPORT jboolean JNICALL
Java_com_simulator_giocchi27_alarisgp_MainActivity_invoke_1per_1tick(JNIEnv *env, jobject callingObject, jobject obj);

/** Getter functions.
 *
 *    \return a float
 */
JNIEXPORT jfloat JNICALL
Java_com_simulator_giocchi27_alarisgp_MainActivity_invoke_1GetInfusionrate(JNIEnv *env, jobject callingObject);

JNIEXPORT jfloat JNICALL
Java_com_simulator_giocchi27_alarisgp_MainActivity_invoke_1GetVTBI(JNIEnv *env, jobject callingObject);

JNIEXPORT jfloat JNICALL
Java_com_simulator_giocchi27_alarisgp_MainActivity_invoke_1GetVolumeinfused(JNIEnv *env, jobject callingObject);

JNIEXPORT jfloat JNICALL
Java_com_simulator_giocchi27_alarisgp_MainActivity_invoke_1GetTime(JNIEnv *env, jobject callingObject);

JNIEXPORT jfloat JNICALL
Java_com_simulator_giocchi27_alarisgp_MainActivity_invoke_1GetElapsedtime(JNIEnv *env, jobject callingObject);

JNIEXPORT void JNICALL
Java_com_simulator_giocchi27_alarisgp_MainActivity_invoke_1SetVTBI(JNIEnv* env, jobject callingObject, jfloat ji);


/** ---------------------------------------------------------------
*   C code generated using PVSio-web MisraCPrinter ver 0.1
*   Tool freely available at http://www.pvsioweb.org
*  --------------------------------------------------------------*/
