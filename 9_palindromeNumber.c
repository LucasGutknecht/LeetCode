bool isPalindrome(int x) {
    int temporary = x;
    long long reverse = 0;

    if(x < 0) return false;

    while(temporary != 0){
        reverse = (reverse * 10) + (temporary % 10);
        temporary = temporary / 10;
    }

    return (reverse == x ) ? true : false;

}
