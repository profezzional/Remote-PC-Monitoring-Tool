export type ComponentName = 'cpu' | 'memory';
export type DataPointName = 'usage' | 'temp' | 'speed';


/** Defines a data unit, like Celsius (degrees). */
export type DataUnit = {
    abbreviation: string;
    name: string;
    units: string;
};

export type DataPoint = {
    name: string;
    value: number;
    unit: DataUnit;
};

export type ComponentData = {
    [dataPointName in DataPointName]: DataPoint;
};

/** Format of data coming back from server. */
export type DataResponse = {
    [componentName in ComponentName]: ComponentData;
};