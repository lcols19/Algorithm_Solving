// Clock shows 'h' hours, 'm' minutes and 's' seconds after midnight. Your task 
	// is to make 'Past' function which returns time converted to milliseconds.

fun past(h: Int, m: Int, s: Int): Int {
    var result = (s + (m * 60) + (h * 60 * 60)) * 1000 
    return result
}