const express = require("express");
const path = require("path");
const router = require("./routes/router");
const apirouter = require("./routes/apirouter");
const app = express();

const port = 3000;

app.set("view engine", "pug");
app.set("views", process.cwd() + "/public");

app.use("/api", apirouter);
app.use(router);
app.use(express.static(path.join(__dirname, "public")));

app.listen(port, () => console.log(`Listening on port ${port}`));
