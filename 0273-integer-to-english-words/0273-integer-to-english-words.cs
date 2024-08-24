public class Solution {
    private static List<string> BaseCases = new List<string>()
    {
        "Zero",
        "One",
        "Two",
        "Three",
        "Four",
        "Five",
        "Six",
        "Seven",
        "Eight",
        "Nine",
        "Ten",
        "Eleven",
        "Twelve",
        "Thirteen",
        "Fourteen",
        "Fifteen",
        "Sixteen",
        "Seventeen",
        "Eighteen",
        "Nineteen"
    };
    private static List<string> BelowHundred = new List<string>()
    {
        "",
        "",
        "Twenty",
        "Thirty",
        "Forty",
        "Fifty",
        "Sixty",
        "Seventy",
        "Eighty",
        "Ninety",
    };
    public string NumberToWords(int number) 
    {
        // Range(1) -> from 0 to 19.
        if (number < 20)
            return BaseCases[number];

        string words = "";

        // Range(2) -> from 20 to 99.
        if (number < 100)
        {
            words = BelowHundred[number / 10];
            if (number % 10 != 0)
                words += " " + NumberToWords(number % 10);
        }

        // Range(3) -> from 100 to 999.
        else if (number < 1000)
        {
            words = BaseCases[number / 100] + " Hundred";
            if (number % 100 != 0)
                words += " " + NumberToWords(number % 100);
        }

        // Range(4) -> from 1000 to 999,999.
        else if (number < 1000000)
        {
            words = NumberToWords(number / 1000) + " Thousand";
            if (number % 1000 != 0)
                words += " " + NumberToWords(number % 1000);
        }

        // Range(5) -> from 1,000,000 to 999,999,999.
        else if (number < 1000000000)
        {
            words = NumberToWords(number / 1000000) + " Million";
            if (number % 1000000 != 0)
                words += " " + NumberToWords(number % 1000000);
        }

        // Range(6) -> from 1,000,000,000
        else 
        {
            words = NumberToWords(number / 1000000000) + " Billion";
            if (number % 1000000000 != 0)
                words += " " + NumberToWords(number % 1000000000);
        }
        return words;
    }
}