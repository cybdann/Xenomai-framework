/**********************************************************
 * This file is generated by the 20-sim C++ Code Generator
 *
 *  file:  SequencePan.h
 *  subm:  SequencePan
 *  model: SequencePan
 *  expmt: Jiwy-with-controller
 *  date:  April 6, 2023
 *  time:  2:12:46 PM
 *  user:  20-sim 5.0 Student License
 *  from:  Universiteit Twente
 *  build: 5.0.2.12127
 *
 **********************************************************/

/* This file describes the model functions
   that are supplied for computation.

   The model itself is the SequencePan.cpp file
*/
#ifndef SequencePan_H
#define SequencePan_H

/* 20-sim include files */
#include "common/xxfuncs.h"
#include "common/xxmatrix.h"
#include "common/xxmodel.h"
#include "common/xxinteg.h"


class SequencePan: virtual public Submodel20sim
{
	public:
		enum stateflags_SequencePan {initialrun, mainrun, finished};

		/**
		 * SequencePan constructor
		 */
		SequencePan(void);

		/**
		 * SequencePan destructor
		 */
		virtual ~SequencePan(void);

		/**
		 * SequencePan Initialization of the model and calculation of the values for the start time t
		 * @param u	This is the array with all input signals for this submodel
		 * @param y	This is the array with all output signals from this submodel
		 * @param t This is the start time for this run
		 */
		void Initialize (XXDouble *u, XXDouble *y, XXDouble t);

		/**
		 * SequencePan Calculate
		 * @param u	This is the array with all input signals for this submodel
		 * @param y	This is the array with all output signals from this submodel
		 */
		void Calculate (XXDouble *u, XXDouble *y /*, XXDouble t*/ );

		/**
		 * SequencePan Terminate
		 * @param u	This is the array with all input signals for this submodel
		 * @param y	This is the array with all output signals from this submodel
		 */
		void Terminate (XXDouble *u, XXDouble *y /*, XXDouble t*/ );


		/**
		 * SetFinishTime()
		 * @brief Overrrides the default finish time (from 20-sim) for this submodel
		 * @param time is the wanted finish time. Use 0.0 to change it to infinite.
		 * 
		 */
		bool SetFinishTime(XXDouble newtime);

		bool IsFinished(void);
		/**
		 * Reset()
		 * @brief Resets the submodel back to its initial state for a new run
		 */
		void Reset(XXDouble starttime);

		stateflags_SequencePan state;

	protected:
		/**
		 * CalculateDynamic()
		 * This function calculates the dynamic equations of the model.
		 * These equations are called from the integration method
		 * to calculate the new model rates (that are then integrated).
		 */
		void CalculateDynamic (void);

	private:
		/* internal submodel computation methods */

		/**
		 * CalculateInitial()
		 * This function calculates the initial equations of the model.
		 * These equations are calculated before anything else
		 */
		void CalculateInitial (void);

		/**
		 * CalculateStatic()
		 * This function calculates the static equations of the model.
		 * These equations are only dependent from parameters and constants
		 */
		void CalculateStatic (void);

		/**
		 * CalculateInput()
		 * This function calculates the input equations of the model.
		 * These equations are dynamic equations that must not change
		 * in calls from the integration method (like random and delay).
		 */
		void CalculateInput (void);

		/**
		 * CalculateOutput()
		 * This function calculates the output equations of the model.
		 * These equations are not needed for calculation of the rates
		 * and are kept separate to make the dynamic set of equations smaller.
		 * These dynamic equations are called often more than one time for each
		 * integration step that is taken. This makes model computation much faster.
		 */
		void CalculateOutput (void);

		/**
		 * CalculateFinal()
		 * This function calculates the final equations of the model.
		 * These equations are calculated after all the calculations
		 * are performed
		 */
		void CalculateFinal (void);

		/**
		 * CopyInputsToVariables
		 * This private function copies the input variables from the input vector
		 * @param u	This is the array with all input signals for this submodel
		 */
		void CopyInputsToVariables (XXDouble *u);

		/**
		 * CopyVariablesToOutputs
		 * This private function copies the output variables to the output vector
		 * @param y	This is the array with all output signals from this submodel
		 */
		void CopyVariablesToOutputs (XXDouble *y);

		static const size_t m_timeevent_size = 2;
		XXDouble m_time_event[m_timeevent_size];

		/**
		 * XXTimeEvent
		 * This private function implements the 20-sim timeevent function behavior
		 * @param argument The time value to use as reference
		 * @param id The unique identifier for this event
		 */
		XXBoolean XXTimeEvent (XXDouble argument, XXInteger id);

		Euler myintegmethod;	///< pointer to the integration method for this submodel
};

#endif	/* SequencePan_H */

