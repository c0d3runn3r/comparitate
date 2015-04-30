var fs = require('fs');

var start = new Date();

var ar = [];
var letters = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ';

for(var i = 0; i < 10000; i++) {
	ar.push(letters[Math.floor(Math.random() * letters.length)]
		+ letters[Math.floor(Math.random() * letters.length)]
		+ letters[Math.floor(Math.random() * letters.length)]
		+ letters[Math.floor(Math.random() * letters.length)]);
}

ar.sort(function (a, b) {
	return a > b ? 1 : -1;
});

var output = ar.join('\n');

fs.writeFile('./roberto_output.txt', output, function(err) {
	if(err) throw err;
	console.log('Elapsed time: ' + (new Date() - start) + 'ms\n');
});
