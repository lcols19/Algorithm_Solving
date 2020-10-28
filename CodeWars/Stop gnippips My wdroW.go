// Write a function that takes in a string of one or more words, and returns 
// the same string, but with all five or more letter words reversed (Just like 
// the name of this Kata). Strings passed in will consist of only letters and 
// spaces. Spaces will be included only when more than one word is present.

package kata

import (
    "strings"
)

func reverse(s string) string {
    rns := []rune(s)
    for i, j := 0, len(rns) - 1; i < j; i, j = i + 1, j - 1 {
        rns[i], rns[j] = rns[j], rns[i]
    }
    return string(rns)
}

func SpinWords(s string) string {
    results := strings.Split(s, " ")
    //fmt.Printf("%s", results[0])
    for i , str := range results {
        i = i
        if len(str) >= 5 {
            results[i] = reverse(str)
        }
    }
    res := strings.Join(results, " ")
    return res
}