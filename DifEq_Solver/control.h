    #pragma once
    //Функции Управляющих воздействий
    double control_none(double t);
    double control_sin(double t);
    double control_ln(double t);
    double control_exp(double t);
    double control_heavyside(double t);

    //перечисление видов управляющего воздействия
    enum Control {NONE, SIN, LN, EXP, HS};