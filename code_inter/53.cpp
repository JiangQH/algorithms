bool partern(char* str, char* partern) {
	if (!str || !partern)
		return false;
	return match(str, partern);
}

bool match(char* str, char* partern) {
	if (*str == '\0' && *partern == '\0')
		return true;
	if (*str != '\0' && *partern == '\0')
		return false;
	if (*(partern+1) == '*') {
		// it has to decide 3 situations
		if (*partern == *str || (*partern == '.' && *str != '\0')) {
			return match(str+1, partern+2) || match(str, partern+2)
					|| match(str+1, partern);
		}
		else
			return match(str, partern+2);

	}
	if (*partern == *str || (*partern == '.' && *str != '\0'))
		return match(str+1, partern+1);
	return false;
}