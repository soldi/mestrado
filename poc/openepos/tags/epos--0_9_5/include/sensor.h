// EPOS-- Sensor Mediator Common Package

#ifndef __sensor_h
#define __sensor_h

#include <system/config.h>

__BEGIN_SYS

class Sensor_Common
{
protected:
    Sensor_Common() {}
};

class Temperature_Sensor_Common: public Sensor_Common
{


    class Temperature_Sensor_Base
    {
    public:
	Temperature_Sensor_Base(unsigned int unit = 0) {}

	virtual ~Temperature_Sensor_Base() {}

	virtual int sample() = 0;

	virtual int get() = 0;

	virtual bool enable() = 0;

	virtual void disable() = 0;

	virtual bool data_ready() = 0;

    
    };
    template<typename Temperature_Sensor, bool polymorphic>
    class Temperature_Sensor_Wrapper: public Temperature_Sensor_Base, private Temperature_Sensor
    {
    public:

	Temperature_Sensor_Wrapper(unsigned int unit = 0) : Temperature_Sensor(unit) {}

	virtual ~Temperature_Sensor_Wrapper() {}

	virtual int sample() {
	    return Temperature_Sensor::sample();
	}

	virtual int get() {
	    return Temperature_Sensor::get();
	}

	virtual bool enable() {
	    return Temperature_Sensor::enable();
	}

	virtual void disable() {
	    Temperature_Sensor::disable();
	}

	virtual bool data_ready() {
	    return Temperature_Sensor::data_ready();
	}

    };
    template<typename Temperature_Sensor>
    class Temperature_Sensor_Wrapper<Temperature_Sensor, false>: public Temperature_Sensor
    {
    public:
	Temperature_Sensor_Wrapper(unsigned int unit = 0) : Temperature_Sensor(unit) {}
    };

    template<typename Temperature_Sensors>
    class Meta_Temperature_Sensor
    {
    private:
	static const bool polymorphic = Temperature_Sensors::Polymorphic;

    public:
	typedef 	
	typename IF<polymorphic,
		    Temperature_Sensor_Base, 
		    typename Temperature_Sensors::template Get<0>::Result>::Result Base;

	template<int Index>
	struct Get
	{ 
	    typedef
	    Temperature_Sensor_Wrapper<typename Temperature_Sensors::template Get<Index>::Result,
				       polymorphic> Result;
	};
    };



};


class Photo_Sensor_Common: public Sensor_Common
{

    class Photo_Sensor_Base
    {
    public:
	Photo_Sensor_Base(unsigned int unit = 0) {}

	virtual ~Photo_Sensor_Base() {}

	virtual int sample() = 0;

	virtual int get() = 0;

	virtual bool enable() = 0;

	virtual void disable() = 0;

	virtual bool data_ready() = 0;
    
    };
    template<typename Photo_Sensor, bool polymorphic>
    class Photo_Sensor_Wrapper: public Photo_Sensor_Base, private Photo_Sensor
    {
    public:

	Photo_Sensor_Wrapper(unsigned int unit = 0) : Photo_Sensor(unit) {}

	virtual ~Photo_Sensor_Wrapper() {}

	virtual int sample() {
	    return Photo_Sensor::sample();
	}

	virtual int get() {
	    return Photo_Sensor::get();
	}

	virtual bool enable() {
	    return Photo_Sensor::enable();
	}

	virtual void disable() {
	    Photo_Sensor::disable();
	}

	virtual bool data_ready() {
	    return Photo_Sensor::data_ready();
	}

    };
    template<typename Photo_Sensor>
    class Photo_Sensor_Wrapper<Photo_Sensor, false>: public Photo_Sensor
    {
    public:
	Photo_Sensor_Wrapper(unsigned int unit = 0) : Photo_Sensor(unit) {}
    };

    template<typename Photo_Sensors>
    class Meta_Photo_Sensor
    {
    private:
	static const bool polymorphic = Photo_Sensors::Polymorphic;

    public:
	typedef 	
	typename IF<polymorphic,
		    Photo_Sensor_Base, 
		    typename Photo_Sensors::template Get<0>::Result>::Result Base;

	template<int Index>
	struct Get
	{ 
	    typedef
	    Photo_Sensor_Wrapper<typename Photo_Sensors::template Get<Index>::Result,
				       polymorphic> Result;
	};
    };



};

class Accelerometer_Common: public Sensor_Common
{

    class Accelerometer_Base
    {
    public:
	Accelerometer_Base(unsigned int unit = 0) {}

	virtual ~Accelerometer_Base() {}

	virtual int sample_x() = 0;

	virtual int get_x() = 0;

	virtual bool enable_x() = 0;

	virtual void disable_x() = 0;

	virtual bool data_ready_x() = 0;

	virtual int sample_y() = 0;

	virtual int get_y() = 0;

	virtual bool enable_y() = 0;

	virtual void disable_y() = 0;

	virtual bool data_ready_y() = 0;
    
    };
    template<typename Accelerometer, bool polymorphic>
    class Accelerometer_Wrapper: public Accelerometer_Base, private Accelerometer
    {
    public:

	Accelerometer_Wrapper(unsigned int unit = 0) : Accelerometer(unit) {}

	virtual ~Accelerometer_Wrapper() {}

	virtual int sample_x() {
	    return Accelerometer::sample_x();
	}

	virtual int get_x() {
	    return Accelerometer::get_x();
	}

	virtual bool enable_x() {
	    return Accelerometer::enable_x();
	}

	virtual void disable_x() {
	    Accelerometer::disable_x();
	}

	virtual bool data_ready_x() {
	    return Accelerometer::data_ready_x();
	}

	virtual int sample_y() {
	    return Accelerometer::sample_y();
	}

	virtual int get_y() {
	    return Accelerometer::get_y();
	}

	virtual bool enable_y() {
	    return Accelerometer::enable_y();
	}

	virtual void disable_y() {
	    Accelerometer::disable_y();
	}

	virtual bool data_ready_y() {
	    return Accelerometer::data_ready_y();
	}

    };
    template<typename Accelerometer>
    class Accelerometer_Wrapper<Accelerometer, false>: public Accelerometer
    {
    public:
	Accelerometer_Wrapper(unsigned int unit = 0) : Accelerometer(unit) {}
    };

    template<typename Accelerometers>
    class Meta_Accelerometer
    {
    private:
	static const bool polymorphic = Accelerometers::Polymorphic;

    public:
	typedef 	
	typename IF<polymorphic,
		    Accelerometer_Base, 
		    typename Accelerometers::template Get<0>::Result>::Result Base;

	template<int Index>
	struct Get
	{ 
	    typedef
	    Accelerometer_Wrapper<typename Accelerometers::template Get<Index>::Result,
				       polymorphic> Result;
	};
    };



};


/*

class Descriptor {

    enum SENSOR_TYPE {
	ACCELEROMETER,
	MICROPHONE,
	THERMISTOR,
	TEMPERATURE,
	MAGNETOMETER,
    };

    enum PRECISION {
	INT,
	LONG,
	FLOAT,
	DOUBLE,
    }

    enum PHYSICAL_UNIT {
	METERS_PER_SECOND_SQ,
	GEES,
	DEGREES_CENTIGRATE,
	DEGREES_KELVIN,
	DEGREES_FAHRENHEIT,
    };

};

class Accelerometer_Descriptor {

    int type();
    int precision();
    int physical_unit();

    int sensitivity_x();
    int sensitivity_y();
    int sensitivity_z();
    
    int frequency();

    struct Calibration;
    
};

*/



__END_SYS

#ifdef __SENSOR_H
#include __SENSOR_H
#endif

#endif
