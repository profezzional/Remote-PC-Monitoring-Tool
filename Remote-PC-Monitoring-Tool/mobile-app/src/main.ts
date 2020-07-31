import { platformNativeScriptDynamic } from '@nativescript/angular/platform'; // this import should be first in order to load some required settings (like globals and reflect-metadata)

import { AppModule } from './app/app.module';

/** Link to Java code written in {projectDir}/platforms/android/app/src/main/java/org. Usage: org.[sub-package].[class name].[method](...args) */
declare var org: any;

platformNativeScriptDynamic().bootstrapModule(AppModule);