// This is an example of closures in javascript.
// javascript supports closures which most languages dont.

var message = "world"
function greetWorld() {
  console.log('Hello ' + message)
}
greetWorld()

// As you notice there is no argument passed into the function yet we are printing the message. How so you ask? It is because of the message variable declared above the function which has a global scope. I repeat not many languages support this behaviour that is CLOSURES but luckily we have javascript. For languages which do not have the support for closures we would have to pass in the message as a argument to the function in order for it to make it work.

function sendRequest() {
  let requestID = 123
  if (requestID === 123) {
    function approveRequest() {
      console.log("Request with request ID: " + requestID + " has been approved" )
    }
  }
  return approveRequest()
}

sendRequest()

// In the above example we have a function inside of another function. The outer function "sendRequest()" has a variable declared inside it "requestID". This variable is able to be read by the inner function "approveRequest()". This is possible because of closures, in other languages you would have to create some sort of data object and pass it into the function for it to use inside it or imagine the pain of having to create a data object everytime you want to use it. Ain't closure the best?