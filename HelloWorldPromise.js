export const helloWorld = () => {
  return new Promise((resolve, reject) => {
    console.log('Hello World with Promise!!!');
    resolve();
  })
}
