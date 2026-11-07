using System;
using System.Collections.Generic;
using System.Linq;

namespace ConsoleApp1
{
    class Program
    {
        static void Main()
        {
            int[] a = new int[5010];
            int L = int.Parse(Console.ReadLine());
            int N = int.Parse(Console.ReadLine());
            if (N == 0)
            {
                Console.WriteLine("{0} {1}", 0, 0);
                return;
            }
            string[] input = Console.ReadLine().Split();
            int maxans = 0,minans = 0;
            for (int i = 0; i < N; i++)
            {
                a[i] = int.Parse(input[i]);
                maxans=Math.Max(maxans,Math.Max(L+1-a[i],a[i])); 
                minans=Math.Max(minans,Math.Min(L+1-a[i],a[i]));
            }
            Console.WriteLine(minans + " " + maxans);
        }
    }
}
