var score = 0;
(function() {
    var Question = function(question, answer, correct) {
        this.question = question;
        this.answer = answer;
        this.correct = correct;
    }

    function getRandomArbitrary(min, max) {
        return Math.floor(Math.random() * (max - min + 1) + min);
    }

    Question.prototype.displayQuestion = function() {
        console.log(this.question);
        for(var i = 0; i < this.answer.length; i++)
        {
            console.log((i+1) + ". "+this.answer[i]);
        }
    }

    Question.prototype.checkAnswer = function(choice) {
        if(this.correct == choice-1)
        {
                return function() {
                    this.score += 1;
                    console.log("Your current score is "+this.score);
            }
        }
        else
        {
            return function() {
                console.log("Your current score is "+this.score);
            }
        }
    };



    var q1 = new Question(
        "Is JavaScript a programming language",
        ['No', 'Yes'],
        1,
    );

    var q2 = new Question(
        "Capital of India",
        ['Delhi', 'Kolkata'],
        0,
    );

    var q3 = new Question(
        "What is Django",
        ['A framework', 'A programming language'],
        0,
    );

    var qarr = [q1, q2, q3];

    while(true)
    {
        var index = getRandomArbitrary(0,2);
        var ques = qarr[index];
        ques.displayQuestion();
        var choice = prompt("Enter the answer code");
        if(choice === "exit")
        {
            break;
        }
        else
        {
            ques.checkAnswer(choice)()
        }
    }
})();