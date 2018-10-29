const messages = {
  species: 'human',
  name: 'Anik3t',
  message: 'hello world'
}

// We want to just display "hello world" along with the name.
// We will use destructuring to achieve this objective.

let { name, message } = messages
console.log(name + ' says' + ' ' + message)