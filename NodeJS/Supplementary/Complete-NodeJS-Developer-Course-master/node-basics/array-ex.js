var grades = [100, 50, 75];

var totalGrade = 0;
grades.forEach(function (grade) {
  totalGrade += grade;
});

var average = totalGrade/grades.length;

console.log("Average is = " + average);
