import { NgModule, NO_ERRORS_SCHEMA } from '@angular/core';
import { NativeScriptModule } from '@nativescript/angular';

import { AppRoutingModule } from './app-routing.module';
import { AppComponent } from './app.component';
import { DashboardComponent } from 'components/dashboard/dashboard.component';

import { Services } from 'services/services.module';


@NgModule({
    bootstrap: [
        AppComponent
    ],
    imports: [
        NativeScriptModule,
        AppRoutingModule,

        Services.forRoot(),
    ],
    declarations: [
        AppComponent,
        DashboardComponent
    ],
    providers: [],
    schemas: [
        NO_ERRORS_SCHEMA
    ]
})
export class AppModule { }