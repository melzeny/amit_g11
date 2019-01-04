/*
 * SevSegments_config.h
 *
 * Created: 10/19/2018 7:01:41 PM
 *  Author: MuhammadElzeiny
 */ 


#ifndef SEVSEGMENTS_CONFIG_H_
#define SEVSEGMENTS_CONFIG_H_

/*
* choose between	SEVSEGMENTS_COMMON_CATHOD
*					SEVSEGMENTS_COMMON_ANOD
*/

#define SEVSEGMENTS_COMMON_TYPE			SEVSEGMENTS_COMMON_CATHOD

/*
*	Choos PinNumber
*/
#define SEVSEGMENTS_COMMON_PIN			DIO_PIN_A7

/*
*	Choos PortNo
*/
#define SEVSEGMENTS_ATTACHED_PORT		DIO_PORT_B

#endif /* SEVSEGMENTS_CONFIG_H_ */
