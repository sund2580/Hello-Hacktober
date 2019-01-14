let helloWorld= function () {
  return Promise.resolve('hello world')
}
helloworld.then((v) => console.log(v))
