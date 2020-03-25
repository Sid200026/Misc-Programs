const notes = require('./note');

const allNotes = notes()

allNotes.forEach(note => {
    console.log(note);
})