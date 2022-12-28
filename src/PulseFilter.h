#ifndef PulseFilter_h
#define PulseFilter_h

//--------- Constants --------

#define N_SAMPLE 		25			// Samples used to calculate average
#define DEFAULT_BAND	4			// Error range of deadband filter. Changes in signal within this band are ignored.

//---------- Class -----------

template<volatile uint16_t* input, int BAND = DEFAULT_BAND> 	
class PulseFilter {
  private:
    uint16_t mean=0;
    int filter=0; 
  
  public:
	/* input average */
    void calibrate() {
      uint32_t sum = 0;
      for( int count = 0; count < N_SAMPLE; count += 1 ) {
        sum += (*input);
        delay(20);			// period of 50hz pwm signal    
      }
      // store truncated mean
      float f_mean = float(sum)/float(N_SAMPLE);
      mean = uint16_t(f_mean);
    }

	/* update and return output */
    int update() {
      int value = int(*input) - int(mean); 
      // deadband 
      int change = value - filter;
      if( change > BAND ) {
        filter += change - BAND;
      } else if ( change < -BAND ) {
        filter += change + BAND;
      }
      return filter;
    }
};

//------- Clear labels -------

#undef N_SAMPLE
#undef DEFAULT_BAND

#endif
