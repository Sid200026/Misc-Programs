const yargs = require("yargs");
const add = require("./actions/add");
const sanitize = require("./utils/sanitize");
const view = require("./actions/view");
const all = require("./actions/all");
const rm = require("./actions/rm");

yargs
  .alias("v", "version")
  .alias("h", "help")
  .command(
    "add [title] [detail]",
    "Add a new note",
    yargs => {
      yargs
        .positional("title", {
          alias: "t",
          type: "string",
          describe: "Title of the note"
        })
        .positional("detail", {
          alias: "d",
          type: "string",
          describe: "Details of the note"
        })
        .demandOption(
          ["title", "detail"],
          "Please provide both the title and details of the note"
        );
    },
    argv => {
      const arr = [argv.title, argv.detail];
      sanitize(arr);
      add(arr[0], arr[1]);
    }
  )
  .command(
    "view [title]",
    "View a particular note",
    yargs => {
      yargs
        .positional("title", {
          alias: "t",
          type: "string",
          describe: "Title of the note"
        })
        .demandOption(["title"], "Please provide the title of the note");
    },
    argv => {
      const arr = [argv.title];
      sanitize(arr);
      view(arr[0]);
    }
  )
  .command("all", "View all notes", () => all())
  .command(
    "rm [title]",
    "Remove a particular note",
    yargs => {
      yargs
        .positional("title", {
          alias: "t",
          type: "string",
          describe: "Title of the note"
        })
        .demandOption(["title"], "Please provide the title of the note");
    },
    argv => {
      const arr = [argv.title];
      sanitize(arr);
      rm(arr[0]);
    }
  )
  .help().argv;
