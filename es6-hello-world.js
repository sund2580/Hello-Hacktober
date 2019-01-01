const messages = [
  {message: 'Hello', name: 'world'},
  {message: 'Hey', name: 'peter'},
  {message: 'Wassup', name: 'mattias'}
]

// we want to filter out "Hello world" from this messages array
// we will use higher order functions and es6 syntax for this 
// they are: filter() and map().

const helloWorld = messages.filter((event) => {
  return event.message === 'Hello' && event.name === 'world'
}).map((event) => {
  return event.message + " " + event.name
})
console.log(helloWorld)