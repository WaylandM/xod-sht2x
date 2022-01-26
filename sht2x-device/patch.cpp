// Tell XOD where it can download the libraries:
#pragma XOD require "https://github.com/RobTillaart/SHT2x"

//Include C++ libraries
#include <Wire.h>
#include <SHT2x.h>

node {

    meta {
        // Define our custom type as a pointer on the class instance.
        using Type = SHT2x*;
    }

    // Create an object of class SHT2x
    SHT2x sensor = SHT2x();

    void evaluate(Context ctx) {
        // It should be evaluated only once on the first (setup) transaction
        if (!isSettingUp())
            return;

        auto wire = getValue<input_I2C>(ctx);

        // Try to initialize sensor
        if (!sensor.begin(wire)) {
            raiseError(ctx);
            return;
        }
        emitValue<output_DEV>(ctx, &sensor);
    }
}
