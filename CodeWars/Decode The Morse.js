// In this kata you have to write a simple Morse code decoder. The Morse code 
// encodes every character as a sequence of "dots" and "dashes". For example, 
// the letter A is coded as ·−, letter Q is coded as −−·−, and digit 1 is coded 
// as ·−−−−. The Morse code is case-insensitive, traditionally capital letters 
// are used. When the message is written in Morse code, a single space is used 
// to separate the character codes and 3 spaces are used to separate words. For 
// example, the message HEY JUDE in Morse code is ···· · −·−−   ·−−− ··− −·· ·.
// NOTE: Extra spaces before or after the code have no meaning and should be 
// ignored.
// In addition to letters, digits and some punctuation, there are some special 
// service codes, the most notorious of those is the international distress 
// signal SOS (that was first issued by Titanic), that is coded as ···−−−···. 
// These special codes are treated as single special characters, and usually are
// transmitted as separate words. Your task is to implement a function that 
// would take the morse code as input and return a decoded human-readable string.
// NOTE: For coding purposes you have to use ASCII characters . and -, not 
// Unicode characters.
// The Morse code table is preloaded for you as a dictionary, feel free to use 
// it: MORSE_CODE['.--']. All the test strings would contain valid Morse code, 
// so you may skip checking for errors and exceptions.

decodeMorse = function(morseCode){
	var str1 = [];
	str1 = morseCode.trim();
	var str = [];
	str = str1.split("   ");
	for (var i = 0; str[i] && i < str.length; i++)
	  {
		for (var j = 0; str[i] && j < str[i].length; j++)
		  {
		   console.log(str[i]);
			console.log('here');
			if ((str[i][j] == '.' || str[i][j] == '-'))
			  {
				var crc = [];
				crc = str[i].split(' ');
				for (var k = 0; crc[k] && k < crc.length ; k++)
					crc[k] = MORSE_CODE[crc[k]];
				str[i] = crc.join('');
				console.log(str[i]);
				break;
			  }
		  }
	  }
	var res = str.join(' ');
	console.log(res);
	return res;
  };