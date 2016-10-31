#include "WVPIDController.h"

WVPIDController::WVPIDController(double _Kp, double _Ki, double _Kd,
                                 double _setPoint, bool _integralThreshold)
    : lastPWM(0), error(0), Kp(_Kp), Ki(_Ki), Kd(_Kd),
      setPoint(_setPoint), integralThreshold(_integralThreshold),
      previousError(0.0), integral(0.0)
{
}

double WVPIDController::Tick(double measuredValue)
{
    error = setPoint - measuredValue;
    if(integralThreshold)
    {
        if(error <= .1)
            integral += error;
    }
    else
        integral += error;
    double derivative = error - previousError;
    previousError = error;

    lastPWM = Kp * error + Ki * integral + Kd * derivative;

    return lastPWM;
}

////////////////////////////////////////////////////////////
//  Setters
////////////////////////////////////////////////////////////

void WVPIDController::setSetPoint(double setPoint)
{
    setPoint = setPoint;
    integral = 0;
    previousError = 0;
    error = 0;
}

void WVPIDController::setKp(double _Kp)
{
    Kp = _Kp;
}

void WVPIDController::setKi(double _Ki)
{
    Ki = _Ki;
}

void WVPIDController::setKd(double _Kd)
{
    Kd = _Kd;
}

////////////////////////////////////////////////////////////
//  Getters
////////////////////////////////////////////////////////////

double WVPIDController::getKp()
{
    return Kp;
}

double WVPIDController::getKi()
{
    return Ki;
}

double WVPIDController::getKd()
{
    return Kd;
}

double WVPIDController::getSetPoint()
{
    return setPoint;
}

double WVPIDController::getError()
{
    return error;
}

double WVPIDController::getLastPWM()
{
    return lastPWM;
}
