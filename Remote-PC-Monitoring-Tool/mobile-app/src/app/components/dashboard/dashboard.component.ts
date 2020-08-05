import { Component, OnInit } from '@angular/core';

import { DataService } from 'services/data.service';
import { SensorData } from 'interfaces/data.interface';


@Component({
    selector: 'dashboard',
    templateUrl: './dashboard.component.html',
    styleUrls: ['./dashboard.component.scss']
})
export class DashboardComponent implements OnInit {
    private data: SensorData;

    public constructor(private dataService: DataService) {

    }

    public ngOnInit(): void {
        this.getData();
    }

    private async getData(): Promise<void> {
        console.log('end result:', await this.dataService.getData());
    }
}