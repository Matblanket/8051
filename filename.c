#include <8051.h>

sbit START_BUTTON = P3^0;
sbit STOP_BUTTON = P3^2;
sbit OUTPUT_PIN[] = {P1^0, P1^2, P2^7, P3^1, P2^6};
sbit RESPONSE_PIN[] = {P2^0, P2^1, P2^2, P2^3, P2^4};

#define TOTAL_OUTPUTS 5
unsigned int outputTimes[TOTAL_OUTPUTS] = {10000, 17000, 30000, 32000, 40000};
unsigned int responseTimes[TOTAL_OUTPUTS] = {1000, 12000, 1000, 3000, 1000};

void generateOutput(int index);
void abortLowering(void);

void main() {
    unsigned int elapsedTime = 0;
    unsigned int responseTime = 0;

    while (1) {
        if (START_BUTTON == 0) {
            for (int i = 0; i < TOTAL_OUTPUTS; i++) {
                generateOutput(i);

                if (STOP_BUTTON == 0) {
                    abortLowering();
                    break;
                }

                RESPONSE_PIN[i] = 1;

                responseTime = 0;
                while (responseTime < responseTimes[i]) {
                    if (STOP_BUTTON == 0) {
                        abortLowering();
                        break;
                    }

                    for (int delay = 0; delay < 1000; delay++) {
                        // Formula ne calculate kar
                    }

                    responseTime++;
                }

                RESPONSE_PIN[i] = 0;

                if (STOP_BUTTON == 0) {
                    abortLowering();
                    break;
                }
            }
        }
    }
}

void generateOutput(int index) {
    OUTPUT_PIN[index] = 1;

    unsigned int startTime = 0;
    while (startTime < outputTimes[index]) {
        for (int delay = 0; delay < 1000; delay++) {
            // Formula ne calculate kar 
        }

        startTime++;
    }

    OUTPUT_PIN[index] = 0;
}

void abortLowering(void) {
   // ABORT ABORT
}