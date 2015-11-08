const gulp = require('gulp')
const path = require('path')

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
  // TODO: watch main.js input.txt expected.txt
  gulp.watch('src/**/*.js').on('change', (file)=> {
    const input = path.join(path.dirname(file.path), 'input.txt')
    const output = path.join(path.dirname(file.path), 'output.txt')
    const expected= path.join(path.dirname(file.path), 'expected.txt')

    exec(`node ${file.path} < ${input} > ${output}`).then((stdout)=> {
      exec(`diff ${expected} ${output}`).then((stdout)=> {
        console.log('passed tests')
      }).catch((stderr)=> {
        console.log('failed tests')
      })
    })
  })
})
