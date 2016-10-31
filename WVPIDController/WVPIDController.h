#ifndef PIDCONTROLLER_H
#define PIDCONTROLLER_H

class WVPIDController
{
    public:
        WVPIDController(double _Kp, double _Ki, double _Kd, double _setPoint,
                        bool _integralThreshold);

        double Tick(double measuredValue);

        void setSetPoint(double setPoint);
        void setKp(double _Kp);
        void setKi(double _Ki);
        void setKd(double _Kd);

        double getSetPoint();
        double getKp();
        double getKi();
        double getKd();

        double getError();
        double getLastPWM();

    private:
        bool integralThreshold;

        double Kp;
        double Ki;
        double Kd;

        double setPoint;
        double error;
        double previousError;
        double integral;
        double lastPWM;
};

#endif
