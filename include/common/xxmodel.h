/**********************************************************
 * This file is generated by 20-sim ANSI-C Code Generator
 *
 *  file:  common\xxmodel.h
 *  subm:  SequencePan
 *  model: SequencePan
 *  expmt: Jiwy-with-controller
 *  date:  April 6, 2023
 *  time:  2:12:46 PM
 *  user:  20-sim 5.0 Student License
 *  from:  Universiteit Twente
 *  build: 5.0.2.12127
 **********************************************************/

#ifndef SUBMODEL20SIM_H
#define SUBMODEL20SIM_H

#include "xxtypes.h"
#include "xxmatrix.h"


class Submodel20sim
{
	protected:
		friend class IntegrationMethod;
		friend class Discrete;
		friend class Euler;
		friend class RungeKutta2;
		friend class RungeKutta4;
		virtual void CalculateDynamic (void) {};

		bool m_initialize;
		bool m_major;
		bool m_stop_run;
		XXDouble m_step_size;
		XXDouble m_start_time;
		XXDouble m_finish_time;
		XXDouble m_time;

	public:
		virtual ~Submodel20sim(){};
		
		XXDouble GetStepSize(void) { return m_time; };
		XXDouble GetStartTime(void) { return m_start_time; };
		XXDouble GetFinishTime(void) { return m_finish_time; };
		XXDouble GetTime(void) { return m_time; };

		/* the variable count */
		int m_number_constants;
		int m_number_parameters;
		int m_number_initialvalues;
		int m_number_variables;
		int m_number_states;
		int m_number_rates;
		int m_number_matrices;
		int m_number_unnamed;

		/* the variable arrays are allocated in the derived submodel class */
		XXDouble* m_C;					/* constants */
		XXDouble* m_P;					/* parameters */
		XXDouble* m_I;				/* initial values */
		XXDouble* m_V;					/* variables */
		XXDouble* m_s;						/* states */
		XXDouble* m_R;						/* rates (or new states) */
		XXMatrix* m_M;					/* matrices */
		XXDouble* m_U;					/* unnamed */
		XXDouble* m_workarray;
};

#endif 	/* SUBMODEL20SIM_H */
