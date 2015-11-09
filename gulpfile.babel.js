const gulp = require('gulp')
const path = require('path')
const fs = require('fs')
require('babel-polyfill')

// promised wrapper
function exec(cmd) {
  const exec = require('child_process').exec
  const promise = new Promise((resolve, reject)=> {
    exec(cmd, (stderr, stdout)=> {
      if (stderr) {
        reject(stderr)
      } else {
        resolve(stdout)
      }
    })
  })
  return promise
}

gulp.task('watch', ()=> {
  gulp.watch('src/**/*.js').on('change', (file)=> {
    // paths
    const input     = path.join(path.dirname(file.path), 'input.txt')
    const output    = path.join(path.dirname(file.path), 'output.txt')
    const expected  = path.join(path.dirname(file.path), 'expected.txt')

    // run
    exec(`timeout 5 node ${file.path} < ${input} > ${output}`).then(()=> {
      exec(`diff ${expected} ${output}`).then((stdout)=> {
        console.log('passed')
      }).catch((stderr)=> {
        console.log('failed')
        console.log(stderr.toString())
        console.log(fs.readFileSync(output).toString());
      })
    }).catch((stderr)=> {
      console.log(stderr.toString())
    })
  })
})
