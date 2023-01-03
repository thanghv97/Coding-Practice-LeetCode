func isUpper(ch byte) bool {
	return ch >= 'A' && ch <= 'Z';
}

func detectCapitalUse(word string) bool {
	opt := 1;
	if (isUpper(word[0])) {
			if (len(word) > 1 && isUpper(word[1])) {
					opt = 0;
			}
	} else {
			opt = 2;
	}
	for i := 1; i < len(word); i++ {
			switch opt {
					case 0:
							if !isUpper(word[i]) {
									return false;
							}
					case 1, 2:
							if isUpper(word[i]) {
									return false;
							}
			}
	}
	return true;
}