'use strict';

module.exports = function (grunt) {

    grunt.initConfig({
        pkg: grunt.file.readJSON('package.json'),

        // Watch for changes and trigger compass, jshint, uglify and livereload
        watch: {
            compass: {
                files: ['sass/{,**/}*.scss'],
                tasks: ['compass:dev']
            },
            livereload: {
                options: {
                    livereload: true
                },
                files: [
                    'css/*.css',
                    'js/*.js',
                    'images/{,**/}*.{png,jpg,jpeg,gif,webp,svg}'
                ]
            }
        },


        // Compass and scss
        compass: {
          options: {
            httpPath: '/sites/all/themes/qma',
            cssDir: 'css',
            sassDir: 'sass',
            imagesDir: 'images',
            assetCacheBuster: 'none',
            require: [
              'susy'
            ]
          },
          dev: {
            options: {
              environment: 'development',
              outputStyle: 'expanded',
              relativeAssets: true,
              raw: 'line_numbers = :true\nline_comments = :true\n'
            }
          },
          dist: {
            options: {
              environment: 'production',
              outputStyle: 'compact',
              force: true
            }
          }
        },

    });

    grunt.loadNpmTasks('grunt-contrib-watch');
    grunt.loadNpmTasks('grunt-contrib-jshint');
    grunt.loadNpmTasks('grunt-contrib-compass');

    grunt.registerTask('build', [
//        'jshint',
        'compass:dist'
    ]);

    grunt.registerTask('default', [
//        'jshint',
        'compass:dev',
        'watch'
    ]);

};