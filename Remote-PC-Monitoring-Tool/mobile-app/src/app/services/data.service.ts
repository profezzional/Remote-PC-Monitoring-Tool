import { Injectable } from '@angular/core';
import { request as HttpRequest, HttpResponse } from 'tns-core-modules/http';

import { SensorData, DataResponse } from 'interfaces/data.interface';
import { SettingsService } from 'services/settings.service';


@Injectable()
export class DataService {
    public constructor(private settingsService: SettingsService) {

    }

    public async getData(): Promise<DataResponse> {
        const host: string = this.settingsService.networkSettings.host || (org as any).broadcast.GetBroadcast.getBroadcast();
        const url: string = `http://${host}${this.settingsService.networkSettings.port ? ':' + this.settingsService.networkSettings.port : ''}/sensors`;
        const response: HttpResponse = await HttpRequest({ url, method: 'GET' });

        return response.statusCode === 200 ? { data: (response.content.toJSON() as SensorData), error: null } : { data: null, error: response.content.toString() };
    }
}