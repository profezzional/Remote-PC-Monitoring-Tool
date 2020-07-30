import { DataResponse } from 'interfaces/data.interface';


export class DataService {
    public constructor() {

    }

    public async getData(): Promise<DataResponse> {
        return {
            cpu: {
                usage: {
                    name: 'CPU Usage',
                    value: 0.5,
                    unit: {
                        name: 'Percentage',
                        abbreviation: '%',
                        units: 'Percent'
                    }
                },
                speed: {
                    name: 'CPU Frequency',
                    value: 5.1,
                    unit: {
                        name: 'Gigahertz',
                        abbreviation: 'GHz',
                        units: 'Gigahertz'
                    }
                },
                temp: {
                    name: 'CPU Temperature',
                    value: 65,
                    unit: {
                        name: 'Celsius',
                        abbreviation: 'C',
                        units: 'Degrees'
                    }
                }
            },
            memory: {
                usage: {
                    name: 'Memory Usage',
                    value: 0.37,
                    unit: {
                        name: 'Percentage',
                        abbreviation: '%',
                        units: 'Percent'
                    }
                },
                speed: {
                    name: 'Memory Frequency',
                    value: 3.385,
                    unit: {
                        name: 'Gigahertz',
                        abbreviation: 'GHz',
                        units: 'Gigahertz'
                    }
                },
                temp: {
                    name: 'Memory Temperature',
                    value: 50.5,
                    unit: {
                        name: 'Celsius',
                        abbreviation: 'C',
                        units: 'Degrees'
                    }
                }
            },
        };
    }
}