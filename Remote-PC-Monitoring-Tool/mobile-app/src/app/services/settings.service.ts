import { Injectable } from '@angular/core';
import { NetworkSettings } from 'interfaces/settings.interface';


@Injectable()
export class SettingsService {
    private _networkSettings: NetworkSettings = {
        host: null,
        port: 1234
    };
    public get networkSettings(): NetworkSettings {
        return this._networkSettings;
    }


    public constructor() {

    }

    public setIPAddress(ipAddress: string): void {
        this._networkSettings.host = ipAddress;
    }

    public setPort(port: number): void {
        this._networkSettings.port = port;
    }
}