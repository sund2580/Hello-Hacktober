const express = require("express");
const app = express();
const PORT = process.env.PORT || 1337;

app.get("/hello", (req, res) => {
  res.json({ text: "Hello World!!" });
});

app.listen(PORT, () => console.log(`Server is ready at port ${PORT}`));
