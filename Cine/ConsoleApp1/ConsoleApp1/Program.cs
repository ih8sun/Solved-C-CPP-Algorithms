using System;

namespace ConsoleApp1
{


    class Program
    {
        static int vol(int x, int y = 3, int z = 1)
        {
            return x * y * z;
        }

        static void Main(string[] args)
        {

            Console.WriteLine(vol(2, 4));

        }


    }


}
