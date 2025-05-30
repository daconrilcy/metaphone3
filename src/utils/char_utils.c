#include "utils/char_utils.h"
#include <ctype.h>
#include <stdbool.h>
#include "metaphone3.h"

bool IsVowel(char inChar)
{
    inChar = ToUpper(inChar);
    if ((inChar == 'A') || (inChar == 'E') || (inChar == 'I') || (inChar == 'O') || (inChar == 'U') || (inChar == 'Y') || (inChar == 'Ŕ') || (inChar == 'Á') || (inChar == 'Â') || (inChar == 'Ă') || (inChar == 'Ä') || (inChar == 'Ĺ') || (inChar == 'Ć') || (inChar == 'Č') || (inChar == 'É') || (inChar == 'Ę') || (inChar == 'Ë') || (inChar == 'Ě') || (inChar == 'Í') || (inChar == 'Î') || (inChar == 'Ď') || (inChar == 'Ň') || (inChar == 'Ó') || (inChar == 'Ô') || (inChar == 'Ő') || (inChar == 'Ö') || (inChar == '?') || (inChar == 'Ř') || (inChar == 'Ů') || (inChar == 'Ú') || (inChar == 'Ű') || (inChar == 'Ü') || (inChar == 'Ý') || (inChar == '?'))
    {
        return true;
    }

    return false;
}

bool IsConsonant(char c)
{
    c = ToUpper(c);
    return ((c >= 'A' && c <= 'Z') && !IsVowel(c));
}

char ToUpper(char c)
{
    return (char)toupper((unsigned char)c);
}

char ToLower(char c)
{
    return (char)tolower((unsigned char)c);
}

// Renvoie true si c'est une voyelle à la position idx (ou fin de mot)
bool IsVowelAt(Metaphone3 *ctx, int idx)
{
    char c = CharAt(ctx->m_inWord, idx);
    return IsVowel(c);
}
