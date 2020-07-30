import { Component, OnInit } from '@angular/core';

import { DataService } from 'services/data.service';
import { DataResponse } from '../../interfaces/data.interface';


@Component({
    selector: 'dashboard',
    templateUrl: './dashboard.component.html',
    styleUrls: ['./dashboard.component.scss']
})
export class DashboardComponent implements OnInit {
    private data: string;

    public constructor(private dataService: DataService) {

    }

    public ngOnInit(): void {
        this.dataService.getData().then(dataResponse => this.data = JSON.stringify(dataResponse));
    }
}