#pragma XOD evaluate_on_pin disable
#pragma XOD evaluate_on_pin enable input_UPD

node {    
    void evaluate(Context ctx) {
        // The node responds only if there is an input pulse
        if (!isInputDirty<input_UPD>(ctx))
            return;

        auto sensor = getValue<input_DEV>(ctx);
        Number EIDA = sensor->getEIDA();
        Number EIDB = sensor->getEIDB();
        emitValue<output_EIDA>(ctx, EIDA);
        emitValue<output_EIDB>(ctx, EIDB);
        emitValue<output_Done>(ctx, 1);
    }
}
