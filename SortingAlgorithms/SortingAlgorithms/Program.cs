using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Diagnostics;

namespace SorthingAlgorithms
{

    class Program
    {
        static readonly int[] size = { 32000 };
        const int testSize = 100;
        int[] array = null;
        int[] unsortedArray = null;
        void RandomNumbers(int index)
        {
            array = new int[size[index]];
            Random randomNum = new Random();
            for (int i = 0; i < array.Length; i++)
            {
                int randomInt = randomNum.Next(0, 128000);
                array[i] = randomInt;
            }
        }

        void BubbleSort(int[] arr)
        {
            int temp = 0;
            Stopwatch watch = new Stopwatch();
            watch.Start();
            for (int write = 0; write < arr.Length; write++)
            {
                for (int sort = 0; sort < arr.Length - 1; sort++)
                {
                    if (arr[sort] > arr[sort + 1])
                    {
                        temp = arr[sort + 1];
                        arr[sort + 1] = arr[sort];
                        arr[sort] = temp;
                    }
                }
            }
            watch.Stop();
            Console.Out.WriteLine("Executation time for bubble sort: " + watch.ElapsedMilliseconds + " miliseconds");
        }
        void ImprovedBubbleSort(int[] arr)
        {
            int temp = 0;
            bool swapped = false;
            Stopwatch watch = new Stopwatch();
            watch.Start();
            for (int write = 0; write < arr.Length; write++)
            {
                swapped = false;
                for (int sort = 0; sort < arr.Length - 1; sort++)
                {
                    if (arr[sort] > arr[sort + 1])
                    {
                        swapped = true;
                        temp = arr[sort + 1];
                        arr[sort + 1] = arr[sort];
                        arr[sort] = temp;
                    }
                }
                if (!swapped)
                {
                    break;
                }
            }
            watch.Stop();
            Console.Out.WriteLine("Executation time for improved bubble sort: " + watch.ElapsedMilliseconds + " miliseconds");
            
        }
        public void SelectionSort(int[] arr)
        {
            Stopwatch watch = new Stopwatch();
            watch.Start();
            int pos_min, temp;
            for (int i = 0; i < arr.Length - 1; i++)
            {
                pos_min = i;
                for (int j = i + 1; j < arr.Length; j++)
                {
                    if (arr[j] < arr[pos_min])
                    {
                        pos_min = j;
                    }
                }
                if (pos_min != i)
                {
                    temp = arr[i];
                    arr[i] = arr[pos_min];
                    arr[pos_min] = temp;
                }
            }
            watch.Stop();
            Console.Out.WriteLine("Executation time for selection sort: " + watch.ElapsedMilliseconds + " miliseconds");
        }
        private static void Swap(ref int a, ref int b)
        {
            a ^= b;
            b ^= a;
            a ^= b;
        }
        void CocktailSort(int[] arr)
        {
            int startOfArr = 0;
            int endOfArr = arr.Length - 1;
            int temp;
            bool swapped = true;
            Stopwatch watch = new Stopwatch();
            watch.Start();
            for (int z = 0; z<arr.Length/2; z++)
            {
                swapped = false;
                for (int i = startOfArr + z; i < endOfArr; i++)
                {
                    if (arr[i] > arr[i + 1])
                    {
                        temp = arr[i];
                        arr[i] = arr[i + 1];
                        arr[i + 1] = temp;
                        swapped = true;
                    }
                }
                //endOfArr--;
                for (int i = endOfArr - z; i > startOfArr; i--)
                {
                    if (arr[i] < arr[i - 1])
                    {
                        temp = arr[i];
                        arr[i] = arr[i - 1];
                        arr[i - 1] = temp;
                        swapped = true;
                    }
                }
                
                //startOfArr++;
            }
            watch.Stop();
            Console.Out.WriteLine("Executation time for Cocktail sort: "
                + watch.ElapsedMilliseconds + " miliseconds");
        }
        void InsertionSort(int[] inputArray)
        {
            Stopwatch watch = new Stopwatch();
            watch.Start();
            for (int i = 0; i < inputArray.Length - 1; i++)
            {
                for (int j = i + 1; j > 0; j--)
                {
                    if (inputArray[j - 1] > inputArray[j])
                    {
                        int temp = inputArray[j - 1];
                        inputArray[j - 1] = inputArray[j];
                        inputArray[j] = temp;
                    }
                }
            }
            watch.Stop();
            Console.Out.WriteLine("Executation time for insertion sort: "
                + watch.ElapsedMilliseconds + " miliseconds");
        }

        void ImprovedInsertionSort(int[] inputArray)
        {
            Stopwatch watch = new Stopwatch();
            watch.Start();

            int temp, j;
            for(int i = 1; i<inputArray.Length; i++)
            {
                temp = inputArray[i];
                j = i;
                while(j>0 && inputArray[j-1] > temp)
                {
                    inputArray[j] = inputArray[j - 1];
                    j = j - 1;
                }
                inputArray[j] = temp;
            }
            watch.Stop();
            Console.Out.WriteLine("Executation time for shell sort with different gap: " + watch.ElapsedMilliseconds + " miliseconds");
        }
        void ShellSort(int[] inputArray)
        {
            Stopwatch watch = new Stopwatch();
            watch.Start();
            int inc, temp, j;
            inc = 3;//gap size
            while (inc > 0)
            {
                for (int i = 0; i < inputArray.Length; i++)
                {
                    j = i;
                    temp = inputArray[i];
                    while ((j >= inc) && (inputArray[j - inc] > temp))
                    {
                        inputArray[j] = inputArray[j - inc];
                        j = j - inc;
                    }
                    inputArray[j] = temp;
                }
                if (inc / 2 != 0)
                {
                    inc = inc / 2;
                }
                else if (inc == 1)
                {
                    inc = 0;
                }
                else {
                    inc = 1;
                }
            }
            watch.Stop();
            Console.Out.WriteLine("Executation time for shell sort: "
                + watch.ElapsedMilliseconds + " miliseconds");
        }
        private void ShellSortWithDiffGap(int[] array)
        {
            int n = array.Length;
            int gap = n / 2;
            int temp;
            Stopwatch watch = new Stopwatch();
            watch.Start();
            while (gap > 0)
            {
                for (int i = 0; i + gap < n; i++)
                {
                    int j = i + gap;
                    temp = array[j];

                    while (j - gap >= 0 && temp < array[j - gap])
                    {
                        array[j] = array[j - gap];
                        j = j - gap;
                    }

                    array[j] = temp;
                }

                gap = gap / 2;
            }
            watch.Stop();
            Console.Out.WriteLine("Executation time for shell sort with different gap: " + watch.ElapsedMilliseconds + " miliseconds");
        }

        private void QuickSort(int[] array, int left, int right)
        {

            int i = left;
            int j = right;
            int pivot = array[(left + right) / 2];
            while (i < j)
            {
                while (array[i] < pivot) i++;
                while (array[j] > pivot) j--;
                if (i <= j)
                {
                    // swap
                    int tmp = array[i];
                    array[i++] = array[j]; 
                    array[j--] = tmp;
                }
            }
            if (left < j) QuickSort(array, left, j);
            if (i < right) QuickSort(array, i, right);
        }

        static void ShowArray(int[] arr)
        {
            for (int i = 0; i < arr.Length; i++)
            {
                Console.Out.WriteLine(arr[i]);
            }
        }
        void RewriteArrays(int[] unsorted, int[] toSorted)
        {
            for(int i = 0; i < unsorted.Length; i++)
            {
                toSorted[i] = unsorted[i];
            }
        }
        static void Main(string[] args)
        {
            
            for (int iteration = 0; iteration < size.Length; iteration++)
            {
                Console.Out.WriteLine("For " + size[iteration] + " number of elements:");
                Program program = new Program();
                program.RandomNumbers(iteration);
                program.unsortedArray = new int[size[iteration]];
                for(int i = 0; i<program.array.Length; i++)
                {
                    program.unsortedArray[i] = program.array[i];
                }
                //program.ShowArray(program.unsortedArray);
                //Stopwatch watch = new Stopwatch();
                //watch.Start();
                //program.QuickSort(program.array, 0, program.array.Length - 1);
                //watch.Stop();
                //Console.Out.WriteLine("Executation time for shell sort with different gap: " + watch.ElapsedMilliseconds + " miliseconds");
                program.ImprovedBubbleSort(program.array);
                program.RewriteArrays(program.unsortedArray, program.array);
                program.CocktailSort(program.array);
                program.RewriteArrays(program.unsortedArray, program.array);
                program.BubbleSort(program.array);
            }


        }


    }
}


