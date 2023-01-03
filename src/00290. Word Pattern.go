func wordPattern(pattern string, s string) bool {
	dictA := make(map[byte]int)
	dictB := make(map[string]int)
	ss := strings.Split(s, " ")
	
	if len(pattern) != len(ss) {
			return false
	}
	
	for i := 0; i < len(pattern); i++ {
			vals, isOks := dictA[pattern[i]];
			valch, isOkch := dictB[ss[i]];
			if (isOks != isOkch || vals != valch) {
					return false;
			}
			dictA[pattern[i]] = i;
			dictB[ss[i]] = i;
	}
	return true
}