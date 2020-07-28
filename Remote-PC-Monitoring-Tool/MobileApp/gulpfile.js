const gulp_util = require('gulp-util');
const through2 = require('through2');
const fs = require('fs');
const path = require('path');

const gulp = require('gulp');
const gulp_typescript = require('gulp-typescript');
const gulp_sourcemaps = require('gulp-sourcemaps');
const typescript = require('typescript');

const args = require('yargs').argv;
const showLogs = args.logs;


// turn all relative paths into absolute paths
gulp.task('transpilePaths', (done) => {
    const baseLog = (message, data) => {
        if (showLogs) {
            if (message == '\n') {
                console.log('');
            } else {
                const hasFunctionName = message[0] == '[' && message.indexOf(']') != -1;
                const functionName = hasFunctionName ? message.substring(0, message.indexOf(']') + 1) : '';
                const messageText = hasFunctionName ? message.substring(message.indexOf(']') + 2) : message;

                const dataText = (() => {
                    switch (typeof data) {
                        case 'string': return gulp_util.colors.yellow(data);
                        case 'number': return gulp_util.colors.green(data);
                        case 'boolean': return gulp_util.colors.cyan(data);
                        case 'undefined': return '';
                        default: return data;
                    }
                })();

                gulp_util.log(gulp_util.colors.magenta(functionName) + ' ' + messageText, dataText);
            }
        }
    };

    const tsProject = gulp_typescript.createProject('tsconfig.json', { typescript: typescript });

    const tsImport = (importOptions) => {
        const log = (message, data) => {
            baseLog('[tsimport] ' + message, data);
        };

        log('tsImport');
        log('importOptions:', importOptions);

        return through2.obj(function (file, encoding, cb) {
            let code = file.contents.toString('utf8');
            code = replacePath(code, file.history.toString(), importOptions);
            file.contents = Buffer.from(code);
            this.push(file);
            cb();
        });
    };

    const replacePath = (code, filePath, importOptions) => {
        const rootPath = importOptions.baseUrl;
        const targetPaths = importOptions.paths;
        const log = (message, data) => {
            if (message == '\n') {
                baseLog(message);
            } else {
                baseLog('[replacePath] ' + message, data);
            }
        };

        log('\n');
        log('filePath:', filePath);
        log('rootPath:', rootPath);
        log('targetPaths:', targetPaths);

        const tscPaths = Object.keys(targetPaths);
        const lines = code.split('\n');

        const replacedLines = lines.map((line) => {
            const requireStatements = line.match(/require\(('|")(.*)('|")\)/g);

            if (requireStatements && requireStatements.length > 0) {
                const requireStatement = requireStatements[0];

                log('old line:', line);
                log('requireStatement:', requireStatement);

                const requirePath = requireStatement.substring(requireStatement.indexOf('"') + 1, requireStatement.lastIndexOf('"'));
                log('requirePath', requirePath);

                let foundMatch = false;

                for (const tscPath of tscPaths) {
                    log('tscPath:', tscPath);

                    const requiredModules = requirePath.match(new RegExp('^' + tscPath, 'g'));

                    if (requiredModules && requiredModules.length > 0) {
                        for (const requiredModule of requiredModules) {
                            log('requiredModule:', requiredModule);
                            let modulePath = path.resolve('./node_modules/' + tscPath);
                            log('modulePath:', modulePath);

                            if (modulePath.endsWith('*')) {
                                modulePath = modulePath.substring(0, modulePath.length - 1);
                            }

                            const modulePathIsInNodeModules = fs.existsSync(modulePath);
                            log('modulePathIsInNodeModules:', modulePathIsInNodeModules);

                            if (!modulePathIsInNodeModules) {
                                const sourcePath = path.dirname(filePath).replace(/\\/g, '/');
                                log('sourcePath:', sourcePath);
                                const targetPath = path.dirname(path.resolve(rootPath + '/' + targetPaths[tscPath])).replace(/\\/g, '/');
                                log('targetPath:', targetPath);
                                const relativePath = path.relative(sourcePath, targetPath).replace(/\\/g, '/');
                                log('relativePath:', relativePath);
                                const firstPart = line.substring(0, line.indexOf('require("') + 9);
                                log('firstPart:', firstPart);
                                const oldPath = line.substring(firstPart.length);
                                log('oldPath:', oldPath);
                                const reqModWithoutSlash = requiredModule.substring(0, requiredModule.length - 1);
                                log('reqModWithoutSlash:', reqModWithoutSlash);
                                const newPath = oldPath.substring(oldPath.indexOf(reqModWithoutSlash) + requiredModule.length, oldPath.indexOf('\"'));
                                log('newPath:', newPath);
                                const replacedPath = (relativePath + '/' + newPath).replace(/src/g, importOptions.outDir);
                                log('replacedPath:', replacedPath);
                                const newLine = firstPart + replacedPath + '\"' + ')'.repeat(firstPart.split('(').length - 1) + ';';
                                log('newLine:', newLine);

                                line = newLine;
                                foundMatch = true;
                                break;
                            }
                        }
                    }

                    if (foundMatch) {
                        break;
                    }
                }

                if (!foundMatch) {
                    log('no matches found');
                }
            }

            return line;
        }).join('\n');

        return replacedLines;
    };

    tsProject.src()
        .pipe(gulp_sourcemaps.init())
        .pipe(tsProject())
        .on('error', function (error) {
            console.log(gulp_util.colors.red(error.message));
            baseLog('\n');
            this.emit('end');
        })
        .pipe(tsImport(tsProject.config.compilerOptions))
        .on('error', function (error) {
            console.log(gulp_util.colors.red('Error transpiling import paths:'), error.stack);
            baseLog('\n');
            this.emit('end');
        })
        .pipe(gulp_sourcemaps.write())
        .pipe(gulp.dest('dist'))
        .on('end', done);

    baseLog('\n');
    done();
});